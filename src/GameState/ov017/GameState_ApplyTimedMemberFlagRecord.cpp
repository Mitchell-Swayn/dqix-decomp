#include <globaldefs.h>
ARM
extern "C" { unsigned char* GameState_GetObjectWithFlag100(void*,int); void* Object_GetGlobalConnectionState(); bool TestActiveWordAndGlobalStateNonzero(unsigned*); unsigned char* ReadWordFieldAtOffset150(void*); unsigned long long _Z19GetCurrentTimestampv(); void UpdateKeyedRecordByteFlags(int,int,int,int); }
// Original: arm9/ov017 @ 0x021CE054; symbol: func_ov017_021ce054; size: 0xBC.
extern "C" void GameState_ApplyTimedMemberFlagRecord(int index,unsigned char* packet,void* state,int resources) {
 int valid=index>=0 && index<=3;
 if(!valid) return;
 unsigned char* member=GameState_GetObjectWithFlag100(state,*(unsigned short*)(packet+8));
 if(!member) return;
 unsigned char* data=ReadWordFieldAtOffset150(member);
 unsigned* connection=(unsigned*)Object_GetGlobalConnectionState();
 if(*(unsigned short*)(packet+4)!=1) return;
 if(*(short*)(packet+6)>0) {
  UpdateKeyedRecordByteFlags(resources,1,*(short*)(member+4),2);
  data[0x56c]=1;
  if(TestActiveWordAndGlobalStateNonzero(connection)) return;
  *(unsigned long long*)(data+0x480)=_Z19GetCurrentTimestampv();
 } else {
  data[0x56c]=0;
  UpdateKeyedRecordByteFlags(resources,0,*(short*)(member+4),2);
 }
}
