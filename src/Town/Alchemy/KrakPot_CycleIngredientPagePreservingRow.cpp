#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" unsigned KrakPot_GetSelectedCategoryItemCount(void*);extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);extern "C" void KrakPot_RefreshIngredientPage(void*);extern "C" void KrakPot_RefreshSelectedIngredientPreview(char*);
// Original: arm9/ov006 @ 0x0215F3D8; symbol: Input_CyclePageAndPreserveClampedSelectionRow; size: 0x104.
extern "C" void KrakPot_CycleIngredientPagePreservingRow(char* self){if(!(U(self,0x394)&4))return;int changed=0;if(W(self,0x350)&16){B(self,0x388)++;changed=1;}else if(W(self,0x350)&32){B(self,0x388)--;changed=1;}if(B(self,0x388)==255)B(self,0x388)=B(self,0x389)-1;if(B(self,0x389)<=B(self,0x388))B(self,0x388)=0;if(!changed)return;int count=KrakPot_GetSelectedCategoryItemCount(self);int base=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear((unsigned char*)P(self,20),17);short offset=H(self,0x364)-base;short selected=offset;selected=(B(self,0x388)<<3)+selected;if(count<=selected)selected=count-1;count=(short)(selected%8);H(self,0x364)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear((unsigned char*)P(self,20),17)+count;KrakPot_RefreshIngredientPage(self);KrakPot_RefreshSelectedIngredientPreview(self);}
