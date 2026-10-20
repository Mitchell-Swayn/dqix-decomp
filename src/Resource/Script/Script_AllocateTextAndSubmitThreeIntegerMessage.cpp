#pragma thumb off
#pragma optimization_level 2

#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct Message{int unused,third,first,second;char* text;};
// Original data: arm9/main @ 0x21536c4; symbol: data_021536c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {unsigned String_CountBytesUntilTerminator(const char*);void* memset(void*,int,unsigned);int sprintf(char*,const char*,...);void VideoCaptions_AppendEntryIfSpace(void*,const Message*);extern void* ScriptExecuteCodeWithTwoOwnersAndReturnZero_UnknownRoleZeroInitializedStorage[2];}
// Original: arm9/main @ 0x020E5750; symbol: func_020e5750; size: 0x90.
extern "C" int Script_AllocateTextAndSubmitThreeIntegerMessage(const Script::Parameter* args){Message message;memset(&message,0,20);message.first=args[0].ToInt();message.second=args[1].ToInt();message.third=args[2].ToInt();const char* format=args[3].ToString();if(format){unsigned length=String_CountBytesUntilTerminator(format);message.text=(char*)((SafeAllocator*)ScriptExecuteCodeWithTwoOwnersAndReturnZero_UnknownRoleZeroInitializedStorage[0])->Allocate(length+1);sprintf(message.text,format);}VideoCaptions_AppendEntryIfSpace(ScriptExecuteCodeWithTwoOwnersAndReturnZero_UnknownRoleZeroInitializedStorage[1],&message);return 1;}
