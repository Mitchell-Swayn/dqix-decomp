#include <globaldefs.h>
ARM
// Original data: arm9/ov009 @ 0x218a9ac; symbol: data_ov009_0218a9ac.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 6500000065000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
extern "C" {void* memset(void*,int,unsigned);int rand();int sprintf(char*,const char*,...);void* ResourceStringTable_GetTextByKey(void*,void*);extern int FormatRandomCategoryEntry_UnknownRoleInitializedBytes[];}
// Original: arm9/ov009 @ 0x0218A8B8; symbol: func_ov009_0218a8b8; size: 0x78.
// Clears selected48-byte text storage and formats a random indexed category record into it.
extern "C" void FormatRandomCategoryEntry(unsigned char* p) {
 char* buffer=(*(char***)(p+0xdb0))[p[0xda3]];
 memset(buffer,0,0x48);
 int count=FormatRandomCategoryEntry_UnknownRoleInitializedBytes[p[0xda3]];
 int offset=rand()%count;
 int categoryBase=p[0xda3]*1000+20000;
 short index=offset+categoryBase;
 const char* format=(const char*)ResourceStringTable_GetTextByKey(p+0xe0,(void*)index);
 sprintf(buffer,format);
}
