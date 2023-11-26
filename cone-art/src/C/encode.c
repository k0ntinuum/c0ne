void copy_key(i64 d[N],i64 s[N]) {
    for (i64 i = 0; i < N; i++) d[i] = s[i];
}
void shift(i64* t, i64 l, i64 s) {
    i64 temp[T];
    for (i64 i = 0; i < l; i++) temp[i] = t[(l + i + s)%l];
    for (i64 i = 0; i < l; i++) t[i] = temp[i];
}

