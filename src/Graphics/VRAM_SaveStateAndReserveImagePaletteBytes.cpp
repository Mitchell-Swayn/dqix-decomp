#include <globaldefs.h>
#include <Graphics/VRAMAllocations.h>
#pragma always_inline on
struct ImageState {unsigned words[10];}; struct State {ImageState current,saved;unsigned imageKey,imageAmount; TexturePaletteVRAMState palette,paletteSaved; unsigned paletteKey,paletteAmount;};
extern "C" unsigned NNS_GfdAllocFrmTexVram(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0207DE48; symbol: func_0207de48; size: 0x108.
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(State* p,unsigned imageAmount,unsigned paletteAmount) {SaveTextureImageVRAMState(p->current.words); p->saved=p->current; SaveTexturePaletteVRAMState(&p->palette); unsigned first=((volatile TexturePaletteVRAMState*)&p->palette)->freeStart; unsigned second=((volatile TexturePaletteVRAMState*)&p->palette)->freeEnd;p->paletteSaved.freeStart=first;p->paletteSaved.freeEnd=second; p->imageKey=0; unsigned remaining=imageAmount; while((int)remaining>0){if((int)remaining>131072){p->imageKey=NNS_GfdAllocFrmTexVram(131072,0,0);remaining-=131072;}else {p->imageKey=NNS_GfdAllocFrmTexVram(remaining,0,0);remaining=0;}} if(imageAmount&&!p->imageKey)imageAmount=0; p->paletteKey=0; if(paletteAmount)p->paletteKey=AllocateTexturePaletteVRAM(paletteAmount,0,0); if(paletteAmount&&!p->paletteKey)paletteAmount=0; p->imageAmount=imageAmount;p->paletteAmount=paletteAmount; }
