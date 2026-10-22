#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <World/Zone3D.h>
#include <World/Object3D.h>
#include <std_library_functions.h>
ARM

extern "C" {
void _ZN23ZoneContainerRenderPart5ResetEv(void*);
void InitializeFlag400ObjectAndEmbeddedFields(unsigned short* state);
void Memory_ClearThreeHalfwords(char* p);
void CombatScene_ClearFadingEnemyList(void* base);
void BattleScene_ResetPartyAnimationReloadQueue(unsigned char* state);
void Util_InitializeStateTwoAndFixedPointDefaults(char* self);
void BattleMenu_InitializeController(void*, void*);
extern unsigned BattleSceneUpdate_UnknownRoleZeroInitializedStorage[];
}

#define SCENE_STATE BattleSceneUpdate_UnknownRoleZeroInitializedStorage
#define WORD(offset) (*(int*)(scene + (offset)))
#define HALF(offset) (*(short*)(scene + (offset)))
#define BYTE(offset) (*(signed char*)(scene + (offset)))

struct SceneFlags5951 {
    unsigned char low : 3;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char high : 3;
};

// Original: arm9/ov000 @ 0x02160140; symbol: func_ov000_02160140; size: 0x3b0.
// Registers the scene as the active battle scene and resets its state: zone,
// camera defaults and menu controller, effect/cursor render parts, the five
// allocators and per-slot animation records, display models, fade lists and
// selection indices, leaving the shared update state cleared.
extern "C" void BattleScene_Initialize(unsigned char* scene)
{
    WORD(0x2a0) = 0;
    WORD(0x55f8) = 0;
    WORD(0x55fc) = 0;
    SCENE_STATE[1] = (unsigned)scene;
    WORD(0x55f4) = 0;
    BYTE(0x5710) = 0;
    BYTE(0x5711) = 0;
    WORD(0x5724) = 0;
    ((Zone3D*)(scene + 0xec8))->InitializeState();
    Util_InitializeStateTwoAndFixedPointDefaults((char*)(scene + 0xc18));
    BattleMenu_InitializeController(scene + 0x3760, 0);
    memset(scene + 0x54f4, 0, 0x10);
    memset(scene + 0x5728, 0, 0x30);
    for (int i = 0; i < 4; i++)
        ((int*)(scene + 0xeb8))[i] = 0;
    BattleScene_ResetPartyAnimationReloadQueue(scene);
    WORD(0xea8) = 0;
    WORD(0xeac) = 0;
    SCENE_STATE[0] = 1;

    WORD(0x5574) = 0;
    WORD(0x5578) = 0;
    WORD(0x557c) = 0;
    WORD(0x5580) = 0;
    WORD(0x5588) = 0;
    HALF(0x558c) = 0;
    WORD(0x5590) = 0;
    HALF(0x55b8) = 0;
    HALF(0x55ba) = 0;
    BYTE(0x55be) = 0;
    WORD(0x5594) = 0;
    WORD(0x55c4) = 0;
    WORD(0x55c8) = 0;
    WORD(0x55cc) = 0;
    WORD(0x55d0) = 0;
    BYTE(0x55d4) = 0;
    BYTE(0x55d5) = 0;
    WORD(0x58c0) = 0;
    WORD(0x58c4) = 0;
    BYTE(0x58c8) = 0;
    memset(scene + 0x58d0, 0, 0x30);
    BYTE(0x5900) = 0;
    BYTE(0x5901) = -1;
    memset(scene + 0x5758, 0, 0x10);

    BYTE(0x576c) = 0;
    BYTE(0x5950) = 1;
    BYTE(0x7728) = 0;
    HALF(0x772a) = -1;
    HALF(0x772c) = -1;
    BYTE(0x772e) = 0;
    BYTE(0x7712) = 0;
    BYTE(0x7711) = 0;
    BYTE(0x772f) = 0;
    ((Object3D*)(scene + 0x5954))->Initialize();
    ((Object3D*)(scene + 0x5a00))->Initialize();
    BYTE(0x5aac) = 0;
    BYTE(0x5aad) = 0;
    memset(scene + 0x5c3c, 0, 0x1c0);
    for (int i = 0; i < 2; i++)
        _ZN23ZoneContainerRenderPart5ResetEv(scene + 0x5600 + i * 0x88);
    WORD(0x5dfc) = 0;
    HALF(0x58ce) = 0;
    for (int i = 0; i < 5; i++)
        ((SafeAllocator*)(scene + 8 + i * 0x14))->ResetAllocatorPointer();
    for (int i = 0; i < 5; i++) {
        InitializeFlag400ObjectAndEmbeddedFields((unsigned short*)(scene + 0x5e24 + i * 0x190));
        memset(scene + 0x6aa4 + i * 0x70, 0, 0x70);
    }

    SCENE_STATE[0] = 0;
    WORD(0x6e24) = 0;
    HALF(0x6e28) = 0;
    BYTE(0x6e2a) = 1;
    BYTE(0x6e2b) = 0;
    HALF(0x6e2c) = 0;
    CombatScene_ClearFadingEnemyList(scene);
    WORD(0x6e38) = 0;
    WORD(0x6e3c) = 0;
    WORD(0x6e40) = 0;
    Memory_ClearThreeHalfwords((char*)scene);
    for (int i = 0; i < 5; i++)
        *(short*)(scene + i * 0x20 + 0x6e6a) = -1;
    WORD(0xea4) = 0;
    WORD(0x2a4) = 0;
    WORD(0) = 0;
    memset(scene + 0x76ec, 0, 0x1e);

    HALF(0x770a) = 0;
    WORD(0x770c) = 0;
    WORD(0x55d8) = 0;
    ((SceneFlags5951*)(scene + 0x5951))->bit3 = 0;
    ((SceneFlags5951*)(scene + 0x5951))->bit4 = 0;
    HALF(0x7730) = -1;
    BYTE(0x6e4d) = 0;
    BYTE(0x6e4b) = 0;
    *(unsigned char*)(scene + 0x7744) = 0xff;
    *(unsigned char*)(scene + 0x7745) = 0xff;
    *(unsigned char*)(scene + 0x7746) = 0xff;
    BYTE(0x5e00) = 0;
    BYTE(0x7747) = 0;
    BYTE(0x7710) = 0;
    BYTE(0x7748) = 0;
    BYTE(0x7749) = 0;
    BYTE(0xeb5) = 1;
    ((SafeAllocator*)(scene + 0x774c))->ResetAllocatorPointer();
    BYTE(0x77d0) = 0;
    BYTE(0x77d1) = 0;
    HALF(0x7714) = HALF(0x771e) = HALF(0x7720) = -1;
    BYTE(0x6ff9) = 0;
    BYTE(0x77d2) = 0;
}
