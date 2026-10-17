#include <globaldefs.h>
ARM
struct Code { unsigned pad:20; unsigned value:8; unsigned rest:4; };
struct Flags { unsigned char primary:1; unsigned char a:7; };
struct Nibble { unsigned char low:4; unsigned char high:4; };
struct Text8 { char data[8]; };
struct Text10 { char data[10]; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetObjectWithFlag100(void*,int);
unsigned char* ReadWordFieldAtOffset150(void*);
char* GetIndirectField150Address488(void*);
int ReadPreferredHalfwordOrAlternateWith999Sentinel(void*,int);
void __clear(void*,unsigned);
char* strcpy(char*,const char*);
int sprintf(char*,const char*,...);
extern Text8 data_020e8834;
extern Text10 data_020e883c;
extern char data_020f0d04[],data_020f0d0a[];
}
// Original: arm9/main @ 0x02072E94; symbol: func_02072e94; size: 0x24C.
extern "C" int Graphics_FormatSelectedRecordValue(char* output,int objectIndex,int mode,char* record,char* alternate) {
 void* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),objectIndex);
 unsigned char* fields=ReadWordFieldAtOffset150(object);
 char* info=GetIndirectField150Address488(object);
 unsigned char which=((Flags*)(info+0x14))->primary;
 int value=ReadPreferredHalfwordOrAlternateWith999Sentinel(record,which);
 char* other=0;
 char* root=0;
 if(alternate) {root=alternate;other=alternate+0xe0;}
 Text8 label=data_020e8834;
 char prefix[2]={0};
 char suffix[2]={0};
 if(mode==4) {
  strcpy(label.data,data_020f0d04);
  prefix[0]='a';prefix[1]=0;
  value+=((Nibble*)(info+0x15))->low;
 }
 int otherValue=-1;
 if(other && *(short*)(other+0x18)>-1)otherValue=ReadPreferredHalfwordOrAlternateWith999Sentinel(other,which);
 if(mode==3) {
  prefix[0]='a';prefix[1]=0;
  if(otherValue>=0) {
   int group=otherValue/100;
   if((unsigned)group<10) {
   Text10 table=data_020e883c;
   int letter=table.data[group];
   if(!letter)return 0;
   prefix[0]=letter;
   if(group==3 && !which && *(short*)(info+6)==9001)prefix[0]='f';
   } else return 0;
  }
 }
 if(mode==5 && root) {
  if(*(short*)(info+8)==8010 || *(short*)(info+8)<0)value=ReadPreferredHalfwordOrAlternateWith999Sentinel(root,which);
  strcpy(label.data,data_020f0d04);
 }
 if(mode==6)strcpy(label.data,data_020f0d04);
 if(*(short*)(record+0x18)==1000)value+=fields[0x56a];
 unsigned code=((Code*)(record+0x10))->value;
 sprintf(output,data_020f0d0a,(char)code,value,prefix,suffix,label.data);
 return 1;
}
