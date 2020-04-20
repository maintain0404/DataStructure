#include<stdio.h>
#include<stdlib.h>

typedef int DATA;

typedef struct __node{
    DATA data;
    int priority;
    struct __node * left;
    struct __node * right;
}node;

typedef struct __priority_queue{
    int count;
    struct __node * root;
}priority_queue;

node * MakeNode(DATA data, int priority){
    node * temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->priority = priority;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//노드 두개의 데이터와 우선도를 스왑
void SwapNodeInfo(node * a, node * b){
    int temp_p, temp_d;
    temp_p = a->priority;
    temp_d = a->data;
    a->priority = b->priority;
    a->data = b->data;
    b->priority = temp_p;
    b->data = temp_d;
}

void PrirorityQueueInit(priority_queue * pqueue){
    pqueue->count = 0;
    pqueue->root = NULL;
}

int EnqueueInner(node * current, node * new){
    //현재 노드와 추가하려는 노드를 비교해서 추가하려는 노드가 현재노드보다 항상 작도록 설정
    if(new->priority > current->priority){
        SwapNodeInfo(current, new);
    }
    //바닥케이스 1 : 자식이 없는 경우
    if(current->left == NULL && current->right == NULL){
        current->left = new;
        return 0;
    }
    //바닥케이스 2 : 자식이 오른쪽만 있는 경우, 왼쪽에 추가
    else if(current->left != NULL && current->right == NULL){
        current->right = new;
        return 0;
    }
    //바닥케이스 3 : 자식이 왼쪽만 있는 경우, 오른쪽에 추가
    else if(current->left == NULL && current->right != NULL){
        current->left = new;
        return 0;
    }else{
        //왼쪽 자식이 우선도가 높은 경우 오른쪽 자식으로 재귀실행
        if(current->left->priority > current->right->priority){
            EnqueueInner(current->right, new);
        }
        //오른쪽 자식이 우선도가 높은 경우 왼쪽 자식으로 재귀실행
        else{
            EnqueueInner(current->left, new);
        }
    }
}

int Enqueue(priority_queue * pq, DATA data, int priority){
    node * new_node;
    new_node = MakeNode(data, priority);
    //메모리가 할당되지 않은 경우
    if(new_node == NULL){
        fputs("Memory allocation failed while making node in priority queue.\n", stderr);
        return 2;
    }
    if (pq->root == NULL){
        pq->root = new_node;
    }else{
        EnqueueInner(pq->root, new_node);
    }
    (pq->count)++;
    return 0;
}

int DequeueInner(node * current){
    //바닥케이스 1 : 자식이 없는 경우 -> 종료
    if(current->left == NULL && current->right == NULL){
        return 0;
    }
    //바닥케이스 2 : 왼쪽만 자식이 있는 경우 -> 왼쪽을 해제하고 종료
    else if(current->left != NULL && current->right == NULL){
        SwapNodeInfo(current, current->left);
        free(current->left);
        current->left = NULL;
        return 1;
    }
    //바닥케이스 3 : 오른쪽만 자식이 있는 경우 -> 오른쪽을 해제하고 종료
    else if(current->left == NULL && current->right != NULL){
        SwapNodeInfo(current, current->right);
        free(current->right);
        current->right = NULL;
        return 1;
    }
    else{
        //왼쪽의 우선도가 높은 경우 -> 왼쪽을 올리고 왼쪽으로 재귀실행
        if(current->left->priority > current->right->priority){
            SwapNodeInfo(current, current->left);
            //왼쪽의 자식이 없었던 경우 -> 왼쪽을 해제
            if(DequeueInner(current->left) == 0){
                free(current->left);
                current->left = NULL;
            };
        }
        //오른쪽의 우선도가 높은 경우 -> 오른쪽을 올리고 오른쪽으로 재귀실행
        else{
            SwapNodeInfo(current, current->right);
            //오른쪽의 자식이 없었던 경우 -> 오른쪽을 해제
            if(DequeueInner(current->right) == 0){
                free(current->right);
                current->right = NULL;
            }
        }
    }
    return 1;
}

int Dequeue(priority_queue * pq, DATA * output){
    //빼낼 데이터가 없는 경우
    if(pq->root == NULL){
        fputs("Priority queue is empty.\n", stderr);
        return 1;
    }else{
        *output = pq->root->data;
        DequeueInner(pq->root);
    }
    (pq->count)--;
    return 0;
}

int Peek(priority_queue * pq, DATA * output){
    if(pq->root == NULL){
        fputs("Priority queue is empty.\n", stderr);
        return 1;
    }else{
        *output = pq->root->data;
        return 0;
    }
}

int Count(priority_queue * pq){
    return pq->count;
}