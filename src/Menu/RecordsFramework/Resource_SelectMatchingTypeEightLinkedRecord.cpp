#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" char* Util_AdvanceLinkedPointer(void*,int);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" unsigned MenuRecord_GetKey(void*);
extern "C" char* MenuRecord_GetNext(void*);
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*,void*);
// Original: arm9/ov023 @ 0x021F88B8; symbol: Resource_SelectMatchingTypeEightLinkedRecord; size: 0x8c.
// Sets selection bit only on matching type-eight list entry with equal group halfword, then dispatches ready record.
extern "C" void Resource_SelectMatchingTypeEightLinkedRecord(unsigned short* self,void* context,int selected) {
 char* node=Util_AdvanceLinkedPointer(Menu_GetDisplayRecordRegistry(context),0);
 while(node){if(MenuRecord_GetType(node)==8 && *(unsigned short*)(node+0x34)==self[3]) {
 if(selected==MenuRecord_GetKey(node))*(unsigned char*)(node+0x45)=(*(unsigned char*)(node+0x45)&~1)|1;
 else *(unsigned char*)(node+0x45)&=~1;
 }node=MenuRecord_GetNext(node);}
 MenuTextCanvas_RefreshConfiguredFrameAndContents(self,context);
}
