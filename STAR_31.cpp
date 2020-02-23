# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<math.h>
# pragma warning(disable: 4996)

int interprime(int, int);
int translate(char*);
int gcd(int, int);

int main()
{
	int cases = 0;
	char n1[100] = { 0 }, n2[100] = { 0 };
	int num1, num2;
	scanf("%d\n", &cases);
	for (int i = 0; cases - i ;i++) {
		fgets(n1, 100, stdin);
		fgets(n2, 100, stdin);

		num1 = translate(n1);
		num2 = translate(n2);
		if (interprime(num1, num2)) {
			printf("Pair #%d: All you need is love!\n", i + 1);
		}
		else {
			printf("Pair #%d: Love is not all you need!\n", i + 1);
		}
	}
	system("PAUSE");
	return 0;
}

int interprime(int x, int y)
{
	if (x < y) {
		int temp = x;
		x = y;
		y = temp;
	}
	if (gcd(x, y) == 1)
		return 0;
	else
		return 1;
}

int gcd(int x, int y)
{
	if (x == 0 || y == 0) {
		return 0;
	}
	if (x % y == 0) {
		return y;
	}
	else {
		return gcd(y, x % y);
	}
}

int translate(char* num)
{
	int i = 0;
	int l = strlen(num) - 1;
	int number = 0;
	for (i = 0; i < l; i++) {
		number += (num[l - i - 1] - '0') * int(pow(2,i));
	}

	return number;
}