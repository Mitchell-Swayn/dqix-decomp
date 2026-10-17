#include <globaldefs.h>
struct Arguments { unsigned char count; unsigned char padding; unsigned short values[8]; short first,second; };
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void Memory_CopyIntoIndexedRecord(void*,unsigned,Arguments*);
// Original: arm9/ov011 @ 0x021882D4; symbol: func_ov011_021882d4; size: 0xB0.
extern "C" unsigned func_ov011_021882d4(void* self,int count) {
 Arguments args;
 VectorizedMemset(&args,0,sizeof(args));
 args.first=-1;
 args.second=-1;
 int i;
 unsigned id=func_ov011_02184c30(self);
 args.first=func_ov011_02184c30((char*)self+8);
 void* previous=(char*)self+16;
 self=(char*)self+24;
 args.second=func_ov011_02184c30(previous);
 args.count=count-3;
 for(i=0;i<args.count;i++) {
  unsigned value=func_ov011_02184c30(self);
  self=(char*)self+8;
  if(i<8) args.values[i]=value;
 }
 Memory_CopyIntoIndexedRecord(func_ov011_021849c8(func_ov017_021b2164()),id,&args);
 return 1;
}
