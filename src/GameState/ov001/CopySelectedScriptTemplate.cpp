#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov001_021658b8[];
extern "C" unsigned char data_ov001_021658d8[];
extern "C" unsigned char data_ov001_02165944[];
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" void* func_ov001_02153884(void*, int);
extern "C" void* memcpy(void*, const void*, unsigned);
// Original: arm9/ov001 @ 0x0215E444; symbol: func_ov001_0215e444; size: 0x70.
extern "C" int CopySelectedScriptTemplate(void* parameter) {
    data_ov001_021658b8[0x8c] = 0;
    int index = ReadScriptParameterAsInteger(parameter);
    if (index < 0) return 1;
    void* entry = func_ov001_02153884(data_ov001_021658d8, index);
    if (entry == 0) return 0;
    void* source = *(void**)((char*)entry + 4);
    if (source == 0) return 0;
    memcpy(data_ov001_02165944, source, 0x11);
    data_ov001_021658b8[0x9c] = 0;
    return 1;
}
