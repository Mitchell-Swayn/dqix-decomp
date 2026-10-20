#include "System/VRAM.h"
#include "System/Graphics.h"

#pragma optimize_for_size off

#if defined(jpn)
#define DisableAssignedVRAMBanksByUsage_UnknownRoleZeroInitializedStorage data_02110ec2

#define System_ReleaseOwnedInterruptSlots func_020cb554
#endif

// Original data: arm9/main @ 0x2111222; symbol: data_02111222.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short DisableAssignedVRAMBanksByUsage_UnknownRoleZeroInitializedStorage;

extern "C"
{
    void System_ReleaseOwnedInterruptSlots(unsigned short banks, unsigned short owner);
}

// Original: arm9/main @ 0x020C3A4C; symbol: InitializeVRAM; size: 0x60.
void InitializeVRAM()
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.mainOBJBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.arm7WorkRAMBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.textureImageBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.texturePaletteBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.clearTextureBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.subOBJBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGExtPaletteBanks_ = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.subObjExtPaletteBanks_ = 0;

    intptr_t vramAddr = 0x04000240;
    *(int*)vramAddr = 0; // banks A, B, C, D
    *(char*)(vramAddr + 4) = 0; // bank E
    *(char*)(vramAddr + 5) = 0; // bank F
    *(char*)(vramAddr + 6) = 0; // bank G
    *(short*)(vramAddr + 8) = 0; // banks H, I
}

// Original: arm9/main @ 0x020C3AAC; symbol: InternalMapVRAMBanksToLCDC; size: 0xB8.
void InternalMapVRAMBanksToLCDC(int banks)
{
    // 0x80 = enabled, MST = 0 (LCDC), offset = 0 (not relevant)
    if (banks & VRAM_BANK_A)
        VRAMCNT_A = 0x80;
    if (banks & VRAM_BANK_B)
        VRAMCNT_B = 0x80;
    if (banks & VRAM_BANK_C)
        VRAMCNT_C = 0x80;
    if (banks & VRAM_BANK_D)
        VRAMCNT_D = 0x80;
    if (banks & VRAM_BANK_E)
        VRAMCNT_E = 0x80;
    if (banks & VRAM_BANK_F)
        VRAMCNT_F = 0x80;
    if (banks & VRAM_BANK_G)
        VRAMCNT_G = 0x80;
    if (banks & VRAM_BANK_H)
        VRAMCNT_H = 0x80;
    if (banks & VRAM_BANK_I)
        VRAMCNT_I = 0x80;
}

// Original: arm9/main @ 0x020C3B64; symbol: MapVRAMBanksToMainBG; size: 0x290.
extern "C" void MapVRAMBanksToMainBG(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGBanks_ = banks;
    // You can either use any of banks A,B,C,D, or you can use any of E,F,G
    // but you can't mix the two sets.
    // A,B,C,D are all 128k and are mapped consecutively to 06000000, 06020000, ...
    // E is 64k and will be mapped to 06000000 (offset 0)
    // F, G are 16k and are mapped to 06000000 & 06004000 (offsets 0 and 1) if used without E
    // or 06010000 and 06014000 (offsets 2 and 3) if used with E.
    // All of these use MST = 1 (means main BG for banks A-G), for which
    // offsets 0, 1, 2, 3 give flags 0x81, 0x89, 0x91, 0x99 respectively.
    switch (banks)
    {
    case VRAM_BANK_D:
        VRAMCNT_D = 0x81;
        break;
    case VRAM_BANK_C | VRAM_BANK_D:
        VRAMCNT_D = 0x89;
    case VRAM_BANK_C:
        VRAMCNT_C = 0x81;
        break;
    case VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
        VRAMCNT_D = 0x91;
    case VRAM_BANK_B | VRAM_BANK_C:
        VRAMCNT_C = 0x89;
    case VRAM_BANK_B:
        VRAMCNT_B = 0x81;
        break;
    case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
        VRAMCNT_D = 0x99;
    case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C:
        VRAMCNT_C = 0x91;
    case VRAM_BANK_A | VRAM_BANK_B:
        VRAMCNT_B = 0x89;
    case VRAM_BANK_A:
        VRAMCNT_A = 0x81;
        break;
    case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_D:
        VRAMCNT_A = 0x81;
        VRAMCNT_B = 0x89;
        VRAMCNT_D = 0x91;
        break;
    case VRAM_BANK_A | VRAM_BANK_C | VRAM_BANK_D:
        VRAMCNT_D = 0x91;
    case VRAM_BANK_A | VRAM_BANK_C:
        VRAMCNT_A = 0x81;
        VRAMCNT_C = 0x89;
        break;
    case VRAM_BANK_A | VRAM_BANK_D:
        VRAMCNT_A = 0x81;
        VRAMCNT_D = 0x89;
        break;
    case VRAM_BANK_B | VRAM_BANK_D:
        VRAMCNT_B = 0x81;
        VRAMCNT_D = 0x89;
        break;
    
    
    case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G:
        VRAMCNT_G = 0x99;
    case VRAM_BANK_E | VRAM_BANK_F:
        VRAMCNT_F = 0x91;
    case VRAM_BANK_E:
        VRAMCNT_E = 0x81;
        break;
    case VRAM_BANK_E | VRAM_BANK_G:
        VRAMCNT_G = 0x91;
        VRAMCNT_E = 0x81;
        break;
    
    case VRAM_BANK_F | VRAM_BANK_G:
        VRAMCNT_G = 0x89;
    case VRAM_BANK_F:
        VRAMCNT_F = 0x81;
        break;
    case VRAM_BANK_G:
        VRAMCNT_G = 0x81;
        break;
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C3DF4; symbol: MapVRAMBanksToMainObj; size: 0x150.
extern "C" void MapVRAMBanksToMainObj(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.mainOBJBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.mainOBJBanks_ = banks;
    // You can either use A and/or B, or you can use any of E,F,G.
    // Offset assignments are like with main BG (see previous function).
    // Here MST = 2 in all cases, so offsets 0,1,2,3 correspond to
    // 0x82, 0x8a, 0x92, 0x9a respectively.
    switch (banks)
    {
    case 0:
        break;
    case VRAM_BANK_A | VRAM_BANK_B:
        VRAMCNT_B = 0x8a;
    case VRAM_BANK_A:
        VRAMCNT_A = 0x82;
        break;
    case VRAM_BANK_B:
        VRAMCNT_B = 0x82;
        break;

    case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G:
        VRAMCNT_G = 0x9a;
    case VRAM_BANK_E | VRAM_BANK_F:
        VRAMCNT_F = 0x92;
    case VRAM_BANK_E:
        VRAMCNT_E = 0x82;
        break;
    case VRAM_BANK_E | VRAM_BANK_G:
        VRAMCNT_G = 0x92;
        VRAMCNT_E = 0x82;
        break;
    case VRAM_BANK_F | VRAM_BANK_G:
        VRAMCNT_G = 0x8a;
    case VRAM_BANK_F:
        VRAMCNT_F = 0x82;
        break;
    case VRAM_BANK_G:
        VRAMCNT_G = 0x82;
        break;
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C3F44; symbol: MapVRAMBanksToMainBGExtendedPalette; size: 0x100.
void MapVRAMBanksToMainBGExtendedPalette(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_ = banks;
    // MST = 4 and offset 0 or 1: 0x84 or 0x8c
    switch (banks)
    {
    case VRAM_BANK_E:
        DISPCNT |= DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
        VRAMCNT_E = 0x84;
        break;
    case VRAM_BANK_G:
        DISPCNT |= DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
        VRAMCNT_G = 0x8c;
        break;
    case VRAM_BANK_F | VRAM_BANK_G:
        VRAMCNT_G = 0x8c;
    case VRAM_BANK_F:
        VRAMCNT_F = 0x84;
        DISPCNT |= DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
        break;
    
    case 0:
        DISPCNT &= ~DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
        break;
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C4044; symbol: MapVRAMBanksToMainObjExtendedPalette; size: 0xAC.
void MapVRAMBanksToMainObjExtendedPalette(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_ = banks;
    // MST = 5, only offset 0 can work
    switch (banks)
    {
    case VRAM_BANK_F:
        DISPCNT |= DISPCNT_ENABLE_OBJ_EXTENDED_PALETTE;
        VRAMCNT_F = 0x85;
        break;
    case VRAM_BANK_G:
        DISPCNT |= DISPCNT_ENABLE_OBJ_EXTENDED_PALETTE;
        VRAMCNT_G = 0x85;
        break;
    case 0:
        DISPCNT &= ~DISPCNT_ENABLE_OBJ_EXTENDED_PALETTE;
        break;
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C40F0; symbol: MapVRAMBanksToTextureImage; size: 0x1D8.
void MapVRAMBanksToTextureImage(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.textureImageBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.textureImageBanks_ = banks;
    // MST = 3 for A-D means texture image.
    // Offsets 0, 1, 2, 3 are 0x83, 0x8b, 0x93, 0x9b respectively.
    if (banks == 0)
        DISP3DCNT &= 0xffff & ~((1 << 0) | (1 << 12) | (1 << 13));
    else
    {
        DISP3DCNT = (DISP3DCNT & ~((1 << 12) | (1 << 13))) | (1 << 0);
        switch (banks)
        {
        case VRAM_BANK_A | VRAM_BANK_C:
            VRAMCNT_A = 0x83;
            VRAMCNT_C = 0x8b;
            break;
        case VRAM_BANK_A | VRAM_BANK_D:
            VRAMCNT_A = 0x83;
            VRAMCNT_D = 0x8b;
            break;
        case VRAM_BANK_B | VRAM_BANK_D:
            VRAMCNT_B = 0x83;
            VRAMCNT_D = 0x8b;
            break;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_D:
            VRAMCNT_A = 0x83;
            VRAMCNT_B = 0x8b;
            VRAMCNT_D = 0x93;
            break;
        case VRAM_BANK_A | VRAM_BANK_C | VRAM_BANK_D:
            VRAMCNT_A = 0x83;
            VRAMCNT_C = 0x8b;
            VRAMCNT_D = 0x93;
            break;
        case VRAM_BANK_D:
            VRAMCNT_D = 0x83;
            break;
        case VRAM_BANK_C | VRAM_BANK_D:
            VRAMCNT_D = 0x8b;
        case VRAM_BANK_C:
            VRAMCNT_C = 0x83;
            break;
        case VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
            VRAMCNT_D = 0x93;
        case VRAM_BANK_B | VRAM_BANK_C:
            VRAMCNT_C = 0x8b;
        case VRAM_BANK_B:
            VRAMCNT_B = 0x83;
            break;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C | VRAM_BANK_D:
            VRAMCNT_D = 0x9b;
        case VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_C:
            VRAMCNT_C = 0x93;
        case VRAM_BANK_A | VRAM_BANK_B:
            VRAMCNT_B = 0x8b;
        case VRAM_BANK_A:
            VRAMCNT_A = 0x83;
        }
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C42C8; symbol: MapVRAMBanksToTexturePalette; size: 0xE8.
void MapVRAMBanksToTexturePalette(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.texturePaletteBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.texturePaletteBanks_ = banks;
    // MST = 3 for E,F,G means texture palette.
    // Offset 2 for F or G puts it right after E ends
    switch (banks)
    {
    case 0:
        break;
    case VRAM_BANK_F | VRAM_BANK_G:
        VRAMCNT_G = 0x8b;
    case VRAM_BANK_F:
        VRAMCNT_F = 0x83;
        break;
    case VRAM_BANK_G:
        VRAMCNT_G = 0x83;
        break;
    case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G:
        VRAMCNT_G = 0x9b;
    case VRAM_BANK_E | VRAM_BANK_F:
        VRAMCNT_F = 0x93;
    case VRAM_BANK_E:
        VRAMCNT_E = 0x83;
        break;
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C43B0; symbol: MapVRAMBanksToClearTextures; size: 0x134.
void MapVRAMBanksToClearTextures(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.clearTextureBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.clearTextureBanks_ = banks;
    switch (banks)
    {
    case VRAM_BANK_A | VRAM_BANK_B:
        VRAMCNT_A = 0x93;
    case VRAM_BANK_B:
        VRAMCNT_B = 0x9b;
        DISP3DCNT |= DISP3DCNT_USE_CLEAR_TEXTURES;
        break;
    case VRAM_BANK_C | VRAM_BANK_D:
        VRAMCNT_C = 0x93;
    case VRAM_BANK_D:
        VRAMCNT_D = 0x9b;
        DISP3DCNT |= DISP3DCNT_USE_CLEAR_TEXTURES;
        break;
    case 0:
        DISP3DCNT &= ~DISP3DCNT_USE_CLEAR_TEXTURES;
        break;
    case VRAM_BANK_A:
        VRAMCNT_A = 0x9b;
        DISP3DCNT |= DISP3DCNT_USE_CLEAR_TEXTURES;
        break;
    case VRAM_BANK_C:
        VRAMCNT_C = 0x9b;
        DISP3DCNT |= DISP3DCNT_USE_CLEAR_TEXTURES;
        break;
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// This match is a war crime but switch(...) just wasn't cooperating here
// Original: arm9/main @ 0x020C44E4; symbol: MapVRAMBanksToArm7WorkRAM; size: 0xAC.
void MapVRAMBanksToArm7WorkRAM(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.arm7WorkRAMBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.arm7WorkRAMBanks_ = banks;
    if (banks <= 8)
    {
        if (banks >= 8)
            goto workram_case_D;
        // I do love that this is entirely equivalent to banks != 4
        if (banks > 4 || banks < 0 || banks == 0 || banks != 4)
            goto workram_switch_end;
        goto workram_case_C;
    }
    else
    {
        if (banks != 12)
            goto workram_switch_end;
        // falls through to case C+D
    }

workram_case_C_D:
    VRAMCNT_D = 0x8a;
    VRAMCNT_C = 0x82;
    goto workram_switch_end;
workram_case_C:
    VRAMCNT_C = 0x82;
    goto workram_switch_end;
workram_case_D:
    VRAMCNT_D = 0x82;
    goto workram_switch_end;
workram_switch_end:
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C4590; symbol: MapVRAMBanksToLCDC; size: 0x20.
void MapVRAMBanksToLCDC(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ |= banks;
    InternalMapVRAMBanksToLCDC(banks);
}

// more war crimes here
// Original: arm9/main @ 0x020C45B0; symbol: MapVRAMBanksToSubBG; size: 0xA8.
void MapVRAMBanksToSubBG(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGBanks_ = banks;
    // this one uses MST 4 for bank C, but MST 1 for H and I (no offsets)
    if (banks <= 0x80)
    {
        if (banks >= 0x80)
            goto subBG_case_H;

        if (banks > 4 || banks < 0 || banks == 0 || banks != 4)
            goto subBG_switch_end;
        // goes to case C
    }
    else
    {
        if (banks != 0x180)
            goto subBG_switch_end;
        goto subBG_case_H_I;
    }
subBG_case_C:
    VRAMCNT_C = 0x84;
    goto subBG_switch_end;
subBG_case_H_I:
    VRAMCNT_I = 0x81;
subBG_case_H:
    VRAMCNT_H = 0x81;
    goto subBG_switch_end;
subBG_switch_end:
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C4658; symbol: MapVRAMBanksToSubObj; size: 0x70.
void MapVRAMBanksToSubObj(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.subOBJBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.subOBJBanks_ = banks;
    // this mode uses MST = 4 for D and MST = 2 for I
    switch (banks)
    {
    case 0:
        break;
    case VRAM_BANK_D:
        VRAMCNT_D = 0x84;
        break;
    case VRAM_BANK_I:
        VRAMCNT_I = 0x82;
        break;
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C46C8; symbol: MapVRAMBanksToSubBGExtendedPalette; size: 0x80.
void MapVRAMBanksToSubBGExtendedPalette(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGExtPaletteBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGExtPaletteBanks_ = banks;
    switch (banks)
    {
    case VRAM_BANK_H:
        DISPCNTSUB |= DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
        VRAMCNT_H = 0x82;
        break;
    case 0:
        DISPCNTSUB &= ~DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
        break;
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C4748; symbol: MapVRAMBanksToSubObjExtendedPalette; size: 0x80.
void MapVRAMBanksToSubObjExtendedPalette(int banks)
{
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ = ~banks & (InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ | InitializeVRAM_UnknownRoleZeroInitializedStorage.subObjExtPaletteBanks_);
    InitializeVRAM_UnknownRoleZeroInitializedStorage.subObjExtPaletteBanks_ = banks;
    switch (banks)
    {
    case VRAM_BANK_I:
        DISPCNTSUB |= DISPCNT_ENABLE_OBJ_EXTENDED_PALETTE;
        VRAMCNT_I = 0x83;
        break;
    case 0:
        DISPCNTSUB &= ~DISPCNT_ENABLE_OBJ_EXTENDED_PALETTE;
        break;
    }
    InternalMapVRAMBanksToLCDC(InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C47C8; symbol: ResetAssignedVRAMBanksByUsage; size: 0x34.
unsigned short ResetAssignedVRAMBanksByUsage(unsigned short* usage)
{
    int banks = *usage;
    *usage = 0;
    InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_ |= banks;
    InternalMapVRAMBanksToLCDC(banks);
    return banks;
}

// Original: arm9/main @ 0x020C47FC; symbol: ReleaseMainBGVRAMBanks; size: 0x14.
unsigned short ReleaseMainBGVRAMBanks()
{
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGBanks_);
}

// Original: arm9/main @ 0x020C4810; symbol: ReleaseMainBGExtendedPaletteVRAMBanks; size: 0x24.
unsigned short ReleaseMainBGExtendedPaletteVRAMBanks()
{
    DISPCNT &= ~DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_);
}

// Original: arm9/main @ 0x020C4834; symbol: ReleaseMainObjExtendedPaletteVRAMBanks; size: 0x24.
unsigned short ReleaseMainObjExtendedPaletteVRAMBanks()
{
    DISPCNT &= ~DISPCNT_ENABLE_OBJ_EXTENDED_PALETTE;
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_);
}

// Original: arm9/main @ 0x020C4858; symbol: ReleaseTextureImageVRAMBanks; size: 0x14.
unsigned short ReleaseTextureImageVRAMBanks()
{
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.textureImageBanks_);
}

// Original: arm9/main @ 0x020C486C; symbol: ReleaseTexturePaletteVRAMBanks; size: 0x14.
unsigned short ReleaseTexturePaletteVRAMBanks()
{
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.texturePaletteBanks_);
}

// Original: arm9/main @ 0x020C4880; symbol: ReleaseClearTextureVRAMBanks; size: 0x14.
unsigned short ReleaseClearTextureVRAMBanks()
{
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.clearTextureBanks_);
}

// Original: arm9/main @ 0x020C4894; symbol: ReleaseSubBGVRAMBanks; size: 0x14.
unsigned short ReleaseSubBGVRAMBanks()
{
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGBanks_);
}

// Original: arm9/main @ 0x020C48A8; symbol: ReleaseSubObjVRAMBanks; size: 0x14.
unsigned short ReleaseSubObjVRAMBanks()
{
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.subOBJBanks_);
}

// Original: arm9/main @ 0x020C48BC; symbol: ReleaseSubBGExtendedPaletteVRAMBanks; size: 0x28.
unsigned short ReleaseSubBGExtendedPaletteVRAMBanks()
{
    DISPCNTSUB &= ~DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGExtPaletteBanks_);
}

// Original: arm9/main @ 0x020C48E4; symbol: ReleaseSubObjExtendedPaletteVRAMBanks; size: 0x28.
unsigned short ReleaseSubObjExtendedPaletteVRAMBanks()
{
    DISPCNTSUB &= ~DISPCNT_ENABLE_OBJ_EXTENDED_PALETTE;
    return ResetAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.subObjExtPaletteBanks_);
}

// Original: arm9/main @ 0x020C490C; symbol: DisableAssignedVRAMBanksByUsage; size: 0xE0.
unsigned int DisableAssignedVRAMBanksByUsage(unsigned short* usage)
{
    unsigned int banks = *usage;
    *usage = 0;
    if (banks & VRAM_BANK_A)
        VRAMCNT_A = 0;
    if (banks & VRAM_BANK_B)
        VRAMCNT_B = 0;
    if (banks & VRAM_BANK_C)
        VRAMCNT_C = 0;
    if (banks & VRAM_BANK_D)
        VRAMCNT_D = 0;
    if (banks & VRAM_BANK_E)
        VRAMCNT_E = 0;
    if (banks & VRAM_BANK_F)
        VRAMCNT_F = 0;
    if (banks & VRAM_BANK_G)
        VRAMCNT_G = 0;
    if (banks & VRAM_BANK_H)
        VRAMCNT_H = 0;
    if (banks & VRAM_BANK_I)
        VRAMCNT_I = 0;
    System_ReleaseOwnedInterruptSlots(banks, DisableAssignedVRAMBanksByUsage_UnknownRoleZeroInitializedStorage);
    return banks;
}

// Original: arm9/main @ 0x020C49EC; symbol: DisableMainBGVRAMBanks; size: 0x14.
unsigned int DisableMainBGVRAMBanks()
{
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGBanks_);
}

// Original: arm9/main @ 0x020C4A00; symbol: DisableMainObjVRAMBanks; size: 0x14.
unsigned int DisableMainObjVRAMBanks()
{
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.mainOBJBanks_);
}

// Original: arm9/main @ 0x020C4A14; symbol: DisableMainBGExtendedPaletteVRAMBanks; size: 0x24.
unsigned int DisableMainBGExtendedPaletteVRAMBanks()
{
    DISPCNT &= ~DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_);
}

// Original: arm9/main @ 0x020C4A38; symbol: DisableMainObjExtendedPaletteVRAMBanks; size: 0x24.
unsigned int DisableMainObjExtendedPaletteVRAMBanks()
{
    DISPCNT &= ~DISPCNT_ENABLE_OBJ_EXTENDED_PALETTE;
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_);
}

// Original: arm9/main @ 0x020C4A5C; symbol: DisableTextureImageVRAMBanks; size: 0x14.
unsigned int DisableTextureImageVRAMBanks()
{
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.textureImageBanks_);
}

// Original: arm9/main @ 0x020C4A70; symbol: DisableTexturePaletteVRAMBanks; size: 0x14.
unsigned int DisableTexturePaletteVRAMBanks()
{
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.texturePaletteBanks_);
}

// Original: arm9/main @ 0x020C4A84; symbol: DisableClearTextureVRAMBanks; size: 0x14.
unsigned int DisableClearTextureVRAMBanks()
{
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.clearTextureBanks_);
}

// Original: arm9/main @ 0x020C4A98; symbol: DisableArm7WorkVRAMBanks; size: 0x14.
unsigned int DisableArm7WorkVRAMBanks()
{
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.arm7WorkRAMBanks_);
}

// Original: arm9/main @ 0x020C4AAC; symbol: DisableLCDCMappedVRAMBanks; size: 0x14.
unsigned int DisableLCDCMappedVRAMBanks()
{
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.lcdcMappedBanks_);
}

// Original: arm9/main @ 0x020C4AC0; symbol: DisableSubBGVRAMBanks; size: 0x14.
unsigned int DisableSubBGVRAMBanks()
{
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGBanks_);
}

// Original: arm9/main @ 0x020C4AD4; symbol: DisableSubObjVRAMBanks; size: 0x14.
unsigned int DisableSubObjVRAMBanks()
{
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.subOBJBanks_);
}

// Original: arm9/main @ 0x020C4AE8; symbol: DisableSubBGExtendedPaletteVRAMBanks; size: 0x28.
unsigned int DisableSubBGExtendedPaletteVRAMBanks()
{
    DISPCNTSUB &= ~DISPCNT_ENABLE_BG_EXTENDED_PALETTE;
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGExtPaletteBanks_);
}

// Original: arm9/main @ 0x020C4B10; symbol: DisableSubObjExtendedPaletteVRAMBanks; size: 0x28.
unsigned int DisableSubObjExtendedPaletteVRAMBanks()
{
    DISPCNTSUB &= ~DISPCNT_ENABLE_OBJ_EXTENDED_PALETTE;
    return DisableAssignedVRAMBanksByUsage(&InitializeVRAM_UnknownRoleZeroInitializedStorage.subObjExtPaletteBanks_);
}

// Original: arm9/main @ 0x020C4B38; symbol: GetMainBGVRAMBanks; size: 0x10.
unsigned short GetMainBGVRAMBanks() { return InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGBanks_; }
// Original: arm9/main @ 0x020C4B48; symbol: GetMainObjVRAMBanks; size: 0x10.
unsigned short GetMainObjVRAMBanks() { return InitializeVRAM_UnknownRoleZeroInitializedStorage.mainOBJBanks_; }
// Original: arm9/main @ 0x020C4B58; symbol: GetMainBGExtendedPaletteVRAMBanks; size: 0x10.
unsigned short GetMainBGExtendedPaletteVRAMBanks() { return InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGExtPaletteBanks_; }
// Original: arm9/main @ 0x020C4B68; symbol: GetMainObjExtendedPaletteVRAMBanks; size: 0x10.
unsigned short GetMainObjExtendedPaletteVRAMBanks() { return InitializeVRAM_UnknownRoleZeroInitializedStorage.mainObjExtPaletteBanks_; }
// Original: arm9/main @ 0x020C4B78; symbol: GetTextureImageVRAMBanks; size: 0x10.
unsigned short GetTextureImageVRAMBanks(){ return InitializeVRAM_UnknownRoleZeroInitializedStorage.textureImageBanks_; }
// Original: arm9/main @ 0x020C4B88; symbol: GetTexturePaletteVRAMBanks; size: 0x10.
unsigned short GetTexturePaletteVRAMBanks() { return InitializeVRAM_UnknownRoleZeroInitializedStorage.texturePaletteBanks_; }
// Original: arm9/main @ 0x020C4B98; symbol: GetSubBGVRAMBanks; size: 0x10.
unsigned short GetSubBGVRAMBanks() { return InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGBanks_; }
// Original: arm9/main @ 0x020C4BA8; symbol: GetSubObjVRAMBanks; size: 0x10.
unsigned short GetSubObjVRAMBanks() { return InitializeVRAM_UnknownRoleZeroInitializedStorage.subOBJBanks_; }
// Original: arm9/main @ 0x020C4BB8; symbol: GetSubBGExtendedPaletteVRAMBanks; size: 0x10.
unsigned short GetSubBGExtendedPaletteVRAMBanks() { return InitializeVRAM_UnknownRoleZeroInitializedStorage.subBGExtPaletteBanks_; }
// Original: arm9/main @ 0x020C4BC8; symbol: GetSubObjExtendedPaletteVRAMBanks; size: 0x10.
unsigned short GetSubObjExtendedPaletteVRAMBanks() { return InitializeVRAM_UnknownRoleZeroInitializedStorage.subObjExtPaletteBanks_; }

// Original: arm9/main @ 0x020C4BD8; symbol: GetTotalComponentVRAMSize; size: 0x54.
unsigned int GetTotalComponentVRAMSize(int banks)
{
    unsigned int total = 0;
    if (banks & VRAM_BANK_A)
        total += 128 * 1024;
    if (banks & VRAM_BANK_B)
        total += 128 * 1024;
    if (banks & VRAM_BANK_C)
        total += 128 * 1024;
    if (banks & VRAM_BANK_D)
        total += 128 * 1024;
    if (banks & VRAM_BANK_E)
        total += 64 * 1024;
    if (banks & VRAM_BANK_F)
        total += 16 * 1024;
    if (banks & VRAM_BANK_G)
        total += 16 * 1024;
    if (banks & VRAM_BANK_H)
        total += 32 * 1024;
    if (banks & VRAM_BANK_I)
        total += 16 * 1024;
    return total;
}

// Original: arm9/main @ 0x020C4C2C; symbol: GetMainBGAssignedVRAMSize; size: 0x18.
unsigned int GetMainBGAssignedVRAMSize() { return GetTotalComponentVRAMSize(InitializeVRAM_UnknownRoleZeroInitializedStorage.mainBGBanks_); }
// Original: arm9/main @ 0x020C4C44; symbol: GetTextureImageAssignedVRAMSize; size: 0x18.
unsigned int GetTextureImageAssignedVRAMSize() { return GetTotalComponentVRAMSize(InitializeVRAM_UnknownRoleZeroInitializedStorage.textureImageBanks_); }
// Original: arm9/main @ 0x020C4C5C; symbol: GetTexturePaletteAssignedVRAMSize; size: 0x18.
unsigned int GetTexturePaletteAssignedVRAMSize() { return GetTotalComponentVRAMSize(InitializeVRAM_UnknownRoleZeroInitializedStorage.texturePaletteBanks_); }