#include <globaldefs.h>
ARM
struct State;
struct Table { unsigned values[19]; };
extern "C" Table data_ov004_021700ec;
extern "C" void Grotto_ConfigureHardwareAndRefreshContext();
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void func_ov011_02184a24(State*, unsigned, unsigned);
extern "C" void func_ov011_02184c28(State*, unsigned);
// Original: arm9/ov004 @ 0x0216AA70; symbol: func_ov004_0216aa70; size: 0x7C.
extern "C" void Resource_InitializeTableWithCallback(unsigned allocator, State* state) {
    Table table = data_ov004_021700ec;
    char* copy = _ZN13SafeAllocator8AllocateEj(allocator, sizeof(Table));
    memcpy(copy, &table, sizeof(Table));
    func_ov011_02184a24(state, (unsigned)copy, 19);
    func_ov011_02184c28(state, (unsigned)Grotto_ConfigureHardwareAndRefreshContext);
}
