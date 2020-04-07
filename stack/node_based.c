#include<stdio.h>
#include<stdlib.h>

typedef int DATA;

typedef struct __node{
    struct __node * next;
    DATA data;
}node;

typedef struct __stack{
    struct __node * head;
    int count;
}stack;

node * make_node(DATA input){
    node * temp;
    temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = input;

    return temp;
}

void InitStack(stack * target){
    //더미 노드 생성
    node * temp;
    temp = make_node(0);

    //헤드와 연결 및 개수 초기화
    target->head = temp;
    target->count = 0;
}

int Push(stack * target, DATA input){
    //임시 노드에 헤드 옮김
    node * temp;
    temp = target->head->next;

    //새 노드 생성
    node * new;
    new = make_node(input);
    if(new == NULL){
        fputs("Memory is not enough.\n", stderr);
        return 1;
    }
    new->next = temp;
    
    //연결 및 재설정
    target->head->next = new;
    (target->count)++;
    return 0;
}

int Pop(stack * target, DATA * output){
    if(target->count == 0){
        fputs("This stack is empty,\n", stderr);
        return 1;
    }
    //임시 포인터에 헤드 연결
    node * temp;
    temp = target->head->next;

    //헤드에 다음 노드 연결
    target->head->next = temp->next;
    (target->count)--;

    //임시 노드 해제
    *output = temp->data;
    free(temp);

    return 0;
}

int Count(stack * target){
    return target->count;
}

void DeleteStack(stack * target){
    node * temp, * temp_next;
    
    temp = target->head; 
    while(temp != NULL){
        temp_next = temp->next;
        free(temp);
        temp = temp_next;
    }
}