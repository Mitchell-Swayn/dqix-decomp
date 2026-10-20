#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadPResources(void*);
extern "C" void Graphics_SetMainOrSubBrightness(void*,int,int);
extern "C" void Menu_RemoveStoredBackgroundTask(int*);
extern "C" void Resource_DestroyAndResetSharedRecordState(char*);
extern "C" void Resource_InitializeSharedRecordState(char*,unsigned short,int);
extern "C" void ItemDetail_AllocateDisplayResources(void*,int);
// Original: arm9/ov023 @ 0x021DC9E8; symbol: ResetTasksAndReinitializeSharedRecord; size: 0xa0.
// Removes eight background tasks, resets shared record, merges mask774 and stores value48.
extern "C" void ItemDetail_ResetAndAllocateDisplay(char* p,int a,unsigned short id,int value,unsigned short mask){
 GameState_ReadPResources(_ZN9GameState11GetInstanceEv());Graphics_SetMainOrSubBrightness(p,-16,1);Menu_RemoveStoredBackgroundTask((int*)(p+0x734));
 for(int i=0;i<7;i++)Menu_RemoveStoredBackgroundTask((int*)(p+0x738)+i);
 Resource_DestroyAndResetSharedRecordState(p);Resource_InitializeSharedRecordState(p,id,*(signed char*)(p+0x77b));
 *(unsigned short*)(p+0x774)|=mask;ItemDetail_AllocateDisplayResources(p,a);*(int*)(p+0x48)=value;
}
