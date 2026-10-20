#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <World/Zone3DEmbeddedState.h>
ARM
struct IntegerParameterView;struct GameResources;
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" unsigned ScriptQueryContext_GetActiveInstance();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" unsigned FieldBattle_GetScene(void*);
extern "C" void* BattleScene_GetMenuController(unsigned char*);
extern "C" void World_ResetZoneStateAndClearThreeWords(unsigned char*);
extern "C" void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754*,int);
extern "C" int Inventory_AddSpecialItemQuantityAndCacheResult(char*,unsigned,unsigned,...);
struct TemporaryAllocator : SafeAllocator {TemporaryAllocator(){ResetAllocatorPointer();}};
struct TemporaryKeyState {TemporaryAllocator allocator;ZoneState2754 zone;void* loaded;unsigned words[2];};
// Original: arm9/main @ 0x0209D8A8; symbol: func_0209d8a8; size: 0xCC.
// Applies script key/value through a temporary zone view and remembers the original integer arguments.
extern "C" int Script_AddSpecialItemQuantityAndRememberArguments(char* parameters) {
 int key,value;
 GameState_GetIndexList(GameState::GetInstance());
 char* output=(char*)ScriptQueryContext_GetActiveInstance();
 if(!output)return 0;
 key=Script_ReadParameterAsInteger((IntegerParameterView*)parameters);
 value=Script_ReadParameterAsInteger((IntegerParameterView*)(parameters+8));
 char* resources=(char*)GameResources_GetInstance();
 unsigned address=FieldBattle_GetScene(*(void**)(resources+0x3718));
 if(!address)return 1;
 char* embedded=(char*)BattleScene_GetMenuController((unsigned char*)address);
 if(!embedded)return 1;
 ZoneState2754* zone=(ZoneState2754*)(embedded+0xd0);
 TemporaryKeyState temporary;
 World_ResetZoneStateAndClearThreeWords((unsigned char*)&temporary);
 if(ZoneState2754_FindPrimaryRecordByKey(zone,(short)key)) {
  temporary.loaded=zone;
  Inventory_AddSpecialItemQuantityAndCacheResult((char*)&temporary,(short)key,(signed char)value);
 }
 *(int*)(output+0x90)=key;
 *(int*)(output+0x94)=value;
 return 1;
}
