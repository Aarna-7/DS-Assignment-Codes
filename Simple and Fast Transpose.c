#include <stdio.h>

void Compact_Form(int A[20][20], int B[100][3], int rows, int cols)
{
    int i, j, k = 1;

    B[0][0] = rows;
    B[0][1] = cols;
    B[0][2] = 0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }

    B[0][2] = k - 1;
}

void Simple_Transpose(int B[100][3], int C[100][3])
{
    int i, j, k = 1;
    int rows = B[0][0];
    int cols = B[0][1];
    int terms = B[0][2];

    C[0][0] = cols;
    C[0][1] = rows;
    C[0][2] = terms;

    for (i = 0; i < cols; i++)
    {
        for (j = 1; j <= terms; j++)
        {
            if (B[j][1] == i)
            {
                C[k][0] = B[j][1];
                C[k][1] = B[j][0];
                C[k][2] = B[j][2];
                k++;
            }
        }
    }
}

void Fast_Transpose(int B[100][3], int C[100][3])
{
    int row_terms[20], starting_pos[20];
    int i, j, cols, terms;

    cols = B[0][1];
    terms = B[0][2];

    C[0][0] = B[0][1];
    C[0][1] = B[0][0];
    C[0][2] = terms;

    for (i = 0; i < cols; i++)
        row_terms[i] = 0;

    for (i = 1; i <= terms; i++)
        row_terms[B[i][1]]++;

    starting_pos[0] = 1;

    for (i = 1; i < cols; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

    for (i = 1; i <= terms; i++)
    {
        j = starting_pos[B[i][1]];

        C[j][0] = B[i][1];
        C[j][1] = B[i][0];
        C[j][2] = B[i][2];

        starting_pos[B[i][1]]++;
    }
}

int main()
{
    int A[20][20], B[100][3], C[100][3], D[100][3];
    int rows, cols, i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            scanf("%d", &A[i][j]);
    }

    Compact_Form(A, B, rows, cols);

    printf("\nCompact Form:\n");
    for (i = 0; i <= B[0][2]; i++)
        printf("%d\t%d\t%d\n", B[i][0], B[i][1], B[i][2]);

    Simple_Transpose(B, C);

    printf("\nSimple Transpose:\n");
    for (i = 0; i <= C[0][2]; i++)
        printf("%d\t%d\t%d\n", C[i][0], C[i][1], C[i][2]);

    Fast_Transpose(B, D);

    printf("\nFast Transpose:\n");
    for (i = 0; i <= D[0][2]; i++)
        printf("%d\t%d\t%d\n", D[i][0], D[i][1], D[i][2]);

    return 0;
}