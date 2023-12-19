// 2 - go through an array and calculate the number of pairs of elements who's value is equal to 50
// 3 - interchange the 2nd element and the 2nd to last element
// 4 - calculate the sum of the squares of the values along the main diagnol of a 2d array
// 5 - compute the sum and mean of a 2d array
#include <stdio.h>

int pairs_of_fifty();
int interchange();
int sum_of_squares();
int mean_and_sum();

int main()
{
    int exercise_numer = 0;
    printf("Please input the number of the exercise you wish to use: ");
    scanf("%d", &exercise_numer);
    if (exercise_numer == 2)
    {
        pairs_of_fifty();
    }
    if (exercise_numer == 3)
    {
        interchange();
    }
    if (exercise_numer == 4)
    {
        sum_of_squares();
    }
    if (exercise_numer == 5)
    {
        mean_and_sum();
    }
}

pairs_of_fifty()
{
    int number_of_pairs = 0;
    int array[100] = {0};
    for (int index = 1; index < 101; index++)
    {
        array[index] = index;
        printf("%d\n", array[index]);
    }
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            if (array[i] + array[j] == 50)
            {
                number_of_pairs++;
            }
        }
    }
    printf("the number of paris that add up to 50, when taking into account 25 + 25 is: %d\n", number_of_pairs);
}

interchange()
{
    int array[100] = {0};
    for (int index = 1; index < 101; index++)
    {
        array[index] = index;
        printf("%d,", array[index]);
    }

    int array_value_one = array[1];
    int array_value_two = array[99];
    array[1] = array_value_two;
    array[99] = array_value_one;
    printf("\n\n");
    for (int index = 1; index < 101; index++)
    {
        printf("%d,", array[index]);
    }
}

sum_of_squares()
{
    int matrix[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int j = 0;
    int sum = 0;
    for (int i = 1; i < 5; i++)
    {
        sum = sum + (matrix[i][j]) * (matrix[i][j]);
        j++;
    }
    printf("%d\n", sum);
}

mean_and_sum()
{
    int sum = 0;
    int matrix[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum = sum + matrix[i][j];
        }
    }
    printf("The mean of this 2d array is: %d\n", sum / 25);
    printf("The sum of this 2d array is: %d\n", sum);
}
