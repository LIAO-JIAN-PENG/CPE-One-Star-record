# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# pragma warning(disable: 4996)

/* Tell the number if it devided by 11 */
/* The sum of odd digit and the sum of even digit*/
/* The digit limit in 1000 */

int devidedBy11(char*, int);

int main()
{
	char num[2000] = { 0 };
	while (scanf("%s", num) != EOF) {
		if (num[0] == '0' && num[1] == '\0')
			break;

		if (devidedBy11(num, strlen(num))) {
			printf("%s is a multiple of 11.\n", num);
		}
		else {
			printf("%s is not a multiple of 11.\n", num);
		}
	}
	system("PAUSE");
	return 0;
}

int devidedBy11(char* num, int l)
{
	int Esum = 0;
	int Osum = 0;

	int i;
	for (i = 0; i < l; i++) {
		if (i % 2) {
			Osum += num[i] - 48;
		}
		else {
			Esum += num[i] - 48;
		}
	}
	if (abs(Esum - Osum) % 11 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}