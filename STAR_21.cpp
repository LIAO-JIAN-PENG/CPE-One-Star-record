# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)
/*
	Rulw:
	Definition: Symmetric matrix is such a matrix 
	that all elements of it are non-negative and symmetric
	with relation to the center of this matrix.
	ex:
	1 2 3
	4 0 4
	3 2 1

	1 4 5 6
	9 8 7 3
	3 7 8 9
	6 5 4 1

	exclude:
	1  2  3
	4 -5  4
	3  2  1 (with negative number)
*/
int symmetric(long long[100][100], int);
int main()
{
	int cases = 0;
	int n = 0;// n dimension
	long long matrix[100][100] = { 0 };
	int s = 0;// symmetric

	scanf("%d", &cases);
	for (int t = 1; t <= cases;t++) {
		scanf(" N = %d", &n);//這裡很重要很重要N前面一定要有空格不然會錯(from internet)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%lld", &matrix[i][j]);
			}
		}
		s = symmetric(matrix, n);
		if (s) {
			printf("Test #%d: Symmetric.\n", t);
		}
		else {
			printf("Test #%d: Non-symmetric.\n", t);
		}
	}

	system("PAUSE");
	return 0;
}

int symmetric(long long M[100][100], int n)
{
	int i, j;
	int S = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			/* get the number from middle point formula*/
			if (M[i][j] != M[n - i - 1][n - j - 1])
				S = 0;
			else if (M[i][j] < 0 || M[j][i] < 0)
				S = 0;
		}
	}
	return S;
}