# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# pragma warning(disable: 4996)

void getAnswer(char[100][100], int, int);
void setflag(char[100][100], int, int, int, int);

int main()
{
	int R, C;
	int field = 1;
	char map[100][100] = { 0 };

	while (scanf("%d %d", &R, &C) != EOF) {
		memset(map, '0', sizeof(char) * 10000);
		if (R == 0 && C == 0)
			break;
		if (field != 1) {
			printf("\n");
		}
		
		int i, j;
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				while (map[i][j] = getchar()) {
					if (map[i][j] != '\n')
						break;
				}
				if (map[i][j] == '.') {
					map[i][j] = '0';
				}
			}
		}

		getAnswer(map, R, C);

		printf("Field #%d:\n", field);
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		field++;
	}
	system("PAUSE");
	return 0;
}

void getAnswer(char map[100][100], int R, int C)
{
	int i, j;
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (map[i][j] == '*') {
				setflag(map, i, j, R, C);
			}
		}
	}
}

void setflag(char map[100][100], int r, int c, int R, int C)
{
	int i, j;
	for (i = r - 1; i <= r + 1; i++) {
		for (j = c - 1; j <= c + 1; j++) {
			if (i < 0 || i >= R || j < 0 || j >= C || (i == r && j == c))
				continue;
			else {
				if (map[i][j] == '*')
					continue;

				map[i][j]++;
			}
		}
	}
}