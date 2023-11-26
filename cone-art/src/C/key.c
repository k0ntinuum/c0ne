void shift_row(i64 k[N][N], i64 r, i64 s) {
    i64 temp[T];
    for (i64 i = 0; i < N; i++) temp[i] = k[r][(i + s)%N];
    for (i64 i = 0; i < N; i++) k[r][i] = temp[i];
}
void shift_col(i64 k[N][N], i64 c, i64 s) {
    i64 temp[T];
    for (i64 i = 0; i < N; i++) temp[i] = k[(i + s)%N][c];
    for (i64 i = 0; i < N; i++) k[i][c] = temp[i];
}
void spin_key(i64 k[N][N], i64 d, i64 a) {
	for (i64 i = 0 ; i < N ; i++) {
		switch ((i + d)% 2) {
			case 0 : shift_row(k, i, k[i][i] + a + 1);break;
			case 1 : shift_col(k, i, k[i][i] + a + 1);break;
		}
	}
}
i64 trace(i64 k[N][N]) {
	i64 s = 0;
	for (i64 i = 0; i < N; i++) s += k[i][i];
	return s;
}
void auto_spin(i64 k[N][N], i64 j) {
	for (i64 i = 0 ; i < N ; i++) switch (k[i][j]%2) {
            case 0 : shift_row(k, i, k[j][i] + 1);break;
            case 1 : shift_col(k, i, k[j][i] + 1);break;
    }
}
