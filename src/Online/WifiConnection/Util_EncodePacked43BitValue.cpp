#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
// Original data: arm9/ov031 @ 0x22460c4; symbol: data_ov031_022460c4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0102000403050607.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22460cc; symbol: data_ov031_022460cc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0509010e0c020a000b0d030408060f07.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char UtilEncodePacked43BitValue_UnknownRoleInitializedBytes_Variant2[],UtilEncodePacked43BitValue_UnknownRoleInitializedBytes[];
union Packed { unsigned long long value; unsigned char bytes[8]; };
// Original: arm9/ov031 @ 0x0221BE64; symbol: func_ov031_0221be64; size: 0x184.
extern "C" unsigned long long Util_EncodePacked43BitValue(unsigned a,unsigned b,unsigned c,unsigned d) {
 Packed packed;
 packed.value=((unsigned long long)d&3)|(((unsigned long long)c&1)<<2)|(((unsigned long long)b&0xffffff)<<3)|(((unsigned long long)a&0xffff)<<27);
 {
 unsigned char* ptr=packed.bytes;
 int i=0;
 do { *ptr^=0xd6; ptr++; i++; } while(i<6);
 }
 {
 unsigned char* ptr=packed.bytes;
 int i=0;
 do {
 unsigned char v=*ptr;
 *ptr=(UtilEncodePacked43BitValue_UnknownRoleInitializedBytes_Variant2[(v>>4)&15]<<4)|UtilEncodePacked43BitValue_UnknownRoleInitializedBytes_Variant2[v&15];
 ptr++; i++;
 } while(i<5);
 unsigned long long copy;
 MI_CpuCopy8(&packed,&copy,8);
 unsigned char* map=UtilEncodePacked43BitValue_UnknownRoleInitializedBytes;
 unsigned char* src=(unsigned char*)&copy;
 i=0;
 do { packed.bytes[*map++]=*src++; i++; } while(i<5);
 packed.bytes[7]=0;packed.bytes[6]=0;packed.bytes[5]&=7;
 packed.value<<=1;
 packed.bytes[0] |= (packed.bytes[5]>>3)&1;
 { unsigned char* ptr=packed.bytes; int i=0; do { *ptr^=0x67; ptr++; i++; } while(i<6); }
 packed.bytes[7]=0;packed.bytes[6]=0;packed.bytes[5]&=7;
 }
 return packed.value;
}
