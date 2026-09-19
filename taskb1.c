#include <conio.h>
#include <stdio.h>

int main()
{
    int season, roomType, nights;
    float rate, total, discount, finalPrice;
    
	printf("===HOTEL BOOKING SYSYTEM===\n\n");
    printf("Enter season:\n\n");
    printf("1. Peak\n"); // peak = charges more
    printf("2. Off-Peak\n"); // resonable charges
    scanf("%d", &season);
	printf("-------------\n\n");
    printf("Enter room type:\n\n");
    printf("1. Standard\n");
    printf("2. Deluxe\n");
    printf("3. Suite\n");
    scanf("%d", &roomType);
	printf("-------------\n\n");
    printf("Enter number of nights: "); // per night stay
    scanf("%d", &nights);
		printf("-------------\n\n");
		
    if (season == 1)
    {
        if (roomType == 1)
            rate = 5000;
        else if (roomType == 2)
            rate = 8000;
        else if (roomType == 3)
            rate = 12000;
        else
        {
            printf("Invalid room type.\n"); // if user enter other than 1,2 and 3
            return 0;
        }
    }
    else if (season == 2)
    {
        if (roomType == 1)
            rate = 3000;
        else if (roomType == 2)
            rate = 5000;
        else if (roomType == 3)
            rate = 8000;
        else
        {
            printf("Invalid room type.\n");
            return 0;
        }
    }
    else
    {
        printf("Invalid season.\n");
        return 0;
    }

    total = rate * nights;

    if (nights > 7)
        discount = total * 0.15;
    else
        discount = 0;

    finalPrice = total - discount;
	printf(" ------Reciept------\n");
    printf("\nTotal Price = Rs. %.2f", total);
    printf("\nDiscount = Rs. %.2f\a", discount);
    printf("\nFinal Price = Rs. %.2f\n", finalPrice);
    getch();
    return 0;
}


