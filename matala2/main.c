#include "myBank.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int ID = 0;
	char menu = '?';
	double amount = 0;
	do {
		printf("Welcome to the bank!\n");
		printf("1) O\n");
		printf("2) B\n");
		printf("3) D\n");
		printf("4) W\n");
		printf("5) C\n");
		printf("6) I\n");
		printf("7) P\n");
		printf("8) E\n");
		scanf("%c", &menu);
		switch (menu) {
		case 'O':
			printf("Initial deposit:\n");
			if (isLegal(&amount))
				openAccount(amount);
			break;
		case 'B':
			printf("Enter your account number: \n");
			scanf("%d", &ID);
			balance(ID);
			break;
		case 'D':
			printf("Enter your account number: \n");
			scanf("%d", &ID);
			printf("Enter the amount to be deposit\n");
			if (isLegal(&amount))
				deposit(ID, amount);
			break;
		case 'W':
			printf("Enter your account number: \n");
			scanf("%d", &ID);
			printf("Enter the amount to be withdrawal\n");
			if (isLegal(&amount))
				withDrawal(ID, amount);
			break;
		case 'C':
			printf("Enter your account number: \n");
			scanf("%d", &ID);
			closeAccount(ID);
			break;

		case 'I':
			printf("Enter interest rate\n");
			if (isLegal(&amount))
				intrest(amount);
			break;
		case 'P':
			printAccounts();
			break;

		case 'E':
			closeAllAccounts();
			break;

		default:
			printf("There is not such activity for your input\n");
		}
		amount = 0;
		while ((getchar() != '\n'))
			; // to empty the char
	} while (menu != 'E');

	return 0;
}

