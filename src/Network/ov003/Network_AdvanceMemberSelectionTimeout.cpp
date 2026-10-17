#include <globaldefs.h>
ARM
struct Owner;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Object_GetGlobalConnectionState();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" int ReadCurrentStateHalfwordFromAvailableRepresentation(void*);
extern "C" int Return10(void*);
extern "C" int Object_Get192ByteIndexedEntryAtOffset10(int,int);
extern "C" void Object_SetSelectedBitAndRefreshState(unsigned char*,unsigned char);
extern "C" void UpdateEnabledMemberCountAndTimestampOnTransition(unsigned char*);
extern "C" unsigned WaitForStateThreeThenProcessOwnerWithTimeout(Owner*);
// Original: arm9/ov003 @ 0x02171640; symbol: func_ov003_02171640; size: 0xB8.
extern "C" void Network_AdvanceMemberSelectionTimeout(char* self) {
void* state=_ZN9GameState11GetInstanceEv();
unsigned char* connection=(unsigned char*)Object_GetGlobalConnectionState();
unsigned delta=_ZNK9GameState21GetEffectiveDeltaTimeEv(state);
if(delta<*(unsigned*)(self+4)) {
*(unsigned*)(self+4)-=delta;
int mask=ReadCurrentStateHalfwordFromAvailableRepresentation(connection);
int limit=Return10(connection);
for(int i=1;i<limit;++i) {
if(mask&(1<<i)) {
Object_Get192ByteIndexedEntryAtOffset10((int)connection,i);
self[0x199]=i;
Object_SetSelectedBitAndRefreshState(connection,(unsigned char)i);
UpdateEnabledMemberCountAndTimestampOnTransition(connection);
self[0]=2;
return;
}
}
} else {
*(unsigned*)(self+4)=0;
WaitForStateThreeThenProcessOwnerWithTimeout((Owner*)connection);
self[0]=4;
}
}
