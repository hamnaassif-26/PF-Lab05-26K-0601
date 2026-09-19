#include <stdio.h>

int main()
{
    int quantity;
    float price, discount, tax;
    float subtotal, discountedAmount, finalBill;
	printf("ONLINE SHOPPING BILL CALCULATOR\n\n");
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price per item: ");
    scanf("%f", &price);

    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    printf("Enter tax percentage: ");
    scanf("%f", &tax);

    if (quantity <= 0)
    {
        printf("Error: Invalid quantity.\n");
    }
    else if (price < 0)
    {
        printf("Error: Invalid price.\n");
    }
    else if (discount < 0 || discount > 100)
    {
        printf("Error: Invalid discount percentage.\n");
    }
    else if (tax < 0 || tax > 100)
    {
        printf("Error: Invalid tax percentage.\n");
    }
    else
    {
        subtotal = quantity * price;

        discountedAmount =
            subtotal - (subtotal * discount) / 100;

        finalBill =
            discountedAmount +
            (discountedAmount * tax) / 100;

        printf("\n----- SHOPPING BILL -----\n");
        printf("Quantity = %d\n", quantity);
        printf("Price per item = %.2f\n", price);
        printf("Subtotal = %.2f\n", subtotal);
        printf("Discount = %.2f%%\n", discount);
        printf("Discounted Amount = %.2f\n", discountedAmount);
        printf("Tax = %.2f%%\n", tax);
        printf("Final Bill = %.2f\n", finalBill);
    }

    return 0;
}
