#include <globaldefs.h>
#include <Resource/Script.h>
ARM
struct E;
extern "C" E* LinkedList_FindNodeByUnsignedKey(E**,unsigned);
extern "C" unsigned char ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage[];
struct MatchingNode { unsigned char prefix[11]; unsigned char option; unsigned char unknown[0x44-12]; unsigned short serial; unsigned char pad[0x2a]; MatchingNode* next; };
// Original: arm9/main @ 0x0206CAD8; symbol: func_0206cad8; size: 0x70.
// Updates the option byte on the keyed node with the currently selected serial.
extern "C" int Script_SetMatchingNodeOptionByte(Script::Parameter* params,int) {
 unsigned key=params[0].ToInt();
 MatchingNode* node=(MatchingNode*)LinkedList_FindNodeByUnsignedKey(*(E***)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+16),key);
 if(!node)return 0;
 while(node){if(node->serial==*(unsigned short*)(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage+10))break;node=node->next;}
 if(!node)return 0;
 node->option=params[1].ToInt();return 1;
}
