#include <globaldefs.h>
ARM
extern "C" int String_CountBytesUntilTerminator(...);
extern "C" int String_TestSecondIsPrefixOfFirst(...);
extern "C" int __clear(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov003 @ 0x217f600; symbol: data_ov003_0217f600.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 72031802.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" char TagModeDecodeGuestNameTokenPairs_UnknownRoleDataReferences[];
// Original data: arm9/ov003 @ 0x217f604; symbol: data_ov003_0217f604.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex df021802.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" char TagModeDecodeGuestNameTokenPairs_UnknownRoleDataReferences_Variant2[];
// Original data: arm9/ov003 @ 0x217f608; symbol: data_ov003_0217f608.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex d2021802d9021802e2021802ca021802e5021802dc021802c6021802e802180210051802d00218020c0318021e031802c4021802120318022205180215031802 ...; full span in module reference.
// Observed span: 1036 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" char TagModeDecodeGuestNameTokenPairs_UnknownRoleDataReferences_Variant3[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x02170A7C; symbol: DecodePairedPrefixTokensIntoEightByteOutput.
extern "C" void TagMode_DecodeGuestNameTokenPairs(char*input,char*output){
if(!output||!input)return;unsigned char remaining=String_CountBytesUntilTerminator(input)+1;unsigned char index=0;char buffer[16];__clear(buffer,16);int used=0;while(P(TagModeDecodeGuestNameTokenPairs_UnknownRoleDataReferences,index*12)&&remaining){int matched=0;if(String_TestSecondIsPrefixOfFirst(input,P(TagModeDecodeGuestNameTokenPairs_UnknownRoleDataReferences,index*12)))matched=1;else if(String_TestSecondIsPrefixOfFirst(input,P(TagModeDecodeGuestNameTokenPairs_UnknownRoleDataReferences_Variant2,index*12)))matched=1;if(!matched){index++;continue;}char*token=P(TagModeDecodeGuestNameTokenPairs_UnknownRoleDataReferences_Variant3,(unsigned)index*12);strcpy(buffer+used,token);used+=String_CountBytesUntilTerminator(token);remaining-=2;input+=2;index=0;}memcpy(output,buffer,8);
}
