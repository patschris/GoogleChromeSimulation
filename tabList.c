#include <stdio.h>
#include <stdlib.h>
#include "siteList.h"
#include "tabList.h"

/* list's node of tabs */
struct TabNode {
	TabNodePtr PrevTab, NextTab; //next-previous tab
	SiteNodePtr FirstSite; // points to the first node of the site's list
	SiteNodePtr CurrSite; // points to the current node of the site's list
} TabNode; 


/* Creates new node for the tab's list */
TabNodePtr createNewTabNode() {
	 return ((TabNodePtr) malloc (sizeof(TabNode)));
}


/* Inserts new tab in the end of tab's list */
void InsertNewTab (TabNodePtr *first, TabNodePtr node) {
	if(*first == NULL) {
		*first = node;
		node -> NextTab = node;
		node -> PrevTab = node;
	}
	else {
		TabNodePtr last = *first;
		while (last -> NextTab != *first) last = last -> NextTab;
		last -> NextTab = node; 
		node -> PrevTab = last;
		node -> NextTab = *first;
		(*first) -> PrevTab= node;
	}
}


/* Deletes the last node of the tab's list */
void DeleteLastTab (TabNodePtr *first) { 
	TabNodePtr last = *first;
	while (last -> NextTab != *first) last = last -> NextTab;
	if (last != *first) {
		(*first) -> PrevTab = last -> PrevTab;
		last -> PrevTab -> NextTab = *first;
	}
	else {
		*first = NULL;
	}
	free(last);
}


/* DestroyS the tab's list by deleting everytime the last node */
void DestroyTabList (TabNodePtr *first) {
	while(*first != NULL) DeleteLastTab(first);
}


/* Returns the next tab of the given tab */
TabNodePtr FindNextOfGivenTab (TabNodePtr first, TabNodePtr tofind) {
	TabNodePtr temp = first;
	while(temp != tofind) temp = temp->NextTab;
	return temp->NextTab;
}


/* Returns the previous tab of the given tab */
TabNodePtr FindPrevOfGivenTab (TabNodePtr first, TabNodePtr tofind){
	TabNodePtr temp = first;
	while(temp != tofind) temp = temp->NextTab;
	return temp->PrevTab;
}


/* Destroys site's list of the given tab and deletes it  */
void DeleteByNode (TabNodePtr *first, TabNodePtr todel, InfoSessionPtr *isp) {
	TabNodePtr prev, next;
	TabNodePtr temp = *first;
	printf("I am going to delete tab (%p)\n", todel);
	while(temp != todel) temp = temp->NextTab;
	DestroySiteList(&(temp->FirstSite));
	if(temp == *first) {
		if(temp == temp->NextTab) { // last tab in session
			SessionClose(*isp);
			*isp = NULL;
			printf("This tab is also the last open tab. I am going to close the session\n");
		}
		else {
			prev = temp -> PrevTab;
			next = temp -> NextTab;
			prev -> NextTab = next;
			next -> PrevTab	= prev;		
			*first = temp->NextTab;
			printf("This tab is also the first tab\nFirst tab is now the next one(%p)\n", temp->NextTab);		
			SetFirstTab (*isp, temp->NextTab);
			SetCurrTab (*isp, temp->NextTab);
			free(temp);
			printSession(*isp);
		}
	}
	else { 
		if (temp->NextTab == *first) { // deleting last tab
			SetLastTab(*isp, temp->PrevTab); // set last tab as the previous of the former one
			printf("This tab is also the last tab\nLast tab is now the previous one(%p)\n",temp->PrevTab);		
		}
		prev = temp -> PrevTab;
		next = temp -> NextTab;
		prev->NextTab = next;
		next -> PrevTab = prev;
		SetCurrTab (*isp, next);
		free(temp);
		printSession(*isp);
	}		
}


/* Setters kai Getters for TabNode's field */
TabNodePtr GetPrevTab(TabNodePtr t){
	return t->PrevTab;
}

void SetPrevTab(TabNodePtr t,TabNodePtr tnp){
	t->PrevTab = tnp;
}

TabNodePtr GetNextTab (TabNodePtr t){
	return t->NextTab;
}

void SetNextTab(TabNodePtr t,TabNodePtr tnp){
	t->NextTab = tnp;
}

SiteNodePtr GetFirstSite (TabNodePtr s){
	return s->FirstSite;
} 

void SetFirstSite (TabNodePtr s, SiteNodePtr site){
	s->FirstSite = site;
}

SiteNodePtr GetCurrSite (TabNodePtr s){
	return s->CurrSite;
} 

void SetCurrSite (TabNodePtr s, SiteNodePtr site){
	s->CurrSite = site;
}
