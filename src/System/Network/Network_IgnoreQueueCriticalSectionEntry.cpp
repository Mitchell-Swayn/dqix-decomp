// Original: arm9/main @ 0x020D84E4; symbol: func_020d84e4; size: 0x4.
// Empty entry hook called after interrupt masking before network queue operations.
// Paired with the empty exit hook func_020d84e8; broader synchronization intent is uncertain.
extern "C" void Network_IgnoreQueueCriticalSectionEntry()
{
}
