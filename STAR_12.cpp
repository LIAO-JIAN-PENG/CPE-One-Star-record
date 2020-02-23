# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# pragma warning(disable: 4996)

/*
	Rule:
	Rotating the writing
	EX:
	012 34567
	98 4 675
	
	-> 90
	   81
	    2
	   4 
	    3
	   64
	   75
	   56
	    7
*/
int main()
{
	char writing[100][1000] = { 0 };// Writing have 100 x 1000(length)
	int row = 0;

	int Lmax = 0;// Longest length
	while (fgets(writing[row], 1000, stdin) != NULL) {
		writing[row][strlen(writing[row]) - 1] = '\0';// Delete the Enter key

		/* Decide the longest length */
		Lmax = Lmax < strlen(writing[row]) ? strlen(writing[row]) : Lmax;

		row++;
	}

	for (int i = 0; i < Lmax; i++) {
		for (int j = row - 1; j >= 0; j--) {
			/* Dealing with the space and vacuum */
			if (writing[j][i] == 0 || writing[j][i] == NULL) {
				printf(" ");
			}
			else {
				printf("%c", writing[j][i]);
			}
		}
		printf("\n");
	}
	system("PAUSE");
	return 0;
}