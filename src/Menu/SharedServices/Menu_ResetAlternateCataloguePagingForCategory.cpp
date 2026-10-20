#include <globaldefs.h>
ARM
extern "C" int GameState_AppendValueAndSetNodeFlags(...);
extern "C" int GameState_ClearMaskFromKeyedEntry(...);
extern "C" int MenuRecord_GetType(...);
extern "C" int Menu_GetAlternateCatalogueCategoryFilters(...);
extern "C" int Menu_GetDisplayRecordRegistry(...);
extern "C" int Menu_CountEnabledAlternateCatalogueEntriesByCategory(...);
extern "C" int MenuTileGrid_SetCoordinatesByKey(...);
extern "C" int MenuRecordList_LocateByKey(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov004 @ 0x021555B0; symbol: UpdateKeyedEntryMasksFromScaledCoordinateCount.
extern "C" int Menu_ResetAlternateCataloguePagingForCategory(char*self){
short x,y,z;Menu_GetAlternateCatalogueCategoryFilters(self,&x,&y,&z);char*entry=C(MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),57));if(!entry)return 0;if(MenuRecord_GetType(entry)!=18)return 0;struct Object{virtual void V0();virtual void V1();virtual void V2();virtual void V3();virtual void V4();virtual void V5();virtual void V6();virtual void V7();virtual void V8();virtual void V9();virtual void V10();virtual void V11();virtual void V12();virtual void V13();virtual void V14();virtual void V15();virtual void V16();virtual void V17();virtual void V18();virtual void V19();virtual void V20();virtual void V21();virtual void V22();virtual void V23();virtual void V24();virtual void V25();virtual void V26();virtual void V27();virtual void V28();virtual void V29();virtual void V30();virtual void V31();virtual void V32();virtual void V33();virtual void V34();virtual void V35();virtual void V36();virtual void V37();virtual void V38();virtual void V39();virtual void V40();virtual void V41();virtual void V42();virtual void V43();virtual void V44();virtual void V45();virtual void V46();virtual void V47();virtual void V48();virtual void V49();virtual void V50();virtual void V51();virtual void V52();virtual void V53();virtual void V54();virtual void V55();virtual void V56();virtual void V57();virtual void V58();virtual char*Get();};char*object=((Object*)entry)->Get();if(!entry)return 0;int count=Menu_CountEnabledAlternateCatalogueEntriesByCategory(object,x,y,z);short chunks=(count+15)/16;if(!count){GameState_AppendValueAndSetNodeFlags(self,10,8);GameState_ClearMaskFromKeyedEntry(self,3,4);unsigned short key=26;for(unsigned short i=0;i<16;key++,i++)GameState_AppendValueAndSetNodeFlags(self,key,8);GameState_ClearMaskFromKeyedEntry(self,58,8);}else GameState_AppendValueAndSetNodeFlags(self,58,8);MenuTileGrid_SetCoordinatesByKey(self,(void*)44,0,chunks);return 0;
}
