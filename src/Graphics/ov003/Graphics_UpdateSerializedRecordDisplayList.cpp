#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetIndexList(void*);
int ReadNthPositiveHalfwordValue(void*,int,int);
int ReadNthPositiveSignedByteFromSelectedArray(void*,int,int);
unsigned char ReadGlobalElementI(unsigned);
void SetKeyedRecordFlagMask40(unsigned char*,int);
void SetFlagTwoForEachListedId(unsigned char*,int);
void SetKeyedRecordFlagMaskTwo(unsigned char*,int);
void SetKeyedRecordFlagMaskOne(unsigned char*,int);
void ClearFlagMaskOneForEachGroupRecord(unsigned char*,int);
void ClearResolvedEntryByteC5Bit20(unsigned char*,int);
void Object_SetGroupNibbleAndTextureLowFourBits(char*,int,unsigned char);
void SetKeyedRecordFirstWord(char*,int,int);
void Object_SetSelectedPartInitialWord(char*,int,int);
void* Object_ResolveSelectedPartMessageId(char*,int);
void Object_SetSelectedGroupBooleanFlag(char*,int,int);
int Object_CreateAndConfigureSelectedDisplayPart(char*,int);
int Object_CountNonzeroFlagBytes(char*);
char* FindSerializedPrimaryRecordByKey(void*,int);
int func_ov003_02175f90(void*);
void Graphics_ConfigureSelectedPartModes(void*,void*,int,int);
}
// Original: arm9/ov003 @ 0x02177DD4; symbol: func_ov003_02177dd4; size: 0x3B8.
extern "C" void Graphics_UpdateSerializedRecordDisplayList(char* p){
 char* list; int selected; short title,fourth,pagePart,pageCountPart,message; int count; short* keys; signed char* values; int word,half;char* record; int value;
 list=(char*)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
 selected=0;
 keys=0;values=0;
 char* display=*(char**)(p+0x89c);
 int group=0x16;short first=0xa7,second=0xaf,third=0xb7,fifth=0xc7;
 title=0xa6;fourth=0xbf;pagePart=0xcf;pageCountPart=0xd0;
 short rows=8;
 if(*(short*)(p+0x100c)==0x77){
 group=(short)(*(short*)(p+0x1012)-0x11e);
 selected=ReadGlobalElementI(group);
 count=func_ov003_02175f90(p);
 *(short*)(p+0x1016)=(count+4)/5;
 if(*(short*)(p+0x1016)==0)*(short*)(p+0x1016)=1;
 message=(short)(group+0x11e);
 group=0x1e;title=0x126;first=0x127;second=0x12c;third=0x131;fourth=0x136;fifth=0x13b;pagePart=0x140;pageCountPart=0x141;rows=5;
 }else{
 count=Object_CountNonzeroFlagBytes(list);
 keys=(short*)(list+0xc);values=(signed char*)(list+0x13c);message=0x7a;
 }
 ClearResolvedEntryByteC5Bit20((unsigned char*)display,group);
 Object_SetGroupNibbleAndTextureLowFourBits(display,group,0);
 ClearFlagMaskOneForEachGroupRecord((unsigned char*)display,group);
 SetFlagTwoForEachListedId((unsigned char*)display,group);
 Object_SetSelectedGroupBooleanFlag(display,group,rows<count);
 short start=(short)(*(short*)(p+0x1014)*rows);
 short end=(short)(start+rows);
 for(short i=start;i<end;i++){
 if(count<=i){
 SetKeyedRecordFlagMaskTwo((unsigned char*)display,first);
 SetKeyedRecordFlagMaskOne((unsigned char*)display,first);
 SetKeyedRecordFlagMaskOne((unsigned char*)display,second);
 SetKeyedRecordFlagMaskOne((unsigned char*)display,third);
 SetKeyedRecordFlagMaskOne((unsigned char*)display,fourth);
 SetKeyedRecordFlagMaskOne((unsigned char*)display,fifth);
 }else{
 word=0;half=0;int key;
 if(keys)key=keys[i];else key=ReadNthPositiveHalfwordValue(list+0x1d4,selected,i);
 record=FindSerializedPrimaryRecordByKey(p+0x874,key);
 if(record){word=*(int*)(record+4);half=*(unsigned short*)(record+0x1a);}
 if(values)value=values[i];else value=ReadNthPositiveSignedByteFromSelectedArray(list+0x1d4,selected,i);
 Graphics_ConfigureSelectedPartModes(p,record,second,third);
 SetKeyedRecordFlagMask40((unsigned char*)display,first);
 SetKeyedRecordFirstWord(display,first,word);
 Object_SetSelectedPartInitialWord(display,second,half);
 Object_SetSelectedPartInitialWord(display,fifth,value);
 }
 first++;second++;third++;fourth++;fifth++;
 }
 SetKeyedRecordFirstWord(display,title,(int)Object_ResolveSelectedPartMessageId(display,message));
 Object_SetSelectedPartInitialWord(display,pagePart,*(short*)(p+0x1014)+1);
 Object_SetSelectedPartInitialWord(display,pageCountPart,*(short*)(p+0x1016));
 Object_CreateAndConfigureSelectedDisplayPart(display,group);
}
