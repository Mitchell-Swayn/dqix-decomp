struct Triple { unsigned x,y,z; };
extern "C" void __clear(void*,unsigned);
// Original: arm9/main @ 0x02049C08; symbol: func_02049c08; size: 0x58.
// Reads the nested target X/Z fields at +0x10/+0x18 with Y=204.
// A missing nested state produces zero. ABI: twelve-byte result buffer r0, receiver r1.
extern "C" Triple Object_ReadNestedTargetXZWithFixedY(char* owner)
{
    Triple result;
    __clear(&result,12);
    unsigned* data=*(unsigned**)(owner+0x13c);
    if(!data) return result;
    unsigned z=data[6];
    unsigned x=data[4];
    result.x=x;
    result.y=0xcc;
    result.z=z;
    return result;
}
