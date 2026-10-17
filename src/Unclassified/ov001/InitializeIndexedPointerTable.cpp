#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Entry { void* value; int index; };
extern "C" void* data_ov001_02165d74[];
extern "C" Entry data_ov001_02164d6c[];
extern "C" void Script_SetOpcodeHandlerTable(void*,void**,int);
// Original: arm9/ov001 @ 0x02164114; symbol: func_ov001_02164114; size: 0x80.
extern "C" void InitializeIndexedPointerTable(void* self) {
 memset(data_ov001_02165d74,0,4000);
 Entry* p=data_ov001_02164d6c;
 while(p) {
  void* value=p->value;
  if(!value) break;
  int index=p->index;
  if(index>=0 && index<1000) {
   if(data_ov001_02165d74[index]) { for(;;) {} }
   data_ov001_02165d74[index]=value;
  }
  p++;
 }
 Script_SetOpcodeHandlerTable(self,data_ov001_02165d74,1000);
}
