#include <stdio.h>
#include <stdlib.h>

struct Coach
{
    int coachNumber;
    struct Coach *next;
};

struct Coach *head = NULL;

// Function prototypes
void addCoachFront(int num);
void addCoachEnd(int num);
void removeFrontCoach();
void searchCoach(int num);
int countCoaches();
void displayTrain();

int main()
{
    int choice, num;

    do
    {
        printf("\n====== TRAIN MANAGEMENT MENU ======\n");
        printf("1. Add Coach at Front\n");
        printf("2. Add Coach at End\n");
        printf("3. Remove Front Coach\n");
        printf("4. Search Coach\n");
        printf("5. Display Train\n");
        printf("6. Count Coaches\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter coach number: ");
            scanf("%d", &num);
            addCoachFront(num);
            break;

        case 2:
            printf("Enter coach number: ");
            scanf("%d", &num);
            addCoachEnd(num);
            break;

        case 3:
            removeFrontCoach();
            break;

        case 4:
            printf("Enter coach number to search: ");
            scanf("%d", &num);
            searchCoach(num);
            break;

        case 5:
            displayTrain();
            break;

        case 6:
            printf("Total Coaches: %d\n", countCoaches());
            break;

        case 0:
            printf("Exiting system...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}

// Add coach at front (engine side)
void addCoachFront(int num)
{
    struct Coach *newCoach = (struct Coach *)malloc(sizeof(struct Coach));
    if (newCoach == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newCoach->coachNumber = num;
    newCoach->next = head;
    head = newCoach;

    printf("Coach %d added at the front.\n", num);
}

// Add coach at end (last coach)
void addCoachEnd(int num)
{
    struct Coach *newCoach = (struct Coach *)malloc(sizeof(struct Coach));
    if (newCoach == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newCoach->coachNumber = num;
    newCoach->next = NULL;

    if (head == NULL)
    {
        head = newCoach;
    }
    else
    {
        struct Coach *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newCoach;
    }

    printf("Coach %d added at the end.\n", num);
}

// Remove coach from the front
void removeFrontCoach()
{
    if (head == NULL)
    {
        printf("Train has no coaches! Nothing to remove.\n");
        return;
    }

    struct Coach *temp = head;
    head = head->next;

    printf("Removed Coach %d\n", temp->coachNumber);
    free(temp);
}

// Search for a coach in the train
void searchCoach(int num)
{
    struct Coach *temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->coachNumber == num)
        {
            printf("Coach %d found at position %d\n", num, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Coach %d not found in the train.\n", num);
}

// Count total coaches
int countCoaches()
{
    int count = 0;
    struct Coach *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Display the current train
void displayTrain()
{
    if (head == NULL)
    {
        printf("Train is empty!\n");
        return;
    }

    struct Coach *temp = head;
    printf("Train Coaches Order: ");

    while (temp != NULL)
    {
        printf("[C-%d] -> ", temp->coachNumber);
        temp = temp->next;
    }
    printf("NULL\n");
}
