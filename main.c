#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabList.h"
#include "options.h"

#define BUFSIZE 120
#define URLSIZE 120

int main (int argc, char *argv[]) {

	InfoSessionPtr MySession = NULL;
	char *buffer, str[URLSIZE];
	int opt;	
	buffer = (char*) malloc (BUFSIZE * sizeof(char));
	while (1) {
		printOptions();
		scanf("%s", buffer); // read what user types
		opt = chooseFunction(buffer); // find the code of the option	
		switch (opt) {
			case 0 : // SessionNew
				printf("\nPlease enter the default opening address: ");
				scanf("%s", str);
				MySession = SessionNew(str);
				break;
			case 1 : //SessionNewTab
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionNewTab(MySession);
				break;
			case 2 : //SessionTabShow
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionTabShow (GetCurrTab(MySession));
				break;
			case 3 : //SessionTabNext
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionTabNext(MySession);
				break;
			case 4 : //SessionTabPrev
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionTabPrev(MySession);
				break;
			case 5 : //SessionTabMoveLeft
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionTabMoveLeft(MySession);
				break;
			case 6 : //SessionTabMoveRight
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionTabMoveRight(MySession);
				break;
			case 7 : //SessionNewOpeningAddress
				if (MySession == NULL) 	{
					printf("There is no open session\n\n");
				}
				else {
					printf("\nPlease enter the new opening address: ");
					scanf("%s", str);
					SessionNewOpeningAddress(MySession , str);
				} 
				break;
			case 8 : //SessionShowOpeningAddress
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionShowOpeningAddress(MySession);
				break;
			case 9 : //SessionSiteNext
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionSiteNext(MySession);
				break;
			case 10 : //SessionSitePrev
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionSitePrev(MySession);
				break;
			case 11 : //SessionSiteShow
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionSiteShow(GetCurrSite(GetCurrTab(MySession)));
				break;
			case 12 : //SessionTabClose
				if (MySession == NULL) printf("There is no open session\n\n");
				else SessionTabClose(&MySession);
				break;
			case 13 : // SessionClose
				if (MySession == NULL) {
					printf("There is no open session\n\n");
				}
				else {
					printf("Closing session\n\n");
					SessionClose(MySession);
					MySession = NULL;
				}
				break;
			case 14 : // SessionNewAddress
				if (MySession == NULL) {
					printf("There is no open session\n\n");
				}
				else {
					printf("\nPlease enter the new address: ");
					scanf("%s", str);
					SessionNewAddress(MySession, str);
				}
				break;
			case 15 : // Exit 
				printf("Exiting program\n");
				if (MySession != NULL) SessionClose(MySession);
				free(buffer);
				return 0;
			case 16 : // Wrong input
				printf("Wrong input\n\n");
				break;
			default : // default case
				printf("Never should be here\n\n");
				return -1;
		}	
	}
	free(buffer);
	return 0;
}
