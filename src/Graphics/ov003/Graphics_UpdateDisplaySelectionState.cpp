#include <globaldefs.h>
ARM
extern "C" char data_02108760[];
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);
extern "C" void Graphics_UpdateCounted224ByteDisplayRecords(char*);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
extern "C" void Object_SetGroupNibbleAndTextureLowFourBits(char*,int,unsigned char);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
extern "C" void SetKeyedRecordByteFlagBitSixAndRefresh(void*,int,int);
extern "C" void ResetPointedHalfwordAndSynchronizeSignedByteState(unsigned char*);
extern "C" int UpdateSelectionFromActiveInputOrHitTest(char*);
extern "C" int TestInputOrPointerRectangleGate(unsigned char*);
// Original: arm9/ov003 @ 0x021786BC; symbol: func_ov003_021786bc; size: 0x254.
extern "C" void Graphics_UpdateDisplaySelectionState(char* p) {
 char* display=*(char**)(p+0x89c);
 unsigned state=*(unsigned char*)(p+0x103f);
 if(state==0) {
  *(unsigned short*)(p+0x1046)&=~0x400;
  *(short*)(p+0xffe)=2;
  if(*(short*)(p+0x1004)<0) *(short*)(p+0x1004)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear((unsigned char*)display,*(short*)(p+0xffe));
  *(short*)(display+0x36)=*(short*)(p+0x1004);
  Object_CreateAndConfigureSelectedDisplayPart(display,*(short*)(p+0xffe));
  Object_SetGroupNibbleAndTextureLowFourBits(display,*(short*)(p+0xffe),0);
  SetKeyedRecordByteFlagBitSixAndRefresh(display,*(short*)(p+0xffe),0);
  ResetPointedHalfwordAndSynchronizeSignedByteState((unsigned char*)p+0x88c);
  *(unsigned*)(p+0xff8)=0;
  ++*(unsigned char*)(p+0x103f);
 } else if(state==1) {
  *(short**)(p+0xff8)=(short*)(p+0x1004);
  if(UpdateSelectionFromActiveInputOrHitTest(p)) {
   DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
   ResetPointedHalfwordAndSynchronizeSignedByteState((unsigned char*)p+0x88c);
   int next=0; *(unsigned*)(p+0xff8)=0;
   int selection=-1; *(short*)(p+0x1000)=selection;
   switch(*(short*)(p+0x1004)) {
   case 4:
    selection=1; next=2;
    Object_SetGroupNibbleAndTextureLowFourBits(display,*(short*)(p+0xffe),1);
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
    Object_SetGroupNibbleAndTextureLowFourBits(display,*(short*)(p+0xffe),1);
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
  } else if(TestInputOrPointerRectangleGate((unsigned char*)p)) {
   ResetPointedHalfwordAndSynchronizeSignedByteState((unsigned char*)p+0x88c);
   *(unsigned*)(p+0xff8)=0;
   *(unsigned char*)(p+0x103e)=9;
   *(short*)(p+0x1036)=6;
   Graphics_UpdateCounted224ByteDisplayRecords(display);
  }
 }
}
