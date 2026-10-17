// ReadPointerAtOffset4334: describes the directly observed offset-level operation; field roles remain unknown.
// Original: arm9/ov017 @ 0x021BDBC0; symbol: func_ov017_021bdbc0; size: 0xC.
extern "C" void* ReadPointerAtOffset4334(void* object)
{
    return *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x4334);
}
