#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma force_active on
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void Graphics_SetTextBackgroundScreenSize(int,unsigned);
extern "C" void Graphics_SetBackgroundColorMode(void*,unsigned);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(void*,void*,void*);
struct TransferState {char prefix[28];unsigned char engine:4,layer:4;char tail[3];};
// Original data: arm9/main @ 0x0211E33C; symbol: data_0211e33c.
// Mutable zero-initialized storage; observed offsets belong to this consumer, not a proven object extent.
// Initial value: zero-filled. Full initialized state and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_ReadPResources(void*);
extern "C" void Graphics_SetSubBg0Control(unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void Graphics_SetSubBG1Control(unsigned,unsigned,unsigned,unsigned,unsigned);
// The original script caller supplies a fourth zero argument; the resource loader does not consume it.
extern "C" int Graphics_LoadTaggedLayerResource(void*,const void*,unsigned,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToSubBG0CharacterData(const void*,unsigned,unsigned);
extern "C" unsigned short* GetSubBG0ScreenBase();
extern "C" unsigned short* GetSubBG1ScreenBase();
// Original: arm9/ov001 @ 0x0215E5B0; symbol: func_ov001_0215e5b0; size: 0x1A8.
// Initializes sub-screen text backgrounds, clears their character storage, and fills their screen maps.
extern "C" int Script_InitializeSubScreenTextBackgrounds()
{
    _ZN16BackgroundLoader13AddLockGlobalEv();
    _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
    char* resources = GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
    char* characters = Main_UnknownRoleZeroInitializedStorage_Variant6;
    *(volatile unsigned*)0x04001000 = (*(volatile unsigned*)0x04001000 & ~0x1f00) | 0x300;
    Graphics_SetSubBg0Control(0, 0, 14, 0, 0);
    Graphics_SetSubBG1Control(0, 0, 15, 0, 0);
    volatile unsigned short* control = (volatile unsigned short*)0x04001008;
    control[0] = control[0] & ~3;
    control[1] = (control[1] & ~3) | 1;
    control[2] = (control[2] & ~3) | 2;
    control[3] = (control[3] & ~3) | 3;
    *(volatile unsigned*)0x04000010 = 0;
    *(volatile unsigned*)0x04000014 = 0;
    *(volatile unsigned short*)0x04001050 = 0;
    TransferState transfer;
    Graphics_InitializeCanvasTransferState((char*)&transfer);
    transfer.engine = 1;
    Graphics_LoadTaggedLayerResource(&transfer, *(void**)(resources + 0x2c), 0, 0);
    unsigned length = 0x6400;
    memset(characters, 0, length);
    memset(characters + 0x20, 0x11111111, 0x20);
    _Z25CleanInvalidateCacheRangePKvj(characters, length);
    LoadToSubBG0CharacterData(characters, 0, length);
    unsigned short* screen = GetSubBG0ScreenBase();
    unsigned short tile = 3;
    for (unsigned short i = 0; i < 0x300; ++i) { *screen++ = tile; ++tile; }
    screen = GetSubBG1ScreenBase();
    for (unsigned short i = 0; i < 0x300; ++i) *screen++ = 1;
    _ZN16BackgroundLoader16RemoveLockGlobalEv();
    return 1;
}
