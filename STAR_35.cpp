# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

int GCD(int, int);

/*
	Rule:
	G=0;
	for(i=1;i<N;i++)
	{
		for(j=i+1;j<=N;j++)
		{
			G+=GCD(i,j);
		}	}
	N as terminal
*/
int main()
{
	int G = 0;
	int N = 0;
	
	while (scanf("%d", &N) != EOF && N != 0) {
		G = 0;
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				G += GCD(i, j);
			}
		}
		printf("%d\n", G);
	}

	system("PAUSE");
	return 0;
}

int GCD(int a, int d) 
{
	if (a < d) {
		int temp = a;
		a = d;
		d = temp;
	}
	if (d == 0) {
		return a;
	}
	else {
		return GCD(d, a % d);
	}
}