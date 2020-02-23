# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# pragma warning(disable: 4996)

int CountDeci(int);
int CountHex(int);

/*
	Rule:
		1. Read the number N to encrypt : M = 265
		2. Interpret N as a decimal number : X1 = 265 (decimal)
		3. Convert the decimal interpretation of N to 
			its binary representation : X1 = 100001001 (binary)

		4. Let b1 be equal to the number of 1¡¦s in this binary 
			representation : b1 = 3

		5. Interpret N as a Hexadecimal number : X2 = 265 (hexadecimal)
		6. Convert the hexadecimal interpretation of N to 
			its binary representation : X2 = 1001100101

		7. Let b2 be equal to the number of 1¡¦s in 
			the last binary representation : b2 = 5
		Output b1 b2
*/
int main()
{
	int cases = 0;
	int num = 0;
	scanf("%d", &cases);


	int deci = 0, hex = 0;
	while (cases) {
		scanf("%d", &num);
		deci = CountDeci(num);
		hex = CountHex(num);
		printf("%d %d\n", deci, hex);
		cases--;
	}
	system("PAUSE");
	return 0;
}

int CountDeci(int n)
{
	int i = 0;
	int count = 0;
	for (i = 0; n; i++) {
		if (n % 2)
			count++;
		n /= 2;
	}
	return count;
}

int CountHex(int n)
{
	int i = 0;
	int num = 0;
	for (i = 0; n; i++) {
		num += (n % 10) * int(pow(16,i));
		n /= 10;
	}

	return CountDeci(num);
}