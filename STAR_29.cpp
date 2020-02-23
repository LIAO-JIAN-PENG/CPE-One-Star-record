# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

/*base for output cheapest base(s)*/
void base(int[4][9], int);
/*
	Rule:
	10 8 12 13 15 13 13 16 9
	11 18 24 21 23 23 23 13 15
	17 33 21 23 27 26 27 19 4
	22 18 30 30 24 16 26 21 21 -> 36 characters' seals and thier peice chart	We need to find out the cheapest way to produce chartacters	ex: 14 => 10 (base 14)  '1' + '0' = 18 cents			  11 (base 13)  '1' + '1' = 16 cents			  12 (base 12)  ...			  ...
*/
int main()
{
	int cases = 0;
	int num = 0, prices[4][9] = {0};
	
	scanf("%d", &cases);

	for (int c = 1; cases ; c++) {

		int test = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 9; j++) {
				scanf("%d", &prices[i][j]);
			}
		}

		printf("Case %d:\n", c);
		scanf("%d", &test);// test cases
		while (test) {
			scanf("%d", &num);
			printf("Cheapest base(s) for number %d:", num);
			base(prices, num);
			printf("\n");
			test--;
		}
		
		cases--;
		if (cases)
			printf("\n");

	}
	system("PAUSE");
	return 0;
}

void base(int prices[4][9], int num)
{
	int base;
	int cost = 0, cheapest = 999999, costs[37] = {0};

	for (base = 2; base <= 36; base++) {
		int number = num;// save origin num
		cost = 0;

		for (int i = 0; number; i++) {
			cost += prices[0][number % base];// add on the price to spend
			number /= base;
		}
		costs[base] = cost;
		cheapest = (cheapest > cost) ? cost : cheapest;// find cheapest price
	}

	for (int i = 2; i <= 36; i++) {
		if (costs[i] == cheapest || num < 2) {
			printf(" %d", i);// find cheapest base
		}
	}
}