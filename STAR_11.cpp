# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<ctype.h>
# pragma warning(disable: 4996)

/*
	Rule:
		Give two line of string and print out the same part of permutating alpha
		EX:
		1.apple
		  maple -> aelp
		2.hello
		  yellow -> ello
*/
void AlphaCount(char*, int*);
int main()
{
	FILE *fptr = fopen("ans.txt", "w+");
	char str1[1001] = { 0 };
	char str2[1001] = { 0 };

	while (fgets(str1, 1001, stdin) != NULL) {
		fgets(str2, 1001, stdin);

		/* With 26 alphabet */
		int alpha1[26] = { 0 };
		int alpha2[26] = { 0 };

		AlphaCount(str1, alpha1);
		AlphaCount(str2, alpha2);

		for (int i = 0; i < 26; i++) {
			if (alpha1[i] * alpha2[i]) {// When one of alpha is 0, we skip
				int same = alpha1[i] > alpha2[i] ? alpha2[i] : alpha1[i];
				
				for (int j = 0; j < same; j++) {
					printf("%c", i + 97);
					fprintf(fptr, "%c", i + 97);
				}
			}
		}
		printf("\n");
		fprintf(fptr, "\n");
	}
	system("PAUSE");
	return 0;
}

void AlphaCount(char* str, int* alpha)
{
	/* Count for alphabet in string*/
	int i;
	for (i = 0; i < strlen(str); i++) {
		if (isalpha(str[i])) {
			alpha[str[i] - 97]++;
		}
	}
}