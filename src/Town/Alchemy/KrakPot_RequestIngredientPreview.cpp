#include <globaldefs.h>
ARM
extern "C" {void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void ItemDetail_QueueQuantityModeArchive(void*,int);}
// Original: arm9/ov006 @ 0x02155710; symbol: CancelTwoTasksAndConfigureSelection; size: 0xb0.
// Cancels two pending background tasks, configures selection and resets load flags.
extern "C" void KrakPot_RequestIngredientPreview(char* self,unsigned short selection,unsigned char mode){void* loader=_ZN16BackgroundLoader11GetInstanceEv();if(*(int*)(self+0xad4)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xad4));*(int*)(self+0xad4)=-1;}*(int*)(self+0xad4)=-1;self[0xade]=0;*(unsigned short*)(self+0xae2)|=2;ItemDetail_QueueQuantityModeArchive(self+0xae4,2);*(unsigned short*)(self+0x12b8)=selection;self[0x12ba]=mode;*(unsigned short*)(self+0xae2)&=~1;if(*(int*)(self+0xad8)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xad8));*(int*)(self+0xad8)=-1;}*(int*)(self+0xad8)=-1;self[0xadf]=0;}
