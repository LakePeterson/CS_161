/******************************************************
 * ** Program: Program_2 (Adventure Text Game)
 * ** Author: Lake Peterson
 * ** Date: 10/07/2018
 * ** Description: Asks user for several inputs that will guide them down certain scenarios depenting on what
 * **              their inputs are.  
 * ** Input: Text
 * ** Output: Text
 * ******************************************************/

#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{

	char playAgain = 'Y';

	int sunRain = 0;

	/* Here I am just introducung the user to the program to give 
 	** them some insight on what is expected from them throughout
	** the program.
	*/	

	cout << "Hi, welcome to your local middle school text adventure game where you get to decide your journey throughout the adventure!" << endl;

	cout << endl;

	cout << "Throughout this adventure you will be given a series of choices that you get to choose from. In this weeks adventure you will ";
	cout << "be traveling through the jungle full of challenges and mystery..." << endl;

	cout << endl;

	/* This while loop encapsulates the entire program. I did 
	** it like this because it prompts the user if they would
	** would like to play again or quit, at the end of the game.
	*/

	while(playAgain == 'Y' || playAgain == 'y')
	{

		cout << "You have now started your journey through the jungle and notice that the sun is shining in one direction and rain clouds in the other direction." << endl;

		cout << endl;

		cout << "Enter a 1 to travel towards the sun. Enter a 2 to travel towards the rain clouds." << endl;
		
		cout << endl; 

		/* Here I am using "do while" loop to check the conditions
 		** of the users input. If the users input is not a 1 or a 2
		** than it will ask them to try again and remind that their original
		** input was not valid.
		*/

		do
		{		

			cin >> sunRain;

			if(sunRain != 1 && sunRain != 2)
			{

				cout << "Please enter a valid input." << endl;
				
				cout << endl;
			}

		}while(sunRain != 1 && sunRain != 2);

		cout << endl;
		
		/* Here I have nested if statements that are scenarios for the user.
                ** Besed on the users input they will be prompted with different scenarios,
                ** due to the nested if statements. 
                */

		if (sunRain == 1)
		{		

			int bugHome = 0;
			srand(time(NULL));
			int random = rand() % 2 + 1;

			cout << "You have chosen to walk towards the sun. You notice a cool looking bug ahead that you want to try and get a picture of, but its starting to get late.";

			cout << endl;

			cout << "Enter 1 take a picture of the bug. Enter a 2 to head back home." << endl;
			
			cout << endl;

			/* Here I am using "do while" loop to check the conditions
                 	** of the users input. If the users input is not a 1 or a 2
                        ** than it will ask them to try again and remind that their original
                        ** input was not valid.
                        */

			do
			{

				cin >> bugHome;

				if (bugHome != 1 && bugHome != 2) 
				{	

					cout << "Please enter a valid input." << endl;
					
					cout << endl;
				}

			}while(bugHome != 1 && bugHome != 2);

			cout << endl;
			
			if (bugHome == 1)
			{	

				cout << "You ended up taking a picture of the rarest bug in the world, and start you journey back home." << endl;
					
				cout << endl;

				if (random == 1)
				{

					cout << "Once you get home you find out that you picture of that rare bug is worth millions. Knowing that, you";
					cout << " sell your picture and become a millionaire!" << endl;
				
					cout << endl;

				}
				else 
				{

					cout << "On your way home you accidentally step in quicksand and lose your picture of the bug, you are eventually rescued out and";
					cout << " taken home." << endl;

					cout << endl;

				}

			}
			else
			{

				cout << "You decide to walk home after a long day walking, all while not having much to show for your day..." << endl;

				cout << endl;
			}	

		}
		else if (sunRain == 2)
		{

			int waterfallHome = 0;

			cout << "You have chosen to walk towards to rain clouds, and notice a sign up ahead that looks sort of like a waterfall. Do you " << endl;
			cout << "wish to investigate to see if it is a waterfall, or head home since it is getting late?" << endl;

			cout << endl;

			cout << "Enter a 1 to walk towards the waterfall. Enter a 2 to start walking home." << endl;	

			cout << endl;
			
			/* Here I am using "do while" loop to check the conditions
                        ** of the users input. If the users input is not a 1 or a 2
                        ** than it will ask them to try again and remind that their original
                        ** input was not valid.
                        */
			
			do
			{

				cin >> waterfallHome;

				if(waterfallHome != 1 && waterfallHome != 2)
				{

					cout << "Please enter a valid input." << endl;
					
					cout << endl;
				}
			
			/* Here I have nested if statements that are scenarios for the user.
			** Besed on the users input they will be prompted with different scenarios,
			** due to the nested if statements.
			*/
	
			}while(waterfallHome != 1 && waterfallHome != 2);

			cout << endl;

			if (waterfallHome == 1)
			{

				cout << "You start walking towards the sign and find the most beautiful waterfall that you have ever seen. As the sun starts to set you ";
				cout << "head home knowing you had a awesome day!" << endl;

				cout << endl;

			}
			else
			{

				cout << "You decide to walk home after a long day walking, all while not having much to show for your day..." << endl;

				cout << endl;

			}	
		}
		else
		{

			cout << "Please enter a valid input." << endl;

			cout << endl;

		}
		
		/* Here I ask the user if they would like to play again,
 		** if they say yes it doesn't break the original condition
		** and the while loop will continue. If the user puts any other 
		** character in the game will end as long as the initial condition is 
		** broke.
		*/
		
		cout << "Would you like to play the text adventure game again?" << endl;
		cout << "Enter a Y for yes or a N for no." << endl;

		cin >> playAgain;

	} 

cout << endl;

cout << "Thank you for playing!" << endl;

cout << endl; 

return 0;

}
