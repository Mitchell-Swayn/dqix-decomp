#include <globaldefs.h>
ARM
extern "C" int ValidateStatusNineOrTenAndReadSharedActiveFlags(int,int,void*,unsigned,unsigned short,unsigned short,unsigned short);
extern "C" void MBi_CheckWmErrcode(int,int);
// Original: arm9/ov027 @ 0x021DCEF8; symbol: func_ov027_021dcef8; size: 0x4C.
// Submits MP data on the fixed port and reports operation-fifteen errors.
extern "C" int MBi_SetMPData(int callback,void *data,unsigned size,unsigned unused,unsigned short destinations)
{
    int result=ValidateStatusNineOrTenAndReadSharedActiveFlags(callback,0,data,size,destinations,1,3);
    MBi_CheckWmErrcode(15,result);
    return result;
}
