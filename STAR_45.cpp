# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# pragma warning(disable: 4996)

void north(int*);
void south(int*);
void east(int*);
void west(int*);

int main()
{
	int step = 0;
	while (scanf("%d", &step) != EOF) {
		int dice[6] = { 1,2,4,3,5,6 };

		if (step == 0)
			break;
		char command[15] = { 0 };
		while (step) {
			scanf("%s", command);

			if (strcmp(command, "north") == 0) {
				north(dice);
			}
			else if (strcmp(command, "south") == 0) {
				south(dice);
			}
			else if (strcmp(command, "west") == 0) {
				west(dice);
			}
			else if (strcmp(command, "east") == 0) {
				east(dice);
			}

			step--;
		}
		printf("%d\n", dice[0]);
	}
	system("PAUSE");
	return 0;
}


void north(int* dice)
{
	dice[1] = dice[0];
	dice[0] = dice[4];
	dice[4] = 7 - dice[1];
	dice[5] = 7 - dice[0];
}
void south(int* dice)
{
	dice[4] = dice[0];
	dice[0] = dice[1];
	dice[1] = 7 - dice[4];
	dice[5] = 7 - dice[0];
}
void east(int* dice)
{
	dice[2] = dice[0];
	dice[0] = dice[3];
	dice[3] = 7 - dice[2];
	dice[5] = 7 - dice[0];
}
void west(int* dice)
{
	dice[3] = dice[0];
	dice[0] = dice[2];
	dice[2] = 7 - dice[3];
	dice[5] = 7 - dice[0];
}