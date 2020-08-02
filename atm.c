//////////////////////////////////////////////////////////////////////////
// Name: Ryan McGarry                                                   //
// Date: 2/17/2019                                                      //
// Course: CSC345_80                                                    //
// Homework Number: 1                                                   //
// Problem Statement: First, I created a typedef called bool for pin    //
// and defined true/false vars. Then, I made global vars for the values //
// needed. Finally, I implemented the functions I needed and used a     //
// switch statement that would call a function based on user input.     //
//////////////////////////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

int balance = 5000;
int withdrawalAmount = 1000;
int depositLimit = 10000;
int transCount = 0;

bool pin();
void menu();

int currentBalance();
int cashWithdrawl();
int cashDeposit();

void receipt();

int main()
{
    bool pinTry = pin();
    if(pinTry == false)
    {
        exit(0);
    }

    int choice,tryCount=0;
    while(true)
    {
        menu();
        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice<1 || choice >4)
        {
            printf("Invalid input\n");
            ++tryCount;
        }
        if(tryCount>2)
        {
            printf("Too many invalid inputs. Terminating.\n");
            exit(0);
        }
        switch(choice)
        {
        case 1:
            currentBalance();
            receipt();
            break;
        case 2:
            cashWithdrawl();
            receipt();
            break;
        case 3:
            cashDeposit();
            receipt();
            break;
        case 4:
            receipt();
            printf("\nThank you for using the ATM\nYou completed %d transactions.\n",transCount);
            exit(0);
        }
    }
    return 0;
}
bool pin()
{
    int input, pinCount=0,pin = 3014;
    while(pinCount <3)
    {
        printf("Enter your pin: ");
        scanf("%d",&input);
        pinCount++;
        if(input == pin)
        {
            printf("Success\n");
            return true;
        }
        else
        {
            printf("Incorrect pin\n");
        }

    }
    if(pinCount = 3)
    {
        printf("\nToo many incorrect pins, terminating..\n");
        return false;
    }

}
void menu()
{
    printf("1. Balance\n2. Cash withdrawal\n3. Cash deposition\n4. Quit\n");
}
int currentBalance()
{
    printf("Current balance: %d\n",balance);
    transCount++;
    return balance;
}
int cashWithdrawl()
{
    int amount;
    printf("How much money would you like to withdrawal($1000 daily limit): ");
    scanf("%d",&amount);
    if(amount%20 != 0)
    {
        printf("Invalid amount (must be 20,40,60,80)\n");
        exit(0);
    }

    withdrawalAmount -= amount;

    if(withdrawalAmount <0)
    {
        printf("Overdrew $1000 limit.\n");
        exit(0);
    }
    else
    {
        balance-=amount;
        printf("\nWithdrawal amount: %d\n", amount);
        printf("Remaining balance: %d\n\n", balance);
        transCount++;
        return balance;
    }

}
int cashDeposit()
{
    int amount;
    printf("How much money would you like to deposit($10000 daily limit): ");
    scanf("%d",&amount);

    depositLimit-= amount;
    if(depositLimit<0)
    {
        printf("Deposit limit reached\n");
        exit(0);
    }
    else
    {
        balance+= amount;

        printf("\nDeposit amount: %d\n", amount);
        printf("New balance: %d\n\n", balance);
        transCount++;
        return balance;
    }
}
void receipt(){
    int choice;
    printf("\nWould you like a receipt?(1 for Yes, 2 for No): ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("Printing...\n\n");
    }
    else if(choice == 2){
        printf("\nNo receipt to be printed\n\n");
    }
     else{
        printf("\ninvalid input\n\n");
    }

}
