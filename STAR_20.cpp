# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

/*
	Rule:
	 x + y  = sum
	|x - y| = diff
	find the x, y from sum and (absolute) difference
	note: x, y > 0 and (sum + diff) must be even
*/
int main()
{
	int cases = 0;
	long long sum = 0, diff = 0;// sum and (absolute) difference
	long long x = 0, y = 0;

	scanf("%d", &cases);
	while (cases) {
		scanf("%lld %lld", &sum, &diff);
		/* Note */
		x = (sum + diff) % 2 ? -1 : (sum + diff) / 2;
		y = (sum - diff) % 2 ? -1 : (sum - diff) / 2;
		if (x < 0 || y < 0) {
			printf("impossible\n");
		}
		else {
			printf("%lld %lld\n", x, y);
		}
		cases--;
	}
	system("PAUSE");
	return 0;
}