# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

int distance(int, int);
int findMinSum(int*, int);
int main()
{
	int cases = 0;
	int streets[1000] = { 0 };
	scanf("%d", &cases);

	int s = 0;
	while (cases) {
		scanf("%d", &s);
		for (int i = 0; i < s; i++) {
			scanf("%d", &streets[i]);
		}

		int min = findMinSum(streets, s);

		printf("%d\n", min);

		cases--;
	}

	system("PAUSE");
	return 0;
}

int distance(int x, int y)
{
	return abs(x - y);
}

int findMinSum(int* nums, int l)
{
	int i, j;
	int sum = 0;
	int min = 2147483647;
	for (i = 0; i < l; i++) {
		sum = 0;
		for (j = 0; j < l; j++) {
			if (i == j)
				continue;
			sum += distance(nums[i], nums[j]);
		}
		if (min > sum) {
			min = sum;
		}
	}
	return min;
}
