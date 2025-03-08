#include<iostream>
using namespace std;
void board(int n,char arr[100][100])
{
	int t = 1;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
		for (int j = 0; j < n; j++)
		{
			if (j < n - 1)
			{
					cout <<" " << arr[i][j]<<" |";
			}
			else if (j = n - 1) 
			{
				cout << " " << arr[i][j];
			}
		}
		cout << endl;
		if (i < n - 1)
		{
			cout <<  "\t";
			for (int j = 0; j < n; j++) 
			{
				cout << "--- ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
int input()
{
	char c;
	cout << "What you want to choose Player 1 (O or X) = ";
	cin >> c;
	for (int i = 0; c != 'x' && c != 'X' && c != 'o' && c != 'O';i++)
	{
		if (c != 'x' || c != 'X' || c != 'o' || c != 'O')
		{
			cout << "You entered an illegal Symbol." << endl << "Enter again = " << endl;
			cin >> c;
		}
	}
	return c;
}
void coordinates(char arr[100][100],int &a,int &b)
{
	cin >> a >> b;
	if (arr[a][b] != ' ') 
	{
		cout << "Enter another box = " << endl;
		coordinates(arr, a, b);
	}
}
bool condition(char arr[100][100], int n)
{
	int X, Y;
	for (int i = 0; i < n; i++)
	{
		X = 0;
		Y = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'X')
				X++;
			else if (arr[i][j] == 'O')
				Y++;
		}
		if (X == n || Y == n)
			return true;
	}
	for (int j = 0; j < n; j++)
	{
		X = 0;
		Y = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][j] == 'X')
				X++;
			else if (arr[i][j] == 'O')
				Y++;
		}
		if (X == n || Y == n)
			return true;
	}
	{
		 X = 0;
		 Y = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][i] == 'X')
				X++;
			else if (arr[i][i] == 'O')
				Y++;
		}
		if (X == n || Y == n)
			return true;
	}
	
	{
		X = 0;
		Y = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][n - 1 - i] == 'X')
				X++;
			else if (arr[i][n - 1 - i] == 'O')
				Y++;
		}
		if (X == n || Y == n)
			return true;
	}

	return false;
}
bool draw(char arr[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == ' ')
				return false; 
		}
	}
	return true; 
}
int main()
{
	int n, a, b;
	char p1, p2;
	char arr[100][100], c;
	bool again = true;
	while(again)
	{
		cout << "Enter the size of the table of tic tac toe (3 or greater than 3) = " << endl;
		cin >> n;
		for (int i = 0; n <= 2; i++)
		{
			if (n <= 2)
			{
				cout << "Wrong value. Enter again = " << endl;
				cin >> n;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = ' ';
			}
		}
		board(n, arr);
		c = input();
		if (c == 'O' || c == 'o')
		{
			cout << "Player 2, You are playing with X " << endl;
			p1 = 'O';
			p2 = 'X';
		}
		else if (c == 'X' || c == 'x')
		{
			cout << "Player 2 You are playing with O " << endl;
			p1 = 'X';
			p2 = 'O';
		}
		for (int i = 0; i < n * n; i++)
		{
			if (i % 2 == 0)
			{
				cout << "Player 1 enter the coordinates eg(0 1) to mark a box to put " << p1 << " = " << endl;
				coordinates(arr, a, b);
				arr[a][b] = p1;
				system("CLS");
				board(n, arr);
				if (condition(arr, n))
				{
					cout << "Congratulations Players 1. You won !!!" << endl;
					break;
				}
				else if (draw(arr, n))
				{
					cout << "The game ends in a draw"<<endl;
					break;
				}
			}
			else
			{
				cout << "Player 2 enter the coordinates eg(0 1) to mark a box to put " << p2 << " = " << endl;
				coordinates(arr, a, b);
				arr[a][b] = p2;
				system("CLS");
				board(n, arr);
				if (condition(arr, n))
				{
					cout << "Congratulations Players 2. You won !!!"<<endl;
					break;
				}
				else if (draw(arr, n))
				{
					cout << "The game ends in a draw" << endl;
					break;
				}
			}
		}
		cout << "Do you want to play again? (1 for yes, 0 for no) = " << endl;
		cin >> again;
	}
	return 0;
}