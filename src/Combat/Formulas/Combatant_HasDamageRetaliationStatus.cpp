struct DescriptorForFlag18 { unsigned char reserved[0x18]; unsigned int flags; };
struct RecordForFlag18 { unsigned char reserved[0x138]; DescriptorForFlag18* descriptor; };
// Original: arm9/ov024 @ 0x021E67B0; symbol: func_ov024_021e67b0; size: 0x18.
extern "C" int Combatant_HasDamageRetaliationStatus(RecordForFlag18* record) {
    return (record->descriptor->flags & 0x20) != 0;
}
