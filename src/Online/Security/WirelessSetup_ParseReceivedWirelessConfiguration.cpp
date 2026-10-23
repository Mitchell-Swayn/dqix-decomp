#pragma thumb off
#include <std_library_functions.h>
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
// Original data: arm9/ov031 @ 0x0224F9C4; symbol: data_ov031_0224f9c4.
// Shared mutable BSS; logical extent is unresolved. See docs/data-symbols/ov031.md.
extern "C" unsigned WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/ov031 @ 0x0224F9F0; symbol: data_ov031_0224f9f0.
// Shared mutable BSS; logical extent is unresolved. See docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant5[];
// Original data: arm9/ov031 @ 0x0224F8C4; symbol: data_ov031_0224f8c4.
// Shared mutable BSS; logical extent is unresolved. See docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov031 @ 0x0224FA28; symbol: data_ov031_0224fa28.
// Shared mutable BSS; logical extent is unresolved. See docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant6[];
// Original data: arm9/ov031 @ 0x0224FAC0; symbol: data_ov031_0224fac0.
// Shared mutable BSS; logical extent is unresolved. See docs/data-symbols/ov031.md.
extern "C" unsigned WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant7[];
struct Zero32 { unsigned words[8]; };
struct Zero72 { unsigned words[18]; };
extern "C" unsigned char* WirelessSetup_ReadNextAlignedTaggedField(unsigned char**, const unsigned char*, unsigned*, int*);
extern "C" int WirelessSetup_FormatHexByte(char*, int);
// Original: arm9/ov031 @ 0x022206E0; symbol: func_ov031_022206e0; size: 0x1D4.
// Reads aligned configuration tags, decodes network halfwords, and stores SSID, security settings, and key text.
extern "C" int WirelessSetup_ParseReceivedWirelessConfiguration(unsigned char* packet)
{
    unsigned char* start = packet + 8;
    unsigned char* cursor = start;
    int result = 0;
    unsigned short value = *(unsigned short*)packet;
    unsigned total = (unsigned short)(((unsigned char)(value >> 8)) | ((value << 8) & 0xff00));
    unsigned tag;
    int length;
    unsigned char* field;
    while ((field = WirelessSetup_ReadNextAlignedTaggedField(&cursor, start + total, &tag, &length)) != 0) {
        switch (tag) {
        case 0x201:
            __builtin__clear(WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant4,32);
            memcpy(WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant4, field, length);
            result = 1;
            break;
        case 0x202:
            value = *(unsigned short*)field;
            *(unsigned*)WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant5 = (unsigned short)(((unsigned char)(value >> 8)) | ((value << 8) & 0xff00));
            break;
        case 0x203:
            value = *(unsigned short*)field;
            { int i=0;
            unsigned char* output=WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage_Variant3;
            unsigned decoded=(unsigned short)(((unsigned char)(value >> 8)) | ((value << 8) & 0xff00));
            for (;i<4;++i,output+=40) *(unsigned*)(output+0x15c)=decoded; }
            break;
        case 0x204:
            value = *(unsigned short*)field;
            { unsigned char* output=WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage_Variant3;
            int i=0;
            unsigned decoded=(unsigned short)(((unsigned char)(value >> 8)) | ((value << 8) & 0xff00));
            for (;i<4;++i,output+=40) *(unsigned*)(output+0x160)=decoded; }
            break;
        case 0x205:
            value = *(unsigned short*)field;
            *(unsigned*)(WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant5 + 4) = (unsigned short)(((unsigned char)(value >> 8)) | ((value << 8) & 0xff00));
            break;
        case 0x206: case 0x207: case 0x208: case 0x209:
            memset(WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant6 + (tag - 0x206)*40, 0, 32);
            if (*(unsigned*)(WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant5 + 0x30) == 1) {
                char* output = (char*)WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant6 + (tag - 0x206)*40;
                for (int i = 0; i < length; ++i) output += WirelessSetup_FormatHexByte(output, (signed char)*field++);
            } else memcpy(WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant6 + (tag - 0x206)*40, field, length);
            break;
        case 0x20a:
            __builtin__clear(WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant7,72);
            memcpy(WirelessSetupPrepareWirelessEncryptionKeys_UnknownRoleZeroInitializedStorage_Variant7, field, length);
            break;
        }
    }
    return result;
}
