#include <iostream>
using namespace std;

void draw (int x1,int y1,int x2,int y2)
{
cout<<"E E E E E E E E E E\n";
for (int l=8; l>0; l--)
{
        if (l==y1 && l==y2)
	{
            	cout<<"E ";
		if (x1<x2)
		{
			for (int m=1; m<x1; m++)
				cout<<"  ";
				
			cout<<"P ";
				
			for (int n=1; n<x2-x1; n++)
				cout<<"  ";

			cout<<"C";				

			for (int p=1; p<9-x2; p++)
				cout<<"  ";
				
		}

		if (x1>x2)
		{
			for (int m=1; m<x2; m++)
				cout<<"  ";
				
			cout<<"C ";
				
			for (int n=1; n<x1-x2; n++)
				cout<<"  ";

			cout<<"P ";				

			for (int p=1; p<9-x1; p++)
				cout<<"  ";
				
		}
		
		cout<<"E\n";	
	}
	
	else if (l==y1)
	{
		cout<<"E ";
		for (int m=1; m<x1; m++)
			cout<<"  ";
				
		cout<<"P ";
				
		for (int n=1; n<9-x1; n++)
			cout<<"  ";
		cout<<"E\n";
				
	}

	else if (l==y2)
	{
		cout<<"E ";
		for (int m=1; m<x2; m++)
			cout<<"  ";
				
		cout<<"C ";
				
		for (int n=1; n<9-x2; n++)
			cout<<"  ";
		cout<<"E\n"; 
				
	}

	else
		cout<<"E                 E\n";
	
	}

cout<<"E E E E E E E E E E\n\n";
}

char evaluate (int x1, int y1, int x2, int y2, char t)
{
	if (x1==x2 && y1==y2)
	{
		if (t=='p')
			return 'p';
		if (t=='c')
			return 'c';
	}
	if (x1 == 0 || y1 == 0 || x1 == 9 || y1 == 9)
		return 'c';
	if (x2 == 0 || y2 == 0 || x2 == 9 || y2 == 9)
		return 'b';
	else
		return 'n';
}

void game ()
{
	char move;
	int x1=8;
	int y1=1;
	int x2=1;
	int y2=8;
	char pos [5];
	char over='n';
	draw (x1,y1,x2,y2);
	
	while (true)
	{
		cout << "Your move: ";
		cin >> move;
		cout << "\n\n";

		if (move == 'u')
			y1++;
		else if (move == 'd')
			y1--;
		else if (move == 'l')
			x1--;
		else if (move == 'r')
			x1++;
		else
			continue;

		over = evaluate(x1, y1, x2, y2, 'p');

		if (over != 'n')
			break;

		draw(x1, y1, x2, y2);

		pos[0] = 'd';
		pos[1] = 'u';
		pos[2] = 'l';
		pos[3] = 'r';
		pos[4] = 'y';

		if (y2 - y1 == -1 && x2 == x1)
		{
			pos[4] = 'n';
			move = 'u';
		}
		if (y2 - y1 == 1 && x2 == x1)
		{
			pos[4] = 'n';
			move = 'd';
		}
		if (x2 - x1 == 1 && y2 == y1)
		{
			pos[4] = 'n';
			move = 'l';
		}
		if (x2 - x1 == -1 && y2 == y1)
		{
			pos[4] = 'n';
			move = 'r';
		}

		if (y2 - y1 == -2 && (x2 - x1 == -1 || x2 - x1 == 1))
		{
			pos[4] = 'n';
			move = 'u';
		}
		if (y2 - y1 == 2 && (x2 - x1 == -1 || x2 - x1 == 1))
		{
			pos[4] = 'n';
			move = 'd';
		}
		if (x2 - x1 == 2 && (y2 - y1 == -1 || y2 - y1 == 1))
		{
			pos[4] = 'n';
			move = 'l';
		}
		if (x2 - x1 == -2 && (y2 - y1 == -1 || y2 - y1 == 1))
		{
			pos[4] = 'n';
			move = 'r';
		}

		if (x2 - x1 == -1 && y2 - y1 == -1)
		{
			pos[1] = 'n';
			pos[2] = 'n';
		}
		if (x2 - x1 == 1 && y2 - y1 == -1)
		{
			pos[1] = 'n';
			pos[3] = 'n';
		}
		if (x2 - x1 == -1 && y2 - y1 == 1)
		{
			pos[0] = 'n';
			pos[2] = 'n';
		}
		if (x2 - x1 == 1 && y2 - y1 == 1)
		{
			pos[0] = 'n';
			pos[3] = 'n';
		}

		if (x2 == 1)
			pos[2] = 'n';
		if (x2 == 8)
			pos[3] = 'n';
		if (y2 == 1)
			pos[0] = 'n';
		if (y2 == 8)
			pos[1] = 'n';

		if (pos[4] == 'y')
		{
			for (int i = 0; i < 4; i++)
			{
				if (pos[i] != 'n')
				{
					move = pos[i];
					break;
				}

				if (y2 == 1)
					move = 'u';
				if (y2 == 8)
					move = 'd';
			}

		}

		if (move == 'u')
			y2++;
		if (move == 'd')
			y2--;
		if (move == 'l')
			x2--;
		if (move == 'r')
			x2++;
		
		cout << "Computer's move: " << move << "\n\n";

		over = evaluate(x1, y1, x2, y2, 'c');

		if (over != 'n')
			break;

		draw(x1, y1, x2, y2);
		

		
	}

	if (over == 'p')
		cout << "You Won!!!\n";
	if (over == 'c')
		cout << "The Computer Won!!!\n";
	if (over == 'b')
		cout << "BUG PRESENT!!!\n";

}
