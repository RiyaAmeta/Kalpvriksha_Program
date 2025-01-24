#include <stdio.h>

void towerOfHanoi(int disk, char source, char destination, char helper)
{
    if (disk == 1)
    {
        printf("Move disk 1 from %c to %c.\n", source, destination);
        return;
    }
    towerOfHanoi(disk - 1, source, helper, destination);
    printf("Move disk %d from %c to %c.\n", disk, source, destination);
    towerOfHanoi(disk - 1, helper, destination, source);
}
int main()
{
    int disk;
    scanf("%d", &disk);
    towerOfHanoi(disk, 'A', 'C', 'B');
    return 0;
}
