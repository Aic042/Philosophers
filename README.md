# Philosophers
Philosophers and forks! Sleeping, thinking, eating and even dying all in a simulation! Let it pour!


# Functions
✅ philo.c

    main(): función principal. Crea filósofos, estructuras, mutexes y lanza los hilos.

    cleaner(): libera memoria de config, philos, y threads.

    init_structs(): inicializa los campos de cada filósofo (ID, mutex personal, etc.).

    fork_assigner(): asigna índices de tenedores izquierdo y derecho.

✅ philo_actions.c

    eepy_philo(): el filósofo duerme.

    philo_think(): el filósofo piensa.

    philo_feeder(): el filósofo come, actualiza su tiempo de comida y contador.

    philo_die(): marca a un filósofo como muerto y detiene el programa.

✅ philo_routine.c

    routine(): rutina de cada filósofo. Ciclo: comer → dormir → pensar.

    fork_taker(): el filósofo intenta coger los tenedores.

    drop_forks(): libera los tenedores.

    monitor(): revisa si algún filósofo ha muerto por inanición.

✅ time.c

    get_time_ms(): devuelve el tiempo actual en milisegundos.

✅ parsing.c

    arg_checker(): valida los argumentos de entrada.

    check_pos_int(): comprueba que un número es positivo.

✅ utils.c

    ft_isdigit(), ft_isspace(), ft_atoi(), is_str_digit(): funciones de utilidad para parseo.

✅ variables.c

    initialize_var(): inicializa los valores del struct t_config.
