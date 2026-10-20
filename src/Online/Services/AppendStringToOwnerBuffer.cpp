#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Buffer {char* start;char* current;char* end;unsigned size;};
// Original data: arm9/ov031 @ 0x2249ee8; symbol: data_ov031_02249ee8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25730000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern char AppendStringToOwnerBuffer_UnknownRoleInitializedBytes[];int Text_FormatBoundedVariadicString(char*,int,const char*,...);int GrowBufferAndPreserveCursor(void*,Buffer*,int);}
// Original: arm9/ov031 @ 0x02218710; symbol: func_ov031_02218710; size: 0x88.
extern "C" int AppendStringToOwnerBuffer(char* owner,const char* text){
int length;Buffer* buffer=(Buffer*)(owner+0x19f8);
length=strlen(text);int available=buffer->end-buffer->current;
if(length>available){if(!GrowBufferAndPreserveCursor(owner,buffer,length-available+1))return 1;available=buffer->end-buffer->current;}
int written=Text_FormatBoundedVariadicString(buffer->current,available,AppendStringToOwnerBuffer_UnknownRoleInitializedBytes,text);
if(written!=length)return 1;
buffer->current+=written;return 0;
}
