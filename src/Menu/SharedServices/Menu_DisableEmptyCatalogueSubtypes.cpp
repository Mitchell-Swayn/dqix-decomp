#include <globaldefs.h>
ARM
class Entry {public:
virtual void Slot0();
virtual void Slot1();
virtual void Slot2();
virtual void Slot3();
virtual void Slot4();
virtual void Slot5();
virtual void Slot6();
virtual void Slot7();
virtual void Slot8();
virtual void Slot9();
virtual void Slot10();
virtual void Slot11();
virtual void Slot12();
virtual void Slot13();
virtual void Slot14();
virtual void Slot15();
virtual void Slot16();
virtual void Slot17();
virtual void Slot18();
virtual void Slot19();
virtual void Slot20();
virtual void Slot21();
virtual void Slot22();
virtual void Slot23();
virtual void Slot24();
virtual void Slot25();
virtual void Slot26();
virtual void Slot27();
virtual void Slot28();
virtual void Slot29();
virtual void Slot30();
virtual void Slot31();
virtual void Slot32();
virtual void Slot33();
virtual void Slot34();
virtual void Slot35();
virtual void Slot36();
virtual void Slot37();
virtual void Slot38();
virtual void Slot39();
virtual void Slot40();
virtual void Slot41();
virtual void Slot42();
virtual void Slot43();
virtual void Slot44();
virtual void Slot45();
virtual void Slot46();
virtual void Slot47();
virtual void Slot48();
virtual void Slot49();
virtual void Slot50();
virtual void Slot51();
virtual void Slot52();
virtual void Slot53();
virtual void Slot54();
virtual void Slot55();
virtual void Slot56();
virtual void Slot57();
virtual void Slot58();
virtual void* GetSource();};
extern "C" {void* Menu_GetDisplayRecordRegistry(void*);void* MenuRecordList_LocateByKey(void*,unsigned short);unsigned MenuRecord_GetType(void*);int Menu_CountEnabledCatalogueEntriesByCategory(void*,int,int,int);void Menu_SetKeyedControlMode(void*,unsigned,int);}
// Original: arm9/ov004 @ 0x02154DA8; symbol: ClearTwelveUnavailableEntryFlags; size: 0xbc.
// Tests twelve virtual source entries and clears keys26-37 when unavailable.
extern "C" int Menu_DisableEmptyCatalogueSubtypes(void* self){void* entry=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),57);if(!entry)return 0;if(MenuRecord_GetType(entry)!=18)return 0;void* source=((Entry*)entry)->GetSource();if(!entry)return 0;unsigned short key=26;for(short i=0;i<=11;++i){if(!Menu_CountEnabledCatalogueEntriesByCategory(source,-1,0,i))Menu_SetKeyedControlMode(self,key,0);++key;}return 0;}
