#include <globaldefs.h>
extern "C" void DispatchRenderRequestAtProvidedPosition(void*,void*,unsigned,unsigned,unsigned short);
struct Object
{
    unsigned char pad[16];
    char* entries;
    unsigned char rest[9];
    unsigned char count;
};
// Original: arm9/main @ 0x0204B988; symbol: func_0204b988; size: 0x30.
extern "C" ARM void Graphics_UpdateBoundedSixteenByteEntry(Object* p,unsigned index,unsigned a,unsigned b,unsigned short value)
{
    if(p->count<=index)return;
    if(!p->entries)return;
    DispatchRenderRequestAtProvidedPosition(p,p->entries+index*16,a,b,value);
}
