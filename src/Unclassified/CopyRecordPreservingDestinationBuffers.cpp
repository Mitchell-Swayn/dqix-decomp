#include <globaldefs.h>
#include <std_library_functions.h>
struct State {unsigned short unknown;unsigned short count:15;unsigned short flag:1;};struct Record {void* data;char* text;unsigned rest[6];};
// Original: arm9/main @ 0x020DF6CC; symbol: func_020df6cc; size: 0xA8.
extern "C" int CopyRecordPreservingDestinationBuffers(State* self,Record* dest,unsigned ignored,const Record* source) {char* text=dest->text;void* data=dest->data;memcpy(dest,source,32);dest->text=text;dest->data=data;char* sourceText=source->text;if(dest->text){if(!sourceText)dest->text[0]=0;else strcpy(dest->text,sourceText);}if(dest->data && source->data){memcpy(dest->data,source->data,32);++self->count;}return 1;}
