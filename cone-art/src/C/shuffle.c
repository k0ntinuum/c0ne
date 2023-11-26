void shuffle(i64* v, i64 len) {
    i64 j = 0;
    i64 temp = 0;
    for (i64 i = len - 1; i > 0; i -= 1) {
        j = arc4random_uniform(i+1);
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void check_text_equality(const i64 u[T], const i64 v[T] ) {
	for (i64 i = 0; i < T; i++) if (u[i] != v[i]) printf("inequality found at symbol %lld \n",i);
}

void record_difference(i64* x, const i64* y, const i64* z) {
    for (i64 i = 0; i < T; i++) x[i] = (y[i] != z[i]);
}

void copy_text(i64 d[T] , i64 s[T]) {
	for (i64 i = 0; i < T; i++) d[i] = s[i];
}

