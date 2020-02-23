# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

int	exchange(int);
int formula(int);

int main()
{
	int cola = 0;
	while (scanf("%d", &cola) != EOF) {
		//int result = exchange(cola);
		int result = formula(cola);
		printf("%d\n", result);
	}
	system("PAUSE");
	return 0;
}

int exchange(int bottle)
{
	int total = 0;

	while (bottle != 0) {
		if (bottle == 1) {
			total++; 
			break;
		}
		else if (bottle == 2) {
			total += 3;
			break;
		}

		total += (bottle / 3) * 3;
		bottle = (bottle / 3) + (bottle % 3);
	}
	return total;
}

int formula(int bottle)
{
	return int(bottle * 1.5);
}