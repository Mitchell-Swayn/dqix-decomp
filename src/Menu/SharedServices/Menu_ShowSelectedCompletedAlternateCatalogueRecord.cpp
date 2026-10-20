#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" char* Menu_GetSelectedAlternateCatalogueRecord(void*);
extern "C" unsigned char* GameState_GetSerializedProgressState();
extern "C" unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
extern "C" void MenuBackground_SelectStateRecord(void*,int);
// Original: arm9/ov004 @ 0x021552B8; symbol: ForwardValidatedAlternateRecordValue; size: 0x94.
// Finds type16 entry2E and forwards selected signed record value when its packed index bit is enabled.
extern "C" int Menu_ShowSelectedCompletedAlternateCatalogueRecord(void* p){
 void* entry=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(p),0x2e);if(!entry)return 0;if(MenuRecord_GetType(entry)!=16)return 0;
 char* r=Menu_GetSelectedAlternateCatalogueRecord(p);int value=-1;
 if(r){unsigned flags=*(unsigned*)(r+12);value=*(short*)(r+24);int index=(unsigned short)((flags<<9)>>21);
 if(index>0){unsigned char* global=GameState_GetSerializedProgressState();if(!BitArray_ReadNonnegativeIndexMask(global,global+0x8c,index+0xc76))value=-1;}}
 MenuBackground_SelectStateRecord(entry,value);return 0;
}
