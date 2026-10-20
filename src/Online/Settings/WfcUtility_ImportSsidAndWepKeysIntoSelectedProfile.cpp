#include <globaldefs.h>
ARM
extern "C" int WfcUtility_CommitEditedConnectionProfile(...);
extern "C" int MI_CpuCopy8(...);
extern "C" int VectorizedMemset(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x02236250; symbol: ConfigureSharedWirelessKeysAndApplySelectedPage.
extern "C" void WfcUtility_ImportSsidAndWepKeysIntoSelectedProfile(char*input){
char*state=P(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage,0);VectorizedMemset(state+1024,0,239);MI_CpuCopy8(input,state+1088,32);int length;switch(W(input,32)){case 1:B(state,1254)=(B(state,1254)&~3)|1;length=5;break;case 2:B(state,1254)=(B(state,1254)&~3)|2;length=13;break;case 3:B(state,1254)=(B(state,1254)&~3)|3;length=16;break;default:B(state,1254)&=~3;length=0;break;}B(state,1254)&=~252;int i=0;char*destination=state+1152;char*source=input+40;do{MI_CpuCopy8(source,destination,length);i++;destination+=16;source+=32;}while(i<4);B(state,1255)=2;VectorizedMemset(state+1264,0,4);B(state,1269)=1;B(state,1270)=1;WfcUtility_CommitEditedConnectionProfile();
}
