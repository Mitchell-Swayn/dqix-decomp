#include <globaldefs.h>
extern "C" unsigned BattleScene_GetActiveInstance();
extern "C" char* BattleScene_ResolveCurrentActionRecord(char*);
extern "C" void* ActionData_GetGlobalTables();
extern "C" void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*, void*);
// Original: arm9/ov025 @ 0x021EBA60; symbol: func_ov025_021eba60; size: 0x54.
extern "C" void Combat_EnablePrimaryActorFacingForActionType(unsigned char* self) {
    char* record = BattleScene_ResolveCurrentActionRecord((char*)BattleScene_GetActiveInstance());
    void* result = ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(), (void*)(int)*(short*)record);
    if (result != 0 && (*(unsigned*)((char*)result + 0x14) >> 28) == 2 && ((*(unsigned*)((char*)result + 8) << 22) >> 30) == 1) {
        *(unsigned*)((char*)self + 0x1c4) |= 0x80;
    }
}
