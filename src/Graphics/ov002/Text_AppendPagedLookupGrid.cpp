#include <globaldefs.h>
ARM
extern "C" {
int AppendFiveFormattedArguments(char*,int,int,int,int,int);
int TextMarkup_AppendCursorTag(char*,int);
void* ReadGlobalValueAt02108844();
int Ov002_IncrementSigned16Except32(void*,int);
int Object_ReadIndexedLookupByte(void*,int);
int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
const char* ResolveIndexedRecordAndReturnSecondWord(void*,int);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
int AppendFormatText(char*,const char*);
void Util_SetRecordProgressFlags(void*,int,int,int);
extern char data_ov002_0216d2b4[];
}
// Original: arm9/ov002 @ 0x02160AA0; symbol: func_ov002_02160aa0; size: 0x1C8.
extern "C" void Text_AppendPagedLookupGrid(char* p,char* out,int format){
if(!out)return;
int cursor=*(short*)(p+0x1c0c);
int remainder=cursor%16;
int page=cursor/16;
cursor=remainder;
*(unsigned char*)(p+0x2484)=page;
if(format)AppendFiveFormattedArguments(out,cursor,8,5,5,5);
TextMarkup_AppendCursorTag(out,cursor);
short row=0;
unsigned char start=*(unsigned char*)(p+0x2484)<<4;
unsigned char end=start+16;
void* lookup=ReadGlobalValueAt02108844();
for(;start<end;start++){
int value=Object_ReadIndexedLookupByte(lookup,Ov002_IncrementSigned16Except32(p,start));
if(!value){
Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
Text_AppendFormattedIntegerAndStringFragment(out,row,ResolveIndexedRecordAndReturnSecondWord(p+0x20,0x119d));
}else if(*(unsigned*)(p+0x2480)&(1<<(value-1))){
Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
Text_AppendFormattedIntegerAndStringFragment(out,row,ResolveIndexedRecordAndReturnSecondWord(p+0x20,(short)(value+0x119d)));
}else{
Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
Text_AppendFormattedIntegerAndStringFragment(out,row,ResolveIndexedRecordAndReturnSecondWord(p+0x20,0x119c));
}
row++;
if(start&1)AppendFormatText(out,*(char**)(p+0x1bdc));else AppendFormatText(out,data_ov002_0216d2b4);
}
Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
Util_SetRecordProgressFlags(p,0x22,*(unsigned char*)(p+0x2484),2);
}
