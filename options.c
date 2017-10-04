#include <stdio.h>
#include <string.h>

/* Possible options */
void printOptions() { 
	printf("\nPlease type one of the following options:\n");
	printf("1) SessionNew\n");
	printf("2) SessionNewTab\n");
	printf ("3) SessionTabShow\n");
	printf ("4) SessionTabNext\n");
	printf ("5) SessionTabPrev\n");
	printf ("6) SessionTabMoveLeft\n");
	printf ("7) SessionTabMoveRight\n");
	printf ("8) SessionNewOpeningAddress\n");
	printf ("9) SessionShowOpeningAddress\n");
	printf ("10) SessionSiteNext\n");
	printf ("11) SessionSitePrev\n");
	printf ("12) SessionSiteShow\n");
	printf ("13) SessionTabClose\n");
	printf ("14) SessionClose\n");
	printf ("15) SessionNewAddress\n");
	printf("16) Exit\n\n");
}


int chooseFunction (char *buf) {
	if (strcmp(buf,"SessionNew")==0) return 0;
	else if (strcmp(buf,"SessionNewTab")==0) return 1;
	else if (strcmp(buf,"SessionTabShow")==0) return 2;
	else if (strcmp(buf,"SessionTabNext")==0) return 3;
	else if (strcmp(buf,"SessionTabPrev")==0) return 4;
	else if (strcmp(buf,"SessionTabMoveLeft")==0) return 5;
	else if (strcmp(buf,"SessionTabMoveRight")==0) return 6;
	else if (strcmp(buf,"SessionNewOpeningAddress")==0) return 7;
	else if (strcmp(buf,"SessionShowOpeningAddress")==0) return 8;
	else if (strcmp(buf,"SessionSiteNext")==0) return 9;
	else if (strcmp(buf,"SessionSitePrev")==0) return 10;
	else if (strcmp(buf,"SessionSiteShow")==0) return 11;
	else if (strcmp(buf,"SessionTabClose")==0) return 12;
	else if (strcmp(buf,"SessionClose")==0) return 13;
	else if (strcmp(buf,"SessionNewAddress")==0) return 14;
	else if (strcmp(buf,"Exit")==0) return 15;
	else return 16;
}
