#include <globaldefs.h>
ARM
extern "C" {void* BattleScene_GetActiveInstance();void* BattleScene_ResolveCurrentActionRecord(void*);char* Combat_GetCommandActorSnapshot(void*,int);int Combat_AppendActionMessage(void*,unsigned short,short,int,void*,short,unsigned short);void Presentation_AppendWordAndTwoByteFields(void*,short,int,int);}
// Original: arm9/ov025 @ 0x021EAF48; symbol: AppendLinkedPresentationItemsForPrimaryRecord; size: 0xc4.
// Appends linked presentation items and customizes item172 using primary target selection.
extern "C" void Combat_QueuePrimaryActorLinkedMessages(char* self,int index,int mode,char* record){char* primary=Combat_GetCommandActorSnapshot(BattleScene_ResolveCurrentActionRecord(BattleScene_GetActiveInstance()),index);if(!primary)return;unsigned key=*(unsigned short*)(primary+32);if(!record)return;short selected=key;if(mode==3)selected=*(short*)(primary+28);char* node=*(char**)(record+8);for(;node;node=*(char**)(node+4)){int value=Combat_AppendActionMessage(self+0x5e8,*(unsigned short*)node,selected,3,record,(short)key,0);if(*(unsigned short*)node==0x172)Presentation_AppendWordAndTwoByteFields(self+0x5e8,*(short*)(record+12),4,value);}}
