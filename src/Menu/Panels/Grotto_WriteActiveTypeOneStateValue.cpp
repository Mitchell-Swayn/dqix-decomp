#include <globaldefs.h>
ARM
struct GameResources;struct E;
extern "C" void* Zone3D_GetMainInstance();
extern "C" int _Z12IsGrottoZonei(int);
extern "C" int LinkedList_ContainsNodeByIdentity(E**,E*);
extern "C" unsigned char* _ZN17ActiveGrottoClass15GetDetailedDataEv(void*);
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" void Script_WriteIntegerReferenceOutput(void*,int);
struct Buffer {int pad[3];unsigned value:7;unsigned rest:25;unsigned char remaining[0xa0];};
// Original: arm9/ov023 @ 0x021EAEA0; symbol: func_ov023_021eaea0; size: 0xB0.
extern "C" int Grotto_WriteActiveTypeOneStateValue(void* output){
 Buffer buffer;
 int value=0;
 unsigned char* resources=(unsigned char*)GameResources_GetInstance();
 E** list;
 E* node=*(E**)(resources+0x3718);
 list=*(E***)(resources+0x36fc);
 unsigned char* embedded=(unsigned char*)FieldBattle_GetEncounterRequest(node);
 if(LinkedList_ContainsNodeByIdentity(list,node)){
 unsigned char* zone=(unsigned char*)Zone3D_GetMainInstance();
 unsigned char* details=_ZN17ActiveGrottoClass15GetDetailedDataEv(zone+0x23ec);
 if(embedded[0x24] && _Z12IsGrottoZonei(*(unsigned short*)zone) && details && details[1]==1){
 GameState_CopyStatisticsRecord(&buffer);
 value=buffer.value;
 }
 }
 Script_WriteIntegerReferenceOutput(output,value);
 return 1;
}
