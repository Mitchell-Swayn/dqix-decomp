#include <globaldefs.h>
ARM
struct TransitionDisplay { typedef void(TransitionDisplay::*Handler)(); };
struct HandlerTable { TransitionDisplay::Handler entries[5]; };
extern "C" {
void PopulateDisplayFromProtagonistAndStoredId(unsigned char*);
void GameState_AdvancePartyTransitionDisplayRequest(unsigned char*);
void GameState_ResetPartyTransitionDialogue(unsigned char*);
int Field_IsHostDisconnectPending();
extern HandlerTable GameStateUpdatePartyTransitionDialogue_UnknownRoleProcedureReferenceRecords;
extern TransitionDisplay::Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
}
// Original: arm9/main @ 0x02092BCC; symbol: GameState_UpdatePartyTransitionDialogue; size: 0x104.
extern "C" int GameState_UpdatePartyTransitionDialogue(void* context,int elapsed){
unsigned char* self=(unsigned char*)context;
if(!self[0x3a]&&Field_IsHostDisconnectPending()){self[0x3a]=1;GameState_ResetPartyTransitionDialogue(self);}
if(*(short*)(self+0x32)>0){*(short*)(self+0x32)-=elapsed;if(*(short*)(self+0x32)<0)*(short*)(self+0x32)=0;}
PopulateDisplayFromProtagonistAndStoredId(self);GameState_AdvancePartyTransitionDisplayRequest(self);
if(self[0x37]&4)return 0;
HandlerTable handlers=GameStateUpdatePartyTransitionDialogue_UnknownRoleProcedureReferenceRecords;
handlers.entries[4]=ShopUpdateInterface_UnknownRoleInitializedBytes;
unsigned index=self[0x34];if(!handlers.entries[index])return 1;
(((TransitionDisplay*)self)->*handlers.entries[index])();return 0;
}
