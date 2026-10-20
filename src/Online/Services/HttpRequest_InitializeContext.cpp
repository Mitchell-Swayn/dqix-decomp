#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
struct Parameters{unsigned words[7];};typedef void*(*Allocate)(const char*,unsigned);extern "C" {void VectorizedMemset(void*,int,unsigned);int HttpRequest_AllocateBuffer(void*,void*,unsigned);int Network_ParseUrl(char*,const char*);int HttpRequest_BuildInitialGetOrPostHeader(char*);extern char HttpRequest_InitializeContext_TextALLOCHttpLowrecvbuf[],HttpRequest_InitializeContext_TextALLOCHttpLowsendbuf[];}
// Original: arm9/ov031 @0x02217c00; symbol:Network_InitializeRequestContextAndAllocateBuffers; size:0x11c.
// Initializes request context, copies seven parameter words, allocates two named buffers and parses URL before formatting request.
extern "C" int HttpRequest_InitializeContext(unsigned char* self,Parameters* parameters){Allocate allocate=(Allocate)parameters->words[3];VectorizedMemset(self,0,0x1c14);W(self,0x1a30)=-1;W(self,0x1a34)=-1;*(Parameters*)(self+0x1004)=*parameters;P(self,0x19cc)=(unsigned char*)allocate(HttpRequest_InitializeContext_TextALLOCHttpLowrecvbuf,0xb68);if(!P(self,0x19cc)){W(self,0x1020)=1;return 1;}P(self,0x19d0)=(unsigned char*)allocate(HttpRequest_InitializeContext_TextALLOCHttpLowsendbuf,0x5ea);if(!P(self,0x19d0)){W(self,0x1020)=1;return 1;}if(!HttpRequest_AllocateBuffer(self,self+0x1a08,W(self,0x100c))){W(self,0x1020)=1;return 1;}if(!Network_ParseUrl((char*)self,(char*)parameters->words[0])){W(self,0x1020)=1;return 1;}W(self,0x1020)=HttpRequest_BuildInitialGetOrPostHeader((char*)self);if(!W(self,0x1020))self[0x1000]=255;return W(self,0x1020);}
