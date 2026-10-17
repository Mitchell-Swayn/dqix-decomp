#include <globaldefs.h>
ARM
#include <Graphics/Vector.h>
extern "C" unsigned data_ov000_02184264[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,Vector3i*);
extern "C" void __clear(void*,unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
struct ScriptRecord { unsigned type,next; unsigned char a,mode,value,flag; int upper,lower; Vector3i vector; unsigned char enabled; unsigned char padding[3]; };
// Original: arm9/ov000 @ 0x0216AED0; symbol: func_ov000_0216aed0; size: 0x1B8.
extern "C" int Resource_ScriptQueueType42VectorRecord(char* args,int count) {
 ScriptRecord* rec=(ScriptRecord*)_ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2],0x24);
 rec->type=0; rec->next=0; rec->type=0x2a;
 rec->a=_ZNK6Script9Parameter5ToIntEv(args);
 char* modeArg=args+8; args+=16;
 rec->mode=_ZNK6Script9Parameter5ToIntEv(modeArg);
 Vector3i vector; __clear(&vector,12);
 int value=0;
 rec->flag=0; rec->lower=0x666; rec->upper=0x1266;
 if(rec->mode==7) value=_ZNK6Script9Parameter5ToIntEv(args);
 else if(rec->mode==8) {
  if(count>=3) args=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(args,&vector);
  if(count>=4) value=_ZNK6Script9Parameter5ToIntEv(args);
 } else if(rec->mode==9) {
  char* current=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(args,&vector);
  rec->enabled=0;
  if(count>=6) rec->enabled=_ZNK6Script9Parameter5ToIntEv(current)!=0;
 } else if(rec->mode==11) {
  args=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(args,&vector);
  if(count>=6) {
   rec->flag=_ZNK6Script9Parameter5ToIntEv(args);
   if(count>=7) {
    rec->lower=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(args+8));
    rec->upper=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(args+16));
   }
  }
 } else if(count>=3) _ZN6Script9Parameter9ToVec3fixEP8Vector3i(args,&vector);
 rec->value=value;
 rec->vector=vector;
 Overlay_EnqueueLinkedNode(rec);
 return 1;
}
