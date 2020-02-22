# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<ctype.h>
# pragma warning(disable: 4996)

/* 
	There will be n as lines
	And the format is(country woman's name)
	Count the women in different country
*/

struct woman {
	/* We record the women's country and number of them*/
	char country[100];
	int count;
};

int countryCount = 0;
void sort(woman*, int);
void getCountry(char*);
void recordCountry(char*, woman*);

int main()
{
	FILE *fptr = fopen("ans.txt", "w+");
	int lines = 0;
	char names[100] = { 0 };
	woman countries[2000] = { 0 };
	
	/* The number of women's names*/
	scanf("%d\n", &lines);

	while (lines) {
		fgets(names, 100, stdin);
		getCountry(names);// After that we get the country of this woman

		recordCountry(names, countries);// record the woman's imformation and solving the same country
		lines--;
	}
	
	/*sorting*/
	sort(countries, countryCount + 1);

	int i = 0;
	while (countries[i].count != 0) {
		printf("%s %d\n", countries[i].country, countries[i].count);
		fprintf(fptr, "%s %d\n", countries[i].country, countries[i].count);
		i++;
	}
	fclose(fptr);
	system("PAUSE");
	return 0;
}

void getCountry(char* name)
{
	/*
		Get rid of the rest of the name except the country
		Put '\0' in front of the name
	*/
	int i = 0;
	while (!isalpha(name[i])) {
		i++;
	}

	int start = 0;
	if (i) {
		start = i;
	}
	while (name[i] != ' ' && name[i] != '\0') {
		i++;
	}
	name[i] = '\0';
	if (start) {
		strcpy(name, &name[start]);
	}
}

void recordCountry(char* country, woman* record)
{
	/* Process the same country in the record and add one */
	int i = 0;
	while (record[i].count != 0) {
		if (strcmp(country, record[i].country) == 0) {
			/* existed country*/
			record[i].count++;
			return;
		}

		i++;
	}

	countryCount = i;
	/* new country*/
	record[i].count = 1;
	strcpy(record[i].country, country);
}

void sort(woman* record, int count)
{
	int i, j;
	for (i = 0; i < count; i++) {
		for (j = i + 1; j < count; j++) {
			for (int chr = 0; chr < strlen(record[i].country) || chr < strlen(record[i].country); chr++) {
				if (record[i].country[chr] > record[j].country[chr]) {
					woman temp = record[i];
					record[i] = record[j];
					record[j] = temp;
					break;
				}
				else if (record[i].country[chr] < record[j].country[chr]) {
					break;
				}
			}
		}
	}
}