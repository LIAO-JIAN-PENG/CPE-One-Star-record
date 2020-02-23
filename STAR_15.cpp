# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

/*
	Rule: Jolly Sequence
	if the absolute values of the difference between
	successive elements take on all the values 1 through n − 1
	EX. 1 4 2 3 -> (3, 2, 1)
*/
void sort(int*, int);

int main()
{
	FILE *fptr = fopen("ans.txt", "w+");
	int length = 0;// 
	int num = 0, temp = 0;
	int Jolly = 1;// Jolly Squence
	int i;
	while (scanf("%d", &length) != EOF) {
		Jolly = 1;
		int diff[2000] = { 0 };
		for (i = 0; i < length; i++) {
			scanf("%d", &num);
			if (i > 0) {// start from num and temp
				diff[i - 1] = abs(num - temp);
			}
			temp = num;
		}

		sort(diff, length - 1);

		for (int i = 0; i < length - 1; i++) {
			if (diff[i] != i + 1) {
				Jolly = 0;
			}
		}
		if (Jolly) {
			printf("Jolly\n");
			fprintf(fptr, "Jolly\n");
		}
		else {
			printf("Not jolly\n");
			fprintf(fptr, "Not jolly\n");
		}
	}
	fclose(fptr);
	system("PAUSE");
	return 0;
}

void sort(int* num, int L)
{
	int i, j;
	for (i = 0; i < L; i++) {
		for (j = i + 1; j < L; j++) {
			if (num[i] > num[j]) {
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
}