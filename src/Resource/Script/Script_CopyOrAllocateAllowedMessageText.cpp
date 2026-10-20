#pragma opt_repositioncode off
#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"
#include <std_library_functions.h>
struct State {unsigned char count;char pad;unsigned short idsCount;char* destination;short* ids;SafeAllocator* allocator;void* context;};
struct Message {short id;short pad;char* text;};
// Original data: arm9/main @ 0x2108db0; symbol: data_02108db0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20f0cf0; symbol: data_020f0cf0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25730000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ScriptCopyOrAllocateAllowedMessageText_UnknownRoleInitializedBytes[];
extern "C" unsigned int String_CountBytesUntilTerminator(const char*);
extern "C" void MessageTextTable_AppendTextEntry(void*,Message*);
// Original: arm9/main @ 0x0207267C; symbol: func_0207267c; size: 0x15C.
extern "C" ARM int Script_CopyOrAllocateAllowedMessageText(Script::Parameter* params) {
 Script::Parameter* first=params;
 Message message;message.text=0;++params;message.id=first->ToInt();
 bool allowed=true;
 if(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.ids && ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.idsCount) {
  allowed=false;
  for(unsigned short i=0;i<ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.idsCount;++i)if(message.id==ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.ids[i])allowed=true;
 }
 if(!allowed)return 1;
 for(unsigned char i=0;i<ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.count;++i){params->ToString();++params;}
 register int length;
 const char* source=params->ToString();
 if(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.destination) {if(source)strcpy(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.destination,source);return 1;}
 length=0;if(source)length=String_CountBytesUntilTerminator(source);
 message.text=(char*)ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.allocator->Allocate(length+1);if(!message.text)return 0;
 message.text[length]=0;if(message.text)sprintf(message.text,ScriptCopyOrAllocateAllowedMessageText_UnknownRoleInitializedBytes,source);
 MessageTextTable_AppendTextEntry(ScriptCopyOrAllocateAllowedMessageText_UnknownRoleZeroInitializedStorage.context,&message);return 1;
}
