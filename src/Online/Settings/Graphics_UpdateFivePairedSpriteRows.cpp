#include <globaldefs.h>
ARM
extern "C" int FastIntModulus(int,int);
struct Global {unsigned short pad,position;unsigned char* state;};
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Global TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0222C660; symbol: func_ov031_0222c660; size: 0xBC.
extern "C" void Graphics_UpdateFivePairedSpriteRows(){
 int y=54-FastIntModulus(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.position,28);
 int count=TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state[0x51];
 if(count>5)count=5;
 int i=0;
 if(count>0){do{
 unsigned* a=*(unsigned**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state+0x10+i*4);
 *a=(*a&0xfe00ff00)|((y-2)&255)|0xb30000;
 unsigned* b=*(unsigned**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state+0x24+i*4);
 *b=(*b&0xfe00ff00)|((y+1)&255)|0xd20000;
 i++;y+=28;
 }while(i<count);
 }
 TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state[0x56]=1;
}
