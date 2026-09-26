#include <stdio.h>

int main()
{
    int door_lock = 1;
    int alarm_sys = 2;
    int cctv = 4;
    int motion_sensor = 8;

    int activate = 1, inactivate = 0;
    int operation;
    int device;
    int security_mode;
    int permission = 0;

    printf("====== Smart Home Security Controller ======\n\n");

    printf("Select device type:\n");
    printf("1. Door Lock\n");
    printf("2. Alarm System\n");
    printf("3. CCTV\n");
    printf("4. Motion Sensor\n\n");

    printf("Enter your choice: ");
    scanf("%d", &device);

    printf("\nSelect operation:\n");
    printf("1. Activate a device\n");
    printf("2. Deactivate a device\n");
    printf("3. Check Status of your device\n");
    printf("4. Toggle a device\n\n");

    printf("Enter your choice: ");
    scanf("%d", &operation);

    printf("\nSelect Security Mode:\n");
    printf("1. Home Mode\n");
    printf("2. Away Mode\n");
    printf("3. Night Mode\n\n");

    printf("Enter your choice: ");
    scanf("%d", &security_mode);


    switch (device)
    {
        case 1:     // Door Lock
            printf("\nDoor Lock Selected\n");

            switch (operation)
            {
                case 1:
                    permission = permission | door_lock;
                    printf("Door Lock Is Activated Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                case 2:
                    permission = permission & ~door_lock;
                    printf("Door Lock Is Deactivated Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                case 3:
                    if ((permission & door_lock) == door_lock)
                    {
                        printf("Status: Door is Locked\n");
                    }
                    else
                    {
                        printf("Status: Door is Unlocked\n");
                    }

                    printf("Updated Status: %d\n", permission);
                    break;

                case 4:
                    permission = permission ^ door_lock;
                    printf("Device Status Toggled Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                default:
                    printf("Invalid Operation entered. Please try again.\n");
            }
            break;


        case 2:     // Alarm System
            printf("\nAlarm System Selected\n");

            switch (operation)
            {
                case 1:
                    permission = permission | alarm_sys;
                    printf("Alarm System Is Activated Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                case 2:
                    permission = permission & ~alarm_sys;
                    printf("Alarm System Deactivated Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                case 3:
                    if ((permission & alarm_sys) == alarm_sys)
                    {
                        printf("Status: Alarm System is Activated\n");
                    }
                    else
                    {
                        printf("Status: Alarm System is Deactivated\n");
                    }

                    printf("Updated Status: %d\n", permission);
                    break;

                case 4:
                    permission = permission ^ alarm_sys;
                    printf("Alarm System Is Toggled Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                default:
                    printf("Invalid Operation entered. Please try again.\n");
            }
            break;


        case 3:     // CCTV
            printf("\nCCTV System Selected\n");

            switch (operation)
            {
                case 1:
                    permission = permission | cctv;
                    printf("CCTV System Is Activated Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                case 2:
                    permission = permission & ~cctv;
                    printf("CCTV System Deactivated Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                case 3:
                    if ((permission & cctv) == cctv)
                    {
                        printf("Status: CCTV System is Activated\n");
                    }
                    else
                    {
                        printf("Status: CCTV System is Deactivated\n");
                    }

                    printf("Updated Status: %d\n", permission);
                    break;

                case 4:
                    permission = permission ^ cctv;
                    printf("CCTV System Is Toggled Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                default:
                    printf("Invalid Operation entered. Please try again.\n");
            }
            break;


        case 4:     // Motion Sensor
            printf("\nMotion Sensor Selected\n");

            switch (operation)
            {
                case 1:
                    permission = permission | motion_sensor;
                    printf("Motion Sensor Is Activated Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                case 2:
                    permission = permission & ~motion_sensor;
                    printf("Motion Sensor Deactivated Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                case 3:
                    if ((permission & motion_sensor) == motion_sensor)
                    {
                        printf("Status: Motion Sensor is Activated\n");
                    }
                    else
                    {
                        printf("Status: Motion Sensor is Deactivated\n");
                    }

                    printf("Updated Status: %d\n", permission);
                    break;

                case 4:
                    permission = permission ^ motion_sensor;
                    printf("Motion Sensor Is Toggled Successfully.\n");
                    printf("Updated Status: %d\n", permission);
                    break;

                default:
                    printf("Invalid Operation entered. Please try again.\n");
            }
            break;


        default:
            printf("Invalid Device Type Entered.\n");
    }


    /* Security Modes */

    switch (security_mode)
    {
        case 1:
            // Home Mode: Door + CCTV
            permission = permission | door_lock | cctv;

            printf("\nHome Mode Activated Successfully.\n");
            printf("Updated Status of Home Mode: %d\n", permission);
            break;


        case 2:
            // Away Mode: All four devices
            permission = permission | door_lock | alarm_sys | cctv | motion_sensor;

            printf("\nAway Mode Activated Successfully.\n");
            printf("Updated Status of Away Mode: %d\n", permission);
            break;


        case 3:
            // Night Mode: Door + Alarm + Motion
            // CCTV remains unchanged
            permission = permission | door_lock | alarm_sys | motion_sensor;

            printf("\nNight Mode Activated Successfully.\n");
            printf("Updated Status of Night Mode: %d\n", permission);
            break;


        default:
            printf("\nInvalid Security Mode Entered.\n");
    }


    /* Display individual device status */

    printf("\n====== DEVICE STATUS ======\n");

    printf("Door Lock     : %s (1)\n",
           (permission & door_lock) ? "ACTIVE" : "INACTIVE");

    printf("Alarm System  : %s (2)\n",
           (permission & alarm_sys) ? "ACTIVE" : "INACTIVE");

    printf("CCTV Camera   : %s (4)\n",
           (permission & cctv) ? "ACTIVE" : "INACTIVE");

    printf("Motion Sensor : %s (8)\n",
           (permission & motion_sensor) ? "ACTIVE" : "INACTIVE");


    /* Check whether all four devices are active */

    if ((permission & (door_lock | alarm_sys | cctv | motion_sensor)) ==
        (door_lock | alarm_sys | cctv | motion_sensor))
    {
        printf("\nSECURITY SYSTEM FULLY ARMED\n");
    }
    else
    {
        printf("\nSECURITY SYSTEM PARTIALLY ARMED\n");
    }


    printf("\nBinary-equivalent status value: %d\n", permission);

    return 0;
}
