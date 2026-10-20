#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void Graphics_UpdateCounted224ByteDisplayRecords(char*);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
extern "C" void TextCanvas_SetGroupPalette(char*,int,unsigned char);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" void TextCanvas_SetDisplayPartRefreshFlag(void*,int,int);
extern "C" void KeyRepeater_Reset(unsigned char*);
extern "C" int Shop_TestSelectionConfirmation(char*);
extern "C" int Shop_TestSelectionCancellation(unsigned char*);
// Original: arm9/ov003 @ 0x021786BC; symbol: func_ov003_021786bc; size: 0x254.
extern "C" void Graphics_UpdateDisplaySelectionState(char* p) {
 char* display=*(char**)(p+0x89c);
 unsigned state=*(unsigned char*)(p+0x103f);
 if(state==0) {
  *(unsigned short*)(p+0x1046)&=~0x400;
  *(short*)(p+0xffe)=2;
  if(*(short*)(p+0x1004)<0) *(short*)(p+0x1004)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear((unsigned char*)display,*(short*)(p+0xffe));
  *(short*)(display+0x36)=*(short*)(p+0x1004);
  TextCanvas_CreateAndConfigureDisplayPart(display,*(short*)(p+0xffe));
  TextCanvas_SetGroupPalette(display,*(short*)(p+0xffe),0);
  TextCanvas_SetDisplayPartRefreshFlag(display,*(short*)(p+0xffe),0);
  KeyRepeater_Reset((unsigned char*)p+0x88c);
  *(unsigned*)(p+0xff8)=0;
  ++*(unsigned char*)(p+0x103f);
 } else if(state==1) {
  *(short**)(p+0xff8)=(short*)(p+0x1004);
  if(Shop_TestSelectionConfirmation(p)) {
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   KeyRepeater_Reset((unsigned char*)p+0x88c);
   int next=0; *(unsigned*)(p+0xff8)=0;
   int selection=-1; *(short*)(p+0x1000)=selection;
   switch(*(short*)(p+0x1004)) {
   case 4:
    selection=1; next=2;
    TextCanvas_SetGroupPalette(display,*(short*)(p+0xffe),1);
    *(short*)(p+0xffc)=*(short*)(p+0xffe);
    *(unsigned short*)(p+0x1046)|=0x20;
    *(short*)(p+0x1014)=0;
    *(short*)(p+0x1016)=(*(unsigned char*)(p+0x835)+5)/6;
    *(unsigned short*)(p+0x1046)&=~0x400;
    if(*(short*)(p+0x1016)>1) *(unsigned short*)(p+0x1046)|=0x400;
    break;
   case 5:
    *(short*)(p+0x100c)=0x76;
    next=3;
    TextCanvas_SetGroupPalette(display,*(short*)(p+0xffe),1);
    *(short*)(p+0xffc)=*(short*)(p+0xffe);
    break;
   case 6:
    next=9; selection=6;
    Graphics_UpdateCounted224ByteDisplayRecords(display);
    break;
   }
   *(short*)(p+0x1036)=selection;
   *(unsigned char*)(p+0x103e)=next;
   *(unsigned char*)(p+0x103f)=0;
  } else if(Shop_TestSelectionCancellation((unsigned char*)p)) {
   KeyRepeater_Reset((unsigned char*)p+0x88c);
   *(unsigned*)(p+0xff8)=0;
   *(unsigned char*)(p+0x103e)=9;
   *(short*)(p+0x1036)=6;
   Graphics_UpdateCounted224ByteDisplayRecords(display);
  }
 }
}
