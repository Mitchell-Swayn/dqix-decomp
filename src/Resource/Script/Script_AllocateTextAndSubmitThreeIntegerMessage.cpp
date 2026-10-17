#pragma thumb off
#pragma optimization_level 2

#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct Message{int unused,third,first,second;char* text;};
extern "C" {unsigned String_CountBytesUntilTerminator(const char*);void* memset(void*,int,unsigned);int sprintf(char*,const char*,...);void AppendFiveFieldRecordWithinCapacity(void*,const Message*);extern void* data_021536c4[2];}
// Original: arm9/main @ 0x020E5750; symbol: func_020e5750; size: 0x90.
extern "C" int Script_AllocateTextAndSubmitThreeIntegerMessage(const Script::Parameter* args){Message message;memset(&message,0,20);message.first=args[0].ToInt();message.second=args[1].ToInt();message.third=args[2].ToInt();const char* format=args[3].ToString();if(format){unsigned length=String_CountBytesUntilTerminator(format);message.text=(char*)((SafeAllocator*)data_021536c4[0])->Allocate(length+1);sprintf(message.text,format);}AppendFiveFieldRecordWithinCapacity(data_021536c4[1],&message);return 1;}
