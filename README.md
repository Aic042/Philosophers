# Philosophers
Philosophers and forks! Sleeping, thinking, eating and even dying all in a simulation! Let it pour!


# Functions
Archivo: actions.c

    eepy_philo(t_philo *p)
        Hace que un filósofo duerma: imprime el estado "is sleeping", espera el tiempo especificado (time_to_sleep), y cambia el estado a "pensando" (is_thinking = 1).
    philo_think(t_philo *p)
        Cambia el estado de un filósofo a "pensando": imprime "is thinking" y prepara al filósofo para comer estableciendo is_eating = 1.
    philo_die(t_philo *p)
        Maneja la muerte de un filósofo: si el filósofo está vivo (unalived = 1), imprime "died", marca al filósofo como muerto (unalived = 0) y establece la bandera de salida del programa (exit = 1).
    grab_forks(t_philo *p)
        Intenta que un filósofo tome dos tenedores: bloquea el tenedor derecho y luego el izquierdo, imprime "has taken a fork" para cada uno, y verifica si el filósofo muere o se acaba el tiempo antes de tomarlos. Retorna 1 si logra tomar ambos, 0 si no.
    philo_eat(t_philo *p)
        Gestiona el proceso de comer: verifica si el filósofo puede comer (no está muerto ni ha pasado el tiempo de muerte), toma los tenedores (usando grab_forks o three_philos para 3 filósofos), imprime "is eating", actualiza el tiempo de la última comida, espera el tiempo de comer, libera los tenedores, incrementa el contador de comidas (times_ate), y cambia el estado a "durmiendo" (is_sleeping = 1).

Archivo: action_utils.c

    three_philos(t_philo *p)
        Maneja el caso especial de 3 filósofos: bloquea un mutex adicional (take_forks) para sincronizar el acceso a los tenedores, toma ambos tenedores, imprime "has taken a fork" dos veces, y libera el mutex. Retorna 1 si tiene éxito, 0 si el filósofo muere o se acaba el tiempo.
    philo_eat_helper(t_philo *p)
        Ayuda en el proceso de comer: actualiza el tiempo de la última comida (last_meal_time), espera el tiempo de comer (time_to_eat), libera los tenedores, y bloquea el mutex de comidas (meals) para actualizar el contador de comidas.

Archivo: exitdeath.c

    get_exit(t_config *c)
        Obtiene el valor de la bandera de salida (exit) de la configuración, protegido por el mutex exit_mutex.
    set_exit(t_config *c, int value)
        Establece el valor de la bandera de salida (exit) en la configuración, protegido por el mutex exit_mutex.
    die_checker(t_philo *p)
        Verifica si un filósofo está muerto: retorna 1 si unalived = 0, protegido por el mutex death_mutex.
    check_one_philo(t_philo *p)
        Maneja el caso de un solo filósofo: imprime que toma un tenedor, espera el tiempo de muerte (time_to_die), marca al filósofo como muerto con philo_die, y retorna 1 para terminar el hilo.
    joint_actions(t_philo *p)
        Ejecuta el ciclo principal de un filósofo: verifica si el programa debe terminar (get_exit), si el filósofo muere por inanición (time_over), si está muerto (die_checker), o si todos han comido lo suficiente (all_philos_ate_enough). Según el estado, llama a philo_think, philo_eat, o eepy_philo.

Archivo: main.c

    init_structs(t_philo *philos, t_config *config)
        Inicializa las estructuras: configura los mutex (print, meals, take_forks, exit_mutex, death_mutex), asigna memoria para los tenedores (forks), inicializa la bandera exit a 0, y establece valores iniciales para los filósofos (id, config, times_ate, is_thinking).
    assign_forks(t_philo *philo, t_fork *forks, int pos)
        Asigna los tenedores derecho (fork_r) e izquierdo (fork_l) a un filósofo según su posición, alternando el orden para filósofos impares para evitar bloqueos.
    init_variables(int argc, char **argv, t_philo *p, t_config *config)
        Inicializa los campos de los filósofos (id, is_sleeping, is_eating, is_thinking, times_ate, unalived, last_meal_time) y los parámetros de configuración (time_to_die, time_to_eat, time_to_sleep, num_of_times_each_philo_must_eat) desde los argumentos de entrada.
    main(int argc, char **argv)
        Punto de entrada del programa: valida los argumentos, asigna memoria para config y p, inicializa las estructuras y variables, ejecuta la simulación con meal, y libera recursos con cleaner.
    cleaner(t_philo *p, t_config *config)
        Libera recursos: destruye los mutex de los tenedores y de la configuración, y libera la memoria asignada para forks, config, y p.

Archivo: meal.c

    sleep_function(t_philo *p, int time)
        Implementa una espera precisa: duerme durante el tiempo especificado (time), comprobando periódicamente si el filósofo muere por inanición (time_to_die).
    init_sleep(t_philo *p)
        Introduce un retraso inicial para sincronizar a los filósofos: filósofos pares esperan 150 µs, impares (con número impar de filósofos) esperan 100 µs, más un retraso adicional de 1000 µs.
    all_philos_ate_enough(t_philo *p)
        Verifica si todos los filósofos han comido el número requerido de veces (num_of_times_each_philo_must_eat), protegido por el mutex meals. Retorna 1 si todos han terminado, 0 si no.
    routine(void *arg)
        Rutina de cada hilo filósofo: maneja el caso de un solo filósofo con check_one_philo, aplica un retraso inicial con init_sleep, y ejecuta el ciclo de acciones con joint_actions.
    meal(t_philo *p)
        Inicia la simulación: crea un hilo por filósofo, asigna la rutina routine, y espera a que todos los hilos terminen con pthread_join.

Archivo: parsing.c

    check_pos_int(int num)
        Verifica si un número es no negativo: imprime un error y retorna 0 si es negativo, 1 si es válido.
    arg_checker(int argc, char **argv)
        Valida los argumentos de entrada: comprueba el número de argumentos (5 o 6), que no sean nulos, que sean dígitos, que sean no negativos, y que time_to_eat y time_to_sleep no sean 0. Retorna 1 si son válidos, 0 si no.

Archivo: time_stuff.c

    get_time_ms(void)
        Obtiene el tiempo actual en milisegundos usando gettimeofday.
    time_over(t_philo *p)
        Verifica si un filósofo ha muerto por inanición: compara el tiempo actual con el tiempo de la última comida (last_meal_time) y time_to_die, protegido por el mutex death_mutex.

Archivo: utils.c

    ft_isdigit(int c)
        Verifica si un carácter es un dígito (0-9): retorna el carácter si es dígito, 0 si no.
    is_str_digit(char *str)
        Comprueba si una cadena representa un número: ignora signos iniciales (+ o -), y verifica que todos los caracteres restantes sean dígitos. Retorna 1 si es válido, 0 si no.
    ft_atol(const char *s)
        Convierte una cadena a un número long, manejando signos y desbordamiento (retorna 0 si excede INT_MAX).
    print_status(t_philo *p, char *msg)
        Imprime el estado de un filósofo (con timestamp, ID y mensaje) en stdout, protegido por el mutex print para evitar condiciones de carrera, y solo imprime si el programa no ha terminado (get_exit).
