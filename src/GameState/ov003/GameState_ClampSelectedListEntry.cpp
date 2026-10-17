#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetIndexList(void*);
short CountPositiveSignedByteQuantities(void*,int);
int ReadNthPositiveHalfwordValue(void*,int,int);
unsigned char ReadGlobalElementI(unsigned);
int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
int Object_CountNonzeroFlagBytes(char*);
}
// Original: arm9/ov003 @ 0x02179FF0; symbol: func_ov003_02179ff0; size: 0x15C.
extern "C" void GameState_ClampSelectedListEntry(unsigned char* p) {
 unsigned char* group=*(unsigned char**)(p+0x89c);
 unsigned char* list=(unsigned char*)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
 if(*(short*)(p+0x100c)==0x77) {
  int base=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(group,0x1d);
  int kind=ReadGlobalElementI((short)(*(short*)(p+0x1012)-base));
  int count=CountPositiveSignedByteQuantities(list+0x1d4,kind);
  int offset=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(group,0x1e);
  short index=(short)(*(short*)(p+0x100e)-offset)+*(short*)(p+0x1014)*5;
  if(count<=index) index=count-1;
  *(short*)(p+0x103a)=ReadNthPositiveHalfwordValue(list+0x1d4,kind,index);
  int origin=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(group,0x1e);
  *(short*)(p+0x100e)=index%5+origin;
 } else {
  int count=Object_CountNonzeroFlagBytes((char*)list);
  int offset=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(group,0x16);
  short index=(short)(*(short*)(p+0x100e)-offset)+*(short*)(p+0x1014)*8;
  if(count<=index) index=count-1;
  *(short*)(p+0x103a)=*(short*)(list+index*2+0xc);
  int origin=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(group,0x16);
  *(short*)(p+0x100e)=index%8+origin;
 }
}
