#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
extern "C" void* NetworkOwnership_GetRegistry();extern "C" unsigned char NetworkOwnership_ClassifyLocalRequest(void*,unsigned);extern "C" void Field_ApplyPartyRecoveryAndRefreshActors(int,int,int,int);extern "C" void NetworkOwnership_ReleaseForLocalPeer(void*,int);extern "C" void Field_ClearPartyRecoveryRequest(void*);extern "C" void NetworkOwnership_ClearLocalEntry(void*,int);extern "C" void Field_QueuePartyRecoveryOwnershipRequest(void*,const void*);
// Original: arm9/ov017 @ 0x0218D818; symbol: DispatchPendingContextOrRestoreSixByteEntry; size: 0xb4.
extern "C" void Field_ProcessPartyRecoveryOwnershipRequest(char* self){
if(B(self,0x435b)!=1)return;void* context=NetworkOwnership_GetRegistry();unsigned result=NetworkOwnership_ClassifyLocalRequest(context,1);if(result==1){Field_ApplyPartyRecoveryAndRefreshActors(B(self,0x4356),B(self,0x4357),H(self,0x4358),B(self,0x435a));NetworkOwnership_ReleaseForLocalPeer(context,1);Field_ClearPartyRecoveryRequest(self+0x4356);}else if(result-3<=2){NetworkOwnership_ClearLocalEntry(context,1);unsigned short record[3];record[0]=H(self,0x4356);record[1]=H(self,0x4358);record[2]=H(self,0x435a);Field_QueuePartyRecoveryOwnershipRequest(self,record);}
}
