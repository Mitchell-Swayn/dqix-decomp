#include <globaldefs.h>
ARM
#include <Resource/Script.h>
#include <World/Zone3DEmbeddedState.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
extern unsigned data_02108ce0[];extern "C" unsigned char* ReadGlobalValueAt020FB3F0();extern "C" int func_020981e4(void*,unsigned),func_02098268(void*,int),LinkedList_FindNodeByUnsignedKey(unsigned,int);
// Original: arm9/main @ 0x02064D48; symbol: func_02064d48; size: 0xD8.
extern "C" int Script_PrependLabelNodeForValidEntry(Script::Parameter* params){int id=params->ToInt();unsigned char* zone=ReadGlobalValueAt020FB3F0();if(((ZoneState0840*)(zone+0x840))->IsValueInRangeC3b5(*(unsigned short*)zone)&&((ZoneState0840*)(zone+0x840))->IsEntryStateValid(id))return 1;if(!LinkedList_FindNodeByUnsignedKey(data_02108ce0[1],id))return 1;unsigned char* node=(unsigned char*)((SafeAllocator*)data_02108ce0[0])->Allocate(20);if(!node)return 0;*(short*)node=id;node[2]=params[1].ToInt();params[2].ToString();const char* text=params[3].ToString();if(text)strcpy((char*)node+4,text);node[3]=params[4].ToInt();unsigned* head=(unsigned*)data_02108ce0[2];*(unsigned*)(node+16)=*head;*head=(unsigned)node;return 1;}
