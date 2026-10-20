// Original: arm9/main @ 0x020D84E8; symbol: func_020d84e8; size: 0x04.
// Empty hook called after both network queue operations, immediately before
// restoring their interrupt mask. Hook purpose beyond this call position is unknown.
#pragma thumb off
extern "C" void Network_LeaveQueueOperationHook(void)
{
}
