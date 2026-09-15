#include <stdio.h>
#include <conio.h>

int main()
{
    // Variables
    int accountType, transaction;
    int serve_charge = 50;
    int over_draft = 50000;
    float amount, balance;

    // Header layout
    printf("==================================================\n");
    printf("     |---SMART BANKING TRANSACTION TERMINAL---|   \n");
    printf("==================================================\n\n");

    // Menu selections
    printf("Account Category:\n");
    printf("1. Savings Account\n");
    printf("2. Current Account\n");
    printf("3. Student Account\n\n");
    printf("Select Category type: ");
    scanf("%d", &accountType);
    printf("--------------------------------------------------\n");

    printf("Enter Transaction Type:\n");
    printf("1. Deposit\n");
    printf("2. Withdrawal\n");
    printf("3. Balance Inquiry\n\n");
    printf("Select Transaction: ");
    scanf("%d", &transaction);
    printf("--------------------------------------------------\n");

    printf("Enter Current Balance: ");
    scanf("%f", &balance);
    printf("--------------------------------------------------\n\n");

    // Processing accounts
    switch (accountType)
    {
    case 1: // Savings Account
        printf("[ SAVINGS ACCOUNT ]\n");
        switch (transaction)
        {
        case 1: // Deposit
            printf("Enter Deposit Amount: ");
            scanf("%f", &amount);
            if (amount > 0) {
                balance += amount;
                printf("\n=> Deposit Successful!\nUpdated Balance: %.2f Rs\n", balance);
            } else {
                printf("\n Error: Invalid Amount entered!\n");
            }
            break;

        case 2: // Withdrawal
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                printf("\n=> Withdrawal Successful!\nRemaining Balance: %.2f Rs\n", balance);
            } else {
                printf("\nError: Amount exceeds your current balance or is invalid.\n");
            }
            break;

        case 3: // Balance Inquiry
            printf("Current Balance: %.2f Rs\n", balance);
            break;
            
        default:
            printf("\nError: Invalid Transaction!\n");
        }
        break;
		
    case 2: // Current Account
        printf("[ CURRENT ACCOUNT ]\n");
        switch (transaction)
        {
        case 1: // Deposit
            printf("Enter amount for deposition: ");
            scanf("%f", &amount); 
            if (amount > 0) {
                balance += amount;
                printf("\nAmount deposited successfully!\nUpdated Balance = %.2f Rs\n", balance);
            } else {
                printf("\nError: Invalid Amount.\n");
            }
            break;

        case 2: // Withdrawal via Overdraft
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount); // FIXED: Added missing scanf prompt
            if (amount > 0 && amount <= balance + over_draft) {
                balance -= amount;
                printf("\n=> Withdrawal successful via Overdraft!\nRemaining balance = %.2f Rs\n", balance);
            } else {
                printf("\n? Error: Amount exceeds overdraft limit.\n");
            }
            break;

        case 3: // Balance Inquiry
            printf("Current Balance: %.2f Rs\n", balance);
            break;

        default:
            printf("\n? Error: Invalid Transaction!\n");
        }
        break;

    case 3: // Student Account
        printf("[ STUDENT ACCOUNT MENU ]\n");
        switch (transaction)
        {
        case 1: // withdrawal
            printf("Enter withdrawal amount: "); 
            scanf("%f", &amount);
            if (amount > 0 && amount <= balance) 
			{
                if ((balance - amount) >= 2000) 
				{
                    balance -= amount;
                    printf("\nWithdrawal successful!\nRemaining amount = %.2f Rs\n", balance);
                } else {
                    printf("\nError: Transaction declined! Must maintain a minimum balance of 2000 Rs.\n");
                }
            } else {
                printf("\nError: Invalid amount or insufficient balance!\n");
            }
            break;

        case 2: // Withdrawal with service charge
            printf("Enter amount for Withdrawal: ");
            scanf("%f", &amount); 
            
            if (amount > 0 && (amount + serve_charge) <= balance) {
                balance -= (amount + serve_charge);
                printf("\nWithdrawal successful!\nDispensed cash: %.2f Rs\nService Charge: %d Rs\nRemaining Account Balance = %.2f Rs\n", amount, serve_charge, balance);
            } else {
                printf("\n? Error: Insufficient funds to cover withdrawal and service charge.\n");
            }
            break;

        case 3: // Balance Inquiry
            printf("Current Balance = %.2f Rs\n", balance);
            break;

        default:
            printf("\nError: Invalid Transaction!\n");
        }
        break;

    default:
        printf("\n? Error: Invalid Account Type Selected!\n");
    }

    printf("\n==================================================\n");
    printf("Press any key to exit...");
    getch();
    return 0;
}

