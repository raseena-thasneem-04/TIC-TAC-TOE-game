#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};  // intializing a character array (board) 
int row,column;
string player1,player2;
int box;
char turn='X';


void Board()
{
	
	 cout << "      |      |      \n";
    cout << board[0][0] <<   "     |    " <<  board[0][1]  << " |    " <<  board[0][2] <<"\n";
    cout << "      |      |    \n";
    cout<<"____________________" << "\n";
    cout << "      |      |      \n";
    cout << board[1][0] <<   "     |    " <<  board[1][1]  << " |    " <<  board[1][2] <<"\n";
    cout << "      |      |    \n";
    cout<<"____________________" << "\n";
    cout << "      |      |      \n";
    cout << board[2][0] <<   "     |    " <<  board[2][1]  << " |    " <<  board[2][2] <<"\n";
    cout << "      |      |    \n";
    cout<<"\n";
    cout<<"\n";
 
    
}


void input()
{
	
	cout<<"ENTER THE BOX NUMBER : "<<"\n";
	cin>>box;
	//fetting the box number where they want to enter x or o , this box number decides the row and columnn number
	if(box==1)
	{
		row=0;
		column=0;
	
	}
	else if(box==2)
	{
		row=0;
		column=1;
	
	}
	else if(box==3)
	{
		row=0;
		column=2;
	
	}
	else if(box==4)
	{
		row=1;
		column=0;
	
	}
	else if(box==5)
	{
		row=1;
		column=1;
	
	}
	else if(box==6)
	{
		row=1;
		column=2;
	
	}
	else if(box==7)
	{
		row=2;
		column=0;
	
	}
	else if(box==8)
	{
		row=2;
		column=1;
	
	}
	else if(box==9)
	{
		row=2;
		column=2;
	
	}
	else{
		cout<<"INVALID BOX!!!";
	}
	
	//checking for availability of the box before giving input 
	if(turn == 'X' && board[row][column]!='X' && board[row][column]!='O')
	{
		
			board[row][column]='X';
			turn = 'O';
	}
	else if(turn == 'O' && board[row][column]!='X' && board[row][column]!='X')
	{
		
			board[row][column]='O';
			turn = 'X';
		
	}
	//suppose the player entered a box number which was already filled , we are gonna call the function once again after throwing an already occupied message
	else{
		cout<<"BOX ALREADY OCCUPIED!!";
		input();
		
	}
	Board();
	//like this all the boxes will be filled
		
	
}

bool tie = false;

bool CheckWin()
{
	//horzontal and vertical checking 
	for(int i=0;i<3;i++)
	{
		if((board[i][0] == board[i][1] && board[i][1] == board[i][2] )|| (board[0][i] == board[1][i] && board[1][i] == board[2][i] ) )
		{
			return true;
		}
	}
	
	//diagonal checking
	if(board[0][0] == board[1][1] &&  board[1][1] == board[2][2] || board[2][0] == board[1][1] && board[1][1] == board[0][2] )
	{
		return true;
	}
}
	//checking if any empty places left in the board
	//this part of the code is executed only when there is no winner
bool CheckTie()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j] != 'X' && board[i][j] != 'O')
			{
				return false;
			}
		}
	}
	return true;	
}

string p1;
string p2;
int main()
{
	//Getting the details of the players
	cout<<"ENTER PLAYER 1 NAME :  "<<"\n";
	cin>>player1;
	p1 = player1;
	
	cout<<"ENETR PLAYER 2 NAME :  "<<"\n";
    cin>>player2;
    p2 = player2;
	cout<<"     PLAYER 1 TAKES     X    AND PLAYER 2 TAKES      O      "<<"\n";
	
	
	//run a while loop till one of the player wins
	while(!CheckWin() && !CheckTie())
	{
		 input();
		 
	}
	
	
	if(turn== 'X' && CheckWin() )
	{
		cout<<"PLAYER " << p2 << " WINS";
	}
	else if(turn == 'O' && CheckWin() )
	{
		cout<<"PLAYER " << p1 << " WINS";
	}
	else{
		cout<<"IT'S A TIE";
	}
}
