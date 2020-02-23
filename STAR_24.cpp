# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

int main()
{
	/*velocity & time*/
	/* print out the twice time distance*/
	int v = 0, t = 0;
	while (scanf("%d %d", &v, &t) != EOF) {
		printf("%d\n", v * 2 * t);
	}
	system("PAUSE");
	return 0;
}