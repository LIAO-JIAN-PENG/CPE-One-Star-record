# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

int main()
{
	long long i, j;
	int cases = 0;
	int count;
	scanf("%d", &cases);
	for (count = 1; cases; count++) {
		long long x1, y1, x2, y2;
		long long start, end;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		start = x1 + y1 + 1;
		end = x2 + y2 + 1;


		long long step = 0;
		for (i = start + 1; i < end; i++) {
			step += i;
		}
		if (start == end) {
			step = x2 - x1;
		}
		else {
			step += y1 + x2 + 1;
		}
		
		printf("Case %d: %lld\n", count, step);
		cases--;
	}
	system("PAUSE");
	return 0;
}