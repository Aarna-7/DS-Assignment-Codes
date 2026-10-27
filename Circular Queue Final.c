#include <stdio.h>
#include <string.h>

struct Circularqueue
{
    int jobid;
    char jobtitle[10];
};

struct Circularqueue q[15];
int front = 0;
int rear = -1;
int count = 0;

int isfull()
{
    if (count == 15)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (count == 0)
        return 1;
    else
        return 0;
}

void add(int jobid, char jobtitle[10])
{
    if (isfull() == 0)
    {
        rear = (rear + 1) % 15;

        q[rear].jobid = jobid;
        strcpy(q[rear].jobtitle, jobtitle);

        if (count == 0)
            front = rear;

        count++;
    }
    else
        printf("The queue is full.\n");
}

void delete()
{
    if (isempty() == 0)
    {
        printf("Deleted Job ID: %d\n", q[front].jobid);
        printf("Deleted Job Title: %s\n", q[front].jobtitle);

        front = (front + 1) % 15;
        count--;
    }
    else
    {
        printf("The queue is empty.\n");
    }
}

void display()
{
    int i;
    int j;

    if (isempty() == 1)
    {
        printf("The queue is empty.\n");
        return;
    }

    i = front;

    for (j = 0; j < count; j++)
    {
        printf("%d %s\n", q[i].jobid, q[i].jobtitle);
        i = (i + 1) % 15;
    }
}

int main()
{
    int x;
    int jobid;
    char jobtitle[10];
    int flag = 0;

    while (flag == 0)
    {
        printf("\n1. Add\n2. Delete\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &x);

        switch (x)
        {
            case 1:
                printf("Enter the Job ID: ");
                scanf("%d", &jobid);

                printf("Enter the Job Title: ");
                scanf("%9s", jobtitle);

                add(jobid, jobtitle);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                flag = 1;
                break;

            default:
                printf("Invalid Input\n");
        }
    }

    return 0;
}