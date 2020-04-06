#include<stdio.h>
#include<stdlib.h>

typedef struct __stack{
    int size;
    int count;
    void * data;
}stack;

void InitStack(stack * target, int stack_size, int data_size){
    target->size = 0;
    target->count = 0;
    target->data = malloc(stack_size * data_size);
}

int Push(stack * target, data input){
    if(target->size == target->count){
        fputs(stderr, "stack is already full.\n");
        return -1;
    }
    (target->count)++;
    return 0;
}

int Pop(stack * target, data * output){
    if(target->count == 0){
        fputs(stderr, "stack is empty.\n");
        return -1;
    }
    *output = *(target->data + target->count);
    return 0;
}

int Count(stack * target){
    return target->count;
}
