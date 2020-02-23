# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

/*
	Rule:
	A B2-Sequence is a sequence of "positive integers"
	1 ≤ b1 < b2 < b3 . . . such that all pairwise sums bi +bj ,
	where i ≤ j, are different.
*/
int diffPairSum(int*, int);

int main()
{
	int length = 0;
	int nums[1000] = { 0 };
	int ascending = 1;
	int count = 1;
	FILE *fptr = fopen("ans.txt", "w+");

	while (scanf("%d", &length) != EOF) {
		ascending = 1;

		for (int i = 0; i < length; i++) {
			scanf("%d", &nums[i]);
			if ((i != 0 && nums[i] <= nums[i - 1]) || nums[i] < 1)
				ascending = 0;
		}
		
		if (ascending && diffPairSum(nums, length)) {
			printf("Case #%d: It is a B2-Sequence.\n\n", count);
			fprintf(fptr, "Case #%d: It is a B2-Sequence.\n\n", count);
		}
		else {
			printf("Case #%d: It is not a B2-Sequence.\n\n", count);
			fprintf(fptr, "Case #%d: It is not a B2-Sequence.\n\n", count);
		}

		count++;
	}

	fclose(fptr);
	system("PAUSE");
	return 0;
}

int diffPairSum(int* nums, int n) 
{
	int mid = n / 2;
	int sums[10000] = { 0 };
	int count = 0;
	int i, j;

	for (i = 0; i <= mid; i++) {
		for (j = mid; j < n; j++) {
			sums[count] = nums[i] + nums[j];
			count++;
		}
	}

	for (i = 0; i < count; i++) {
		for (j = i+1; j < count; j++) {
			if (sums[i] == sums[j])
				return 0;
		}
	}
	return 1;
}