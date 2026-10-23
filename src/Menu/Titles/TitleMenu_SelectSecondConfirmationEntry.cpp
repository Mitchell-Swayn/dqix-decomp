#include <globaldefs.h>
struct State;
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void Menu_SetSelectedGridRow(void*,unsigned);
// Original: arm9/ov004 @ 0x0216E5F4; symbol: func_ov004_0216e5f4; size: 0x44.
// Selects row one of the confirmation grid when the keyed record has grid type.
extern "C" int TitleMenu_SelectSecondConfirmationEntry(State* self){
 void* record=MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),0x12d);
 if(!record)return 0;
 if(MenuRecord_GetType(record)!=7)return 0;
 Menu_SetSelectedGridRow(record,1);
 return 0;
}
