#include <globaldefs.h>
ARM
extern "C" int Network_AdvanceAndPublishAccessPointScanPhase(...);
extern "C" int System_DispatchWithIndexedTableFlag(...);
extern "C" unsigned long long _Z19GetCurrentTimestampv(...);
extern "C" int FindPriorityBitByRank(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov031 @ 0x2245fb0; symbol: data_ov031_02245fb0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffff0000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x02214EA8; symbol: AdvanceTimedPackedEntryAndPublishIndexedTransfer.
extern "C" int Network_AdvanceTimedSsidChannelScan(char*self){
unsigned long long elapsed=(_Z19GetCurrentTimestampv()-*(unsigned long long*)(self+3248))<<6;struct Flags{unsigned char mode:4;unsigned char other:4;};if(elapsed/33514>=150||((Flags*)(self+B(self,3343)*36+768))->mode==1){((Flags*)(self+768+(short)B(self,3343)*36))->mode=0;B(self,3343)++;if(B(self,3344)<=B(self,3343)){B(self,3349)++;B(self,3343)=0;B(self,3345)=FindPriorityBitByRank(B(self,3349));}if(*(signed char*)(self+3345)<0){B(self,3349)=0;return Network_AdvanceAndPublishAccessPointScanPhase(self,5);}*(unsigned long long*)(self+3248)=_Z19GetCurrentTimestampv();System_DispatchWithIndexedTableFlag(NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes,self+772+B(self,3343)*36,*(signed char*)(self+3345),0x300000);}return 5;
}
