#include <globaldefs.h>
ARM
#include <Resource/Script.h>
#include <World/Zone3DEmbeddedState.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
// Original data: arm9/main @ 0x2108ce0; symbol: data_02108ce0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned ScriptPrependLabelNodeForValidEntry_UnknownRoleZeroInitializedStorage[];extern "C" unsigned char* Zone3D_GetMainInstance();extern "C" int func_020981e4(void*,unsigned),func_02098268(void*,int),LinkedList_FindNodeByUnsignedKey(unsigned,int);
// Original: arm9/main @ 0x02064D48; symbol: func_02064d48; size: 0xD8.
extern "C" int Script_PrependLabelNodeForValidEntry(Script::Parameter* params){int id=params->ToInt();unsigned char* zone=Zone3D_GetMainInstance();if(((ZoneState0840*)(zone+0x840))->IsValueInRangeC3b5(*(unsigned short*)zone)&&((ZoneState0840*)(zone+0x840))->IsEntryStateValid(id))return 1;if(!LinkedList_FindNodeByUnsignedKey(ScriptPrependLabelNodeForValidEntry_UnknownRoleZeroInitializedStorage[1],id))return 1;unsigned char* node=(unsigned char*)((SafeAllocator*)ScriptPrependLabelNodeForValidEntry_UnknownRoleZeroInitializedStorage[0])->Allocate(20);if(!node)return 0;*(short*)node=id;node[2]=params[1].ToInt();params[2].ToString();const char* text=params[3].ToString();if(text)strcpy((char*)node+4,text);node[3]=params[4].ToInt();unsigned* head=(unsigned*)ScriptPrependLabelNodeForValidEntry_UnknownRoleZeroInitializedStorage[2];*(unsigned*)(node+16)=*head;*head=(unsigned)node;return 1;}
