#include <globaldefs.h>
ARM
struct FilterNode; struct FilterList; struct Owner;
extern "C" char data_02108760[];
extern "C" unsigned short data_02114e30[];
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);
extern "C" void ResolveAndResetPresentEntry(unsigned char*,int);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
extern "C" void ResetPointedHalfwordAndSynchronizeSignedByteState(unsigned char*);
extern "C" FilterNode* Util_FilterAndRebuildNodeList(FilterList*,int,int,int,short,short*);
extern "C" int func_ov014_02186f10(Owner*);
extern "C" int func_ov014_02186ff0(Owner*);
extern "C" short func_ov014_021874f8(Owner*);
extern "C" void func_ov014_02188330(Owner*,unsigned);
// Original: arm9/ov014 @ 0x02187DB8; symbol: func_ov014_02187db8; size: 0x258.
extern "C" void Graphics_UpdateFilteredDisplaySelection(char* p) {
 if(*(unsigned char*)(p+0x17b)==0) {
  if(*(unsigned char*)(p+0x17e)&0x10) return;
  *(short*)(p+0x170)=2;
  if(*(short*)(p+0x174)<0) *(short*)(p+0x174)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(*(unsigned char**)(p+0xc0),*(short*)(p+0x170));
  Object_CreateAndConfigureSelectedDisplayPart(*(char**)(p+0xc0),*(short*)(p+0x170));
  *(signed char*)(p+0x17d)=*(short*)(p+0x174)-11;
  short count=0;
  *(unsigned*)(p+0xb8)=(unsigned)Util_FilterAndRebuildNodeList((FilterList*)(p+0xa4),*(signed char*)(p+0x17d),-1,(*(unsigned char*)(p+0x17e)&8)!=0,16,&count);
  unsigned list=*(unsigned*)(p+0xb8);
  *(unsigned*)(p+0xbc)=list; func_ov014_02188330((Owner*)p,list);
  ++*(unsigned char*)(p+0x17b);
 } else if(*(unsigned char*)(p+0x17b)==1) {
  *(short**)(p+0xd0)=(short*)(p+0x174);
  *(signed char*)(p+0x17d)=*(short*)(p+0x174)-11;
  if(*(int*)(p+0x160)!=0 || *(short*)(p+0x178)!=**(short**)(p+0xd0)) {
   short count=0;
   *(unsigned*)(p+0xb8)=(unsigned)Util_FilterAndRebuildNodeList((FilterList*)(p+0xa4),*(signed char*)(p+0x17d),-1,(*(unsigned char*)(p+0x17e)&8)!=0,16,&count);
   unsigned list=*(unsigned*)(p+0xb8);
  *(unsigned*)(p+0xbc)=list; func_ov014_02188330((Owner*)p,list);
  }
  if(func_ov014_02186f10((Owner*)p)) {
   DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
   ResetPointedHalfwordAndSynchronizeSignedByteState((unsigned char*)p+0x14c);
   if(func_ov014_021874f8((Owner*)p)) {
    ResolveAndResetPresentEntry(*(unsigned char**)(p+0xc0),*(short*)(p+0x170));
    *(void**)(p+0xd0)=0;
    *(unsigned char*)(p+0x17a)=4; *(unsigned char*)(p+0x17b)=0;
    *(unsigned char*)(p+0x17e)|=0x10;
   }
  } else if(func_ov014_02186ff0((Owner*)p)) {
   ResolveAndResetPresentEntry(*(unsigned char**)(p+0xc0),*(short*)(p+0x170));
   *(short*)(p+0x174)=-1; *(signed char*)(p+0x17d)=-1;
   *(unsigned char*)(p+0x17a)=2; *(unsigned char*)(p+0x17b)=0;
  } else if(Object_TestNewlySetHalfwordMask(data_02114e30,0x800)) {
   ResolveAndResetPresentEntry(*(unsigned char**)(p+0xc0),*(short*)(p+0x170));
   *(short*)(p+0x174)=-1; *(signed char*)(p+0x17d)=-1;
   *(unsigned char*)(p+0x17a)=5; *(unsigned char*)(p+0x17b)=0;
  }
 }
}
