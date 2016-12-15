#include <stdio.h>
#include <stdlib.h>
#include "math/add_two_int.h"  //should be the whole path

int main(int argc, char **argv)
{
   int add_two_int(int a, int b);
   int a, b;
   a = atoi(argv[1]);
   b = atoi(argv[2]);
   printf("the sum is : %d\n", a + b);
}

