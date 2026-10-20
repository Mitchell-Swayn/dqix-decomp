#include <globaldefs.h>
ARM
extern "C" int sprintf(char*,const char*,...);
extern "C" char* strcpy(char*,const char*);
extern "C" void __clear(void*,unsigned);
extern "C" unsigned ZoneSerializedRecord_GetPreferredAttribute(void*,int);
extern "C" char* ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" char Text_FormatSerializedRecordValue_TextNsbmd[],Text_FormatSerializedRecordValue_TextNsbtx[],Text_FormatSerializedRecordValue_TextBbdccfcea[],Text_FormatSerializedRecordValue_FormatDC03DSSS[],Text_FormatSerializedRecordValue_FormatPC03DSSS[];
struct Eight {char v[8];};struct Ten {char v[10];};
struct CodeBits {unsigned pad:20;unsigned code:8;unsigned rest:4;};
// Original: arm9/ov015 @ 0x0218C03C; symbol: func_ov015_0218c03c; size: 0x238.
extern "C" int Text_FormatSerializedRecordValue(char* self,char* out,int index,int alternate) {
 char* owner=*(char**)self;
 char* first=ZoneState2754_FindPrimaryRecordByKey(owner+0x4c,(short)(*(int**)(self+0x20))[index]);
 char* other=ZoneState2754_FindPrimaryRecordByKey(*(char**)self+0x4c,(short)(*(int**)(self+0x20))[7]);
 unsigned value=ZoneSerializedRecord_GetPreferredAttribute(first,*(unsigned char*)(self+0x3b));
 Ten letters;
 Eight suffix=*(Eight*)Text_FormatSerializedRecordValue_TextNsbmd;
 char prefix[2],extra[2];
 __clear(prefix,2);__clear(extra,2);
 switch(index) {
 case 4:
  strcpy(suffix.v,Text_FormatSerializedRecordValue_TextNsbtx);
  prefix[0]='a';prefix[1]=0;
  value+=*(unsigned char*)(self+0x3c);
  break;
 case 3:
  prefix[0]='a';prefix[1]=0;
  if(other && *(short*)(other+0x18)>-1) {
   unsigned digit=(int)ZoneSerializedRecord_GetPreferredAttribute(other,*(unsigned char*)(self+0x3b))/100;
   if(digit>=10)return 0;
   letters=*(Ten*)Text_FormatSerializedRecordValue_TextBbdccfcea;
   char ch=letters.v[digit];
   if(!ch)return 0;
   prefix[0]=ch;
   if(digit==3 && !*(unsigned char*)(self+0x3b) && *(short*)(first+0x18)==0x2329)prefix[0]='f';
  }
  break;
 case 5:case 6:
  if(alternate)strcpy(suffix.v,Text_FormatSerializedRecordValue_TextNsbtx);
  break;
 }
 if(!alternate)sprintf(out,Text_FormatSerializedRecordValue_FormatDC03DSSS,(signed char)((CodeBits*)(first+0x10))->code,value,prefix,extra,suffix.v);
 else sprintf(out,Text_FormatSerializedRecordValue_FormatPC03DSSS,(signed char)((CodeBits*)(first+0x10))->code,value,prefix,extra,suffix.v);
 return 1;
}
