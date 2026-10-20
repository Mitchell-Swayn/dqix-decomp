#include <globaldefs.h>
ARM
struct Owner;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void* Network_GetConnectionManager();
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(Owner*);
extern "C" int Network_GetLocalMemberId(char*);
extern "C" void Network_ActivateMember(unsigned char*,int);
extern "C" void Network_UpdateMemberCountAndSessionTime(unsigned char*);
extern "C" void Ov003_ProcessFixedRegionInChunks(unsigned char*,int);
struct Flags { unsigned char unused:6,enabled:1,other:1; };
// Original: arm9/ov003 @ 0x02171AF0; symbol: func_ov003_02171af0; size: 0xB0.
extern "C" void Network_AdvanceConnectionSelectionTimeout(unsigned char* self) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char* connection=(unsigned char*)Network_GetConnectionManager();
 *(unsigned*)(self+0x72c)+=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);
 if(*(unsigned*)(self+0x72c)>3000) {
  WaitForStateThreeThenProcessOwnerWithTimeout((Owner*)connection);
  *(unsigned*)(self+0x72c)=0;
  self[0]=0;
 }
 if(Network_GetLocalMemberId((char*)connection)>0) {
  Network_ActivateMember(connection,Network_GetLocalMemberId((char*)connection));
  Network_ActivateMember(connection,self[0x199]);
  Network_UpdateMemberCountAndSessionTime(connection);
  int enabled;
  if(((Flags*)(self+0x1b1))->enabled) enabled=1; else enabled=0;
  Ov003_ProcessFixedRegionInChunks(self,enabled);
  self[0]=7;
 }
}
