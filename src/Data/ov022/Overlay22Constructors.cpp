// Overlay 22 has no static initializers. The runtime constructor walk ends here.
#pragma define_section overlay22_constructors ".ctor" RW
typedef void (*Overlay22Constructor)(void);
__declspec(section "overlay22_constructors")
Overlay22Constructor data_ov022_021d8a40 = 0;
