#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Flag{char pad[46];unsigned char value:1;};struct Key{unsigned value:4;};extern "C" unsigned TextContext_GetSharedInstance();extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);extern "C" void __clear(void*,unsigned);extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const unsigned char*,unsigned char*,unsigned);extern "C" void Text_InitializeNameDescriptor(void*,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char);extern "C" void* Text_LookupStandardString(unsigned);extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);extern "C" void TextWindow_StartFormattedMessage(int,int,int,int);
// Original: arm9/ov003 @ 0x02170960; symbol: Text_InitializeOptionalPartyNameDescriptorsAndMessage; size 0x11c.
extern "C" void Text_InitializeOptionalPartyNameDescriptorsAndMessage(char* self,int key,unsigned char* input){signed char* owner=(signed char*)TextContext_GetSharedInstance();TextLayout_ResetFormattingWorkspace(owner);unsigned name[3],format[3];unsigned char text[48];__clear(text,48);if(input){Text_MapInputBytesToVariableLengthOutputSequences(input,text,1);Text_InitializeNameDescriptor(name,(unsigned)text,0,0,0,0,0,((struct Flag*)input)->value,0,1,0,1);P(owner,16)=(char*)name;void* resource=Text_LookupStandardString(((struct Key*)((char*)input+12))->value);Text_InitializeNameDescriptor(format,(unsigned)resource,0,0,0,0,0,0,0,0,0,0);P(owner,40)=(char*)format;}void* msg=ResourceStringTable_GetTextByKey(P(self,0xd8),(void*)(int)(short)key);TextWindow_StartFormattedMessage((int)owner,(int)msg,0,227);B(owner,0x19b2)=1;W(owner,0x99c)=2;}
