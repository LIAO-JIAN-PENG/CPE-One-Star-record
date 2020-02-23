# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# pragma warning(disable: 4996)

double func(int, double, int);

/*
	Rule:
	ex: Probabilty is 1/6 as a dice
		2 people participate
		1P has 1/6 + (5/6)^2*(1/6) + (5/6)^4*(1/6) + ... probability to win
		2P has (5/6)*(1/6) + (5/6)^3*(1/6) + ... probability to win

		3 people participate
		1P has 1/6 + (5/6)^3*(1/6) + (5/6)^6*(1/6) + ... probability to win
		2P has (5/6)*(1/6) + (5/6)^4*(1/6) + ... probability to win
		3P has (5/6)^2*(1/6) + (5/6)^5*(1/6) + ... probability to win

		p: Probability, n: number of people, i: index of player
		Formula: (1-p)^(i-1) * p / (1 - (1-p)^n)
*/
int main()
{
	int cases = 0;
	double p = 0;// Probability
	int player = 0;
	int index = 0;

	scanf("%d", &cases);
	while (cases) {
		scanf("%d %lf %d", &player, &p, &index);
		double ans = func(player, p, index);
		printf("%.4lf\n", ans);
		cases--;
	}
	system("PAUSE");
	return 0;
}

double func(int n, double p, int i)
{
	//printf("n=%d\np=%lf\ni=%d\n", n, p, i);
	if ((1 - pow((1 - p), n) == 0)) {
		return 0;
	}
	return p * pow((1 - p), i - 1) / (1 - pow((1 - p), n));
}