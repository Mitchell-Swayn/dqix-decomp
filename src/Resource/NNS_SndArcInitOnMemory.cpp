#include <globaldefs.h>
ARM
#pragma opt_propagation off
extern "C" int MIi_CpuCopy32(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/main @ 0x020BD368; symbol: CopyResourceHeaderAndRelocateRelativePointers; size: 0xc4.
extern "C" void NNS_SndArcInitOnMemory(char* self,char* source){
MIi_CpuCopy32(source,self,48);P(self,0x8c)=W(self,24)==0?0:source+W(self,24);P(self,0x84)=W(self,32)==0?0:source+W(self,32);P(self,0x88)=W(self,16)==0?0:source+W(self,16);W(self,0x90)=0;unsigned i=0;if((unsigned)W(P(self,0x84),8)>i){unsigned offset=i;do{char* entry=(P(self,0x84)+12)+offset;P(entry,8)=W(entry,0)==0?0:source+W(entry,0);i++;offset+=16;}while(i<(unsigned)W(P(self,0x84),8));}W(self,48)=0;P(NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage,0)=self;
}
