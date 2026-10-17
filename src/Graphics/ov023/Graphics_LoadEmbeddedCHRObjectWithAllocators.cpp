#include <globaldefs.h>
#include <World/Object3D.h>
ARM
struct Tree;struct State;struct Item;
extern "C" Tree* FindTreeNodeForwarder(Tree*,unsigned);
extern "C" Item* func_ov011_0218466c(State*,unsigned);
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);
extern "C" void Object_InvokeSaveTextureImageVRAMState(char*);
// Original: arm9/ov023 @ 0x021FD120; symbol: func_ov023_021fd120; size: 0xC0.
extern "C" void Graphics_LoadEmbeddedCHRObjectWithAllocators(unsigned char* p,void* state,const void* archive,int value) {
if(!archive || !value)return;
unsigned char* memory=(unsigned char*)FindTreeNodeForwarder((Tree*)state,*(unsigned short*)(p+8));
unsigned char* texture=(unsigned char*)func_ov011_0218466c((State*)state,*(unsigned short*)(p+10));
if(!memory || !texture)return;
SafeAllocator* allocator=(SafeAllocator*)(memory+4);
allocator->GetSizeWithLargestBlockRemoved();
Graphics_RestoreTextureImageAndPaletteVRAMState(texture+4);
((Object3D*)(p+0x20))->Initialize();
ObjectArchiveLoadInfo info;info.fileData=archive;info.unk_8=value;info.allocator=allocator;
((Object3D*)(p+0x20))->LoadFromCHRArchive(&info);
((Object3D*)(p+0x20))->MaybeSetBCFGAnimation(0,0);
((Object3D*)(p+0x20))->SetScale(0x10a,0x10a,0x10a);
Object_InvokeSaveTextureImageVRAMState((char*)texture+4);
allocator->GetSizeWithLargestBlockRemoved();
}
