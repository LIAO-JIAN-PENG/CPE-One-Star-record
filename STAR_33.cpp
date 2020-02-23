# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# pragma warning(disable: 4996)

int isPrime(int);
int reverse(int);
int getDigit(int);

int main()
{
	/*
	1. ．N is not prime.・, if N is not a Prime number.
	2. ．N is prime.・, if N is Prime and N is not Emirp.
	3. ．N is emirp.・, if N is Emirp.	*/
	int num = 0;
	while (scanf("%d", &num) != EOF) {

		if (isPrime(num) && isPrime(reverse(num)) && num != reverse(num)) {
			printf("%d is emirp.\n", num);
		}
		else if (isPrime(num)) {
			printf("%d is prime.\n", num);
		}
		else{
			printf("%d is not prime.\n", num);
		}
	}
	system("PAUSE");
	return 0;
}

int isPrime(int n)
{
	int i;
	for (i = 2; i <= int(sqrt(n)); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int reverse(int n)
{
	int i = 0;
	int ren = 0;
	int digit = getDigit(n);

	for (i = digit - 1; i > -1; i--) {
		ren += (n % 10) * int(pow(10, i));
		n /= 10;
	}
	return ren;
}

int getDigit(int n)
{
	int i;
	for (i = 0; n; i++) {
		n /= 10;
	}
	return i;
}