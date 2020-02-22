# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

int main()
{
	long long num1, num2;
	while (scanf("%lld %lld", &num1, &num2) != EOF) {
		printf("%lld\n", abs(num1 - num2));
	}
	system("PAUSE");
	return 0;
}