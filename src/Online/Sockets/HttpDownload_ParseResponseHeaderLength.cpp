#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x2249e28; symbol: data_ov031_02249e28.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0d0a0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char HttpRequest_InsertHeader_Text[],HttpDownload_ParseResponseHeaderLength_TextContentLength[],HttpDownloadParseResponseHeaderLength_UnknownRoleInitializedBytes[];extern "C" char* strstr(const char*,const char*);extern "C" unsigned strlen(const char*);extern "C" int Runtime_ParseStringAsBaseTenInteger(const char*);extern "C" void _Z9LockMutexP5Mutex(void*);extern "C" void _Z11UnlockMutexP5Mutex(void*);
// Original: arm9/ov031 @ 0x02217FB0; symbol: ParseHeaderBoundaryAndDecimalLengthUnderMutex; size: 0xE8.
extern "C" int HttpDownload_ParseResponseHeaderLength(char* self){char* source=P(self,0x1a08);char** headers=(char**)(self+0x1a08);if(!strstr(source,HttpRequest_InsertHeader_Text))return 0;char* end=strstr(source,HttpRequest_InsertHeader_Text)+4;_Z9LockMutexP5Mutex(self+0x1a18);W(self,0x1a34)=headers[1]-end;_Z11UnlockMutexP5Mutex(self+0x1a18);char* field=strstr(headers[0],HttpDownload_ParseResponseHeaderLength_TextContentLength);if(!field)return 1;unsigned prefix=strlen(HttpDownload_ParseResponseHeaderLength_TextContentLength);char* delimiter=strstr(field+prefix,HttpDownloadParseResponseHeaderLength_UnknownRoleInitializedBytes);signed char saved=*delimiter;*delimiter=0;_Z9LockMutexP5Mutex(self+0x1a18);W(self,0x1a30)=Runtime_ParseStringAsBaseTenInteger(field+prefix);_Z11UnlockMutexP5Mutex(self+0x1a18);*delimiter=saved;return 1;}
