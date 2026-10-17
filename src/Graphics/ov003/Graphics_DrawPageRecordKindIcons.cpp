#include <globaldefs.h>
ARM
extern "C" {
char* FindTwoHundredTwentyFourByteRecordByByteKey(char*,unsigned);
bool TestField9CEqualsThree(void*);
void* FindSerializedPrimaryRecordByKey(void*,int);
void Object_ComputeGroupAndPartScaledXY(char*,unsigned,int,short*,short*);
int LookupMappedRecordKindOrReturnNineteen(void*);
void Graphics_SetIndexedRecordCoordinatesAndSubmit(char*,int,int,unsigned char,unsigned char);
int AreBothWordFieldsD4And9CNonzero(char*);
extern unsigned char data_ov003_0217fabd[],data_ov003_0217fa9c[];
}
// Original: arm9/ov003 @ 0x02175504; symbol: func_ov003_02175504; size: 0x278.
extern "C" void Graphics_DrawPageRecordKindIcons(char* self) {
 char* display=*(char**)(self+0x89c);
 unsigned char slot=6;
 char* group=FindTwoHundredTwentyFourByteRecordByByteKey(display,3);
 if(group) {
  if(TestField9CEqualsThree(group)) {
   short part=7;
   short index=*(short*)(self+0x1014)*6;
   for(unsigned char i=0;i<6;part++,index++,i++) {
    void* entry=FindSerializedPrimaryRecordByKey(self+0x874,*(short*)(self+0x848+index*2));
    if(entry) {
     short x,y;
     Object_ComputeGroupAndPartScaledXY(display,3,part,&x,&y);
     int kind=LookupMappedRecordKindOrReturnNineteen(entry);
     Graphics_SetIndexedRecordCoordinatesAndSubmit(self,x,y-1,kind+6,slot);
    }
    slot++;
   }
  }
 } else {
  if(*(short*)(self+0x100c)==119) {
   char* selected=0;
   char* node=FindTwoHundredTwentyFourByteRecordByByteKey(display,21);
   if(node && TestField9CEqualsThree(node))selected=node;
   node=FindTwoHundredTwentyFourByteRecordByByteKey(display,22);
   if(node && TestField9CEqualsThree(node))selected=node;
   node=FindTwoHundredTwentyFourByteRecordByByteKey(display,30);
   if(node && TestField9CEqualsThree(node))selected=node;
   if(selected) {
    short x=*(short*)(selected+0xac),y=*(short*)(selected+0xae);
    unsigned char key=*(short*)(self+0x1012)-286;
    x*=8;y*=8;
    Graphics_SetIndexedRecordCoordinatesAndSubmit(self,x+3,y+3,data_ov003_0217fabd[key],6);
    return;
   }
  }
  if(*(void**)(self+0xff8) && *(short*)(self+0xffe)>=0) {
   char* selected=FindTwoHundredTwentyFourByteRecordByByteKey(display,14);
   if(selected && AreBothWordFieldsD4And9CNonzero(selected)) {
    short part=104;
    for(unsigned char i=0;i<8;part++,slot++,i++) {
     short x,y;
     Object_ComputeGroupAndPartScaledXY(display,14,part,&x,&y);
     Graphics_SetIndexedRecordCoordinatesAndSubmit(self,x,y-1,data_ov003_0217fa9c[i],slot);
    }
   }
  }
 }
}
