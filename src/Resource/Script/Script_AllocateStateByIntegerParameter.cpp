#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Script.h>

struct ScriptTableState
{
    void* state;
    unsigned char reserved[8];
    SafeAllocator* allocator;
};

extern "C" {
    extern ScriptTableState data_02108efc;
    void AllocateSixtyFourByteRecordArrayAndResetCount(unsigned int* state, SafeAllocator* allocator, int count);
// Original: arm9/main @ 0x02089B64; symbol: func_02089b64; size: 0x2C.
    ARM int Script_AllocateStateByIntegerParameter(Script::Parameter* parameter)
    {
        AllocateSixtyFourByteRecordArrayAndResetCount((unsigned int*)data_02108efc.state, data_02108efc.allocator, (short)parameter->ToInt());
        return 1;
    }
}
