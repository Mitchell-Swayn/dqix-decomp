#include <globaldefs.h>
ARM
extern "C" char* HttpResponse_FindFieldValue(const char*,int,char*,unsigned); extern "C" unsigned strlen(const char*); extern "C" int Network_DecodeCustomBase64(const char*,unsigned,char*,unsigned);
// Original: arm9/ov031 @ 0x02218E84; symbol: Network_DecodeLabelToBoundedOutput; size: 0x54.
// Finds a label, decodes its base64 contents into a bounded output, and terminates short results.
extern "C" int Network_DecodeLabelToBoundedOutput(const char* input,int option,char* output,unsigned capacity) { char* label=HttpResponse_FindFieldValue(input,option,output,capacity); if(!label)return 0; int result=Network_DecodeCustomBase64(label,strlen(label),output,capacity); if(result==(int)0xffffffff || (unsigned)result>=capacity)return result; output[result]=0; return result; }
