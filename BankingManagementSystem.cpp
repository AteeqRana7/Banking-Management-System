/*
Name: Ateeq Rana

Bank Management System
*/

#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
#pragma warning(disable : 4996)
using namespace std;

struct payBillNode
{
	string billType;
	long billInvoiceNumber;
	long double billAmount;
	payBillNode *next;
	payBillNode *prev;
};

class billPaymentQueue
{
private:
	payBillNode *front;
	payBillNode *rear;
public:
	billPaymentQueue()
	{
		front = rear = NULL;
	}
	bool isEmpty()
	{
		if (rear == NULL && front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void enqueue()
	{
		payBillNode *temp = new payBillNode();
		char confirmation;

		cout << "\t\t\t\t Kindly write down your bill type from the following: Electricity, Gas, Internet -> ";
		cin >> temp->billType;
		cout << "\t\t\t\t Kindly write down the 10 digit Invoice Number -> ";
		cin >> temp->billInvoiceNumber;
		cout << "\t\t\t\t Kindly write down the bill amount -> ";
		cin >> temp->billAmount;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tBill Type : " << temp->billType << endl;
		cout << "\t\t\t\tBill Invoice# : " << temp->billInvoiceNumber << endl;
		cout << "\t\t\t\tBill Amount : " << temp->billAmount << endl;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\t Press 'Y' to confirm, or 'N' to exit" << endl;
		cout << "\t\t\t\t ", cin >> confirmation;
		temp->next = NULL;

		if (confirmation == 'y' || confirmation == 'Y')
		{
			if (isEmpty())
			{
				temp->prev = NULL;
				front = rear = temp;
				cout << "\t\t\t\t Transaction Completed, Bill payment in process." << endl;
			}
			else
			{
				temp->prev = rear;
				rear->next = temp;
				rear = temp;
				cout << "\t\t\t\t Transaction Completed, Bill payment in process." << endl;
			}
		}
		else if (confirmation == 'n' || confirmation == 'N')
		{
			temp = NULL;
			cout << "\t\t\t\t Transaction not Completed." << endl;
		}
		else
		{
			cout << "\t\t\t\t ERROR ERROR ERROR!!! Wrong input entered, transaction failed!" << endl;
			temp = NULL;
		}

		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void dequeue()
	{
		payBillNode *temp = front;

		if (isEmpty())
		{
			cout << "\t\t\t\t Bill Payment Queue is empty, nothing left to process" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}
		else if (front == rear)
		{
			cout <<"\t\t\t\t Bill# " << temp->billInvoiceNumber << " has been paid" << endl;
			front = rear = NULL;
		}
		else
		{
			front = front->next;
			cout << "\t\t\t\t Bill# " << temp->billInvoiceNumber << " has been paid." << endl;
		}
		delete temp;
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayBillPaymentQueue()
	{
		payBillNode *temp = front;
		
		if (isEmpty())
		{
			cout << "\t\t\t\t Bill Payment Queue is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 0;

		while (temp != NULL)
		{
			cout << "\t\t\t\t--------------- #" << count++ <<" ---------------"<< endl;
			cout << "\t\t\t\tBill Type : " << temp->billType << endl;
			cout << "\t\t\t\tBill Invoice# : " << temp->billInvoiceNumber << endl;
			cout << "\t\t\t\tBill Amount : " << temp->billAmount << endl;
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl << endl;
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayFront()
	{
		payBillNode *temp = front;

		if (isEmpty())
		{
			cout << "\t\t\t\t Bill Payment Queue is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		cout << "\t\t\t\t------------------------------" << endl;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tBill Amount: " << temp->billAmount << endl;
		cout << "\t\t\t\tBill Invoice#: " << temp->billInvoiceNumber << endl;
		cout << "\t\t\t\tBill Type: " << temp->billType << endl;
		cout << "\t\t\t\t------------------------------" << endl << endl;
		// temp = temp->next;
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
};

struct withdrawDepositNode
{
	long accountNumber;
	long double cashAmount;
	bool withdrawCash;
	bool depositCash;
	withdrawDepositNode *next;
	withdrawDepositNode *prev;
};

class withdrawDepositQueue
{
private:
	withdrawDepositNode *front;
	withdrawDepositNode *rear;
public:
	withdrawDepositQueue()
	{
		front = rear = NULL;
	}
	bool isEmpty()
	{
		if (rear == NULL && front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void enqueue()
	{
		withdrawDepositNode *temp = new withdrawDepositNode();

		int opt = 0;
		string flag = "";

		cout << "\t\t\t\t Kindly choose from the following two options: 1) Withdraw Cash (cheque) or 2) Deposit Cash -> ";
		cin >> opt;

		if (opt == 1)
		{
			temp->withdrawCash = true;
			temp->depositCash = false;
			flag = "Withdraw Cash";
		}
		else if (opt == 2)
		{
			temp->depositCash = true;
			temp->withdrawCash = false;
			flag = "Deposit Cash";
		}
		else
		{
			cout << "\t\t\t\t Wrong option entered, press any key to return to menu." << endl;
			_getch();
			return;
		}

		char confirmation;

		cout << "\t\t\t\t Kindly write down the 10 digit Account Number -> ";
		cin >> temp->accountNumber;
		cout << "\t\t\t\t Kindly write down the cash amount -> ";
		cin >> temp->cashAmount;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tAccount#: " << temp->accountNumber << endl;
		cout << "\t\t\t\tCash: " << temp->cashAmount << endl;
		cout << "\t\t\t\tTransaction Type: " << flag << endl;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\t Press 'Y' to confirm, or 'N' to exit" << endl;
		cout << "\t\t\t\t ", cin >> confirmation;
		temp->next = NULL;

		if (confirmation == 'y' || confirmation == 'Y')
		{
			if (isEmpty())
			{
				temp->prev = NULL;
				front = rear = temp;
				cout << "\t\t\t\t Transaction Completed." << endl;
			}
			else
			{
				temp->prev = rear;
				rear->next = temp;
				rear = temp;
				cout << "\t\t\t\t Transaction Completed." << endl;
			}
		}
		else if (confirmation == 'n' || confirmation == 'N')
		{
			temp = NULL;
			cout << "\t\t\t\t Transaction not Completed." << endl;
		}
		else
		{
			cout << "\t\t\t\t ERROR ERROR ERROR!!! Wrong input entered, transaction failed!" << endl;
			temp = NULL;
		}

		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();

	}
	void dequeue()
	{
		withdrawDepositNode *temp = front;

		if (isEmpty())
		{
			cout << "\t\t\t\t Withdraw/Deposit Queue is empty, nothing left to process" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}
		else if (front == rear)
		{
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\t " << temp->accountNumber << endl;
			cout << "\t\t\t\t " << temp->cashAmount << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\t Transaction has been done." << endl;
			front = rear = NULL;
		}
		else
		{
			front = front->next;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\t " << temp->accountNumber << endl;
			cout << "\t\t\t\t " << temp->cashAmount << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\t Transaction has been done." << endl;
		}
		delete temp;
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayWithdrawDepositQueue()
	{
		withdrawDepositNode *temp = front;

		if (isEmpty())
		{
			cout << "\t\t\t\t Withdraw/Deposit Payment Queue is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 0;

		while (temp != NULL)
		{
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
			cout << "\t\t\t\t " << temp->accountNumber << endl;
			cout << "\t\t\t\t " << temp->cashAmount << endl;
			cout << "\t\t\t\t Withdraw =" << temp->withdrawCash << endl;
			cout << "\t\t\t\t Deposit =" << temp->depositCash << endl;
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl << endl;
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
};

class address
{
public:
	int houseNumber;
	string townName;
	int streetNumber;
	string city;

	address(int hN = 0,string tN = "",int sN = 0,string c = "")
	{
		houseNumber = hN;
		townName = tN;
		streetNumber = sN;
		city = c;
	}
	void setAddress()
	{
		cout << "\t\t\t\t House# = ", cin >> houseNumber;
		cout << "\t\t\t\t Town Name = ", cin >> townName;
		cout << "\t\t\t\t Street# = ", cin >> streetNumber;
		cout << "\t\t\t\t City = ", cin >> city;
	}
	int getHouseNumber()
	{
		return houseNumber;
	}
	int getStreetNumber()
	{
		return houseNumber;
	}
	string getCity()
	{
		return city;
	}
	string getTownName()
	{
		return townName;
	}
	void displayAddress()
	{
		cout << "\t\t\t\t House# = "<< houseNumber <<endl;
		cout << "\t\t\t\t Town Name = " << townName << endl;
		cout << "\t\t\t\t Street# = " << streetNumber << endl;
		cout << "\t\t\t\t City = "<< city << endl;
	}
	
};

struct newAccountNode
{
	string firstName;
	string lastName;
	string accountStatus;
	long long phoneNumber;
	long long CNIC;
	long double cash;
	string emailAddress;
	address homeAddress;
	bool debitCard;
	bool chequeBook;
	int debitCardPin;
	string username;
	string password;
	long accountNumber;
	newAccountNode *next;
	newAccountNode *prev;
};

class bankAccountsDatabase
{
public:
	newAccountNode *head, *tail;

public:
	bankAccountsDatabase()
	{
		head = tail = NULL;
	}
	void insertNewAccount()
	{
		newAccountNode *temp = new newAccountNode();

		char confirmation;
		int debitCardOpt = 0;
		int chequeBookOpt = 0;
		time_t t = time(NULL);
		tm* tPtr = localtime(&t);

		cout << "\t\t\t\t Kindly write down your First Name -> ";
		cin >> temp->firstName;
		cout << "\t\t\t\t Kindly write down your Last Name -> ";
		cin >> temp->lastName;
		cout << "\t\t\t\t Kindly write down your Email Address -> ";
		cin >> temp->emailAddress;
		cout << "\t\t\t\t Kindly write down your Home Address -> " << endl;
		temp->homeAddress.setAddress();
		cout << "\t\t\t\t Kindly write down your Phone Number -> ";
		cin >> temp->phoneNumber;
		cout << "\t\t\t\t Kindly write down your CNIC -> ";
		cin >> temp->CNIC;
		cout << "\t\t\t\t Do you want to get a Debit Card: write Yes(1) or No(0)-> ";
		cin >> debitCardOpt;

		if (debitCardOpt == 1)
		{
			temp->debitCard = true;
			cout << "\t\t\t\t Kindly write down your Debit Card PIN (4 Digits) -> ";
			cin >> temp->debitCardPin;
		}
		else if (debitCardOpt == 0)
		{
			temp->debitCard = false;
			temp->debitCardPin = 0;
			cout << "\t\t\t\t Debit card is set as No(0)" << endl;
		}
		else
		{
			temp->debitCard = false;
			temp->debitCardPin = 0;
			cout << "\t\t\t\t Invalid Option entered, debit card is set as No(N)" << endl;
		}

		cout << "\t\t\t\t Do you want to get a ChequeBook: write Yes(1) or No(0)-> ";
		cin >> chequeBookOpt;
		if (chequeBookOpt == 1)
		{
			temp->chequeBook = true;
		}
		else if (chequeBookOpt == 0)
		{
			temp->chequeBook = false;
		}
		else
		{
			cout << "\t\t\t\t Invalid Option entered, cheque book is set as No(N)" << endl;
		}

	TYPEAGAINUSNM:cout << "\t\t\t\t Kindly write down your desired Username(NO Space Allowed) -> ";
		cin >> temp->username;

		if (checkUsernameClash(temp->username))
		{
			cout << "\t\t\t\t Username has already been taken.!" << endl;
			goto TYPEAGAINUSNM;
		}

		cout << "\t\t\t\t Kindly write down your desired Password(NO Space Allowed) -> ";
		cin >> temp->password;

		system("cls");

		cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
		cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;

		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
		cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
		cout << "\t\t\t\tEmail Address: " << temp->emailAddress << endl;
		cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
		cout << "\t\t\t\tPhone#: " << temp->phoneNumber << endl;
		cout << "\t\t\t\t ---Address--- " << endl;
		temp->homeAddress.displayAddress();
		cout << "\t\t\t\t -------------" << endl;
		cout << "\t\t\t\tUsername: " << temp->username << endl;
		cout << "\t\t\t\tPassword: " << temp->password << endl;
		cout << "\t\t\t\tDebit Card: " << temp->debitCard << endl;
		cout << "\t\t\t\tCheque Book: " << temp->chequeBook << endl;
		cout << "\t\t\t\tDebit Card PIN: " << temp->debitCardPin << endl;
		cout << "\t\t\t\t Press 'Y' to confirm, or 'N' to exit" << endl;
		cout << "\t\t\t\t ", cin >> confirmation;
		temp->next = NULL;

		if (confirmation == 'y' || confirmation == 'Y')
		{
			if (head == NULL)
			{
				temp->prev = NULL;
				temp->cash = 900000;
				temp->accountStatus = "In Process";
				temp->accountNumber = 0;
				head = tail = temp;
				cout << "\t\t\t\t Account Details Completed, in process now." << endl;
			}
			else
			{
				temp->cash = 900000;
				temp->accountStatus = "In Process";
				temp->accountNumber = 0;
				temp->prev = tail;
				tail->next = temp;
				tail = temp;
				cout << "\t\t\t\t Account Details Completed, in process now." << endl;
			}
		}
		else if (confirmation == 'n' || confirmation == 'N')
		{
			temp = NULL;
			cout << "\t\t\t\t Account not Completed." << endl;
		}
		else
		{
			cout << "\t\t\t\t ERROR ERROR ERROR!!! Wrong input entered, account opening failed!" << endl;
			temp = NULL;
		}

		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void viewAccountsToBeProcessed()
	{
		newAccountNode *temp = head;

		if (head == NULL)
		{
			cout << "\t\t\t\t Account Database is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 1;

		while (temp != NULL)
		{
			if (temp->accountStatus == "In Process")
			{
				cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
				cout << "\t\t\t\t----------" << endl;
				cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
				cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
				cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
				cout << "\t\t\t\t ---Address--- " << endl;
				temp->homeAddress.displayAddress();
				cout << "\t\t\t\t -------------" << endl;
				cout << "\t\t\t\tUsername: " << temp->username << endl;
				cout << "\t\t\t\tPassword: " << temp->password << endl;
				cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
			}
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	void processAccounts()
	{
		newAccountNode *temp = head;

		if (head == NULL)
		{
			cout << "\t\t\t\t Account Database is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 1;
		int opt;

		while (temp != NULL)
		{
			if (temp->accountStatus == "In Process")
			{
				cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
				cout << "\t\t\t\t----------" << endl;
				cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
				cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
				cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
				cout << "\t\t\t\t ---Address--- " << endl;
				temp->homeAddress.displayAddress();
				cout << "\t\t\t\t -------------" << endl;
				cout << "\t\t\t\tUsername: " << temp->username << endl;
				cout << "\t\t\t\tPassword: " << temp->password << endl;
				cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
				cout << "\t\t\t\t Do you want to process this account or not? Yes(1) No(0)" << endl;
				cin >> opt;

				if (opt == 1)
				{
					temp->accountStatus = "Completed";
					temp->accountNumber = generateAccountNumber();
				}
				else if (opt == 0)
				{
					temp->accountStatus == "Declined";
				}
				else
				{
					cout << "\t\t\t\t Wrong option entered, account not completed nor declined." << endl;
				}
			}		
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	
	int countNodes()
	{
		int count = 0;

		if (head == NULL)
		{
			return count;
		}
		else
		{
			newAccountNode *temp = head;

			while (temp != NULL)
			{
				if (temp->accountStatus == "Completed")
				{
					count++;
				}
				temp = temp->next;	
			}
			return count;
		}
	}
	long generateAccountNumber()
	{
		long accNumber = 1007750 + countNodes() ;

		return accNumber;
	}
	void deleteAccount(long accountNum)
	{
		newAccountNode *temp = head;
		newAccountNode *findAndDelete;

		if (head == NULL)
		{
			cout << "\t\t\t\tAccount Database is empty, nothing is available to delete!!!!" << endl;
		}
		else if (head->accountNumber == accountNum)
		{
			head = head->next;
			findAndDelete = temp;
			temp = NULL;
			delete findAndDelete;
			cout << "\t\t\t\tAccount found in database and successfully deleted !!!!" << endl;
		}

		int flag = 0;

		while (temp != NULL)
		{
			temp = temp->next;
			if (temp->accountNumber == accountNum)
			{
				findAndDelete = temp;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				flag = 1;
			}
		}

		if (flag == 0)
		{
			cout << "\t\t\t\tAccount not found in database !!!!" << endl;
		}
		else if (flag == 1)
		{
			delete findAndDelete;
			cout << "\t\t\t\tAccount found in database and successfully deleted !!!!" << endl;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
	newAccountNode *checkIfAccountPresent(string usernm, string paswd)
	{
		newAccountNode *temp = NULL;
		if (head == NULL)
		{
			cout << "\t\t\t\tAccount not found in Database, because database is empty." << endl;
			return temp;
		}

		temp = head;

		while (temp != NULL)
		{
			if (temp->username == usernm && temp->password == paswd && temp->accountStatus == "Completed")
			{
				cout << "\t\t\t\tAccount found in Database." << endl;
				return temp;
			}
			temp = temp->next;
		}
		cout << "\t\t\t\tAccount not found in Database." << endl;

		return temp;
	}
	bool checkATMCredentials(int pn, long accNum)
	{
		if (head == NULL)
		{
			return false;
		}

		newAccountNode *temp = head;

		while (temp != NULL)
		{
			if (temp->debitCardPin == pn && temp->accountNumber == accNum && temp->accountStatus == "Completed")
			{
				return true;
			}
			temp = temp->next;
		}

		return false;
	}
	bool checkUsernameClash(string usernameEnt)
	{
		if (head == NULL)
		{
			return false;
		}

		newAccountNode *temp = head;

		while (temp != NULL)
		{
			if (temp->username == usernameEnt)
			{
				return true;
			}
			temp = temp->next;
		}

		return false;
	}
	void withDrawCash(string usernm, string paswd, long double amount)
	{
		newAccountNode *withDrawAcc = checkIfAccountPresent(usernm, paswd);

		if (withDrawAcc == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, transaction failed !!!!" << endl;
		}
		else
		{
			if (amount > withDrawAcc->cash)
			{
				cout << "\t\t\t\tAccount does not contain this much cash, transaction failed !!!!" << endl;
				cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
				_getch();
				return;
			}

			withDrawAcc->cash = withDrawAcc->cash - amount;
			cout << "\t\t\t\tTransaction successful!" << endl;
			cout << "\t\t\t\tRemaining Balance -> " << withDrawAcc->cash << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void changeATMpin(string usernm, string paswd, int oldPin, int newPin)
	{

		newAccountNode *changePinAcc = checkIfAccountPresent(usernm, paswd);

		if (changePinAcc == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, transaction failed !!!!" << endl;
		}
		else
		{
			if (newPin > 9999 || changePinAcc->debitCardPin != oldPin)
			{
				cout << "\t\t\t\tNew PIN is not 4 digits or Old PIN is invalid, process failed!!!!" << endl;
				return;
			}

			changePinAcc->debitCardPin = newPin;
			cout << "\t\t\t\tProcess successful!" << endl;
			cout << "\t\t\t\tPin Updated " << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void balanceEnquiry(string usernm, string paswd)
	{
		newAccountNode *balanceEnquiryAcc = checkIfAccountPresent(usernm, paswd);

		if (balanceEnquiryAcc == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, process failed !!!!" << endl;
		}
		else
		{
			cout << "\t\t\t\tAccount# -> " << balanceEnquiryAcc->accountNumber << endl;
			cout << "\t\t\t\tBalance -> " << balanceEnquiryAcc->cash << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayAccountDetails(string usernm, string paswd)
	{
		newAccountNode *accountDisplay = checkIfAccountPresent(usernm, paswd);
		if (accountDisplay == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, process failed !!!!" << endl;
		}
		else
		{
			cout << "\t\t\t\t------------------------------" << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\tAccount#: " << accountDisplay->accountNumber << endl;
			cout << "\t\t\t\tAccount Status: " << accountDisplay->accountStatus << endl;
			cout << "\t\t\t\tFirst Name: " << accountDisplay->firstName << endl;
			cout << "\t\t\t\tLast Name: " << accountDisplay->lastName << endl;
			cout << "\t\t\t\tEmail Address: " << accountDisplay->emailAddress << endl;
			cout << "\t\t\t\tCNIC: " << accountDisplay->CNIC << endl;
			cout << "\t\t\t\tPhone#: " << accountDisplay->phoneNumber << endl;
			cout << "\t\t\t\tCash: " << accountDisplay->cash << endl;
			cout << "\t\t\t\t ---Address--- " << endl;
			accountDisplay->homeAddress.displayAddress();
			cout << "\t\t\t\t -------------" << endl;
			cout << "\t\t\t\tUsername: " << accountDisplay->username << endl;
			cout << "\t\t\t\tPassword: " << accountDisplay->password << endl;
			cout << "\t\t\t\tDebit Card: " << accountDisplay->debitCard << endl;
			cout << "\t\t\t\tCheque Book: " << accountDisplay->chequeBook << endl;
			cout << "\t\t\t\tDebit Card PIN: " << accountDisplay->debitCardPin << endl;
			cout << "\t\t\t\t------------------------------" << endl << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayAllAccounts()
	{
		newAccountNode *temp = head;

		if (head == NULL)
		{
			cout << "\t\t\t\t Account Database is empty" << endl;
			cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 1;

		while (temp != NULL)
		{
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\tAccount Status: " << temp->accountStatus << endl;
			cout << "\t\t\t\tAccount Number: " << temp->accountNumber << endl;
			cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
			cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
			cout << "\t\t\t\tEmail Address: " << temp->emailAddress << endl;
			cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
			cout << "\t\t\t\tPhone#: " << temp->phoneNumber << endl;
			cout << "\t\t\t\t ---Address--- " << endl;
			temp->homeAddress.displayAddress();
			cout << "\t\t\t\t -------------" << endl;
			cout << "\t\t\t\tUsername: " << temp->username << endl;
			cout << "\t\t\t\tPassword: " << temp->password << endl;
			cout << "\t\t\t\tDebit Card: " << temp->debitCard << endl;
			cout << "\t\t\t\tCheque Book: " << temp->chequeBook << endl;
			cout << "\t\t\t\tDebit Card PIN: " << temp->debitCardPin << endl;
			cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
			temp = temp->next;
		}
		cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
		_getch();
	}
};

class admin
{
private:
	const string username = "admin123";
	const string password = "helloworld";
public:
	admin()
	{

	}
	string getUserName() const
	{
		return username;
	}
	string getPassWord() const
	{
		return password;
	}
	bool checkCredentials(string userNm, string passWd)
	{
		if (userNm == username && passWd == password)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void startScreen(tm* tPtr);
void endScreen(tm* tPtr);
void bankEnterScreen(tm* tPtr, int &opt);
void screenBank(tm* tPtr, int &opt);
void screenATMone(tm* tPtr, long &userCardNumber, int &userPINnumber);
void screenATMtwo(tm* tPtr, int &opt);
void screenAdminOne(tm* tPtr, string &adminUserName, string &adminPassword);
void screenAdminTwo(tm* tPtr, int &opt);
void screenAdminAccountOpenings(tm* tPtr, int &opt);
void screenAdminBillPayments(tm* tPtr, int &opt);

int main()
{
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);
	int bankEnterOption = 0;
	int optionInBankOne = 0;
	int optionInBankTwo = 0;
	int optionInATMone = 0;
	int optionInATMtwo = 0;
	int optionInAdmin = 0;
	int optionInAdminAccOpen = 0;
	int optionInAdminBillPaymt = 0;
	long userCardNumber = 0;
	int userCardPIN = 0;
	string accountViewUsnm = "";
	string accountViewPaswd = "";
	string adminUserName;
	string adminPassword;
	int flag = 0;
	admin administrator;
	long double withdrawCash = 0.00;
	int oldPinChange = 0;
	int newPinChange = 0;
	bankAccountsDatabase accDatabase;
	billPaymentQueue billPaymentLine;
	withdrawDepositQueue withDwDepstLine;
	string usnmATM = "";
	string pssdATM = "";

	startScreen(tPtr);
	system("cls");
	
BANKSCREEN:bankEnterScreen(tPtr, bankEnterOption);
	system("cls");
	switch (bankEnterOption)
	{
	case 1:
		INSIDEBANK:screenBank(tPtr, optionInBankOne);
		system("cls");

		cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
		cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		switch (optionInBankOne)
		{
		case 1:
			billPaymentLine.enqueue();
			system("cls");
			goto INSIDEBANK;
			break;
		case 2:
			withDwDepstLine.enqueue();
			system("cls");
			goto INSIDEBANK;
			break;
		case 3:
			accDatabase.insertNewAccount();
			system("cls");
			goto INSIDEBANK;
			break;
		case 4:
			cout << "\t\t\t Enter Username: ", cin >> accountViewUsnm, cout << endl;
			cout << "\t\t\t Enter Password: ", cin >> accountViewPaswd, cout << endl;
			accDatabase.displayAccountDetails(accountViewUsnm, accountViewPaswd);
			system("cls");
			goto INSIDEBANK;
			break;
		case 5:
			system("cls");
			goto BANKSCREEN;
			break;
		default:
			system("cls");
			cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
			cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

			cout << "\t\t\t ##########################################################################################################################" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu "<< endl;
			_getch();
			system("cls");
			goto INSIDEBANK;
			break;
		}
		break;
	case 2:
		MAINATMSCREEN:screenATMone(tPtr, userCardNumber, userCardPIN);
		system("cls");

		if (accDatabase.checkATMCredentials(userCardPIN, userCardNumber))
		{
		ATMSCREEN:screenATMtwo(tPtr, optionInATMtwo);
			system("cls");
			cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
			cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

			cout << "\t\t\t ##########################################################################################################################" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			switch (optionInATMtwo)
			{
			case 1:
				cout << "\t\t\t # Enter amount you wish to withdraw -> ", cin >> withdrawCash;
				cout << "\t\t\t # Enter your username -> ", cin >> usnmATM;
				cout << "\t\t\t # Enter your password -> ", cin >> pssdATM;
				accDatabase.withDrawCash(usnmATM, pssdATM, withdrawCash);
				system("cls");
				goto ATMSCREEN;
				break;
			case 2:
				cout << "\t\t\t # Enter your username -> ", cin >> usnmATM;
				cout << "\t\t\t # Enter your password -> ", cin >> pssdATM;
				accDatabase.balanceEnquiry(usnmATM, pssdATM);
				system("cls");
				goto ATMSCREEN;
				break;
			case 3:
				cout << "\t\t\t # Enter your username -> ", cin >> usnmATM;
				cout << "\t\t\t # Enter your password -> ", cin >> pssdATM;
				cout << "\t\t\t # Enter old pin -> ", cin >> oldPinChange;
				cout << "\t\t\t # Enter new pin (4 Digits) -> ", cin >> newPinChange;
				accDatabase.changeATMpin(usnmATM, pssdATM, oldPinChange, newPinChange);
				system("cls");
				goto ATMSCREEN;
				break;
			case 4:
				system("cls");
				goto BANKSCREEN;
				break;
			default:
				system("cls");
				cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
				cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

				cout << "\t\t\t ##########################################################################################################################" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
				_getch();
				system("cls");
				goto ATMSCREEN;
				break;
			}
		}
		else
		{
			cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
			cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

			cout << "\t\t\t ##########################################################################################################################" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t # Invalid Credentials Added" << endl;
			cout << "\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			system("cls");
			goto BANKSCREEN;
		}
		break;
	case 3:
		screenAdminOne(tPtr, adminUserName, adminPassword);
		system("cls");
		if (administrator.checkCredentials(adminUserName, adminPassword))
		{
			ADMINSCREEN:screenAdminTwo(tPtr, optionInAdmin);
			system("cls");

			switch (optionInAdmin)
			{
			case 1:
				ACCOPPSCREN:screenAdminAccountOpenings(tPtr, optionInAdminAccOpen);
				system("cls");
				cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
				cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

				cout << "\t\t\t ##########################################################################################################################" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				switch (optionInAdminAccOpen)
				{
				case 1:
					accDatabase.viewAccountsToBeProcessed();
					system("cls");
					goto ACCOPPSCREN;
					break;
				case 2:
					accDatabase.processAccounts();
					system("cls");
					goto ACCOPPSCREN;
					break;
				case 3:
					accDatabase.displayAllAccounts();
					system("cls");
					goto ACCOPPSCREN;
				case 4:
					system("cls");
					goto ADMINSCREEN;
					break;
				default:
					system("cls");
					cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
					cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

					cout << "\t\t\t ##########################################################################################################################" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
					_getch();
					system("cls");
					goto ACCOPPSCREN;
					break;
				}
			case 2:
				BILLPAYSCREEN:screenAdminBillPayments(tPtr, optionInAdminBillPaymt);
				system("cls");
				cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
				cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

				cout << "\t\t\t ##########################################################################################################################" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				switch (optionInAdminBillPaymt)
				{
				case 1:
					billPaymentLine.displayBillPaymentQueue();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 2:
					billPaymentLine.displayFront();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 3:
					billPaymentLine.dequeue();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 4:
					system("cls");
					goto ADMINSCREEN;
					break;
				default:
					system("cls");
					cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
					cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

					cout << "\t\t\t ##########################################################################################################################" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
					_getch();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				}
				break;
			case 3:
				system("cls");
				goto BANKSCREEN;
				break;
			default:
				system("cls");
				cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
				cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

				cout << "\t\t\t ##########################################################################################################################" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
				cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
				_getch();
				system("cls");
				goto ADMINSCREEN;
				break;
			}
		}
		else
		{
			cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
			cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

			cout << "\t\t\t ##########################################################################################################################" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
			cout << "\t\t\t # Invalid Credentials Added" << endl;
			cout << "\t\t\t Press any key to return to Bank Menu" << endl;
			_getch();
			system("cls");
			goto BANKSCREEN;
		}
		break;
	case 4:
		system("cls");
		endScreen(tPtr);
		break;
	default:
		system("cls");
		cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
		cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
		_getch();
		system("cls");
		goto BANKSCREEN;
		break;
	}

	cout << "\t\t\t ", system("pause");
	return 0;
}

void startScreen(tm* tPtr)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\tWelcome\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t  to\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\tDeveloped  by Ateeq Rana  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t ",system("pause");
}

void endScreen(tm* tPtr)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\tThank you\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\tfor using\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\tDeveloped  by Ateeq Rana  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
}

void bankEnterScreen(tm* tPtr, int &opt)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Enter Bank\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Enter ATM\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Admin Login\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Option: ",cin>>opt,cout<<endl;
}

void screenBank(tm* tPtr, int &opt)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to Bank\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Pay Bills\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Deposits/Cheques\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Open up Account\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) View your Account\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    5) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
}

void screenATMone(tm* tPtr, long &userCardNumber, int &userPINnumber)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to ATM\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\tEnter Following Details:\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Account Number\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Debit Card PIN\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Account Number: ", cin >> userCardNumber, cout << endl;
	cout << "\t\t\t Enter Debit Card PIN: ", cin >> userPINnumber, cout << endl;
}

void screenATMtwo(tm* tPtr, int &opt)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to ATM\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Withdraw Cash\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Balance Inquiry\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Change Pin\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
}

void screenAdminOne(tm* tPtr, string &adminUserName, string &adminPassword)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    Welcome to Admin\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\tEnter Following Details:\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Username\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Password\t\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Username: ", cin >> adminUserName, cout << endl;
	cout << "\t\t\t Enter Password: ", cin >> adminPassword, cout << endl;
}
void screenAdminTwo(tm* tPtr, int &opt)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    Welcome to Admin\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Process Account Openings\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Process Bill Payments\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
}
void screenAdminAccountOpenings(tm* tPtr, int &opt)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\tWelcome to Account Openings\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) View Account Openings\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Process Accounts\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) View Accounts in Database\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
}
void screenAdminBillPayments(tm* tPtr, int &opt)
{
	cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
	cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t Horizon Union Bank Ltd.\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    Welcome to Bill Payments\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    1) View Bill Payments\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    2) View Bill Payment at Front\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Process Bill Payment at Front\t\t\t\t          #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t    4) Exit\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
	cout << "\t\t\t ##########################################################################################################################" << endl;
	cout << "\t\t\t Enter Option: ", cin >> opt, cout << endl;
}