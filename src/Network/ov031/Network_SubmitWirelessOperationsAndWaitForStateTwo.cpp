#include <globaldefs.h>
ARM
extern "C" int WirelessCommand_CopyValidatedSharedTwoThousandByteBlock(int);
extern "C" int WirelessCommand_SubmitOpcodeOne(void*);
extern "C" int SubmitOperationTwoAndNormalizePendingResult(unsigned);
extern "C" void func_ov031_022359e0();
extern "C" unsigned char* data_ov031_02290cf8;
// Original: arm9/ov031 @ 0x022358E8; symbol: func_ov031_022358e8; size: 0x9C.
extern "C" int Network_SubmitWirelessOperationsAndWaitForStateTwo(){
 data_ov031_02290cf8[0x1e5c]=1;
 WirelessCommand_CopyValidatedSharedTwoThousandByteBlock((int)(data_ov031_02290cf8+0x168c));
 if(*(unsigned short*)(data_ov031_02290cf8+0x168c)!=2){
 if(WirelessCommand_SubmitOpcodeOne((void*)func_ov031_022359e0)!=2)return 0;
 do{
 WirelessCommand_CopyValidatedSharedTwoThousandByteBlock((int)(data_ov031_02290cf8+0x168c));
 }while(*(unsigned short*)(data_ov031_02290cf8+0x168c)!=2);
 }
 if(SubmitOperationTwoAndNormalizePendingResult((unsigned)func_ov031_022359e0)!=2)return 0;
 return 1;
}
