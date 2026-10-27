
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[20];
int top = -1;

char s[20][20];
int t = -1;

/* In-stack priority */
int ISP(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 2;

        case '*':
        case '/':
        case '%':
            return 4;

        case '^':
            return 5;

        case '(':
            return 0;
    }

    return -1;
}

/* Incoming priority */
int ICP(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
        case '%':
            return 3;

        case '^':
            return 6;

        case '(':
            return 7;
    }

    return -1;
}

/* Check whether character is an operand */
int Operand(char ch)
{
    if (isalnum((unsigned char)ch))
        return 1;
    else
        return 0;
}

/* Push character onto stack */
void push(char elem)
{
    stack[++top] = elem;
}

/* Pop character from stack */
char pop()
{
    return stack[top--];
}

/* Infix to Postfix conversion */
void Infix_Postfix(char Infix[], char Postfix[])
{
    int i, j = 0;
    char ch, elem;

    top = -1;

    for (i = 0; Infix[i] != '\0'; i++)
    {
        ch = Infix[i];

        if (ch == ' ')
            continue;

        if (Operand(ch))
        {
            Postfix[j++] = ch;
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                Postfix[j++] = pop();
            }

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   ISP(stack[top]) >= ICP(ch))
            {
                Postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        elem = pop();

        if (elem != '(')
            Postfix[j++] = elem;
    }

    Postfix[j] = '\0';
}

/* Push string onto 2D stack */
void push2(char elem[20])
{
    t++;
    strcpy(s[t], elem);
}

/* Pop string from 2D stack */
void pop2(char elem[20])
{
    strcpy(elem, s[t]);
    t--;
}

/* Postfix to Prefix conversion */
void Postfix_Prefix(char Postfix[], char Prefix[])
{
    int i;
    char op1[20], op2[20], exp[20];

    t = -1;

    for (i = 0; Postfix[i] != '\0'; i++)
    {
        if (Postfix[i] == ' ')
            continue;

        if (Operand(Postfix[i]))
        {
            exp[0] = Postfix[i];
            exp[1] = '\0';
            push2(exp);
        }
        else
        {
            pop2(op2);
            pop2(op1);

            exp[0] = Postfix[i];
            exp[1] = '\0';

            strcat(exp, op1);
            strcat(exp, op2);

            push2(exp);
        }
    }

    pop2(Prefix);
}

int main()
{
    char Infix[20], Postfix[20], Prefix[20];

    printf("Enter infix expression: ");
    scanf("%19s", Infix);

    Infix_Postfix(Infix, Postfix);
    printf("Postfix expression: %s\n", Postfix);

    Postfix_Prefix(Postfix, Prefix);
    printf("Prefix expression: %s\n", Prefix);

    return 0;
}
