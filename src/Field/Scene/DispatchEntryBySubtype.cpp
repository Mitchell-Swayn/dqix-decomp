#include <globaldefs.h>
ARM
extern "C" void UpdateIndexedConnectionAvailability(void*, void*, unsigned, unsigned, unsigned);
extern "C" void FieldDialogue_ProcessPeerResponse(void*, void*, unsigned, unsigned, unsigned);
struct DispatchDescriptor { unsigned char pad[4]; unsigned char first; unsigned char second; unsigned char type; unsigned char pad2; unsigned short value; };
// Original: arm9/ov017 @ 0x021D0808; symbol: func_ov017_021d0808; size: 0x58.
extern "C" void DispatchEntryBySubtype(void* input, DispatchDescriptor* descriptor, unsigned unused, unsigned char* resourceBase) {
    void* resource = *(void**)(resourceBase + 0x3710);
    if (descriptor->type == 0) {
        UpdateIndexedConnectionAvailability(resource, input, descriptor->first, descriptor->second, descriptor->value);
    } else if (descriptor->type == 1) {
        FieldDialogue_ProcessPeerResponse(resource, input, descriptor->first, descriptor->second, descriptor->value);
    }
}
