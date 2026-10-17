#include <globaldefs.h>
ARM
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void SetOneOfSixteenWordFieldsAtOffset8B0(unsigned*,int,unsigned);
extern "C" void Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(char*,int,int);
extern "C" void WriteBoundedIndexedByteAt902(char*,int,int);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,void*,void*,int,int,unsigned);
extern "C" char* strstr(const char*,const char*);
extern "C" int sprintf(char*,const char*,...);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadSupportedFirmwareLanguage(void*);
extern "C" int data_ov023_021fd75c[];
extern "C" char data_ov023_021fddb0[],data_ov023_021fddb4[];
// Original: arm9/ov023 @ 0x021E83C8; symbol: func_ov023_021e83c8; size: 0x174.
extern "C" void Resource_SetupTextAndLocalizedNumericFields(char* self) {
 char* state=(char*)ReadWordFieldAtOffset1C();
 int values[2]={*(unsigned short*)(self+0x60e),*(unsigned char*)(self+0x610)};
 int kinds[2]={data_ov023_021fd75c[14],data_ov023_021fd75c[15]};
 int* kindArray=kinds;
 for(int i=0;i<2;i++) {
  SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)state,i,values[i]);
  Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(state,i,1);
  WriteBoundedIndexedByteAt902(state,i,(unsigned char)kindArray[i]);
 }
 void* record=ResolveIndexedRecordAndReturnSecondWord(self+0x4c,0);
 ProcessSixStagesUsingSharedWordScratchBuffer(state,10,record,*(void**)(self+0x5d8),256,0,0);
 int a,b;
 char* first=strstr(*(char**)(self+0x5d8),data_ov023_021fddb0);
 char* second=strstr(first+1,data_ov023_021fddb0);
 a=130;b=180;
 switch(GameState_ReadSupportedFirmwareLanguage(_ZN9GameState11GetInstanceEv())){
 case 2:case 5:a=165;b=193;break;
 case 3:a=146;b=182;break;
 }
 char buf1[4],buf2[4];
 sprintf(buf1,data_ov023_021fddb4,a);
 sprintf(buf2,data_ov023_021fddb4,b);
 memcpy(first+3,buf1,3);
 memcpy(second+3,buf2,3);
}
