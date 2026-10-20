// Returns whether the signed byte at record offset 0x4354 is nonpositive.
extern "C" {
// Original: arm9/ov017 @ 0x021A4E70; symbol: func_ov017_021a4e70; size: 0x18.
int FieldInput_IsPostCommandCooldownExpired(const unsigned char* record)
{
    return *(const signed char*)(record + 0x4354) <= 0;
}
}
