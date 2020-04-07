#include<stdio.h>
#include<stdlib.h>

typedef int DATA;

typedef struct __stack{
    int size;
    int count;
    DATA * data;
}stack;

void InitStack(stack * target, int stack_size){
    target->size = stack_size;
    target->count = 0;
    target->data = malloc(stack_size * sizeof(DATA));
}

int Push(stack * target, DATA input){
    if(target->size == target->count){
        fputs("stack is already full.\n", stderr);
        return 1;
    }
    *(target->data + target->count) = input;
    (target->count)++;
    return 0;
}

int Pop(stack * target, DATA * output){
    if(target->count == 0){
        fputs("stack is empty.\n", stderr);
        return 1;
    }
    (target->count)--;    
    *output = *(target->data + target->count);
    return 0;
}

int Count(stack * target){
    return target->count;
}

void DeleteStack(stack * target){
    free(target->data);
}
