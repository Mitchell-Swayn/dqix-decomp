#include <globaldefs.h>
ARM
#pragma force_active on
struct PersistentIdentifierFields { unsigned long long first,second; unsigned short field10,field12; };
extern "C" {
void MI_CpuCopy8(const void*,void*,unsigned);
// Original data: arm9/ov031 @ 0x0224e6ac, 0x0224e6b2, 0x0224e6b8;
// symbols: data_ov031_0224e6ac, data_ov031_0224e6b2, data_ov031_0224e6b8; initially zero, packed identifier bytes.
extern unsigned char Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage[];
extern unsigned char WfcUtilityEncodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage[];
extern unsigned char WfcUtilityDecodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage_Variant3[];
}
// Original: arm9/ov031 @ 0x0221b8e4; symbol: func_ov031_0221b8e4; size: 0xc0.
// Packs the two 43-bit identifier fields and the trailing 10- and 16-bit fields into the shared 14-byte buffer.
extern "C" unsigned char* WfcUtility_EncodePersistentIdentifierFields(const PersistentIdentifierFields* fields)
{
    unsigned long long second=fields->second;
    MI_CpuCopy8(fields,Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage,5);
    Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage[5]=((fields->first>>40)&7)|((second&31)<<3);
    second>>=5;
    MI_CpuCopy8(&second,WfcUtilityEncodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage,4);
    Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage[10]=((second>>32)&63)|((fields->field10&3)<<6);
    Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage[11]=fields->field10>>2;
    MI_CpuCopy8(&fields->field12,WfcUtilityDecodePersistentIdentifierFields_UnknownRoleZeroInitializedStorage_Variant3,2);
    return Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage;
}

#pragma force_active reset
