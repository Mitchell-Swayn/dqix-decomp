#include <globaldefs.h>
ARM
#pragma opt_foldconstants off
#pragma opt_arithtransformation off
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" int Text_FormatBoundedVariadicString(...);
extern "C" int HttpRequest_AllocateBuffer(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
extern "C" char HttpRequest_BuildInitialGetOrPostHeader_FormatPOSTSHTTP10ContentTypeApplicationXWwwFormUrlencodedHostS[];
extern "C" char HttpRequest_BuildInitialGetOrPostHeader_FormatGETSHTTP10HostS[];
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x02218468; symbol: AppendSelectedFormatAndTwoStringsToBuffer; size: 0xc0.
extern "C" int HttpRequest_BuildInitialGetOrPostHeader(char* self){
char* buffer=self+0x19f8;const char* format;if(W(self,0x1008)==0)format=HttpRequest_BuildInitialGetOrPostHeader_FormatPOSTSHTTP10ContentTypeApplicationXWwwFormUrlencodedHostS;else format=HttpRequest_BuildInitialGetOrPostHeader_FormatGETSHTTP10HostS;int first=strlen(P(self,0x1124));int pattern=strlen(format);int required=first+((pattern-4)+strlen(P(self,0x1128)))+1024;if(HttpRequest_AllocateBuffer(self,self+0x19f8,required)!=1)return 1;int size=Text_FormatBoundedVariadicString(P(buffer,4),W(buffer,12),format,P(self,0x1128),P(self,0x1124));P(buffer,4)+=size;return 0;
}
