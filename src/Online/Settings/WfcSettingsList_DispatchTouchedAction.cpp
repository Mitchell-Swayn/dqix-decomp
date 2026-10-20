#include <globaldefs.h>
ARM
extern "C" unsigned WfcSettingsList_HitTestAction(void*);
extern "C" int WfcSettingsList_IsActionEnabled(unsigned);
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcSettingsList_SelectActionAndHighlight(unsigned);
extern "C" void WfcSettingsList_StartSelectedOptionFlash();
extern "C" void WfcSettingsList_ActivateAction(unsigned);
// Original: arm9/ov031 @ 0x0222F188; symbol: ResolveSelectedActionAndDispatchSpecialCases; size: 0x84.
extern "C" char* WfcUtility_GetEditableConnectionProfile();
extern "C" int WfcSettingsList_DispatchTouchedAction() {
 unsigned action=WfcSettingsList_HitTestAction(WfcUtility_GetEditableConnectionProfile());
 if(action==14)return 0;
 if(!WfcSettingsList_IsActionEnabled(action)){WfcUtility_PlaySequenceArchiveEntry(9);return 1;}
 WfcSettingsList_SelectActionAndHighlight(action);
 switch(action){case 2:case 3:case 7:case 8:WfcSettingsList_StartSelectedOptionFlash();break;}
 WfcSettingsList_ActivateAction(action);return 1;
}
