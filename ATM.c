#include <stdio.h>
#include<stdlib.h>

int ATM_Transaction();
int anotherTransaction,amountToWidthdraw,amountToDeposit,pin,n;
double balance = 10000; //Default amount

int  main()
{
  printf("******** Welcome to your Virtual Bank ATM ******** \n");
  int ch;
  int num;
  FILE *fptr;
  printf("Enter any option to be served!\n\n");
  printf("1. New User \n");
  printf("2. Regular User \n");
  scanf("%d", &ch);

  switch(ch)
   {
    case 1: 
    fptr = fopen("C:\\program.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
    printf("Please Generate Your PIN: ");
    scanf("%d", &num);
    fprintf(fptr,"%d",num);
    pin = num;
    fclose(fptr);
    printf("Please enter number between 25 to 30 for security check.\n");
    scanf("%d",&n);
    if (n == 25 || n == 26 || n == 27 || n == 28 || n== 29 || n==30)
    {
       ATM_Transaction();
    }
    else
    {
      printf("Please Enter Number Within Given Range.\n");
    }
    break;

    case 2:
    printf("******** Welcome Back Sir ******** \n");
    printf("Please enter number between 25 to 30 for security check.\n");
    scanf("%d",&n);
    if (n == 25 || n == 26 || n == 27 || n == 28 || n== 29 || n==30)
    {
    printf(" Enter your PIN Please: \n");
    scanf("%d",&pin);

    if ((fptr = fopen("C:\\program.txt","r")) == NULL)
    {
       printf("Error!");
       exit(1);
    }
    fscanf(fptr,"%d", &num);
    fclose(fptr); 
    if(pin != num)
    {
       printf("Sorry your PIN is wrong, Please try again.\n");
    }
    else
    {
      ATM_Transaction();     // function call
    }
    }
    else
    {
      printf("Please Enter Number Within Given Range.\n");
    }
    break;

    default:
    printf("Sorry Your Transition is cancelled.");
    exit(1);
   }
}

int ATM_Transaction()
{
  int choice;
  printf("Enter any option to be served!\n\n");
  printf("1. Balance Enquiry \n");
  printf("2. Cash Withdraw\n");
  printf("3. Deposit Cash\n");
  printf("4. Exit \n");
  scanf("%d",  &choice);

  switch(choice)

  {

    case 1: // BALANCE Enquiry
    printf("Your bank balance is: %f", balance);
    printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit\n\n"); // request for another transaction
    scanf("%d",&anotherTransaction);
    if(anotherTransaction == 1)
      {
        ATM_Transaction();// call our transaction method here
      }
     break;

    case 2:// Second option should be withdraw
    printf("Please enter amount to withdraw: ");
    scanf("%d", &amountToWidthdraw);
    if(amountToWidthdraw <= balance) //bal = 1000
    {
     printf("Pls collect your cash\n");
     balance=balance-amountToWidthdraw;//
     printf("Your available balance is %lf\n",balance);
     printf("\n\nDo you want to perform another transaction?\n Press 1 to proceed and 2 to exit\n\n");
     scanf("%d", &anotherTransaction);
       if(anotherTransaction == 1)
        {
             ATM_Transaction();  // call our ATM_Transaction method here
        }
    }
     else
    {
       printf("Sorry in-sufficient funds in your account");
       printf("\n\nDo you want to perform another transaction?\n Press 1 to proceed and 2 to exit\n\n");
       scanf("%d", &anotherTransaction);
       if(anotherTransaction == 1)
        {
             ATM_Transaction();  // call our ATM_Transaction method here
        }
    }
    break;

    case 3:// DEPOSIT
    printf("Please enter amount to deposit: ");
    scanf("%d", &amountToDeposit);
    balance = amountToDeposit + balance; //600+500
    printf("Thank you for depositing, your new balance is: %f", balance);
    printf("\n\nDo you want another transaction?\nPress 1 to proceed and 2 to exit\n\n");// request for another transaction
    scanf("%d", &anotherTransaction);
    if(anotherTransaction == 1)
     {
        ATM_Transaction(); // call our transaction method here
     }
    break;
    default:
     printf("Thanks for Using ATM services, See you soon");
  }

}




