#include <globaldefs.h>
ARM
extern "C" int MI_CpuCopy8(...);
extern "C" int Network_NormalizeWirelessProfileIndex(...);
extern "C" int Util_ReadFourBytesAndReversePackedWord(...);
extern "C" int Network_BuildByteSwappedPrefixMask(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
// Original data: arm9/ov031 @ 0x2246028; symbol: data_ov031_02246028.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 00000001000000000000000001000000000000000000000000000000000000000000000000100000001000000000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 91 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcConnectionBuildSelectedProfileIpSettings_UnknownRoleDataReferences[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x02215528; symbol: BuildAddressSettingsFromSelectedProfile; size: 0xc0.
extern "C" void WfcConnection_BuildSelectedProfileIpSettings(int* source,char* owner,int* output){
MI_CpuCopy8(WfcConnectionBuildSelectedProfileIpSettings_UnknownRoleDataReferences,output,88);output[1]=source[0];output[2]=source[1];unsigned selected=B(owner,0xd0d);if(selected>=6)return;char* profile=owner+(Network_NormalizeWirelessProfileIndex(selected)<<8);if(B(profile,0xc0)){output[3]=0;output[4]=Util_ReadFourBytesAndReversePackedWord(profile+0xc0);output[5]=Network_BuildByteSwappedPrefixMask(B(profile,0xd0));output[6]=Util_ReadFourBytesAndReversePackedWord(profile+0xc4);output[7]=Util_ReadFourBytesAndReversePackedWord(profile+0xc8);output[8]=Util_ReadFourBytesAndReversePackedWord(profile+0xcc);}else{output[3]=1;output[4]=0;output[5]=0;output[6]=0;output[7]=0;output[8]=0;}
}
