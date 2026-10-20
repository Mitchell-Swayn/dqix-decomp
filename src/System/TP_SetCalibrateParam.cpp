// Original: arm9/main @ 0x020CD99C; symbol: func_020cd99c; size: 0x128.
// NitroSDK TP_SetCalibrateParam: installs touchscreen calibration and reciprocals.
// ABI confirmed by pret/pokeheartgold 14c48938174ec92563afc6d03de5fa162f4cfdce,
// lib/include/nitro/spi/ARM9/tp.h (signed-short offsets and dot sizes).
struct Calibration { short xOffset, yOffset, xScale, yScale; };
struct State { char prefix[28]; int xOffset,xScale,xReciprocal,yOffset,yScale,yReciprocal; unsigned short enabled; };
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" State TPWaitBusy_UnknownRoleZeroInitializedStorage;
int DisableIRQInterrupts();
void SetIRQInterruptState(int);
static inline void StartDivision(int numerator,int denominator) {
    *(volatile unsigned short*)0x04000280=0;
    *(volatile int*)0x04000290=numerator;
    *(volatile unsigned long long*)0x04000298=(unsigned)denominator;
}
extern "C" void TP_SetCalibrateParam(const Calibration *param)
{
    if (!param) { TPWaitBusy_UnknownRoleZeroInitializedStorage.enabled=0; return; }
    int irq=DisableIRQInterrupts();
    int xScale=param->xScale;
    if (xScale) {
        StartDivision(0x10000000,xScale);
        TPWaitBusy_UnknownRoleZeroInitializedStorage.xOffset=param->xOffset;
        TPWaitBusy_UnknownRoleZeroInitializedStorage.xScale=param->xScale;
        while (*(volatile unsigned short*)0x04000280 & 0x8000) {}
        TPWaitBusy_UnknownRoleZeroInitializedStorage.xReciprocal=*(volatile int*)0x040002a0;
    } else { TPWaitBusy_UnknownRoleZeroInitializedStorage.xOffset=0; TPWaitBusy_UnknownRoleZeroInitializedStorage.xScale=0; TPWaitBusy_UnknownRoleZeroInitializedStorage.xReciprocal=0; }
    int yScale=param->yScale;
    if (yScale) {
        StartDivision(0x10000000,yScale);
        TPWaitBusy_UnknownRoleZeroInitializedStorage.yOffset=param->yOffset;
        TPWaitBusy_UnknownRoleZeroInitializedStorage.yScale=param->yScale;
        while (*(volatile unsigned short*)0x04000280 & 0x8000) {}
        TPWaitBusy_UnknownRoleZeroInitializedStorage.yReciprocal=*(volatile int*)0x040002a0;
    } else { TPWaitBusy_UnknownRoleZeroInitializedStorage.yOffset=0; TPWaitBusy_UnknownRoleZeroInitializedStorage.yScale=0; TPWaitBusy_UnknownRoleZeroInitializedStorage.yReciprocal=0; }
    SetIRQInterruptState(irq);
    TPWaitBusy_UnknownRoleZeroInitializedStorage.enabled=1;
}
