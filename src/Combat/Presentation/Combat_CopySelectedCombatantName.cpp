#include <globaldefs.h>
ARM
struct GameState;struct Buffer;
extern "C" int Combat_DispatchSelectionProcedure(void*,void*,unsigned,void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void BattleScene_GetActiveInstance();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned char* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);
extern "C" void TextContext_SetStringArgument(Buffer*,int,const char*);
// Original: arm9/ov025 @ 0x021E5E84; symbol: func_ov025_021e5e84; size: 0xBC.
extern "C" int Combat_CopySelectedCombatantName(const unsigned char* self,void* argument,void* unused,void* procedure) {
int selection[8];
if(Combat_DispatchSelectionProcedure(procedure,argument,self[9],selection)!=1) return 1;
GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
Buffer* buffer=(Buffer*)TextContext_GetSharedInstance();
int index=selection[0];
BattleScene_GetActiveInstance();
_ZN9GameState19GetCombatantByIndexEi(state,index);
bool member;
if(index>=0 && index<=3) member=true;else member=false;
if(member) {
char* object=(char*)GameState_GetObjectWithFlag100(state,index);
if(object) TextContext_SetStringArgument(buffer,self[8],*(const char**)(object+0x134));
} else {
unsigned char* object=GameState_FindIndexedObjectWithFlag400(state,index);
if(object) TextContext_SetStringArgument(buffer,self[8],(const char*)object+0x14c);
}
return 1;
}
