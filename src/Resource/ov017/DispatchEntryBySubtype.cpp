#include <globaldefs.h>
ARM
extern "C" void func_ov017_021b996c(void*, void*, unsigned, unsigned, unsigned);
extern "C" void func_ov017_021b9a98(void*, void*, unsigned, unsigned, unsigned);
struct DispatchDescriptor { unsigned char pad[4]; unsigned char first; unsigned char second; unsigned char type; unsigned char pad2; unsigned short value; };
// Original: arm9/ov017 @ 0x021D0808; symbol: func_ov017_021d0808; size: 0x58.
extern "C" void DispatchEntryBySubtype(void* input, DispatchDescriptor* descriptor, unsigned unused, unsigned char* resourceBase) {
    void* resource = *(void**)(resourceBase + 0x3710);
    if (descriptor->type == 0) {
        func_ov017_021b996c(resource, input, descriptor->first, descriptor->second, descriptor->value);
    } else if (descriptor->type == 1) {
        func_ov017_021b9a98(resource, input, descriptor->first, descriptor->second, descriptor->value);
    }
}
