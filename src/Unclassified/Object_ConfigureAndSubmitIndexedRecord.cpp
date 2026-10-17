#include <globaldefs.h>
ARM
extern "C" void func_0205afb0(void*,void*,unsigned short);
extern "C" void func_0205ac40(void*,void*);
struct Record {char pad[12];unsigned a,b,c,d;char pad1c[4];unsigned short value;unsigned char flags;char pad23[3];unsigned char mode;char pad27;};
// Original: arm9/main @ 0x0202756C; symbol: func_0202756c; size: 0x78.
extern "C" void Object_ConfigureAndSubmitIndexedRecord(char* owner,unsigned a,unsigned b,int index,unsigned char flags,unsigned char mode,unsigned short kind,unsigned char value,unsigned c,unsigned d) {
    Record* p=(Record*)(owner+232)+index;
    p->c=a;p->d=b;p->flags=flags&127;p->mode=mode&3;
    if(kind<15)func_0205afb0(owner+148,p,kind);
    if(value<64)p->value=value;
    p->a=c;p->b=d;
    func_0205ac40(owner+148,p);
}
