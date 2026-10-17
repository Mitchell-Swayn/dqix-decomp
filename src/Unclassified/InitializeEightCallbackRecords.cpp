#include <globaldefs.h>
struct Record { unsigned a,b; unsigned char flag,pad[3]; }; extern "C" Record data_02114260[8];
// Original: arm9/main @ 0x020D2930; symbol: func_020d2930; size: 0x30.
 extern "C" ARM void InitializeEightCallbackRecords() { int i=0;Record* p=data_02114260;do{p->a=0;p->b=0;++i;p->flag=0;++p;}while(i<8); }
