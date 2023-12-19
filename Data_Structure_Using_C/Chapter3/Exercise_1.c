/*
Consider an array MARKS[20][5] which stores the
marks obtained by 20 students in 5 subjects. Now
write a program to

(a) - find the average marks in each subject
(b) - average mark of every student
(c) - find every student who has below a 50 in class
*/

#include <stdio.h>

int subject_average();
int student_average();
int below_50();
int grades[20][5] = {{50, 50, 50, 50, 50}, {60, 60, 60, 60, 60}, {70, 70, 70, 70, 70}, {70, 70, 70, 70, 70}, {70, 70, 70, 70, 70}, {60, 60, 60, 60, 60}, {50, 50, 50, 50, 50}, {50, 50, 50, 50, 50}, {50, 50, 50, 50, 50}, {50, 50, 50, 50, 50}, {60, 60, 60, 60, 60}, {60, 60, 60, 60, 60}, {60, 60, 60, 60, 60}, {60, 60, 60, 60, 60}, {60, 60, 60, 60, 60}, {60, 60, 60, 60, 60}, {60, 60, 60, 60, 60}, {60, 60, 60, 60, 60}, {60, 60, 60, 60, 60}, {60, 60, 60, 60, 60}};

int main()
{
    char function_chosen[] = "";
    printf("Input which sub-program you want: ");
    scanf("%s", &function_chosen);
    printf("the function that has been chosen is: %c\n", function_chosen[0]);

    if (function_chosen[0] == 'a')
    {
        subject_average();
    }
    if (function_chosen[0] == 'b')
    {
        student_average();
    }
    if (function_chosen[0] == 'c')
    {
        below_50();
    }
}

subject_average()
{
    printf("subject average is being called\n");
    double subject_average_value = 0;
    // loop through each index in the row and take the average, then do that for each column value
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            subject_average_value = grades[i][j] + subject_average_value;
        }
        subject_average_value /= 20;
        printf("The average value for subject %d is: %lf\n", j + 1, subject_average_value);
        subject_average_value = 0;
    }
}

student_average()
{
    printf("\nstudent average is being called\n");
    double all_student_average_value = 0;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            all_student_average_value = grades[i][j] + all_student_average_value;
        }
    }
    printf("The average grade for all students across all grades is: %lf\n", all_student_average_value / 100);
}

below_50()
{
    printf("below 50 is being called\n");
    double student_average_value = 0;
    // loop through each index in the row and take the average, then do that for each column value
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            student_average_value = grades[i][j] + student_average_value;
        }
        student_average_value /= 5;
        if (student_average_value <= 50)
        {
            printf("student %d has below a 50\n", i);
        }
        student_average_value = 0;
    }
}
