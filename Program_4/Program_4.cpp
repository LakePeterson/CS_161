/****************************************************
 ** Author: Lake Peterson
 ** Date: 10/21/2018
 ** Description:  
 ** Input:
 ** Output:
 ******************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib> 
#include <cmath>
#include <string>
#include <climits>
#include <bitset>

using namespace std;

int validInput(string str);

void printIntro();

int binaryToDecimal(string binaryVal);

float gradeAverage(int gEntries);

float weightedGradeAverage(int wEntries);

int main()
{

	char playAgain = 'Y';

	printIntro();

	while(playAgain == 'y' || playAgain == 'Y')
	{

		int calcType;
		string btodInput;
		int btodAnswer;
		string dtobInput;
		int gEntries;
		int wEntries;
		float gAverage;
		float wAverage;
		int xTemp;

		do
		{

			string inputType;

			getline(cin, inputType);

			calcType = validInput(inputType);

			if(calcType != 1 && calcType != 2 && calcType != 3 && calcType != 4 && calcType != 5)
			{

				cout << "Please input an integer that correctly represents the calculation type that you want." << endl;

			}

		}while(calcType != 1 && calcType != 2 && calcType != 3 && calcType != 4 && calcType != 5);

		switch(calcType)
		{

			case 1:{

				       return 0;

			       }break;

			case 2:{

				       cout << "You chose to do a binary to decimal conversion! Please enter a binary value and I will convert it!" << endl; 

				       getline(cin, btodInput);

				       btodAnswer = binaryToDecimal(btodInput);

				       cout << btodAnswer << endl;

			       }break;

			case 3:{

				       cout << "You chose to do a decimal to binary conversion! Please enter a decimal value and I will convert it!" << endl;

				       cin >> dtobInput;

				       xTemp = stoi(dtobInput);	

				       bitset<16> dtobAnswer(xTemp);

				       cout << dtobAnswer << endl;

			       }break;

			case 4:{

				       cout << "You chose to use my average grade calculator! Please enter how many grade entries you would like to make." << endl;

				       cin >> gEntries;

				       gAverage = gradeAverage(gEntries);

				       cout << "The average score of your grades was: " << gAverage << endl;

			       }break;

			case 5:{

				       cout << "You chose to use my weighted grade calculator! Please enter how many grade entries you would like to make." << endl;

				       cin >> wEntries;

				       wAverage = weightedGradeAverage(wEntries);

				       cout << "Your average weighted score was: " << wAverage << endl;

			       }break;

		}

		cout << "Would you like to make another calculation? Enter Y/y for yes or pressany other key to exit the calculator." << endl;

		cin >> playAgain;

	}

	return 0;

}

/********************************************************************
 ** Function: validInput
 ** Description: takes in a string and outputs an integer
 ** Parameters: int
 ** Pre-Conditions: Takes in a user input of any type
 ** Post-Conditions: Outputs an integer
 ** *****************************************************************/

int validInput(string str)
{

	int number;
	int sum = 0;

	for(int i = 0; i < str.length(); i++)
	{

		number = str[i];

		number -= 48;

		if(number < 0 || number > 9)
		{

			return INT_MAX;

		}

		sum += number * pow(10, str.length() - 1 - i);

	}

	return sum;

}

/*********************************************************************
 ** Function: printIntro
 ** Description: Prints out the instruction of the game for the user.
 ** Parameters: void
 ** Pre-Conditions: Takes in predetermined text
 ** Post-Conditions: Outputs text
 ** ******************************************************************/

void printIntro()
{

	cout << "Welcome to my calculator program you will be able to make standard calculation (+, -, *, /), a "; 
	cout <<	"binary to decimal conversion, decimal to binary conversion and a grade calculator for average and weighted grades." << endl;

	cout << endl;

	cout << "What type of calculation would you like to make?" << endl;

	cout << endl;

	cout << "(1) Standard Calculation" << endl;
	cout << "(2) Binary to Decimal Calculation" << endl;
	cout << "(3) Decimal to Binary Calculation" << endl;
	cout << "(4) Average Grade Calculator" << endl;
	cout << "(5) Weighted Grade Calculator" << endl;

	cout << endl;

	cout << "Please use a number associated with the calculation type." << endl;
}

/*********************************************************************
 ** Function: binaryToDecimal
 ** Description: Converts a binary value into a decimal value.
 ** Parameters: int
 ** Pre-Conditions: Takes in a BINARY value (string)
 ** Post-Conditions: Outputs a DECIMAL value (int)
 ** ******************************************************************/

int binaryToDecimal(string binaryVal)
{
	int decimalVal = 0;
	int multi = 1;

	for(int i = binaryVal.length() - 1; i >= 0; i--)
	{

		int parse = binaryVal[i];

		if(parse == '1')

			decimalVal = decimalVal + multi;
		multi = 2 * multi; 

	}

	return decimalVal;

}

/**********************************************************************
 ** Function: gradeAverage
 ** Description: Takes in grade entries and averages them.
 ** Parameters: int
 ** Pre-Conditions: Takes in a how many entries (int)
 ** Post-Conditions: Outputs the average (int)
 ** ******************************************************************/

float gradeAverage(int gEntries)
{

	float average;
	float sum;

	string userInput;

	for(int i = 0; i < gEntries; i++)
	{

		cout << "Please enter grade " << i + 1 << ": ";

		cin >> userInput;

		cout << endl;

		sum += stof(userInput);

	}

	average = sum / (float)gEntries;

	return average;

}

/**********************************************************************
 ** Function: weightedGradeAverage
 ** Description: Takes in grade entries and weights ----> averages them.
 ** Parameters: int
 ** Pre-Conditions: Takes in a how many entries (int)
 ** Post-Conditions: Outputs the average (int)
 ** ******************************************************************/

float weightedGradeAverage(int wEntries)
{

	float average;
	float grade;
	float weight;
	float temp = 0;
	string gradeInput;
	string weightInput;

	for(int i = 0; i < wEntries; i++)
	{

		cout << "Please enter grade " << i + 1 << ": ";

		cin >> gradeInput; 

		cout << "Please enter the weight " << i + 1 << ": ";		

		cin >> weightInput;

		grade = stof(gradeInput) / 100;

		weight = stof(weightInput) / 100;

		temp += grade * weight;

	}

	average = temp * 100;

	return average;

}
