#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MyStringLib.h"
#include <iomanip>


using namespace std;
using namespace MyStringLib;

const string ClientsFileName = "Clients.txt";

namespace MyBankDataLib
{
	string GetClientsFileName()
	{
		return ClientsFileName;
	}
	struct stClientData
	{
		string AccountNumber = "";
		string Name = "";
		string Phone = "";
		string PinCode = "";
		double AccountBalance = 0;
		bool MarkForDelete = false;
	};
	bool IsClientExistsByAccountNumber(const string& FileName,
		const string& AccountNumber);
	//stClientData ConvertLineToRecord();

	stClientData ReadNewClient()
	{
		stClientData Client;
		cout << "Enter Client.AccountNumber: ";
		getline(cin >> ws, Client.AccountNumber);
		Client.AccountNumber = Trim(Client.AccountNumber);
		
		while (IsClientExistsByAccountNumber(ClientsFileName, Client.AccountNumber))
		{
			cout << "Client with [" << Client.AccountNumber << "] already exists\nEnter another account number : ";
			getline(cin >> ws, Client.AccountNumber);
			Client.AccountNumber = Trim(Client.AccountNumber);
		}
		cout << "Enter Client.Name : ";
		getline(cin, Client.Name);
		Client.Name = Trim(Client.Name);
		cout << "Enter Client.Phone : ";
		getline(cin, Client.Phone);
		Client.Phone = Trim(Client.Phone);
		cout << "Enter Client.PinCode : ";
		getline(cin, Client.PinCode);
		Client.PinCode = Trim(Client.PinCode);
		cout << "Enter Client.AccountBalance: ";
		cin >> Client.AccountBalance;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return Client;
	}

	string ConvertRecordToLine(const stClientData& Client, string Separator = "#//#")
	{
		string Record = "";
		Record += Client.AccountNumber + Separator;
		Record += Client.Name + Separator;
		Record += Client.Phone + Separator;
		Record += Client.PinCode + Separator;
		Record += to_string(Client.AccountBalance);

		return Record;
	}

	stClientData ConvertLineToRecord(string Line, string Separator = "#//#")
	{
		vector<string> vString = SplitString(Line, Separator);
		stClientData Client;
		if (vString.size() < 5)
		{
			return Client; // هيرجع Struct قيمها الافتراضية فاضية ورصيدها 0
		}
		Client.AccountNumber = vString[0];
		Client.Name = vString[1];
		Client.Phone = vString[2];
		Client.PinCode = vString[3];
		Client.AccountBalance = stod(vString[4]);

		return Client;
	}

	void PrintClientCard(const stClientData& Client)
	{
		cout << "AccountNumber : " << Client.AccountNumber << endl;
		cout << "Name : " << Client.Name << endl;
		cout << "Phone : " << Client.Phone << endl;
		cout << "PinCode : " << Client.PinCode << endl;
		cout << "AccountBalance: " << Client.AccountBalance << endl;
	}
	void AddDataLineToFile(string FileName, const string DataLine)
	{
		fstream myFile;
		myFile.open(FileName, ios::out | ios::app);

		if (myFile.is_open())
		{
			myFile << DataLine << endl;
			myFile.close();
		}
	}
	vector<stClientData> LoadClientsDataFromFile(string FileName)
	{
		vector<stClientData> vClients;
		fstream myFile;
		myFile.open(FileName, ios::in);//Read (input) mode.

		if (myFile.is_open())
		{
			string line;
			stClientData Client;
			while (getline(myFile, line))
			{
				// لو السطر فاضي تماماً في الملف تخطاه فوراً ولا تقم بتحويله
				if (line == "")
					continue;
				Client = ConvertLineToRecord(line);
				vClients.push_back(Client);
			}
			myFile.close();
		}
		return vClients;
	}
	void AddNewClient(vector<stClientData>& vClients)
	{
		stClientData Client;
		Client = ReadNewClient();
		AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
		vClients = LoadClientsDataFromFile(ClientsFileName);
	}
	void AddClients(vector<stClientData>& vClients)
	{
		char AddMore = 'Y';
		do
		{
			//system("cls");
		//	cout << "Adding New Client:\n\n";
			AddNewClient(vClients);
			cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
				cin >> AddMore;
		} while (toupper(AddMore) == 'Y');
	}
	void PrintHeader(const vector<stClientData>& vClients)
	{
		cout << "\n\t\t\t\t\t Clients List (" << vClients.size() << ") Client(s)\n";
		cout << "________________________________________________________________________________________________\n";
		cout << "| " << left << setw(10) << "Acc.No";
		cout << "| " << left << setw(25) << "Name";
		cout << "| " << left << setw(16) << "Phone";
		cout << "| " << left << setw(10) << "PinCode";
		cout << "| " << left << setw(20) << "AccountBalance" << endl;
		cout << "________________________________________________________________________________________________\n";
	}
	void PrintClientRecord(const stClientData Client)
	{
		cout << "| " << left << setw(10) << Client.AccountNumber;
		cout << "| " << left << setw(25) << Client.Name;
		cout << "| " << left << setw(16) << Client.Phone;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(20) << Client.AccountBalance << endl;
	}
	void PrintClientsTable(const vector<stClientData>& vClients)
	{
		PrintHeader(vClients);
		for (const stClientData& client : vClients) {
			PrintClientRecord(client);
		}
		cout << "________________________________________________________________________________________________\n";


	};


	bool FindClientByAccountNumber(const string& AccountNumber, stClientData& Client,const vector<stClientData>& vClients)
	{
		for (const stClientData& c : vClients)
		{
			if (AccountNumber == c.AccountNumber)
			{
				Client = c;
				return true;
			}
		}
		return false;
	}
	string ReadClientAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

	void SaveClientsDataToFile(string FileName, const vector<stClientData>& vClients)
	{
		fstream myFile;
		myFile.open(FileName, ios::out);

		if (myFile.is_open())
		{
			string line;
			//stClientData Client;
			for (const stClientData& c : vClients)
			{
				if (c.MarkForDelete == false)
				{
					line = ConvertRecordToLine(c);
					myFile << line << endl;
				}
			}
			myFile.close();
		}
	}

	bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClientData>& vClients)
	{
		for (stClientData& c : vClients)
		{
			if (AccountNumber == c.AccountNumber)
			{
				c.MarkForDelete = true;
				return true;
			}
		}
		return false;
	}
	void DeleteClientByAccountNumber(string AccountNumber, vector <stClientData>& vClients)
	{
		stClientData Client;
		char Answer = 'n';

		if (FindClientByAccountNumber(AccountNumber, Client, vClients))
		{

			cout << "\nThe following are the client details:\n\n";
			PrintClientCard(Client);


			cout << "\nAre you sure you want to delete this Client ? [Y/N] >> ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
				SaveClientsDataToFile(ClientsFileName, vClients);
				vClients = LoadClientsDataFromFile(ClientsFileName);

				cout << "\nClient deleted successfully.\n";
			}
			else cout << "\nClient Not Deleted.\n";

		}
		else cout << "\nClient with Account Number [" << AccountNumber << "] Not Found!\n";

	}


	stClientData changeClientRecord(string AccountNumber)
	{
		stClientData Client;
		Client.AccountNumber = AccountNumber;
		cout << "Update Name : ";
		getline(cin >> ws, Client.Name);
		Client.Name = Trim(Client.Name);

		cout << "Update Phone : ";
		getline(cin, Client.Phone);
		Client.Phone = Trim(Client.Phone);

		cout << "Update Pin Code : ";
		getline(cin, Client.PinCode);
		Client.PinCode = Trim(Client.PinCode);

		cout << "Update Account Balance : ";
		cin >> Client.AccountBalance;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return Client;
	}
	bool UpdateRecord(string AccountNumber, vector <stClientData>& vClients)
	{
		for (stClientData& c : vClients)
		{
			if (AccountNumber == c.AccountNumber)
			{
				c = changeClientRecord(AccountNumber);
				return true;
			}
		}
		return false;
	}
	void UpdateClientByAccountNumber(string AccountNumber, vector <stClientData>& vClients)
	{
		stClientData Client;
		char Answer = 'n';

		if (FindClientByAccountNumber(AccountNumber, Client, vClients))
		{
			cout << "\nThe following are the client details:\n\n";
			PrintClientCard(Client);

			cout << "\nAre you sure you want to Update this Client ? [Y/N] >> ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{

				UpdateRecord(AccountNumber, vClients);
				SaveClientsDataToFile(ClientsFileName, vClients);

				cout << "\nClient Updated Successfully.\n";
				FindClientByAccountNumber(AccountNumber, Client, vClients); // عشان نطبع البيانات الجديدة صح، بنجيبها من الفيكتور بعد ما اتحدث
				cout << "\nThe following are the updated client details:\n\n";
				PrintClientCard(Client);
			}
			else cout << "\nUpdated Cancelled.\n";

		}
		else cout << "\nClient with Account Number [" << AccountNumber << "] Not Found!\n";
	}
	bool IsClientExistsByAccountNumber(const string& FileName,
		const string& AccountNumber)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				if (Line == "") continue; 
				stClientData Client = ConvertLineToRecord(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return true;
				}
			}
			MyFile.close();
		}
		return false; 
	}
	
}
