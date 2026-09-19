#include <stdio.h>

int main()
{
    char vehicle, category, permit, emergency;
    int vehicles;
    int zoneA = 0, zoneB = 0, zoneC = 0;
    int accepted = 0, rejected = 0;
    int cars = 0, bikes = 0, vans = 0;
    int spaces, assigned = 0;

    printf("====================================\n");
    printf("   SMART CAMPUS PARKING SYSTEM\n");
    printf("====================================\n\n");

    printf("Enter number of vehicles: ");
    scanf("%d", &vehicles);

    /* Vehicle 1 */
    printf("\nEnter vehicle type (C/B/V): ");
    scanf(" %c", &vehicle);

    printf("Enter category (F/S/G): ");
    scanf(" %c", &category);

    printf("Enter valid permit (Y/N): ");
    scanf(" %c", &permit);

    if (permit == 'N' || permit == 'n')
    {
        printf("Emergency vehicle? (Y/N): ");
        scanf(" %c", &emergency);
    }
    else
    {
        emergency = 'N';
    }

    /* Validate information */
    if ((vehicle != 'C' && vehicle != 'c') &&
        (vehicle != 'B' && vehicle != 'b') &&
        (vehicle != 'V' && vehicle != 'v'))
    {
        printf("Rejected: Invalid vehicle type.\n");
        rejected++;
    }
    else if ((category != 'F' && category != 'f') &&
             (category != 'S' && category != 's') &&
             (category != 'G' && category != 'g'))
    {
        printf("Rejected: Invalid category.\n");
        rejected++;
    }
    else if ((permit != 'Y' && permit != 'y') &&
             (permit != 'N' && permit != 'n'))
    {
        printf("Rejected: Invalid permit value.\n");
        rejected++;
    }
    else
    {
        /* Check permit */
        if (permit == 'N' || permit == 'n')
        {
            if (emergency == 'Y' || emergency == 'y')
            {
                printf("Emergency vehicle accepted.\n");
            }
            else
            {
                printf("Rejected: Invalid permit.\n");
                rejected++;
            }
        }

        if ((permit == 'Y' || permit == 'y') ||
            (emergency == 'Y' || emergency == 'y'))
        {
            assigned = 0;

            /* Faculty */
            if (category == 'F' || category == 'f')
            {
                if (vehicle == 'V' || vehicle == 'v')
                {
                    if (zoneA <= 18)
                    {
                        zoneA = zoneA + 2;
                        assigned = 1;
                    }
                    else
                    {
                        printf("Rejected: No available space in Zone A.\n");
                        rejected++;
                    }
                }
                else
                {
                    if (zoneA < 20)
                    {
                        zoneA++;
                        assigned = 1;
                    }
                    else
                    {
                        printf("Rejected: No available space in Zone A.\n");
                        rejected++;
                    }
                }
            }

            /* Student */
            else if (category == 'S' || category == 's')
            {
                if (vehicle == 'V' || vehicle == 'v')
                {
                    if (zoneC < 15)
                    {
                        zoneC++;
                        assigned = 1;
                    }
                    else
                    {
                        printf("Rejected: No suitable zone for student van.\n");
                        rejected++;
                    }
                }
                else
                {
                    if (zoneB < 40)
                    {
                        zoneB++;
                        assigned = 1;
                    }
                    else
                    {
                        printf("Rejected: No available space in Zone B.\n");
                        rejected++;
                    }
                }
            }

            /* Visitor */
            else if (category == 'G' || category == 'g')
            {
                if (vehicle == 'V' || vehicle == 'v')
                {
                    if (zoneC <= 13)
                    {
                        zoneC = zoneC + 2;
                        assigned = 1;
                    }
                    else
                    {
                        printf("Rejected: Not enough space in Zone C for van.\n");
                        rejected++;
                    }
                }
                else
                {
                    if (zoneC < 15)
                    {
                        zoneC++;
                        assigned = 1;
                    }
                    else
                    {
                        printf("Rejected: No available space in Zone C.\n");
                        rejected++;
                    }
                }
            }

            /* Count accepted vehicles */
            if (assigned == 1)
            {
                accepted++;

                if (vehicle == 'C' || vehicle == 'c')
                {
                    cars++;
                }
                else if (vehicle == 'B' || vehicle == 'b')
                {
                    bikes++;
                }
                else if (vehicle == 'V' || vehicle == 'v')
                {
                    vans++;
                }

                if (category == 'F' || category == 'f')
                {
                    printf("Assigned Zone: A\n");
                    printf("Remaining Zone A capacity: %d\n", 20 - zoneA);
                }
                else if (category == 'S' || category == 's')
                {
                    if (vehicle == 'V' || vehicle == 'v')
                    {
                        printf("Assigned Zone: C\n");
                        printf("Remaining Zone C capacity: %d\n", 15 - zoneC);
                    }
                    else
                    {
                        printf("Assigned Zone: B\n");
                        printf("Remaining Zone B capacity: %d\n", 40 - zoneB);
                    }
                }
                else
                {
                    printf("Assigned Zone: C\n");
                    printf("Remaining Zone C capacity: %d\n", 15 - zoneC);
                }
            }
        }
    }

    /* Summary */
    printf("\n====================================\n");
    printf("        PARKING SUMMARY\n");
    printf("====================================\n");

    printf("Total Vehicles Entered: %d\n", vehicles);
    printf("Accepted Vehicles: %d\n", accepted);
    printf("Rejected Vehicles: %d\n", rejected);

    printf("Cars Successfully Parked: %d\n", cars);
    printf("Bikes Successfully Parked: %d\n", bikes);
    printf("Vans Successfully Parked: %d\n", vans);

    printf("\nZone A Occupied: %d\n", zoneA);
    printf("Zone A Remaining: %d\n", 20 - zoneA);

    printf("Zone B Occupied: %d\n", zoneB);
    printf("Zone B Remaining: %d\n", 40 - zoneB);

    printf("Zone C Occupied: %d\n", zoneC);
    printf("Zone C Remaining: %d\n", 15 - zoneC);

    /* Highest occupancy */
    if (zoneA >= zoneB && zoneA >= zoneC)
    {
        printf("\nHighest Occupancy: Zone A\n");
    }
    else if (zoneB >= zoneA && zoneB >= zoneC)
    {
        printf("\nHighest Occupancy: Zone B\n");
    }
    else
    {
        printf("\nHighest Occupancy: Zone C\n");
    }

    /* Full campus check */
    if (zoneA == 20 && zoneB == 40 && zoneC == 15)
    {
        printf("Entire campus parking facility is FULL.\n");
    }
    else
    {
        printf("Parking spaces are still available.\n");
    }

    return 0;
}
