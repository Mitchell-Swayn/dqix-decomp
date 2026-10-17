#include <globaldefs.h>
ARM
extern "C" {
unsigned char* FindTwoHundredTwentyFourByteRecordByByteKey(unsigned char*,unsigned);
int AreBothWordFieldsD4And9CNonzero(char*);
int ReadSelectedCoordinatePair(void*,int*,int*);
int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);
char* func_ov014_021873a0(char*);
void* Util_FilterAndRebuildNodeList(void*,int,int,int,int,short*);
void func_ov014_02187228(char*,char*);
void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);
void Object_ClearBit4OnReferencedGroupParts(unsigned char*,int);
void func_ov014_0218854c(char*);
void func_ov014_021885bc(char*);
extern unsigned char data_02114e54[];
extern char data_02114e30[],data_02108760[];
}
struct NodeFlags { unsigned char a:1; unsigned char enabled:1; unsigned char b:6; };
// Original: arm9/ov014 @ 0x02187074; symbol: func_ov014_02187074; size: 0x1B4.
extern "C" int Graphics_ToggleSelectionFromTouchOrButton(char* self) {
 int active=0;
 char* record=(char*)FindTwoHundredTwentyFourByteRecordByByteKey(*(unsigned char**)(self+0xc0),4);
 if(record && AreBothWordFieldsD4And9CNonzero(record)) {
  short bottom=*(short*)(record+0xae);
  short height=*(short*)(record+0xaa);
  bottom--;
  height++;
  short x=*(short*)(record+0xac);
  short width=*(short*)(record+0xa8);
  x*=8;
  bottom*=8;
  short right=x+(short)(width*8);
  short end=bottom+(short)(height*8);
  if(data_02114e54[0x55]) {
   int px,py;
   ReadSelectedCoordinatePair(data_02114e54,&px,&py);
   if(x<=px && px<right && bottom<=py && py<end)active=1;
  }
 }
 if(Object_TestNewlySetHalfwordMask((unsigned short*)data_02114e30,4))active=1;
 if(active) {
  char* target=func_ov014_021873a0(self);
  if(!target)return 0;
  if(!((NodeFlags*)(target+0x13))->enabled) {
   *(short*)(self+0x176)=-1;
   *(short*)(self+0x178)=-1;
   target=0;
  }
  if((*(unsigned char*)(self+0x17e))&8)(*(unsigned char*)(self+0x17e))&=~8;
  else (*(unsigned char*)(self+0x17e))|=8;
  short value=0;
  *(void**)(self+0xb8)=Util_FilterAndRebuildNodeList(self+0xa4,*(signed char*)(self+0x17d),-1,((*(unsigned char*)(self+0x17e))&8)!=0,16,&value);
  func_ov014_02187228(self,target);
  DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
  Object_ClearBit4OnReferencedGroupParts(*(unsigned char**)(self+0xc0),5);
  func_ov014_0218854c(self);
  func_ov014_021885bc(self);
 }
 return active;
}
