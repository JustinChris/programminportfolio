#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

char funFact(){
	char info[7][500] = {
							{"Human eye can differentiate approximately 10 million different colors"},
							{"Eyes are made up of over 2 million working parts"},
							{"The world's most common eye color is brown"},
							{"Ommetaphobia is the fear of eyes"},
							{"Pirates wore earrings because they believed it improved their eyesight"},
							{"Your eyes are about 1 inch across and weigh about 0.25 ounce"},
						};
	int random;
	srand(time(0));
	random = rand() % 7;
	printf("%s\n",info[random]);

}

void timer(long long int calc, long long int minute) {
	system("cls");
	puts("===========================================");
	puts("                  Timer                    ");
	puts("          Take Care of Your Eyes           ");
	puts("===========================================");
	printf("Timer Set for %lld minutes interval\n",minute);
	printf("Timer On...");
	while (true) {
		Beep(750,800);
		Sleep(calc);
	}
}


int main() {
	puts("===========================================");
	puts("                  Timer                    ");
	puts("          Take Care of Your Eyes           ");
	puts("           By @justin_christians           ");
	puts("===========================================");
	puts("");
	puts("             ..,,;;;;;;,,,,");
	puts("       .,;'';;,..,;;;,,,,,.''';;,..");
	puts("    ,,''                    '';;;;,;''");
	puts("   ;'    ,;@@;'  ,@@;, @@, ';;;@@;,;';.");
	puts("  ''  ,;@@@@@'  ;@@@@; ''    ;;@@@@@;;;;");
	puts("     ;;@@@@@;    '''     .,,;;;@@@@@@@;;;");
	puts("    ;;@@@@@@;           , ';;;@@@@@@@@;;;.");
	puts("     '';@@@@@,.  ,   .   ',;;;@@@@@@;;;;;;");
	puts("        .   '';;;;;;;;;,;;;;@@@@@;;' ,.:;'");
	puts("          ''..,,     ''''    '  .,;'");
	puts("               ''''''::''''''''");
	puts("");
	puts("===========================================");
	puts("Did You Know ?");
	funFact();
	puts("===========================================");
	puts("What time interval do you want ?");
	
	long long int minute;
	long long int calculated;
	scanf("%lld",&minute);
	calculated = minute * 60000;
	timer(calculated,minute);
	
	return 0;
}
