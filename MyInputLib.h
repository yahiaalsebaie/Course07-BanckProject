#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

namespace MyInputLib {
    /*int ReadNumber(string Message = "Please enter a number: ") {
        int Number = 0;
        cout << Message;
        cin >> Number;
        return Number;
    }*/
    int ReadNumber(string Message = "Please enter a number: ") {
        int Number = 0;
        cout << Message;
        cin >> Number;

        while (cin.fail()) //Validation..
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Invalid Number, Enter a valid one : ";
            cin >> Number;
        }


        return Number;
    }

    float ReadFloatNumber(string Message) {
        float Number = 0;
        cout << Message;
        cin >> Number;
        return Number;
    }

    int ReadPositiveNumber(string Message) {
        unsigned int Number = 0;
        do {
            cout << Message;
            cin >> Number;
            while (cin.fail()) //Validation..
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid Number, Enter a valid one : ";
                cin >> Number;
            }
        } while (Number <= 0);
        return Number;
    }

    int ReadNumberInRange(int From, int To, string Message = "Enter number: ") {
        int Number = 0;
        do {
            cout << Message << " [" << From << " to " << To << "]: ";
            cin >> Number;
            while (cin.fail()) //Validation..
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid Number, Enter a valid one : ";
                cin >> Number;
            }
        } while (Number < From || Number > To);
        
       

        return Number;

    }

    string ReadText(string Message) {
        string Text = "";
        cout << Message;
        getline(cin >> ws, Text); // ws to skip whitespaces
        return Text;
    }

    string ReadPassword() {
        string Password = "";
        cout << "Enter 3-Letter Password: ";
        cin >> Password;
        return Password;
    }

    void ReadVectorNumbers(vector<int>& vNumbers)
    {
        char AddMore = 'y';

        do
        {
            int Number;
            cout << "Enter a Number: "; cin >> Number;
            while (cin.fail()) //Validation..
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid Number, Enter a valid one : ";
                cin >> Number;
            }
            vNumbers.push_back(Number);
            cout << "Do you want to add more Numbers? : ";
            cin >> AddMore;
        } while (AddMore == 'y' || AddMore == 'Y' || AddMore == '1');

    }
}