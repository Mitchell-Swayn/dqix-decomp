#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off

#include <System/Graphics.h>
void MapVRAMBanksToMainBG(int); void MapVRAMBanksToMainObj(int);
void MapVRAMBanksToSubBG(int); void MapVRAMBanksToSubObj(int);
void ColorEffect_ConfigureBrightnessAdjust(int,unsigned,int);
unsigned short Graphics_WriteVBlankInterruptEnableAndReturnOldBit(int); void Graphics_SetMainDisplayModeAndSelection(unsigned short,unsigned,int);
void Graphics_WriteSignedBrightnessMagnitudeAndMode(unsigned short*,int); void Graphics_WriteSubDisplayModeLowBits(unsigned);
void WfcUtility_InitializeTextCanvasServices(); void Resource_InitializeTwoBuffersAndCallbackTask(); void Resource_AllocateAndInitializeTwoStateBlocks(); void WfcUtility_InitializeSpriteGroupPools(); void GX_DispOn();
#define REG32(a) (*(volatile unsigned*)(a))
#define REG16(a) (*(volatile unsigned short*)(a))

static inline void SetDisplayLayers(volatile unsigned *display,unsigned layers) {*display=(*display&~0x1f00)|layers;}
static inline void SetDisplayWindows(volatile unsigned *display,unsigned windows) {*display=(*display&~0xe000)|windows;}
static inline void SetBackgroundControl(volatile unsigned short *control,unsigned value) {*control=(*control&0x43)|value;}
#pragma force_active on
// Original: arm9/ov031 @ 0x022271F0; symbol: func_ov031_022271f0; size: 0x278.
// Configures both displays and VRAM banks, resets background state and initializes text, OAM and sprite services.
void WfcUtility_InitializeDisplaysAndRenderServices()
{
    volatile unsigned short *mainBackground=(volatile unsigned short*)0x04000008;
    volatile unsigned short *subBackground=(volatile unsigned short*)0x04001008;
    volatile unsigned short *subRest=(volatile unsigned short*)0x0400100a;

    Graphics_WriteVBlankInterruptEnableAndReturnOldBit(0);
    MapVRAMBanksToMainBG(1); MapVRAMBanksToMainObj(2);
    Graphics_SetMainDisplayModeAndSelection(1,0,0);
    SetDisplayLayers((volatile unsigned*)0x04000000,0); SetDisplayWindows((volatile unsigned*)0x04000000,0);
    Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,0);
    DISPCNT=(DISPCNT&0xffcfffef)|0x200010;
    BG0CNT &= ~0x40; BG1CNT &= ~0x40; BG2CNT &= ~0x40; BG3CNT &= ~0x40;
    REG32(0x04000010)=0; REG32(0x04000014)=0; REG32(0x04000018)=0; REG32(0x0400001c)=0;
    ColorEffect_ConfigureBrightnessAdjust(0x04000050,0x3f,16);
    MapVRAMBanksToSubBG(0x80); MapVRAMBanksToSubObj(0x100);
    Graphics_WriteSubDisplayModeLowBits(0);
    SetDisplayLayers((volatile unsigned*)0x04001000,0); SetDisplayWindows((volatile unsigned*)0x04001000,0);
    Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,0);
    DISPCNTSUB=(DISPCNTSUB&0xffcfffef)|0x10;
    BG0CNTSUB &= ~0x40; BG1CNTSUB &= ~0x40; BG2CNTSUB &= ~0x40; BG3CNTSUB &= ~0x40;
    REG32(0x04001010)=0; REG32(0x04001014)=0; REG32(0x04001018)=0; REG32(0x0400101c)=0;
    ColorEffect_ConfigureBrightnessAdjust(0x04001050,0x3f,16);
    SetBackgroundControl(mainBackground+0,0xc00);
    SetBackgroundControl(mainBackground+1,0xd08);
    SetBackgroundControl(mainBackground+2,0xe10);
    SetBackgroundControl(mainBackground+3,0xf10);
    SetBackgroundControl(subBackground+0,0xc00);
    SetBackgroundControl(subRest+0,0xd00);
    SetBackgroundControl(subRest+1,0xe00);
    SetBackgroundControl(subRest+2,0xf00);
    DISPCNT &= ~0x38000000; DISPCNT &= ~0x07000000;
    REG16(0x04000304) &= ~0x8000;
    WfcUtility_InitializeTextCanvasServices(); Resource_InitializeTwoBuffersAndCallbackTask(); Resource_AllocateAndInitializeTwoStateBlocks(); WfcUtility_InitializeSpriteGroupPools(); GX_DispOn();
    DISPCNTSUB |= 0x10000;
    Graphics_WriteVBlankInterruptEnableAndReturnOldBit(1);
}
#pragma force_active reset
