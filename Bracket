#include <stdio.h>

#define MAX 1024
int Answer;
char a[MAX];
int s0[MAX];
int idx0;

int main()
{
	int t,T;
	int i;
	int temp0,temp1;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(t = 1; t <= T; ++t)
	{
		scanf("%s", &a);
		//printf("%s", a);

		idx0 = 0;
		Answer = 0;
		for(i = 0; a[i] != '\0'; ++i)
		{
			if(a[i] == '(' || a[i] == '[')
			{
				s0[idx0++] = a[i];
			}
			else if(a[i] == ')')
			{
				temp0 = s0[--idx0];
				s0[idx0] = 0;//reset
				if(temp0 == '(')
				{
					s0[idx0++] = 2;
					/*
					if(idx0 > 1)
					{
						temp0 = s0[--idx0];
						if(s0[idx0-1] != '(' && s0[idx0-1] != '[')//two int
						{
							temp1 = s0[--idx0];
							temp0 = temp0 + temp1;
							s0[idx0++] = temp0;
						}
						else
						{
							s0[idx0++] = temp0;
						}
					}
					*/
				}
				else if(temp0 != '(')
				{
					temp1 = s0[--idx0];
					s0[idx0] = 0;
					if(temp1 == '(')
					{
						temp0 = temp0 * 2;
						s0[idx0++] = temp0;

						/*
						if(idx0 > 1)
						{
							temp0 = s0[--idx0];
							if(s0[idx0-1] != '(' && s0[idx0-1] != '[')//two int
							{
								temp1 = s0[--idx0];
								temp0 = temp0 + temp1;
								s0[idx0++] = temp0;
							}
							else
							{
								s0[idx0++] = temp0;
							}
						}
						*/
					}
				}
				if(idx0 > 1)
				{
					temp0 = s0[--idx0];
					s0[idx0] = 0;
					if(s0[idx0-1] != '(' && s0[idx0-1] != '[')//two int
					{
						temp1 = s0[--idx0];
						s0[idx0] = 0;
						temp0 = temp0 + temp1;
						s0[idx0++] = temp0;
					}
					else
					{
						s0[idx0++] = temp0;
					}
				}
			}
			else if(a[i] == ']')
			{
				temp0 = s0[--idx0];
				s0[idx0] = 0;
				if(temp0 == '[')
				{
					s0[idx0++] = 3;
					
					/*
					if(idx0 > 1)
					{
						temp0 = s0[--idx0];
						if(s0[idx0-1] != '[' && s0[idx0-1] != '(')//two int
						{
							temp1 = s0[--idx0];
							temp0 = temp0 + temp1;
							s0[idx0++] = temp0;
						}
						else
						{
							s0[idx0++] = temp0;
						}
					}
					*/
				}
				
				else if(temp0 != '[')
				{
					temp1 = s0[--idx0];
					s0[idx0] = 0;
					if(temp1 == '[')
					{
						temp0 = temp0 * 3;
						s0[idx0++] = temp0;

						/*
						if(idx0 > 1)
						{
							temp0 = s0[--idx0];
							if(s0[idx0-1] != '[' && s0[idx0-1] != '(')//two int
							{
								temp1 = s0[--idx0];
								temp0 = temp0 + temp1;
								s0[idx0++] = temp0;
							}
							else
							{
								s0[idx0++] = temp0;
							}
						}
						*/
					}
				}

				if(idx0 > 1)
				{
					temp0 = s0[--idx0];
					s0[idx0] = 0;
					if(s0[idx0-1] != '(' && s0[idx0-1] != '[')//two int
					{
						temp1 = s0[--idx0];
						s0[idx0] = 0;
						temp0 = temp0 + temp1;
						s0[idx0++] = temp0;
					}
					else
					{
						s0[idx0++] = temp0;
					}
				}
			}
		}

		if(idx0 == 1)//just int and in stack postion 0
		{
			Answer = s0[--idx0];
		}
		else
		{
			Answer = 0;
		}

		
		printf("Case#%d:", t);
		printf("%d %d\n", idx0, Answer);

	}

	return 0;
}
