#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" unsigned char* WirelessSetup_ValidateMessageChecksum(const void*, unsigned*, unsigned*);
extern "C" unsigned short* WirelessSetup_ReadNextAlignedTaggedField(unsigned char**, unsigned char*, unsigned*, unsigned*);
// Original: arm9/ov031 @ 0x02220418; symbol: func_ov031_02220418; size: 0xD4.
// Validates a type-one capability message, requires fields one and two to equal one, and reports the optional capability.
extern "C" int WirelessSetup_ValidateCapabilityMessage(const void* message, int* hasOptionalCapability)
{
    struct Fields { unsigned char* cursor; unsigned fieldLength; unsigned tag; unsigned length; unsigned type; } fields;
    unsigned char* payload = WirelessSetup_ValidateMessageChecksum(message, &fields.type, &fields.length);
    int first = 0;
    int second;
    int optional = 0;
    fields.cursor = payload;
    second = 0;
    if (!payload) return 0;
    if (fields.type != 1) return 0;
    unsigned size = fields.length;
    fields.cursor = payload + 8;
    unsigned short* field;
    while ((field = WirelessSetup_ReadNextAlignedTaggedField(&fields.cursor, payload + size, &fields.tag, &fields.fieldLength)) != 0) {
        switch (fields.tag) {
        case 1: first = (unsigned short)((unsigned char)(*field >> 8) | ((*field << 8) & 0xff00)); break;
        case 2: second = (unsigned short)((unsigned char)(*field >> 8) | ((*field << 8) & 0xff00)); break;
        case 5: optional = (unsigned short)((unsigned char)(*field >> 8) | ((*field << 8) & 0xff00)); break;
        }
    }
    if (first != 1 || second != 1) return 0;
    if (optional >= 1) *hasOptionalCapability = 1;
    else *hasOptionalCapability = 0;
    return 1;
}
