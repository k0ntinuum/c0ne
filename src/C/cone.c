#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <unistd.h>
typedef int64_t i64;
const i64 N =27;
const i64 H = 3;//3^3 = 27; center of 27 is 27/2 + 1 = 14
const i64 center = 0;
const i64 T = 27;
const i64 B = 3;

char alph[] = "O|@";
#include"shuffle.c"
#include"randomize.c"
#include"key.c"
#include"print.c"
#include"cellular.c"
#include"encode.c"
#include"encryption_demo.c"
#include"key_demo.c"
	
int main() {
	//encoding_demo();
	key_demo();

}
