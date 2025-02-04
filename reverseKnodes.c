#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *createNewNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(node **head, int data){
    node *newNode = createNewNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void reverse(node *head){
    node *temp = head;
    node *front = NULL;
    node *prev = NULL;
    while(temp != NULL){
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    head = prev;
    return;
}

node *kthnode(node *temp, int k){
    k = k-1;
    while(temp != NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}

node *reverseKNodes(node **head, int k){
    node *temp = *head;
    node *nextNode = NULL;
    node *prevNode = NULL;
    while(temp != NULL){
        node *kth = kthnode(temp, k);
        if(kth == NULL){
            prevNode->next = temp;
            break;
        }
        nextNode = kth->next;
        kth->next = NULL;
        reverse(temp);

        if(temp == *head){
            *head = kth;
        }
        else{
            prevNode->next = kth;
        }
        prevNode = temp;
        temp = nextNode;
        
    }
    return *head;
}

void printList(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    node *head = NULL;
    int n, data;
    printf("Enter the number of nodes in the list: ");
    scanf("%d", &n);
    
    for(int i =0; i < n; i++){
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }
    int k;
    printf("Enter k :");
    scanf("%d", &k);
    node *ans = reverseKNodes(&head, k);
    printList(head);
    return 0;
}
