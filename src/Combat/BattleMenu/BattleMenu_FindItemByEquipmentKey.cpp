#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned ZoneState2754_FindPrimaryRecordByKey(...);
extern "C" unsigned GameState_GetObjectWithFlag100(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
// Original data: arm9/ov000 @ 0x02183388; symbol: data_ov000_02183388.
// Identical equipment-slot order used independently by BattleMenu_FindItemByEquipmentKey to search equipped records by key.
// Values (uint8_t[8]): {8, 9, 7, 0, 5, 1, 6, 10}.
extern "C" unsigned char BattleMenu_EquipmentLookupSlotOrder[];
// Original: arm9/ov000 @ 0x02171d90; symbol: FindPositivePrimaryRecordByEquipmentKey.
struct RecordKind{unsigned kind:4,unused:28;};
extern "C" void* BattleMenu_FindItemByEquipmentKey(char* p,int key){if(key<0)return 0;char* object=(char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),U(p,0x4c));if(object){struct Bytes{unsigned char values[8];};Bytes local=*(Bytes*)BattleMenu_EquipmentLookupSlotOrder;for(unsigned char i=0;i<8;i++){char* entry=(char*)U(object,0x150)+0x194+local.values[i]*32;if(entry){int value=*(short*)(entry+0x18);if(value>0){unsigned kind=((RecordKind*)(entry+8))->kind;unsigned valid=kind>=0&&kind<=7;if(valid!=0){if(value==key)return entry;}}}}}return (void*)ZoneState2754_FindPrimaryRecordByKey(U(p,0),key);}
