#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "MyBankDataLib.h"
#include "MyInputLib.h"
using namespace std;

namespace bank = MyBankDataLib;

enum enMainMenuOptions {
	ShowClientsList = 1, AddNewClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Transactions = 6, Exit = 7
};
enum enTransactions {
	Deposit = 1, Withdraw = 2, TotalBalances = 3, MainMenu = 4
};



void ShowMainMenuScreen(vector<bank::stClientData>& vClients);
void ShowTransactionsMenuScreen(vector<bank::stClientData>& vClients);


void BackToMainMenu()
{
	cout << "\n\nPress any key to go back to Main Menu...";
	system("pause>0");
}
void BackToTransactionsScreen()
{
	cout << "\n\nPress any key to go back to Transactions Menu...";
	system("pause>0");
}
void showExitScreen()
{
	system("cls");
	cout << "=========================================\n";
	cout << "\tThe End of Program ^_^\n";
	cout << "=========================================\n";
//	system("pause>0");
}
void ShowClientsListScreen(const vector<bank::stClientData> &vClients)
{
	system("cls");
	//cout << "=========================================\n";
	//cout << "\tShow Clients Screen\n";
	//cout << "=========================================\n";
	bank::PrintClientsTable(vClients);
	BackToMainMenu();
}
void AddNewClientsScreen(vector<bank::stClientData>& vClients)
{
	system("cls");
	cout << "=========================================\n";
	cout << "\tAdd New Client Screen\n";
	cout << "=========================================\n";
	bank::AddClients(vClients);
	BackToMainMenu();
}
void DeleteClientScreen(vector<bank::stClientData>& vClients)
{
system("cls");
cout << "=========================================\n";
cout << "\tDelete Client Screen\n";
cout << "=========================================\n";
bank::DeleteClientByAccountNumber(bank::ReadClientAccountNumber(), vClients);
BackToMainMenu();
}

void UpdateClientScreen(vector<bank::stClientData>& vClients)
{
	system("cls");
	cout << "=========================================\n";
	cout << "\tUpdate Client Screen\n";
	cout << "=========================================\n";
	bank::UpdateClientByAccountNumber(bank::ReadClientAccountNumber(), vClients);
	BackToMainMenu();
}

void FindClientScreen(const vector<bank::stClientData>& vClients)
{
	bank::stClientData Client;
	system("cls");
	cout << "=========================================\n";
	cout << "\tFind Client Screen\n";
	cout << "=========================================\n";
	string AccountNumber = bank::ReadClientAccountNumber();
	if (bank::FindClientByAccountNumber(AccountNumber,Client,vClients))
	bank::PrintClientCard(Client);
	else cout << "\nClient with Account Number [" << AccountNumber << "] Not Found! :(\n";
	BackToMainMenu();
}

void PrintShortClientHeader(const vector<bank::stClientData>& vClients)
{
	cout << "\n\t\t\t\t\t Clients List (" << vClients.size() << ") Client(s)\n";
	cout << "________________________________________________________________________________________________\n";
	cout << "| " << left << setw(10) << "Acc.No";
	cout << "| " << left << setw(40) << "Name";
	cout << "| " << left << setw(20) << "AccountBalance" << endl;
	cout << "________________________________________________________________________________________________\n";
}
void PrintShortClientRecord(const bank::stClientData Client)
{
	cout << "| " << left << setw(10) << Client.AccountNumber;
	cout << "| " << left << setw(45) << Client.Name;
	cout << "| " << left << setw(20) << Client.AccountBalance << endl;
}
void PrintClientsShortTableWithTotalBalancesScreen(const vector<bank::stClientData>& vClients)
{	
	double total = 0;
	PrintShortClientHeader(vClients);
	for (const bank::stClientData& client : vClients) {
		PrintShortClientRecord(client);
		total += client.AccountBalance;
	}

	cout << "________________________________________________________________________________________________\n";
	cout << "\n\t\t\t\t\t Total Balances = " << total << endl;

};
//double CalculateTotalBalances(const vector<bank::stClientData>& vClients)
//{
//	double total = 0;
//	for (const bank::stClientData& client : vClients) {
//		total += client.AccountBalance;
//	}
//	return total;
//}
//void PrintClientsShortTable(const vector<bank::stClientData>& vClients)
//{
//	PrintShortClientHeader(vClients);
//	for (const bank::stClientData& client : vClients) {
//		PrintShortClientRecord(client);
//	}
//	cout << "________________________________________________________________________________________________\n";
//};

//void PrinttotalBalances()
//{
//
//}

bool UpdateBalance (string AccountNumber, vector <bank::stClientData>& vClients, double NewBalance)
{
	for (bank::stClientData& c : vClients)
	{
		if (AccountNumber == c.AccountNumber)
		{
			c.AccountBalance = NewBalance;
			bank::SaveClientsDataToFile(bank::GetClientsFileName(), vClients);
			return true;
		}
	}
	return false;
}
void WithdrawFromClientBalanceByAccountNumber(string AccountNumber, vector <bank::stClientData>& vClients/*, double Amount ,double NewBalance*/)
{
	bank::stClientData Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, Client, vClients))
	{
		cout << "\nThe following are the client details:\n\n";
	
		PrintClientCard(Client);

		//Amount
		double WithdrawAmount = MyInputLib::ReadPositiveNumber("\n\nPlease Enter Withdraw Amount : ");
		
		while (Client.AccountBalance < WithdrawAmount)
		{
			cout << "\nAmount Exceeds the Balance!\n";
			cout << "You can withdraw up to : " << Client.AccountBalance << endl;
			WithdrawAmount = MyInputLib::ReadPositiveNumber("Please Enter another Amount : ");
		}
			double NewBalance = Client.AccountBalance - WithdrawAmount;


		cout << "\nAre you sure you want to perform this transaction ? [Y/N] >> ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			UpdateBalance(AccountNumber, vClients, NewBalance);

			cout << "New balance is [" << NewBalance << "]." << endl;
		}
		else cout << "\nNo Changes..\n";

	}
	else cout << "\nClient with Account Number [" << AccountNumber << "] Not Found!\n";
}
void DepositClientBalanceByAccountNumber(string AccountNumber, vector <bank::stClientData>& vClients/*, double Amount ,double NewBalance*/)
{
	bank::stClientData Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, Client, vClients))
	{
		cout << "\nThe following are the client details:\n\n";
	
		PrintClientCard(Client);

		//Amount
		double DepositAmount = MyInputLib::ReadPositiveNumber("\n\nPlease Enter Deposit Amount : ");

		double NewBalance = DepositAmount + Client.AccountBalance;


		cout << "\nAre you sure you want to perform this transaction ? [Y/N] >> ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{

			UpdateBalance(AccountNumber, vClients, NewBalance);

			cout << "Done Successfully, New balance is [" << NewBalance << "]." << endl;
		}
		else cout << "\nNo Changes..\n";

	}
	else cout << "\nClient with Account Number [" << AccountNumber << "] Not Found!\n";
}

void ShowDepositScreen( vector<bank::stClientData>& vClients)
{
	bank::stClientData Client;

	system("cls");
	cout << "=========================================\n";
	cout << "\tDeposit Screen \n";
	cout << "=========================================\n";
	string AccountNumber = "";
	
		AccountNumber = bank::ReadClientAccountNumber();
	/*	double DepositAmount = MyInputLib::ReadPositiveNumber("Please Enter Deposit Amount : ");*/
		//double NewBalance = DepositAmount + Client.AccountBalance;
		DepositClientBalanceByAccountNumber(AccountNumber, vClients);

}
void ShowWithdrawScreen( vector<bank::stClientData>& vClients)
{
	bank::stClientData Client;

	system("cls");
	cout << "=========================================\n";
	cout << "\tWithdraw Screen \n";
	cout << "=========================================\n";
	string AccountNumber = "";
	
		AccountNumber = bank::ReadClientAccountNumber();
	/*	double DepositAmount = MyInputLib::ReadPositiveNumber("Please Enter Deposit Amount : ");*/
		//double NewBalance = DepositAmount + Client.AccountBalance;
		WithdrawFromClientBalanceByAccountNumber(AccountNumber, vClients);

}

void PerformTransactionsScreen(enTransactions TransactionsOptions, vector<bank::stClientData>& vClients)
{

	//	string AccountNumber = ""; 
	bank::stClientData Client;

	switch (TransactionsOptions)
	{
	case Deposit: ShowDepositScreen(vClients);
		BackToTransactionsScreen();
		break;
	case Withdraw: ShowWithdrawScreen(vClients);
		BackToTransactionsScreen();
		break;
	case TotalBalances: system("cls");
		PrintClientsShortTableWithTotalBalancesScreen(vClients);
		BackToTransactionsScreen();
		break;
	case MainMenu:
		break;
	}
}

void ShowTransactionsMenuScreen( vector<bank::stClientData>& vClients)
{
	enTransactions Choice;

	do {
		system("cls");
		system("color 0A");

	bank::stClientData Client;
	system("cls");
	cout << "\n==========================================\n";
	cout <<   "========[Transactions Menu Screen]========";
	cout << "\n==========================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menu.\n";
	cout << "==========================================\n";
	Choice = (enTransactions)MyInputLib::ReadNumberInRange(1, 4, "Choose what do you want to do");
	PerformTransactionsScreen(Choice, vClients);
	} while (Choice != enTransactions::MainMenu);
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOptions, vector<bank::stClientData>& vClients)
{
	
//	string AccountNumber = ""; 
	bank::stClientData Client;

	switch (MainMenuOptions)
	{
	case ShowClientsList:
		ShowClientsListScreen(vClients);
		break;

	case AddNewClient:
		AddNewClientsScreen(vClients);
		break;

	case DeleteClient:
		DeleteClientScreen(vClients);
		break;

	case UpdateClient:
		UpdateClientScreen(vClients);
		break;

	case FindClient:
		FindClientScreen(vClients);
		break;

	case Transactions:
		ShowTransactionsMenuScreen(vClients);
		break;
	case Exit:
		showExitScreen();
		break;
	}
}

void ShowMainMenuScreen(vector<bank::stClientData>& vClients)
{
	enMainMenuOptions Choice;

	do {
		system("cls");
		system("color 0A");
		cout << "\n=========================================\n";
		cout << "============[Main Menu Screen]===========";
		cout << "\n=========================================\n";
		cout << "\t[1] Show Clients List.\n";
		cout << "\t[2] Add New Client.\n";
		cout << "\t[3] Delete Client.\n";
		cout << "\t[4] Update Client Info.\n";
		cout << "\t[5] Find Client.\n";
		cout << "\t[6] Transactions.\n";
		cout << "\t[7] Exit.\n";
		cout << "=========================================\n";
		 Choice = (enMainMenuOptions)MyInputLib::ReadNumberInRange(1, 7, "Choose what do you want to do");
		PerformMainMenuOption(Choice,vClients);
	} while (Choice != enMainMenuOptions::Exit);
	
}

int main()
{
	vector<bank::stClientData> vClients = bank::LoadClientsDataFromFile(bank::GetClientsFileName());

	ShowMainMenuScreen(vClients);

	return 0;
}