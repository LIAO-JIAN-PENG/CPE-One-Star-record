# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# pragma warning(disable: 4996)

int squareNum(int, int);
int main()
{
	int min = 0, max = 0;
	while (scanf("%d %d", &min, &max) != EOF) {
		if (min == 0 && max == 0) {
			break;
		}
		printf("%d\n", squareNum(min, max));
	}
	system("PAUSE");
	return 0;
}

int squareNum(int min, int max)
{
	int i;
	int count = 0;
	for (i = min; i <= max; i++) {
		if (sqrt(i) == int(sqrt(i))) {
			count++;
		}
	}
	return count;
}