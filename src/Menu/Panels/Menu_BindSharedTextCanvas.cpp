#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
// Original data: arm9/ov023 @ 0x21ff9e0; symbol: data_ov023_021ff9e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" char MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov023 @ 0x021DDC34; symbol: func_ov023_021ddc34; size: 0x64.
extern "C" int Menu_BindSharedTextCanvas(char* obj,short a,short b,short c,short d) {
    char* buffer=*(char**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+4);
    int result=0;
    if(buffer && obj) {
        memset(buffer,0,0x1800);
        *(char**)(obj+8)=*(char**)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+4);
        *(short*)(obj+0xac)=a;
        *(short*)(obj+0xae)=b;
        *(short*)(obj+0xa8)=c;
        *(short*)(obj+0xaa)=d;
        result=1;
    }
    return result;
}
