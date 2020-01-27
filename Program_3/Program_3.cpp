/******************************************************
 ** Program: Program_3
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

using namespace std;

/*********************************************************************
 * ** Function: printInstructions
 * ** Description: Prints out the instruction of the game for the user.
 * ** Parameters: void
 * ** Pre-Conditions: Takes in predetermined text
 * ** Post-Conditions: Outputs text
 * ******************************************************************/

void printInstructions()
{

	cout << "Welcome to the elevator game where you will be trying to get to the top floor in order to get to the treasure chest!" << endl;

	cout << endl;

	cout << "You will be given different types of math problems, if you answer the problem correctly than you";
	cout << " will move up a floor, if you answer incorrectly you will stay on the same floor." << endl;

	cout << endl;

}

/*********************************************************************
 ** Function: valid
 ** Description: takes in a string and outputs an integer
 ** Parameters: int
 ** Pre-Conditions: Takes in a user input of any type
 ** Post-Conditions: Outputs an integer
 ** ***********************************************************/

int valid(string str)
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

	if(str[0] == '-')
	{

		number = number * -1;

	}

	return sum;
}

/*********************************************************************
 ** Function: printFloors
 ** Description: Prints out the floors 
 ** Parameters: void
 ** Pre-Conditions: Takes in inter values
 ** Post-Conditions: Outputs the amount of floors user has chosen and puts them on the bottom floor.
 ** *****************************************************************/

void printFloors(int currentPosition, int floors)
{

	int number;
	int sum = 0;
	int floorsInput;


	for(int i = floors; i >= 1; i--)
	{

		if(currentPosition == i)
		{

			cout << "|__X__|" << endl;

		}
		else
		{

			cout << "|_____|" << endl;

		}
	}
}

/*********************************************************************
 ** Function: displayEquation
 ** Description: Prints out the equation as well as internally does the math.
 ** Parameters: int
 ** Pre-Conditions: Takes in user input values
 ** Post-Conditions: Outputs integer.
 ** ******************************************************************/

int displayEquation(int problemType, int lowest, int highest)
{

	string userInput;
	int userAnswer;
	int answer;
	int x, A, B;
	int tempA, tempB;
	int newB;

	A = lowest;
	B = highest;

	switch(problemType)
	{

		case 1:

			if(abs(B) > abs(A))
			{

				/* Nothing needs to happen here,
				 *  ** only when A is greater than B, 
				 *   ** they will switch values.
				 *    */

			}
			else
			{

				tempA = A;
				A = B;
				B = tempA;

			}

			answer = (B - A);
			x = answer;

			cout << "You chose a addition problem!" << endl;

			cout << endl;

			cout << "Here is your problem:" << " X" << " + " << A << " = " << B << endl;
			cout << "What is X: ";
			getline(cin, userInput);

			cout << endl;

			userAnswer = valid(userInput);	

			if (userAnswer == answer)
			{

				return 1;

			}

			return 0;

			break;

		case 2:

			answer = (B + A);
			x = answer;

			cout << "You chose a subtraction problem!" << endl;

			cout << endl;

			cout << "Here is your problem:" << " X" << " - " << A << " = " << B << endl;
			cout << "What is X: ";
			getline(cin, userInput);

			cout << endl;

			userAnswer = valid(userInput);

			if (userAnswer == answer)
			{

				return 1;

			}

			return 0;

			break;

		case 3:

			if(abs(B) > abs(A))
			{

				/* Nothing needs to happen here,
				 * only when A is greater than B, 
				 * they will switch values.
				 */

			}
			else
			{

				tempA = A;
				A = B;
				B = tempA;

			}                                         

			answer = (B / A);
			x = answer;
			newB = x * A;

			cout << "You chose a multiplication problem!" << endl;

			cout << endl;

			cout << "Here is your problem:" << " X" << " * " << A << " = " << newB << endl;
			cout << "What is X: ";
			getline(cin, userInput);

			cout << endl;

			userAnswer = valid(userInput);

			if (userAnswer == answer)
			{

				return 1;

			}

			return 0;


			break;

		case 4:

			if(abs(A) > abs(B))
			{

				/* Nothing needs to happen here,
				 * only when A is greater than B, 
				 * they will switch values.
				 */

			}
			else
			{

				tempB = B;
				B = A;
				A = tempB;

			}                                         

			answer = B * A;
			x = answer; 

			cout << "You chose a division problem!" << endl;

			cout << endl;

			cout << "Here is your problem:" << " X" << " / " <<  A << " = " << B << endl;
			cout << "What is X: ";
			getline(cin, userInput);

			cout << endl;

			userAnswer = valid(userInput);

			if (userAnswer == answer)
			{

				return 1;

			}

			return 0;

			break;
	}
}

int main()
{

	char playAgain = 'Y';

	srand(time(NULL));

	printInstructions();

	while (playAgain == 'Y' || playAgain == 'y')
	{

		int currentPosition = 1;
		int randChoice;
		int tempA;
		int lowest, highest;
		int answer;
		int floors;	
		int difficulty;
		int problemType;	
		int userAnswer;
		string userInput;

		cout << "What difficulty would you like to play? Easy (1), Hard (2): ";

		do
		{

			string diffValid;

			getline(cin, diffValid);

			difficulty = valid(diffValid);

			if(difficulty != 1 && difficulty != 2)
			{


				cout << "Please enter a valid input." << endl;

			}

		}while(difficulty != 1 && difficulty != 2);

		cout << endl;

		cout << "How many floors are in your building: ";

		cout << endl;

		do
		{

			string floorsValid;

			getline(cin, floorsValid);

			floors = valid(floorsValid);

			if(floors <= 0 || floors >= 9)
			{

				cout << "Please enter a valid input." << endl;

			}

		}while(floors <= 0 || floors >= 9);

		printFloors(currentPosition, floors);

		cout << endl;

		do
		{

			if(difficulty == 1)
			{

				cout << "Would you like to solve an addition(1), subtraction(2), multiplication(3), or a division(4) problem." << endl;

				cout << endl;

				cout << "Addition(1)" << endl;
				cout << "Subtraction(2)" << endl;
				cout << "Multiplication(3)" << endl;
				cout << "Division(4)" << endl;

				cout << endl;

				cout << "Please enter the type of problem you want to solve, which is represented as an integer." << endl;

				do
				{

					string typeValid;				

					getline(cin, typeValid);

					problemType = valid(typeValid);

					if(problemType != 1 && problemType != 2 && problemType != 3 && problemType != 4)
					{

						cout << "Please enter a valid input." << endl;

					}

				}while(problemType != 1 && problemType != 2 && problemType != 3 && problemType != 4);

				cout << endl;

				lowest = rand() % 101;
				highest = rand() % 101;

				userAnswer = displayEquation(problemType, lowest, highest);

				if(userAnswer)
				{

					cout << "You are correct!" << endl;

					currentPosition++;

					if(currentPosition == floors)
					{

						cout << "You have reached the treasure chest!" << endl;

						cout << endl;

					}
					else
					{

						/* Nothing happens here because if the user 
						 *  ** gets the problem wrong then the compiler moves 
						 *   ** to the other else statement in the main if 
						 *    ** statement.
						 *     */ 

					}
				}
				else
				{

					cout << "You are incorrect!" << endl;

					if(currentPosition != 1)
					{

						currentPosition--;

					}
					else
					{

						/* Nothing happens here because if the user
						 *  ** is already on the first floor than we do not want to them to go down, 
						 *   ** instead they will be held on the first floor
						 *    */

					}
				}

				printFloors(currentPosition, floors);

				cout << endl;

			}
			else if(difficulty == 2)
			{

				cout << "You chose hard, you will now be given a random math problem to solve that is either addition, subtraction,"; 
				cout << " multiplication or division." << endl;

				cout << endl;

				int randChoice = rand() % 4 + 1;
				int A;
				int B;
				int userCorrect;
				string userInput;

				switch(randChoice)
				{

					case 1:

						int answerAdd;

						A = rand() % 201 + (-100);
						B = rand() % 201 + (-100);

						if(abs(B) > abs(A))
						{

							/* Nothing needs to happen here,
							 ** only when A is greater than B, 
							 ** they will switch values.
							 */

						}
						else
						{

							tempA = A;
							A = B;
							B = tempA;

						}

						answerAdd = (B - A);

						cout << "You were given an addition problem!" << endl;

						cout << endl;

						cout << "Here is your problem:" << " X" << " + " << A << " = " << B << endl;
						cout << "What is X: ";

						getline(cin, userInput);

						cout << endl;

						userAnswer = valid(userInput);

						if (userAnswer == answerAdd)
						{

							cout << "You are correct!" << endl;

							currentPosition++;

							if(currentPosition == floors)
							{

								cout << "You have reached the treasure chest!" << endl;

								cout << endl;

							}
							else
							{

								/* Nothing happens here because if the user 
								 ** gets the problem wrong then the compiler moves 
								 ** to the other else statement in the main if 
								 ** statement.
								 */

							}
						}
						else
						{

							cout << "You are incorrect!" << endl;

							if(currentPosition != 1)
							{

								currentPosition--;

							}
							else
							{

								/* Nothing happens here because if the user
								 ** is already on the first floor than we do not want to them to go down, 
								 ** instead they will be held on the first floor
								 */

							}
						}

						printFloors(currentPosition, floors);

						cout << endl;

						break;

					case 2:

						int answerSub;

						A = rand() % 201 + (-100);
						B = rand() % 101 + (-100);

						answerSub = (B + A);

						cout << "You were given a subtraction problem!" << endl;

						cout << endl;

						cout << "Here is your problem:" << " X" << " - " << A << " = " << B << endl;
						cout << "What is X: ";

						getline(cin, userInput);

						cout << endl;

						userAnswer = valid(userInput);

						if (userAnswer == answerSub)
						{

							cout << "You are correct!" << endl;

							currentPosition++;

							if(currentPosition == floors)
							{

								cout << "You have reached the treasure chest!" << endl;

								cout << endl;

							}
							else
							{

								/* Nothing happens here because if the user 
								 ** gets the problem wrong then the compiler moves 
								 ** to the other else statement in the main if 
								 ** statement.
								 */ 

							}
						}
						else
						{

							cout << "You are incorrect!" << endl;

							if(currentPosition != 1)
							{

								currentPosition--;

							}
							else
							{

								/* Nothing happens here because if the user
								 ** is already on the first floor than we do not want to them to go down, 
								 ** instead they will be held on the first floor
								 */

							}
						}

						printFloors(currentPosition, floors);

						cout << endl;

						break;

					case 3:

						int answerMul;
						int newB;
						int xSub;
						int xMul;

						A = rand() % 101;
						B = rand() % 101;

						if(abs(B) > abs(A))
						{

							/* Nothing needs to happen here,
							 ** only when A is greater than B, 
							 ** they will switch values.
							 */

						}
						else
						{

							tempA = A;
							A = B;
							B = tempA;

						}

						answerMul = (B / A);
						xMul = answerMul;
						newB = xMul * A;

						cout << "You chose a multiplication problem!" << endl;

						cout << endl;

						cout << "Here is your problem:" << " X" << " * " << A << " = " << newB << endl;
						cout << "What is X: ";

						getline(cin, userInput);

						cout << endl;

						userAnswer = valid(userInput);

						if (userAnswer == answerMul)
						{


							cout << "You are correct!" << endl;

							currentPosition++;

							if(currentPosition == floors)
							{

								cout << "You have reached the treasure chest!" << endl;

								cout << endl;

							}
							else
							{

								/* Nothing happens here because if the user 
								 ** gets the problem wrong then the compiler moves 
								 */ 

							}
						}
						else
						{

							cout << "You are incorrect!" << endl;

							if(currentPosition != 1)
							{

								currentPosition--;

							}
							else
							{

								/* Nothing happens here because if the user
								 ** is already on the first floor than we do not want to them to go down, 
								 ** instead they will be held on the first floor
								 */

							}
						}

						printFloors(currentPosition, floors);

						cout << endl;

						break;

					case 4:

						int answerDiv;
						int xDiv;
						int tempB;

						A = rand() % 201 + (-100);
						B = rand() % 201 + (-100);

						if(abs(A) > abs(B))
						{

							/* Nothing needs to happen here,
							 ** only when A is greater than B, 
							 ** they will switch values.
							 */

						}
						else
						{

							tempB = B;
							B = A;
							A = tempB;

						}

						answerDiv = B * A;
						xDiv = answerDiv;

						cout << "You chose a division problem!" << endl;

						cout << endl;

						cout << "Here is your problem:" << " X" << " / " <<  A << " = " << B << endl;
						cout << "What is X: ";

						getline(cin, userInput);

						cout << endl;

						userAnswer = valid(userInput);

						cout << userAnswer << "        " << answerDiv << endl; 



						if (userAnswer == answerDiv)					
						{


							cout << "You are correct!" << endl;

							currentPosition++;

							if(currentPosition == floors)
							{

								cout << "You have reached the treasure chest!" << endl;

								cout << endl;							

							}
							else
							{

								/* Nothing happens here because if the user 
								 ** gets the problem wrong then the compiler moves 
								 ** to the other else statement in the main if 
								 ** statement.
								 */ 

							}
						}
						else
						{

							cout << "You are incorrect!" << endl;

							if(currentPosition != 1)
							{

								currentPosition--;

							}
							else
							{

								/* Nothing happens here because if the user
								 ** is already on the first floor than we do not want to them to go down, 
								 ** instead they will be held on the first floor
								 */

							}
						}

						printFloors(currentPosition, floors);

						cout << endl;

						break;

				}


			}

		}while(currentPosition != floors);

		cout << "Would you like to play again" << endl;

		cout << endl;

		cout << "Enter Y/y for YES or N/n for no." << endl;
		cin >> playAgain;

	}

	return 0;
}
