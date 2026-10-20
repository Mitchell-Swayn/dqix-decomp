#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct CountPrice{unsigned count:7,price:25;};
struct FlagBits{unsigned char a:1,b:1,index:6;};
struct Nibbles{unsigned char low:4,high:4;};
struct SixFlags{unsigned char index:6,a:1,b:1;};
extern "C" unsigned Util_FindRecordWithProportionalTriple(...);
extern "C" unsigned __clear(...);
// Original: arm9/ov006 @ 0x0215fd60; symbol: MergeThreePositiveKeysAndFindProportionalRecord.
extern "C" void* KrakPot_FindRecipeForSelectedIngredients(char* p,short* input,unsigned char* counts,unsigned char* output){short keys[3];unsigned char values[3];__clear(keys,6);__clear(values,3);for(unsigned char i=0;i<3;i++){short key=input[i];if(key<=0)continue;for(unsigned char j=0;j<3;j++){short existing=keys[j];if(key==existing){keys[j]=key;values[j]+=counts[i];break;}if(existing<=0){keys[j]=key;values[j]=counts[i];break;}}}return (void*)Util_FindRecordWithProportionalTriple(p+0x14c,keys,values,output);}
