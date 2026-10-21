#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
ARM

struct LowTwelve {
    unsigned value : 12;
    unsigned rest : 20;
};

extern "C" {
char* BattleScene_ResolveCurrentActionRecord(char* p);
void* ActionData_GetGlobalTables();
void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
void CombatScript_CompileBufferToCommandGroups(unsigned int globalValue, const void* program, unsigned int length, unsigned int* result);
void* CombatScript_FindCommandGroupByActionKey(void* list, int value);
void InitializeOverlayAllocatorAndResourceState(char* p);
void Combat_BindBasePresentationAllocatorAndTextureState(void* arg0, int arg1, int arg2);
void Combat_BindActionSelectionContext(void* p, unsigned int v);
void Combat_InitializeActionPresentation(void* p, void* command);
void BattleScene_StartCommandMovementAndCamera(void* self);
extern int BattleSceneStartCurrentAction_UnknownRoleInitializedBytes;
extern char BattleScene_FinishLoadingActionScript_FormatSp03DBact[];
extern char BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov025 @ 0x021DC694; symbol: func_ov025_021dc694; size: 0x1ec.
// When a background action-script load finishes, looks up the action definition,
// compiles spNNN.bact from the narc, and starts presentation/camera motion.
extern "C" void BattleScene_FinishLoadingActionScript(char* self)
{
    char* record = BattleScene_ResolveCurrentActionRecord(self);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(BattleSceneStartCurrentAction_UnknownRoleInitializedBytes) == 0) {
        return;
    }
    void* file = 0;
    unsigned fileSize = 0;
    loader->GetLoadedFileByID(BattleSceneStartCurrentAction_UnknownRoleInitializedBytes, &file, &fileSize);
    void* definition = ActionData_FindDefinitionInPrimaryOrSecondaryTable((char*)ActionData_GetGlobalTables(), *(short*)record);
    if (file && fileSize && definition) {
        char name[80];
        sprintf(name, BattleScene_FinishLoadingActionScript_FormatSp03DBact, ((LowTwelve*)((char*)definition + 4))->value);
        const void* program = 0;
        unsigned length = 0;
        if (GetFileInNarc(file, name, &program, &length, 0)) {
            unsigned compiled = 0;
            CombatScript_CompileBufferToCommandGroups((unsigned)(self + 0x30), program, length, &compiled);
            if (compiled) {
                InitializeOverlayAllocatorAndResourceState(self + 0x2a8);
                Combat_BindBasePresentationAllocatorAndTextureState(self + 0x2a8, (int)(self + 0x30), (int)(self + 0x14c));
                Combat_BindActionSelectionContext(self + 0x2a8, *(unsigned*)(self + 0x29c));
                Combat_InitializeActionPresentation(self + 0x2a8, (void*)compiled);
                BattleScene_StartCommandMovementAndCamera(self);
            }
        }
    }
    unsigned mode = *(unsigned*)(self + 0xeac);
    if (mode != 3 && mode != 2 && mode != 6) {
        unsigned kind = (*(unsigned*)((char*)definition + 0x18) << 0x14) >> 0x19;
        int key = ((LowTwelve*)((char*)definition + 4))->value;
        if (kind == 0xc) {
            key = 0x158;
        }
        void* group = CombatScript_FindCommandGroupByActionKey(*(void**)(self + 0x5724), key);
        if (group) {
            InitializeOverlayAllocatorAndResourceState(self + 0x2a8);
            Combat_BindBasePresentationAllocatorAndTextureState(self + 0x2a8, (int)(self + 0x30), (int)(self + 0x14c));
            Combat_BindActionSelectionContext(self + 0x2a8, *(unsigned*)(self + 0x29c));
            Combat_InitializeActionPresentation(self + 0x2a8, group);
            BattleScene_StartCommandMovementAndCamera(self);
        } else {
            *(unsigned*)(self + 0xeac) = 5;
            *(unsigned*)(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage + 0x10) = 0;
            *(unsigned*)(BattleSceneStartCurrentAction_UnknownRoleZeroInitializedStorage + 8) = 0;
        }
    }
    loader->RemoveTask(BattleSceneStartCurrentAction_UnknownRoleInitializedBytes);
    BattleSceneStartCurrentAction_UnknownRoleInitializedBytes = -1;
}
