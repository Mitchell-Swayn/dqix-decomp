#include <globaldefs.h>
ARM
extern "C" bool TextCanvas_HasDisplayPart(void*,int);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(void*,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" void TextCanvas_SetGroupPalette(char*,int,unsigned char);
extern "C" void KeyRepeater_Reset(void*);
extern "C" int Shop_TestSelectionConfirmation(char*);
extern "C" int Shop_TestSelectionCancellation(void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(void*,int,void*);
extern "C" void TextCanvas_ResetDisplayPartByKey(void*,int);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov003 @ 0x0217A280; symbol: func_ov003_0217a280; size: 0x22C.
extern "C" void Graphics_UpdateTwoChoiceDisplaySelection(char* self) {
 char* display=*(char**)(self+0x89c);
 if(*(unsigned char*)(self+0x103f)==0) {
 *(short*)(self+0xffe)=2;
 if(!TextCanvas_HasDisplayPart(display,*(short*)(self+0xffe))) {
 if(*(short*)(self+0x1004)<0)*(short*)(self+0x1004)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(display,*(short*)(self+0xffe));
 *(short*)(display+0x36)=*(short*)(self+0x1004);
 TextCanvas_CreateAndConfigureDisplayPart(display,*(short*)(self+0xffe));
 TextCanvas_SetGroupPalette(display,*(short*)(self+0xffe),1);
 *(short*)(self+0xffc)=*(short*)(self+0xffe);
 }
 *(short*)(self+0xffe)=16;
 if(*(short*)(self+0x100c)<0)*(short*)(self+0x100c)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(display,*(short*)(self+0xffe));
 *(short*)(display+0x36)=*(short*)(self+0x100c);
 TextCanvas_CreateAndConfigureDisplayPart(display,*(short*)(self+0xffe));
 KeyRepeater_Reset(self+0x88c);
 *(void**)(self+0xff8)=0;
 ++*(unsigned char*)(self+0x103f);
 } else if(*(unsigned char*)(self+0x103f)==1) {
 *(void**)(self+0xff8)=self+0x100c;
 if(Shop_TestSelectionConfirmation(self)) {
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 KeyRepeater_Reset(self+0x88c);
 *(void**)(self+0xff8)=0;
 switch(*(short*)(self+0x100c)) {
 case 118:
 *(short*)(self+0xffc)=*(short*)(self+0xffe);
 *(short*)(self+0x1036)=11;
 *(unsigned char*)(self+0x103e)=4;
 *(unsigned char*)(self+0x103f)=0;
 *(unsigned short*)(self+0x1046)|=0x20;
 break;
 case 119:
 *(short*)(self+0xffc)=*(short*)(self+0xffe);
 *(short*)(self+0x1036)=12;
 *(unsigned char*)(self+0x103e)=7;
 *(unsigned char*)(self+0x103f)=0;
 *(short*)(self+0x1012)=-1;
 *(unsigned short*)(self+0x1046)|=0x20;
 break;
 }
 } else if(Shop_TestSelectionCancellation(self)) {
 KeyRepeater_Reset(self+0x88c);
 *(void**)(self+0xff8)=0;
 *(short*)(self+0x1036)=10;
 *(unsigned char*)(self+0x103e)=1;
 *(unsigned char*)(self+0x103f)=0;
 TextCanvas_ResetDisplayPartByKey(display,*(short*)(self+0xffe));
 }
 }
}
