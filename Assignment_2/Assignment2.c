#include<stdio.h>
#include<string.h>
void add_new_user();
void display_list_of_users();
void update_user_info();
void delete_user();
int ID[100];
char name[100][22];
int age[100];
int main(){
    // FILE *fptr;
    // fptr = fopen("users.txt","a");
    int ch;
    while (1)
    {
        printf("1- Add new user\n");
        printf("2- Display all users\n");
        printf("3-Update the user details, provide ID\n");
        printf("4- Delete a user, provide ID\n");
        printf("5-Exit the menu\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        if(ch==1){
            add_new_user();
            
        }
        if(ch==2){
            display_list_of_users();
        }
        if(ch==3){
            update_user_info();
        }
        if(ch==4){
            delete_user();
        }
        if(ch==5){
            break;
        }
    }
    
}
void add_new_user(){
    FILE *fptr;
    fptr = fopen("users.txt","a");
    int i =0;
    while (ID[i]!=0&&i<100){
        i++;
        printf("%d",ID[i]);
    }
    printf("Enter unique user ID: ");
    scanf("%d",&ID[i]);
    fprintf(fptr,"ID : %d\n",ID[i]);
    printf("Enter user name: ");
    scanf("%s",&name[i]);
    fprintf(fptr,"Name : %s\n",name[i]);
    printf("Enter user age: ");
    scanf("%d",&age[i]);
    fprintf(fptr,"Age : %d\n",age[i]);
    return;
    // fprintf(fptr,"\n");
    fclose(fptr);
}
void display_list_of_users(){
    FILE *fptr;
    fptr = fopen("users.txt","r");
    if(fptr==NULL){
        printf("FIle dosen't exist.\n");
        return;
    }
    char ch;
    while((ch=fgetc(fptr))!=EOF){
        printf("%c",ch);
    }
    fclose(fptr);
}
void update_user_info(){
    int i=0, IDu;
    char nameU[22];
    int ageU;
    printf("Enter ID to be updates : ");
    scanf("%d",&IDu);
    for (i = 0; i < 100; i++){
        if(ID[i]==IDu){
            printf("Enter new name: ");
            scanf("%s",nameU);
            strcpy(name[i],nameU);
            printf("Enter new age: ");
            scanf("%d", &ageU);
            age[i]=ageU;
            FILE *fptr = fopen("users.txt","w");
            for (int j =0;ID[j]!=0 && j<100;j++){
                fprintf(fptr,"ID : %d\n",ID[j]);
                fprintf(fptr,"Name : %s\n",name[j]);
                fprintf(fptr,"Age : %d\n",age[j]);
            }
            fclose(fptr);
            return;
    
        }}
}
void delete_user(){
    int i=0, IDu;
    // char nameU[22];
    // int ageU[22];
    printf("Enter ID to be deleted: ");
    scanf("%d",&IDu);
    for (i = 0; i < 100; i++){
        if (ID[i] == IDu) {
            for (int j = i; j < 99; j++) {
                ID[j] = ID[j + 1];
                strcpy(name[j], name[j + 1]);
                age[j]=age[j + 1];
        }
        FILE *fptr = fopen("users.txt","w");
            for (int j =0;ID[j]!=0 && j<100;j++){
                fprintf(fptr,"ID : %d\n",ID[j]);
                fprintf(fptr,"Name : %s\n",name[j]);
                fprintf(fptr,"Age : %d\n",age[j]);
            }
            fclose(fptr);
        return;
    }
}
}
