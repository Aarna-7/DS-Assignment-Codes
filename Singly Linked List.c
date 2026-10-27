
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int RegNo;
    char Name[30];
    struct node *next;
};

struct node *head;

/* Add participant at a given position */
void add()
{
    struct node *newnode, *temp;
    int pos, i = 1;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter Registration Number: ");
    scanf("%d", &newnode->RegNo);

    printf("Enter Name: ");
    scanf("%29s", newnode->Name);

    printf("Enter position: ");
    scanf("%d", &pos);

    temp = head;

    while (i < pos && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (pos < 1 || i != pos)
    {
        printf("Invalid position.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Participant added successfully.\n");
}

/* Remove participant using Registration Number */
void remove_participant()
{
    struct node *temp, *prev;
    int reg;

    if (head->next == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter Registration Number to delete: ");
    scanf("%d", &reg);

    prev = head;
    temp = head->next;

    while (temp != NULL && temp->RegNo != reg)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Participant not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Participant removed successfully.\n");
}

/* Display participants */
void display()
{
    struct node *temp;

    if (head->next == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head->next;

    while (temp != NULL)
    {
        printf("Registration Number: %d, Name: %s\n",
               temp->RegNo, temp->Name);
        temp = temp->next;
    }
}

/* Count participants */
void count()
{
    struct node *temp;
    int cnt = 0;

    temp = head->next;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    printf("Total participants: %d\n", cnt);
}

/* Sort in ascending order of Registration Number */
void sort()
{
    struct node *temp, *temp2;
    int reg;
    char name[30];

    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        for (temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
        {
            if (temp->RegNo > temp2->RegNo)
            {
                reg = temp->RegNo;
                temp->RegNo = temp2->RegNo;
                temp2->RegNo = reg;

                strcpy(name, temp->Name);
                strcpy(temp->Name, temp2->Name);
                strcpy(temp2->Name, name);
            }
        }
    }

    printf("List sorted successfully.\n");
}

/* Reverse using three pointers */
void reverse()
{
    struct node *lastrev, *present, *infuture;

    lastrev = NULL;
    present = head->next;

    while (present != NULL)
    {
        infuture = present->next;
        present->next = lastrev;
        lastrev = present;
        present = infuture;
    }

    head->next = lastrev;

    printf("List reversed successfully.\n");
}

int main()
{
    int choice;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    head->next = NULL;

    do
    {
        printf("\n--- Workshop Enrollment ---\n");
        printf("1. Add Participant\n");
        printf("2. Remove Participant\n");
        printf("3. Display Participants\n");
        printf("4. Count Participants\n");
        printf("5. Sort by Registration Number\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add();
                break;

            case 2:
                remove_participant();
                break;

            case 3:
                display();
                break;

            case 4:
                count();
                break;

            case 5:
                sort();
                break;

            case 6:
                reverse();
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 7);

    while (head->next != NULL)
    {
        struct node *temp = head->next;
        head->next = temp->next;
        free(temp);
    }

    free(head);

    return 0;
}
