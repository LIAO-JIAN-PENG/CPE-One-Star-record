# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

/*
	Rule:
	ex: 125 5 => 125 25 5 1		output (125 25 5 1)
		30 3 => 30 10 3(..1) ...output (Boring)
		notice (0, 1)
*/

int main()
{
	long long num = 0, divisor = 1;
	long long divided[1000] = { 0 };
	while (scanf("%lld %lld", &num, &divisor) != EOF) {
		int count = 0;
		
		if (divisor == 0 || divisor == 1) {
			printf("Boring!\n");
			continue;
		}

		for (long long i = 1; i <= num; i *= divisor) {
			if (num % i == 0) {
				divided[count] = num / i;
				count++;
			}
			else {
				break;
			}
		}
		if (divided[count - 1] == 1 && count != 1) {
			for (int i = 0; i < count - 1; i++) {
				printf("%lld ", divided[i]);
			}
			printf("%d", 1);
		}
		else {
			printf("Boring!");
		}
		printf("\n");
	}
	system("PAUSE");
	return 0;
}