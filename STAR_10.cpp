# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

/* Rule:
	Get the sum of each digit
	Until the num less than 10 (-> 1)
	EX:
	12345->15->6
*/

long long f(long long);
int main()
{
	long long num = 0;
	long long g;
	while (1) {
		scanf("%lld", &num);
		if (num == 0) {
			break;
		}
		g = f(num);
		printf("%lld\n", g);
	}

	system("PAUSE");
	return 0;
}

long long f(long long x)
{
	long long sum = 0;
	if (x < 10) {
		return x;
	}
	else {
		

		while (x) {// while x != 0
			sum += x % 10;
			x /= 10;
		}
		f(sum);
	}
}