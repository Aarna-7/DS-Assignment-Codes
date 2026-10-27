#include <stdio.h>
#include <string.h>

struct LQ
{
    int jobid;
    char jobtitle[10];
};

struct LQ que[15];
int front = -1;
int rear = -1;

int isfull()
{
    if (rear == 14)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (rear == front)
        return 1;
    else
        return 0;
}

void add(int jobid, char jobtitle[10])
{
    if (isfull() == 0)
    {
        rear = rear + 1;
        que[rear].jobid = jobid;
        strcpy(que[rear].jobtitle, jobtitle);
    }
    else
        printf("The queue is full.\n");
}

int delete()
{
    int jobid;

    if (isempty() == 0)
    {
        front = front + 1;

        jobid = que[front].jobid;

        printf("Deleted Job ID: %d\n", jobid);
        printf("Deleted Job Title: %s\n", que[front].jobtitle);

        return jobid;
    }
    else
    {
        printf("The queue is empty.\n");
        return -1;
    }
}

void display()
{
    if (isempty() == 1)
    {
        printf("The queue is empty.\n");
        return;
    }

    for (int i = front + 1; i <= rear; i++)
    {
        printf("%d %s\n", que[i].jobid, que[i].jobtitle);
    }
}

int main()
{
    int x;
    int jobid;
    char jobtitle[10];

    printf("\n1. Add");
    printf("\n2. Delete");
    printf("\n3. Display");
    printf("\nEnter your choice: ");
    scanf("%d", &x);

    switch (x)
    {
        case 1:{
            printf("Enter the Job ID: ");
            scanf("%d", &jobid);

            printf("Enter the Job Title: ");
            scanf("%s", jobtitle);

            add(jobid, jobtitle);
            break;}

        case 2:{
            delete();
            break;}

        case 3:{
            display();
            break;}

        default:
            printf("Invalid Input");
    }

    return 0;
}

