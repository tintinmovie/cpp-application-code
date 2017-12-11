/*
________________________________________
|                                       |
|       game_EN.cpp                        | 
|                                        \
|       Google-code-in (2k17-18)          \
|                                          \
|                                           \
|       Game - Tic-Tac-Toe                   |
|                                            |	
`---------@@@@@-------------------@@@--------'

*/



#include "strings_EN.cpp"
#include <iostream>
using namespace std;



int is_winner(char );
void banner_ttt();
int authenticated_index(int );
void show_status_ttt();
void tic_tac_toe();



// Array storing the '0' or 'X' on positions entered by players
//
char a[9] = {'T','T','T','T','T','T','T','T','T'};			




int main()
{
	// calling the main block for Tic-Tac-Toe game 
	tic_tac_toe();		
}



// main block for Tic-Tac-Toe game
// Game starts from here, turn-wise game
void tic_tac_toe()
{
	int flag = 0, turn_counter = 1;
	int zero, cross;
	int continue_p2 = 0;


	banner_ttt();


		
		// Taking user-inputs until one of the 2 users win
		while(1)
		{

			// Checking if player2 has not triggered continue, 
			// if not, player1 has its turn
			//
			if ( continue_p2 != 1 )
			{
				cout<<"Player1 -> ";
				// User inputs the position which furthur is used to store '0' on that position in array
				cin>>zero;				


					// Checking if the index entered by user is a valid one or not
					if (( authenticated_index(zero-1)) )
					{	
						++turn_counter;				
						a[zero-1] = '0';				
						show_status_ttt();
						
							if (turn_counter > 4 && is_winner('0', a))	
							{
								cout<<"Congratulations!!\n";
								cout<<"Player 1 wins !\n";
								exit(0);
							}
					}
				
					else 
						continue;
					
			}
	
	

			cout<<"Player2 -> ";
			cin>>cross;

				// Checking if the index entered by user is a valid one or not
				if (authenticated_index(cross-1))
				{	
					
					++turn_counter;
					a[cross-1] = 'X';				
					show_status_ttt();
					continue_p2 = 0;					
	
						if (turn_counter > 4  && is_winner('X', a))
						{
							cout<<"Congratulations!!\n";
							cout<<"Player 2 wins !\n";
							exit(0);
						}
				}
			
				// if the index entered by the user in not valid
				// continue looping such that player2 has his turn
				else 
				{
					// setting up a 'continue_p2' flag so as to identify
					// player2 game the command to continue and that 
					// the turn continues with player2 and not player1
					continue_p2 = 1;
					continue;	
				}
	
		}

}



// Returns a non-zero number if the player calling the function wins 
// and returns 0 if the player calling the function has not won yet.
//
int is_winner(char ch, char array)
{
	// Code goes here
	//Note there are 8 ways to win a standard game of tic tac toe (3x3 board), which means the following code will look at all of these eight ways
	
	//HORIZONTAL CHECK
	//This line loop looks over the array looking for a win that is across the board (left to right, right to left)
	//Note it will break once i is greater than 6. This because once it reaches
	for (int i = 0; i < 6 ;i+=3)
	{
		//Checks whether a row has 3 consequetive chars that are the exact same, meaning the player won
		if (array[i] == ch && array[i+1] == ch && array[i+2] == ch)
		{
			//This returns 1, meaning the player (represented by ch) has won
			return 1;	
		}
	}
	
	//VERTICAL CHECK
	//Contains the amount of columns (which should be the same to the number of rows)
	int numberOfColumns = 3
	//Loops through the columns (i starts at 1 and increase by 1 each time) 
	//It will go through the top 3 chars in the array
	for (int i=0; i < 2;i++) 
	{
		//Looks at every third character trying to find a vertical column with all the same character
		if (array[i+numberOfColumns] == ch && array[i+numberOfColumns] == ch && array[i+numberOfColumns*2] == ch)
		{
			//A player has won!!!
			return 1;	
		}
	}
	
	//HORIZONTAL CHECK
	//Using just if statements as there are only two ways to win diagonally (ignoring order)
	//Temp value as there is no for loop
	int i = 0;
	//Looks in diagonal. Note. The +4 could be replaced by numberofcolums + 1, as they are in relation to each other
	if (array[0] == ch && array[4] == ch && array[8] == ch) 
	{
		//Player won
		return 1;
	}
	
	// Looks in the other diagonal way 
	else if (array[2] == ch && array[4] && array[6])
	{
		//Player won
	 	return 1;	
	}
	
	//If non of the returns ran that means the player hasn't won yet
	return 0;
		
}



// Checks if 
// 1. The 'position' entered by user is not the
// 	  one entered by any of the two users earlier.
// 2. The 'position' is not out of range of the
//    playing board.
// Returns 1 if position is valid otherwise 0.
//
int authenticated_index(int index)
{
	//Code goes here
	//Index is greater than the size of the array
	if (index > sizeof(a))
	{
		return 0;	
	}
	//The given index in the array, has a value other than 'T' - meaning a player has already entered that index before
	if (a[index] != 'T') 
	{
		//Returns zero, meaning that the player cannot place their 'piece' down
		return 0;	
	}
	
	else
	{
		return 1;;
	}	
	
	

}



// Shows the current status of the game 
// It is called each time a user has his turn.
void show_status_ttt()
{
	
	cout<<"\n";
	
	for( int i=0 ; i<9 ; ++i )
	{
		
		if (i != 0 && i%3 == 0 )
		{
			cout<<"\n";
			cout<<"___|___|___\n";
		}	
	
		cout<<" ";

		if ( a[i] == '0' || a[i] == 'X' )
			{
				cout<<(char )a[i]<<" ";
				if (i != 2 && i != 5 && i !=8)
					cout<<"|";
				
			}

			else 
			{
				cout<<"  ";
				if (i != 2 && i !=5 && i != 8)
					cout<<"|";
			}
	}

	cout<<"\n   |   |   \n";

	cout<<"\n";
}





