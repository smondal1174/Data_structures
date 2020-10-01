#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
}queue;

//inserting element on Queue
void insert(queue *q, int data){
    node* ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->data=data;
    if(q->front==NULL){
        q->front=ptr;
        q->rear=ptr;
        q->front->next=q->rear->next=NULL;
    }            
    else{
        q->rear->next=ptr;
        q->rear=ptr;
        q->rear->next=NULL;
    }
    
}

//deleting elements of queue
int delete(queue *q){
    node *ptr=q->front;
    int deleted_data=ptr->data;
    if(q->front==NULL){
        printf("Underflow condition");
    }
    
    else{
        q->front=q->front->next;
        free(ptr);
    }
    return deleted_data;
}

//displaying elements od Queue
queue* display(queue* q1){
    if(q1->front==NULL){
        printf("Queue is empty");
    }
    else{
        node *temp=q1->front;
        while(temp!=q1->rear){
            printf("%d\n", temp->data);
            temp=temp->next;
        }
        printf("%d", temp->data);
    }
    return q1;
}

int main(){
 queue q;
 q.front=NULL;
 q.rear=NULL;
 insert(&q, 1);
 insert(&q, 2);
 insert(&q, 3);
 insert(&q, 4);
 insert(&q, 5);
 display(&q);
 
 return 0;
}
