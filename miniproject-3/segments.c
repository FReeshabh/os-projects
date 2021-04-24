/*
* Rishabh Tewari
* Operating Systems Miniproject 3
*/

#include "segments.h"
#include <string.h>
#include <stdlib.h>

/*Data intitialization*/
//Data
char *data_1 = "data 1";
char *data_2 = "data 2";

//bss
char *bss_1 = "bss 1";
char *bss_2 = "bss 2";

//Heap
char *heap_1 = "heap 1";
char *heap_2 = "heap 2";

//Text
char *text_1(){
    return "text 1";
}

char *text_2(){
    return "text 2";
}

//Stack
char *stack_f(char* val){
    return val;
}

//Functions
void init_pointers(){
    char local_stack_1[] = "stack 1";
    char local_stack_2[] = "stack 2";
    data_ptr_1 = data_1;
    data_ptr_2 = data_2;

    bss_ptr_1 = bss_1;
    bss_ptr_2 = bss_2;

    heap_ptr_1 = (char *)malloc(sizeof(char *));
    strcpy(heap_ptr_1, heap_1);
    heap_ptr_2 = (char *)malloc(sizeof(char *));
    strcpy(heap_ptr_2, heap_2);

    text_ptr_1 = text_1;
    text_ptr_2 = text_2;

    stack_ptr_1 = stack_f(local_stack_1);
    stack_ptr_2 = stack_f(local_stack_2);
}

void free_pointers() {
    free(heap_ptr_1);
    free(heap_ptr_2);
}