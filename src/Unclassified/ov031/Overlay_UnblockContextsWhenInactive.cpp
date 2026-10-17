#include <globaldefs.h>
ARM
extern "C" void* volatile data_ov031_0224e588;
extern "C" void func_ov031_0221038c(unsigned);
extern "C" int _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z15UnblockContextsP18BlockedContextList(void*);
extern "C" void Ov031_TemporarilySwitchProcessorContext(void);
// Original: arm9/ov031 @ 0x022101E0; symbol: func_ov031_022101e0; size: 0x70.
extern "C" int Overlay_UnblockContextsWhenInactive(void) {
    if (data_ov031_0224e588 == 0) return 1;
    func_ov031_0221038c(2);
    if (!_Z17IsContextInactiveP16ProcessorContext((char*)data_ov031_0224e588 + 0xa10)) {
        Ov031_TemporarilySwitchProcessorContext();
        return 0;
    }
    _Z15UnblockContextsP18BlockedContextList((char*)data_ov031_0224e588 + 0xa04);
    data_ov031_0224e588 = 0;
    return 1;
}
