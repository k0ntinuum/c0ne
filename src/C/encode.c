void copy_key(i64 d[N],i64 s[N]) {
    for (i64 i = 0; i < N; i++) d[i] = s[i];
}
void shift(i64* t, i64 l, i64 s) {
    i64 temp[T];
    for (i64 i = 0; i < l; i++) temp[i] = t[(l + i + s)%l];
    for (i64 i = 0; i < l; i++) t[i] = temp[i];
}

void encode(i64 c[T], i64 p[T], i64 f[N][N], i64 k[N]) {
	//load_f(f,0,k);
	calc(f,k,0);
	for (i64 i = 0 ; i < T ; i++) {
		c[i] = ( apex(f) + p[i] )%B;
		shift(k, N - 1, p[i] + 1);
		calc(f,k,p[i]);
		//load_f(f,p[i],k);
		//spin_key(k, trace(k), c[i] + p[i]);
	}
}
void decode(i64 d[T], i64 c[T], i64 f[N][N], i64 k[N]) {
	calc(f,k,0);
	for (i64 i = 0 ; i < T ; i++) {
		d[i] = (B + c[i] - apex(f))%B;
		shift(k, N - 1, d[i] + 1);
		calc(f,k,d[i]);
		//load_f(f,d[i],k);
		//spin_key(k, trace(k), c[i] + d[i]);
	}
}
void reverse(i64 t[T]) {
    i64 temp[T];
    for (i64 i = 0; i < T; i++) temp[i] = t[i];
    for (i64 i = 0; i < T; i++) t[i] = temp[T - 1 - i];
}

void cone_encrypt(i64 c[T], i64 p[T], i64 f[N][N], i64 k[N]  ) {
	i64 m[N] = {0};
	i64 u[T] = {0};
	i64 v[T] = {0};
	copy_text(v,p);
	for (i64 r = 0 ; r < N ; r++) {
		copy_key(m,k);
		shift(m, N - 1,  r);
		copy_text(u,v);
		encode(v,u,f,m);
		reverse(v);
	}
	copy_text(c,v);
}
void cone_decrypt(i64 d[T], i64 c[T], i64 f[N][N], i64 k[N]) {
	i64 m[N] = {0};
	i64 u[T] = {0};
	i64 v[T] = {0};
	copy_text(v,c);
	for (i64 r = 0 ; r < N ; r++) {
		copy_key(m,k);
		shift(m, N - 1, N - 1 - r);
		copy_text(u,v);
		reverse(u);
		decode(v,u,f,m);	
	}
	copy_text(d,v);
}


