#include <globaldefs.h>
extern "C" char data_0210fd74[],data_0210fdbc[];extern "C" void ProcessEightMaskBitsAndDispatchCommandThirteen(int,int,unsigned,int),func_020d24c4(int),SoundCommand_WaitUntilRecordCompletes(int);extern "C" int ReadSelectedGlobalValueUnderIRQProtection();struct State{char pad[0x24];int first,second,index;};
// Original: arm9/main @ 0x020BD02C; symbol: func_020bd02c; size: 0x60.
extern "C" ARM void DispatchSavedStateAndSynchronizeCommandCounter(){State* p=(State*)data_0210fdbc;if(!*(int*)(data_0210fd74+0x48))return;unsigned mask=p->index>=0?1u<<p->index:0;ProcessEightMaskBitsAndDispatchCommandThirteen(p->first,p->second,mask,0);int old=ReadSelectedGlobalValueUnderIRQProtection();func_020d24c4(1);SoundCommand_WaitUntilRecordCompletes(old);}
