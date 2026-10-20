#include <globaldefs.h>
ARM
extern "C" char* strstr(...);
extern "C" void strcpy(...);
extern "C" unsigned strlen(const char*);
extern "C" char Filesystem_SplitMatchedPathPrefixAndSuffix_TextCharaP[],Filesystem_SplitMatchedPathPrefixAndSuffix_TextCharaP_Copy2[],Filesystem_SplitMatchedPathPrefixAndSuffix_TextChara[],Combat_LoadActorActionReplacementModel_PathDataPackLv5CharaPcGp2[],Filesystem_SplitMatchedPathPrefixAndSuffix_TextCharaMp[],Filesystem_SplitMatchedPathPrefixAndSuffix_TextCharaMp_Copy2[],Filesystem_SplitMatchedPathPrefixAndSuffix_PathDataPackLv5CharaMpGp2[];
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};
// Original: arm9/ov025 @ 0x021E24D0; symbol: Filesystem_SplitMatchedPathPrefixAndSuffix; size: 0xd4.
// Splits paths at either primary marker into prefix and suffix; fallback searches are called but their result is unused.
extern "C" bool Filesystem_SplitMatchedPathPrefixAndSuffix(char* input,char* prefix,char* suffix){char* found=strstr(input,Filesystem_SplitMatchedPathPrefixAndSuffix_TextCharaP);if(!found)strstr(input,Filesystem_SplitMatchedPathPrefixAndSuffix_TextCharaP_Copy2);if(found){strcpy(suffix,found+strlen(Filesystem_SplitMatchedPathPrefixAndSuffix_TextChara));strcpy(prefix,Combat_LoadActorActionReplacementModel_PathDataPackLv5CharaPcGp2);return true;}found=strstr(input,Filesystem_SplitMatchedPathPrefixAndSuffix_TextCharaMp);if(!found)strstr(input,Filesystem_SplitMatchedPathPrefixAndSuffix_TextCharaMp_Copy2);if(!found)return false;strcpy(suffix,found+strlen(Filesystem_SplitMatchedPathPrefixAndSuffix_TextChara));strcpy(prefix,Filesystem_SplitMatchedPathPrefixAndSuffix_PathDataPackLv5CharaMpGp2);return true;}
