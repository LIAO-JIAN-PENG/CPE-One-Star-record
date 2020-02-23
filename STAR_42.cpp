# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

int swapTime(int*, int);
void swap(int*, int*);
int main()
{
	int cases = 0;
	int nums[1000] = { 0 };
	scanf("%d", &cases);
	while (cases) {
		int len = 0;
		scanf("%d", &len);
		for (int i = 0; i < len; i++) {
			scanf("%d", &nums[i]);
		}
		int time = swapTime(nums, len);
		printf("Optimal train swapping takes %d swaps.\n", time);
		cases--;
	}

	system("PAUSE");
	return 0;
}

int swapTime(int* nums, int L)
{
	int time = 0;
	int i, j;
	for (i = 0; i < L; i++) {
		for (j = i + 1; j < L; j++) {
			if (nums[i] > nums[j]) {
				swap(&nums[i], &nums[j]);
				time++;
			}
		}
	}
	return time;
}
void swap(int*a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}