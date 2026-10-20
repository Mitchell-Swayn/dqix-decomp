#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
// Original data: arm9/ov031 @ 0x2291e04; symbol: data_ov031_02291e04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2291eae; symbol: data_ov031_02291eae.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 118 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ScriptDecodeSelectedTwentyByteHexSlot_UnknownRoleZeroInitializedStorage[], ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02243018; symbol: func_ov031_02243018; size: 0x12C.
// Decodes a script string into a selected twenty-byte slot and stores accompanying parameters.
extern "C" int Script_DecodeSelectedTwentyByteHexSlot(char* args){
_ZNK6Script9Parameter8ToStringEv(args);
signed char buffer[82];memset(buffer,0,82);
buffer[0]=_ZNK6Script9Parameter5ToIntEv(args+8);
int slot=_ZNK6Script9Parameter5ToIntEv(args+16)-1;
unsigned char* out=(unsigned char*)(buffer+2)+(unsigned char)slot*20;
buffer[1]=slot;
const char* str=_ZNK6Script9Parameter8ToStringEv(args+24);
int length=strlen(str);
for(int i=0;i<length;++i){
unsigned char digit;
if(*str>='0' && *str<='9')digit=*str-'0';
else if(*str>='A' && *str<='E')digit=*str-'A'+10;
else if(*str>='a' && *str<='e')digit=*str-'a'+10;
else digit=0;
++str;
if(i%2==0)*out|=digit<<4;
else {*out|=digit;++out;}
}
memcpy(ScriptDecodeSelectedTwentyByteHexSlot_UnknownRoleZeroInitializedStorage,buffer,82);
*(const char**)(ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage+52)=_ZNK6Script9Parameter8ToStringEv(args+32);
*(short*)(ScriptSetIndexedNetworkWord_UnknownRoleZeroInitializedStorage+8)=_ZNK6Script9Parameter5ToIntEv(args+40);
return 1;
}
