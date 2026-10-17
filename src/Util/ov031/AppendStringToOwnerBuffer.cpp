#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Buffer {char* start;char* current;char* end;unsigned size;};
extern "C" {extern char data_ov031_02249ee8[];int ForwardVariadicArgumentsFromStack(char*,int,const char*,...);int GrowBufferAndPreserveCursor(void*,Buffer*,int);}
// Original: arm9/ov031 @ 0x02218710; symbol: func_ov031_02218710; size: 0x88.
extern "C" int AppendStringToOwnerBuffer(char* owner,const char* text){
int length;Buffer* buffer=(Buffer*)(owner+0x19f8);
length=strlen(text);int available=buffer->end-buffer->current;
if(length>available){if(!GrowBufferAndPreserveCursor(owner,buffer,length-available+1))return 1;available=buffer->end-buffer->current;}
int written=ForwardVariadicArgumentsFromStack(buffer->current,available,data_ov031_02249ee8,text);
if(written!=length)return 1;
buffer->current+=written;return 0;
}
