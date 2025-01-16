#include <stdio.h>
#include <string.h>

typedef struct
{
    char studentID[20];
    char gameName[20];
} id[10];

void sortIDs(char IDs[10][20], int count)
{
    for (int rowIndex = 0; rowIndex < count - 1; rowIndex++)
    {
        for (int j = rowIndex + 1; j < count; j++)
        {
            if (strcmp(IDs[rowIndex], IDs[j]) > 0)
            {
                char temp[20];
                strcpy(temp, IDs[rowIndex]);
                strcpy(IDs[rowIndex], IDs[j]);
                strcpy(IDs[j], temp);
            }
        }
    }
}

int main()
{
    id S;
    int num;
    printf("Enter the number of students: ");
    scanf("%d", &num);
    getchar();

    char studentsInBadminton[10][20];
    char studentsInCricket[10][20];
    char studentsInTT[10][20];
    int badmintonCount = 0, cricketCount = 0, TTCount = 0;

    printf("Enter ID and game name:\n");
    for (int Index = 0; Index < num; Index++)
    {
        printf("Enter student ID: ");
        fgets(S[Index].studentID, 20, stdin);
        S[Index].studentID[strcspn(S[Index].studentID, "\n")] = '\0';
        printf("Enter game name: ");
        fgets(S[Index].gameName, 20, stdin);
        S[Index].gameName[strcspn(S[Index].gameName, "\n")] = '\0';

        if (strcmp(S[Index].gameName, "badminton") == 0)
        {
            strcpy(studentsInBadminton[badmintonCount++], S[Index].studentID);
        }
        else if (strcmp(S[Index].gameName, "cricket") == 0)
        {
            strcpy(studentsInCricket[cricketCount++], S[Index].studentID);
        }
        else if (strcmp(S[Index].gameName, "TT") == 0)
        {
            strcpy(studentsInTT[TTCount++], S[Index].studentID);
        }
    }

    printf("Students enrolled in all three games:\n");
    int found = 0;
    for (int badmintonIndex = 0; badmintonIndex < badmintonCount; badmintonIndex++)
    {
        for (int cricketIndex = 0; cricketIndex < cricketCount; cricketIndex++)
        {
            for (int TTIndex = 0; TTIndex < TTCount; TTIndex++)
            {
                if (strcmp(studentsInBadminton[badmintonIndex], studentsInCricket[cricketIndex]) == 0 && strcmp(studentsInBadminton[badmintonIndex], studentsInTT[TTIndex]) == 0)
                {
                    printf("%s\n", studentsInBadminton[badmintonIndex]);
                    found = 1;
                }
            }
        }
    }
    if (!found)
    {
        printf("-1\n");
    }

    printf("\nAll unique students enrolled in at least one game:\n");
    char uniqueStudents[30][20];
    int uniqueCount = 0;

    for (int uniqueRow = 0; uniqueRow < badmintonCount; uniqueRow++)
    {
        int isUnique = 1;
        for (int uniqueCol = 0; uniqueCol < uniqueCount; uniqueCol++)
        {
            if (strcmp(studentsInBadminton[uniqueRow], uniqueStudents[uniqueCol]) == 0)
            {
                isUnique = 0;
                break;
            }
        }
        if (isUnique)
        {
            strcpy(uniqueStudents[uniqueCount++], studentsInBadminton[uniqueRow]);
        }
    }

    for (int uniqueRow = 0; uniqueRow < cricketCount; uniqueRow++)
    {
        int isUnique = 1;
        for (int uniqueCol = 0; uniqueCol < uniqueCount; uniqueCol++)
        {
            if (strcmp(studentsInCricket[uniqueRow], uniqueStudents[uniqueCol]) == 0)
            {
                isUnique = 0;
                break;
            }
        }
        if (isUnique)
        {
            strcpy(uniqueStudents[uniqueCount++], studentsInCricket[uniqueRow]);
        }
    }

    for (int uniqueRow = 0; uniqueRow < TTCount; uniqueRow++)
    {
        int isUnique = 1;
        for (int uniqueCol = 0; uniqueCol < uniqueCount; uniqueCol++)
        {
            if (strcmp(studentsInTT[uniqueRow], uniqueStudents[uniqueCol]) == 0)
            {
                isUnique = 0;
                break;
            }
        }
        if (isUnique)
        {
            strcpy(uniqueStudents[uniqueCount++], studentsInTT[uniqueRow]);
        }
    }

    sortIDs(uniqueStudents, uniqueCount);

    for (int uniqueRow = 0; uniqueRow < uniqueCount; uniqueRow++)
    {
        printf("%s\n", uniqueStudents[uniqueRow]);
    }

    return 0;
}
