# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# pragma warning(disable: 4996)

/*
	Rule:
		When we meet " , we change it to `` when odd time, else '' when even time 
*/
int main()
{
	char sentence[3000] = { 0 };
	int Switch = 1;

	while (fgets(sentence, 3000, stdin) != NULL) {
		int l = strlen(sentence);

		for (int i = 0; i < l; i++) {
			if (sentence[i] == 34) {
				if (Switch > 0) {
					printf("``");
				}
				else {
					printf("''");
				}
				Switch *= -1;
			}
			else {
				printf("%c", sentence[i]);
			}
		}
	}
	return 0;
}