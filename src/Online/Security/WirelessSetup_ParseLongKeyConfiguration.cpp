#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" void System_Copy8WithReversedPointers(void*, const void*, unsigned);
extern "C" void Memory_FillBufferWithLowByteUsingVectorizedMemset(void*, unsigned, unsigned);
extern "C" unsigned short WirelessSetup_EncodeNetworkHalfword(unsigned short);
extern "C" unsigned WirelessSetup_EncodeNetworkWord(unsigned);
extern "C" unsigned WirelessSetup_DecodeNetworkHalfword(unsigned);
extern "C" unsigned WirelessSetup_DecodeNetworkWord(unsigned);
extern "C" void Aoss_SetLastError(int);
// Original: arm9/ov031 @ 0x0221DA60; symbol: func_ov031_0221da60; size: 0xB8.
// Parses linked long-key fields, bounds raw and terminated text keys, and copies them into their configuration slots.
extern "C" int WirelessSetup_ParseLongKeyConfiguration(unsigned char* source, unsigned char* destination)
{
    unsigned char* record = source + 6;
    unsigned char* first;
    unsigned char* text = destination + 8;
    unsigned char* raw = destination + 0x30;
    first = record;
    for (;;) {
        unsigned length = WirelessSetup_DecodeNetworkHalfword(*(unsigned short*)(record + 2));
        int type = record[0];
        switch (type) {
        case 0x30:
        case 0x40:
            if (length > 0x40) return -1;
            break;
        case 0x35:
        case 0x45:
            if (length > 0x21) return -1;
            break;
        }
        switch (type) {
        case 0x30:
        case 0x40:
            System_Copy8WithReversedPointers(raw, record + 6, length);
            *(unsigned*)(destination + 4) = length;
            break;
        case 0x35:
        case 0x45:
            if (length != 0 && record[length + 5] != 0) return -1;
            System_Copy8WithReversedPointers(text, record + 6, length);
            break;
        default:
            return -1;
        }
        unsigned next = *(unsigned short*)(record + 4);
        if (next != 0) record = first + WirelessSetup_DecodeNetworkHalfword(next);
        else return 0;
    }
}
