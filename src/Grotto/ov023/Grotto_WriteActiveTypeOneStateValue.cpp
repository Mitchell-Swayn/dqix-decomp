#include <globaldefs.h>
ARM
struct GameResources;struct E;
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" int _Z12IsGrottoZonei(int);
extern "C" int LinkedList_ContainsNodeByIdentity(E**,E*);
extern "C" unsigned char* _ZN17ActiveGrottoClass15GetDetailedDataEv(void*);
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* OV017_GetEmbeddedField1C(void*);
extern "C" void SetNestedSecondWordForTypeThree(void*,int);
struct Buffer {int pad[3];unsigned value:7;unsigned rest:25;unsigned char remaining[0xa0];};
// Original: arm9/ov023 @ 0x021EAEA0; symbol: func_ov023_021eaea0; size: 0xB0.
extern "C" int Grotto_WriteActiveTypeOneStateValue(void* output){
 Buffer buffer;
 int value=0;
 unsigned char* resources=(unsigned char*)GameResources_GetInstance();
 E** list;
 E* node=*(E**)(resources+0x3718);
 list=*(E***)(resources+0x36fc);
 unsigned char* embedded=(unsigned char*)OV017_GetEmbeddedField1C(node);
 if(LinkedList_ContainsNodeByIdentity(list,node)){
 unsigned char* zone=(unsigned char*)ReadGlobalValueAt020FB3F0();
 unsigned char* details=_ZN17ActiveGrottoClass15GetDetailedDataEv(zone+0x23ec);
 if(embedded[0x24] && _Z12IsGrottoZonei(*(unsigned short*)zone) && details && details[1]==1){
 GameState_CopyB0ByteStateBufferToOutput(&buffer);
 value=buffer.value;
 }
 }
 SetNestedSecondWordForTypeThree(output,value);
 return 1;
}
