/*
 * myBank.h
 *
 *  Created on: Nov 20, 2019
 *      Author: sivannamma
 */
#ifndef MYBANK_H_
#define MYBANK_H_
#define INDEXADAPTER 901
#define ROW 50
#define COL 2
extern double bankData[ROW][2];
void update(int);
void printNot();
int isExist(int);
void openAccount(double sum);
void balance(int accountID);
void deposit(int accountID, double amount);
void withDrawal(int accountID, double amount);
void closeAccount(int accountID);
void intrerest(double interest);
void printAccounts();
void closeAllAccounts();
int isLegal();

#endif /* MYBANK_H_ */

