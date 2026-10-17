#include <globaldefs.h>
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" int PowerManagement_ExecuteCommandSynchronously(unsigned,unsigned,void*);
// Original: arm9/main @ 0x020CEE18; symbol: func_020cee18; size: 0x3C.
extern "C" ARM int IPC_QueryCommandFifteenValueSix(unsigned* out){unsigned short result;int status=PowerManagement_ExecuteCommandSynchronously(15,6,&result);if(status!=0)return status;if(out)*out=result;return status;}
