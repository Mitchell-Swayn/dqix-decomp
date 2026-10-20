#pragma thumb off
#pragma force_active on
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov023 @ 0x021F6BB8; symbol: func_ov023_021f6bb8; size: 0x8.
extern "C" unsigned MenuRecordList_GetBackgroundTaskId(void* self)
{
    return *(unsigned*)((char*)self + 4);
}
