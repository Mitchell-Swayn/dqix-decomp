#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* memset(void*,int,unsigned);int BuildRequestBufferAndExecuteScript(void*,int,const void*,unsigned,void*,unsigned,unsigned char,unsigned,unsigned);char* strstr(const char*,const char*);unsigned strlen(const char*);void* memcpy(void*,const void*,unsigned);extern char ProfileEditor_GeneratePreviewText_MarkupPAGE[];}
// Original: arm9/ov012 @ 0x0218AE74; symbol: Text_ExecuteRequestAndExtractOptionalSuffix; size: 0x100.
// Executes a bounded script request and extracts suffix after an optional formatting marker.
extern "C" int ProfileEditor_GeneratePreviewText(unsigned char* self,void* request){self[0x1335]=1;int result=1;memset(P(self,0x1374),0,2400);BuildRequestBufferAndExecuteScript(request,W(self,0x13b0),P(self,0x13b4),W(self,0x13b8),P(self,0x1374),2400,0,(unsigned)(self+0x1440),(unsigned)(self+0x1400));char* text=(char*)P(self,0x1374);char* marker=strstr(text,ProfileEditor_GeneratePreviewText_MarkupPAGE);if(!marker){result=0;self[0x14bd]=0;self[0x1334]=0;self[0x1335]=0;}else if(!self[0x14bd])*marker=0;else text=marker+strlen((char*)P(self,0x13b0))+11;memset(P(self,0x13bc),0,242);memcpy(P(self,0x13bc),text,strlen(text));return result;}
