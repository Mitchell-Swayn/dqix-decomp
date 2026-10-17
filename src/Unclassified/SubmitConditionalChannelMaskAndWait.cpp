#include <globaldefs.h>
#pragma always_inline on
extern "C" unsigned data_0210fd74[],data_0210fdbc[];extern "C" char data_0210fd7c[];
extern "C" void ProcessEightMaskBitsAndDispatchCommandThirteen(unsigned,unsigned,unsigned,unsigned),SubmitOperationCodeTwentyFive(unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned ReadSelectedGlobalValueUnderIRQProtection();extern "C" void func_020d24c4(unsigned),SoundCommand_WaitUntilRecordCompletes(unsigned);
extern "C" int MessageQueue_ReceiveWithOptionalBlocking(void*,void**,int);extern "C" void ResourceManager_ClearGlobalFlagMask(unsigned),DispatchMaskAndClearGlobalMaskBits(unsigned),ClearGlobal0210F3C0SlotBit(int);
inline bool available(int slot){return slot>=0;}
// Original: arm9/main @ 0x020BCF3C; symbol: func_020bcf3c; size: 0xF0.
extern "C" void SubmitConditionalChannelMaskAndWait(){unsigned *object=data_0210fdbc;if(!data_0210fd74[18])return;bool active=available((int)object[11]);unsigned mask=active?(1u<<object[11]):0;ProcessEightMaskBitsAndDispatchCommandThirteen(object[9],object[10],mask,0);if(active){unsigned state=ReadSelectedGlobalValueUnderIRQProtection();func_020d24c4(1);SoundCommand_WaitUntilRecordCompletes(state);while(MessageQueue_ReceiveWithOptionalBlocking(data_0210fd7c,0,0)){} }if(object[10])ResourceManager_ClearGlobalFlagMask(object[10]);if(object[8])DispatchMaskAndClearGlobalMaskBits(object[8]);if(active)ClearGlobal0210F3C0SlotBit(object[11]);if(object[1]==1)SubmitOperationCodeTwentyFive(0,0,0,0);object[0]=0;}
