#include <globaldefs.h>
ARM
extern "C" unsigned char* data_ov031_02290d38;
extern "C" unsigned short data_ov031_022493b2[],data_ov031_022493b0[];
extern "C" const unsigned short data_ov031_022493ac[];
extern "C" void* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void DispatchFiveValuesUsingGlobalConfigurationTable(unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned GetSubBG0ScreenBase();
extern "C" unsigned GetMainBG0ScreenBase();
extern "C" void Graphics_FillScreenBlockTilesWithPalette(unsigned short*,int,int,int,int,int,unsigned,unsigned);
extern "C" void func_ov031_0223ca40(void*,int);
extern "C" void Graphics_UploadDirtyBgCharacterData(void*);
extern "C" void* Unclassified_InvokeHelperWithZeroFifthArgument(int,void(*)(void*),void*,int);
struct Canvas {unsigned words[6];void* self;void* settings;unsigned a,b;void* pixels;void* task;};
// Original: arm9/ov031 @ 0x0223C560; symbol: func_ov031_0223c560; size: 0x178.
extern "C" Canvas* Graphics_CreateBG0CanvasForScreen(int screen,int settings) {
 unsigned short rows=data_ov031_022493b2[screen*2];
 unsigned short columns=data_ov031_022493b0[screen*2];
 Canvas* canvas=(Canvas*)(data_ov031_02290d38+0x610+screen*48);
 canvas->pixels=Memory_AllocateZeroedBlock(columns*rows*32,32);
 if(screen==1) {
  *(volatile unsigned short*)0x04001008&=~0x40;
  *(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&0x43)|0xc00;
 } else {
  *(volatile unsigned short*)0x04000008&=~0x40;
  *(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&0x43)|0xc00;
 }
 DispatchFiveValuesUsingGlobalConfigurationTable((unsigned)canvas,(unsigned)canvas->pixels,columns,rows,4);
 unsigned char* config=data_ov031_02290d38+settings*8;
 int one=1;
 canvas->self=canvas;
 canvas->settings=config;
 canvas->a=one;
 canvas->b=one;
 unsigned screenBase;
 if(screen==1) screenBase=GetSubBG0ScreenBase();
 else screenBase=GetMainBG0ScreenBase();
 int zero=0;
 int tile=data_ov031_022493ac[screen];
 Graphics_FillScreenBlockTilesWithPalette((unsigned short*)screenBase,columns,rows,zero,zero,32,tile,15);
 func_ov031_0223ca40(canvas,0);
 canvas->task=Unclassified_InvokeHelperWithZeroFifthArgument(1,Graphics_UploadDirtyBgCharacterData,data_ov031_02290d38+0x67c+screen,200);
 return canvas;
}
