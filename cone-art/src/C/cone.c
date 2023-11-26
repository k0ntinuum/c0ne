#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <unistd.h>
typedef u_int32_t u32;
typedef int64_t i64;
const u32 N = 27;
const u32 H = 3;//3^3 = 27; center of 27 is 27/2 + 1 = 14
const u32 center = 13;
const u32 T = 27;
const u32 B = 3;

char alph[] = "O|@";
#include"shuffle.c"
#include"randomize.c"
#include"key.c"
#include"print.c"
#include"cellular.c"
#include"encode.c"
#include"key_demo.c"
	
int main() {
	//encoding_demo();
	key_demo();

}
