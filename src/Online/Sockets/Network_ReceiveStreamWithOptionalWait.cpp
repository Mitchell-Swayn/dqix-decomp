#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" int Network_SubmitBlockingSocketReceive(void*,void*,int,unsigned short*,unsigned*);
extern "C" int Network_CopyAvailableSocketReceiveData(void*,void*,int,unsigned short*,unsigned*);
// Original: arm9/ov031 @ 0x02205AD4; symbol: func_ov031_02205ad4; size: 0x74.
// Falls back from an immediate receive to a queued receive when waiting is requested.
// Scalar address words preserve the existing DispatchSocketReceiveWithPeek ABI;
// the two fallback receive helpers use independently inferred pointer contracts.
extern "C" int Network_ReceiveStreamWithOptionalWait(void* object,int destination,int count,int port,int address,int flags)
{
 if(*(signed char*)((unsigned char*)object+0x73)==4)
  return Network_SubmitBlockingSocketReceive(object,(void*)destination,count,(unsigned short*)port,(unsigned*)address);
 int result=Network_CopyAvailableSocketReceiveData(object,(void*)destination,count,(unsigned short*)port,(unsigned*)address);
 if(result!=-6)return result;
 if(!(flags&1))return result;
 return Network_SubmitBlockingSocketReceive(object,(void*)destination,count,(unsigned short*)port,(unsigned*)address);
}
