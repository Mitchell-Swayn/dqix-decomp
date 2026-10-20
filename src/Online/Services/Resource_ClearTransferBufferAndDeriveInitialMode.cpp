#include <globaldefs.h>
ARM
extern "C" unsigned OnlineError_GetStatusAndCategory(int*,unsigned*);
extern "C" void* memset(void*,int,unsigned);
extern "C" void OnlineTransfer_SetOperationMode(void*,int);
// Original: arm9/ov031 @ 0x02245478; symbol: Resource_ClearTransferBufferAndDeriveInitialMode; size: 0xb0.
// Clears transfer buffer and derives error/mode from query result with mode6 special status14/15.
extern "C" void Resource_ClearTransferBufferAndDeriveInitialMode(char* self) {
 int error;unsigned mode;unsigned result=OnlineError_GetStatusAndCategory(&error,&mode);memset(*(void**)(self+0x37c),0,*(unsigned*)(self+0x380));*(int*)(self+0x394)=-error;
 switch(mode){case 0:*(int*)(self+0x394)=0;break;case 1:*(int*)(self+0x394)=0;break;case 6:if(result-14<=1)self[0x398]=1;break;case 7:self[0x398]=2;break;}
 OnlineTransfer_SetOperationMode(self,0);
}
