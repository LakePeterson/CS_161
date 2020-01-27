/******************************************************
 * ** Program: numbers.cpp
 * ** Author: Lake Peterson
 * ** Date: October 1, 2018
 * ** Description: Calculates maximum and  minimum signed and 
 * ** maximum and minimum unsigned number stored in n bytes
 * ** based on the users input. 
 * ** Input: None
 * ** Output: Text to Screen
 * ******************************************************/

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main()

{

	double user_input;

	cout << endl;

	/* Within this part of my program I am just giving the user default minimum and maximum
	 * memory values for int's, long's, and shorts so that they know the limits of each memory type.
	 */

	cout << "Here are the maximum and minimum values four unsigned and signed ints, longs, and shorts, by using literal numerical values that I have printed." << endl;

	cout << endl;

	cout << "Here are the maximum values:" << endl;

	cout << endl;

	cout << "Unsigned int: " << UINT_MAX << endl;
	cout << "Unsigned long: " << ULONG_MAX << endl;
	cout << "Unsigned long long: " << ULLONG_MAX << endl;
	cout << "Unsigned short: " << USHRT_MAX << endl;
	cout << "Signed int: " << INT_MAX << endl;
	cout << "Signed long: " << LONG_MAX << endl;
	cout << "Signed long long: " << LLONG_MAX << endl;
	cout << "Signed short: " << SHRT_MAX << endl;

	cout << endl;

	cout << "Here are the minimum values:" << endl;

	cout << endl;

	cout << "Unsigned int: " << "0" << endl;
	cout << "Unsigned long: " << "0" << endl;
	cout << "Unsigned long long: " << "0" << endl;
	cout << "Unsigned short: " << "0" << endl;
	cout << "Signed int: " << INT_MIN << endl;
	cout << "Signed long: " << LONG_MIN << endl;
	cout << "Signed long long: " << LLONG_MIN << endl;
	cout << "Signed short: " << SHRT_MIN << endl;

	cout << endl;

	/* Within this part of my program I am calculating the maximum and 
	 * minimum signed and maximum and minimum unsigned number stored in n bytes
	 * based on the users input.
	 */

	cout << "Now, I am going to calculate and print the maximum and minimum signed and maximum and minimum unsigned number stored in n bytes." << endl;

	cout << endl;

	/* I also used an if statement to set perameters, so that the user
	 * would not be able to use values outside the desired integers.
	 */

	cout << "Please choose an integer value between 0-8" << endl;
	cin >> user_input;

	if (user_input >= 0 && user_input <= 8)
	{
		unsigned long long int unsigned_min = 0;
		unsigned long long int unsigned_max = (long double)pow(2,8 * user_input) - 1;
		long long int signed_min = - (long double)pow(2,8 * user_input) / 2;
		long long int signed_max = (long double)pow(2,8 * user_input) / 2 - 1;

		cout << "Unsigned min: " << unsigned_min << endl;
		cout << "Unsigned max: " << unsigned_max << endl;
		cout << "Signed min: " << signed_min << endl;
		cout << "Signed max: " << signed_max << endl;

		cout << endl;

		cout << "Unsigned min: " << unsigned_min << endl;
		cout << "Unsigned max + 1: " << unsigned_max + 1 << endl;
		cout << "Signed min + 1: " << signed_min + 1 << endl;
		cout << "Signed max + 1: " << signed_max + 1 << endl;
	}
	else
	{
		cout << "Sorry that was not a valid entry." << endl;
	}

	return 0;
}
