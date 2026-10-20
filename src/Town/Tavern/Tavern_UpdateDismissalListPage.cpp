#include <globaldefs.h>
ARM
extern "C" {void Tavern_GetRosterCapacityAndFreeStoredSlots(void*,short*,short*);void* _ZN9GameState11GetInstanceEv();unsigned char* GameState_GetIndexList(void*);void Tavern_PopulateStoredCharacterDismissalList(void*);}
// Original: arm9/ov003 @ 0x02166184; symbol: AdvanceWrappedPageFromDirectionFlags; size: 0x9c.
// Computes four-items-per-page count and wraps signed page using direction flags10/20.
extern "C" void Tavern_UpdateDismissalListPage(char* self){short a,b;Tavern_GetRosterCapacityAndFreeStoredSlots(self,&a,&b);int pages=(GameState_GetIndexList(_ZN9GameState11GetInstanceEv())[0x2c8c]+3)/4;unsigned flags=*(unsigned*)(self+0x45c);if(flags&16)++self[0x49f];else if(flags&32)--self[0x49f];if(pages<=(signed char)self[0x49f])self[0x49f]=0;else if((signed char)self[0x49f]<0)self[0x49f]=pages-1;Tavern_PopulateStoredCharacterDismissalList(self);}
