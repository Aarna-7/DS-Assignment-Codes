#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

void create_polynomial(struct node *head)
{
    struct node *temp, *last;
    int n, i;

    last = head;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));

        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &temp->coeff, &temp->exp);

        last->next = temp;
        last = temp;
    }

    last->next = head;
}

void addPolynomial(struct node *head1,
                   struct node *head2,
                   struct node *head3)
{
    struct node *p, *q, *temp, *last;

    p = head1->next;
    q = head2->next;
    last = head3;

    while (p != head1 && q != head2)
    {
        temp = (struct node *)malloc(sizeof(struct node));

        if (p->exp == q->exp)
        {
            temp->coeff = p->coeff + q->coeff;
            temp->exp = p->exp;
            p = p->next;
            q = q->next;
        }
        else if (p->exp > q->exp)
        {
            temp->coeff = p->coeff;
            temp->exp = p->exp;
            p = p->next;
        }
        else
        {
            temp->coeff = q->coeff;
            temp->exp = q->exp;
            q = q->next;
        }

        last->next = temp;
        last = temp;
    }

    while (p != head1)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff = p->coeff;
        temp->exp = p->exp;

        last->next = temp;
        last = temp;
        p = p->next;
    }

    while (q != head2)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff = q->coeff;
        temp->exp = q->exp;

        last->next = temp;
        last = temp;
        q = q->next;
    }

    last->next = head3;
}

void display_polynomial(struct node *head)
{
    struct node *temp;

    temp = head->next;

    if (temp == head)
    {
        printf("0");
        return;
    }

    while (temp != head)
    {
        printf("%dx^%d", temp->coeff, temp->exp);

        temp = temp->next;

        if (temp != head)
            printf(" + ");
    }

    printf("\n");
}

int main()
{
    struct node *head1, *head2, *head3;

    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head3 = (struct node *)malloc(sizeof(struct node));

    head1->next = head1;
    head2->next = head2;
    head3->next = head3;

    printf("Enter first polynomial:\n");
    create_polynomial(head1);

    printf("Enter second polynomial:\n");
    create_polynomial(head2);

    printf("First polynomial: ");
    display_polynomial(head1);

    printf("Second polynomial: ");
    display_polynomial(head2);

    addPolynomial(head1, head2, head3);

    printf("Sum: ");
    display_polynomial(head3);

    return 0;
}