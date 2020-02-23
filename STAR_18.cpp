# include<stdio.h>
# include<stdlib.h>
# include<ctype.h>
# include<string.h>
# include<math.h>
# pragma warning(disable: 4996)

/*
	Rule:
	Give a x value, and calculate the ans of the ¡§Polly the Polynomial"
	ex:
	Input:
	4
	4 3 1
	Output:
	x = 4
	4x^2 + 3x + 1
	>> 8x + 3 = 8 * 4 + 3 = 35
	*/

int main()
{
	long long valueX = 0;
	long long coeff[10000] = { 0 };
	long long result = 0;
	FILE *fptr = fopen("ans.txt", "w+");

	while (scanf("%lld", &valueX) != EOF) {
		int i = 0;
		result = 0;

		do {
			scanf("%lld", &coeff[i]);
			i++;
		} while (getchar() != 10);

		for (int j = 0; j < i; j++) {
			coeff[j] *= i - j - 1;
			coeff[j] *= int(pow(valueX, i - j - 2));
			result += coeff[j];
		}
		printf("%lld\n", result);
		fprintf(fptr, "%lld\n", result);
	}
	fclose(fptr);
	system("PAUSE");
	return 0;
}