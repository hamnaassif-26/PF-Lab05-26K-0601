#include <stdio.h>

int main()
{
    printf("====================================\n");
    printf("       EV CHARGING MANAGEMENT       \n");
    printf("====================================\n\n");

    char vehicle, member, disabled, available;
    float battery, requiredLevel, parkingHours, currentTime;
    float requiredCharging;
    float chargingCost = 0, parkingCost = 0;
    float discount = 0, finalAmount;
    char priority[30];

    printf("Enter Vehicle Type (E/H): ");
    scanf(" %c", &vehicle);

    printf("Enter Current Battery Level: ");
    scanf("%f", &battery);

    printf("Enter Required Charging Level: ");
    scanf("%f", &requiredLevel);

    printf("Enter Expected Parking Duration (hours): ");
    scanf("%f", &parkingHours);

    printf("Enter Current Time (24-hour format): ");
    scanf("%f", &currentTime);

    printf("Are you a member? (Y/N): ");
    scanf(" %c", &member);

    printf("Disabled-person priority? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Is charging station available? (Y/N): ");
    scanf(" %c", &available);

    printf("\n------------------------------------\n");
    printf("Vehicle Type: %c\n", vehicle);
    printf("Current Battery: %.0f%%\n", battery);
    printf("Required Charging Level: %.0f%%\n", requiredLevel);

    /* Checking charging station */
    if (available == 'N' || available == 'n')
    {
        if (vehicle == 'H' || vehicle == 'h')
        {
            printf("Charging unavailable - Parking only.\n");
        }
        else
        {
            printf("No charging slot available.\n");
        }
    }
    else
    {
        /* Checking vehicle eligibility */
        if (vehicle == 'E' || vehicle == 'e')
        {
            printf("Vehicle qualifies for EV charging.\n");

            requiredCharging = requiredLevel - battery;

            if (requiredLevel <= battery)
            {
                printf("No charging required.\n");
            }
            else
            {
                /* Priority checking */
                if (battery <= 15 && requiredLevel >= 80)
                {
                    printf("Charging Priority: Emergency Charging Priority\n");
                    priority[0] = 'E';
                    priority[1] = '\0';
                }
                else if (disabled == 'Y' || disabled == 'y' ||
                        (member == 'Y' || member == 'y') && battery <= 30)
                {
                    printf("Charging Priority: Priority Charging\n");
                    priority[0] = 'P';
                    priority[1] = '\0';
                }
                else
                {
                    printf("Charging Priority: Normal Charging\n");
                    priority[0] = 'N';
                    priority[1] = '\0';
                }

                /* Peak / Off-peak */
                if (currentTime < 17 || currentTime > 22)
                {
                    printf("Time Status: Off-Peak\n");

                    chargingCost = requiredCharging * 35;

                    /* Member discount except emergency */
                    if ((member == 'Y' || member == 'y') && priority[0] != 'E')
                    {
                        discount = chargingCost * 0.20;
                    }
                }
                else
                {
                    printf("Time Status: Peak\n");

                    chargingCost = requiredCharging * 50;
                    discount = chargingCost * 0.10;
                }

                chargingCost = chargingCost - discount;
            }
        }
        else if (vehicle == 'H' || vehicle == 'h')
        {
            if (battery < 40)
            {
                printf("Vehicle qualifies for EV charging.\n");

                requiredCharging = requiredLevel - battery;

                if (requiredLevel <= battery)
                {
                    printf("No charging required.\n");
                }
                else
                {
                    /* Priority checking */
                    if (battery <= 15 && requiredLevel >= 80)
                    {
                        printf("Charging Priority: Emergency Charging Priority\n");
                        priority[0] = 'E';
                        priority[1] = '\0';
                    }
                    else if (disabled == 'Y' || disabled == 'y' ||
                            (member == 'Y' || member == 'y') && battery <= 30)
                    {
                        printf("Charging Priority: Priority Charging\n");
                        priority[0] = 'P';
                        priority[1] = '\0';
                    }
                    else
                    {
                        printf("Charging Priority: Normal Charging\n");
                        priority[0] = 'N';
                        priority[1] = '\0';
                    }

                    /* Peak / Off-peak */
                    if (currentTime < 17 || currentTime > 22)
                    {
                        printf("Time Status: Off-Peak\n");

                        chargingCost = requiredCharging * 35;

                        if ((member == 'Y' || member == 'y') && priority[0] != 'E')
                        {
                            discount = chargingCost * 0.20;
                        }
                    }
                    else
                    {
                        printf("Time Status: Peak\n");

                        chargingCost = requiredCharging * 50;
                        discount = chargingCost * 0.10;
                    }

                    chargingCost = chargingCost - discount;
                }
            }
            else
            {
                printf("Vehicle does not qualify for EV charging.\n");
            }
        }
        else
        {
            printf("Invalid vehicle type.\n");
        }
    }

    /* Parking charges */
    if (parkingHours <= 2)
    {
        parkingCost = 200;
    }
    else if (parkingHours <= 5)
    {
        parkingCost = 400;
    }
    else
    {
        parkingCost = 700;
    }

    /* Disabled person gets free parking */
    if (disabled == 'Y' || disabled == 'y')
    {
        parkingCost = 0;
    }
    else if (member == 'Y' || member == 'y')
    {
        parkingCost = parkingCost - (parkingCost * 0.20);
    }

    /* Long stay warning */
    if (parkingHours > 8)
    {
        printf("Warning: Long-stay warning: Please relocate your vehicle after charging.\n");
    }
    else
    {
        printf("Message: Standard parking duration.\n");
    }

    finalAmount = chargingCost + parkingCost;

    printf("\n====================================\n");
    printf("           BILL SUMMARY             \n");
    printf("====================================\n");

    printf("Charging Cost: Rs. %.2f\n", chargingCost);
    printf("Parking Cost: Rs. %.2f\n", parkingCost);
    printf("Discount: Rs. %.2f\n", discount);
    printf("Final Payable Amount: Rs. %.2f\n", finalAmount);

    return 0;
}
