#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" const char* ResolveIndexedRecordAndReturnSecondWord(void*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFormatText(char*,const char*);
extern "C" unsigned char* FindReadyRecordByIdBeforeStopIndex(void*,unsigned);
extern "C" void WriteFieldD8Bit0AndResetProgress(unsigned char*,unsigned);
extern "C" void SetMaskedFlagsAtOffsetD9(unsigned char*,int);
extern "C" void Object_SetElement218AndSetElement216To2(unsigned char*,unsigned char);
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(void*,unsigned,void*,unsigned,unsigned char);
extern "C" const char data_ov003_02180c7f[];
// Original: arm9/ov003 @ 0x0217DFB4; symbol: func_ov003_0217dfb4; size: 0x14C.
extern "C" void Text_RefreshSixEntryPage(char* self) {
 ReadGlobalValueAt020FB3F0(); ReadWordFieldAtOffset1C();
 char text[1024]; __clear(text,1024);
 char* owner=*(char**)(self+0x90);
 int end,i; int page=*(int*)(owner+0x68);
 end=(page+1)*6;
 if(end>*(unsigned char*)(self+0x30))end=*(unsigned char*)(self+0x30);
 if(*(int*)(self+0x14)==2)AppendFiveFormattedArguments(text,Selection_ReadEnabledIndexFromControl(owner)%6,8,5,5,5);
 for(i=page*6;i<end;i++) {
 const char* label=ResolveIndexedRecordAndReturnSecondWord(self+0xcc,(short)(*(unsigned char*)(self+i+0x18)+100));
 Text_AppendFormattedIntegerAndStringFragment(text,i%6,label);
 if(i!=end-1)AppendFormatText(text,data_ov003_02180c7f);
 }
 if(*(unsigned char*)(self+0x32)>1) {
 unsigned char* record=FindReadyRecordByIdBeforeStopIndex(*(void**)(self+0x90),0);
 if(record) {
 WriteFieldD8Bit0AndResetProgress(record,1);
 SetMaskedFlagsAtOffsetD9(record,(unsigned char)page);
 Object_SetElement218AndSetElement216To2(record,*(unsigned char*)(self+0x32));
 }
 }
 LoadMatchingReadyRecordAndRefreshOwner(*(void**)(self+0x90),0,text,1,0);
}
