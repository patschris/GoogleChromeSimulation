#ifndef __siteList__
#define __siteList__

#include "session.h"

SiteNodePtr createNewSiteNode();
void InsertNewSite (SiteNodePtr *, SiteNodePtr);
void DeleteLastSite (SiteNodePtr *);
void DestroySiteList (SiteNodePtr *);
void DeleteAfterNode (SiteNodePtr *, SiteNodePtr);
SiteNodePtr GetPrevSite (SiteNodePtr);
void SetPrevSite (SiteNodePtr, SiteNodePtr);
SiteNodePtr GetNextSite (SiteNodePtr);
void SetNextSite (SiteNodePtr, SiteNodePtr);
TabNodePtr GetUpTab (SiteNodePtr);
void SetUpTab (SiteNodePtr, TabNodePtr);
void setAddress (SiteNodePtr, char *);
char * GetAddress(SiteNodePtr);

#endif
