#include <globaldefs.h>
ARM
extern "C" void KrakPot_GetSelectedIngredientAndStock(unsigned char*,unsigned char*,short*,unsigned char*);
extern "C" void KrakPot_RefreshIngredientPage(unsigned char*);
extern "C" void TextCanvas_SetEntryNumericValue(char*,int,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
// Original: arm9/ov006 @ 0x021593B0; symbol: DecrementSelectionUnlessAtOneAndRefreshParts; size: 0x8c.
extern "C" void KrakPot_DecreaseIngredientQuantity(unsigned char* self){
unsigned char group,flag;short value;KrakPot_GetSelectedIngredientAndStock(self,&group,&value,&flag);if(flag>9)flag=9;if(flag){int previous=self[0x38b];self[0x38b]--;if(!self[0x38b])self[0x38b]=1;if(previous!=self[0x38b])self[0x431]=1;}KrakPot_RefreshIngredientPage(self);TextCanvas_SetEntryNumericValue(*(char**)(self+20),31,self[0x38b]);TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self+20),6);
}
