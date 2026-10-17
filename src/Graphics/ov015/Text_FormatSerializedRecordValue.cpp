#include <globaldefs.h>
ARM
extern "C" int sprintf(char*,const char*,...);
extern "C" char* strcpy(char*,const char*);
extern "C" void __clear(void*,unsigned);
extern "C" unsigned ReadPreferredHalfwordOrAlternateWith999Sentinel(void*,int);
extern "C" char* FindSerializedPrimaryRecordByKey(void*,int);
extern "C" char data_ov015_02193cd4[],data_ov015_02193fe4[],data_ov015_02193ce5[],data_ov015_02193fea[],data_ov015_02193ffa[];
struct Eight {char v[8];};struct Ten {char v[10];};
struct CodeBits {unsigned pad:20;unsigned code:8;unsigned rest:4;};
// Original: arm9/ov015 @ 0x0218C03C; symbol: func_ov015_0218c03c; size: 0x238.
extern "C" int Text_FormatSerializedRecordValue(char* self,char* out,int index,int alternate) {
 char* owner=*(char**)self;
 char* first=FindSerializedPrimaryRecordByKey(owner+0x4c,(short)(*(int**)(self+0x20))[index]);
 char* other=FindSerializedPrimaryRecordByKey(*(char**)self+0x4c,(short)(*(int**)(self+0x20))[7]);
 unsigned value=ReadPreferredHalfwordOrAlternateWith999Sentinel(first,*(unsigned char*)(self+0x3b));
 Ten letters;
 Eight suffix=*(Eight*)data_ov015_02193cd4;
 char prefix[2],extra[2];
 __clear(prefix,2);__clear(extra,2);
 switch(index) {
 case 4:
  strcpy(suffix.v,data_ov015_02193fe4);
  prefix[0]='a';prefix[1]=0;
  value+=*(unsigned char*)(self+0x3c);
  break;
 case 3:
  prefix[0]='a';prefix[1]=0;
  if(other && *(short*)(other+0x18)>-1) {
   unsigned digit=(int)ReadPreferredHalfwordOrAlternateWith999Sentinel(other,*(unsigned char*)(self+0x3b))/100;
   if(digit>=10)return 0;
   letters=*(Ten*)data_ov015_02193ce5;
   char ch=letters.v[digit];
   if(!ch)return 0;
   prefix[0]=ch;
   if(digit==3 && !*(unsigned char*)(self+0x3b) && *(short*)(first+0x18)==0x2329)prefix[0]='f';
  }
  break;
 case 5:case 6:
  if(alternate)strcpy(suffix.v,data_ov015_02193fe4);
  break;
 }
 if(!alternate)sprintf(out,data_ov015_02193fea,(signed char)((CodeBits*)(first+0x10))->code,value,prefix,extra,suffix.v);
 else sprintf(out,data_ov015_02193ffa,(signed char)((CodeBits*)(first+0x10))->code,value,prefix,extra,suffix.v);
 return 1;
}
