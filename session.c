#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "siteList.h"
#include "tabList.h"


struct InfoSession { // Session information
	TabNodePtr FirstTab; // First tab of the list
	TabNodePtr LastTab;  // Last tab of the list
	TabNodePtr CurrTab; // current tab
	TabNodePtr AuxTab;  // temporary to swap tabs
	char *OpeningAddress; // opening page
};


/* Prints session information */
void printSession (InfoSessionPtr isp) {
	printf("FirstTab : %p\n", isp->FirstTab);
	printf("LastTab : %p\n", isp->LastTab);
	printf("CurrTab : %p\n", isp->CurrTab);
}


/* Creates new session. The first tab opens the opening address */
InfoSessionPtr SessionNew (char *OpeningAddress) {
	TabNodePtr firstTab = NULL;
	SiteNodePtr firstSite = NULL; 
	InfoSessionPtr newses = (InfoSessionPtr)malloc(sizeof(InfoSession));
	TabNodePtr newtab = createNewTabNode();
	SiteNodePtr newsite = createNewSiteNode();
	setAddress(newsite, OpeningAddress);
	SetUpTab(newsite, newtab);
	SetFirstSite (newtab, newsite);
	SetCurrSite (newtab, newsite); 
	InsertNewTab (&firstTab, newtab);
	InsertNewSite (&firstSite, newsite);
	newses -> OpeningAddress = (char*) malloc((strlen(OpeningAddress)+1)*sizeof(char));
	strcpy (newses -> OpeningAddress, OpeningAddress);			
	newses -> FirstTab = firstTab;
	newses -> LastTab = firstTab;
	newses -> CurrTab = firstTab;
	newses -> AuxTab = NULL; 
	printf("New session created\nFirst tab created (%p)\nThe address of the first site of the first tab is : %s (%p)\n", firstTab, OpeningAddress, newsite);
	printSession(newses);	
	return newses;
}


/* Adds a new tab in the current session. Tab opens the default opening address. New tab is the current tab and the last tab as well */
void SessionNewTab (InfoSessionPtr Session) {
	TabNodePtr firstTab = Session->FirstTab;
	SiteNodePtr firstSite = NULL; 
	TabNodePtr newtab = createNewTabNode();
	SiteNodePtr newsite = createNewSiteNode();
	setAddress(newsite, Session->OpeningAddress);
	SetUpTab(newsite, newtab); 
	SetFirstSite(newtab, newsite); 
	SetCurrSite(newtab, newsite);
	InsertNewTab(&firstTab, newtab);
	InsertNewSite(&firstSite, newsite);
	Session -> CurrTab =  newtab;
	Session -> LastTab = newtab;
	printf("A new tab has created (%p)\nThis tab is the last and the current tab\nThe default opening site %s has opened in this tab\n",newtab, Session->OpeningAddress);
	printSession(Session);
}


/* Prints the address of the current site of the current tab */
void SessionTabShow (TabNodePtr tab) {
	if (tab != NULL){
		SiteNodePtr site = GetCurrSite(tab);
		if(site != NULL) {
			char *addr = GetAddress(site);
			printf("The address of current tab(%p) is: %s\n", tab, addr);
			free(addr);
		}
	}
}


/* Changes current tab. New current tab is the next of the former current tab */
void SessionTabNext (InfoSessionPtr isp) {
	TabNodePtr newcur = FindNextOfGivenTab (isp->FirstTab,isp->CurrTab);
	if (newcur == isp -> CurrTab) {
		printf("You have only one open tab\n");
	}
	else { 
		printf("Current tab changed(%p)\n", newcur);
		isp-> CurrTab = newcur;
	}
	printSession(isp);
}


/* Changes current tab. New current tab is the previous of the former current tab */
void SessionTabPrev(InfoSessionPtr isp) {
	TabNodePtr newcur = FindPrevOfGivenTab(isp->FirstTab,isp->CurrTab);
	if (newcur == isp -> CurrTab) {
		printf("You have only one open tab\n");
	}
	else { 
		isp-> CurrTab = newcur;
		printf("Current tab changed(%p)\n", newcur);
	}
	printSession(isp);
}


/* Swap the current tab with the one in the left of the current tab */
void SessionTabMoveLeft (InfoSessionPtr isp) {
	if (isp->CurrTab == isp->FirstTab) {
		printf("Cannot move left first tab\n\n");
	}
	else {
		isp->AuxTab = createNewTabNode(); // use AuxTab to swap tabs
		SetFirstSite(isp->AuxTab,GetFirstSite(isp->CurrTab));
		SetCurrSite(isp->AuxTab, GetCurrSite(isp->CurrTab)); 
		TabNodePtr prev = GetPrevTab(isp->CurrTab);
		SetFirstSite(isp->CurrTab,GetFirstSite(prev));	
		SetCurrSite(isp->CurrTab, GetCurrSite(prev));
    	SetFirstSite(prev,GetFirstSite(isp->AuxTab)); 	
		SetCurrSite(prev, GetCurrSite(isp->AuxTab));
		isp->CurrTab = prev;
		free(isp->AuxTab);
		printf("Current tab moved left (%p)\n", isp->CurrTab);
	}
	printSession(isp);
}


/* Swap the current tab with the one in the right of the current tab */
void SessionTabMoveRight (InfoSessionPtr isp) {
	if (isp->CurrTab == isp->LastTab) {
		printf("Cannot move right the last tab\n\n");
	}
	else {
		isp->AuxTab = createNewTabNode(); // use AuxTab to swap tabs
		SetFirstSite(isp->AuxTab,GetFirstSite(isp->CurrTab));	
		SetCurrSite(isp->AuxTab, GetCurrSite(isp->CurrTab)); 
		TabNodePtr next = GetNextTab(isp->CurrTab);
		SetFirstSite(isp->CurrTab,GetFirstSite(next));
		SetCurrSite(isp->CurrTab, GetCurrSite(next));
    	SetFirstSite(next,GetFirstSite(isp->AuxTab));	
		SetCurrSite(next , GetCurrSite(isp->AuxTab));
		isp->CurrTab = next;
		free(isp->AuxTab);
		printf("Current tab moved right (%p)\n", isp->CurrTab);
	}
	printSession(isp);
}


/* Changes the default opening address */
void SessionNewOpeningAddress (InfoSessionPtr isp ,char *s) {
	free(isp-> OpeningAddress);
	isp -> OpeningAddress = (char*) malloc((strlen(s)+1)*sizeof(char));
	strcpy (isp -> OpeningAddress, s);
	printf("Default opening address has changed\nNew opening address is : %s\n\n", isp->OpeningAddress);	
}


/* Prints the opening address */
void SessionShowOpeningAddress (InfoSessionPtr isp) {
	printf("The default Opening Address is : %s\n",isp->OpeningAddress);
}


/* New current site of the current tab is the next of the former one */
void SessionSiteNext (InfoSessionPtr isp) {
	SiteNodePtr cs = GetCurrSite(isp->CurrTab);
	SiteNodePtr csn = GetNextSite (cs);
	if(csn == NULL) { 
		printf("There is no next site in the current tab\n\n");
	}
	else {
		SetCurrSite (isp->CurrTab, csn);
		char *addr = GetAddress(csn);
		printf("New current site of the current tab: %s (%p)\n\n", addr, csn);
		free(addr);
	}
}


/* New current site of the current tab is the previous of the former one */
void SessionSitePrev (InfoSessionPtr isp) {
	SiteNodePtr cs = GetCurrSite(isp->CurrTab);
	SiteNodePtr csn = GetPrevSite (cs);
	if (csn == NULL) {
		printf("There is no previous site in the current tab\n\n");
	}
	else {
		SetCurrSite(isp->CurrTab, csn);
		char *addr = GetAddress(csn);
		printf("New current site : %s (%p)\n\n", addr, csn);
		free(addr);
	}
}


/* Prints the address of the current site */
void SessionSiteShow (SiteNodePtr s) {
	char *addr = GetAddress(s);
	printf("The address of the current site is: %s (%p)\n\n", addr, s);
	free(addr);
}


/* Deletes current tab */
void SessionTabClose (InfoSessionPtr *isp) {
	DeleteByNode (&((*isp)->FirstTab), (*isp)->CurrTab, isp);
}


/* Close the session (delete every tab and every site) */
void SessionClose (InfoSessionPtr isp) {
	if (isp == NULL) return;
	TabNodePtr tempTab = isp -> FirstTab;
	int time =0;
	while (tempTab != isp -> FirstTab || time == 0) {
		time++;		
		SiteNodePtr tempSite = GetFirstSite(tempTab);
		DestroySiteList(&tempSite);
		tempTab = GetNextTab (tempTab);
	}
	DestroyTabList (&(isp -> FirstTab));
	free(isp->OpeningAddress);
	free(isp);
	isp = NULL;
}


/* Deletes every site after the current site of the current tab. Inserts a new site after the last site of the list. This new site is the new current site */
void SessionNewAddress (InfoSessionPtr isp, char *newaddr) {
	SiteNodePtr firstsite = GetFirstSite(isp->CurrTab);	
	SiteNodePtr currsite = GetCurrSite(isp->CurrTab); 
	DeleteAfterNode(&firstsite, currsite);
	SiteNodePtr newsite = createNewSiteNode();
	setAddress(newsite, newaddr);
	SetUpTab(newsite, isp->CurrTab);
	InsertNewSite(&firstsite, newsite);
	SetCurrSite(isp->CurrTab, newsite);
	printf("New site added(%p) in the tab (%p)\nThe address of this site is: %s\n\n", newsite, isp->CurrTab, newaddr);
}


/* Getters & setters for InfoSession's field */

TabNodePtr GetFirstTab (InfoSessionPtr s) {
	return s->FirstTab;
}


void SetFirstTab (InfoSessionPtr s, TabNodePtr t) {
	s->FirstTab = t;
}


TabNodePtr GetLastTab (InfoSessionPtr s) {
	return s->LastTab;
}


void SetLastTab (InfoSessionPtr s, TabNodePtr t) {
	s->LastTab = t;
}


TabNodePtr GetCurrTab (InfoSessionPtr s) {
	return s->CurrTab;
}


void SetCurrTab (InfoSessionPtr s, TabNodePtr t) {
	s->CurrTab = t;
}
