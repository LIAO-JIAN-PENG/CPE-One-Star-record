# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<math.h>
# define R 6440 // the radius of the earth
# define pi 3.141592653589793238 // long is for insurance
# pragma warning(disable: 4996)

int main()
{
	double S = 0, D = 0;// satellite to groud, degree
	char deg[10] = { 0 };// degree or minute
	while (scanf("%lf %lf %s", &S, &D, deg) != EOF) {
		double r = R + S;// real radius from earth to satellite

		if (strcmp(deg, "min") == 0) {
			D /= 60;
		}
		while (D >= 360) {// solve over 360 degrees
			D -= 360;
		}
		if (D > 180) {// take the compliment of the over 180 degrees
			D = 360 - D;
		}

		double chord = 0, arc = 0;
		double rad = 2*pi * (D / 360);// turn to rad system
		chord = r * sqrt(2 - 2 * cos(rad));// c^2 = a^2 + b^2 - 2ab*cos(theta)
		arc = r * rad;// r * theta

		printf("%lf %lf\n", arc, chord);
	}
	system("PAUSE");
	return 0;
}