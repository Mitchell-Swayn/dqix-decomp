// Original: arm9/main @ 0x020CD99C; symbol: func_020cd99c; size: 0x128.
// NitroSDK TP_SetCalibrateParam: installs touchscreen calibration and reciprocals.
// ABI confirmed by pret/pokeheartgold 14c48938174ec92563afc6d03de5fa162f4cfdce,
// lib/include/nitro/spi/ARM9/tp.h (signed-short offsets and dot sizes).
struct Calibration { short xOffset, yOffset, xScale, yScale; };
struct State { char prefix[28]; int xOffset,xScale,xReciprocal,yOffset,yScale,yReciprocal; unsigned short enabled; };
extern "C" State data_021117b0;
int DisableIRQInterrupts();
void SetIRQInterruptState(int);
static inline void StartDivision(int numerator,int denominator) {
    *(volatile unsigned short*)0x04000280=0;
    *(volatile int*)0x04000290=numerator;
    *(volatile unsigned long long*)0x04000298=(unsigned)denominator;
}
extern "C" void TP_SetCalibrateParam(const Calibration *param)
{
    if (!param) { data_021117b0.enabled=0; return; }
    int irq=DisableIRQInterrupts();
    int xScale=param->xScale;
    if (xScale) {
        StartDivision(0x10000000,xScale);
        data_021117b0.xOffset=param->xOffset;
        data_021117b0.xScale=param->xScale;
        while (*(volatile unsigned short*)0x04000280 & 0x8000) {}
        data_021117b0.xReciprocal=*(volatile int*)0x040002a0;
    } else { data_021117b0.xOffset=0; data_021117b0.xScale=0; data_021117b0.xReciprocal=0; }
    int yScale=param->yScale;
    if (yScale) {
        StartDivision(0x10000000,yScale);
        data_021117b0.yOffset=param->yOffset;
        data_021117b0.yScale=param->yScale;
        while (*(volatile unsigned short*)0x04000280 & 0x8000) {}
        data_021117b0.yReciprocal=*(volatile int*)0x040002a0;
    } else { data_021117b0.yOffset=0; data_021117b0.yScale=0; data_021117b0.yReciprocal=0; }
    SetIRQInterruptState(irq);
    data_021117b0.enabled=1;
}
