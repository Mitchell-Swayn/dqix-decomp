#include <globaldefs.h>
ARM
extern "C" void* GameState_GetSerializedProgressState();
extern "C" int GameState_ReadProtagonistStateAndStatusKindNine(void*,void*);
extern "C" void Script_DispatchResultCommandsToWorld(void*);
struct ItemScriptResult {char prefix[16];int item;char rest[32];};
// Original: arm9/ov002 @ 0x021575D4; symbol: func_ov002_021575d4; size: 0x60.
// Dispatches the selected item result script and chooses the follow-up message on success.
extern "C" int PartyMenu_DispatchSelectedItemScript(char* self) {
 int success=0;
 ItemScriptResult result;
 void* state=GameState_GetSerializedProgressState();
 result.item=*(short*)(self+0x1c22);
 if(GameState_ReadProtagonistStateAndStatusKindNine(state,&result)) {
   success=1;
   Script_DispatchResultCommandsToWorld(&result);
   *(short*)(self+0x1c28)=0x232a;
   *(short*)(self+0x1c2a)=-1;
 }
 return success;
}
