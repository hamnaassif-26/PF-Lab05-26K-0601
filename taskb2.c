#include <stdio.h>

int main()
{	printf("===ELEVATOR SIMULATION===\n\n");
    int currentFloor = 0;
    int requestedFloor;

    printf("Enter requested floor: ");
    scanf("%d", &requestedFloor);

    if (requestedFloor > currentFloor)
    {
        printf("\n^Moving Up^\n");
    }
    else if (requestedFloor < currentFloor)
    {
        printf("\n!Moving Down!\n");
    }
    else
    {
        printf("\n~Doors Opening~\n");
    }

    currentFloor = requestedFloor;

    printf("\nCurrent Floor = %d\n", currentFloor);

    return 0;
}
