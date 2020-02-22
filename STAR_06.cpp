# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

FILE *fptr = fopen("ans.txt", "w+");
/* Bangla Numbers:
	・kuti・ (10000000), 10^7
	・lakh・ (100000),   10^5
	・hajar・ (1000),	   10^3
	・shata・ (100)	   10^2
	display the number with Bangla Number system
*/

void Bangla(long long);

int main()
{
	
	long long num, last;
	int count = 0;
	while (scanf("%lld", &num) != EOF) {
		count++;// count for index
		printf("%4d.", count);
		fprintf(fptr, "%4d.", count);

		Bangla(num);

		printf("\n");
		fprintf(fptr, "\n");
	}
	fclose(fptr);
	system("PAUSE");
	return 0;
}

void Bangla(long long num)
{
	long long kuti = 0, lakh = 0, hajar = 0, shata = 0, last = 0;
	last = num % 100;
	num /= 100;
	shata = num % 10;
	num /= 10;
	hajar = num % 100;
	num /= 100;
	lakh = num % 100;
	num /= 100;
	kuti = num;
	
	if (kuti >= 100)
		Bangla(kuti);

	if (kuti >= 100) {
		printf(" kuti");
		fprintf(fptr, " kuti");
	}
	else if (kuti) {
		printf(" %d kuti", kuti);
		fprintf(fptr, " %d kuti", kuti);
	}
	if (lakh) {
		printf(" %d lakh", lakh);
		fprintf(fptr, " %d lakh", lakh);
	}
	if (hajar) {
		printf(" %d hajar", hajar);
		fprintf(fptr, " %d hajar", hajar);
	}
	if (shata) {
		printf(" %d shata", shata);
		fprintf(fptr, " %d shata", shata);
	}
	if (last) {
		printf(" %d", last);
		fprintf(fptr, " %d", last);
	}
	else if (kuti == 0 && lakh == 0 && hajar == 0 && shata == 0) {
		printf(" %d", last);
		fprintf(fptr, " %d", last);
	}
}