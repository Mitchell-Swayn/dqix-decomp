#include <globaldefs.h>
ARM
extern "C" char* Combat_GetIndexedActionTarget(unsigned char*,int);
extern "C" char* Combat_GetCommandActorSnapshot(unsigned char*,int);
extern "C" int Combat_GetLatestTargetFromHistory(char*);
// Original: arm9/ov000 @ 0x021818E0; symbol: func_ov000_021818e0; size: 0xB0.
extern "C" int GameState_ReadLinkedRecordValueByMode(int mode,int index,unsigned char* owner,int* out) {
 switch(mode) {
 case 0:
  if((int)owner[9]<index+1) return 0;
  *out=*(short*)(Combat_GetIndexedActionTarget(owner,index)+0xe);
  return 1;
 case 1:
  if((int)owner[8]<index+1) return 0;
  *out=*(unsigned short*)(Combat_GetCommandActorSnapshot(owner,index)+0x20);
  return 1;
 case 2:
  if((int)owner[9]<index+1) return 0;
  *out=Combat_GetLatestTargetFromHistory(Combat_GetIndexedActionTarget(owner,index));
  return 1;
 }
 return 0;
}
