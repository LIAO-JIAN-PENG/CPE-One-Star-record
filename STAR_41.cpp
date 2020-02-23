# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# pragma warning(disable: 4996)

struct Alpha {
	char chr;
	int count;
};
void sort(Alpha*, int);
int main()
{
	char code[5000] = { 0 };
	Alpha chr[5000] = { 0 };
	int r = 0;
	while (fgets(code, 5000, stdin) != NULL) {
		if (r) {
			printf("\n");
		}
		int l = strlen(code) - 1;
		code[l] = '\0';
		for (int i = 0; i < l; i++) {
			for (int j = i+1; j < l; j++) {
				if (code[i] < code[j]) {
					char temp = code[i];
					code[i] = code[j];
					code[j] = temp;
				}
			}
		}
		int count = 1;
		int c = 0;
		for (int i = 0; i < l; i++) {
			if (code[i] == code[i + 1]) {
				count++;
			}
			else {
				chr[c].chr = code[i];
				chr[c].count = count;
				c++;
				count = 1;
			}
		}
		sort(chr, c);
		for (int i = 0; i < c; i++) {
			printf("%d %d\n", chr[i].chr, chr[i].count);
		}
		r = 1;
	}
	system("PAUSE");
	return 0;
}

void sort(Alpha* chr, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (chr[i].count > chr[j].count) {
				Alpha temp = chr[i];
				chr[i] = chr[j];
				chr[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (chr[i].chr < chr[j].chr && chr[i].count == chr[j].count) {
				Alpha temp = chr[i];
				chr[i] = chr[j];
				chr[j] = temp;
			}
		}
	}
}