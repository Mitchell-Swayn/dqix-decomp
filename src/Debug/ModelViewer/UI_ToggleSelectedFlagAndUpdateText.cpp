#include <globaldefs.h>
ARM
struct RangeState;struct State;
extern "C" int CharacterViewer_GetMenuSelectionIndex(RangeState*);
extern "C" char* DebugMenu_GetEntryByIndex(char*,int);
extern "C" void DebugMenu_SetEntryLabel(State*,const unsigned char*);
extern "C" unsigned char UI_ToggleSelectedFlagAndUpdateText_TextAspect[],UI_ToggleSelectedFlagAndUpdateText_TextAspect_Copy2[],UI_ToggleSelectedFlagAndUpdateText_TextFloor[],UI_ToggleSelectedFlagAndUpdateText_TextMonsterBox[],UI_ToggleSelectedFlagAndUpdateText_TextMonsterBox_Copy2[],UI_ToggleSelectedFlagAndUpdateText_TextSyncMotion[],UI_ToggleSelectedFlagAndUpdateText_TextSyncMotion_Copy2[],UI_ToggleSelectedFlagAndUpdateText_TextViewMemory[],UI_ToggleSelectedFlagAndUpdateText_TextViewMemory_Copy2[];
// Original: arm9/ov015 @ 0x02191F04; symbol: func_ov015_02191f04; size: 0x160.
extern "C" void UI_ToggleSelectedFlagAndUpdateText(unsigned char* p) {
 int selected=CharacterViewer_GetMenuSelectionIndex((RangeState*)(p+0x2c4));
 State* text=(State*)DebugMenu_GetEntryByIndex((char*)p+0x2c4,*(short*)(p+0x324));
 switch(selected) {
 case 0: p[0x19c]=!p[0x19c]; if(p[0x19c]) DebugMenu_SetEntryLabel(text,UI_ToggleSelectedFlagAndUpdateText_TextAspect); else DebugMenu_SetEntryLabel(text,UI_ToggleSelectedFlagAndUpdateText_TextAspect_Copy2); break;
 case 1: p[0x19d]=!p[0x19d]; DebugMenu_SetEntryLabel(text,UI_ToggleSelectedFlagAndUpdateText_TextFloor); break;
 case 2: p[0x19e]=!p[0x19e]; if(p[0x19e]) DebugMenu_SetEntryLabel(text,UI_ToggleSelectedFlagAndUpdateText_TextMonsterBox); else DebugMenu_SetEntryLabel(text,UI_ToggleSelectedFlagAndUpdateText_TextMonsterBox_Copy2); break;
 case 3: p[0x19f]=!p[0x19f]; if(p[0x19f]) DebugMenu_SetEntryLabel(text,UI_ToggleSelectedFlagAndUpdateText_TextSyncMotion); else DebugMenu_SetEntryLabel(text,UI_ToggleSelectedFlagAndUpdateText_TextSyncMotion_Copy2); break;
 case 4: p[0x1a0]=!p[0x1a0]; if(p[0x1a0]) DebugMenu_SetEntryLabel(text,UI_ToggleSelectedFlagAndUpdateText_TextViewMemory); else DebugMenu_SetEntryLabel(text,UI_ToggleSelectedFlagAndUpdateText_TextViewMemory_Copy2); break;
 }
 p[0x350]=1;
}
