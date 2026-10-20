#include <globaldefs.h>
ARM
extern "C" {void KrakPot_GetSelectedIngredientAndStock(unsigned char*,unsigned char*,short*,unsigned char*);void KrakPot_RefreshIngredientPage(void*);void TextCanvas_SetEntryNumericValue(char*,int,int);int TextCanvas_CreateAndConfigureDisplayPart(char*,int);}
// Original: arm9/ov006 @ 0x02159320; symbol: IncrementBoundedSelectionAndUpdateParts; size: 0x90.
// Clamps selected table flag to9, increments bounded selection and updates display parts31 and6.
extern "C" void KrakPot_IncreaseIngredientQuantity(unsigned char* self){unsigned char group,flag;short value;KrakPot_GetSelectedIngredientAndStock(self,&group,&value,&flag);if(flag>9)flag=9;if(flag){unsigned old=self[0x38b];self[0x38b]=old+1;if(flag<self[0x38b])self[0x38b]=flag;if(old!=self[0x38b])self[0x430]=1;}KrakPot_RefreshIngredientPage(self);TextCanvas_SetEntryNumericValue(*(char**)(self+20),31,self[0x38b]);TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self+20),6);}
