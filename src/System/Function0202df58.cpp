// Returns the 16-bit system state stored at 0x021015A0.
extern "C" volatile unsigned short data_021015a0;

extern "C" unsigned short func_0202df58()
{
    return data_021015a0;
}
