#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct HighTwoBits{unsigned char low:6,high:2;};
extern "C" unsigned Text_FormatBoundedVariadicString(...);
extern "C" unsigned GrowBufferAndPreserveCursor(...);
extern "C" unsigned char HttpRequest_InsertHeader_Text[];
extern "C" unsigned char HttpRequest_InsertHeader_FormatSS[];
// Original: arm9/ov031 @ 0x02218528; symbol: InsertFormattedHeaderIntoGrowableBuffer.
extern "C" int HttpRequest_InsertHeader(char* owner,const char* name,const char* value){char* buffer=owner+0x19f8;int length=strlen(value);int formatLength=strlen((const char*)HttpRequest_InsertHeader_FormatSS);int nameLength=strlen(name);length+=formatLength-4+nameLength;int available=U(buffer,8)-U(buffer,4);if(length+1>available){if(!GrowBufferAndPreserveCursor(owner,buffer,length-available+1))return 1;}char* found=strstr((const char*)U(buffer,0),(const char*)HttpRequest_InsertHeader_Text);char saved=found[2];char* insertion=found+2;memmove(insertion+length,insertion,strlen(insertion)+1);int written=Text_FormatBoundedVariadicString(insertion,length+1,HttpRequest_InsertHeader_FormatSS,name,value);insertion[written]=saved;U(buffer,4)+=length;return 0;}
