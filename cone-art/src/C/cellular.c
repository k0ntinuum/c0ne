
int i64_pow(i64 x, i64 b) {
	i64 s = 1;
	for (i64 j = 0; j < x; j++) {
		s *= b;
	}
	return s;
}
int safe_col(int x) {
	if (x < 0) return x + N;
	if (x > N - 1) return x - N;
	return x;
}
int code(i64 r, i64 c, i64 f[N][N], i64 k[N]) {
	int sum = 0;
	int start = c - N/2;
	for (int j = 0; j < N; j++) {
		sum += i64_pow(j,B)*f[r-1][safe_col( start + j)];
	}
	return sum;
}
void load_f(i64 f[N][N], i64 p, i64 k[N]) {
    for (int i = 0; i < N/2 ; i++ ) f[0][i] = k[i];
    for (int i = N/2 + 1; i < N ; i++ ) f[0][i] = k[i-1];
    f[0][N/2] = p;
}
void compute_next_row(i64 d[N], i64 s[N], i64 k[N]) {
    int sum, start;
    for (int c = 0; c < N; c++) {
        sum = 0;start = c - H/2;
        for (int j = 0; j < H; j++) sum += i64_pow(j,B)*s[safe_col( start + j)];
        d[c] = k[sum];
	}
}
void calc(i64 f[N][N], i64 k[N], i64 v) {
    //for (int i = 0; i < N ; i++ ) f[0][i] = k[i];
    load_f(f,v,k);
    for (int i = 1; i < N/2 + 1 ; i++) compute_next_row(f[i],f[i-1],k);
}
void insert_calc(i64 f[N][N], i64 k[N], i64 v) {
    //for (int i = 0; i < N ; i++ ) f[0][i] = k[i];
	k[N/2] = v;
	load_f(f,v, k);
   // load_f(f,v,k);
    for (int i = 1; i < N/2 + 1 ; i++) compute_next_row(f[i],f[i-1],k);
}

i64 apex(i64 f[N][N]) {
    return f[N/2][center];
}