# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

void Matrix(char[200][200], int, int);
int Lsquare(char[200][200], int, int, int, int);
int main()
{
	int T;
	int M, N, Q;
	int L;
	scanf("%d", &T);
	while (T) {
		char matrix[200][200] = { 0 };
		int x, y;
		scanf("%d %d %d\n", &M, &N, &Q);

		Matrix(matrix, M, N);

		printf("%d %d %d\n", M, N, Q);
		while (Q) {
			scanf("%d %d", &x, &y);
			L = Lsquare(matrix, x, y, M, N);
			printf("%d\n", L);
			Q--;
		}
		T--;
	}
	system("PAUSE");
	return 0;
}

void Matrix(char matrix[200][200], int M, int N)
{
	int i, j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			scanf("%c", &matrix[i][j]);
			if (matrix[i][j] == '\n') {
				scanf("%c", &matrix[i][j]);
			}
		}
	}
}

int Lsquare(char matrix[200][200], int x, int y, int M, int N)
{
	char C = matrix[x][y];// center
	int i;
	int l = 0;
	
	int flag = 1;
	while (flag) {
		l ++;
		for (i = 0; i <= l; i++) {
			/*printf("l = %d: %c %c %c %c %c %c %c %c\n", l, matrix[x - l][y + i],matrix[x - l][y - i],
				matrix[x + l][y + i],matrix[x + l][y - i],
				matrix[x + i][y + l],matrix[x - i][y + l],
				matrix[x + i][y - l],matrix[x - i][y - l]);*/
			/* Bug is here*/
			if (matrix[x - l][y + i] == C && matrix[x - l][y - i] == C
				&& matrix[x + l][y + i] == C && matrix[x + l][y - i] == C
				&& matrix[x + i][y + l] == C && matrix[x - i][y + l] == C
				&& matrix[x + i][y - l] == C && matrix[x - i][y - l] == C) {
				continue;
			}
			flag = 0;
			break;
		}
	}
	return 2 * l - 1;
}