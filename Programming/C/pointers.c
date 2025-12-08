#include <stdlib.h>
#include <stdio.h>

void printf_tests(){
    printf("%d\n", 5);
    int * p = (int*)3;
    printf("%d\n", p); // undefined behavior !
    printf("%p\n", p); 
    int num = 2;
    p = &num;
    printf("p dereference:\n%d\n", *p);
    printf("p value:\n%p\n", p);
    printf("num address:\n%p\n", &num);
    *p = 10;
    printf("p dereference:\n%d\n", *p);
    
}

void change_pointer_value(int * p){
    *p = 10;
}

void test_change_pointer_value(){
    int num = 1;
    int * p = &num;
    change_pointer_value(p);
    printf("p after change:%d\n", *p);
}

void change_array_value(int arr[], int len)
{
    /* int arr_len = sizeof(arr) / sizeof(int);
    this is WRONG ! arr[] as an arguemnt is the same as passing arr* */
    if(len>0){
        arr[0] = 10;
    }
}

void test_change_array_value(){
    int arr[] = {1,2,3};
    printf("size of arr:%d\n",sizeof(arr));
    printf("arr len:%d\n",sizeof(arr)/sizeof(int));
    printf("arr[0]=%d\n", arr[0]);
    change_array_value(arr,sizeof(arr)/sizeof(int));
    printf("arr[0]=%d\n", arr[0]);
} 

void test_change_string_literal(){
    char* p = "Hello"; 
    p[0] = 'J'; // Undefined behavior: might crash the program
}


int main (int argc, char * argv[])
{
    printf("its running!\n");
    //printf_tests();
    //test_change_pointer_value()
    //test_change_array_value()
    // test_change_string_literal();
    
    exit(0);
}