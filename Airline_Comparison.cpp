/*
 * There are two airlines and A~Z or a~z cities(A and a is not same).
 * if choose a route(from one city to another) from one airline, and another airline also has this route,
 * so they are same, otherwise are not.
*/

#include <stdio.h>

#define MAX 52

int edgeNum0;
int data0[MAX][MAX];
int path0[MAX][MAX];

int edgeNum1;
int data1[MAX][MAX];
int path1[MAX][MAX];

int rear;
int front;
int queue[MAX];
int visited[MAX];

int Answer;

void BFS(int x, int data[][MAX], int path[][MAX])
{
	int i = 0, j = 0;
	int temp = 0;

	rear = 0;
	front = 0;

	for(i = 0; i < MAX; ++i)
	{
		queue[i] = 0;
		visited[i] = 0;
	}

	queue[rear++] = x;
	visited[x] = 1;

	while(front < rear)
	{
		temp = queue[front++];
		if(temp != x)
		{
			//printf("%d ", temp);
			path[x][j++] = temp;
		}

		for(i = 0; i < MAX; ++i)
		{
			if(data[temp][i] == 1 && visited[i] == 0)
			{
				queue[rear++] = i;
				visited[i] = 1;
			}
		}
	}

}

int main()
{
	int i = 0, j = 0, k = 0;
	int T = 0, test_case = 0;
	char x = '\0', y = '\0';
	int tempX = 0, tempY = 0;

	freopen("Airline_Comparison_input.txt", "r", stdin);

	scanf("%d", &T);

	for(test_case = 1; test_case <= T; ++test_case)
	{
		for(i = 0; i < MAX; ++i)
		{
			for(j = 0; j < MAX; ++j)
			{
				path0[i][j] = -1;
				path1[i][j] = -1;
			}
		}


		scanf("%d", &edgeNum0);
		//printf("%d\n", edgeNum0);
		for(i = 0; i < edgeNum0; ++i)
		{
			getchar();
			scanf("%c", &x);
			getchar();
			scanf("%c", &y);
			
			if(x <= 'Z')
			{
				tempX = x - 'A';
			}
			else
			{
				tempX = x - 'a' + 26;
			}

			if(y <= 'Z')
			{
				tempY = y - 'A';
			}
			else
			{
				tempY = y - 'a' + 26;
			}
			data0[tempX][tempY] = 1;
		}

		scanf("%d", &edgeNum1);
		//printf("%d\n", edgeNum1);
		for(i = 0; i < edgeNum1; ++i)
		{
			getchar();
			scanf("%c", &x);
			getchar();
			scanf("%c", &y);

			if(x <= 'Z')
			{
				tempX = x - 'A';
			}
			else
			{
				tempX = x - 'a' + 26;
			}

			if(y <= 'Z')
			{
				tempY = y - 'A';
			}
			else
			{
				tempY = y - 'a' + 26;
			}

			data1[tempX][tempY] = 1;
		}

		for(i = 0; i < MAX; ++i)
		{
			//printf("%d --> ", i);
			BFS(i, data0, path0);
			//printf("\n");
		}

		for(i = 0; i < MAX; ++i)
		{
			//printf("%d --> ", i);
			BFS(i, data1, path1);
			//printf("\n");
		}

#if 0
		for(i = 0; i < MAX; ++i)
		{
			for(j = 0; j < MAX; ++j)
			{
				printf("%d ", path0[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		for(i = 0; i < MAX; ++i)
		{
			for(j = 0; j < MAX; ++j)
			{
				printf("%d ", path1[i][j]);
			}
			printf("\n");
		}
#endif

		Answer = 0;

		for(i = 0; i < MAX; ++i)
		{
			for(j = 0; j < MAX; ++j)
			{
				if(edgeNum0 > edgeNum1)
				{
					if(path0[i][j] != -1)
					{
						for(k = 0; k < MAX; ++k)
						{
							if(path1[i][k] != -1 && path1[i][k] == path0[i][j])
							{
								Answer = 1;
								break;
							}
						}
					}
				}
				else
				{
					if(path1[i][j] != -1)
					{
						for(k = 0; k < MAX; ++k)
						{
							if(path0[i][k] != -1 && path0[i][k] == path1[i][j])
							{
								Answer = 1;
								break;
							}
						}
					}
				}

				if(k == MAX)
				{
					Answer = 0;
					break;
				}
			}
			if(Answer == 0)
			{
				break;
			}
		}

		printf("Case #%d : %s\n", test_case, Answer? "YES" : "NO");
	}

	return 0;
}