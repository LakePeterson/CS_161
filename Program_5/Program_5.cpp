/*****************************************************
 ** Author: Lake Peterson
 ** Date: 10/21/2018
 ** Description:
 ** Input:
 ** Output:
 ******************************************************/

#include <iostream>
#include <ctime>
#include <cmath>
#include <climits>
#include <cstdlib> 
#include <string>

using namespace std;

int valid(string);

void intro();

void rollDice(int*);

void askRoll(int*);

void keepDice(int*);

int topMath(int, int*);

int bottomMath(int*);

int smallStraight(int*);

int largeStraight(int*);

int fullHouse(int*);

int yahtzee(int*);

int chance(int*);

void scoringAlg(int*, int*);

void scoreSheet(int*);

int bonus(int*);

int total(int*);

void winner(int**, int);

int main(int argc, const char * argv[])
{
	srand(time(NULL));

	intro();

	int turns = 0;
	int dice[5];
	string validPlayers;
	int numPlayers;

	numPlayers = valid(argv[1]);

	int **players = new int*[numPlayers];

	for(int i = 0; i < numPlayers; i++)
	{
		players[i] = new int[14];

		for(int j = 0; j < 14; j++)
		{
			players[i][j] = -1;
		}
	}

	do{
		for(int i = 0; i < numPlayers; i++)
		{
			askRoll(dice);
			scoringAlg(players[i], dice);
			scoreSheet(players[i]);
			total(players[i]);
			turns++;
		}
	}while(turns != 13 * numPlayers);

	winner(players, numPlayers);

	for (int i = 0; i < numPlayers; i++)
	{
		delete [] players[i];
	}	
	delete [] players;

	return 0;
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
	return sum;
}

/********************************************************************
 * ** Function: intro
 * ** Description: Prints out the instruction of the game for the user.
 * ** Parameters: void
 * ** Pre-Conditions: Takes in predetermined text
 * ** Post-Conditions: Outputs text
 * ******************************************************************/

void intro()
{
	cout << endl;

	cout << "Welcome to the game of Yahtzee, the game consists of 13 rounds. In each round, you roll the dice and then score the " << endl;
	cout << "roll in one of 13 categories. You must score once in each category, which means that towards the end of the game you " << endl;
	cout << "may have to settle for scoring zero in some categories. The score is determined by a different rule for each category" << endl;
	cout << "in which the object of the game is to maximize your total score." << endl;

	cout << endl;

	cout << "Here are your dice to start the Yahtzee game!" << endl;

	cout << endl;
}

/********************************************************************
 * ** Function: rollDice
 * ** Description: Creates the initial 6 die for the game
 * ** Parameters: void
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs the dice values
 * ******************************************************************/

void rollDice(int* dice)
{
	for(int i = 0; i < 5; i++)
	{
		dice[i] = rand() % 6 + 1;

		cout << "Dice " << i + 1 << ": " << dice[i];

		cout << endl;
	}
	cout << endl;
}

/********************************************************************
 * ** Function: askRoll
 * ** Description: Asks user if they would like to reroll
 * ** Parameters: void
 * ** Pre-Conditions: Takes in predetermined user input
 * ** Post-Conditions: Outputs text
 * ******************************************************************/

void askRoll(int* dice)
{
	char rollAgain;
	int count = 0;

	rollDice(dice);

	while(count == 0 || count == 1)
	{

		cout << "Would you like to re-roll any of your dice?" << endl;
		cout << endl;
		cout << "Enter Y/y for YES or any other key to continue and score your dice." << endl;
		cout << "Remember you only have two opportunities to re-roll!" << endl;
		cin >> rollAgain;

		cout << endl;

		if(rollAgain == 'Y' || rollAgain == 'y')
		{
			keepDice(dice);
		}
		else if(rollAgain != 'y' || rollAgain != 'Y')
		{
			count = 2;
		}
		count++;
	}
}

/********************************************************************
 * ** Function: keepDice
 * ** Description: Allows user to re-roll values for selected die
 * ** Parameters: void
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs the dice values
 * ******************************************************************/

void keepDice(int* dice)
{
	int userInput;

	cout << "Enter 1 to re-roll or any other key to leave that die alone." << endl;

	cout << endl;

	for(int i = 0; i < 5; i++)
	{
		cout << "Would you like to re-roll dice " << i + 1 << ": ";
		cin >> userInput;

		if(userInput == 1)
		{
			dice[i] = rand() % 6 + 1;
		}
	}

	cout << endl;

	cout << "Here are your new dice!" << endl;

	cout << endl;

	for(int j = 0; j < 5; j++)
	{
		cout << "Dice " << j + 1 << ": " << dice[j];

		cout << endl;
	}
	cout << endl;
}

/********************************************************************
 * ** Function: topMath
 * ** Description: Sums the values in the array that the user selected
 * ** Parameters: int
 * ** Pre-Conditions: Takes in an integer and the dice values
 * ** Post-Conditions: Sums the desired values
 * ******************************************************************/

int topMath(int num, int* dice)
{
	int sum = 0;

	for(int i = 0; i < 5; i++)
	{
		if(dice[i] == num)
		{
			sum += dice[i];
		}
	}
	return sum;
}

/********************************************************************
 * ** Function: bottomMath
 * ** Description: Allocates a score depending on what predefined points
 * ** Parameters: int
 * ** Pre-Conditions: Takes in an integer and the dice values
 * ** Post-Conditions: Returns the desired score
 * ******************************************************************/

int bottomMath(int* dice)
{
	int count = 0;
	int sum = 0;

	for(int i = 1; i < 7; i++)
	{
		count = 0;

		for(int j = 0; j < 5; j++)
		{
			if(dice[j] == i)
			{
				count++;
			}
		}
		if(count >= 3)
		{
			sum = i * count;
			break;
		}
	}
	if(count == 3)
	{
		return sum;
	}
	else if(count == 4)
	{
		return sum;
	}
	else
	{
		return 0;
	}
}

/********************************************************************
 * ** Function: fullHouse
 * ** Description: Allows user allocate their points
 * ** Parameters: int
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs score to the scoresheet
 * ******************************************************************/

int fullHouse(int* dice)
{
	int count_low = 0;
	int count_high = 0;

	for(int i = 1; i < 7; i++)
	{
		count_high = 0;

		for(int j = 0; j < 5; j++)
		{
			if(dice[j] == i)
			{
				count_high++;
			}
		}
		if(count_high == 3)
		{
			break;
		}
	}
	for(int i = 1; i < 7; i++)
	{
		count_low = 0;

		for(int j = 0; j < 5; j++)
		{
			if(dice[j] == i)
			{
				count_low++;
			}
		}
		if(count_low == 2)
		{
			break;
		}
	}
	if(count_low == 2 && count_high == 3)
	{
		return 25;
	}
	else
	{
		return 0;
	}
}

/********************************************************************
 * ** Function: smallStraight
 * ** Description: Allows user allocate their points
 * ** Parameters: int
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs score to the scoresheet
 * ******************************************************************/

int smallStraight(int* dice)
{
	int tempArr[6] = {0};

	for(int i = 0; i < 5; i++)
	{
		if(dice[i] == 1)
		{
			tempArr[0] = 1;
		}
		else if(dice[i] == 2)
		{
			tempArr[1] = 1;
		}
		else if(dice[i] == 3)
		{
			tempArr[2] = 1;
		}
		else if(dice[i] == 4)
		{
			tempArr[3] = 1;
		}
		else if(dice[i] == 5)
		{
			tempArr[4] = 1;
		}
		else if(dice[i] == 6)
		{
			tempArr[5] = 1;
		}
	}
	if((tempArr[0] && tempArr[1] && tempArr[2] && tempArr[3]) || (tempArr[1] && tempArr[2] && tempArr[3] && tempArr[4]) || (tempArr[2] && tempArr[3] && tempArr[4] && tempArr[5]))
	{
		return 30;
	}
	else
	{
		return 0;
	}
}

/********************************************************************
 * ** Function: largeStraight
 * ** Description: Allows user allocate their points
 * ** Parameters: int
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs score to the scoresheet
 * ******************************************************************/

int largeStraight(int* dice)
{
	int tempArr[6] = {0};

	for(int i = 0; i < 5; i++)
	{
		if(dice[i] == 1)
		{
			tempArr[0] = 1;
		}
		else if(dice[i] == 2)
		{
			tempArr[1] = 1;
		}
		else if(dice[i] == 3)
		{
			tempArr[2] = 1;
		}
		else if(dice[i] == 4)
		{
			tempArr[3] = 1;
		}
		else if(dice[i] == 5)
		{
			tempArr[4] = 1;
		}
		else if(dice[i] == 6)
		{
			tempArr[5] = 1;
		}
	}
	if((tempArr[0] && tempArr[1] && tempArr[2] && tempArr[3] && tempArr[4]) || (tempArr[1] && tempArr[2] && tempArr[3] && tempArr[4] && tempArr[5]))
	{
		return 40;
	}
	else
	{
		return 0;
	}
}

/********************************************************************
 * ** Function: yahtzee
 * ** Description: Allows user allocate their points
 * ** Parameters: int
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs score to the scoresheet
 * ******************************************************************/

int yahtzee(int* dice)
{
	int count = 0;

	for(int i = 1; i < 7; i++)
	{
		count = 0;

		for(int j = 0; j < 5; j++)
		{
			if(dice[j] == i)
			{
				count++;
			}
		}
		if(count == 5)
		{
			break;
		}
	}
	if(count == 5)
	{
		return 50;
	}
	else
	{
		return 0;
	}
}

/********************************************************************
 * ** Function: chance
 * ** Description: Allows user allocate their points
 * ** Parameters: int
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs score to the scoresheet
 * ******************************************************************/

int chance(int* dice)
{
	int sum = 0;

	for(int i = 0; i < 5; i++)
	{
		sum += dice[i];
	}
	return sum;
}

/********************************************************************
 * ** Function: bonus
 * ** Description: Allows user allocate their points
 * ** Parameters: int
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs score to the scoresheet
 * ******************************************************************/

int bonus(int* score)
{
	int sum = 0;

	for(int i = 0; i < 6; i ++)
	{
		sum += score[i];
	}
	if(sum > 62)
	{
		return 35;
	}
	else
	{
		return 0;
	}
}

/********************************************************************
 * ** Function: scoringAlg
 * ** Description: Determines where to score their points
 * ** Parameters: void
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs to the scoresheet
 * ******************************************************************/

void scoringAlg(int* score, int* dice)
{
	int num;

	scoreSheet(score);

	cout << "Where category would you like to score your points in: ";
	cin >> num;

	cout << endl;

	if(num > 0 && num < 7 && score[num - 1] == -1)
	{
		score[num - 1] = topMath(num, dice);
	}
	else if(num > 6 && num < 9 && score[num-1] == -1)
	{
		score[num - 1] = bottomMath(dice);
	}
	else if(num > 8 && num < 10 && score[num-1] == -1)
	{
		score[num - 1] = smallStraight(dice);
	}
	else if(num > 9 && num < 11 && score[num-1] == -1)
	{
		score[num - 1] = largeStraight(dice);
	}
	else if(num > 10 && num < 12 && score[num-1] == -1)
	{
		score[num - 1] = fullHouse(dice);
	}
	else if(num > 11 && num < 13 && score[num-1] == -1)
	{
		score[num - 1] = yahtzee(dice);
	}
	else if(num > 12 && num < 14 && score[num-1] == -1)
	{
		score[num - 1] = chance(dice);
	}

}

/********************************************************************
 * ** Function: scoreSheet
 * ** Description: Allows user allocate their points
 * ** Parameters: void
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs the scoresheet
 * ******************************************************************/

void scoreSheet(int* score)
{
	score[13] = bonus(score);
	score[14] = total(score) + bonus(score);

	cout << "Here is your current scorecard:" << endl;

	cout << endl;

	cout << "1 - Ones: " << score[0] << endl;
	cout << "2 - Twos: " << score[1] << endl;
	cout << "3 - Threes: " << score[2] << endl;
	cout << "4 - Fours: " << score[3] << endl;
	cout << "5 - Fives: " << score[4] << endl;
	cout << "6 - Sixes: " << score[5] << endl;
	cout << "7 - 3 of a Kind: " << score[6] << endl;
	cout << "8 - 4 of a Kind: " << score[7] << endl;
	cout << "9 - Small Straight: " << score[8] << endl;
	cout << "10 - Large Straight: " << score[9] << endl;
	cout << "11 - Full House: " << score[10] << endl;
	cout << "12 - Yahtzee: " << score[11] << endl;
	cout << "13 - Chance: " << score[12] << endl;
	cout << "     Bonus: " << score[13] << endl;
	cout << "     Total: " << score[14] << endl;

	cout << endl;
}

/********************************************************************
 * ** Function: total
 * ** Description: Adds up the users total points
 * ** Parameters: int
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs the final score
 * ******************************************************************/

int total(int* score)
{
	int sum = 0;

	for(int i = 0; i < 13; i++)
	{
		if (score[i] != -1)
		{
			sum += score[i];
		}
	}
	return sum;
}

/********************************************************************
 * ** Function: winner
 * ** Description: dtermines the winner after game is complete.
 * ** Parameters: int
 * ** Pre-Conditions: None
 * ** Post-Conditions: Outputs the winner
 * ******************************************************************/

void winner(int** score, int numPlayers)
{

	int highest = 0;
	int index = 0;
	int sum = 0;

	for(int i = 0; i < numPlayers; i++)
	{
		sum = total(score[i]);

		if(sum > highest)
		{
			highest = sum;
			index = i;	
		}	
	}
	cout << "Player " << index + 1 << " wins the game!" << endl;
	cout << endl;
}
