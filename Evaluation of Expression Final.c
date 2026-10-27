#include <stdio.h>
#include <string.h>

struct eval
{
    char variable;
    int value;
};

int stack[20];
int top=-1;

void push(int value)
{
    top=top+1;
    stack[top]=value;
}

int pop()
{
    int temp=stack[top];
    top=top-1;
    return temp;
}

int Operand(char symbol)
{
    if ((symbol >= 'A' && symbol <= 'Z') ||
        (symbol >= 'a' && symbol <= 'z') ||
        (symbol >= '0' && symbol <= '9'))
        return 1;
    else
        return 0;
}

void Evaluation_Exp(char Postfix[])
{
    struct eval e[20];

    int i,j,l;
    int n=0;
    int op1,op2,result;
    int found;
    char x;

    l=strlen(Postfix);

    for (i=0;i<l;i++)
    {
        x=Postfix[i];

        if (Operand(x))
        {
            found=0;

            for (j=0;j<n;j++)
            {
                if (e[j].variable==x)
                {
                    found=1;
                    break;
                }
            }

            if (found==0)
            {
                e[n].variable=x;

                printf("Enter value of %c: ",x);
                scanf("%d",&e[n].value);

                n++;
            }
        }
    }


    for (i=0;i<l;i++)
    {
        x=Postfix[i];

        if (Operand(x))
        {
            for (j=0;j<n;j++)
            {
                if (e[j].variable==x)
                {
                    push(e[j].value);
                    break;
                }
            }
        }
        else
        {
            op2=pop();
            op1=pop();

            switch(x)
            {
                case '+':
                    result=op1+op2;
                    break;

                case '-':
                    result=op1-op2;
                    break;

                case '*':
                    result=op1*op2;
                    break;

                case '/':
                    result=op1/op2;
                    break;

                case '%':
                    result=op1%op2;
                    break;

                case '^':
                    result=1;

                    for (j=0;j<op2;j++)
                        result=result*op1;

                    break;

                default:printf("Invalid Character Identitfied.");
                        break;
            }

            push(result);
        }
    }

    result=pop();

    printf("The Evaluated Expression is: %d\n",result);
}

int main()
{
    char Postfix[20];

    printf("Enter the Postfix Expression:\n");
    scanf("%s",Postfix);

    Evaluation_Exp(Postfix);

    return 0;
}
            