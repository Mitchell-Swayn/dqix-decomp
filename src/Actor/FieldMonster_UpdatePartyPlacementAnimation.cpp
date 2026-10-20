#include <globaldefs.h>
struct State {char pad[0xbe];unsigned char mode;};extern "C" void GameObject_ChangeMotionStateAndRefreshAnimation(State*,int);extern "C" void GameObject_MoveInFrontOfSelectedPartyMember(State*);
// Original: arm9/main @ 0x0207872C; symbol: func_0207872c; size: 0x28.
extern "C" void FieldMonster_UpdatePartyPlacementAnimation(State* self) {if(self->mode!=2)GameObject_ChangeMotionStateAndRefreshAnimation(self,2);GameObject_MoveInFrontOfSelectedPartyMember(self);}
