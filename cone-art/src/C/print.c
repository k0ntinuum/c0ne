void rgb(int r, int g, int b) {
    printf("\x1b[38;2;%d;%d;%dm",r,g,b);
}
void gray(int h) {
    rgb(h,h,h);
}
void cls() {
    printf( "\x1b[2J");
}
void reverse_text() {
    printf("\x1b[7m");
}
void stop_reverse_text() {
    printf("\x1b[27m");
}
void hide_cursor() {
    printf("\x1b[?25l");
}
void show_cursor() {
    printf("\x1b[?25h");
}

void cursor_to(int r, int c) {
    printf("\x1b[%d;%dH",r,c);
}

void print_symbol(i64 i) {
    i64 rev = arc4random_uniform(100);
    
    
    //gray(arc4random_uniform(255));
    rgb(0,arc4random_uniform(255),0 );
    //rgb(arc4random_uniform(255),arc4random_uniform(255),arc4random_uniform(255));
    //rgb(0,arc4random_uniform(155),0);
    if (rev == 0) reverse_text();
    switch (i) {
        case 0 : printf("O");break;
        case 1 : printf("|");break;
        case 2 : printf("\u2594");break; //u2594
        case 3 : printf("3");break;
    }
    if (rev == 0) stop_reverse_text();
}
void print_key(const i64 k[N][N]) {
	for (i64 i = 0; i <  N/2  ; i++) {
		for (i64 j = i - 1 ; j <= N - 1 -  i   ; j++) {
            //if (j == center && (i == N/2 || i == 0) )  rgb(255,0,0);
            cursor_to(i,j);
            print_symbol(k[i][j]);
            //if (j == center && (i == N/2 || i == 0) ) rgb(255,255,255);
        }
		printf("\n");
	}
    printf("\n");
}
void print_pyramid(const i64 k[N][N]) {
	//for (i64 i = 0; i <= N/2 ; i++) {
    for (i64 i = 0; i <=  N/2  ; i++) {
		for (i64 j = i; j < N  - i ; j++) {
            cursor_to(15 - i, 7 + 2*j);
            print_symbol(k[i][j]); 
        }

	}
}

void print_pyramid_tight(const i64 k[N][N]) {
    u32 d = 600;
    for (i64 i = 0; i <=  N/2  ; i++) {
        for (int i = N/2; i > -1   ; i-- ) {
		    for (i64 j = i; j < N  - i ; j++) {
                cursor_to(15 - i, 5 + j);
                print_symbol(k[i][j]);
                printf("\n");
                //usleep(arc4random_uniform(20) + 10);
                
            }
            usleep(arc4random_uniform(d) + 100);

	    }
    }
}

void print_text(i64 t[T]) {
	for (i64 i = 0; i < T; i++) print_symbol(t[i]);
}
void print_little_key(i64 k[N]) {   
	for (i64 i = 0; i < N; i++) {
        //if (i == N /2 && N %2 == 0 ) printf("  ");
        //if (i == N /2 + 1 && N %2 == 1 ) printf("  ");
        print_symbol(k[i]); 
        printf(" ");
    }
}

	