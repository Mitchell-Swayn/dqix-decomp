#include <globaldefs.h>
ARM
#pragma force_active on
struct PersistentIdentifierFields { unsigned long long first,second; unsigned short field10,field12; };
extern "C" {
// Original data: arm9/ov031 @ 0x0224e6a0; symbol: data_ov031_0224e6a0; initially zero, storage context with page address at offset 8.
extern unsigned WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x0224e6ac; symbol: data_ov031_0224e6ac; initially zero, packed 14-byte identifier.
extern unsigned char Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage[];
unsigned char* WfcUtility_EncodePersistentIdentifierFields(const PersistentIdentifierFields*);
void CRC16_BuildReflectedPolynomialTable(void*,unsigned);
int Network_SendIpcCommandAndInvalidateResponse(unsigned,unsigned,void*);
void DisableInterruptsAndHaltForever();
void MI_CpuCopy8(const void*,void*,unsigned);
unsigned CRC16_ComputeWithInitialZero(const void*,const void*,unsigned);
void WfcUtility_WriteSettingsStorageUntilAccepted(unsigned,unsigned,void*);
int Network_ValidateAndCompareByteRange(void*,unsigned,unsigned,void*);
int WfcUtility_FinalizeSettingsStorageTransfer();
}
// Original: arm9/ov031 @ 0x0221aed8; symbol: func_ov031_0221aed8; size: 0xdc.
// Writes the packed identifier and CRC into two settings pages, retries until readback agrees, and finalizes storage.
extern "C" int WfcUtility_WriteIdentifierHeaderToSettingsPages(const PersistentIdentifierFields* fields,unsigned char* buffer)
{
    int i;
    unsigned address=WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[2];
    WfcUtility_EncodePersistentIdentifierFields(fields);
    CRC16_BuildReflectedPolynomialTable(buffer+0x200,0xa001);
    for(i=0;i<2;++i,address+=0x100) {
        if(!Network_SendIpcCommandAndInvalidateResponse(address,0x100,buffer)) { DisableInterruptsAndHaltForever(); return 0; }
        MI_CpuCopy8(Copy14BytesFromGlobalBuffer_UnknownRoleZeroInitializedStorage,buffer+0xf0,14);
        *(unsigned short*)(buffer+0xfe)=CRC16_ComputeWithInitialZero(buffer+0x200,buffer,0xfe);
        do { WfcUtility_WriteSettingsStorageUntilAccepted(address,0x100,buffer); }
        while(!Network_ValidateAndCompareByteRange(buffer,address,0x100,buffer+0x100));
    }
    return WfcUtility_FinalizeSettingsStorageTransfer()!=0;
}
#pragma force_active reset
