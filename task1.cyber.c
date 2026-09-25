#include <stdio.h>
int main()
{
	int read = 1;
	int write = 2;
	int execute = 4;
	int admin = 8;
	int permission = 0;
	int choice,action;
	
	printf("=======CYBERSECURITY ACCESS CONTROL SYSTEM USING BITWISE FLAGS======\n\n");
	printf("Select permission type to be granted: \n\n");
	printf("1.READ Permission\n2.WRITE Permission\n3.EXECUTE Permission\n4.ADMINISTRATION Permission\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1: 
		permission = read | permission;
		printf("Permission granted for READ.\nupdated permission is: %d\n",permission);
		break;
		
		case 2:
		permission = write | permission;
		printf("Permission granted for WRITE.\nUpdated permission is: %d\n",permission);
		break;
		
		case 3:
		permission = execute | permission;
		printf("Permission granted for %d.\nUpdated permission is: %d\n",execute,permission);
		break;
		
		case 4:
		permission = admin | permission;
		printf("Permission granted for ADMIN.\nUpdated permission is: %d\n",permission);
		break;
		
		default:
		printf("INVALID choice entered..\a\n");
		
	}
	printf("Select Action :\n");
	printf("1.Check READ permission\n");
	printf("2.Check WRITE permission\n");
	printf("3.Toggle EXECUTE permission\n");
	printf("4.Remove ADMIN permission\n");
	scanf("%d",&action);
	
	switch (action)
	{
		case 1:
			if(permission & read != 0)
			printf("User HAS Read permission");
			else
			printf("User DOESNOT HAVE permission");
			break;
		case 2:
			if(permission & write != 0)
			printf("User HAS Write permission");
			else
			printf("User DOESNOT HAVE permission");
			break;
		case 3:
			permission = permission ^ execute;
			printf("EXECUTE permission toggled.");
			printf("\n Updated permission Value: %d",permission);
			break;
		case 4:
			permission = permission & ~admin;
			printf("Adminstrator permission removed");
			printf("\n Updated Permission Value: %d",permission);
			break;
		default:
			printf("INVALID action.");		
	}
	return 0;
}

