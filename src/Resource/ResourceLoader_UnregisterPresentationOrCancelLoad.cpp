#include <globaldefs.h>
struct Object{unsigned pad[2];int index;unsigned unused;int state;};extern "C" void BackgroundLoader_RemoveTaskAndClearLoadedPointer(Object*);extern "C" void* Object_GetGlobalSixteenEntryDisplayState(Object*);extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(void*,int);
// Original: arm9/main @ 0x020DBEDC; symbol: func_020dbedc; size: 0x3C.
extern "C" ARM void ResourceLoader_UnregisterPresentationOrCancelLoad(Object* p){if(p->state==1){BackgroundLoader_RemoveTaskAndClearLoadedPointer(p);return;}if(p->state!=2)return;void* object=Object_GetGlobalSixteenEntryDisplayState(p);RemoveMatchingNodeAndResetMatchingObjectSlots(object,p->index);p->state=0;}
