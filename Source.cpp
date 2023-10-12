#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

void reveal(int x, int y, char main[30][30], char arr[30][30])
{
	arr[x][y] = main[x][y];
	if ((main[x][y - 1] == '0') && x >= 0 && x < 30 && (y - 1) >= 0 && (y - 1) < 30)
	{
		if (arr[x][y - 1] != '0')
		{
			reveal(x, y - 1, main, arr);
		}
	}
	if ((main[x][y + 1] == '0') && x >= 0 && x < 30 && (y + 1) >= 0 && (y + 1) < 30)
	{
		if (arr[x][y + 1] != '0')
		{
			reveal(x, y + 1, main, arr);
		}
	}
	if ((main[x - 1][y] == '0') && (x - 1) >= 0 && (x - 1) < 30 && y >= 0 && y < 30)
	{
		if (arr[x - 1][y] != '0')
		{
			reveal(x - 1, y, main, arr);
		}
	}
	if ((main[x + 1][y] == '0') && (x + 1) >= 0 && (x + 1) < 30 && y >= 0 && y < 30)
	{
		if (arr[x + 1][y] != '0')
		{
			reveal(x + 1, y, main, arr);
		}
	}
	return;
}

void setColor(int textColor, int backColor = 7)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = backColor << 4 | textColor;
	SetConsoleTextAttribute(consoleHandle, colorAttribute);
}

int main()
{
	system("color 70");
	int ans1, ans2 = 1, ans3;
	do
	{
		ans1 = 1;
		char main[30][30], arr[30][30];
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				arr[i][j] = '*';
			}
		}
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				main[i][j] = '0';
			}
		}
		srand(time(0));
		for (int k = 0; k < 20; k++)
		{
			int i = rand() % 29 + 0;
			int j = rand() % 29 + 0;
			main[i][j] = 'B';
		}
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (main[i][j] != 'B')
				{
					int I = i, J = j, count = 0;
					J--;
					if (I >= 0 && I < 30 && J >= 0 && J < 30)
					{
						if (main[I][J] == 'B')
						{
							count++;
						}
					}
					I--;
					if (I >= 0 && I < 30 && J >= 0 && J < 30)
					{
						if (main[I][J] == 'B')
						{
							count++;
						}
					}
					J++;
					if (I >= 0 && I < 30 && J >= 0 && J < 30)
					{
						if (main[I][J] == 'B')
						{
							count++;
						}
					}
					J++;
					if (I >= 0 && I < 30 && J >= 0 && J < 30)
					{
						if (main[I][J] == 'B')
						{
							count++;
						}
					}
					I++;
					if (I >= 0 && I < 30 && J >= 0 && J < 30)
					{
						if (main[I][J] == 'B')
						{
							count++;
						}
					}
					I++;
					if (I >= 0 && I < 30 && J >= 0 && J < 30)
					{
						if (main[I][J] == 'B')
						{
							count++;
						}
					}
					J--;
					if (I >= 0 && I < 30 && J >= 0 && J < 30)
					{
						if (main[I][J] == 'B')
						{
							count++;
						}
					}
					J--;
					if (I >= 0 && I < 30 && J >= 0 && J < 30)
					{
						if (main[I][J] == 'B')
						{
							count++;
						}
					}
					if (count != 0)
					{
						for (int k = 0; k < count; k++)
						{
							main[i][j]++;
						}
					}
				}
			}
		}
		/*cout << '\n' << '\n' << '\n';
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				cout << "  " << main[i][j];
			}
			cout << '\n';
		}*/
		do
		{
			system("cls");
			int count = 0;
			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					if (arr[i][j] == '*')
					{
						count++;
					}
				}
			}
			if (count == 20)
			{
				ans1 = 0;
				cout << '\n' << '\n';
				setColor(0, 7);
				cout << "  " << "You Won!" << '\n' << '\n';
				for (int i = 0; i < 30; i++)
				{
					for (int j = 0; j < 30; j++)
					{
						switch (main[i][j])
						{
						case 'B':
							setColor(4, 7);
							cout << "  " << main[i][j];
							break;
						case '0':
							setColor(8, 7);
							cout << "  " << main[i][j];
							break;
						case '1':
							setColor(1, 7);
							cout << "  " << main[i][j];
							break;
						case '2':
							setColor(2, 7);
							cout << "  " << main[i][j];
							break;
						default:
							setColor(5, 7);
							cout << "  " << main[i][j];
						}
						//cout << "  " << main[i][j];
					}
					cout << '\n';
				}
				setColor(0, 7);
				cout << '\n' << "  " << "You wish to play again? If you do press 1 : ";
				char ans;
				cin >> ans;
				if (ans != '1')
				{
					ans2 = 0;
				}
				continue;
			}
			cout << '\n' << '\n' << '\n' << '\n';
			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < 30; j++)
				{
					switch (arr[i][j])
					{
					case '*':
						setColor(0, 7);
						cout << "  " << arr[i][j];
						break;
					case 'B':
						setColor(4, 7);
						cout << "  " << arr[i][j];
						break;
					case '0':
						setColor(8, 7);
						cout << "  " << arr[i][j];
						break;
					case '1':
						setColor(1, 7);
						cout << "  " << arr[i][j];
						break;
					case '2':
						setColor(2, 7);
						cout << "  " << arr[i][j];
						break;
					case '^':
						setColor(6, 7);
						cout << "  " << arr[i][j];
						break;
					default:
						setColor(5, 7);
						cout << "  " << arr[i][j];
					}
					//cout << "  " << arr[i][j];
				}
				cout << '\n';
			}
			int x, y;
			char temp[1000], z;
			do
			{
				ans3 = 1;
				setColor(0, 7);
				cout << '\n' << "  " << "Coordinate & Action (press ^ to mark and press any character to choose) : ";
				cin >> x >> y >> temp;
				x--;
				y--;
				if (x < 0 || x >= 30 || y < 0 || y >= 30)
				{
					if ((x < 0 || x >= 30) && (y < 0 || y >= 30))
					{
						cout << '\n' << "  " << "Error" << " : " << ++x << ", " << ++y << '\n' << "  " << "Coordinate Range : 1 to 30" << '\n';
						x--;
						y--;
					}
					else if (x < 0 || x >= 30)
					{
						cout << '\n' << "  " << "Error" << " : " << ++x << '\n' << "  " << "Coordinate Range : 1 to 30" << '\n';
						x--;
					}
					else
					{
						cout << '\n' << "  " << "Error" << " : " << ++y << '\n' << "  " << "Coordinate Range : 1 to 30" << '\n';
						y--;
					}
				}
				if (strlen(temp) > 1)
				{
					cout << '\n' << "  " << "Error" << " : " << temp << '\n' << "  " << "Press only one character to choose the action" << '\n';
					ans3 = 0;
				}
				else
				{
					z = temp[0];
				}
			} while (x < 0 || x >= 30 || y < 0 || y >= 30 || ans3 == 0);
			if (arr[x][y] == '^')
			{
				if (z != '^')
				{
					cout << "  " << "Are you sure about your choice? If you are, press 1 : ";
					char ans;
					cin >> ans;
					if (ans != '1')
					{
						continue;
					}
				}
			}
			if (z == '^')
			{
				if (arr[x][y] = '*')
				{
					arr[x][y] = '^';
				}
			}
			else if (main[x][y] == 'B')
			{
				ans1 = 0;
				system("cls");
				cout << '\n' << '\n';
				cout << "  " << "Game Over!" << '\n' << '\n';
				for (int i = 0; i < 30; i++)
				{
					for (int j = 0; j < 30; j++)
					{
						switch (main[i][j])
						{
						case 'B':
							setColor(4, 7);
							cout << "  " << main[i][j];
							break;
						case '0':
							setColor(8, 7);
							cout << "  " << main[i][j];
							break;
						case '1':
							setColor(1, 7);
							cout << "  " << main[i][j];
							break;
						case '2':
							setColor(2, 7);
							cout << "  " << main[i][j];
							break;
						default:
							setColor(5, 7);
							cout << "  " << main[i][j];
						}
						//cout << "  " << main[i][j];
					}
					cout << '\n';
				}
				setColor(0, 7);
				cout << '\n' << "  " << "You wish to play again? If you do press 1 : ";
				char ans;
				cin >> ans;
				if (ans != '1')
				{
					ans2 = 0;
				}
			}
			else if (main[x][y] != '0')
			{
				arr[x][y] = main[x][y];
			}
			else
			{
				reveal(x, y, main, arr);
			}
		} while (ans1 == 1);
	} while (ans2 == 1);
	return 0;
}