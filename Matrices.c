#include <stdio.h>

void accept_matrix(int mat[20][20],int r,int c);
void display_matrix(int mat[20][20],int r,int c);
void transpose_matrix(int mat[20][20],int tr[20][20],int r,int c);
void add_matrix(int mat1[20][20], int mat2[20][20],int result[20][20],int r,int c);
void sub_matrix(int mat1[20][20],int mat2[20][20],int result[20][20],int r, int c);
int multi_matrix(int mat1[20][20],int mat2[20][20],int result[20][20],int r1, int c1,int r2,int c2);

void accept_matrix(int mat[20][20],int r,int c){
    printf("Enter the elements of the matrix:");
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void display_matrix(int mat[20][20],int r,int c){
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf(" %d",mat[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int mat[20][20],int tr[20][20],int r,int c){
    for (int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            tr[i][j]=mat[j][i];
        }
    }
display_matrix(tr, c, r);}

void add_matrix(int mat1[20][20], int mat2[20][20],int result[20][20],int r,int c){
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            result[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
display_matrix(result, r, c);}

void sub_matrix(int mat1[20][20], int mat2[20][20],int result[20][20],int r,int c){
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            result[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
display_matrix(result, r, c);}

int multi_matrix(int mat1[20][20], int mat2[20][20], int result[20][20], int r1, int c1, int r2, int c2)
{
    if (c1 != r2)
        return -1;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                result[i][j] = result[i][j]+ mat1[i][k] * mat2[k][j];
            }
        }
    }
    return 0;
}

int main()
{
    int mat[20][20];
    int tr[20][20];
    int mat1[20][20];
    int mat2[20][20];
    int result[20][20];
    int r, c;
    int r1, c1, r2, c2;

    printf("Enter rows and columns of matrix: \n");
    scanf("%d%d", &r, &c);

    accept_matrix(mat, r, c);

    printf("The original matrix is: \n");
    display_matrix(mat, r, c);

    printf("The transpose of the matrix is: \n");
    transpose_matrix(mat, tr, r, c);

    printf("\nEnter rows and columns of first matrix: \n");
    scanf("%d%d", &r1, &c1);
    accept_matrix(mat1, r1, c1);

    printf("The first matrix is: \n");
    display_matrix(mat1, r1, c1);

    printf("\nEnter rows and columns of second matrix: \n");
    scanf("%d%d", &r2, &c2);
    accept_matrix(mat2, r2, c2);

    printf("The second matrix is: \n");
    display_matrix(mat2, r2, c2);

    if (r1 == r2 && c1 == c2)
    {
        printf("The addition of the 2 matrices is: \n");
        add_matrix(mat1, mat2, result, r1, c1);

        printf("The subtraction of the 2 matrices is: \n");
        sub_matrix(mat1, mat2, result, r1, c1);
    }
    else
    {
        printf("Addition and subtraction are not possible.\n");
    }

    printf("The multiplication of the 2 matrices is: \n");

    if (multi_matrix(mat1, mat2, result, r1, c1, r2, c2) == -1)
    {
        printf("Matrix multiplication is not possible.\n");
    }
    else
    {
        display_matrix(result, r1, c2);
    }

    return 0;
}