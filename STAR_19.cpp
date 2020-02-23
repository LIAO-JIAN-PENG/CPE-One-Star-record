# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

/*
	Rule:
	Caculate the odd sum between start and end
*/
int OddSumInRange(int, int);
int main()
{
	int cases = 0;
	int start = 0, end = 0;
	
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		scanf("%d %d", &start, &end);
		printf("Case %d: %d\n", i, OddSumInRange(start, end));
	}
	system("PAUSE");
	return 0;
}

int OddSumInRange(int a, int b) {
	a = (a % 2) ? a : a + 1;
	b = (b % 2) ? b : b - 1;
	int sum = 0;
	int i;
	for (i = a; i <= b; i += 2) {
		sum += i;
	}
	return sum;
}