# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

/*
	Quick Sort (T_T)
*/
int nums[1000000] = { 0 };
void quicksort(int *data, int left, int right);
void swap(int *a, int *b);
int main()
{
	int N;
	while (scanf("%d", &N) != EOF) {
		int mid = (N % 2)?N / 2:N / 2 - 1;
		int midCount = 0;
		int possible = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &nums[i]);
		}
		quicksort(nums, 0, N - 1);

		if (N % 2) {
			possible = 1;
			for (int i = 0; i < N; i++) {
				if (nums[i] == nums[mid]) {
					midCount++;
				}
			}
		}
		else {
			possible = nums[mid + 1] - nums[mid] + 1;
			for (int i = 0; i < N; i++) {
				if (nums[i] == nums[mid] || nums[i] == nums[mid+1]) {
					midCount++;
				}
			}
		}
		printf("%d %d %d\n", nums[mid], midCount, possible);
	}
	system("PAUSE");
	return 0;
}
void quicksort(int *data, int left, int right)
{
	int pivot, i, j;

	if (left >= right) { return; }

	pivot = data[left];

	i = left + 1;
	j = right;

	while (1)
	{
		while (i <= right)
		{
			if (data[i] > pivot)
			{
				break;
			}

			i = i + 1;
		}

		while (j > left)
		{
			if (data[j] < pivot)
			{
				break;
			}

			j = j - 1;
		}

		if (i > j) { break; }

		swap(&data[i], &data[j]);
	}

	swap(&data[left], &data[j]);

	quicksort(data, left, j - 1);
	quicksort(data, j + 1, right);
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}