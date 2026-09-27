#include <stdio.h>
int main()
{
    int department,theory_marks,seat_category;
    float practical_marks,attend_percent;

    printf("======Student Result Management System======\n\n\n");
    printf("Select Department (1-4): \n\n");
    printf("1. Computer Science\n");
    printf("2. Electrical Engineering\n");
    printf("3. Bussiness Administration\n");
    printf("4. Mathematics\n\n");
    printf("Enter Choice: ");
    scanf("%d", &department);

    printf("\nTheory marks:");
    scanf("%d", &theory_marks);
    printf("\nPractical marks:");
    scanf("%f", &practical_marks);
    printf("\nAttendence percentage: ");
    scanf("%f", &attend_percent);
	
	printf("\n");
	
    switch (department)
    {
	    case 1: // cs
	        printf("=Computer Science Department=\n\n");
	        if (theory_marks >= 50 && practical_marks >= 40 && attend_percent >= 75)
	        {
	            printf("Student is Passed\n\n");
	        }
	        else
	        {
	            printf("Student is Failed\n\n");
	
	        }
	    break;

	    case 2: //ee
	        printf("Electrical Engineering Department\n\n");
	        if (theory_marks>=55 && practical_marks>=45 && attend_percent>=75)
	        {
	            printf("Student is Passed\n\n");
	        }    
	        else
	        {
	            printf("Student is Failed\n\n");
	        }
	    break;

	    case 3: //bba
	        printf("BBA Department\n\n");
	        if(theory_marks>=50 && practical_marks>=35 && attend_percent>=80)
	        {
	            printf("Student is Passed\n\n");
	        }
	        else
	        {
	            printf("Student is Failed\n\n");
	        }
	    break;

	    case 4: //math
	        printf("Mathematics Department\n\n");
	        if(theory_marks>=60 && practical_marks>=40 && attend_percent>=75)
	        {
	            printf("Student is Passed\n\n");
	        }
	        else
	        {
	            printf("Student is Failed");
	        }
	    break;

	    default:
	    printf("Invalid Deparatmnet Number Entered!\n\n");

    }

    if(theory_marks>=85 && practical_marks>=80 && attend_percent>=90)
    {
        printf("Student is elligible for distinction\n\n");
    }
    else
    {
        printf("Keep Progressing for Distinction\n\n");
    }

    seat_category = theory_marks % 3;
    
    if(seat_category==0)
    {
        printf("SEAT CATEGORY: 'A' \n\n");
    }
    else if(seat_category==1)
    {
        printf("SEAT CATEGORY: 'B' \n\n");
    }
    else if(seat_category==2)
    {
        printf("SEAT CATEGORY: 'C' \n\n");
    }
    else
    {
        printf("Invalid Seat Category\n\n");
    }

    return 0;


}
