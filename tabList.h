#ifndef __tabList__
#define __tabList__

#include "session.h"

TabNodePtr createNewTabNode ();
void InsertNewTab (TabNodePtr *, TabNodePtr);
void DeleteLastTab (TabNodePtr *);
void DestroyTabList (TabNodePtr *);
TabNodePtr FindNextOfGivenTab(TabNodePtr , TabNodePtr);
TabNodePtr FindPrevOfGivenTab(TabNodePtr, TabNodePtr);
void DeleteByNode (TabNodePtr *, TabNodePtr, InfoSessionPtr *);
TabNodePtr GetPrevTab (TabNodePtr);
void SetPrevTab (TabNodePtr,TabNodePtr);
TabNodePtr GetNextTab (TabNodePtr);
void SetNextTab (TabNodePtr,TabNodePtr);
SiteNodePtr GetFirstSite (TabNodePtr);
void SetFirstSite (TabNodePtr, SiteNodePtr);
SiteNodePtr GetCurrSite (TabNodePtr);
void SetCurrSite (TabNodePtr, SiteNodePtr);

#endif
