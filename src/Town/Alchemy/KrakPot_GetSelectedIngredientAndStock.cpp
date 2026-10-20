#include <globaldefs.h>
ARM
#pragma opt_propagation off
extern "C" short* KrakPot_GetSelectedCategoryItemIds(unsigned char*);
extern "C" unsigned char* KrakPot_GetSelectedCategoryItemQuantities(unsigned char*);
extern "C" void* KrakPot_GetSelectedCategoryItemCount(unsigned char*);
// Original: arm9/ov006 @ 0x02159274; symbol: func_ov006_02159274; size: 0xAC.
extern "C" void KrakPot_GetSelectedIngredientAndStock(unsigned char* self,unsigned char* group,short* value,unsigned char* flag) {
 *group=0; *value=-1; *flag=0;
 if(*(short*)(self+0x364)<0) return;
 short selected=*(short*)(self+0x362)-0x5b;
 short* values=KrakPot_GetSelectedCategoryItemIds(self);
 unsigned char* flags=KrakPot_GetSelectedCategoryItemQuantities(self);
 void* table=KrakPot_GetSelectedCategoryItemCount(self);
 if(!values || !flags || !table) return;
 unsigned char page=self[0x388];
 unsigned short index=*(short*)(self+0x364)-100+(unsigned short)(page<<3);
 *group=selected;
 *value=values[index];
 *flag=flags[index];
}
