// CIT237-C1
// Project 3
// Checking Account Register Application
// Ximing He
// Aug. 5, 2015
//
///////////////////////////

#include "Header.h"

using namespace std;

void displayMenu();
bool outPutFile(ofstream &, string);
bool inPutFile(ifstream &, string);
void display_Output(CheckingInfo, ofstream &, string);

int main()
{
	int quit = 0;
	char choice;
	string filename = "0";
	ofstream outFile;
	ifstream inFile;
	CheckingInfo checking1;
	do
	{
		cout << "Enter command (or 'h' for help): ";
		cin.get(choice);
		switch (choice)
		{
		case 'h':
		case 'H':
			displayMenu();
			cin.ignore(1000, '\n');
			break;
		case 'o':
		case 'O':
			cout << "Enter file name: ";
			cin.ignore(1000, '\n');
			getline(cin, filename);
			if (!outPutFile(outFile, filename))
			{
				cout << "something wrong!! check the code!!" << endl;
				system("pause");
				return EXIT_FAILURE;
			}
			break;
		case 'i':
		case 'I':
			if (filename == "0")
			{
				cout << "You have to specify output file first by choosing option \"o\"." << endl;
				break;
			}
			cout << "Enter file name: ";
			cin.ignore(1000, '\n');
			getline(cin, filename);
			if (!inPutFile(inFile, filename))
			{
				cout << "something wrong!! check the code!!" << endl;
				system("pause");
				return EXIT_FAILURE;
			}
			inFile.close();
			break;
		case 's':
		case 'S':
			checking1.setStartingBalance();
			display_Output(checking1, outFile, filename);
			break;
		case 'n':
		case 'N':
			checking1.setCheckNumber();
			break;
		case 'c':
		case 'C':
			checking1.setTransactionDate();
			checking1.setTransactionDescription();
			checking1.setPaymentAmount();
			checking1.setTransactionType(1);
			display_Output(checking1, outFile, filename);
			checking1.setCheckNumber(checking1.getCheckNumber() + 1);
			break;
		case 'w':
		case 'W':
			checking1.setTransactionDate();
			checking1.setTransactionDescription();
			checking1.setPaymentAmount();
			checking1.setTransactionType(2);
			display_Output(checking1, outFile, filename);
			break;
		case 'd':
		case 'D':
			checking1.setTransactionDate();
			checking1.setTransactionDescription();
			checking1.setDepositAmount();
			checking1.setTransactionType(3);
			display_Output(checking1, outFile, filename);
			break;
		case 'q':
		case 'Q':
			quit = -1;
			outFile.close();
			break;
		default:
			cout << "Please enter a valid command!!!" << endl;
			break;
		} // end of switch
	} while (quit != -1); // end of do-while loop

	system("pause");
	return 0;
}

void displayMenu()
{
	cout << endl << "---------------------------------------------------------------" << endl;
	cout << "Suppoted commands: " << endl;
	cout << "\th\t Display this menu." << endl;
	cout << "\to\t Specify an output file." << endl;
	cout << "\ti\t Specify an input file." << endl;
	cout << "\ts\t Set initial balance." << endl;
	cout << "\tn\t Set next check number (default = previous check number + 1)." << endl;
	cout << "\tc\t Record a new check." << endl;
	cout << "\tw\t Purchase or ATM withdrawal." << endl;
	cout << "\td\t Deposit." << endl;
	cout << "\tq\t quit the program." << endl;
	cout << "---------------------------------------------------------------" << endl << endl;
}

bool outPutFile(ofstream &file, string filename)
{
	file.close();
	file.open(filename.c_str());
	cout << "File open (text mode) successful: " << filename << endl;
	return true;
}

bool inPutFile(ifstream &file, string filename)
{
	file.open(filename.c_str());
	while (!file)
	{
		cout << "File not found." << endl;
		cout << "Enter file name again: ";
		file.clear();
		getline(cin, filename);
		file.open(filename.c_str());
	}
	cout << "File open (text mode) successful: " << filename << endl;
	return true;
}

void display_Output(CheckingInfo input, ofstream &file, string filename)
{
	if (input.getTransactionType() == 0) // starting
		cout << "s";
	else if (input.getTransactionType() == 1) // check
		cout << input.getCheckNumber();
	else if (input.getTransactionType() == 2) // withdraw
		cout << "w";
	else if (input.getTransactionType() == 3) // deposit
		cout << "d";
	cout << "|" << input.getTransactionDate() << "|" << input.getTransactionDescription() << "|";
	if (input.getTransactionType() == 1 || input.getTransactionType() == 2) // check or withdraw
		cout << setprecision(2) << fixed << input.getPaymentAmount();
	cout << "|";
	if (input.getTransactionType() == 3) // deposit
		cout << input.getDepositAmount();
	cout << "|" << setprecision(2) << fixed << input.getCurrentBalance() << endl;

	// cout << "Preparing for output to file \"" << filename << "\"" << endl;
	if (filename == "0")
	{
		cout << "unsuccessfully output file!!" << endl;
		cout << "You have to specify output file first" << endl;
		return;
	}
	if (input.getTransactionType() == 0) // starting
		file << "s";
	else if (input.getTransactionType() == 1) // check
		file << input.getCheckNumber();
	else if (input.getTransactionType() == 2) // withdraw
		file << "w";
	else if (input.getTransactionType() == 3) // deposit
		file << "d";
	file << "|" << input.getTransactionDate() << "|" << input.getTransactionDescription() << "|";
	if (input.getTransactionType() == 1 || input.getTransactionType() == 2) // check or withdraw
		file << setprecision(2) << fixed << input.getPaymentAmount();
	file << "|";
	if (input.getTransactionType() == 3) // deposit
		file << setprecision(2) << fixed << input.getDepositAmount();
	file << "|" << input.getCurrentBalance() << endl;
	// cout << "Done output to file: " << filename << endl;

}