#include <stdio.h>
#include <string.h>

#define MAX_TRACKS 100

struct musicTrackInfo
{
    int trackID;
    char title[100];
    char artist[100];
    char genre[50];
    float duration;
}musicList[MAX_TRACKS];

int trackCount = 0;
void addTrack()
{
    printf("Enter track ID: ");
    scanf("%d", &musicList[trackCount].trackID);
    getchar();

    printf("Enter title: ");
    fgets(musicList[trackCount].title, 100, stdin);
    musicList[trackCount].title[strcspn(musicList[trackCount].title, "\n")] = '\0';
    printf("Enter artist: ");
    fgets(musicList[trackCount].artist, 100, stdin);
    musicList[trackCount].artist[strcspn(musicList[trackCount].artist, "\n")] = '\0';
    printf("Enter genre: ");
    fgets(musicList[trackCount].genre, 50, stdin);
    musicList[trackCount].genre[strcspn(musicList[trackCount].genre, "\n")] = '\0';
    printf("Enter duration (in minutes): ");
    scanf("%f", &musicList[trackCount].duration);

    trackCount++;
    printf("The music track has been added successfully.\n");
}

void deleteTrack()
{
    int trackID, trackIterator, found = 0;

    printf("Enter Track ID to delete: ");
    scanf("%d", &trackID);

    for (trackIterator = 0; trackIterator < trackCount; trackIterator++)
    {
        if (musicList[trackIterator].trackID == trackID)
        {
            found = 1;
            for (int j = trackIterator; j < trackCount - 1; j++)
            {
                musicList[j] = musicList[j + 1];
            }
            trackCount--;
            printf("Track deleted successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Track with ID %d not found.\n", trackID);
    }
}

void displayTracks()
{
    if (trackCount == 0)
    {
        printf("No music tracks available.\n");
        return;
    }

    printf("All Music Tracks:\n");
    for (int trackIterator = 0; trackIterator < trackCount; trackIterator++)
    {
        printf("Track ID: %d\n", musicList[trackIterator].trackID);
        printf("Title: %s\n", musicList[trackIterator].title);
        printf("Artist: %s\n", musicList[trackIterator].artist);
        printf("Genre: %s\n", musicList[trackIterator].genre);
        printf("Duration: %.2f minutes\n\n", musicList[trackIterator].duration);
    }
}

void searchTrack()
{
    char title[100];
    int found = 0;

    getchar();
    printf("Enter Title to search: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int trackIterator = 0; trackIterator < trackCount; trackIterator++)
    {
        if (strcmp(musicList[trackIterator].title, title) == 0)
        {
            printf("Track ID: %d\n", musicList[trackIterator].trackID);
            printf("Title: %s\n", musicList[trackIterator].title);
            printf("Artist: %s\n", musicList[trackIterator].artist);
            printf("Genre: %s\n", musicList[trackIterator].genre);
            printf("Duration: %.2f minutes\n\n", musicList[trackIterator].duration);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No track found with the title '%s'.\n", title);
    }
}

void sortTracks()
{
    struct musicTrackInfo temp;

    for (int trackIterator = 0; trackIterator < trackCount - 1; trackIterator++)
    {
        for (int j = trackIterator + 1; j < trackCount; j++)
        {
            if (strcmp(musicList[trackIterator].title, musicList[j].title) > 0)
            {
                temp = musicList[trackIterator];
                musicList[trackIterator] = musicList[j];
                musicList[j] = temp;
            }
        }
    }

    printf("Music tracks sorted by title.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\nMusic List Management System\n");
        printf("1. Add Music Track\n");
        printf("2. Delete Music Track\n");
        printf("3. Display All Music Tracks\n");
        printf("4. Search for Music Track\n");
        printf("5. Sort Music Tracks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTrack();
            break;
        case 2:
            deleteTrack();
            break;
        case 3:
            displayTracks();
            break;
        case 4:
            searchTrack();
            break;
        case 5:
            sortTracks();
            break;
        case 6:
            printf("Exiting the system...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
