#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[100];
    int age;
}User;

void createUser(){
    FILE *file = fopen("users.txt", "a");
    if(!file){
        printf("Error opening file!\n");
        return;
    }
    User user;
    printf("Enter user id: ");
    scanf("%d", &user.id);
    getchar();
    printf("Enter user name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0';
    printf("Enter user age: ");
    scanf("%d", &user.age);

    fprintf(file, "ID: %d\nName: %s\nAge: %d\n\n", user.id, user.name, user.age);
    printf("New User created successfully.\n");
    fclose(file);
};

void displayUser(){
    FILE *file = fopen("users.txt", "r");
    if(!file){
        printf("Error opening file or no data to found\n");
        return;
    }
    char line[150];
    printf("\nUser List:\n");
    while(fgets(line, sizeof(line), file)){
        printf("%s", line);
    }
    fclose(file);
};

void updateUser(){
    FILE *file = fopen("users.txt", "r");
    FILE *tempf = fopen("tempf.txt", "w");
    if(!file || !tempf){
        printf("Error opening file!\n");
        return;
    }
    int id, found =0;
    User user;
    printf("Enter user ID you want to update: ");
    scanf("%d", &id);
    getchar();
    char line[150];
    while(fgets(line, sizeof(line), file)){
        if(scanf(line, "ID: %d", &user.id)==1 && user.id ==id){
            found =1;
            printf("Enter new name: ");
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = '\0';
            printf("Enter new age: ");
            scanf("%d", &user.age);
            getchar();
            fprintf(tempf, "ID: %d\nName: %s\nAge: %d\n\n",user.id, user.name,user.age);
            
            fgets(line, sizeof(line), file);
            fgets(line, sizeof(line), file);
    }else{
        fputs(line, tempf);
    }
    
}
fclose(file);
fclose(tempf);

if(found){
    remove("users.txt");
    rename("tempf.txt", "users.txt");
    printf("User updated successfully\n");
}
else{
    remove("tempf.txt");
    printf("User not found");
}
};

void deleteUser(){
    FILE *file = fopen("users.txt", "r");
    FILE *tempf = fopen("tempf.txt","w");
    if(!file || !tempf){
        printf("Error opening file!\n");
        return;
    }
    int id, found =0;
    User user;
    printf("Enter user id you want to delete: ");
    scanf("%d",&id);
    getchar();
    char line[150];
    while (fgets(line, sizeof(line), file))
    {
        if(sscanf(line, "ID: %d", &user.id)==1 && user.id ==id){
            found=1;
            fgets(line, sizeof(line), file);
            fgets(line, sizeof(line), file);
        }else{
            fputs(line, tempf);
        }
    }
    fclose(file);
    fclose(tempf);

    if(found){
        remove("users.txt");
        rename("tempf.txt", "users.txt");
        printf("User deleted successfully!");
    }else{
        remove("tempf.txt");
        printf("User not found");
    }
};

int main(){
    int choice;

    while (1)
    {
        printf("\n CRUD Operations in File\n");
        printf("1. Create new User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            createUser();
            break;
        case 2:
            displayUser();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice, Please try again.\n");
            
        }
    }
    return 0;
}

