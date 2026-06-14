#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace myInputLib {



int RandomNumber(int From, int To)
{
    
    //srand((unsigned)time(NULL)); //Put it in main()
    
    int random = rand() % (To - From + 1) + From;
    return random;
}
int ReadNumber(string Message)
{
    int Number = 0;
        cout << Message;
        cin >> Number;
    return Number;
}
int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
int ReadNumberInRange(int From, int To)
{
    int Number = 0;
    do
    {
        cin >> Number;
        if (Number < From || Number > To)
            cout << "\nInvalid Input!\n";
    } while (Number < From || Number > To);

    return Number;
}
int ReadNumberInRange(int From, int To, string Message, string InValidInputMessage = "")
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
        if (Number < From || Number > To)
        {
            cout << "\nInvalid Input! Enter In Range [" << From << " to " << To << "].\n";

            cout << InValidInputMessage;
        }
    } while (Number < From || Number > To);

    return Number;
}

enum enPrimeOrNot { Prime = 1, NotPrime = 2 };

enPrimeOrNot CheckPrimeNumbers(int Number)
{
    //  int M = round(Number / 2);
    int M = sqrt(Number); //رياضياً، يكفي أن تبحث حتى الجذر التربيعي للعدد لتكون العملية أسرع بكثير.

    for (int Counter = 2; Counter <= M; Counter++)
        if (Number % Counter == 0) return enPrimeOrNot::NotPrime;
    return enPrimeOrNot::Prime;

}

void PrintPrimeNumbers(int Number)
{
    cout << "\nPrint All Prime Numbers From 1 To " << Number;
    cout << "\n-----------------------------------\n";
    for (int i = 1; i <= Number; i++)
    {
        if (CheckPrimeNumbers(i) == enPrimeOrNot::Prime)
        {
            cout << i << "\n";
        }
    }

}
enum enPerfectNumber { Perfect = 1, NotPerfect = 2 };

bool isPerfectNumber(int Number)
{
    int Sum = 0; // Initialize the sum of divisors to 0.

    // Loop from 1 to Number - 1 to find all proper divisors.
    for (int i = 1; i < Number; i++)
    {
        // If i divides Number evenly, it is a divisor.
        if (Number % i == 0)
            Sum += i; // Add the divisor to the sum.
    }

    // Compare the sum of divisors to the original number.
    // Return true if they are equal (the number is perfect), or false if they are not.
    return Number == Sum;
}

void PrintIsPerfectNumberResults(int Number)
{
    // Check if the number is perfect using the isPerfectNumber function.
    if (isPerfectNumber(Number))
        cout << Number << " Is Perfect Number.\n";  // If true, print that the number is perfect.
    else
        cout << Number << " Is NOT Perfect Number.\n"; // Otherwise, print that it is not perfect.
}
enPerfectNumber CheckPerfectNumber(int Number)
{

    int Sum = 0;
    for (int Counter = 1; Counter <= Number / 2; Counter++)
    {
        if (Number % Counter == 0)
            Sum += Counter;
    }
    return (Number == Sum) ? enPerfectNumber::Perfect : enPerfectNumber::NotPerfect;
}

void PrintAllPerfectNumbersFrom1ToN(int Number)
{
    cout << "\n----------------------------------------\n";
    cout << "Print All Perfect Numbers From 1 To " << Number;
    cout << "\n----------------------------------------\n";

    for (int i = 1; i <= Number; i++)
    {
        if (CheckPerfectNumber(i) == enPerfectNumber::Perfect)
        {
            cout << i << "\n";
        }
    }

}
void PrintDigits(int Number)
{
    int Sum = 0, Remainder = 0; // Initialize variables. Although 'Sum' is declared, it is not used in this function.
    // Continue looping while there are digits left in Number.
    while (Number > 0)
    {
        Remainder = Number % 10; // Extract the last digit of Number.
        Number = Number / 10;    // Remove the last digit from Number.
        cout << Remainder << endl;  // Print the extracted digit on a new line.
    }
}
int ReverseNumber(int Number)
{
    int Remainder = 0, Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number /= 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
}
int SumOfDigits(int Number)
{
    int Remaining = 0, Sum = 0;
    if (Number == 0) { return Sum; }
    while (Number > 0)
    {
        Remaining = Number % 10;
        Number /= 10;
        Sum += Remaining;
    }
    return Sum;
}
void FillFrequencyArray(int FullNumber, int freq[10] = { 0 })
{
    //  for (short i = 0; i < 10; i++) freq[i] = 0; // أصفرها هنا أو في المين
    while (FullNumber > 0)
    {
        freq[FullNumber % 10]++;
        FullNumber /= 10;
    }
}
void PrintFrequencyArray(int freq[10])
{
    for (int Digit = 0; Digit <= 9; Digit++)
    {
        if (freq[Digit] > 0)
        {
            cout << "\n----------------------------------------------\n";
            cout << "Digit (" << Digit << ") Frequency is [" << freq[Digit] << "] Time(s).";
            cout << "\n----------------------------------------------";
        }
    }
}
int CountDigitFrequency(long long FullNumber, short SingleDigit)
{
    int Remainder = 0, counter = 0;
    while (FullNumber > 0)
    {
        Remainder = FullNumber % 10;
        FullNumber /= 10;
        if (SingleDigit == Remainder) counter++;
    }
    return counter;
}
int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Freq = 0;       // Initialize frequency counter to zero.
    int Remainder = 0;  // Variable to store the digit extracted from the number.

    // Process each digit until the number becomes 0.
    while (Number > 0)
    {
        Remainder = Number % 10;  // Extract the last digit from the number.
        Number = Number / 10;     // Remove the last digit from the number.

        // If the extracted digit matches the digit we're checking, increment the frequency counter.
        if (DigitToCheck == Remainder)
        {
            Freq++;
        }
    }
    return Freq;  // Return the total count of the specified digit.
}
void PrintAllDigitsFrequency(int Number)
{
    cout << endl;  // Print an empty line for formatting.

    // Loop through all digits from 0 to 9.
    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = 0;                         // Variable to hold frequency for the current digit.
        DigitFrequency = CountDigitFrequency(i, Number);    // Get the frequency of digit 'i' in the number.

        // Only print the result if the digit appears at least once.
        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequencey is "  // Print the digit and its frequency.
                << DigitFrequency << " Time(s).\n";
        }
    }
}

// Function: ReverseNumber
// Purpose: Reverses the digits of a given number.
//          For example, if the input is 123, the function returns 321.
// Parameter: Number - the positive integer whose digits are to be reversed.
// Returns: The reversed number.
int ReverseNumber(int Number)
{
    int Remainder = 0;  // Variable to store the last digit extracted from the number.
    int Number2 = 0;    // Variable to accumulate the reversed number.

    // Process each digit until the original number becomes 0.
    while (Number > 0)
    {
        Remainder = Number % 10;          // Extract the last digit from Number.
        Number = Number / 10;             // Remove the last digit from Number.
        Number2 = Number2 * 10 + Remainder; // Append the extracted digit to Number2.
    }

    return Number2;  // Return the reversed number.
}

// Function: PrintDigits
// Purpose: Prints each digit of the given number on a new line.
//          It extracts the digits using the modulo operator and division.
// Parameter: Number - the positive integer whose digits will be printed.
void PrintDigits(int Number)
{
    int Remainder = 0;  // Variable to store the digit extracted from the number.

    // Continue processing until there are no digits left in Number.
    while (Number > 0)
    {
        Remainder = Number % 10;  // Extract the last digit.
        Number = Number / 10;     // Remove the last digit.
        cout << Remainder << endl; // Print the extracted digit on a new line.
    }
}

int FillArrayWithDigits(int Number, int Digits[20])
{
    int Counter = 0;
    while (Number > 0)
    {
        Digits[Counter] = Number % 10;
        Number /= 10;
        Counter++;
    }
    return Counter; // We need to know number of digits to print it right
}

void PrintArrayInReverse(int Digits[20], int NumberOfDigits)
{
    for (int i = NumberOfDigits - 1; i >= 0; i--)
    {
        cout << Digits[i] << endl;
    }
}

bool IsPalindromeNumber(int Number)
{
    return (Number == ReverseNumber(Number));
}

void PrintResult(int Number)
{

    if (IsPalindromeNumber(Number)) cout << "\nYes, It is a Palindrome number\n";
    else cout << "\nNo, It is Not a Palindrome number\n";
}
// Function: PrintInvertedNumberPattern
// Purpose: Prints an inverted number pattern where each line prints a sequence of digits.
//          The first line prints the given number repeated that many times, the next line prints one less, and so on.
// Parameter: Number - the starting number and the maximum count of digits to print in the first line.
void PrintInvertedNumberPattern(int Number)
{
    cout << "\n";  // Print an empty line for formatting.

    // Outer loop: Starts from the given number and decrements to 1.
    for (int i = Number; i >= 1; i--)
    {
        // Inner loop: Prints the current number 'i' repeatedly.
        // It runs from 1 up to the current value of 'i'.
        for (int j = 1; j <= i; j++)
        {
            cout << i;  // Print the digit 'i' without a space.
        }

        cout << "\n";  // After printing one line, move to the next line.
    }
}
void PrintNumberPattern(int Number)
{
    for (short i = 1; i <= Number; i++)
    {
        for (short j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

void PrintNumberPattern(int Number)
{
    for (short i = 1; i <= Number; i++)
    {
        for (short j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }

}

void PrintInvertedLettersPatternV1(int Number)
{
    short Count = Number;
    for (short i = Number; i > 0; i--)
    {
        for (short ii = Count; ii > 0; ii--)
        {
            cout << char(Count + 64);
        }
        Count--;
        cout << endl;
    }

}
void PrintInvertedLettersPatternV2(int Number)
{
    for (short i = Number; i >= 1; i--)
    {
        for (short j = 1; j <= i; j++)
        {
            cout << char((i + 64));
        }
        cout << endl;

    }
}

void PrintInvertedLetterPattern(int Number)
{ // حل الأستاذ
    cout << "\n";  // Print an empty line for formatting.

    // Outer loop: 'i' represents the ASCII code for the current letter.
    // It starts at (65 + Number - 1) which is the highest letter to be printed,
    // and decrements down to 65 ('A').
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        // Calculate the number of times to print the current letter.
        // When i = 65 + Number - 1, (65 + Number - 1 - i) equals 0,
        // so the inner loop runs 'Number' times.
        // For each subsequent row, this value increases, reducing the count by 1 each time.
        for (int j = 1; j <= Number - ((65 + Number - 1) - i); j++)
        {
            cout << char(i);  // Print the current letter (converted from its ASCII code).
        }

        cout << "\n";  // After printing the current row, move to the next line.
    }
}
void myPrintLetterPattern(int Number)
{ // Code is read much more often than it is written..
    for (short i = 1; i <= (Number); i++)
    {
        for (short j = 1; j <= i; j++)
        {
            cout << char(i + 64);
        }
        cout << endl;
    }
}

void PrintLetterPattern(int Number)
{ // حل الأستاذ
    cout << "\n";  // Print an empty line for formatting.

    // Outer loop: Iterates from ASCII value 65 ('A') to (65 + Number - 1).
    // Each iteration corresponds to a row in the pattern.
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        // Inner loop: Determines the number of times to print the current letter.
        // The expression (i - 65 + 1) calculates the position of the letter in the alphabet,
        // which is also the number of times it should be repeated in the current row.
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);  // Convert the ASCII value to its corresponding character and print it.
        }

        cout << "\n";  // Move to the next line after printing the current row.
    }
}
void myPrintWordsFromAAAtoZZZ()
{
    for (short i = 65; i <= 90; i++)
    {
        for (short j = 65; j <= 90; j++)
        {
            for (short k = 65; k <= 90; k++)
            {
                cout << char(i) << char(j) << char(k);
                cout << endl;
            }
        }
        cout << endl;
    }
}

void PrintAllFromAAAtoZZZ()
{ // الأستاذ
    cout << "\n";  // Print an empty line for formatting.
    string word = "";  // Initialize an empty string to build each three-letter combination.

    // Outer loop: Iterates over ASCII values for uppercase letters (65 'A' to 90 'Z') for the first letter.
    for (int i = 65; i <= 90; i++)
    {
        // Middle loop: Iterates over ASCII values for uppercase letters for the second letter.
        for (int j = 65; j <= 90; j++)
        {
            // Inner loop: Iterates over ASCII values for uppercase letters for the third letter.
            for (int k = 65; k <= 90; k++)
            {
                // Append the current letter for the first position.
                word += char(i);
                // Append the current letter for the second position.
                word += char(j);
                // Append the current letter for the third position.
                word += char(k);

                // Output the constructed three-letter word.
                cout << word << endl;
                // Reset the word string to empty for the next combination.
                word = "";
            }
        }
        // After completing combinations for the current first letter, print a separator line.
        cout << "\n____________________________\n";
    }
}
string ReadPassword()
{
    string Password = "";
    cout << "Enter 3-Letter Password : ";
    cin >> Password;
    return Password;
}


bool GuessAny3LetterPassword(string Password)
{
    string word = "";
    int Counter = 0;
    for (short i = 32; i <= 126; i++)
    {
        for (short j = 32; j <= 126; j++)
        {
            for (short k = 32; k <= 126; k++)
            {
                Counter++;
                word += char(i);
                word += char(j);
                word += char(k);
                cout << "Trial [" << Counter << "]: " << word << "\n";
                if (word == Password)
                {
                    cout << "Password is [" << Password << "].\n";
                    cout << "Found after [" << Counter << "] Trial(s).\n";
                    return true;
                }
                word = "";
                cout << endl;
            }
        }
        cout << endl;
    }
    return false;
}
bool GuessPassword(string Password)
{
    string word = "";
    int Counter = 0;
    for (short i = 65; i <= 90; i++)
    {
        for (short j = 65; j <= 90; j++)
        {
            for (short k = 65; k <= 90; k++)
            {
                Counter++;
                word += char(i);
                word += char(j);
                word += char(k);
                cout << "Trial [" << Counter << "]: " << word << "\n";
                if (word == Password)
                {
                    cout << "Password is [" << Password << "].\n";
                    cout << "Found after [" << Counter << "] Trial(s).\n";
                    return true;
                }
                word = "";
                cout << endl;
            }
        }
        cout << endl;
    }
    return false;
}

string ReadText(string Message)
{
    string Text = "";
    cout << Message;
    getline(cin, Text);
    return Text;
}


string EncryptText(string txt, short Key)
{

    for (short i = 0; i < txt.length(); i++)
    {
        txt[i] += Key;
    }
    return txt;
}

string DecryptText(string txt, short Key)
{

    for (short i = 0; i < txt.length(); i++)
    {
        txt[i] -= Key;
        // Convert the current character to its integer ASCII value,
        // add the encryption key, cast it back to char, and assign it back.
        //Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return txt;
}

string EncryptText(string txt, short Key)
{

    for (short i = 0; i < txt.length(); i++)
    {
        txt[i] += Key;
    }
    return txt;
}

string DecryptText(string txt, short Key)
{

    for (short i = 0; i < txt.length(); i++)
    {
        txt[i] -= Key;
        // Convert the current character to its integer ASCII value,
        // add the encryption key, cast it back to char, and assign it back.
        //Text[i] = char((int)Text[i] + EncryptionKey);
    }
    return txt;
}
enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4 };

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case SmallLetter:
        return (char)RandomNumber(97, 122);
    case CapitalLetter:
        return (char)RandomNumber(65, 90);
    case SpecialChar:
        return (char)RandomNumber(33, 47);
    case Digit:
        return (char)RandomNumber(48, 57);
    default:
        return (char)RandomNumber(97, 122);
    }
}

string GenerateWord(enCharType CharType, short Length = 4)
{
    string word = "";
    for (short i = 0; i < Length; i++)
    {
        word += GetRandomCharacter(CharType);
    }
    return word;
}

string generateRandomKey(enCharType CharType, short Length = 4)
{
    string RandomKey = "";
    for (short i = 1; i < Length; i++)
    {
        // if (i == 4) return RandomKey += GenerateWord(CharType); //هخليها تحت عشان ميعديش عليها 4 مرات
        RandomKey += GenerateWord(CharType) + '-';
    }
    return RandomKey += GenerateWord(CharType);
}

void PrintGeneratedKeys(int NumberOfKeys, enCharType CharType)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "] : " << generateRandomKey(CharType) << endl;
    }
}

void ReadArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    cout << "\nEnter array elements: \n";
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << endl;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int count = 0;
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (Number == arr[i])
        {
            count++;
        }
    }
    return count;
}
void ReadArrayElements(int NumberOfElements, int Elements[20])
{
    for (short i = 0; i < NumberOfElements; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> Elements[i];
    }
}

void PrintOriginalArray(int Elements[20], int NumberOfElements)
{
    cout << "Original Array : ";
    for (int i = NumberOfElements - 1; i >= 0; i--)
    {
        cout << Elements[i] << " ";
    }
    cout << endl;
}

unsigned short GetRepeatedTimes(int Elements[20], int NumberOfElements, int NumberToCheck)
{
    unsigned short Counter = 0;
    for (unsigned short i = 0; i < NumberOfElements; i++)
    {
        if (Elements[i] == NumberToCheck) Counter++;
    }
    return Counter;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements: ";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);

}

int GetMaxNumberInArray(int arr[100], int arrLength)
{
    short MaxNumber = 0;

    for (short i = 0; i < arrLength; i++)
    {
        if (arr[i] > MaxNumber)
            MaxNumber = arr[i];
    }
    return MaxNumber;

}
int GetMinNumberInArray(int arr[100], int arrLength)
{
    short MinNumber = arr[0];

    for (short i = 0; i < arrLength; i++)
    {
        if (arr[i] < MinNumber)
            MinNumber = arr[i];
    }
    return MinNumber;

}
int GetSumOfNumberInArray(int arr[100], int arrLength)
{
    short MinNumber = 0;

    for (short i = 0; i < arrLength; i++)
    {

        MinNumber += arr[i];
    }
    return MinNumber;

}
int SumArray(int arr[100], int arrLength)
{
    short MinNumber = 0;

    for (short i = 0; i < arrLength; i++)
    {

        MinNumber += arr[i];
    }
    return MinNumber;

}
float ArrayAverage(int arr[100], int arrLength)
{
    return (float)SumArray(arr, arrLength) / arrLength;

}
void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{

    for (short i = 0; i < arrLength; i++)
    {
        arrDestination[i] = arrSource[i];
    }

}

void CopyPrimeNumbersToDestinationArray(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
    int Counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if ((CheckPrimeNumbers(arrSource[i])) == enPrimeOrNot::Prime)
        {
            arrDestination[Counter] = arrSource[i];
            Counter++;
        }
    }
    arr2Length = Counter;
}
void SumOf2Arrays(int arr1[100], int arr2[100], int arr3Sum[100], int arrLength)
{
    for (short i = 0; i < arrLength; i++)
    {
        arr3Sum[i] = arr1[i] + arr2[i];
    }
}
// Function: Swap
// Purpose: Swaps the values of two integers.
// Parameters:
//   - A: Reference to the first integer.
//   - B: Reference to the second integer.
void Swap(int& A, int& B)
{
    int Temp;    // Temporary variable to hold the value of A.
    Temp = A;    // Save the value of A in Temp.
    A = B;       // Copy the value of B into A.
    B = Temp;    // Copy the value of Temp (original A) into B.
}

// Function: FillArrayWith1toN
// Purpose: Fills an array with sequential numbers from 1 to N, where N is the array length.
// Parameters:
//   - arr: The integer array to fill (capacity 100).
//   - arrLength: The number of elements to fill in the array.
void FillArrayWith1toN(int arr[100], int arrLength)
{
    // Loop through each index and assign the value (index + 1) to that element.
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the random range.
//   - To: The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Use the modulus operator to get a random number within the range,
    // then shift it by adding From.
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: ShuffleArray
// Purpose: Randomly shuffles the elements in the array.
// Parameters:
//   - arr: The array to shuffle.
//   - arrLength: The number of elements in the array.
void ShuffleArray(int arr[100], int arrLength)
{
    // Loop through each element of the array.
    // For each iteration, swap two randomly chosen elements.
    for (int i = 0; i < arrLength; i++)
    {
        // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
        // Subtract 1 to convert it to a valid 0-based index.
        int index1 = RandomNumber(1, arrLength) - 1;
        int index2 = RandomNumber(1, arrLength) - 1;
        // Swap the elements at the two randomly chosen indices.
        Swap(arr[index1], arr[index2]);
    }
}
void DrShuffleArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
}

void FillArrayWithOrderedNumbers(int arr[100], int& arrLength)
{

    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;

}
void ShuffleArray(int arr[100], int arrLength)
{
    int RandomI;
    for (short i = 0; i < arrLength; i++)
    {
        RandomI = RandomNumber(0, arrLength - 1);
        swap(arr[i], arr[RandomI]);
    }
}

void CopyReverseArray(int arr[100], int arr2[100], int arrLength)
{
    for (short i = 0; i < arrLength; i++)
    {
        arr2[i] = arr[arrLength - 1 - i];
    }
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case SmallLetter:
        return (char)RandomNumber(97, 122);
    case CapitalLetter:
        return (char)RandomNumber(65, 90);
    case SpecialChar:
        return (char)RandomNumber(33, 47);
    case Digit:
        return (char)RandomNumber(48, 57);
    default:
        return (char)RandomNumber(97, 122);
    }
}
string GenerateWord(enCharType CharType, short Length = 4)
{
    string word = "";
    for (short i = 0; i < Length; i++)
    {
        word += GetRandomCharacter(CharType);
    }
    return word;
}
string GenerateRandomKey(enCharType CharType, short Length = 4)
{
    string RandomKey = "";
    for (short i = 1; i < Length; i++)
    {
        RandomKey += GenerateWord(CharType) + '-';
    }
    return RandomKey += GenerateWord(CharType);
}
void FillArrayWithRandomKeys(string arr[100], int& arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = GenerateRandomKey(enCharType::CapitalLetter);
}


int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}


void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}
void PrintArray(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << "Array[" << i << "] : " << arr[i] << endl;

    cout << "\n";
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}
void FillArrayWithOrderedNumbers(int arr[100], int& arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}
void CopyReverseArray(int arr[100], int arr2[100], int arrLength)
{
    for (short i = 0; i < arrLength; i++)
    {
        arr2[i] = arr[arrLength - 1 - i];
    }
}
// Function: FindNumberPositionInArray
// Purpose: Searches for a given number in an array and returns its index if found,
//          or -1 if the number does not exist in the array.
// Parameters:
//   - Number: The number to search for.
//   - arr: The array in which to search.
//   - arrLength: The number of elements in the array.
// Returns: The index (0-based) of the number if found, or -1 if not found.
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    // Loop through each element in the array.
    for (int i = 0; i < arrLength; i++)
    {
        // Check if the current element equals the searched number.
        if (arr[i] == Number)
            return i; // Return the index immediately when the number is found.
    }

    // If the loop completes without finding the number, return -1.
    return -1;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    for (short i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

short GetIndexPositionInArray(int arr[100], int NumberToSearch, int arrLength)
{
    for (short i = 0; i < arrLength; i++)
    {
        if (arr[i] == NumberToSearch)
        {
            return i;
        }
    }
    return -1;
}
short GetIndexPositionInArray(int arr[100], int NumberToSearch, int arrLength, short arrIndex[100])
{ // لو الرقم مكرر
    short count = 0;
    for (short i = 0; i < arrLength; i++)
    {
        if (arr[i] == NumberToSearch)
        {
            arrIndex[count] = i;
            count++;
        }
    }
    if (count == 0) return -1;
    return count;
}


void PrintNumberPositionInArray(int arr[1000], int NumberToSearch, int arrLength, short arrIndex[1000])
{
    short IndexCount = GetIndexPositionInArray(arr, NumberToSearch, arrLength, arrIndex);
    cout << "\nNumber you are locking for is : " << NumberToSearch << endl;

    if (IndexCount != -1)
    {
        cout << "The number found at position  : ";
        for (short i = 0; i < IndexCount; i++)
        {
            cout << arrIndex[i];
            if (IndexCount != i + 1) cout << " and ";

        }
        cout << "\nThe number found order is     : ";
        for (short i = 0; i < IndexCount; i++)
        {
            cout << arrIndex[i] + 1;
            if (IndexCount != i + 1) cout << " and ";
        }
        if (IndexCount > 1)
            cout << "\nThe number founds [" << IndexCount << "] times. ";
        else cout << "\nThe number founds one time. ";
    }
    else
        cout << "The number is not found X﹏X " << endl;

}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    if (arrLength > 100)
    {
        cout << "\nWarning: Array capacity is 100 only. Adjusting length...\n";
        arrLength = 100;
    }

    for (short i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

short GetIndexPositionInArray(int arr[100], int NumberToSearch, int arrLength)
{
    for (short i = 0; i < arrLength; i++)
    {
        if (arr[i] == NumberToSearch)
        {
            return i;
        }
    }
    return -1;
}
short GetIndexPositionInArray(int arr[100], int NumberToSearch, int arrLength, short arrIndex[100])
{ // لو الرقم مكرر
    short count = 0;
    for (short i = 0; i < arrLength; i++)
    {
        if (arr[i] == NumberToSearch)
        {
            arrIndex[count] = i;
            count++;
        }
    }
    if (count == 0) return -1;
    return count;
}


void PrintNumberPositionInArray(int arr[1000], int NumberToSearch, int arrLength, short arrIndex[1000])
{
    short IndexCount = GetIndexPositionInArray(arr, NumberToSearch, arrLength, arrIndex);
    cout << "\nNumber you are locking for is : " << NumberToSearch << endl;

    if (IndexCount != -1)
    {
        cout << "The number found at position  : ";
        for (short i = 0; i < IndexCount; i++)
        {
            cout << arrIndex[i];
            if (IndexCount != i + 1) cout << " and ";

        }
        cout << "\nThe number found order is     : ";
        for (short i = 0; i < IndexCount; i++)
        {
            cout << arrIndex[i] + 1;
            if (IndexCount != i + 1) cout << " and ";
        }
        if (IndexCount > 1)
            cout << "\nThe number founds [" << IndexCount << "] times. ";
        else cout << "\nThe number founds one time. ";
    }
    else
        cout << "The number is not found X﹏X " << endl;

}


bool IsNumberInArray(int arr[1000], int NumberToSearch, int arrLength)
{
    for (short i = 0; i < arrLength; i++)
    {
        if (arr[i] == NumberToSearch) return 1;
    }
    return 0;
}

void CopyUniqueElements(int arr1Source[1000], int arr2Destination[1000], int arrLength, int& arr2DestinationLength)
{
    arr2DestinationLength = 0;
    for (short i = 0; i < arrLength; i++)
    {
        if (!IsNumberInArray(arr2Destination, arr1Source[i], arr2DestinationLength))
        {
            arr2Destination[arr2DestinationLength] = arr1Source[i];
            arr2DestinationLength++;
        }
    }

}
// Function: ReadNumber
// Purpose: Prompts the user to enter a number and returns the entered number.
// Returns: The number entered by the user.
int ReadNumber()
{
    int Number;  // Variable to store the user's input.
    cout << "\nPlease enter a number? ";
    cin >> Number;  // Read the number from the user.
    return Number;  // Return the entered number.
}

// Function: AddArrayElement
// Purpose: Adds a new element to the array.
// Parameters:
//   - Number: The number to add to the array.
//   - arr: The array to which the number will be added.
//   - arrLength: A reference to the variable tracking the number of elements in the array.
// Behavior: Increments the array length and stores the new element at the new last position.
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    // Since it's a new element, increase the array length by 1.
    arrLength++;
    // Store the new element at the index corresponding to the updated length (using zero-based indexing).
    arr[arrLength - 1] = Number;
}

// Function: InputUserNumbersInArray
// Purpose: Allows the user to input numbers into an array until they choose to stop.
// Parameters:
//   - arr: The array where user numbers will be stored.
//   - arrLength: A reference to the variable tracking the number of elements in the array.
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;  // Boolean flag to control whether more numbers will be added.

    // Continue looping as long as the user wants to add more numbers.
    do
    {
        // Read a number from the user and add it to the array.
        AddArrayElement(ReadNumber(), arr, arrLength);

        // Ask the user if they want to add more numbers.
        // Input 0 for No, 1 for Yes.
        cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
        cin >> AddMore;  // Read user's decision (true if 1, false if 0).

    } while (AddMore);  // Continue looping if the user inputs true.
}

// Function: PrintArray
// Purpose: Prints all the elements of an array separated by spaces.
// Parameters:
//   - arr: The array to print.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline at the end.
}
void AddArrayElement(int IndexNumber, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = IndexNumber; // كان ممكن أخلي قيمتها الأولية صفر بدون ما أنقص واحد ولكن ممكن أستخدم نفس الإجراء في إضافة على مصفوفة موجودةبالفعل
}
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    int IndexNumber = 0;
    char AddMore = '1';
    do
    {
        IndexNumber = ReadPositiveNumber("Enter a Number : ");
        AddArrayElement(IndexNumber, arr, arrLength);
        if (arrLength >= 100)
        {
            cout << "Array is full!";
            AddMore = '0';
            break;
        }
        do
        {

            cout << "Do you want to add more numbers? [0]:No, [1]:Yes >> ";
            cin >> AddMore;
            if (AddMore != '0' && AddMore != '1') cout << "\nEnter a valid choice..\n";
        } while (AddMore != '0' && AddMore != '1');

    } while (AddMore == '1');
}

void AddArrayElement(int IndexNumber, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = IndexNumber;
}

void CopyArrayUsingAddArrayElement(int arr[100], int arr2[100], int arrLength, int& arr2Length)
{
    arr2Length = 0;
    for (short i = 0; i < arrLength; i++)
    {
        AddArrayElement(arr[i], arr2, arr2Length);
    }

}
bool IsOdd(int Number) {
    return Number % 2 != 0;
}
void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
    arr2Length = 0;
    for (short i = 0; i < arrLength; i++)
    {
        if (IsOdd(arrSource[i]))
            AddArrayElement(arrSource[i], arrDestination, arr2Length);
    }

}
void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
{
    arr2Length = 0;
    for (short i = 0; i < arrLength; i++)
    {
        if (CheckPrimeNumbers(arrSource[i]) == enPrimeOrNot::Prime)
            AddArrayElement(arrSource[i], arrDestination, arr2Length);
    }

}
void FillArrayHardCoded(int arr[100], int& arrLength)
{
    arrLength = 10;

    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

void AddArrayElement(int IndexNumber, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = IndexNumber;
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        if (arr[i] == Number) return i;

    return -1;
}

bool IsNumberInArray(int arr[100], int NumberToSearch, int arrLength)
{
    return FindNumberPositionInArray(NumberToSearch, arr, arrLength);
    /* for (short i = 0; i < arrLength; i++)
     {
         if (arr[i] == NumberToSearch) return 1;
     }
     return 0;*/
}

void CopyDistinctNumbersToArray(int arr1Source[100], int arr2Destination[100], int arrLength, int& arr2DestinationLength)
{
    arr2DestinationLength = 0;
    for (short i = 0; i < arrLength; i++)
    {
        if (!IsNumberInArray(arr2Destination, arr1Source[i], arr2DestinationLength))
        {
            AddArrayElement(arr1Source[i], arr2Destination, arr2DestinationLength);
        }
    }

}
bool IsPalindromeArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength / 2; i++)
    {
        if (arr[i] != arr[(arrLength)-i - 1]) return false;
    }
    return true;
}
short CountEvenNumbers(int arrSource[100], int arrLength)
{
    short Count = 0;
    for (short i = 0; i < arrLength; i++)
    {
        if (!IsOdd(arrSource[i]))
            Count++;
    }
    return Count;
}
enum enOddOrEven { Odd = 1, Even = 2 };
short CountOddOrEvenNumbers(int arrSource[100], int arrLength, enOddOrEven OddOrEven)
{
    short Count = 0;
    for (short i = 0; i < arrLength; i++)
    {
        if (OddOrEven == enOddOrEven::Odd)
        {
            if (IsOdd(arrSource[i])) Count++;
        }
        else
        {
            if (!IsOdd(arrSource[i])) Count++;
        }
        /*
        // الحل باستخدام شرط مركب بسيط
        if ((OddOrEven == enOddOrEven::Odd && IsOdd(arrSource[i])) ||
            (OddOrEven == enOddOrEven::Even && !IsOdd(arrSource[i])))
        {
            Count++;
        }
        */
    }
    return Count;
}
short NumberCount(int arr[100], int arrLength, bool isPositive)
{
    short Count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        //if (arr[i] > 0) Count++; // 
        //if (!isPositive) return arrLength - Count; //  هنا ممكن تظهر مشكلة بسبب الرقم صفر فالصح إني أفصلهم أو أحسن الشرط
        if ((isPositive && arr[i] > 0) || (!isPositive && arr[i] < 0)) Count++;

    }
    return Count;
}

short PositiveNumberCount(int arr[100], int arrLength)
{
    short Count = 0;
    for (int i = 0; i < arrLength; i++)
        if (arr[i] > 0) Count++;
    return Count;
}

short NumbersCountNegativeOrPositive(int arr[100], int arrLength, bool isPositive)
{
    short Count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        //if (arr[i] > 0) Count++; // 
        //if (!isPositive) return arrLength - Count; //  هنا ممكن تظهر مشكلة بسبب الرقم صفر فالصح إني أفصلهم أو أحسن الشرط
        if ((isPositive && arr[i] > 0) || (!isPositive && arr[i] < 0)) Count++;

    }
    return Count;
}
short PositiveNumberCount(int arr[100], int arrLength)
{
    short Count = 0;
    for (int i = 0; i < arrLength; i++)
        if (arr[i] > 0) Count++;
    return Count;
}
short NumberCount(int arr[100], int arrLength, bool isPositive)
{
    short Count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        //if (arr[i] > 0) Count++; // 
        //if (!isPositive) return arrLength - Count; //  هنا ممكن تظهر مشكلة بسبب الرقم صفر فالصح إني أفصلهم أو أحسن الشرط
        if ((isPositive && arr[i] > 0) || (!isPositive && arr[i] < 0)) Count++;

    }
    return Count;
}
short PositiveNumberCount(int arr[100], int arrLength)
{
    short Count = 0;
    for (int i = 0; i < arrLength; i++)
        if (arr[i] > 0) Count++;
    return Count;
}
float ReadFloatNumber(string Message)
{
    float Number = 0;

    cout << Message;
    cin >> Number;

    return Number;
}

float MyABS(float Number)
{
    if (Number >= 0) return Number;
    return Number * -1;
}
int MyRound(float Number)
{
    int IntNumber = (int)Number;
    float fractionNumber = Number - IntNumber;

    if (abs(fractionNumber) >= 0.5)
        return (Number > 0) ? ++IntNumber : --IntNumber;

    else return IntNumber;
}
int MyRound2(float Number)
{
    return (Number > 0) ? Number + .5 : Number - .5;
}
int MyFloor(float Number)
{
    int IntNumber = (int)Number;

    if (IntNumber == (float)Number) return Number; // -7 = -7 مصريتنا وطنيتنا حمادة هلال
    return (Number > 0) ? IntNumber : --IntNumber; // لو الرقم السالب بدون كسر بيقل رقم
}

int MyCeil(float Number)
{
    int IntNumber = (int)Number;
    if (Number == IntNumber) return Number; // 5 = 5  مصريتنا وطنيتنا حمادة هلال
    return (Number > 0) ? ++IntNumber : IntNumber;
}
float MySqrt(float Number)
{
    /*  if (Number < 0) return -1;
      if (Number == 0) return 0;*/
    return pow(Number, 0.5);

}

}