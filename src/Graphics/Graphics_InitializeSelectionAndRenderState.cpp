#include <globaldefs.h>
ARM
#pragma opt_common_subs off
extern "C" {
void* memset(void*,int,unsigned);
void ResetEightZoneRenderParts(char*);
void TextEntry_ResetGlyphRenderRecord(char*);
void WindowFrame_SetLinkedPosition(void*,short,short);
void WindowFrame_SetLinkedDimensions(char*,int,int);
void TextWindow_SetClippingEdges(unsigned*,unsigned,unsigned,unsigned,unsigned);
void WindowFrame_ResetTransitionRecord(unsigned char*);
void Graphics_ClearAndStageSharedBuffers(char*);
void TextWindow_SetControlDelays(char*,int,int);
void TextLayout_InitializeSelectionPanel(unsigned char*);
void ResourceHandle_InitializeSequenceHandle(void*);
void WindowControl_InitializeDefaultsAndReset(unsigned char*,unsigned char,unsigned char);
// Original data: arm9/main @ 0x2107820; symbol: data_02107820.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char TextWindowFlushPendingResourceAction_UnknownRoleZeroInitializedStorage[];
}
#define W(o) (*(int*)(self+(o)))
#define H(o) (*(short*)(self+(o)))
#define B(o) (*(signed char*)(self+(o)))
struct ZoneParts { unsigned char data[0x448]; };
struct Owner { unsigned char pad[0x19e0]; ZoneParts zone; };
// Original: arm9/main @ 0x02042C68; symbol: func_02042c68; size: 0x364.
extern "C" void Graphics_InitializeSelectionAndRenderState(unsigned char* self) {
B(0x30)=-1; B(0x31)=-1; W(0x38)=0; W(0x3c)=9; W(0x8c)=0;
TextLayout_InitializeSelectionPanel(self+0x90);
W(0x2c8)=0;memset(self+0x2cc,0,4);
W(0x2d0)=-1;W(0x2d8)=0;W(0x2dc)=0;W(0x2e0)=0;H(0x2e4)=0;B(0x2e6)=1;B(0x2e7)=0;W(0x2e8)=0;
memset(self+0x4ac,0,0x400);
W(0x8ac)=0;memset(self+0x8b0,0,0x40);
B(0x912)=0;B(0x19b0)=0;W(0x9b0)=0;
for(int i=0;i<128;i++) {
TextEntry_ResetGlyphRenderRecord((char*)self+0x9b8+i*0x1c);
*(signed char*)(self+i+0x17b8)=0;
}
W(0x954)=0;W(0x958)=0;B(0x1962)=0;
WindowControl_InitializeDefaultsAndReset(self+0x1964,0,0);
WindowControl_InitializeDefaultsAndReset(self+0x1988,0,1);
WindowFrame_ResetTransitionRecord(self+0x914);
WindowFrame_ResetTransitionRecord(self+0x930);
ResetEightZoneRenderParts((char*)&((Owner*)self)->zone);
*(void**)(self+0x1e20)=self+0x914;
WindowFrame_SetLinkedPosition((unsigned char*)&((Owner*)self)->zone,0,128);
WindowFrame_SetLinkedDimensions((char*)&((Owner*)self)->zone,256,64);
B(0x19b1)=1;W(0x1e28)=0;B(0x19cc)=0;
Graphics_ClearAndStageSharedBuffers((char*)self);
B(0x19bb)=1;W(0x994)=-1;B(0x19bc)=0;B(0x19b2)=1;W(0x99c)=0;
B(0x19b3)=0;B(0x19b4)=0;B(0x19b5)=0;W(0x9a0)=0;H(0x187c)=0x7fff;W(0x9a4)=3;W(0x9b4)=0;B(0x19ac)=0;B(0x19ad)=0;
TextWindow_SetControlDelays((char*)self,0,-1);
B(0x19b8)=0;W(0x1848)=0;W(0x184c)=0;W(0x1850)=256;W(0x1854)=192;
TextWindow_SetClippingEdges((unsigned*)(self+0x1848),0,136,256,192);
B(0x19b9)=1;W(0x1858)=0;W(0x185c)=136;W(0x1860)=12;W(0x1864)=16;B(0x19ae)=0;B(0x19af)=0;W(0x1868)=0;W(0x1838)=-1;W(0x183c)=0;W(0x990)=128;
memset(self+0x95c,0,32);
memset(self+0x97c,0,16);
B(0x19c2)=1;
memset(self+0x1882,0xff01,128);
memset(self+0x1902,0,64);
H(0x1942)=0;H(0x1944)=0;B(0x19be)=0;H(0x1948)=-1;
B(0x194d)=127;B(0x194c)=B(0x194d);B(0x194b)=B(0x194c);B(0x194a)=B(0x194b);
B(0x195a)=8;B(0x195b)=0;B(0x19bf)=0;B(0x19cf)=0;B(0x19cb)=0;B(0x19cc)=0;B(0x19ce)=0;
ResourceHandle_InitializeSequenceHandle(TextWindowFlushPendingResourceAction_UnknownRoleZeroInitializedStorage);
B(0x19d0)=0;H(0x19da)=-1;B(0x19dc)=1;B(0x19b1)=0;
}
