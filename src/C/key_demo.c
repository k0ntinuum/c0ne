void key_demo() {
    hide_cursor();
	i64 k[N];
    i64 f[N][N] = {0};
	randomize_key(k);
    cls();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for (int i = 0; i < 10000 ; i++) {    
        calc(f,k,i%B);
        print_pyramid(f);
        //print_pyramid_tight(f);
        usleep(100000);
        shift(k, N,  1);
    }
    show_cursor();
}