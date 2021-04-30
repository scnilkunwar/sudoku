#include <stdio.h>
#include <conio.h>

int element[9][9] = {{0, 0, 0, 0, 0, 0, 0, 9, 0},
                      {1, 9, 0, 4, 7, 0, 6, 0, 8},
                      {0, 5, 2, 8, 1, 9, 4, 0, 7},
                      {2, 0, 0, 0, 4, 8, 0, 0, 0},
                      {0, 0, 9, 0, 0, 0, 5, 0, 0},
                      {0, 0, 0, 7, 5, 0, 0, 0, 9},
                      {9, 0, 7, 3, 6, 4, 1, 8, 0},
                      {5, 0, 6, 0, 8, 1, 0, 7, 4},
                      {0, 8, 0, 0, 0, 0, 0, 0, 0}};

void board()
{
	for(int i=0;i<9;i++)
	{
		if(i % 3 == 0)
			printf("||===|===|===||===|===|===||===|===|===||\n");
		else
			printf("||---|---|---||---|---|---||---|---|---||\n");
		for(int k=0;k<9;k++)
		{
			if(k % 3 == 0)
			{
				if(element[i][k] == 0)
					printf("||   ");
				else
					printf("|| %d ",element[i][k]);
			}
			else
			{
				if(element[i][k] == 0)
					printf("|   ");
				else
					printf("| %d ",element[i][k]);
			}
		}

		printf("||\n");
	}
	printf("||===|===|===||===|===|===||===|===|===||\n");
}

int ispossible(int x, int y, int n)
{
	//horizontal
	for(int i=0;i<9;i++)
	{
		if(i == y)
        {
            continue;
        }
		if(element[x][i] == n)
        {
            return 0;
        }
	}
	//vertical
	for(int i=0;i<9;i++)
	{
		if(i == x)
        {
            continue;
        }

		if(element[i][y] == n)
        {
           return 0;
        }
	}

	//square
	int x0 = (x/3)*3;
	int y0 = (y/3)*3;

	for(int i=x0;i<x0+3;i++)
	{
		for(int j=y0;j<y0+3;j++)
		{
			if(i == x && j == y)
            {
                continue;
            }
			if(element[i][j] == n)
            {
                return 0;
            }
		}
	}

	return 1;
}

void solve()
{
	for(int x=0;x<9;x++)
	{
		for(int y=0;y<9;y++)
		{
		    if(element[x][y] == 0)
            {
                for(int n=1;n<=9;n++)
                {
					if(ispossible(x, y, n))
					{
                        int count = 0;
					    for(int i=1;i<=9;i++)
                        {
                            if(i == n)
                            {
                                continue;
                            }
                            else
                            {
                                if(ispossible(x,y,i))
                                    count++;
                            }
                        }
                        if(count == 0)
                            element[x][y] = n;
					}
				}
            }
		}
	}
	int count = 0;
	for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            if(element[j][k] == 0)
            {
                count++;
            }
        }
    }
    if(count == 0)
        return;
    else
        solve();
}

int main()
{
	printf("hints:\n");
	board();
	printf("\n\nsolution:\n");
	solve();
	board();
	return 0;
}
