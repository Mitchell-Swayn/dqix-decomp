#include <globaldefs.h>
ARM
struct Owner;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(Owner*);
extern "C" int ReadIndexedSignedField1038(char*);
extern "C" void Object_SetSelectedBitAndRefreshState(unsigned char*,int);
extern "C" void UpdateEnabledMemberCountAndTimestampOnTransition(unsigned char*);
extern "C" void Ov003_ProcessFixedRegionInChunks(unsigned char*,int);
struct Flags { unsigned char unused:6,enabled:1,other:1; };
// Original: arm9/ov003 @ 0x02171AF0; symbol: func_ov003_02171af0; size: 0xB0.
extern "C" void Network_AdvanceConnectionSelectionTimeout(unsigned char* self) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char* connection=(unsigned char*)Object_GetGlobalConnectionState();
 *(unsigned*)(self+0x72c)+=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);
 if(*(unsigned*)(self+0x72c)>3000) {
  WaitForStateThreeThenProcessOwnerWithTimeout((Owner*)connection);
  *(unsigned*)(self+0x72c)=0;
  self[0]=0;
 }
 if(ReadIndexedSignedField1038((char*)connection)>0) {
  Object_SetSelectedBitAndRefreshState(connection,ReadIndexedSignedField1038((char*)connection));
  Object_SetSelectedBitAndRefreshState(connection,self[0x199]);
  UpdateEnabledMemberCountAndTimestampOnTransition(connection);
  int enabled;
  if(((Flags*)(self+0x1b1))->enabled) enabled=1; else enabled=0;
  Ov003_ProcessFixedRegionInChunks(self,enabled);
  self[0]=7;
 }
}
