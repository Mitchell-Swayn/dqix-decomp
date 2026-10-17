#include <globaldefs.h>
ARM
extern "C" {
void GameState_UpdateFourSlotRecord(char*,int,int,int,void*,signed char,signed char);
void* OV017_ReadWordField6AC(void*);
void* OV017_ReadWordField6B0(void*);
void* OV017_GetEmbeddedField1C(void*);
}
// Original: arm9/ov017 @ 0x021C6B04; symbol: func_ov017_021c6b04; size: 0x88.
extern "C" void GameState_UpdateMatchingEmbeddedFourSlotRecord(void* unused,unsigned char* record,int unused2,unsigned char* context) {
 void* owner=*(void**)(context+0x3718);
 unsigned char* embedded=(unsigned char*)OV017_GetEmbeddedField1C(owner);
 if(embedded) {
  char* target=(char*)OV017_ReadWordField6AC(owner);
  if(target && OV017_ReadWordField6B0(owner) && *(unsigned short*)(embedded+8)==*(unsigned short*)(record+4))
   GameState_UpdateFourSlotRecord(target,*(short*)(record+4),*(unsigned short*)(record+6),record[8],(void*)(unsigned)record[9],*(signed char*)(record+10),*(signed char*)(record+11));
 }
}
