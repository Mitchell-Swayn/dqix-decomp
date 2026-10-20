// SetByteOffset1ToOne: describes the directly observed offset-level operation; field roles remain unknown.
// Original: arm9/ov017 @ 0x021C178C; symbol: func_ov017_021c178c; size: 0xC.
extern "C" void Field_CompleteQueuedOperation(void* object)
{
    static_cast<unsigned char*>(object)[1] = 1;
}
