#include <globaldefs.h>
ARM
struct BufferSizes { unsigned values[6]; };
extern "C" {
// Original data: arm9/ov014 @ 0x2189498; symbol: data_ov014_02189498.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0002000000010000003002000008000000280000000400001e00100010001000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern const BufferSizes MemoryAllocateGraphicsBuffersAndNestedAllocators_UnknownRoleInitializedBytes_Variant2;
// Original data: arm9/ov014 @ 0x2189480; symbol: data_ov014_02189480.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0064000080020000cc080000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern const unsigned MemoryAllocateGraphicsBuffersAndNestedAllocators_UnknownRoleInitializedBytes[];
unsigned char* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
void _ZN13SafeAllocator5ResetEv(void*);
void _ZN8Object3D10InitializeEv(void*);
void _ZN8Object3D10EnableFlagEi(void*,int);
void Graphics_InitializeSpriteTransformDefaults(void*);
void Graphics_InitializeSpriteResourceBuffers(unsigned char*);
}
// Original: arm9/ov014 @ 0x02184300; symbol: func_ov014_02184300; size: 0x1C4.
extern "C" void Memory_AllocateGraphicsBuffersAndNestedAllocators(unsigned char* p,void* allocator) {
 if(!allocator) return;
 BufferSizes sizes=MemoryAllocateGraphicsBuffersAndNestedAllocators_UnknownRoleInitializedBytes_Variant2;
 *(void**)(p+0x3c)=_ZN13SafeAllocator8AllocateEj(allocator,0x78);
 *(void**)(p)=_ZN13SafeAllocator8AllocateEj(allocator,12);
 for(int i=0;i<3;i++) (*(void***)(p))[i]=_ZN13SafeAllocator8AllocateEj(allocator,MemoryAllocateGraphicsBuffersAndNestedAllocators_UnknownRoleInitializedBytes[i]);
 *(void**)(p+0x40)=_ZN13SafeAllocator8AllocateEj(allocator,0xac);
 *(void**)(p+0x44)=_ZN13SafeAllocator8AllocateEj(allocator,0x2c8);
 *(void**)(p+0x58)=_ZN13SafeAllocator8AllocateEj(allocator,0x4c);
 *(void**)(p+0x60)=_ZN13SafeAllocator8AllocateEj(allocator,0x48);
 *(void**)(p+0x64)=_ZN13SafeAllocator8AllocateEj(allocator,0x48);
 *(void**)(p+0x68)=_ZN13SafeAllocator8AllocateEj(allocator,0x200);
 *(void**)(p+4)=_ZN13SafeAllocator8AllocateEj(allocator,0x54);
 *(void**)(p+8)=_ZN13SafeAllocator8AllocateEj(allocator,0x78);
 for(unsigned char i=0;i<3;i++) Graphics_InitializeSpriteTransformDefaults(*(unsigned char**)(p+8)+i*0x28);
 Graphics_InitializeSpriteResourceBuffers(*(unsigned char**)(p+4));
 (*(unsigned char**)(p+4))[0x50]=0;
 unsigned char* record=*(unsigned char**)(p+4);
 *(void**)(record+0x40)=*(void**)(p+8);
 *(unsigned short*)(record+0x4c)=3;
 for(int i=0;i<6;i++) {
  unsigned size,offset;
  offset=i*0x14;
  size=sizes.values[i];
  void* block=_ZN13SafeAllocator8AllocateEj(allocator,size);
  _ZN13SafeAllocator11CreateTypeAEPvj(*(unsigned char**)(p+0x3c)+offset,block,size);
  _ZN13SafeAllocator5ResetEv(*(unsigned char**)(p+0x3c)+offset);
 }
 _ZN8Object3D10InitializeEv(*(void**)(p+0x40));
 _ZN8Object3D10EnableFlagEi(*(void**)(p+0x40),4);
 p[0x82]|=4;
}
