#include <globaldefs.h>
ARM
extern "C" unsigned data_ov000_02184264[];
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
struct Record { unsigned type,next; unsigned char id:7; unsigned char enabled:1; unsigned char value,pad[2]; };
// Original: arm9/ov000 @ 0x0216BCF0; symbol: func_ov000_0216bcf0; size: 0xAC.
extern "C" int Script_AllocateTypeSeventyNineBitfieldRecord(char* params,int count) {
 Record* record=(Record*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],12);
 record->type=0x4f;
 record->id=(unsigned char)_ZNK6Script9Parameter5ToIntEv(params);
 record->value=1;
 record->enabled=1;
 if(count>=2) {
  record->value=_ZNK6Script9Parameter5ToIntEv(params+8);
  if(count>=3) record->enabled=(unsigned char)_ZNK6Script9Parameter5ToIntEv(params+16);
 }
 Overlay_EnqueueLinkedNode(record);
 return 1;
}
