#include <globaldefs.h>
ARM
struct NitroVM;
extern "C" int _Z12NitroVM_SeekP7NitroVMii(NitroVM*,int,int);
extern "C" int _Z17NitroVM_ReadAsyncP7NitroVMPvi(NitroVM*,void*,int);
struct AlignedReader { int pad[2]; unsigned offset; NitroVM* vm; unsigned char pending; };
// Original: arm9/ov016 @ 0x0218F5FC; symbol: func_ov016_0218f5fc; size: 0x7C.
extern "C" unsigned Filesystem_ReadAlignedAsync(AlignedReader* p,void* out,unsigned size) {
 unsigned aligned=p->offset&~511;
 unsigned skip=p->offset-aligned;
 unsigned count=size+skip;
 if(count&511) count=(count&~511)+512;
 _Z12NitroVM_SeekP7NitroVMii(p->vm,aligned,0);
 if(_Z17NitroVM_ReadAsyncP7NitroVMPvi(p->vm,out,count)==-1) return 0;
 p->offset+=size;
 p->pending=1;
 return skip;
}
