#include <globaldefs.h>
// Original data: arm9/main @ 0x20e7a50; symbol: data_020e7a50.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0f0f0f000600f00020000000004800000003000000300000000900000010000074000000020000000008000000080000020000000008000074000000.
// Observed span: 60 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Mapping { void *bytes; unsigned char flags; signed char length:6; signed char other:2; }; extern "C" unsigned char TextMapInputBytesToVariableLengthOutputSequences_UnknownRoleInitializedBytes[]; extern "C" Mapping *TextLookup_GetGlyphEntryByIndex(unsigned,unsigned);extern "C" void *memcpy(void *,const void *,unsigned);
// Original: arm9/main @ 0x02042764; symbol: func_02042764; size: 0xA0.
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char *input,unsigned char *output,unsigned mode) { if(!output)return;if(!input){if(output)*output=0;return;} unsigned char b,a;a=TextMapInputBytesToVariableLengthOutputSequences_UnknownRoleInitializedBytes[8];b=TextMapInputBytesToVariableLengthOutputSequences_UnknownRoleInitializedBytes[9];unsigned char fallback[2];while(true){unsigned code=*input;if(!code){*output=0;return;}fallback[0]=a;fallback[1]=b;const void *bytes=fallback;int n=1;Mapping *m=TextLookup_GetGlyphEntryByIndex(code,mode);if(m){bytes=m->bytes;n=m->length;}memcpy(output,bytes,n);++input;output+=n;} }
