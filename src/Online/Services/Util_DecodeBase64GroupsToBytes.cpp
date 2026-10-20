#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define C(p,o) (*(signed char*)((char*)(p)+(o)))
#define V(p,o) (*(char**)((char*)(p)+(o)))
extern "C" int DlcDownload_CopyStringGroupWithZeroPadding(void*,const void*,int);extern "C" int Util_Base64CharacterToIndex(unsigned);
// Original: arm9/ov031 @ 0x0223e54c; symbol: Util_DecodeBase64GroupsToBytes.
extern "C" int Util_DecodeBase64GroupsToBytes(signed char* out,const void* input,int remaining){
unsigned char group[4];signed char decoded[3];int code;int consumed;int total;total=0;const char* source=(const char*)input;consumed=DlcDownload_CopyStringGroupWithZeroPadding(group,source,4);code=0;while(consumed>0&&code>=0){decoded[0]=0;decoded[1]=0;decoded[2]=0;code=Util_Base64CharacterToIndex(group[0]);if(code>=0){decoded[0]=code<<2;code=Util_Base64CharacterToIndex(group[1]);if(code>=0){decoded[0]|=code>>4;decoded[1]=code<<4;code=Util_Base64CharacterToIndex(group[2]);if(code>=0){decoded[1]|=code>>2;decoded[2]=code<<6;code=Util_Base64CharacterToIndex(group[3]);if(code>=0)decoded[2]|=code;}}}int length=consumed-1;int i=0;if(length>0){signed char* copy=decoded;do{*out++=*copy++;++i;}while(i<length);}int written=consumed-1;source+=consumed;total+=written;remaining-=4;if(remaining<=0)break;consumed=DlcDownload_CopyStringGroupWithZeroPadding(group,source,4);}return total;
}
