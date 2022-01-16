#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// function prototypes
int validateUserInput(int & userInput);
string returnRomanThousandsPlace(int & romanNum1K);
string returnRomanHundredsPlace(int & romanNum100);
string returnRomanTensPlace(int & romanNum10);
string returnRomanOnesPlace(int & romanNum10);
char restartInput(char ans);

int main ()
{
    // restart beginning
    bool restart = true;
    while (restart == true)
    {
        system ("cls");

        // variables
        char ans;
        int userInput = 0;
        int romanNum1K = 0;

        // body
        cout << "This program will accept a year written in four digit ordinary numeral and will convert it into roman numerals." << endl;
        cout << endl;
        cout << "Enter a year between 1000 and 3000:" << endl;
        cin >> userInput;
        cout << endl;

        validateUserInput(userInput);

        cout << "Your number in roman numerals is: ";
        cout << returnRomanThousandsPlace(userInput);
        cout << returnRomanHundredsPlace(userInput);
        cout << returnRomanTensPlace(userInput);
        cout << returnRomanOnesPlace(userInput);
        cout << endl;
        cout << endl;

        // restart program
        restart = restartInput(ans);
    }
    return 0;
}

// functions
// user input validation
int validateUserInput(int & userInput)
{
    while (cin.fail() || (userInput < 1000 || userInput > 3000))
    {
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "The year entered is invalid. Enter a valid year between 1000 to 3000:" << endl;
            cin >> userInput;
        }
        while (userInput < 1000 || userInput > 3000)
        {
            cout << "The year entered is invalid. Enter a valid year between 1000 to 3000:" << endl;
            cin >> userInput;
        }
    }
    return userInput;
}

// roman numeral for 1000s
string returnRomanThousandsPlace(int & romanNum1K)
{
    // variables
    string romanNum;

    // body
    for (int i = 0; i < romanNum1K / 1000; i++)
    {
        romanNum = romanNum + "M";
    }
    return romanNum;
}

// roman numeral for 100s
string returnRomanHundredsPlace(int & romanNum100)
{
    // variables
    string romanNum;
    int numCalc = romanNum100 / 100 % 10;

    // body
    if (numCalc == 9)
    {
        romanNum = "CM";
    }
    else if (numCalc > 4)
    {
        for (int i = 5; i < numCalc; i++)
        {
            romanNum = romanNum + "C";
        }
        romanNum = "D" + romanNum;
    }
    else if (numCalc == 4)
    {
        romanNum = "CD";
    }
    else
    {
        for (int i = 0; i < numCalc; i++)
        {
            romanNum = romanNum + "C";
        }
    }
    return romanNum;
}

// roman numeral for 10s
string returnRomanTensPlace(int & romanNum10)
{
    // variables
    string romanNum;
    int numCalc = romanNum10 / 10 % 10;

    // body
    if (numCalc == 9)
    {
        romanNum = "XC";
    }
    else if (numCalc > 4)
    {
        for (int i = 5; i < numCalc; i++)
        {
            romanNum = romanNum + "X";
        }
        romanNum = "L" + romanNum;
    }
    else if (numCalc == 4)
    {
        romanNum = "XL";
    }
    else
    {
        for (int i = 0; i < numCalc; i++)
        {
            romanNum = romanNum + "X";
        }
    }
    return romanNum;
}

// roman numeral for 1s
string returnRomanOnesPlace(int & romanNum1)
{
    // variables
    string romanNum;
    int numCalc = romanNum1 % 10;

    // body
    if (numCalc == 9)
    {
        romanNum = "IX";
    }
    else if (numCalc > 4)
    {
        for (int i = 5; i < numCalc; i++)
        {
            romanNum = romanNum + "I";
        }
        romanNum = "V" + romanNum;
    }
    else if (numCalc == 4)
    {
        romanNum = "IV";
    }
    else
    {
        for (int i = 0; i < numCalc; i++)
        {
            romanNum = romanNum + "I";
        }
    }
    return romanNum;
}

// restart function
char restartInput(char ans)
{
    // variables
    bool restart;

    // body
    cout << "Do you want to repeat this program?" << endl;
    cout << "Y/N" << endl;
    cin >> ans;
    ans = static_cast<char>(toupper(ans));
    while (ans != 'Y' && ans != 'N')
    {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Do you want to repeat this program?" << endl;
        cout << "Y/N" << endl;
        cin >> ans;
        ans = static_cast<char>(toupper(ans));
    }
    if (ans == 'Y')
    {
        restart = true;
    }
    else
    {
        restart = false;
    }
    return restart;
}
