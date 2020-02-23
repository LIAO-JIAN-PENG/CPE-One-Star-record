# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<ctype.h>
# pragma warning(disable: 4996)

/*
	Rule:
	we know that n can be deivided by 9, 
		following the rule that digits sum of n is multiple of 9
	ex:
	12345678 % 9 == 0
	1 + 2 + 3 + 4 ... + 9 = 36
	=> 36 % 9 == 0
	3 + 6 = 9
	=> 9 % 9 == 0 (9-degree = 3)(3 steps)
*/
int digitSum_char(char*, int);
int digitSum_int(int);
int main()
{
	char num[5000] = { 0 };
	while (fgets(num, 5000, stdin) != NULL) {
		/* solving the extra problem '0' */
		if (num[0] == '0')
			break;

		int l = strlen(num) - 1;// delete Enter key
		int sum = digitSum_char(num, l);
		num[l] = '\0';

		int count = 1;
		while (sum % 9 == 0 && sum != 9) {// stop when sum = 9
			sum = digitSum_int(sum);
			count++;
		}
		if (count > 1 || sum == 9) {
			printf("%s is a multiple of 9 and has 9-degree %d.\n", num, count);
		}
		else {
			printf("%s is not a multiple of 9.\n", num, count);
		}
	}
	system("PAUSE");
	return 0;
}

int digitSum_char(char* num, int L)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < L; i++) {
		if (isdigit(num[i])) {
			sum += num[i] - '0';
		}
	}
	return sum;
}

int digitSum_int(int num)
{
	int sum = 0;
	while (num) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}