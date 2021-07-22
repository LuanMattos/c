#include <stdio.h>
int main() {
 int int_var = 5;
 int *int_ptr;
 int_ptr = &int_var; 
 printf("int_ptr = 0x%08x\n", int_ptr);
 printf("&int_ptr = 0x%08x\n", &int_ptr);
 printf("*int_ptr = 0x%08x\n\n", *int_ptr);
 printf("int_var is located at 0x%08x and contains %d\n", &int_var, int_var);
 printf("int_ptr is located at 0x%08x, contains 0x%08x, and points to %d\n\n",
 &int_ptr, int_ptr, *int_ptr);

 int data = 29;
    printf("%x\n", data);
    printf("%0x\n", data);
    printf("%8x\n", data);
    printf("%08x\n", data);
}