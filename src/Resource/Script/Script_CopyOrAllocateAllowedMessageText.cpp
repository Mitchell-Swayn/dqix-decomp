#pragma opt_repositioncode off
#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"
#include <std_library_functions.h>
struct State {unsigned char count;char pad;unsigned short idsCount;char* destination;short* ids;SafeAllocator* allocator;void* context;};
struct Message {short id;short pad;char* text;};
extern "C" State data_02108db0;
extern "C" char data_020f0cf0[];
extern "C" unsigned int String_CountBytesUntilTerminator(const char*);
extern "C" void AppendEightByteRecordWithinCapacity(void*,Message*);
// Original: arm9/main @ 0x0207267C; symbol: func_0207267c; size: 0x15C.
extern "C" ARM int Script_CopyOrAllocateAllowedMessageText(Script::Parameter* params) {
 Script::Parameter* first=params;
 Message message;message.text=0;++params;message.id=first->ToInt();
 bool allowed=true;
 if(data_02108db0.ids && data_02108db0.idsCount) {
  allowed=false;
  for(unsigned short i=0;i<data_02108db0.idsCount;++i)if(message.id==data_02108db0.ids[i])allowed=true;
 }
 if(!allowed)return 1;
 for(unsigned char i=0;i<data_02108db0.count;++i){params->ToString();++params;}
 register int length;
 const char* source=params->ToString();
 if(data_02108db0.destination) {if(source)strcpy(data_02108db0.destination,source);return 1;}
 length=0;if(source)length=String_CountBytesUntilTerminator(source);
 message.text=(char*)data_02108db0.allocator->Allocate(length+1);if(!message.text)return 0;
 message.text[length]=0;if(message.text)sprintf(message.text,data_020f0cf0,source);
 AppendEightByteRecordWithinCapacity(data_02108db0.context,&message);return 1;
}
