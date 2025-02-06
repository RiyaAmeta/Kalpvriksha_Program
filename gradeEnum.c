#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    A,
    B,
    C,
    D,
    F
}grade;

typedef struct node{
    char *name;
    grade type;
    struct node *next;
}node;

int isValid(char type){
    return (type == 'A' || type == 'B' || type == 'C' || type == 'D' || type == 'F');
}

node *createNewNode(char *name, grade type){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->name = (char *)malloc(strlen(name) * sizeof(char));
    strcpy(newNode->name, name);
    newNode->type = type;
    newNode->next = NULL;
    
    return newNode;
}

void insertData(node **head, char *name, grade type){
    node *newNode = createNewNode(name, type);
    node *temp = *head;
    if(*head == NULL || (*head)->type > newNode->type){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    temp = *head;
    node *prev = NULL;
    while(temp != NULL && temp->type <= newNode->type){
        prev = temp;
        temp = temp->next;
    }
  
    newNode->next = prev->next;
    prev->next = newNode;
}

void display(node *head){
    if(head == NULL){
        return;
    }
    node *temp = head;
    while(temp != NULL){
        printf("Name: %s ", temp->name);
      
        switch(temp->type){
            case A:
                printf("A\n");
                break;
            case B:
                printf("B\n");
                break;
            case C:
                printf("C\n");
                break;
            case D:
                printf("D\n");
                break;
            case F:
                printf("F\n");
                break;
            default:
                break;
        }
        temp = temp->next;
    }
}

grade getType(char type){
    if(type == 'A'){
        return A;
    }
    else if(type == 'B'){
        return B;
    }
    else if(type == 'C'){
        return C;
    }
    else if(type == 'D'){
        return D;
    }
    else if(type == 'F'){
        return F;
    }
}

int main(){
    node *head = NULL;
    int choice;
    char type;
    do{
        char *name = (char *)malloc(100 * sizeof(char));
        printf("Enter the name: ");
        scanf("\n");
        scanf("%[^\n]", name);
    
        printf("Enter the type of grades: ");
        scanf("\n");
        scanf("%c", &type);
        
        if(!isValid(type)){
            printf("Invlaid grade");
            continue;
        }
        grade priority = getType(type);
        insertData(&head, name, priority);
        printf("Enter choice 1 if you want to add more, or 0 if not more");
        scanf("%d", &choice);
    }while(choice == 1);
    
    
    display(head);
    return 0;
}
