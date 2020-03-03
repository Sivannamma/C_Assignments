#include "myBank.h"
#include <stdio.h>

double bankData[ROW][2] = { 0 };

void printNot() {
	printf("Account doesn't exist\n");
}
void update(int index) { // function that makes the array to storgae only 2 numberic after dot
	bankData[index][1] = (int) (bankData[index][1] * 100);
	bankData[index][1] /= 100;
}
void openAccount(double sum) {
	int isClosed = 1;
	int i = 0;
	for (i = 0; i < ROW && isClosed; i++) {
		if (bankData[i][0] == 0) {
			bankData[i][0] = 1; // open account
			bankData[i][1] += sum; // deposit the initial amount
			update(i);
			isClosed = 0;
		}
	}
	if (isClosed) { // flag to know weather the account was open or not
		printf("Couldn't open an account\n");
	} else {
		printf("Account was successfully initialized, account number : %d \n",
				--i + INDEXADAPTER);
	}
}
void balance(int accountID) {
	int index = accountID - INDEXADAPTER;
	if (isExist(index)) {
		printf("Account number: %d balance is: %f \n", accountID,
				bankData[index][1]);
	} else
		printNot();
}
int isExist(int index) {
	if (index < 0 || index >= ROW) { // checking boundaries
		return 0;
	}
	if (bankData[index][0] == 1) // checking if the amount exist
		return 1;
	return 0;
}
void deposit(int accountID, double amout) {
	int index = accountID - INDEXADAPTER;
	if (isExist(index)) { // checking if the account exist
		bankData[index][1] += amout; //setting the new balance
		update(index);
		balance(accountID);
	} else
		printNot();
}
void withDrawal(int accountID, double amount) {
	int index = accountID - INDEXADAPTER;
	if (isExist(index)) {
		if (bankData[index][1] - amount >= 0) { // checking if the person has enough money
			bankData[index][1] -= amount; // Setting the new balance
			update(index);
			balance(accountID);
		} else {
			printf("You don't have enough money to withdrawal, ");
			balance(accountID);
		}
	} else
		printNot();

	return;
}
void closeAccount(int accountID) {
	int index = accountID - INDEXADAPTER;
	if (isExist(index)) {
		bankData[index][0] = 0; // setting the account to be closed
		bankData[index][1] = 0; // initialize to 0 for next accounts to yet be open
		printf("Account was successfully closed\n");
	} else
		printNot();
}
void intrest(double intrest) {
	int i = 0;
	for (i = 0; i < ROW; ++i) { // Reducing each account with his own interest percentage
		if (isExist(i))
			withDrawal(i + INDEXADAPTER, intrest * bankData[i][1] / 100);
	}

}
void printAccounts() {
	int i = 0;
	int count = 0;
	for (i = 0; i < ROW; ++i) {
		if (isExist(i)) {
			count++;
			balance(i + INDEXADAPTER);
		}
	}
	if (count == 0) {
		printf("there were no accounts to be printed.\n");
	}
}
void closeAllAccounts() { // closing all the accounts
	int i = 0;
	int count = 0;
	for (i = 0; i < ROW; ++i) {
		if (isExist(i)) // checking if the account exist and need to be closed
				{
			closeAccount(i + INDEXADAPTER);
			count++;
		}
	}
	if (count == 0) {
		printf("There were no accounts to be closed.\n");
	}
}
int isLegal(double *amount) { // function that gets input from the user and checks it
	// checking if the input is correct
	if ((scanf("%lf", amount) == 1) && (amount >= 0))
		return 1;
	else
		printf("input is incorrect\n");
	return 0;
}

