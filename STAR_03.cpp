# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)
int main()
{
	FILE *fptr = fopen("ans.txt", "w+");
	int n1, n2;
	int operation = 0;
	while (scanf("%d %d", &n1, &n2) != EOF) {
		if (n1 == 0 && n2 == 0) {
			break;
		}
		operation = 0;
		int carry = 0;
		while (n1 > 0 || n2 > 0) {
			if ((n1 % 10) + (n2 % 10) + carry >= 10) {
				operation++;
			}
			carry = ((n1 % 10) + (n2 % 10) + carry) / 10;
			n1 /= 10;
			n2 /= 10;
		}

		if (operation == 0) {
			printf("No carry operation.\n");
			fprintf(fptr, "No carry operation.\n");
		}
		else if (operation == 1) {
			printf("1 carry operation.\n");
			fprintf(fptr, "1 carry operation.\n");
		}
		else if (operation > 1) {
			printf("%d carry operations.\n", operation);
			fprintf(fptr, "%d carry operations.\n", operation);
		}
	}
	system("PAUSE");
	return 0;
}