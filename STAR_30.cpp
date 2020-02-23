# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

void Hartal(int*, int, int);
int SumOfHartal(int*, int);

/*
	Rule:
			1	2	3	4	5	6	7	8	9	10	11	12	13	14
	Days						*	*						*	*
			Su	Mo	Tu	We	Th	Fr	Sa	Su	Mo	Tu	We	Th	Fr	Sa
	Party 1			x			x			x			x			period = 3
	Party 2				x				x				x			period = 4
	Party 3								x							period = 8
	Hartals			1	2				3	4			5			½}¤u
	OutPut sum of Hatals' days
*/
int main()
{
	int cases = 0;
	scanf("%d", &cases);
	while (cases) {
		int working[5000] = { 0 };
		int days = 0;
		int parties = 0;
		scanf("%d %d", &days, &parties);

		while (parties) {
			int period = 0;
			scanf("%d", &period);
			Hartal(working, period, days);
			parties--;
		}
		printf("%d\n", SumOfHartal(working, days));
		cases--;
	}
	system("PAUSE");
	return 0;
}

void Hartal(int* work, int period, int days)
{
	int i = 0;
	for (i = period - 1; i < days; i += period) {
		if (i % 7 == 5 || i % 7 == 6)
			continue;
		work[i]++;
	}
}

int SumOfHartal(int* work, int days)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < days; i++) {
		if (work[i] > 0)
			sum++;
	}
	return sum;
}