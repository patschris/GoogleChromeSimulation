#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "siteList.h"
#include "tabList.h"

/* list's node of sites */
typedef struct SiteNode {
	SiteNodePtr PrevSite, NextSite; // previous-nexr site
	TabNodePtr UpTab; // site belongs to upTab
	char *Address; // site's address
} SiteNode;


/* Creates new node for the site's list */
SiteNodePtr createNewSiteNode() {
	return ((SiteNodePtr) malloc (sizeof(SiteNode)));
}


/* Inserts new site in the end of site's list */
void InsertNewSite (SiteNodePtr *first, SiteNodePtr newNode) { 
	if(*first == NULL) {
		*first = newNode;
		newNode -> NextSite = NULL;
		newNode -> PrevSite = NULL;
	}
	else {
		SiteNodePtr last = *first;
		while (last -> NextSite != NULL) last = last -> NextSite;
		last -> NextSite = newNode;
		newNode -> PrevSite = last;
		newNode -> NextSite = NULL;
	}
}


/* Deletes the last node of the site's list */
void DeleteLastSite (SiteNodePtr *first) {
	SiteNodePtr last = *first;
	while (last -> NextSite != NULL) last = last -> NextSite;
	if (last != *first) last -> PrevSite -> NextSite = NULL;
	else *first = NULL;
	free(last->Address);
	free(last);
}


/* Destroy the site's list by deleting everytime the last node */
void DestroySiteList (SiteNodePtr *first) {
	while(*first != NULL) DeleteLastSite(first);
}


/* Deletes every node after the given node */
void DeleteAfterNode (SiteNodePtr *first, SiteNodePtr site) {
	SiteNodePtr last = *first;
	while (last -> NextSite != NULL) last = last -> NextSite;
	while (last != site) {
		last = last ->PrevSite;
		free(last->NextSite->Address);
		free(last->NextSite);
	}
	site->NextSite = NULL;
}


/* Setters and Getters for SiteNode's list */
SiteNodePtr GetPrevSite(SiteNodePtr s){
	return s->PrevSite;
}


void SetPrevSite(SiteNodePtr s, SiteNodePtr ps){
	s->PrevSite = ps;
}


SiteNodePtr GetNextSite(SiteNodePtr s){
	return s->NextSite;
}


void SetNextSite(SiteNodePtr s, SiteNodePtr ns){
	s->NextSite = ns;
}


TabNodePtr GetUpTab(SiteNodePtr s){
	return s->UpTab;
}


void SetUpTab(SiteNodePtr s, TabNodePtr up){
	s->UpTab = up;
}


void setAddress (SiteNodePtr s, char *addr) {
	s-> Address = (char*) malloc((strlen(addr)+1)*sizeof(char));
	strcpy (s->Address, addr);
}


char * GetAddress(SiteNodePtr s){
	char * temp = (char *) malloc((strlen(s->Address) + 1)*sizeof(char));
	strcpy(temp,s->Address);
	return temp;
}
