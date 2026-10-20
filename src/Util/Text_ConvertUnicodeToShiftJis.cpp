#include <globaldefs.h>
ARM
extern "C" unsigned Util_FindShiftJisCodeByUnicode(unsigned,unsigned short*,int);
// Original data: arm9/main @ 0x20e743c; symbol: data_020e743c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 9f840025a0840225a1840c25a2841025a3841825a4841425a5841c25a6842c25a7842425a8843425a9843c25aa840125ab840325ac840f25ad841325ae841b25 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e74bc; symbol: data_020e74bc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 408100304181013042810230.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e74c8; symbol: data_020e74c8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 43810cff44810eff4581fb3046811aff47811bff48811fff498101ff4a819b304b819c30.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e74ec; symbol: data_020e74ec.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4c81b4004d8140ff4e81a8004f813eff5081e3ff51813fff5281fd305381fe3054819d3055819e30568103305781dd4e58810530598106305a8107305b81fc30.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e752c; symbol: data_020e752c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 5c8115205d8110205e810fff5f815c0060811c306181162062815cff6381262064812520658118206681192067811c2068811d20698108ff6a8109ff6b811430 ...; full span in module reference.
// Observed span: 644 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes_Variant4[],TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes_Variant3[],TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes_Variant2[],TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes[],TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes_Variant5[];
// Original: arm9/main @ 0x020328BC; symbol: func_020328bc; size: 0x568.
extern "C" void Text_ConvertUnicodeToShiftJis(char* output,const unsigned short* input,unsigned short count) {
while(*input && count--) {
unsigned ch=*input++;
int code;
if(ch==0xa5) code=0x5c;
else if(ch==0x5c) code=0x815f;
else if(ch==0x203e) code=0x7e;
else if(ch==13 || ch==10) code=ch;
else if(ch>=0x20 && ch<0x7e) code=ch;
else if(ch>=0xa2 && ch<=0xf7) code=Util_FindShiftJisCodeByUnicode(ch,TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes_Variant4,0xab);
else if(ch>=0xff61 && ch<=0xff9f) code=(unsigned short)(ch-0xfec0);
else if(ch==0x4edd) code=0x8157;
else if(ch>=0xff01 && ch<=0xffe5) {
if(ch>=0xff10 && ch<=0xff19) code=(unsigned short)(ch-0x7cc1);
else if(ch>=0xff21 && ch<=0xff3a) code=(unsigned short)(ch-0x7cc1);
else if(ch>=0xff41 && ch<=0xff5a) code=(unsigned short)(ch-0x7cc0);
else code=Util_FindShiftJisCodeByUnicode(ch,TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes_Variant3,0x54);
} else if(ch>=0x3000 && ch<=0x30fe) {
if(ch>=0x3041 && ch<=0x3093) code=(unsigned short)(ch+0x525e);
else if(ch>=0x30a1 && ch<=0x30f6) {
code=(unsigned short)(ch+0x529f);
if(ch>=0x30e0) code=(unsigned short)(code+1);
} else code=Util_FindShiftJisCodeByUnicode(ch,TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes_Variant2,0x6c);
} else if(ch>=0x391 && ch<=0x3a9) {
code=(unsigned short)(ch+0x800e);
if(ch>=0x3a3) code=(unsigned short)(code-1);
} else if(ch>=0x3b1 && ch<=0x3c9) {
code=(unsigned short)(ch+0x800e);
if(ch>=0x3c3) code=(unsigned short)(code-1);
} else if(ch==0x401) code=0x8446;
else if(ch>=0x410 && ch<=0x42f) {
code=(unsigned short)(ch+0x8030);
if(ch>=0x416) code=(unsigned short)(code+1);
} else if(ch>=0x430 && ch<=0x44f) {
code=(unsigned short)(ch+0x8040);
if(ch>=0x436) {
code=(unsigned short)(code+1);
if(ch>=0x43e) code=(unsigned short)(code+1);
}
} else if(ch==0x451) code=0x8476;
else if(ch>=0x2500 && ch<=0x254b) code=Util_FindShiftJisCodeByUnicode(ch,TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes,0x20);
else if((ch>=0x2010 && ch<=0x2312)||(ch>=0x25a0 && ch<=0x266f)) code=Util_FindShiftJisCodeByUnicode(ch,TextConvertUnicodeToShiftJis_UnknownRoleInitializedBytes_Variant5,0xa0);
else code=0x8140;
if(code&0xff00) *output++=code>>8;
*output++=code;
}
}
