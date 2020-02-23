# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<ctype.h>
# include<math.h>
# pragma warning(disable: 4996)

int main()
{
	char num[1000] = { 0 };
	int digitSum = -1;
	int maxdigit = -1;

	while (scanf("%s", num)!=EOF) {
		digitSum = 0;
		maxdigit = -1;

		for (int i = 0; i < strlen(num); i++) {
			
			if (num[i] >= 'A' && num[i] <= 'Z')
				num[i] = num[i] - 'A' + 10;
			else if (num[i] >= 'a' && num[i] <= 'z')
				num[i] = num[i] - 'a' + 36;
			else if (num[i] > '0' && num[i] <= '9')
				num[i] = num[i] - '0';
			else
				continue;
			digitSum += num[i];
			maxdigit = num[i] > maxdigit ? num[i] : maxdigit;
		}

		int devided = 1;
		for (int i = maxdigit; i < 62; i++) {
			if (maxdigit == -1) {
				printf("%d\n", 2);
				devided = 0;
				break;
			}
			else if (digitSum % i == 0) {
				printf("%d\n", i + 1);
				devided = 0;
				break;
			}
		}
		if (devided) {
			printf("such number is impossible!\n");
		}
	}
	system("PAUSE");
	return 0;
}
