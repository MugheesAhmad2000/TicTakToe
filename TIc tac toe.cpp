#include<iostream>
using namespace std;

void printboard(int board[][3],int r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
			if(board[i][j]==0)
				cout << "_ ";
			else if(board[i][j] == 1)
				cout << "0 ";
			else
				cout << "X ";
		cout << endl;
	}
}

bool checkwinner(int board[][3], int r, int& who)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0)
		{
			who = board[i][0];
			return true;
		}
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0)
		{
			who = board[0][i];
			return true;
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
	{
		who = board[0][0];
		return true;
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != 0)
	{
		who = board[0][2];
		return true;
	}
	return false;
}

void calcposition(int board[][3], int opp, int& r, int& c)
{
	int who,winner;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j]==0)
			{
				r = i;
				c = j;
				board[i][j] = 2;
				winner=checkwinner(board,3,who);
				board[i][j] = 0;
				if (winner == true)
					return;
			}
	if (board[1][1] == 0)
	{
		r=1;
		c=1;
	}
}

int main()
{
	int board[3][3] = { 0 };
	int player = 1,r,c,who;
	bool winner = false;
	printboard(board,3);
	for (int i = 0; i < 9 && winner == false; i++)
	{
		if (player == 1)
		{
			calcposition(board, 2, r, c);
			board[r][c] = 1;
			/*cout << "\nEnter coordinates\n";
			cin >> r >> c;
			while(board[r][c] != 0)
			{
				cout << "\nTAKEN Re Enter\n";
				cin >> r >> c;
			}
			board[r][c] = 1;*/

			player = 2;
		}
		else
		{
			cout << "\nEnter coordinates\n";
			cin >> r >> c;
			while (board[r][c] != 0)
			{
				cout << "\nTAKEN Re Enter\n";
				cin >> r >> c;
			}
			board[r][c] = 2;
			player = 1;
		}
		system("cls");
		printboard(board, 3);
		winner = checkwinner(board, 3, who);
	}
	if(winner==true)
		cout << "Winner is player: " << who<<endl;

	system("pause");
	return 0;
}