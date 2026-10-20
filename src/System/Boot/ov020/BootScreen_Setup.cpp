#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
struct Matrix44;
extern "C" {
void* Network_GetConnectionManager();
void GameState_ResetRuntimeDefaults(void*);
void MapVRAMBanksToMainBG(int);
void Graphics_SetMainDisplayModeAndSelection(unsigned short,unsigned,int);
void Graphics_WriteSubDisplayModeLowBits(unsigned);
void G3X_SetClearColor(unsigned,unsigned,unsigned short,unsigned,int);
unsigned char GameState_ReadByteAtOffset4(GameState*);
void Geometry_BuildAndOptionallyApplyProjectionMatrix(int,int,int,int,int,int,int,int,Matrix44*);
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
}
// Original: arm9/ov020 @ 0x0218B5A0; symbol: BootScreen_Setup; size: 0x160.
// Initializes display/capture/projection registers and clears the overlay's allocator-backed state.
extern "C" void BootScreen_Setup(char* p){
 GameState* state=(GameState*)((void*)GameState::GetInstance());
 Network_GetConnectionManager();GameState_ResetRuntimeDefaults(state);
 MapVRAMBanksToMainBG(4);
 *(volatile unsigned*)0x04000000 &= ~0x07000000;
 *(volatile unsigned*)0x04000000 &= ~0x38000000;
 Graphics_SetMainDisplayModeAndSelection(1,0,1);
 Graphics_WriteSubDisplayModeLowBits(0);
 *(volatile unsigned short*)0x04000008 &= ~3;
 *(volatile unsigned short*)0x0400000a=(*(volatile unsigned short*)0x0400000a&~3)|1;
 G3X_SetClearColor(0,0,0x7fff,0x3f,0);
 if(GameState_ReadByteAtOffset4(state)==6)G3X_SetClearColor(0,31,0x7fff,0,0);
 Geometry_BuildAndOptionallyApplyProjectionMatrix(0,0xc0000,0,0x100000,-0x400000,0x400000,0x400000,1,0);
 *(volatile unsigned*)0x0400044c=0;
 *(volatile unsigned short*)0x04000304 &= ~0x8000;
 *(volatile unsigned*)0x04000580=0xbfff0000;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x470);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x484);
 *(int*)(p+8)=0;*(int*)(p+0x500)=0;*(int*)(p+0x4f0)=0;
 *(int*)(p+0x4ec)=0;*(int*)(p+0x4fc)=0;*(int*)(p+0x4f4)=0;
}
