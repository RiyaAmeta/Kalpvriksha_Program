#include <stdio.h>
#include <string.h>
void AddNewUser();
void DisplayListOfUsers();
void UpdateUserInformaion();
void DeleteUser();
int ID[100];
char Name[100][22];
int Age[100];
int main()
{
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
        scanf("%d", &ch);
        if (ch == 1)
        {
            AddNewUser();
        }
        if (ch == 2)
        {
            DisplayListOfUsers();
        }
        if (ch == 3)
        {
            UpdateUserInformaion();
        }
        if (ch == 4)
        {
            DeleteUser();
        }
        if (ch == 5)
        {
            break;
        }
    }
}
void AddNewUser()
{
    FILE *fptr;
    fptr = fopen("users.txt", "a");
    int i = 0;
    while (ID[i] != 0 && i < 100)
    {
        i++;
        printf("%d", ID[i]);
    }
    printf("Enter unique user ID: ");
    scanf("%d", &ID[i]);
    fprintf(fptr, "ID : %d\n", ID[i]);
    printf("Enter user Name: ");
    scanf("%s", &Name[i]);
    fprintf(fptr, "Name : %s\n", Name[i]);
    printf("Enter user Age: ");
    scanf("%d", &Age[i]);
    fprintf(fptr, "Age : %d\n", Age[i]);
    return;
    // fprintf(fptr,"\n");
    fclose(fptr);
}
void DisplayListOfUsers()
{
    FILE *fptr;
    fptr = fopen("users.txt", "r");
    if (fptr == NULL)
    {
        printf("FIle dosen't exist.\n");
        return;
    }
    char ch;
    while ((ch = fgetc(fptr)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(fptr);
}
void UpdateUserInformaion()
{
    int i = 0, UpdatedID;
    char UpdatedName[22];
    int UpdatedAge;
    printf("Enter ID to be updates : ");
    scanf("%d", &UpdatedID);
    for (i = 0; i < 100; i++)
    {
        if (ID[i] == UpdatedID)
        {
            printf("Enter new Name: ");
            scanf("%s", UpdatedName);
            strcpy(Name[i], UpdatedName);
            printf("Enter new Age: ");
            scanf("%d", &UpdatedAge);
            Age[i] = UpdatedAge;
            FILE *fptr = fopen("users.txt", "w");
            for (int j = 0; ID[j] != 0 && j < 100; j++)
            {
                fprintf(fptr, "ID : %d\n", ID[j]);
                fprintf(fptr, "Name : %s\n", Name[j]);
                fprintf(fptr, "Age : %d\n", Age[j]);
            }
            fclose(fptr);
            return;
        }
    }
}
void DeleteUser()
{
    int i = 0, UpdatedID;
    // char UpdatedName[22];
    // int UpdatedAge[22];
    printf("Enter ID to be deleted: ");
    scanf("%d", &UpdatedID);
    for (i = 0; i < 100; i++)
    {
        if (ID[i] == UpdatedID)
        {
            for (int j = i; j < 99; j++)
            {
                ID[j] = ID[j + 1];
                strcpy(Name[j], Name[j + 1]);
                Age[j] = Age[j + 1];
            }
            FILE *fptr = fopen("users.txt", "w");
            for (int j = 0; ID[j] != 0 && j < 100; j++)
            {
                fprintf(fptr, "ID : %d\n", ID[j]);
                fprintf(fptr, "Name : %s\n", Name[j]);
                fprintf(fptr, "Age : %d\n", Age[j]);
            }
            fclose(fptr);
            return;
        }
    }
}
