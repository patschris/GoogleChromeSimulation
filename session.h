#ifndef __session__
#define __session__

typedef struct SiteNode *SiteNodePtr;
typedef struct TabNode *TabNodePtr;
typedef struct InfoSession InfoSession;
typedef struct InfoSession *InfoSessionPtr;

void printSession(InfoSessionPtr);
InfoSessionPtr SessionNew (char *);
void SessionNewTab (InfoSessionPtr);
void SessionTabShow(TabNodePtr);
void SessionTabNext(InfoSessionPtr);
void SessionTabPrev(InfoSessionPtr);
void SessionTabMoveLeft(InfoSessionPtr);
void SessionTabMoveRight(InfoSessionPtr);
void SessionNewOpeningAddress(InfoSessionPtr, char *);
void SessionShowOpeningAddress(InfoSessionPtr);
void SessionSiteNext(InfoSessionPtr);
void SessionSitePrev(InfoSessionPtr);
void SessionSiteShow(SiteNodePtr);
void SessionTabClose(InfoSessionPtr *);
void SessionClose (InfoSessionPtr);
void SessionNewAddress (InfoSessionPtr, char *);
TabNodePtr GetFirstTab(InfoSessionPtr);
void SetFirstTab(InfoSessionPtr, TabNodePtr);
TabNodePtr GetLastTab (InfoSessionPtr);
void SetLastTab(InfoSessionPtr, TabNodePtr);
TabNodePtr GetCurrTab (InfoSessionPtr);
void SetCurrTab(InfoSessionPtr, TabNodePtr);

#endif
