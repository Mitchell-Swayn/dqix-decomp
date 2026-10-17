#include <globaldefs.h>
ARM
extern "C" char* GetSecondaryLinkedRecordByIndex(unsigned char*,int);
extern "C" char* GetPrimaryLinkedRecordByIndex(unsigned char*,int);
extern "C" int ReadHalfwordByClampedByteSelector(char*);
// Original: arm9/ov000 @ 0x021818E0; symbol: func_ov000_021818e0; size: 0xB0.
extern "C" int GameState_ReadLinkedRecordValueByMode(int mode,int index,unsigned char* owner,int* out) {
 switch(mode) {
 case 0:
  if((int)owner[9]<index+1) return 0;
  *out=*(short*)(GetSecondaryLinkedRecordByIndex(owner,index)+0xe);
  return 1;
 case 1:
  if((int)owner[8]<index+1) return 0;
  *out=*(unsigned short*)(GetPrimaryLinkedRecordByIndex(owner,index)+0x20);
  return 1;
 case 2:
  if((int)owner[9]<index+1) return 0;
  *out=ReadHalfwordByClampedByteSelector(GetSecondaryLinkedRecordByIndex(owner,index));
  return 1;
 }
 return 0;
}
