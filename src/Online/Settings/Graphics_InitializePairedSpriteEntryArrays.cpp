#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x2248eb0; symbol: data_ov031_02248eb0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 18171615.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Graphics_InitializePairedSpriteEntryArrays_Text3[],GraphicsInitializePairedSpriteEntryArrays_UnknownRoleInitializedBytes[];
extern "C" void* Resource_ExpandPackedTableToAllocatedBuffer(unsigned,unsigned);
extern "C" void WfcUtility_ExpandSpriteCellTemplate(unsigned,unsigned,void*);
// Original: arm9/ov031 @ 0x0222B918; symbol: func_ov031_0222b918; size: 0x174.
extern "C" void Graphics_InitializePairedSpriteEntryArrays() {
 int count=*(unsigned char*)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+0x51);
 if(count>5)count=5;
 int i=0;
 if(count>0)do {
  *(void**)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+0x10+i*4)=Resource_ExpandPackedTableToAllocatedBuffer(0,0x2e);
  *(void**)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+0x24+i*4)=Resource_ExpandPackedTableToAllocatedBuffer(0,0x18);
  i++;
 } while(i<count);
 {unsigned table=0;unsigned char* pattern=Graphics_InitializePairedSpriteEntryArrays_Text3;unsigned i=0;
 do {
  WfcUtility_ExpandSpriteCellTemplate(table,*pattern,*(void**)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+0x10));
  char* state=*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4);
  *(unsigned short*)(state+0x42+i*2)=*(unsigned short*)(*(char**)(state+0x10)+4)&0x3ff;
 pattern++;i++;
 } while(i<3); }
 {unsigned table=0;unsigned char* pattern=GraphicsInitializePairedSpriteEntryArrays_UnknownRoleInitializedBytes;unsigned i=0;
 do {
  WfcUtility_ExpandSpriteCellTemplate(table,*pattern,*(void**)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+0x24));
  char* state=*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4);
  *(unsigned short*)(state+0x48+i*2)=*(unsigned short*)(*(char**)(state+0x24)+4)&0x3ff;
 pattern++;i++;
 } while(i<4); }
 int j=0;
 if(count<=0)return;
 do {
  unsigned short* first=*(unsigned short**)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+0x10+j*4);
  first[2]=(first[2]&~0xc00)|0xc00;
  unsigned short* second=*(unsigned short**)(*(char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage+4)+0x24+j*4);
  second[2]=(second[2]&~0xc00)|0xc00;
 j++;
 } while(j<count);
}
