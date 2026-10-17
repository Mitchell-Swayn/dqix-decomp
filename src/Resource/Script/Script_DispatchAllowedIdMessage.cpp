#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct Config {short count,pad;short* ids;SafeAllocator* allocator;void* context;};
struct Message {short first,second;char* text;};
extern "C" Config data_0214e33c;
extern "C" char data_020f2330[];
extern "C" int String_CountBytesUntilTerminator();
extern "C" void AllocateAndAppendTwelveByteCopiedNode(void*,Message*);
// Original: arm9/main @ 0x020D7754; symbol: func_020d7754; size: 0xF8.
extern "C" int Script_DispatchAllowedIdMessage(Script::Parameter* parameters) {Message message;message.text=0;message.first=parameters[0].ToInt();message.second=parameters[1].ToInt();bool allowed=true;if(data_0214e33c.ids&&data_0214e33c.count){allowed=false;for(unsigned short i=0;i<data_0214e33c.count;i++)if(message.first==data_0214e33c.ids[i])allowed=true;}if(!allowed)return 1;const char* text=parameters[2].ToString();int size=String_CountBytesUntilTerminator();message.text=(char*)data_0214e33c.allocator->Allocate(size+1);if(!message.text)return 0;message.text[size]=0;sprintf(message.text,data_020f2330,text);AllocateAndAppendTwelveByteCopiedNode(data_0214e33c.context,&message);return 1;}
