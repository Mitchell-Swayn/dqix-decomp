#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov006 @ 0x2160089; symbol: data_ov006_02160089.
// Source-defined character literal. Text: "1". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "1".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
// Original data: arm9/ov006 @ 0x2160092; symbol: data_ov006_02160092.
// Source-defined character literal. Text: "2". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "2".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
struct Params{unsigned char bytes[80];};extern "C" {void ResourceLoader_PollTaskCopyAndRegisterLoadedFile(void*);void Object_InitializeRenderValuesAndUnitScales(void*);char* strcpy(char*,const char*);void ResourceLoader_SpawnRegisteredPresentationOnce(void*,void*);extern char KrakPotStartQueuedAlchemyEffect_Text1[],KrakPotStartQueuedAlchemyEffect_Text2[];}
// Original: arm9/ov006 @ 0x02156D70; symbol: Graphics_InitializeQueuedTypeTwoPresentation; size: 0xe4.
extern "C" void KrakPot_StartQueuedAlchemyEffect(unsigned char* self){ResourceLoader_PollTaskCopyAndRegisterLoadedFile(self+0x12a0);if(self[0x12b4]||!self[0x12bc])return;Params params;Object_InitializeRenderValuesAndUnitScales(&params);params.bytes[17]&=~4;H(params.bytes,18)=0;if(self[0x12bc]==1||self[0x12bc]==2){strcpy((char*)params.bytes,KrakPotStartQueuedAlchemyEffect_Text1);self[0x12bc]=2;}else{strcpy((char*)params.bytes,KrakPotStartQueuedAlchemyEffect_Text2);self[0x12bc]=0;}W(params.bytes,68)=266;W(params.bytes,72)=266;W(params.bytes,76)=266;W(params.bytes,44)=-65;W(params.bytes,48)=-2732;W(params.bytes,52)=17702;ResourceLoader_SpawnRegisteredPresentationOnce(self+0x12a0,&params);}
