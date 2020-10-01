#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

//creating a linked list
node* create_ll(int data){
    node* current;
    current=(node*)malloc(sizeof(node));
    current->data=data;
return current;
}

//adding a node at the end
void add_at_end(node **head, int data ){
    node* new_node=create_ll(data);
    new_node->next=NULL;
    if(*head==NULL){
        *head=new_node;
    }
    else{
        node* temp= *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

//adding a node at the beginning
void add_at_start(node **head, int data){
    node* new_node=create_ll(data);
    new_node->next=*head;
    *head=new_node;
}

//adding node at any position
void add_at_position(node **head, int position, int data){
    node* new_node=create_ll(data);
    int i=1;
    node* temp=*head;
    if(position==1){
        add_at_start(head, data);
    }
    else{
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    }
}

//printing a linked list
void print(node *head){

    while(head!=NULL){
        printf("%d\n", head->data);
        head=head->next;
    }
}
//search in linked list
void search(node  *head, int value){
    node* temp=head;
    int c=1,v=0;
    while(temp!=NULL){
        if(temp->data==value){
            v=c;
            break;
        }
        c++;
        temp=temp->next;
    }
    printf("%d", v);
}

//delete at delete at beginning
int delete_at_begin(node **head){
    int deleted_data;
    node* p;
    if(*head!=NULL){
         p=*head;
         deleted_data=p->data;
         *head=(*head)->next;
         free(p);
    }
    return deleted_data;
}

//delete at any position
int delete_at_position(node **head, int pos){
    node *temp=*head;
    int i=1;
    int deleted_data;
    node *prv;
    if(pos==1){
        deleted_data=delete_at_begin(head);
        return deleted_data;
    }
    while(i<pos-1){
        prv=temp;
        temp=temp->next;
        i++;
    }
    //prv->next=temp->next;
    node *p=temp->next;
    deleted_data = temp->next->data;
    temp->next=temp->next->next;
    free(p);
    return deleted_data;
}

//delete at end
int delete_at_end(node **head){
    int deleted_data;
    node* temp = *head;
    node* pre_node;
    while(temp->next!=NULL){
        pre_node=temp;
        temp=temp->next;
    }
    node *p=temp;
    deleted_data=p->data;
    pre_node->next=NULL;
    free(p);
return deleted_data;
}

//removing duplicates
void removeDuplicates_sortedlist(node** head) {
    node* temp = *head;
    int c=0;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
            c++;
        }

        else{
            c=0;
            temp=temp->next;
        }
    }

}

void reverse_list(node *head){
    node *temp=head;
    node *prv=head;
    node *ptr=head;
    while(ptr->next!=NULL){
        temp=head;
    while(temp->next!=NULL){
        prv=temp;
        temp=temp->next;
    }
    printf("%d\n", temp->data);
    prv->next=NULL;
    if(prv==ptr)
        printf("%d", prv->data);
    }
}

//reversing linked list with recursion
node* reverse(node *head){
    
    node *rev;
    if(head->next==NULL){
        rev=head;
        return rev;
    }
    if(head==NULL){
        return head;
    }
    
    rev=reverse(head->next);
    rev->next->next=rev;
    return rev;

}

//main funtion
int main(){
    node* head=NULL;
    node* tail;
    int n=0;
    printf("Enter the number of data: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        add_at_end(&head, i+1);
    }
    node *rever=reverse(head);
    print(rever);
 return 0;
}
