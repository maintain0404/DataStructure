#include<stdio.h>
#include<stdlib.h>

typedef struct __node{
    struct __node * next;
    void * data;
}node;

typedef struct __stack{
    struct __node * head;
    int count;
}stack;

node * make_node(void * input){
    node * temp;
    temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->data = input;

    return temp;
}

void InitStack(stack * target){
    //더미 노드 생성
    node * temp;
    temp = make_node(NULL)


    //헤드와 연결 및 개수 초기화
    target->head = temp;
    target->count = 0;
}

void Push(stack * target, void * input){
    //임시 노드에 헤드 옮김
    node * temp;
    temp = target->head->next;

    //새 노드 생성
    node * new;
    new = make_node(input);
    new->next = temp;
    
    //연결 및 재설정
    target->head->next = new;
    (target->count)++;
}

void * Pop(stack * target){
    if(target->count == 0){
        fputs(stderr, "This stack is empty,\n");
        return NULL;
    }
    //임시 포인터에 헤드 연결
    node * temp;
    temp = target->head->next;

    //헤드에 다음 노드 연결
    target->head->next = temp->next;
    (target->count)--;

    //임시 노드 해제
    void * output;
    output = temp->data;
    free(temp);
    return output;
}

int Count(stack * target){
    return target->count;
}