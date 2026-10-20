#include <globaldefs.h>
ARM
struct StateBits { unsigned low:7; unsigned value:7; unsigned high:18; };
struct Buffer { unsigned pad[3]; StateBits bits; unsigned tail[40]; };
extern "C" { unsigned char* Zone3D_GetMainInstance(); int _Z12IsGrottoZonei(int); int LinkedList_ContainsNodeByIdentity(void*,void*); unsigned char* _ZN17ActiveGrottoClass15GetDetailedDataEv(void*); bool GameState_CopyStatisticsRecord(void*); unsigned char* GameResources_GetInstance(); unsigned char* FieldBattle_GetEncounterRequest(void*); void Script_WriteIntegerReferenceOutput(void*,int); }
// Original: arm9/ov023 @ 0x021EAF50; symbol: func_ov023_021eaf50; size: 0xB0.
extern "C" int Grotto_WriteTypeTwoStateBits(void* output) {
 int value=0;
 unsigned char* resources=GameResources_GetInstance();
 void* list;
 void* node=*(void**)(resources+0x3718);
 list=*(void**)(resources+0x36fc);
 unsigned char* embedded=FieldBattle_GetEncounterRequest(node);
 if(LinkedList_ContainsNodeByIdentity(list,node)) {
  unsigned char* world=Zone3D_GetMainInstance();
  unsigned char* detail=_ZN17ActiveGrottoClass15GetDetailedDataEv(world+0x23ec);
  if(embedded[0x25] && _Z12IsGrottoZonei(*(unsigned short*)world) && detail && detail[1]==2) {
   Buffer buffer;
   GameState_CopyStatisticsRecord(&buffer);
   value=buffer.bits.value;
  }
 }
 Script_WriteIntegerReferenceOutput(output,value);
 return 1;
}
