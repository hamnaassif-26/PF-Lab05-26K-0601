#include <stdio.h>
int main()
{
    int product_category, customer_type, deliv_distance, deliv_charges = 0,order_amt, order_no, priority_charges, discount_percent, shipping_status, order_process;
    float final_payable_amt, discount = 0;
    const double rateperkm = 10.0;

    printf("======E-Commerce Order Management Sytem======\n\n\n");
    printf("Select Product Category (1-4): \n\n");
    printf("1. Electronic\n");
    printf("2. Clothing\n");
    printf("3. Books\n");
    printf("4. Household\n\n");
    printf("Enter Choice: ");
    scanf("%d", &product_category);

    printf("\nSelect Customer Type: \n\n");
    printf("1. Regular\n");
    printf("2. Premium \n");
    printf("3. Corporate\n\n");
    printf("Enter Choice: ");
    scanf("%d",&customer_type);

    printf("Order Amount: ");
    scanf("%d", &order_amt);

    printf("\nDelivery Distance (km): ");
    scanf("%d", &deliv_distance);

    printf("\nOrder no: ");
    scanf("%d", &order_no);
    
    printf("\n\n");

    switch (product_category)
    {
    case 1: // electronics
        printf("====ELECTRONICS====\n\n");
        switch (customer_type)
        {
        case 1: // regular
            printf("==Custommer Category: Regular==\n\n");
            discount_percent = 5;
            discount = order_amt * 0.05;
            final_payable_amt = order_amt - discount;
            break;

        case 2: // premium
            printf("==Customer Category: Premium==\n\n");
            discount_percent = 10;
            discount = order_amt * 0.1;
            final_payable_amt = order_amt - discount;
            break;

        case 3: // corporate
            printf("Customer Category: Corporate\n\n");
            discount_percent = 15;
            discount = order_amt * 0.15;
            final_payable_amt = order_amt - discount;
            break;

        default:
            printf("Invalid Customer Category");
        }
        break;

    case 2: // clothing
        printf("===CLOTHING===\n\n");

        switch (customer_type)
        {
        case 1:
            printf("==Customer Category: Regular==\n\n");
            discount_percent = 10;
            discount = order_amt * 0.1;
            final_payable_amt = order_amt - discount;
            break;

        case 2:
            printf("==Customer Category: Premium==\n\n");
            discount_percent = 15;
            discount = order_amt * 0.15;
            final_payable_amt = order_amt - discount;
            break;

        case 3:
            printf("==Customer Category: Corporate==\n\n");
            discount_percent = 20;
            discount = order_amt * 0.20;
            final_payable_amt = order_amt - discount;
            break;

        deafult:
            printf("Invaid Customer Type\n\n");
        }
        break;

    case 3: // books
        printf("===BOOKS===\n\n");

        switch (customer_type)
        {
        case 1:
            printf("==Customer Category: Regular==\n\n");
            discount_percent = 8;
            discount = order_amt * 0.08;
            final_payable_amt = order_amt - discount;
            break;

        case 2:
            printf("Customer Category: Premium\n\n");
            discount_percent = 12;
            discount = order_amt * 0.12;
            final_payable_amt = order_amt - discount;
            break;

        case 3:
            printf("Customer Category: Corporate\n\n");
            discount_percent = 18;
            discount = order_amt * 0.18;
            final_payable_amt = order_amt - discount;
            break;

        default:
            printf("Invalid Customer Category entered");
        }
        break;

    case 4: // hoiusehold
        printf("===HOUSEHOLD===\n\n");
        switch (customer_type)
        {
        case 1:
            printf("Customer Category: Regular\n\n");
            discount_percent = 7;
            discount = order_amt * 0.07;
            final_payable_amt = order_amt - discount;
            break;

        case 2:
            printf("Customer Category: Premium\n\n");
            discount_percent = 14;
            discount = order_amt * 0.14;
            final_payable_amt = order_amt - discount;
            break;

        case 3:
            printf("Customer Category: Corporate\n\n");
            discount_percent = 20;
            discount = order_amt * 0.20;
            final_payable_amt = order_amt - discount;
            break;

        default:
            printf("Invalid Customer Category entered\n\n");
        }

    default:
        printf("Invalid Product Category Entered\n\n");
   } 
        if (customer_type == 2 || customer_type == 3 || final_payable_amt >= 5000)
        {
            printf("Elligible for Free Shipping\n");
            deliv_charges = 0;
        }
        else
        {
            printf("Customer Charges will be Applied\n");
            deliv_charges = deliv_distance * rateperkm;
        }

        if (customer_type == 2 || customer_type == 3 && final_payable_amt >= 10000)
        {
            priority_charges = 500;
        }
        else
        {
            priority_charges = 0;
        }
    

    order_process = order_no % 4;

    if (order_process == 0)
        printf("Order Classification: Processing Group 'A'\n\n");
    else if (order_process == 1)
        printf("Order Classification: Processing Group 'B'\n\n");
    else if (order_process == 2)
        printf("Order Classification: Processing Group 'c'\n\n");
    else if (order_process == 3)
        printf("Order Classification: Processing Group 'D'\n\n");
    else
    {
        printf("Order Classification: Processing Group 'F'\n\n");
    }

    printf("Original Order Amount: %d\n", order_amt);
    printf("Applicable Discount Percentage: %d\n", discount_percent);
    printf("Discount Amount: %f\n", discount);
    printf("Final Payable Amount: %f\n", final_payable_amt);
    printf("Delivery Distance: %d\n", deliv_distance);
    printf("Delivery Charges: %d\n", deliv_charges);
    printf("Priority Charges: %d\n", priority_charges);
    printf("Total Amount Payable: %.2f\n", final_payable_amt);

    return 0;
}
