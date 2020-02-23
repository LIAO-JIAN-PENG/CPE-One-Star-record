# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)


struct Point {
	double x;
	double y;
};
int main()
{
	Point p[4] = { 0 };
	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y, &p[3].x, &p[3].y) != EOF) {
		int ep1, ep2;// endpoint
		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < 4; j++) {
				if (p[i].x == p[j].x && p[i].y == p[j].y) {
					ep1 = i;
					ep2 = j;
					break;
				}
			}
		}
		p[3].x = p[1 - ep1].x + p[5 - ep2].x - p[ep1].x;
		p[3].y = p[1 - ep1].y + p[5 - ep2].y - p[ep1].y;
		printf("%.3lf %.3lf\n", p[3]);
	}
	system("PAUSE");
	return 0;
}