#include <globaldefs.h>
ARM
extern "C" {
void TextCanvas_SetEntryNumericValue(char*,int,int);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
char* KrakPot_FindLayoutHitRegion(void*,int);
void KrakPot_RefreshIngredientPage(unsigned char*);
}
// Original: arm9/ov006 @ 0x021596F0; symbol: func_ov006_021596f0; size: 0x144.
// Enables quantity selection input and configures display part six.
extern "C" void ConfigureQuantitySelectionInputAndPart(unsigned char* self) {
 unsigned char* entry;
 entry=(unsigned char*)KrakPot_FindLayoutHitRegion(self+0x100,80);
 if(entry) entry[0x16]|=1;
 entry=(unsigned char*)KrakPot_FindLayoutHitRegion(self+0x100,79);
 if(entry) entry[0x16]&=~1;
 entry=(unsigned char*)KrakPot_FindLayoutHitRegion(self+0x100,14);
 if(entry) entry[0x16]&=~1;
 entry=(unsigned char*)KrakPot_FindLayoutHitRegion(self+0x100,15);
 if(entry) entry[0x16]&=~1;
 entry=(unsigned char*)KrakPot_FindLayoutHitRegion(self+0x100,21);
 if(entry) entry[0x16]&=~1;
 entry=(unsigned char*)KrakPot_FindLayoutHitRegion(self+0x100,31);
 if(entry) entry[0x16]&=~1;
 entry=(unsigned char*)KrakPot_FindLayoutHitRegion(self+0x100,32);
 if(entry) entry[0x16]&=~1;
 entry=(unsigned char*)KrakPot_FindLayoutHitRegion(self+0x100,33);
 if(entry) entry[0x16]&=~1;
 entry=(unsigned char*)KrakPot_FindLayoutHitRegion(self+0x100,34);
 if(entry) entry[0x16]&=~1;
 KrakPot_RefreshIngredientPage(self);
 *(unsigned short*)(self+0x394)|=8;*(short*)(self+0x36e)=6;
 TextCanvas_SetEntryNumericValue(*(char**)(self+0x14),0x1f,self[0x38b]);
 TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self+0x14),6);
}
