#include <globaldefs.h>
ARM
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2109bac; symbol: data_02109bac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char** MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage;extern "C" void Script_SetWeightedGroupEntry(void*,unsigned,int,void*);extern "C" unsigned char* Script_GetWeightedGroupByIndex(void*,unsigned);struct Packet{int value;unsigned short a:8,b:8;};
// Original: arm9/main @ 0x0209AD40; symbol: func_0209ad40; size: 0xD0.
extern "C" int Script_BuildPacketFromIntegerAndPackedByteParameters(Script::Parameter* param){if(!MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage[2])return 1;{unsigned char* object=MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage[0];unsigned id=*(unsigned*)(object+0x1c8);int count=*(int*)(object+0x1cc);Packet packet;packet.value=param->ToInt();int value=(param+1)->ToInt();packet.a=value&0xff;packet.b=(value>>8)&0xff;Script_SetWeightedGroupEntry(MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage[0],id,count,&packet);*(int*)(MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage[0]+0x1cc)=count+1;unsigned char* entry=Script_GetWeightedGroupByIndex(MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage[0],id);if(entry)entry[2]++;}return 1;}
