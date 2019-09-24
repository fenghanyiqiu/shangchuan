#include<stdio.h>
#include "stdlib.h"
int main(){
    int *p;
    int i;
    p=&i;
    *p=100;
    printf("p=%x\n",p);
    printf("&p=%x\n",&p);
    printf("*p=%x\n",*p);
    printf("i=%x\n",i);
    printf("&i=%x\n",&i);
}
