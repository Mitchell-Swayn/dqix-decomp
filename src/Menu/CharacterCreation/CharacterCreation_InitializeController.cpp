#include <globaldefs.h>
ARM
extern "C" {
void* SystemState_GetGlobalFlags();void SystemState_SetFlags(void*,int);
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
void _ZN13ZoneState27545ResetEv(void*);void ResourceStringLoader_Reset(void*);
void CharacterNameFilter_ResetAndResolveTokenGlyphs(void*);
void Graphics_InitializeCanvasTransferState(void*);void Selection_InitializeDisplayController(void*);
void TextCanvas_InitializeLayoutAndTransferDefaults(void*);void _ZN8Object3D10InitializeEv(void*);
void Grid_InitializeDirectionalSelection(void*);void CharacterCreation_ClearChoiceGridLayout(void*);
void* memset(void*,int,unsigned);int TextLookup_FindGlyphIndexByText(const void*,int);
// Original data: arm9/ov009 @ 0x0218ACA4; symbol: data_ov009_0218aca4.
// Initialized bytes: 2a 00; text glyph lookup token. Extent remains unresolved.
// Full reference: docs/data-symbols/ov009.md.
extern unsigned char CharacterCreationInitializeController_UnknownRoleInitializedBytes[];
}
#define W(o) (*(int*)(self+(o)))
#define H(o) (*(short*)(self+(o)))
// Original: arm9/ov009 @ 0x0218454C; symbol: func_ov009_0218454c; size: 0x278.
// Initializes embedded allocators, canvas and selection state, then clears character choices.
extern "C" void CharacterCreation_InitializeController(unsigned char* self,int mode,int standalone) {
 self[0xd95]=standalone;
 if(self[0xd95]==1)SystemState_SetFlags(SystemState_GetGlobalFlags(),15);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x14);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x28);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x3c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x50);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x64);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x78);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0x8c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+0xa0);
 W(0xb4)=0;W(0xb8)=0;W(0xc0)=0;W(0xc4)=0;
 _ZN13ZoneState27545ResetEv(self+0xc8);ResourceStringLoader_Reset(self+0xe0);W(0xf8)=0;
 CharacterNameFilter_ResetAndResolveTokenGlyphs(self+0xfc);
 Graphics_InitializeCanvasTransferState(self+0x138);Graphics_InitializeCanvasTransferState(self+0x158);
 Graphics_InitializeCanvasTransferState(self+0x178);Graphics_InitializeCanvasTransferState(self+0x198);
 Graphics_InitializeCanvasTransferState(self+0x1b8);Graphics_InitializeCanvasTransferState(self+0x1d8);
 Selection_InitializeDisplayController(self+0x1f8);Selection_InitializeDisplayController(self+0x2b4);
 for(int i=0;i<1;i++)TextCanvas_InitializeLayoutAndTransferDefaults(self+0x370+i*0xe0);
 for(int i=0;i<4;i++)TextCanvas_InitializeLayoutAndTransferDefaults(self+0x450+i*0xe0);
 W(0x7d0)=0;W(0x7d4)=0;W(0x7d8)=0;W(0x7dc)=0;W(0x7e0)=0;W(0x7e4)=0;W(0x7e8)=0;W(0x7ec)=0;
 W(0x7f0)=0;W(0x7f4)=0;W(0x7f8)=0;W(0x7fc)=0;W(0x800)=0;W(0x804)=0;
 _ZN8Object3D10InitializeEv(self+0x78+0x800);_ZN8Object3D10InitializeEv(self+0xd8+0xc00);
 Grid_InitializeDirectionalSelection(self+0x3ec+0x800);CharacterCreation_ClearChoiceGridLayout(self+0x2c+0xc00);
 H(0xc4c)=-1;H(0xc4e)=-1;H(0xc50)=-1;H(0xc52)=-1;H(0xc54)=-1;H(0xc56)=-1;
 self[0xc58]=0;self[0xc59]=0;self[0xd84]=0;self[0xd85]=0;W(0xd88)=0;W(0xd8c)=-1;W(0xd90)=0;self[0xd94]=0;H(0xd96)=0;H(0xd98)=0;
 memset(self+0x19c+0xc00,0,4);
 for(int i=0;i<2;i++)*(self+i+0xda0)=1;
 self[0xda2]=mode;self[0xda3]=0;
 for(int i=0;i<2;i++){*(self+i+0xda4)=0;*(self+i+0xda6)=0;*(self+i+0xda8)=0;*(self+i+0xdaa)=0;*(self+i+0xdac)=0;*(self+i+0xdae)=0;}
 W(0xdb0)=0;self[0xdb4]=TextLookup_FindGlyphIndexByText(CharacterCreationInitializeController_UnknownRoleInitializedBytes,0);self[0xdb6]=0;
}
