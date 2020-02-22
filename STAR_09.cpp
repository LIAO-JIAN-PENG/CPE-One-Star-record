# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<ctype.h>
# pragma warning(disable: 4996)

/* 
	Rule: Tranlate the code that go right two keys
	Addition: turn every character to lower
*/
void translate(char*, char*);
int main()
{
	char decode[26] = {'d', 'm', 'b', 'g', 't','h','j','k','p','l',';','\'','.',',','[',']','e','y','f','u','o','n','r','v','i','c'};
	char str[1000] = { 0 };

	fgets(str, 1000, stdin);

	translate(str, decode);

	for (int i = 0; i < strlen(str); i++) {
		printf("%c", str[i]);
	}


	system("PAUSE");
	return 0;
}

void translate(char* str, char* decode)
{
	int i, j;
	for (i = 0; i < strlen(str); i++) {
		str[i] = tolower(str[i]);
		for (j = 0; j < 26; j++) {
			if (str[i] == decode[j]) {
				str[i] = j + 97;
				break;
			}
		}
	}
}