#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct Config {short count,pad;short* ids;SafeAllocator* allocator;void* context;};
struct Message {short first,second;char* text;};
// Original data: arm9/main @ 0x214e33c; symbol: data_0214e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Config LoadFileIntoMemory_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f2330; symbol: data_020f2330.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25730000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ScriptDispatchAllowedIdMessage_UnknownRoleInitializedBytes[];
extern "C" int String_CountBytesUntilTerminator();
extern "C" void AllocateAndAppendTwelveByteCopiedNode(void*,Message*);
// Original: arm9/main @ 0x020D7754; symbol: func_020d7754; size: 0xF8.
extern "C" int Script_DispatchAllowedIdMessage(Script::Parameter* parameters) {Message message;message.text=0;message.first=parameters[0].ToInt();message.second=parameters[1].ToInt();bool allowed=true;if(LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.ids&&LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.count){allowed=false;for(unsigned short i=0;i<LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.count;i++)if(message.first==LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.ids[i])allowed=true;}if(!allowed)return 1;const char* text=parameters[2].ToString();int size=String_CountBytesUntilTerminator();message.text=(char*)LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.allocator->Allocate(size+1);if(!message.text)return 0;message.text[size]=0;sprintf(message.text,ScriptDispatchAllowedIdMessage_UnknownRoleInitializedBytes,text);AllocateAndAppendTwelveByteCopiedNode(LoadFileIntoMemory_UnknownRoleZeroInitializedStorage.context,&message);return 1;}
