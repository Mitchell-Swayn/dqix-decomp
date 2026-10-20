struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
// Original data: arm9/ov012 @ 0x218af88; symbol: data_ov012_0218af88.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0302040205020b0a0c0a.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
extern "C" unsigned char ProfileEditorReturnToParentPage_UnknownRoleInitializedBytes[];
extern "C" WindowCanvasRecord* Window_GetTopTextCanvas(WindowCanvasOwner*);
extern "C" void Window_PopCanvasesAndResetSelection(void*,int);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(void*);
extern "C" void ProfileEditor_RefreshPageText(void*,int,int);
// Original: arm9/ov012 @ 0x0218930C; symbol: ResetSelectionAndConfigureControlsFromLastRecord; size: 0xa8.
extern "C" void ProfileEditor_ReturnToParentPage(char* self,int force) {
 char* record=(char*)Window_GetTopTextCanvas((WindowCanvasOwner*)(self+0xac));
 if(record && !force){for(int i=0;i<5;i++){int value=ProfileEditorReturnToParentPage_UnknownRoleInitializedBytes[i*2];if(value==*(unsigned char*)(record+196)){Window_PopCanvasesAndResetSelection(self+0xac,0);break;}}}
 Window_PopCanvasesAndResetSelection(self+0xac,0);record=(char*)Window_GetTopTextCanvas((WindowCanvasOwner*)(self+0xac));if(!record)return;*(unsigned char*)(self+0x1371)=*(unsigned char*)(record+196);Menu_ConfigurePairedSelectionGridsForActiveCanvas(self);ProfileEditor_RefreshPageText(self,*(unsigned char*)(self+0x1371),0);
}
