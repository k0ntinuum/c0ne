void encoding_demo(){
	i64 k[N];
	i64 m[N];
    i64 f[N][N] = {0};
	i64 g[N][N] = {0};
	i64 p[T];//plain
	i64 c[T];//cipher
	i64 d[T];//decode
	i64 e[T];//diff vector
	i64 hue = 155;
	cls();
	randomize_key(k);

    rgb(255,255,255);
    //printf("f = \n\n");
	//rgb(hue,hue,hue);
	//print_key(f);
	//calc(f,k);
	print_key(f);
	
	calc(f,k,0);
	printf("\n\nf = \n");
	print_little_key(k);
	printf("\n\n");
	print_key(f);

	for (i64 i = 0; i < T/2; i++) {
		randomize_text(p);
		copy_key(m,k);
		//print_little_key(m);printf("\n");
		//encode(c,p,f,m);
		//copy_key(m,k);
		//print_little_key(m);printf("\n");
		//decode(d,c,f,m);
		copy_key(m,k);
		cone_encrypt(c,p,f,m);
		copy_key(m,k);
        cone_decrypt(d,c,f,m);
		check_text_equality(d,p);
		record_difference(e,p,c);
		rgb(255,255,255);printf("f(");rgb(255,0,0);print_text(p);rgb(255,255,255);
		printf(") = ");rgb(255,255,0);print_text(c);printf("  ");rgb(hue,hue,hue);
        if (B == 2) print_text(e);
        printf("\n");
	}
}

        