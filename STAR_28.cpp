# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

int main()
{
	int num = 0;
	while (scanf("%d", &num) != EOF) {
		int n[200] = { 0 };
		int count = 0;
		if (num == 0)
			break;

		int i = 0;
		for (i = 0; num; i++) {
			if (num % 2) {
				n[i] = num % 2;
				count++;
			}	
			num /= 2;
		}
		printf("The parity of ", count);
		for (int j = i - 1; j > -1; j--) {
			printf("%d", n[j]);
		}
		printf(" is %d (mod 2).\n", count);
	}
	system("PAUSE");
	return 0;
}