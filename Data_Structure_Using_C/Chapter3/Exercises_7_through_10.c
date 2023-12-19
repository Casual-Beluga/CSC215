// 7 - find the sum of the main diagnol of a matrix
// 8 - add two 3x3 matrices
// 9 - find the product of the elements in the diagnol above the main diagonal.
// 10 - count the number of non zero elemts in a 2d array.

#include <stdio.h>

int diagonal_sum();
int matrix_addition();
int above_diagnol();
int non_zero();

int main()
{
    int exercise_choice = 0;
    printf("Please input the number of the exercise you want: ");
    scanf("%d", &exercise_choice);
    if (exercise_choice == 7)
    {
        diagonal_sum();
    }
    if (exercise_choice == 8)
    {
        matrix_addition();
    }
    if (exercise_choice == 9)
    {
        above_diagnol();
    }
    if (exercise_choice == 10)
    {
        non_zero();
    }
}

diagonal_sum()
{

    int matrix[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int sum = 0;
    int j = 0;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + matrix[i][j];
        j++;
    }
    printf("The sum of the values in the main diagnol of the matrix is: %d\n", sum);
}

matrix_addition()
{
    int matrix_one[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix_two[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix_three[3][3] = {0};
    int count = 1;
    printf("[");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix_three[i][j] = matrix_one[i][j] + matrix_two[i][j];
            printf(" %d", matrix_three[i][j]);
            if ((count % 3) == 0)
            {
                printf(" ]");
                printf("\n[");
            }
            count++;
        }
    }
    printf("\b");
}

above_diagnol()
{
    int matrix[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int sum = 1;
    int j = 0;
    for (int i = 1; i < 5; i++)
    {

        sum = sum * matrix[i][j];
        j++;
    }
    printf("The sum of the product of the value above the main diagnol are: %d\n", sum);
}

non_zero()
{
    int non_zero_matrix[4][4] = {{1, 2, 3, 0}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 0, 16}};
    int non_zero_value = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (non_zero_matrix[i][j] == 0)
            {
                non_zero_value = non_zero_value + 1;
            }
        }
    }
    printf("the number of non zero elemts in this matrix is: %d\n", non_zero_value);
}
