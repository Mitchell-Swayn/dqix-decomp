#include <globaldefs.h>
#include <GameState/GameState.h>
struct Scroll {int x,y;signed char dx,dy;unsigned char unknown,disabled;};
// Original: arm9/main @ 0x020A63F8; symbol: func_020a63f8; size: 0xAC.
extern "C" void Graphics_UpdateWrappedSubBG1Scroll(Scroll* self) {GameState::GetInstance();if(self->disabled)return;*(volatile unsigned*)0x04001014=(self->x&0x1ff)|((self->y<<16)&(0x1ff<<16));self->x+=self->dx;if(self->x>=256)self->x-=256;if(self->x<=-1)self->x+=256;self->y+=self->dy;if(self->y>=256)self->y-=256;if(self->y<=-1)self->y+=256;}
