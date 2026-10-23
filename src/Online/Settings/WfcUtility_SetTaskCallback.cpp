#pragma thumb off
#pragma force_active on
extern "C" { typedef void WfcTaskCallback(void*, void*); }
// Field roles are not established; names describe the observed layout operation.
// Original: arm9/ov031 @ 0x0223E2B8; symbol: func_ov031_0223e2b8; size: 0x8.
extern "C" void WfcUtility_SetTaskCallback(void* self, WfcTaskCallback* value)
{
    *(WfcTaskCallback**)((char*)self + 8) = value;
}
