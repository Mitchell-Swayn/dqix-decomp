#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct AllocatorUnion;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" unsigned char _ZNK8Object3D10GetField9eEv(void*);
extern "C" unsigned _ZNK8Object3D23GetTexturePaletteOffsetEv(void*);
extern "C" void* _ZN7Model3D7GetTEX0Ev(void*);
extern "C" void _Z28LockStagedTextureVRAMCopyingv();
extern "C" void _Z30UnlockStagedTextureVRAMCopyingv();
extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int,const void*,unsigned,unsigned,bool,bool);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
// Original: arm9/ov017 @ 0x0218F968; symbol: func_ov017_0218f968; size: 0x390.
extern "C" void Graphics_ModifyObjectTexturePalette(void*,int index,unsigned short color) {
void* gs=_ZN9GameState11GetInstanceEv();
unsigned short red=color&31;
unsigned short green=(color&0x3e0)>>5;
unsigned short blue=(color&0x7c00)>>10;
unsigned short* result=0;
_Z28LockStagedTextureVRAMCopyingv();
unsigned char* obj=(unsigned char*)_ZN9GameState20GetGameObjectByIndexEi(gs,index);
if(obj && *(void**)(obj+8)) {
unsigned char* tex=(unsigned char*)_ZN7Model3D7GetTEX0Ev(*(void**)(obj+8));
if(tex) {
if(_ZNK8Object3D10GetField9eEv(obj)==0) {
unsigned offset=*(unsigned*)(tex+0x2c);
if(_ZNK8Object3D23GetTexturePaletteOffsetEv(obj)) offset=_ZNK8Object3D23GetTexturePaletteOffsetEv(obj);
unsigned relative=*(unsigned*)(tex+0x38);
unsigned size=*(unsigned short*)(tex+0x30)<<3;
unsigned vramOffset=((offset<<16)>>13);
tex+=relative;
result=(unsigned short*)AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,size);
if(result) {
for(unsigned i=0;i<size/2;i++) {
unsigned short r=((unsigned short*)tex)[i]&31,g=(((unsigned short*)tex)[i]&0x3e0)>>5,b=(((unsigned short*)tex)[i]&0x7c00)>>10;
r+=red;g+=green;b+=blue;
if(r>31) r=31;
if(g>31) g=31;
if(b>31) b=31;
result[i]=r|(g<<5)|(b<<10);
}
_Z25CleanInvalidateCacheRangePKvj(result,size);
_Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0,result,vramOffset,size,false,true);
}
} else if(_ZNK8Object3D10GetField9eEv(obj)==1) {
unsigned offset=*(unsigned*)(tex+0x2c);
if(_ZNK8Object3D23GetTexturePaletteOffsetEv(obj)) offset=_ZNK8Object3D23GetTexturePaletteOffsetEv(obj);
unsigned size=*(unsigned short*)(tex+0x30)<<3;
offset=((offset<<16)>>13);
result=(unsigned short*)AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,size);
if(result) {
for(unsigned i=0;i<size/2;i++) result[i]=color;
_Z25CleanInvalidateCacheRangePKvj(result,size);
_Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0,result,offset,size,false,true);
}
} else if(_ZNK8Object3D10GetField9eEv(obj)==2) {
unsigned offset=*(unsigned*)(tex+0x2c);
if(_ZNK8Object3D23GetTexturePaletteOffsetEv(obj)) offset=_ZNK8Object3D23GetTexturePaletteOffsetEv(obj);
unsigned relative=*(unsigned*)(tex+0x38);
unsigned size=*(unsigned short*)(tex+0x30)<<3;
offset=((offset<<16)>>13);
tex+=relative;
result=(unsigned short*)AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,size);
if(result) {
float rf=(unsigned)red/31.0f,gf=(unsigned)green/31.0f,bf=(unsigned)blue/31.0f;
for(unsigned i=0;i<size/2;i++) {
unsigned short r=((unsigned short*)tex)[i]&31,g=(((unsigned short*)tex)[i]&0x3e0)>>5,b=(((unsigned short*)tex)[i]&0x7c00)>>10;
r=(unsigned)((unsigned)r*rf);g=(unsigned)((unsigned)g*gf);b=(unsigned)((unsigned)b*bf);
result[i]=r|(g<<5)|(b<<10);
}
_Z25CleanInvalidateCacheRangePKvj(result,size);
_Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0,result,offset,size,false,true);
}
}
}
}
_Z30UnlockStagedTextureVRAMCopyingv();
if(result) Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,result);
}
