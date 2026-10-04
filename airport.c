#include <stdio.h>
int main()
{
    int passeng_category,flight_type,weight,verri_code,age,rem,final_rem,permitted_allow=0;
    int travel_doc;

    printf("========AIRPORT PASSENGER CLASSIFICATION SYSTEM=======\n\n");

    printf("====Passenger Category====\n\n");
    printf("1. ADULT\n2. STUDENT\n3. SENIOR CITEZEN\n\n");
    printf("Select: ");
    scanf("%d",&passeng_category);

    printf("====FLIGHT TYPE====\n\n");
    printf("1. DOMESTIC\n2. INTERNATIOANAL\n\n");
    printf("SELECT:");
    scanf("%d",&flight_type);

    printf("====WEIGHT OF BAGGAGE\n\n");
    printf("Weight: ");
    scanf("%d",&weight);

    printf("====AGE====\n\n");
    printf("age: ");
    scanf("%d",&age);

    printf("Documentd Valid (=Y/0=N):");
    scanf("%d",&travel_doc);

    switch(passeng_category)
    {
        case 1: // ADULT
        printf("====ADULT====\n\n");

        switch(flight_type)
        {
            case 1: // domestic
           permitted_allow = 20;
            break;

            case 2: // international
            permitted_allow = 30;
            break;

            default:
            {
                printf("INVALID FLIGHT TYPE ENTERED\n\n");
            }
        }
        break;

        case 2: // student
        printf("====STUDENT====\n\n");
        {
            switch(flight_type)
            {
                case 1: 
                permitted_allow = 25;
                break;

                case 2: 
                permitted_allow = 35;
                break;

                default:
                {
                    printf("INVALID FLIGHT TYPOE ENTERD\n\n");
                }
            }
            break;
        }
        
        case 3: //seniors
        {
            printf("====SENIOR CITEZEN====\n\n");
            switch(flight_type)
            {
                case 1: 
                permitted_allow = 30;
                break;

                case 2: 
                permitted_allow = 40;
                break;

                default:
                printf("INVALID FLIGHJT TYPE ENETERED\n\n");
            }
            break;
        }

        default:
        printf("THIS PASSENGER CATEOGORY DOEsNOT EXISTS\n\n");
    }

    if(travel_doc)
    {
        printf("TRAVEL DOCUMENTS ARE VALID\n\n");
    }
    else
    {
        printf("INVALID DOCUMENTATION");
    }

    printf("-----BOARDING-----\n\n");

    if(travel_doc == 1 && weight <= permitted_allow)
    {
        printf("PROCEEDING TO NORMAL BOARDING.....\n\n");
    }
    else if(weight > permitted_allow && travel_doc == 1)
    {
        printf("PROCEEDING TO ENHANCED AGGAGE SCREENING\n\n");
    }
    else if(travel_doc == 0)
    {
        printf("DENIED FOR BOARDING\n\n");
    }
    else
    printf("GO BACK TO HOME\n\n");

    rem = age % 5;
    switch(rem)
    {
        case 0:
        printf("CATEGORY A\n\n");
        break;

        case 1:
        printf("CATEGORY B\n\n");
        break;

        case 2:
        printf("CATEGORY C\n\n");
        break;

        case 3:
        printf("CATEGORY D\n\n");
        break;

        case 4:
        printf("CATEGORY E\n\n");
        break;

        default:
        printf("AGE IS NOT VALID");

    }

    if((passeng_category == 3 || passeng_category == 2) && flight_type == 2 )
    {
        printf("QUALIFIED FOR PRIORITY ASSISTANCE\n\n");
    }

    printf("=========RECIEPTF FINALE=========\n\n");
    printf("Passenger Category: %d\n",passeng_category);
    printf("Fight type: %d\n",flight_type);
    printf("PERMITTED LUGGAGE ALLOWANCE: %d\n",permitted_allow);
    printf("DOCUMENT STATUS: %d\n",travel_doc);
    printf("VERIFICATION CATEGORY: %d\n",rem);

    return 0;

}