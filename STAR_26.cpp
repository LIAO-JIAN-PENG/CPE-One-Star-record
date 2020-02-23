# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

int Fibo[50] = { 0 };
void fibo(int);
int getIndex(int);

/*
	Rule:
	fibonacci sum
	1 2 3 5 8 13 21 34 ....
	0 1 1 0 0 1  0  0  = 18 (gived from the Question)
*/
int main()
{
	fibo(1000000000);
	int cases = 0;
	int num = 0, index = 0;
	scanf("%d", &cases);

	while (cases) {
		int fib[100] = { 0 };
		scanf("%d", &num);

		printf("%d = ", num);

		int start = getIndex(num);;
		
		while (num) {
			index = getIndex(num);
			fib[index] = 1;
			num -= Fibo[index];
		}
		
		
		for (int i = start; i > -1; i--) {
			printf("%d", fib[i]);
		}
		printf(" (fib)\n");
		cases--;
	}

	system("PAUSE");
	return 0;
}

void fibo(int x)
{
	int n1 = 1, n2 = 2;
	for (int i = 0;n1 <= x; i++) {
		Fibo[i] = n1;
		n1 = n2;
		n2 += Fibo[i];
	}
}

int getIndex(int n)
{
	int i;
	for (i = 0; n >= Fibo[i]; i++) {
		if (n == Fibo[i]) {
			return i;
		}
	}
	return i - 1;
}