extern "C" { void func_0205af84(void*,void*,int); void func_0205ac40(void*,void*); }
struct Overlay8RenderBinding { unsigned char unknown[0x730]; void* handle; unsigned char* object; unsigned char unknown738[0xb18-0x738]; unsigned flags; };
// Original: arm9/ov008 @ 0x021889F8; symbol: func_ov008_021889f8; size: 0x5C.
extern "C" void func_ov008_021889f8(Overlay8RenderBinding* binding) {
    if(!binding->handle || !(binding->flags & 0x80000)) return;
    unsigned char* object=binding->object;
    *(int*)(object+0x2bc)=0xc8000;
    *(int*)(object+0x2c0)=0x62000;
    func_0205af84(binding->handle,binding->object+0x2a8,1);
    func_0205ac40(binding->handle,binding->object+0x2a8);
}
