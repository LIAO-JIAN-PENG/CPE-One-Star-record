# include<stdio.h>
# include<stdlib.h>
# pragma warning(disable: 4996)

struct point {
	int x;
	int y;
	int direct;
};

int checkRecord(point*, point, int);
int main()
{
	int xbound, ybound;
	char startDirect = 0;
	char O[4] = { 'N', 'E', 'S', 'W' };// Orientation: {0, 1, 2, 3} (%4)
	point start = { 0 };
	int rcount = 0;// record count
	point record[100] = { 0 };// record the places

	scanf("%d %d", &xbound, &ybound);
	while (scanf("%d %d %c\n", &start.x, &start.y, &startDirect)!=EOF) {

		char command = 0;
		int out = 0;// out of bound
		point fall;

		/* start point input*/
		for (int i = 0; i < 4; i++) {
			if (startDirect == O[i]) {
				start.direct = i;
				break;
			}
		}
		
		/* Command input (command: direct & move)*/
		while (command = getchar()) {
			/* save for insureance */
			point temp = { start.x, start.y, start.direct };
			/* end of input */
			if (command == '\n')
				break;
			/* command process*/
			else if (command == 'R') {
				start.direct++;
			}
			else if (command == 'L') {
				start.direct += 3;// prevent negative number
			}
			else if (command == 'F') {
				/*check direction*/
				switch (start.direct) {
				case 0: start.y++; break;
				case 1: start.x++; break;
				case 2: start.y--; break;
				case 3: start.x--; break;
				}
			}
			start.direct %= 4;// direct loop

			if ((start.x > xbound || start.x < 0 || start.y > ybound || start.y < 0) && out == 0){
				/* record fall position */
				fall = temp;
				/* checkRecord is checking there is a record before or not*/
				if (checkRecord(record, fall, rcount)) {
					/* ignore the command */
					out = 0;
					start = temp;
				}
				else {
					/* out and record */
					out = 1;
					record[rcount] = fall;
					rcount++;
				}
			}
		}

		if (out) {
			printf("%d %d %c LOST\n", fall.x, fall.y, O[fall.direct]);
		}
		else {
			printf("%d %d %c\n", start.x, start.y, O[start.direct]);
		}
	}
	system("PAUSE");
	return 0;
}

int checkRecord(point* record, point fall, int rcount)
{
	for (int i = 0; i < rcount; i++) {
		if (fall.x == record[i].x && fall.y == record[i].y) {
			return 1;
		}
	}
	return 0;
}