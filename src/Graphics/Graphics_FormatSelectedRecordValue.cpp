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
unsigned char* GameObject_GetLinkedIndexedState(void*);
char* GameObject_ResolveLinkedStatsOrNull(void*);
int ZoneSerializedRecord_GetPreferredAttribute(void*,int);
void __clear(void*,unsigned);
char* strcpy(char*,const char*);
int sprintf(char*,const char*,...);
extern Text8 Graphics_FormatSelectedRecordValue_TextNsbmd;
// Original data: arm9/main @ 0x20e883c; symbol: data_020e883c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 62626463630063656100.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Text10 GraphicsFormatSelectedRecordValue_UnknownRoleInitializedBytes;
extern char Graphics_FormatSelectedRecordValue_TextNsbtx[],Graphics_FormatSelectedRecordValue_FormatPC03DSSS[];
}
// Original: arm9/main @ 0x02072E94; symbol: func_02072e94; size: 0x24C.
extern "C" int Graphics_FormatSelectedRecordValue(char* output,int objectIndex,int mode,char* record,char* alternate) {
 void* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),objectIndex);
 unsigned char* fields=GameObject_GetLinkedIndexedState(object);
 char* info=GameObject_ResolveLinkedStatsOrNull(object);
 unsigned char which=((Flags*)(info+0x14))->primary;
 int value=ZoneSerializedRecord_GetPreferredAttribute(record,which);
 char* other=0;
 char* root=0;
 if(alternate) {root=alternate;other=alternate+0xe0;}
 Text8 label=Graphics_FormatSelectedRecordValue_TextNsbmd;
 char prefix[2]={0};
 char suffix[2]={0};
 if(mode==4) {
  strcpy(label.data,Graphics_FormatSelectedRecordValue_TextNsbtx);
  prefix[0]='a';prefix[1]=0;
  value+=((Nibble*)(info+0x15))->low;
 }
 int otherValue=-1;
 if(other && *(short*)(other+0x18)>-1)otherValue=ZoneSerializedRecord_GetPreferredAttribute(other,which);
 if(mode==3) {
  prefix[0]='a';prefix[1]=0;
  if(otherValue>=0) {
   int group=otherValue/100;
   if((unsigned)group<10) {
   Text10 table=GraphicsFormatSelectedRecordValue_UnknownRoleInitializedBytes;
   int letter=table.data[group];
   if(!letter)return 0;
   prefix[0]=letter;
   if(group==3 && !which && *(short*)(info+6)==9001)prefix[0]='f';
   } else return 0;
  }
 }
 if(mode==5 && root) {
  if(*(short*)(info+8)==8010 || *(short*)(info+8)<0)value=ZoneSerializedRecord_GetPreferredAttribute(root,which);
  strcpy(label.data,Graphics_FormatSelectedRecordValue_TextNsbtx);
 }
 if(mode==6)strcpy(label.data,Graphics_FormatSelectedRecordValue_TextNsbtx);
 if(*(short*)(record+0x18)==1000)value+=fields[0x56a];
 unsigned code=((Code*)(record+0x10))->value;
 sprintf(output,Graphics_FormatSelectedRecordValue_FormatPC03DSSS,(char)code,value,prefix,suffix,label.data);
 return 1;
}
