#include <globaldefs.h>
struct Entry{unsigned char type,index;char pad[38];Entry* next;};struct List{Entry* entries;unsigned short capacity,total;Entry* first;unsigned short count;};extern "C" Entry* ZoomDestination_FindLowestUnlockedUnindexedEntry(List*);
// Original: arm9/main @ 0x020A8304; symbol: func_020a8304; size: 0xAC.
extern "C" ARM void LinkedList_RebuildOrderedEntriesAndAssignByteIndices(List* p){for(int i=0;i<p->total;i++)p->entries[i].index=255;p->first=0;p->count=0;Entry* current=ZoomDestination_FindLowestUnlockedUnindexedEntry(p);if(!current)return;p->first=current;current->index=0;p->count++;unsigned char index=1;while(current){Entry* next=ZoomDestination_FindLowestUnlockedUnindexedEntry(p);current->next=next;if(next){next->index=index++;p->count++;}current=next;}}
