#include <globaldefs.h>
ARM
struct Texture {char pad[0x2c];unsigned handle:16,rest:16;unsigned short size;char pad2[6];unsigned paletteOffset;};
struct IndexList {int v[14];};
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
int _ZNK8Object3D10GetField9eEv(void*);
void _Z28LockStagedTextureVRAMCopyingv();
void _Z30UnlockStagedTextureVRAMCopyingv();
unsigned char* GameResources_GetAlternateLeaderModel(void*);
unsigned char* _ZN7Model3D7GetTEX0Ev(void*);
void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
void Memory_FreeThroughAllocatorUnion(void*,void*);
void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
void _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(unsigned,const void*,unsigned,unsigned,bool,bool);
// Original data: arm9/ov017 @ 0x21d6260; symbol: data_ov017_021d6260.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000c8000000ff000000ffffffff.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern IndexList GraphicsApplyMemberModelPaletteColor_UnknownRoleInitializedBytes;
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
}
// Original: arm9/ov017 @ 0x0218FD34; symbol: func_ov017_0218fd34; size: 0x478.
extern "C" void Graphics_ApplyMemberModelPaletteColor(void* self,int member,unsigned short color) {
 void* state=_ZN9GameState11GetInstanceEv();
 IndexList indices=GraphicsApplyMemberModelPaletteColor_UnknownRoleInitializedBytes;
 indices.v[0]=member;
 indices.v[1]=member*12+19;
 indices.v[2]=member*12+20;
 indices.v[3]=member*12+22;
 indices.v[4]=member*12+23;
 indices.v[5]=member*12+24;
 indices.v[6]=member*12+25;
 indices.v[7]=member*12+26;
 indices.v[8]=member*12+27;
 indices.v[9]=member*12+28;
 indices.v[10]=member*12+29;
 unsigned short red=color&31,green=(color&0x3e0)>>5,blue=(color&0x7c00)>>10;
 unsigned short* buffers[13]={};
 int mode=0;
 void* base=_ZN9GameState20GetGameObjectByIndexEi(state,indices.v[0]);
 if(base)mode=_ZNK8Object3D10GetField9eEv(base);
 _Z28LockStagedTextureVRAMCopyingv();
 for(int i=0;indices.v[i]>-1;i++){
   int index=indices.v[i];
   unsigned char* object;
   if(index==255)object=GameResources_GetAlternateLeaderModel(self);
   else object=_ZN9GameState20GetGameObjectByIndexEi(state,index);
   if(!object)continue;
   if(*(short*)(object+2)<=-1 && index!=255)continue;
   void* model=*(void**)(object+8);
   if(!model)continue;
   unsigned char* texture=_ZN7Model3D7GetTEX0Ev(model);
   if(!texture)continue;
   unsigned short* palette;unsigned size;int j2;unsigned offset;
   offset=((Texture*)texture)->handle*8;
   palette=(unsigned short*)(texture+((Texture*)texture)->paletteOffset);
   size=((Texture*)texture)->size*8;
   if(mode==0){
     buffers[i]=(unsigned short*)AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,size);
     if(!buffers[i])continue;
     for(unsigned j=0;j<size/2;j++){
       unsigned short src=palette[j];
       unsigned short r=src&31;
       r+=red;
       unsigned short g=(src&0x3e0)>>5;
       unsigned short b=(src&0x7c00)>>10;
       g+=green;b+=blue;
       if(r>31)r=31;if(g>31)g=31;if(b>31)b=31;
       buffers[i][j]=r|(g<<5)|(b<<10);
     }
     _Z25CleanInvalidateCacheRangePKvj(buffers[i],size);
     _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0,buffers[i],offset,size,false,true);
   }else if(mode==1){
     buffers[i]=(unsigned short*)AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,size);
     if(!buffers[i])continue;
     for(unsigned j=0;j<size/2;j++)buffers[i][j]=color;
     _Z25CleanInvalidateCacheRangePKvj(buffers[i],size);
     _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0,buffers[i],offset,size,false,true);
   }else if(mode==2){
     buffers[i]=(unsigned short*)AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,size);
     if(!buffers[i])continue;
     float rf=(float)red/31.0f,gf=(float)green/31.0f,bf=(float)blue/31.0f;
     for(j2=0;j2<size/2;j2++){
       unsigned short src=palette[j2];
       unsigned short r=src&31,g=(src&0x3e0)>>5,b=(src&0x7c00)>>10;
       r=(unsigned short)((float)r*rf);
       g=(unsigned short)((float)g*gf);
       b=(unsigned short)((float)b*bf);
       buffers[i][j2]=r|(g<<5)|(b<<10);
     }
     _Z25CleanInvalidateCacheRangePKvj(buffers[i],size);
     _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0,buffers[i],offset,size,false,true);
   }
 }
 _Z30UnlockStagedTextureVRAMCopyingv();
 for(unsigned i=0;i<13;i++)if(buffers[i])Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,buffers[i]);
}
