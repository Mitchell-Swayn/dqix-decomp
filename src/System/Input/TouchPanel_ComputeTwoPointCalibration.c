#include <globaldefs.h>
extern int _Z20DisableIRQInterruptsv(void);
extern int _Z20SetIRQInterruptStatei(int);
#define DisableIRQInterrupts _Z20DisableIRQInterruptsv
#define SetIRQInterruptState _Z20SetIRQInterruptStatei
typedef signed long s32;
typedef unsigned long u32;
ARM
typedef struct TPCalibration { short x0,y0,xDotSize,yDotSize; } TPCalibration;
#define DIVCNT (*(volatile unsigned short*)0x04000280)
#define DIVNUM (*(volatile s32*)0x04000290)
#define DIVDEN (*(unsigned long long*)0x04000298)
#define DIVRESULT (*(volatile s32*)0x040002a0)
#define SET_DIV(n,d) do {DIVCNT=0;DIVNUM=(n);DIVDEN=(u32)(d);}while(0)
#define WAIT_DIV() while(DIVCNT&0x8000){}
// Original: arm9/main @ 0x020CDDEC; symbol: func_020cddec; size: 0x1EC.
// Computes Q8 per-pixel raw scales and Q2 origins from two raw/display touch pairs.
// Output layout matches pinned NitroSDK TPCalibrateParam (tp.h).
u32 TouchPanel_ComputeTwoPointCalibration(TPCalibration* out,unsigned short rawX1,unsigned short rawY1,unsigned short displayX1,unsigned short displayY1,unsigned short rawX2,unsigned short rawY2,unsigned short displayX2,unsigned short displayY2){
 int irq;
 s32 dy,rawDy,xScale,xOrigin,yScale,yOrigin;
 if(rawX1>=4096 || rawY1>=4096 || rawX2>=4096 || rawY2>=4096)return 1;
 if(displayX1>=256 || displayX2>=256 || displayY1>=192 || displayY2>=192)return 1;
 if(displayX1==displayX2 || displayY1==displayY2 || rawX1==rawX2 || rawY1==rawY2)return 1;
 irq=DisableIRQInterrupts();
 rawDy=rawY1-rawY2;
 dy=displayY1-displayY2;
 SET_DIV((rawX1-rawX2)<<8,displayX1-displayX2);
 WAIT_DIV();xScale=DIVRESULT;
 SET_DIV(rawDy<<8,dy);
 if(xScale>=32768 || xScale< -32768){SetIRQInterruptState(irq);return 1;}
 out->xDotSize=(short)xScale;
 xOrigin=(short)((((rawX1+rawX2)<<8)-out->xDotSize*(displayX1+displayX2))>>7);
 if(xOrigin>=32768 || xOrigin< -32768){SetIRQInterruptState(irq);return 1;}
 out->x0=(short)xOrigin;
 WAIT_DIV();yScale=DIVRESULT;
 SetIRQInterruptState(irq);
 if(yScale>=32768 || yScale< -32768)return 1;
 out->yDotSize=(short)yScale;
 yOrigin=(short)((((rawY1+rawY2)<<8)-out->yDotSize*(displayY1+displayY2))>>7);
 if(yOrigin>=32768 || yOrigin< -32768)return 1;
 out->y0=(short)yOrigin;
 return 0;
}
