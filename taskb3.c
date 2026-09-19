#include <stdio.h>

int main()
{
    int mark1, mark2, mark3, mark4, mark5;
    int sum;
    float average;
	printf("Class Result Processing\n\n");
    printf("Enter marks of 5 subjects: ");
    scanf("%d %d %d %d %d",&mark1, &mark2, &mark3, &mark4, &mark5);

    sum = mark1 + mark2 + mark3 + mark4 + mark5;

    average = sum / 5.0;

    if (mark1 < 33 || mark2 < 33 || mark3 < 33 || mark4 < 33 || mark5 < 33)
    {
        printf("Result: Fail - Subject Deficiency\n");
    }
    else if (average >= 80)
    {
        printf("Result: Distinction\n");
    }
    else if (average >= 60)
    {
        printf("Result: Pass\n");
    }
    else
    {
        printf("Result: Fail\n");
    }

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
