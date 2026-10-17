#include <globaldefs.h>
extern "C" unsigned IPC_SendTwoWordCommandAndStoreCallbackState(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020CE648; symbol: func_020ce648; size: 0x88.
extern "C" unsigned PowerManagement_SetSelectedDeviceEnabled(int a,int b,unsigned c,unsigned d) {int command=0;if(a==0){if(b==1)command=6;if(b==0)command=7;}else if(a==1){if(b==1)command=4;if(b==0)command=5;}else if(a==2){if(b==1)command=8;if(b==0)command=9;}if(!command)return 0xffff;return IPC_SendTwoWordCommandAndStoreCallbackState(command,0,0,c,d);}
