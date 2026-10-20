#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))

#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct Counts{char pad[10];unsigned short first:4,second:4,third:4,rest:4;};
// Original: arm9/ov006 @ 0x02153A78; symbol: Resource_TestThreePackedIngredientRequirements; size: 0x124.
extern "C" int KrakPot_HasIngredientsForBatch(char* self,int count){char* record=P(self,16);if(!record)return 0;if(H(record,4)>0){unsigned nibble=((Counts*)record)->first;if(nibble){int index=H(self,20);if(index<0)return 0;int group=S(self,26);if(group<0)return 0;int needed=(int)nibble*count;if(needed>B(P(P(self,8),group*4),index))return 0;}}if(H(record,6)>0){unsigned nibble=((Counts*)record)->second;if(nibble){int index=H(self,22);if(index<0)return 0;int group=S(self,27);if(group<0)return 0;int needed=(int)nibble*count;if(needed>B(P(P(self,8),group*4),index))return 0;}}if(H(record,8)>0){unsigned nibble=((Counts*)record)->third;if(nibble){int index=H(self,24);if(index<0)return 0;int group=S(self,28);if(group<0)return 0;int needed=(int)nibble*count;if(needed>B(P(P(self,8),group*4),index))return 0;}}return 1;}
