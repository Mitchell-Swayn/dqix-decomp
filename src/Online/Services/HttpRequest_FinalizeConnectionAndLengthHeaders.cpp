#include <globaldefs.h>
ARM
extern "C" int HttpRequest_InsertHeader(void*,const char*,const char*);
extern "C" char* strstr(const char*,const char*);
extern "C" unsigned strlen(const char*);
extern "C" int Text_FormatBoundedVariadicString(char*,unsigned,const char*,...);
// Original data: arm9/ov031 @ 0x2249e00; symbol: data_ov031_02249e00.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25640000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char HttpRequest_FinalizeConnectionAndLengthHeaders_TextConnection[],HttpRequest_FinalizeConnectionAndLengthHeaders_TextClose[],HttpRequest_InsertHeader_Text[],HttpRequestFinalizeConnectionAndLengthHeaders_UnknownRoleInitializedBytes[],HttpRequest_FinalizeConnectionAndLengthHeaders_TextContentLength[];
// Original: arm9/ov031 @ 0x02217D1C; symbol: Network_AddFormattedPayloadLengthHeader; size: 0x98.
extern "C" int HttpRequest_FinalizeConnectionAndLengthHeaders(char* self) {
 char buffer[8];if(HttpRequest_InsertHeader(self,HttpRequest_FinalizeConnectionAndLengthHeaders_TextConnection,HttpRequest_FinalizeConnectionAndLengthHeaders_TextClose))return 1;
 unsigned size=strlen(strstr(*(char**)(self+0x19f8),HttpRequest_InsertHeader_Text)+4);
 if(size){Text_FormatBoundedVariadicString(buffer,7,HttpRequestFinalizeConnectionAndLengthHeaders_UnknownRoleInitializedBytes,size);if(HttpRequest_InsertHeader(self,HttpRequest_FinalizeConnectionAndLengthHeaders_TextContentLength,buffer))return 1;}return 0;
}
