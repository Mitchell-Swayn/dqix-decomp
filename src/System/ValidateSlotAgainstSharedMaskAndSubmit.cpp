#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <System/Cache.h>
struct Context{int pad;unsigned char* data;};extern "C" {Context* ReadGlobalOperationContextPointerAt4();int TestCurrentStatusAgainstVariadicAllowedValues(int,int,int,int,int,int);void SetGlobalIndexedWordAtOffset18(int,int);int func_020d40bc(int,int,unsigned int);
// Original: arm9/main @ 0x020D559C; symbol: func_020d559c; size: 0xE8.
int ValidateSlotAgainstSharedMaskAndSubmit(int value,unsigned int slot){Context* context=ReadGlobalOperationContextPointerAt4();int result=TestCurrentStatusAgainstVariadicAllowedValues(5,7,9,8,10,11);if(result)return result;unsigned short type=*(unsigned short*)context->data;if(type==7||type==9){if(slot<1||slot>15)return 6;InvalidateDataCacheRange(context->data+0x182,2);if(!(*(unsigned short*)(context->data+0x182)&(1U<<slot)))return 7;}else if(slot)return 6;SetGlobalIndexedWordAtOffset18(13,value);result=func_020d40bc(13,1,1U<<slot);if(!result)result=2;return result;}}
