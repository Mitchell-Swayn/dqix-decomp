#include <globaldefs.h>
#include <System/Memory.h>
#include <Graphics/NSBXX/JACInternal.h>
ARM
extern "C" int WfcUtility_ReadSettingsStorageBase(void*);
extern "C" void CRC16_BuildReflectedPolynomialTable(unsigned short*,unsigned);
extern "C" unsigned WfcUtility_ReadFourSettingsPages(int);
extern "C" unsigned CRC16_ComputeWithInitialZero(void*,void*,unsigned);
extern "C" int WfcUtility_ValidateConnectionProfile(char*);
extern "C" void Copy14BytesFromGlobalBuffer(void*);
extern "C" int WfcUtility_InitializeDefaultSettingsPages(char*);
extern "C" bool Network_SendFourCRCProtectedBlocksUntilVerified(char*);
extern "C" void Graphics_ClearIndexedBufferAndSetTerminalByte(void*,unsigned);
// Original: arm9/ov031 @ 0x0221B9B0; symbol: WfcUtility_LoadAndRepairSettingsPages; size: 0x308.
// Validates four CRC-protected pages, repairs redundant records and sends repaired pages.
// Page validity and status-code meanings remain named by observed behavior only.
extern "C" int WfcUtility_LoadAndRepairSettingsPages(char* self) {
 VectorizedMemset(self,0,0x700);
 if(!WfcUtility_ReadSettingsStorageBase(self))return -10001;
 CRC16_BuildReflectedPolynomialTable((unsigned short*)(self+0x500),0xa001);
 if(!WfcUtility_ReadFourSettingsPages((int)self))return -10001;
 int valid[4];VectorizedMemset(valid,0,16);
 int i=0;char* block=self;char* record=self;
 do {
  unsigned crc=CRC16_ComputeWithInitialZero(self+0x500,block,254);
  if(crc==*(unsigned short*)(self+(i<<8)+254))
   if(WfcUtility_ValidateConnectionProfile(record))valid[i]=1;
  ++i;block+=256;record+=256;
 }while(i<3);
 unsigned fourthCrc=CRC16_ComputeWithInitialZero(self+0x500,self+0x300,254);
 if(fourthCrc==*(unsigned short*)(self+0x3fe))valid[3]=1;
 if(valid[0]&&valid[1]&&valid[2]&&valid[3]){Copy14BytesFromGlobalBuffer(self+0xf0);return 0;}
 if(!valid[0]&&!valid[1]&&!valid[2]&&!valid[3]){
  WfcUtility_InitializeDefaultSettingsPages(self);
  return Network_SendFourCRCProtectedBlocksUntilVerified(self)?0:-10000;
 }
 if(!(valid[0]&&valid[1])&&!(valid[2]&&valid[3])){
  WfcUtility_InitializeDefaultSettingsPages(self);
  return Network_SendFourCRCProtectedBlocksUntilVerified(self)?0:-10000;
 }
 if(!valid[0]&&!valid[1]){
  WfcUtility_InitializeDefaultSettingsPages(self);
  return Network_SendFourCRCProtectedBlocksUntilVerified(self)?-10003:-10000;
 }
 if(!valid[0]){
  Graphics_ClearIndexedBufferAndSetTerminalByte(self,0);
  MI_CpuCopy8(self+0x1f0,self+0xf0,14);
  ((unsigned char*)self)[0xef]=((unsigned char*)self)[0x1ef];
 }else if(!valid[1]){
  Graphics_ClearIndexedBufferAndSetTerminalByte(self,1);
  MI_CpuCopy8(self+0xf0,self+0x1f0,14);
  ((unsigned char*)self)[0x1ef]=((unsigned char*)self)[0xef];
 }
 Copy14BytesFromGlobalBuffer(self+0xf0);
 if(!valid[2])Graphics_ClearIndexedBufferAndSetTerminalByte(self,2);
 if(!valid[3])MIi_CpuClear16(0,self+0x300,256);
 int changed=0;i=0;
 do {
  if(!valid[i]&&((unsigned char)((unsigned char*)self)[0xef]&(1<<i))){
   ((unsigned char*)self)[0xef]&=~(1<<i);changed=1;((unsigned char*)self)[0x1ef]=(unsigned char)((unsigned char*)self)[0xef];
  }
 }while(++i<3);
 if(!Network_SendFourCRCProtectedBlocksUntilVerified(self))return -10000;
 return changed?-10002:0;
}
