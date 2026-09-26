#include <stdio.h>
int main()
{
	int veh_sys,severity,mileage,warranty,service_code;
	printf("=====SMART VEHICLE DIAGNOSTIC SYSTEM=====\n\n");
	printf("Select Vehicle System Type\n\n");
	printf("1. Engine\n");
	printf("2. Transmission\n");
	printf("3. Braking System\n");
	printf("4. Electrical System\n\n");
	printf("Enter Choice:");
	scanf("%d",&veh_sys);
	
	printf("\n\nSelect Diognostic Severity\n\n");
	printf("1. Minor\n2. Moderate\n3. Critical\n\n");
	printf("Enter Choice: ");
	scanf("%d",&severity);
	
	printf("\nEnter Mileage:");
	scanf("%d",&mileage);
	
	printf("\nIs vehicle under warranty? 1=yes,0=no:  ");
	scanf("%d",&warranty);
	
	service_code = (mileage%100)+severity; // this will generate a slip on which your service code will be writen
	printf("\nGenerated Service Code: %d\n\n",service_code);
	
	switch (veh_sys)
	{
		case 1: //engine
		printf("=======ENGINE=======\n\n");
		{
			switch (severity)
			{
				case 1: // minor
				printf("Minor issues ONLY requires INSPECTION!\n\n");
				break;
				
				case 2: // moderate
				printf("Maintainence Required\n\n");
				break;
				
				case 3: // critical
				printf("Requires Immediate Shutdown!!!\n\n");
				break;
				
				default:
				printf("INVALID CHOICE ENTERED.\n\n");				
			}
			break;//it is for main cases i.e case 1 engine, case 2: transmission...
		}
		
		case 2: // transmission
		printf("=====TRANSMISSION=====\n\n");
		{
			switch (severity)
			{
				case 1: //minor
				printf("ISSUES MUST BE MONTORED!\n\n");
				break;
				
				case 2:
				printf("Service must be provided within 24 hours\n\n");
				break;
				
				case 3:
				printf("Such issues requires TOWING..\n\n");
				break;
				
				default:
				printf("INVALID CHOICE ENTERED\n\n");
			}
			break;
		}
		
		case 3: // braking system
		printf("=====BRAKING SYSTEM=====\n\n");
		{
			switch(severity)
			{
				case 1:
				printf("Minors issues requires immediate inpection!\n\n");
				break;
				
				case 2:
				printf("Long distance driving prohibited\n\n");
				break;
				
				case 3:
				printf("Vehicle operations are prohibited\n\n");
				break;
				
				default:
				printf("INVALID CHOICE ENTERED\n\n");
			}
			break;
		}
		
		case 4: // ElectricalSystem
		printf("======ELECTRICAL SYSTEM=====\n\n");
		{
			switch(severity)
			{
				case 1:
				printf("Minor issues can be IGNORED TEMPORARILY\n\n");
				break;
				
				case 2:
				printf("Battery Diognostic Test required\n\n");
				break;
				
				case 3:
				printf("COmplete Electrical Isolation Required\n\n");
				break;
				
				deafault:
				printf("INVALID CHOICE ENTERED\n\n");
			}
			break;
		}			
	}
	
	if(mileage>200000)
	{
		printf("Mintainence: HIGH PRIORITY LEVEL\n\n");
	}
	
	if(warranty == 1)
		printf("Status: Eligible for warranty evaluation\n\n");
	else
		printf("Status: Customer-paid service\n\n");
	
	if(severity == 3 || mileage>=200000)
		printf("HIGH PRIORITY\n\n");
	else
		printf("PRIORITY LEVEL: NORMAL\n\n");
	
	printf("=====THANKS FOR USING OUR SERVICE=====\n\n");
	
	
}
