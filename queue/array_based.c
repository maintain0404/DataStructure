#include<stdio.h>
#include<stdlib.h>

typedef int DATA;

typedef struct __queue{
    int size;
    int front;
    int rear;
    DATA * data;
}queue;

int InitQueue(queue * target, int size){
    //사이즈가 잘못될 경우 종료
    if(size <= 0){
        fputs("Wrong size is inputed in queue.\n", stderr);
        return 1;
    } 

    //설정
    target->size = size;
    target->front = 0;
    target->rear = 1;
    target->data = (DATA * )malloc(sizeof(DATA) * size);

    //메모리가 꽉 찼을 경우
    if(target->data == NULL){
        fputs("Memeory allocation failed while making queue\n", stderr);
        return 2;
    }
    return 0;
}

int Enqueue(queue * target, DATA input){
    //스택이 꽉 찼을 경우
    if(target->rear == target->front){
        fputs("Queue is already full.\n", stderr);
        return 1;
    }
    //삽입 후 리어 이동
    *(target->data + target->rear) = input;
    (target->rear)++;
    target->rear = target->rear % size;
    return 0;
}

int Dequeue(queue * target, DATA * output){
    if((target->rear - target->front) % target->size == 1){
        fputs("There is no data to dequeue.\n", stderr);
        return 1;
    }
    *output = *(target->data + target->front);
    (target->front)++;
    target->front = target->front % target->size;
    return 0;
}

int Count(queue * target){
    return ((target->rear - target->front) % target->size) - 1;
}

void DeleteQueue(queue * target){
    free(target->data);
}
