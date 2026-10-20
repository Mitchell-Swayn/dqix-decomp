#include <globaldefs.h>
ARM
struct FilterNode; struct FilterList; struct Owner;
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void TextCanvas_ResetDisplayPartByKey(unsigned char*,int);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" void KeyRepeater_Reset(unsigned char*);
extern "C" FilterNode* Util_FilterAndRebuildNodeList(FilterList*,int,int,int,short,short*);
extern "C" int BestiaryScreen_ProcessSelectionActivation(Owner*);
extern "C" int DetectInputOutsideScaledTextureRegion(Owner*);
extern "C" short BestiaryScreen_CountFilteredMonsters(Owner*);
extern "C" void Graphics_PopulateRecordGroupSummaryDisplay(Owner*,unsigned);
// Original: arm9/ov014 @ 0x02187DB8; symbol: func_ov014_02187db8; size: 0x258.
extern "C" void Graphics_UpdateFilteredDisplaySelection(char* p) {
 if(*(unsigned char*)(p+0x17b)==0) {
  if(*(unsigned char*)(p+0x17e)&0x10) return;
  *(short*)(p+0x170)=2;
  if(*(short*)(p+0x174)<0) *(short*)(p+0x174)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(*(unsigned char**)(p+0xc0),*(short*)(p+0x170));
  TextCanvas_CreateAndConfigureDisplayPart(*(char**)(p+0xc0),*(short*)(p+0x170));
  *(signed char*)(p+0x17d)=*(short*)(p+0x174)-11;
  short count=0;
  *(unsigned*)(p+0xb8)=(unsigned)Util_FilterAndRebuildNodeList((FilterList*)(p+0xa4),*(signed char*)(p+0x17d),-1,(*(unsigned char*)(p+0x17e)&8)!=0,16,&count);
  unsigned list=*(unsigned*)(p+0xb8);
  *(unsigned*)(p+0xbc)=list; Graphics_PopulateRecordGroupSummaryDisplay((Owner*)p,list);
  ++*(unsigned char*)(p+0x17b);
 } else if(*(unsigned char*)(p+0x17b)==1) {
  *(short**)(p+0xd0)=(short*)(p+0x174);
  *(signed char*)(p+0x17d)=*(short*)(p+0x174)-11;
  if(*(int*)(p+0x160)!=0 || *(short*)(p+0x178)!=**(short**)(p+0xd0)) {
   short count=0;
   *(unsigned*)(p+0xb8)=(unsigned)Util_FilterAndRebuildNodeList((FilterList*)(p+0xa4),*(signed char*)(p+0x17d),-1,(*(unsigned char*)(p+0x17e)&8)!=0,16,&count);
   unsigned list=*(unsigned*)(p+0xb8);
  *(unsigned*)(p+0xbc)=list; Graphics_PopulateRecordGroupSummaryDisplay((Owner*)p,list);
  }
  if(BestiaryScreen_ProcessSelectionActivation((Owner*)p)) {
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   KeyRepeater_Reset((unsigned char*)p+0x14c);
   if(BestiaryScreen_CountFilteredMonsters((Owner*)p)) {
    TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(p+0xc0),*(short*)(p+0x170));
    *(void**)(p+0xd0)=0;
    *(unsigned char*)(p+0x17a)=4; *(unsigned char*)(p+0x17b)=0;
    *(unsigned char*)(p+0x17e)|=0x10;
   }
  } else if(DetectInputOutsideScaledTextureRegion((Owner*)p)) {
   TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(p+0xc0),*(short*)(p+0x170));
   *(short*)(p+0x174)=-1; *(signed char*)(p+0x17d)=-1;
   *(unsigned char*)(p+0x17a)=2; *(unsigned char*)(p+0x17b)=0;
  } else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x800)) {
   TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(p+0xc0),*(short*)(p+0x170));
   *(short*)(p+0x174)=-1; *(signed char*)(p+0x17d)=-1;
   *(unsigned char*)(p+0x17a)=5; *(unsigned char*)(p+0x17b)=0;
  }
 }
}
