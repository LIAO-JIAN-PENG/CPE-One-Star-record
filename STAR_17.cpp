# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

/*
	Rule: 
	Start number's the consecutive sum lower than the endSum
*/

int main()
{
	long long start = 0;
	long long endSum = 0;
	long long temp = 0;

	while (scanf("%lld %lld", &start, &endSum) != EOF) {
		temp = start;
		while (start < endSum) {
			temp++;
			start += temp;
		}
		printf("%lld\n", temp);
	}
	system("PAUSE");
	return 0;
}