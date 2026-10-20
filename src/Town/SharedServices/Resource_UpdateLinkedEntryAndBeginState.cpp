#include <globaldefs.h>
ARM
extern "C" char* GameResources_GetInstance();
extern "C" void Field_AdvanceOverlayThirtyOneRequest(void*,void*);
// Original: arm9/ov003 @ 0x02171CF8; symbol: Resource_UpdateLinkedEntryAndBeginState; size: 0x7c.
// Updates the linked resource and starts state bytes when resource flag 4494 is clear.
extern "C" void Resource_UpdateLinkedEntryAndBeginState(char* self) {
 char* resources=GameResources_GetInstance();
 char* entry=*(char**)(resources+0x3b48);
 Field_AdvanceOverlayThirtyOneRequest(entry,*(void**)(resources+0x36fc));
 if (*(int*)(resources+0x4494)) return;
 if (*(unsigned char*)(entry+0x28)) {
 *(unsigned char*)(self+0x730)&=~2;
 *(unsigned char*)(self+0x733)=1;
 }
 *(int*)(GameResources_GetInstance()+0x4494)=1;
 *self=0; self[0x731]=2; self[0x732]=3;
}
