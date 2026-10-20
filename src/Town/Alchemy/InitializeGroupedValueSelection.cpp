#include <globaldefs.h>
ARM
extern "C" {
int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
void TextCanvas_ShowDisplayPart(unsigned char*,int);
void TextCanvas_SetDisplayPartRefreshFlag(void*,int,int);
void KeyRepeater_Reset(unsigned char*);
void KrakPot_ConfigureIngredientPickerHitRegions(void*);
unsigned KrakPot_GetSelectedCategoryItemCount(void*);
void KrakPot_RefreshIngredientPage(unsigned char*);
void KrakPot_RefreshSelectedIngredientPreview(char*);
}
#define H(o) (*(short*)(self+(o)))
#define U(o) (*(unsigned short*)(self+(o)))
// Original: arm9/ov006 @ 0x0215943C; symbol: func_ov006_0215943c; size: 0xE0.
// Resets value selection, derives page availability and selects the first eligible display record.
extern "C" void InitializeGroupedValueSelection(unsigned char* self) {
 TextCanvas_ShowDisplayPart(*(unsigned char**)(self+0x14),0);
 U(0x394)|=0x10;H(0x370)=-1;self[0x38b]=0;
 KrakPot_ConfigureIngredientPickerHitRegions(self+0x100);
 unsigned total=KrakPot_GetSelectedCategoryItemCount(self);
 U(0x394)&=~4;if(total>8) U(0x394)|=4;
 H(0x36e)=0x11;H(0x364)=-1;
 if(*(volatile short*)(self+0x364)<0) H(0x364)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(*(unsigned char**)(self+0x14),H(0x36e));
 *(short*)(*(unsigned char**)(self+0x14)+0x36)=H(0x364);
 KrakPot_RefreshIngredientPage(self);KrakPot_RefreshSelectedIngredientPreview((char*)self);
 KeyRepeater_Reset(self+0x9c);
 *(void**)(self+0x44)=0;
 TextCanvas_SetDisplayPartRefreshFlag(*(void**)(self+0x14),H(0x36e),0);
}
