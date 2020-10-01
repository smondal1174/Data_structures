#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct 
{
    int front;
    int rear;
    int data[MAX];
}queue;

//inserting into the queue
queue* insert(queue *q,int data){
    if(q->rear==MAX-1){
        printf("Overflow condition");
    }

    else if(q->front == -1 && q->rear == -1){
        q->front=0;
        q->rear=0;
        q->data[q->rear]=data;
    }
    
    else{
        q->rear=q->rear+1;
        q->data[q->rear]=data;
    }
    return q;
}

//deleting from the queue
int delete(queue *q){
    int deleted_data=0;
    if(q->front==-1 || q->front > q->rear){
        printf("Underflow condition......Queue is empty");
        return -1;
    }
    else{
        deleted_data=q->data[q->front];
        q->front=q->front+1;
        return deleted_data;
    }
    return deleted_data;    
}

//displaying the queue
void display(queue *q){
    if(q->front==-1 || q->front>q->rear){
        printf("Queue is empty\n");
    }
    else{
        int temp=q->front;
        while(temp <= q->rear){
            printf("%d\n", q->data[temp]);
            temp++;
        }
    }
}

int main(){
    queue q;
    q.front=-1;
    q.rear=-1;
    insert(&q, 1);
    insert(&q, 2);
    insert(&q, 3);
    insert(&q, 4);
    delete(&q);
    display(&q);
  return 0;  
}