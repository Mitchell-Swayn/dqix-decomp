#include <globaldefs.h>
ARM
extern "C" { void Memory_FreeThroughAllocatorUnion(void*,void*); void _ZN13SafeAllocator4FreeEPv(void*,void*); void _ZN13SafeAllocator7DestroyEv(void*); void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*); void Memory_DestroyEightSignedAllocators(); extern unsigned char data_02114e20[]; }
// Original: arm9/ov017 @ 0x021BB108; symbol: func_ov017_021bb108; size: 0x9C.
extern "C" void Memory_DestroyNestedAndDetachedAllocators(unsigned char* object) {
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(object+0x7c)) {
  Memory_DestroyEightSignedAllocators();
  void* nested=_ZNK13SafeAllocator18GetSignedAllocatorEv(object+0x124);
  if(nested) {
   _ZN13SafeAllocator7DestroyEv(object+0x124);
   _ZN13SafeAllocator4FreeEPv(object+0x7c,nested);
  }
  void* parent=_ZNK13SafeAllocator18GetSignedAllocatorEv(object+0x7c);
  _ZN13SafeAllocator7DestroyEv(object+0x7c);
  Memory_FreeThroughAllocatorUnion(data_02114e20,parent);
 }
 if(*(void**)(object+0x138)) {
  void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(*(void**)(object+0x138));
  if(allocation) {
   _ZN13SafeAllocator7DestroyEv(*(void**)(object+0x138));
   Memory_FreeThroughAllocatorUnion(data_02114e20,allocation);
   *(void**)(object+0x138)=0;
  }
 }
}
