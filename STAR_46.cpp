# include<stdio.h>
# include<stdlib.h>
#pragma warning(disable: 4996)

int main()
{
	int cases = 0;
	scanf("%d", &cases);
	getchar();
	while (cases) {
		int finger[10] = { 0 };// record the press time
		char tones[15] = "cdefgabCDEFGAB";// index
		int code[14][10] = { 0,1,1,1,0,0,1,1,1,1//c
							,0,1,1,1,0,0,1,1,1,0//d
							,0,1,1,1,0,0,1,1,0,0//e
							,0,1,1,1,0,0,1,0,0,0//f
							,0,1,1,1,0,0,0,0,0,0//g
							,0,1,1,0,0,0,0,0,0,0//a
							,0,1,0,0,0,0,0,0,0,0//b
							,0,0,1,0,0,0,0,0,0,0//C
							,1,1,1,1,0,0,1,1,1,0//D
							,1,1,1,1,0,0,1,1,0,0//E
							,1,1,1,1,0,0,1,0,0,0//F
							,1,1,1,1,0,0,0,0,0,0//G
							,1,1,1,0,0,0,0,0,0,0//A
							,1,1,0,0,0,0,0,0,0,0 };//B
		char tone = 0;// collect the song tones
		int temp[10] = { 0 };// record the previous tone
		while (tone = getchar()) {
			if (tone == '\n')// stop when '\n'
				break;
			for (int i = 0; i < 15; i++) {// we have 15 tones(codes)
				if (tone == tones[i]) {// match the tone
					for (int j = 0; j < 10; j++) {
						/* the most important part*/
						/* 
							rule: press on(1)
								  unpress (0)
								  Action part:
										unpressing: 1 - 0 == ( 1)
										holding   : 1 - 1 == ( 0)
										pressing  : 0 - 1 == (-1)
						*/
						finger[j] += (code[i][j] - temp[j]) > 0 ? 1 : 0;
						temp[j] = code[i][j];// recording the previous code
					}
				}
			}
		}
		
		for (int i = 0; i < 10; i++) {
			if (i) {
				printf(" ");
			}
			printf("%d", finger[i]);
		}
		printf("\n");
		cases--;
	}
	system("PAUSE");
	return 0;
}