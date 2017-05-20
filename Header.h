// CIT237-C1
// Project 3
// Checking Account Register Application
// Ximing He
// Aug. 5, 2015
//
///////////////////////////

// Specification file for CheckingInfo class
#ifndef CheckingInfo_H
#define CheckingInfo_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <memory>
#include <cctype>
#include <cstring>
#include <new>
#include <algorithm>
#include <list>

using namespace std;

// CheckingInfo class declaration

class CheckingInfo
{
private:
	double currentBalance;
	double startingBalance;
	int checkNumber;
	int transactionType; // 1 = check, 2 = ATM withdrawal, 3 = deposit
	string transactionDate;
	string transactionDescription;
	double paymentAmount;
	double depositAmount;

public:
	CheckingInfo()
	{
		// initialize everything first
		currentBalance = 0.0;
		startingBalance = -1;
		checkNumber = 0;
		transactionType = 0; // 1 = check, 2 = ATM withdrawal, 3 = deposit, 0 = start
		transactionDate = "00/00/0000";
		transactionDescription = "";
		paymentAmount = 0.0;
		depositAmount = 0.0;
	}

	double getCurrentBalance()
	{
		return currentBalance;
	}

	int getCheckNumber()
	{
		return checkNumber;
	}

	int getTransactionType()
	{
		return transactionType;
	}

	string getTransactionDate()
	{
		return transactionDate;
	}

	string getTransactionDescription()
	{
		return transactionDescription;
	}

	double getPaymentAmount()
	{
		return paymentAmount;
	}

	double getDepositAmount()
	{
		return depositAmount;
	}

	void setTransactionType(int input)
	{
		if (input == 1 || input == 2 || input == 3 || input == 0)
			transactionType = input;
		else
		{
			cout << "Something weird happened. Please check the code!!" << endl;
			system("pause");
			exit(EXIT_FAILURE);
		}
	} // end setTransactionType(int input)

	void setStartingBalance()
	{
		if (startingBalance != -1)
		{
			cout << "Starting Balance was set before." << endl;
			cout << "Do you want to erase all data and initialize everything ? (Y/N) ";
			char temp;
			cin.ignore(20, '\n'); // clear the new line charactor in the keyboard buff
			cin.get(temp);
			while (!(toupper(temp) == 'Y' || toupper(temp) == 'N'))
			{
				cout << "You have to choose Y or N here. No tricky play." << endl;
				cout << "Again? (Y/N) ";
				if (temp != '\n')
					cin.ignore(20, '\n'); // clear the new line charactor in the keyboard buff
				cin.get(temp);
			}
			cin.ignore(20, '\n'); // clear the new line charactor in the keyboard buff
			if (toupper(temp) == 'N')
			{
				return;
			}
			else if (toupper(temp) == 'Y')
				CheckingInfo::CheckingInfo();
			else
			{
				cout << "Something weird happened. Please check the code!!" << endl;
				system("pause");
				exit(EXIT_FAILURE);
			}
		} // (end if)

		cout << endl << "Enter starting balance (with decimal point): ";
		cin >> startingBalance;
		while (cin.fail() || startingBalance < 0) // no extraction took place
		{
			cin.clear(); // reset the state bits back to goodbit so we can use ignore()
			cin.ignore(1000, '\n'); // clear out the bad input from the stream
			cout << "invalid input!! Please enter again." << endl;
			cout << "Enter starting balance (with decimal point): ";
			cin >> startingBalance;
		} // (end while)
		currentBalance = startingBalance; // obviously, current balance equals to starting balance
		setTransactionDate();
		setTransactionDescription();
		setTransactionType(0);
	} // end setStartingBalance()

	void setTransactionDate()
	{
		cin.ignore(20, '\n'); // clear the new line charactor in the keyboard buff
		cout << "Enter transaction date: ";
		getline(cin, transactionDate);
		if (transactionDate == "")
		{
			transactionDate = "Today's Date";
		}
	} // end setTransactionDate()

	void setTransactionDescription()
	{
		// cin.ignore(20, '\n'); // clear the new line charactor in the keyboard buff
		cout << "Enter transaction description: " << endl;
		getline(cin, transactionDescription);
	} // end setTransactionDescription()

	void setCheckNumber()
	{
		cout << "Enter the next check number: ";
		cin >> checkNumber;
		while (cin.fail() || checkNumber < 0) // no extraction took place
		{
			cin.clear(); // reset the state bits back to goodbit so we can use ignore()
			cin.ignore(1000, '\n'); // clear out the bad input from the stream
			cout << "invalid input!! Please enter again." << endl;
			cout << "Enter the next check number: ";
			cin >> checkNumber;
		} // (end while)
		cin.ignore(1000, '\n'); // clear out the bad input from the stream
	} // end setCheckNumber()

	void setCheckNumber(int input)
	{
		checkNumber = input;
	} // end setCheckNumber(int input)

	void setPaymentAmount()
	{
		cout << "Enter the payment amount: ";
		cin >> paymentAmount;
		while (cin.fail() || paymentAmount <= 0) // no extraction took place
		{
			cin.clear(); // reset the state bits back to goodbit so we can use ignore()
			cin.ignore(1000, '\n'); // clear out the bad input from the stream
			cout << "invalid input!! Please enter again." << endl;
			cout << "Enter the payment amount: ";
			cin >> paymentAmount;
		} // (end while)
		cin.ignore(1000, '\n'); // clear out the bad input from the stream
		currentBalance -= paymentAmount; // update balance
	} // end setPaymentAmount()

	void setDepositAmount()
	{
		cout << "Enter the deposit amount: ";
		cin >> depositAmount;
		while (cin.fail() || depositAmount <= 0) // no extraction took place
		{
			cin.clear(); // reset the state bits back to goodbit so we can use ignore()
			cin.ignore(1000, '\n'); // clear out the bad input from the stream
			cout << "invalid input!! Please enter again." << endl;
			cout << "Enter the deposit amount: ";
			cin >> depositAmount;
		} // (end while)
		cin.ignore(1000, '\n'); // clear out the bad input from the stream
		currentBalance += depositAmount; // update balance
	} // end setDepositAmount()


};

#endif