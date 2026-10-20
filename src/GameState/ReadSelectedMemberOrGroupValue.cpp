#include <globaldefs.h>
ARM
#pragma opt_propagation off
#include <GameState/GameState.h>
extern "C" void* GameState_GetObjectWithFlag100(GameState*,int);extern "C" void* GameObject_GetLinkedIndexedState(void*);extern "C" int CharacterState_CountCarriedItemCopies(void*,unsigned);extern "C" int Inventory_GetItemCount(void*,unsigned);extern "C" int Inventory_GetItemQuantityAcrossTypeGroups(void*,unsigned,int);
// Original: arm9/main @ 0x02086C4C; symbol: func_02086c4c; size: 0xD4.
extern "C" int ReadSelectedMemberOrGroupValue(unsigned char* object,int selector,unsigned arg){GameState* state=GameState::GetInstance();int result=0;bool valid;if(selector>=0&&selector<=3)valid=true;else valid=false;if(valid){void* member=GameState_GetObjectWithFlag100(state,selector);if(!member)return 0;member=GameObject_GetLinkedIndexedState(member);if(!member)return 0;result=(short)(result+CharacterState_CountCarriedItemCopies(member,arg));}else if(selector==4)result=Inventory_GetItemCount(object,arg);else if(selector==5)result=Inventory_GetItemQuantityAcrossTypeGroups(object+0x1d4,arg,9);else if(selector==6)result=Inventory_GetItemCount(object+0xe04,arg);return result;}
