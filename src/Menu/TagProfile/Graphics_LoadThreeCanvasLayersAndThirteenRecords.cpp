#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void Graphics_SetTextBackgroundScreenSize(int,unsigned);
extern "C" void Graphics_SetBackgroundColorMode(void*,unsigned);
extern "C" void Graphics_AllocateAndClearConfiguredBuffer(char*,void*);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(void*,void*,void*);
extern "C" void ColorEffect_ConfigureAlphaBlend(int,unsigned,unsigned,unsigned,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(void*);
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" int Graphics_LoadTaggedLayerResource(void*,const void*,unsigned,unsigned);
extern "C" void Tilemap_FillClippedRectangle(void*,int,int,int,int,int,int);
extern "C" void Graphics_CleanAndTransferScreenBuffer(char*,void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void TextCanvas_AllocateTilemapAndBindPixels(char*,void*,int,unsigned);
extern "C" void Selection_AttachBackwardLinkedDisplayRecords(unsigned char*,char*,unsigned char);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
// Original data: arm9/ov012 @ 0x218af75; symbol: data_ov012_0218af75.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 010203.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
// Original data: arm9/ov012 @ 0x218af78; symbol: data_ov012_0218af78.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 02010000000800001200000005000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
extern "C" const unsigned char GraphicsLoadThreeCanvasLayersAndThirteenRecords_UnknownRoleInitializedBytes[],GraphicsLoadThreeCanvasLayersAndThirteenRecords_UnknownRoleInitializedBytes_Variant2[];
struct Nibbles {unsigned char low:4,high:4;};
#define R16(a) (*(volatile unsigned short*)(a))
// Original: arm9/ov012 @ 0x02185F74; symbol: func_ov012_02185f74; size: 0x26C.
extern "C" void Graphics_LoadThreeCanvasLayersAndThirteenRecords(char* self) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 _ZN13SafeAllocator5ResetEv(self+0x20);
 char* layer;
 for(int i=0;i<3;i++) {
  layer=self+0x168+i*32;
  Graphics_SetTextBackgroundScreenSize((int)layer,0);
  unsigned high=GraphicsLoadThreeCanvasLayersAndThirteenRecords_UnknownRoleInitializedBytes[i];
  ((Nibbles*)(layer+0x1c))->low=0;
  ((Nibbles*)(layer+0x1c))->high=high;
  Graphics_SetBackgroundColorMode(layer,GraphicsLoadThreeCanvasLayersAndThirteenRecords_UnknownRoleInitializedBytes_Variant2[i]);
  Graphics_AllocateAndClearConfiguredBuffer(layer,self+0x20);
  Graphics_InvokeTwoIndexTransferCallback(layer,0,0);
 }
 R16(0x400000a)=(R16(0x400000a)&0x43)|0x1d00;
 R16(0x400000c)=(R16(0x400000c)&0x43)|0x1e00;
 R16(0x400000e)=(R16(0x400000e)&0x43)|0x1f08;
 ColorEffect_ConfigureAlphaBlend(0x4000050,2,1,10,6);
 char* block;char* file;unsigned fileLength,size;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(self+0x138c),(void**)&file,&fileLength);
 int count=ResourceFile_CountActiveStrideRecords(file);
 for(int i=0;i<count;i++) {
  char* resource=ResourceFile_GetPayloadByIndex(file,i,&block,&size);
  if(resource) {
   Graphics_LoadTaggedLayerResource(self+0x188,resource,(unsigned)(self+0x20),size);
   Graphics_LoadTaggedLayerResource(self+0x1a8,resource,(unsigned)(self+0x20),size);
  }
 }
 for(int i=0;i<3;i++) {
  layer=self+0x168+i*32;
  Tilemap_FillClippedRectangle(layer,0,0,0,32,25,0);
  Graphics_CleanAndTransferScreenBuffer(layer,0);
 }
 *(char**)(self+0x137c)=_ZN13SafeAllocator8AllocateEj((unsigned)(self+0x20),0x7800);
 char* child;
 for(int i=0;i<13;i++) {
  child=self+0x1c8+i*224;
  TextCanvas_AllocateTilemapAndBindPixels(child,self+0x20,*(int*)(self+0x137c),0x800);
  *(char**)(child+4)=self+0x188;
 }
 *(char**)(self+0x144)=self+0x168;
 self[0x15e]=3;
 Selection_AttachBackwardLinkedDisplayRecords((unsigned char*)self+0xac,self+0x1c8,13);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0x138c));
 *(int*)(self+0x138c)=-1;
}
