#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define C(p,o) (*(signed char*)((char*)(p)+(o)))
#define V(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void* Network_GetConnectionManager();extern "C" int Network_IsSessionActive(void*);extern "C" int Network_GetLocalMemberId(char*);extern "C" char* NetworkOwnership_FindEntryByKey(unsigned char*,int);extern "C" void NetworkOwnership_RequestForLocalPeer(void*,int);extern "C" void NetworkOwnership_ReleaseForLocalPeer(int,int);
// Original: arm9/main @ 0x020e30f0; symbol: Network_AdvanceTimedByteRequestsAndPendingKeys.
extern "C" void NetworkOwnership_UpdateRequestsAndTimeouts(unsigned char* self){
char* connection=(char*)Network_GetConnectionManager();if(!Network_IsSessionActive(connection))return;unsigned char* record=self;for(int i=0;i<8;++i,record+=4){if(record[2]==2&&!I(connection,0xfc0)){if(record[3]<=30)++record[3];else{unsigned first,second;second=record[1];first=record[0];NetworkOwnership_ReleaseForLocalPeer((int)self,second);record[1]=second;record[0]=first;record[2]=4;}}}unsigned char* pending=self+32;for(int i=0;i<8;++i,++pending){int key=*pending;if(!key)continue;char* found=NetworkOwnership_FindEntryByKey(self,key);if(found){unsigned state=B(found,2);if(B(found,0)!=Network_GetLocalMemberId(connection)&&state==1)state=3;if(state==1||(unsigned char)(state+252)<=1)*pending=0;else if(state!=2)NetworkOwnership_RequestForLocalPeer(self,key);}else NetworkOwnership_RequestForLocalPeer(self,key);}
}
