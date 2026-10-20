#include <globaldefs.h>
ARM
struct T;
extern "C" {
void* memcpy(void*,const void*,unsigned); unsigned strlen(const char*);
unsigned TextContext_GetSharedInstance();
void TextLayout_ResetFormattingWorkspace(signed char*);
void TextContext_SetNumericArgument(unsigned*,int,unsigned);
unsigned MessageTextTable_FindTextById(T*,int);
void* Filesystem_FindTypeFourEmbeddedValue(void*,unsigned short);
}
// Original: arm9/ov004 @ 0x02157374; symbol: func_ov004_02157374; size: 0x4A8.
// Chooses a resource message by signed identifier ranges, optionally suppresses specialized messages, and copies its bytes.
extern "C" void CopyIdentifierClassMessage(void* state,int id,int mode,char* destination,unsigned char genericOnly){
 if(id<=0)return;
 T* table=(T*)Filesystem_FindTypeFourEmbeddedValue(state,4);
 bool generic=false;
 const char* text;
 if((id>=20000 && id<=20100) ||
    (id>=20102 && id<=20107) ||
    id==20109 ||
    (id>=20111 && id<=20999) ||
    (id>=52004 && id<=52009) ||
    (id>=52013 && id<52100) ||
    (id>=52104 && id<=52109) ||
    (id>=52113 && id<52200) ||
    (id>=52204 && id<=52209) ||
    (id>=52213 && id<52400) ||
    (id>=53000 && id<53300)) text=(const char*)MessageTextTable_FindTextById(table,100);
 else if(id==20101 || (id>=23000 && id<24000)) text=(const char*)MessageTextTable_FindTextById(table,101);
 else if(id==20108) text=(const char*)MessageTextTable_FindTextById(table,102);
 else if(id==20110) text=(const char*)MessageTextTable_FindTextById(table,103);
 else if(id>=51200 && id<51300) text=(const char*)MessageTextTable_FindTextById(table,104);
 else if(id>=50000 && id<50100) text=(const char*)MessageTextTable_FindTextById(table,105);
 else if((id>=51000 && id<=51102) || (id>=51104 && id<51200) || (id>=51300 && id<51400)) text=(const char*)MessageTextTable_FindTextById(table,106);
 else if(id==51103) text=(const char*)MessageTextTable_FindTextById(table,106);
 else if((id>=52000 && id<=52003) ||
    (id>=52010 && id<=52012) ||
    (id>=52100 && id<=52103) ||
    (id>=52110 && id<=52112) ||
    (id>=52200 && id<=52203) ||
    (id>=52210 && id<=52212) ||
    (id>=52400 && id<=52403) ||
    (id>=52410 && id<=52412) ||
    (id>=52500 && id<=52503) ||
    (id>=52510 && id<=52512) ||
    (id>=52700 && id<=52703) ||
    (id>=52710 && id<=52712))text=(const char*)MessageTextTable_FindTextById(table,108);
 else {
  generic=true;
  if(mode==2) text=(const char*)MessageTextTable_FindTextById(table,112);
  else if(id>=31000 && id<32000)text=(const char*)MessageTextTable_FindTextById(table,111);
  else text=(const char*)MessageTextTable_FindTextById(table,110);
 }
 if(genericOnly && !generic)return;
 if(!text)return;
 unsigned* owner=(unsigned*)TextContext_GetSharedInstance();
 TextLayout_ResetFormattingWorkspace((signed char*)owner);
 TextContext_SetNumericArgument(owner,0,id);
 memcpy(destination,text,strlen(text));
}
