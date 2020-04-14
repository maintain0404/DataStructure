#include<stdio.h>
#include<stdlib.h>

typedef int DATA;

typedef struct __node{
    struct __node * next;
    DATA data;
}node;

typedef struct __queue{
    struct __node * front;
    struct __node * rear;
    int count;
}queue;

node * MakeNode(DATA input){
    node * temp;
    temp = (node*)malloc(sizeof(node));
    if(temp == NULL){
        fputs("Memory allocation failed while making node\n", stderr);
        return NULL;
    }
    temp->next = NULL;
    temp->data = input;

    return temp;
}

void InitQueue(queue * target){
    //더미 노드 생성
    node * dummy;
    dummy = MakeNode(0);

    printf("init\n");
    //연결 및 개수 초기화
    target->front = dummy;
    target->rear = dummy;
    target->count = 0;
}

int Enqueue(queue * target, DATA input){
    //새 노드 생성
    node * new;
    new = MakeNode(input);
    if(new == NULL){
        fputs("Memory is not enough.\n", stderr);
        return 1;
    }

    //리어에 연결
    target->rear->next = new;
    target->rear = new;
    (target->count)++;
    return 0;
}

int Dequeue(queue * target, DATA * output){
    if(target->front == target->rear){
        fputs("This queue is empty.\n", stderr);
        return 1;
    }
    //임시 포인터에 프론트 연결
    node * temp;
    temp = target->front;

    //프론트 이동
    target->front = target->front->next;
    (target->count)--;

    //임시 노드 해제
    *output = temp->data;
    free(temp);

    return 0;
}

int Count(queue * target){
    return target->count;
}

void DeleteQueue(queue * target){
    //임시 노드 생성
    node * temp, * temp_next;
    
    //순회하면서 메모리 해제
    temp = target->front; 
    while(temp != NULL){
        temp_next = temp->next;
        free(temp);
        temp = temp_next;
    }
    target->count = 0;
}