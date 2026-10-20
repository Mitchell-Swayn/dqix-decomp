#include <globaldefs.h>
ARM
struct GameResources;
extern "C" GameResources* GameResources_GetInstance();
extern "C" unsigned GameResources_GetAlternateWaAttachment(void*);
extern "C" void* GameResources_GetAlternateWingAttachment(void*);
extern "C" void Graphics_DrawObjectWithBoneAttachments(unsigned char*,void**);
struct Model {unsigned char bytes[0xc20];};
struct Owner {char pad[0x20];Model models[2];char gap[4];unsigned char selected:1,other:7;};
// Original: arm9/ov023 @ 0x021FCD70; symbol: func_ov023_021fcd70; size: 0x64.
// Draws the selected embedded model with two resource attachment pointers, or two null attachments.
extern "C" void Graphics_DrawSelectedModelWithResourceAttachments(Owner* self){
 void* attached[2];GameResources* resources=GameResources_GetInstance();
 if(!resources){attached[1]=0;attached[0]=0;}
 else {attached[1]=(void*)GameResources_GetAlternateWaAttachment(resources);attached[0]=GameResources_GetAlternateWingAttachment(resources);}
 Graphics_DrawObjectWithBoneAttachments(self->models[self->selected].bytes,attached);
}
