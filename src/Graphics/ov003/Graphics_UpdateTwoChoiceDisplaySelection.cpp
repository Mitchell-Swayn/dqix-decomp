#include <globaldefs.h>
ARM
extern "C" bool Object_TestTextureRecordExistsForKey(void*,int);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(void*,int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
extern "C" void Object_SetGroupNibbleAndTextureLowFourBits(char*,int,unsigned char);
extern "C" void ResetPointedHalfwordAndSynchronizeSignedByteState(void*);
extern "C" int UpdateSelectionFromActiveInputOrHitTest(char*);
extern "C" int TestInputOrPointerRectangleGate(void*);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(void*,int,void*);
extern "C" void ResolveAndResetPresentEntry(void*,int);
extern "C" unsigned char data_02108760[];
// Original: arm9/ov003 @ 0x0217A280; symbol: func_ov003_0217a280; size: 0x22C.
extern "C" void Graphics_UpdateTwoChoiceDisplaySelection(char* self) {
 char* display=*(char**)(self+0x89c);
 if(*(unsigned char*)(self+0x103f)==0) {
 *(short*)(self+0xffe)=2;
 if(!Object_TestTextureRecordExistsForKey(display,*(short*)(self+0xffe))) {
 if(*(short*)(self+0x1004)<0)*(short*)(self+0x1004)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(display,*(short*)(self+0xffe));
 *(short*)(display+0x36)=*(short*)(self+0x1004);
 Object_CreateAndConfigureSelectedDisplayPart(display,*(short*)(self+0xffe));
 Object_SetGroupNibbleAndTextureLowFourBits(display,*(short*)(self+0xffe),1);
 *(short*)(self+0xffc)=*(short*)(self+0xffe);
 }
 *(short*)(self+0xffe)=16;
 if(*(short*)(self+0x100c)<0)*(short*)(self+0x100c)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(display,*(short*)(self+0xffe));
 *(short*)(display+0x36)=*(short*)(self+0x100c);
 Object_CreateAndConfigureSelectedDisplayPart(display,*(short*)(self+0xffe));
 ResetPointedHalfwordAndSynchronizeSignedByteState(self+0x88c);
 *(void**)(self+0xff8)=0;
 ++*(unsigned char*)(self+0x103f);
 } else if(*(unsigned char*)(self+0x103f)==1) {
 *(void**)(self+0xff8)=self+0x100c;
 if(UpdateSelectionFromActiveInputOrHitTest(self)) {
 DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
 ResetPointedHalfwordAndSynchronizeSignedByteState(self+0x88c);
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
 } else if(TestInputOrPointerRectangleGate(self)) {
 ResetPointedHalfwordAndSynchronizeSignedByteState(self+0x88c);
 *(void**)(self+0xff8)=0;
 *(short*)(self+0x1036)=10;
 *(unsigned char*)(self+0x103e)=1;
 *(unsigned char*)(self+0x103f)=0;
 ResolveAndResetPresentEntry(display,*(short*)(self+0xffe));
 }
 }
}
