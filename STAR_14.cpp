# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)
# define StartDay 5

int weekDay(int, int);

/* 2011 4/4 is Monday
Normal Year(365 days)
(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
(W + 31 + 28 + 31 + 4)(= W + 94) % 7 = 1
W = 5
StartDay in 2011 is Friday(2000 12 31)
*/

int main()
{
	int cases = 0;
	int month, day;
	int week_day = 0;
	scanf("%d", &cases);
	while (cases) {
		scanf("%d %d", &month, &day);
		week_day = weekDay(month, day);
		
		switch (week_day) {
		case 1: printf("Monday\n"); break;
		case 2: printf("Tuesday\n"); break;
		case 3: printf("Wednesday\n"); break;
		case 4: printf("Thursday\n"); break;
		case 5: printf("Friday\n"); break;
		case 6: printf("Saturday\n"); break;
		case 0: printf("Sunday\n"); break;
		}

		cases--;
	}
	system("PAUSE");
	return 0;
}

int weekDay(int M, int D)
{
	/* We get the week day from the sum of days from 1/0(as 12/31) and % 7 */
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sumDay = 0;
	int i;
	for (i = 0; i < M - 1; i++) {
		sumDay += month[i];
	}
	sumDay += D;

	return (StartDay + sumDay) % 7;
}