#include <globaldefs.h>
ARM
struct GameState;struct GameResources;struct Object3D;
struct Payload {char pad[4];unsigned char index;unsigned char enabled:1;unsigned char overlay:1;unsigned char spare:6;};
extern "C" {Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);unsigned char* GameObject_GetLinkedIndexedState(void*);GameResources* GameResources_GetInstance();void Field_SetPartyMemberMessageFlag(void*,unsigned);void Field_ClearPartyMemberMessageFlag(void*,unsigned);void Field_UpdateCombatantAppearanceFlags(void*,int,int,unsigned);}
// Original: arm9/ov017 @ 0x021D26A4; symbol: func_ov017_021d26a4; size: 0x94.
extern "C" void ApplyPartyMemberMessageFlags(void* unused,Payload* payload,GameState* game,void* owner){
GameResources* resources=GameResources_GetInstance();
Object3D* object=_ZN9GameState21GetPartyMemberByIndexEi(game,payload->index);if(!object)return;
unsigned char* state=GameObject_GetLinkedIndexedState(object);if(!state)return;
state[0x56c]=payload->enabled?1:0;
if(state[0x56c])Field_UpdateCombatantAppearanceFlags(owner,1,payload->index,2);
if(payload->overlay)Field_SetPartyMemberMessageFlag(resources,payload->index);else Field_ClearPartyMemberMessageFlag(resources,payload->index);
}
