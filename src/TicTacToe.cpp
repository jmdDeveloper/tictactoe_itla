#include "TicTacToe.h"
#include <cstdlib>
using namespace std;

char board[3][3]; //Possible values are X, O and _ (for blank positions)
char player = 'X';

bool isAvailable(int row, int column)
{

	bool available = false;
	//TODO: Implement this code so that it tells the user whether or not he can play in the selected cell
		if(board[row-1][column-1]=='X' || board[row-1][column-1]=='O')//if isn't available
		{
			available=false;
			
		}else{//if is available come here.
			available=true;
		}
	
	return available;
}

//Give initial values to the board matrix
void init()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			board[i][j] = '_';
		}
	}
}

void clearScreen()
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

bool validate(int number)
{
	if(number >= 1 && number <= 3)
	{
		return true;
	}else
	{
		cout << "Please pick a value between 1 and 3" << endl;
		return  false;
	}
}

bool gameover()
{
	bool over = false;
	int status= 1; // posible values 1:game in process, 2: gameover
	//TODO: Implement this method,verify if any player has won the match of it's being a tie.
	//Return true if the game is over. Print message informing the user about what just happened.
	
	//validation horizontal
	char firstPlayer = board[1][1];//aqui la inicializamos para no hacerlo en cada bucle principal
	   for(int f=0; f<3; f++){
	   	firstPlayer = board[f][0];
				for(int c=0; c<3; c++){
					
				       if(board[f][c]!='X' && board[f][c]!='O'){//if nobody have played 
						   status = 1; 
						   break; break;
						}
								
					    if(firstPlayer!=board[f][c]){// if the current player isn't the same that the last
				           status = 1;
						   break; break;   	         
				         } 
				        firstPlayer = board[f][c];
				                if(c==2){//game over.
				                	status = 2;
				                	cout<<"Game over you win."<<endl;
				                
				                } 	      
			   }			   
		}//end of validation horizntal
		
	//Validation vertical
		 for(int f=0; f<3; f++){
	   	firstPlayer = board[0][f];
				for(int c=0; c<3; c++){
					
				       if(board[c][f]!='X' && board[c][f]!='O'){//if nobody have played
						   status = 1; 
						   break; break;
						}
								
					    if(firstPlayer!=board[c][f]){// if the current player isn't the same that the last
				           status = 1;
						   break; break;   	         
				         } 
				        firstPlayer = board[c][f];
				                if(c==2){//game over
				                	status = 2;
				                	cout<<"Game over you win."<<endl;
				                	
				                } 	      
			   }			   
		}//cierre de validacion vertical
		
		//validation main diagonal 
		firstPlayer = board[0][0];//we inicialized the variable 'firstPlayer' 
				for(int x=0; x<3; x++){
					
				       if(board[x][x]!='X' && board[x][x]!='O'){//if nobody have played
						   status = 1; 
						   break; break;
						}
								
					    if(firstPlayer!=board[x][x]){// if the current player isn't the same that the last
				           status = 1;
						   break; break;   	         
				         } 
				        firstPlayer = board[x][x];
				                if(x==2){//game over.
				                	status = 2;
				                	cout<<"Game over you win."<<endl;

				                } 	      
		}//end of validation main diagonal.
		
		
		//validacion diagonal segundary
		firstPlayer = board[0][2];//we inicialized variable 'firstPlayer'      
			int f=1;
				for(int c=2; c>0 && f<3; c-- && f++){
							
						       if(board[f][c]!='X' && board[f][c]!='O'){//if nobody have played
								   status = 1; 
								   break; break;
								}
										
							    if(firstPlayer!=board[f][c]){// if the current player isn't the same that the last
						           status = 1;
								   break; break;   	         
						         } 
						        firstPlayer = board[f][c];
						                if(f==2 && c==0){//game over.
						                	status = 2;
						                	
						                } 	      
			}//end of validation of the secundary diagonal.	
				
	switch(status){
		case 1:// in proccess
			over = false;
			break;
		case 2: //game over
			over = true;
			break;
		default: over = false;
	}

	return over;
}

bool isValidInput(istream& in){
	if(in.fail())
	{
		cout <<"Only numbers are accepted" << endl;
	    in.clear();
	    in.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
	    return false;
	}else
	{
		return true;
	}
}

void showBoard()
{
	while(!gameover())
	{
		clearScreen();
		int row = 0;
		int column = 0;

		cout << "It's " << player << "'s turn" << endl;
		//printing column numbers
		cout << "\t";
		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
		}
		cout << endl;

		for(int i = 0 ; i < 3 ; i++)
		{
			cout << i + 1 << "\t";
			for(int j = 0 ; j < 3 ; j++)
			{
				cout << board[i][j] << "\t";
			}
			cout << endl;
		}
		do
		{
			cout << "In what row would you like to play? =>";
			cin >> row;
		}while(!isValidInput(cin) && !validate(row));
		do
		{
			cout << "In what column would you like to play? => ";
			cin >> column;
		}while(!isValidInput(cin) && !validate(column));

		if(isAvailable(row,column))
		{
			board[row - 1][column - 1] = player;
			player = player == 'X' ? 'O' : 'X';
		}else
		{
			cout << "The cell " << row << " , " << column << " is not available" << endl;
		}
	}
}
