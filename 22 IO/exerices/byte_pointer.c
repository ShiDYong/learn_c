//
// Created by root on 23-10-20.
//
#include<stdio.h>
#include<ctype.h>
#include<string.h>

typedef unsigned char *byte_pointer;

void show_byte(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++){
        printf("%.2x", start[i]);
    }
    printf("\n");
}


void show_int(int x){
    show_byte((byte_pointer)&x,sizeof(x));
}

void show_float(float x){
    show_byte((byte_pointer)&x,sizeof(x));
}
void show_void(void*x){
    show_byte((byte_pointer)&x,sizeof(void *));
}

void test_show_byte(int value){
    int int_value=value;
    float float_value=(float)value;
    int *prev= &int_value;
    show_int(int_value);
    show_float(float_value);
    show_void(prev);



}

int main(void){
//  int n=12345;
//    test_show_byte(n);
//   int value = 0x97654321;
//   byte_pointer valP=(byte_pointer)&value;
//    show_byte(valP,1);
//    show_byte(valP,2);
//    show_byte(valP,3);
   const char *s = "abcdef";
    show_byte((byte_pointer)s, strlen(s));

}