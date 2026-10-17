#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
extern "C" {
    extern unsigned char data_02153694[];
    extern SafeAllocator data_02153680;
    void ClearRecordAndInvalidateTwoIndices(void *);
// Original: arm9/main @ 0x020E5058; symbol: func_020e5058; size: 0x3C.
    void ResetTwoRecordsAndGlobalAllocatorPointer(){
        for(int i=0;i<2;i++)ClearRecordAndInvalidateTwoIndices(data_02153694+i*24);
        data_02153680.ResetAllocatorPointer();
    }
}
