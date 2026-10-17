#include <globaldefs.h>
struct State {char pad[0x99c];int type;char pad9a0[0x1012];unsigned char ready,done;};
extern "C" char data_02108760[],data_02107820[];
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(void*,int,void*);
// Original: arm9/main @ 0x020455F8; symbol: func_020455f8; size: 0x90.
extern "C" void DispatchReadyTypeOperationOnce(State* p) {if(p->done==1||!p->ready)return;switch(p->type){case 0:DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,10,data_02107820);break;case 1:DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,12,data_02107820);break;case 2:DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,11,data_02107820);break;}p->done=1;}
