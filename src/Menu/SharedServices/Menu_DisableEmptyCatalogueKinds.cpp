#include <globaldefs.h>
ARM
struct Object{virtual void A0();virtual void A1();virtual void A2();virtual void A3();virtual void A4();virtual void A5();virtual void A6();virtual void A7();virtual void A8();virtual void A9();virtual void A10();virtual void A11();virtual void A12();virtual void A13();virtual void A14();virtual void A15();virtual void A16();virtual void A17();virtual void A18();virtual void A19();virtual void A20();virtual void A21();virtual void A22();virtual void A23();virtual void A24();virtual void A25();virtual void A26();virtual void A27();virtual void A28();virtual void A29();virtual void A30();virtual void A31();virtual void A32();virtual void A33();virtual void A34();virtual void A35();virtual void A36();virtual void A37();virtual void A38();virtual void A39();virtual void A40();virtual void A41();virtual void A42();virtual void A43();virtual void A44();virtual void A45();virtual void A46();virtual void A47();virtual void A48();virtual void A49();virtual void A50();virtual void A51();virtual void A52();virtual void A53();virtual void A54();virtual void A55();virtual void A56();virtual void A57();virtual void A58();virtual void* Call();};
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*,int);
extern "C" int MenuRecord_GetType(void*);
extern "C" int Menu_CountEnabledCatalogueEntriesByCategory(void*,int,int,int);
extern "C" void Menu_SetKeyedControlMode(void*,unsigned short,int);
// Original: arm9/ov004 @ 0x02154E64; symbol: ClearSevenAbsentDescriptorKeys; size: 0xb8.
extern "C" int Menu_DisableEmptyCatalogueKinds(void* self) {
 void* object=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(self),57);if(!object)return 0;if(MenuRecord_GetType(object)!=18)return 0;
 void* descriptor=((Object*)object)->Call();if(!object)return 0;
 unsigned short key=26;for(short i=1;i<=7;key++,i++)if(!Menu_CountEnabledCatalogueEntriesByCategory(descriptor,-1,i,-1))Menu_SetKeyedControlMode(self,key,0);return 0;
}
