#include <globaldefs.h>
#pragma force_active on
ARM
struct State;
struct Object;
extern "C" {
void* Script_ReadGlobalExecutionValue();
void TimedMessageQueue_CancelAndClear(State*);
unsigned TextContext_GetSharedInstance();
void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
void TextLayout_InitializeSelectionPanel(unsigned char*);
void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
void Grid_SetEntryCountAndClampSelection(int*,int);
void* Text_LookupStandardString(unsigned);
void TextLayout_AppendConvertedLineAndUpdateWidths(char*,void*);
void TextLayout_ComputeSelectionPanelBounds(Object*,int,short);
void TextLayout_ResetPanelControlCountersAndSetMode(unsigned char*,unsigned char);
void TextLayout_StartPanelOpening(char*);
}
// Original: arm9/ov017 @ 0x021ADB50; symbol: func_ov017_021adb50; size: 0xE0.
// Creates the single-entry standard-message panel used by a party effect request.
extern "C" void FieldPartyEffect_OpenStandardMessagePanel(unsigned char* request)
{
    TimedMessageQueue_CancelAndClear((State*)Script_ReadGlobalExecutionValue());
    TextWindow_ResetGlyphBuffersAndFrameContexts((void*)TextContext_GetSharedInstance());
    TextLayout_InitializeSelectionPanel(request+0x44);
    Grid_SetOrientationAndCoordinatePointers(request+0x64,1,1,0);
    Grid_SetOrientationAndCoordinatePointers(request+0xb4,1,1,0);
    Grid_SetEntryCountAndClampSelection((int*)(request+0x64),1);
    Grid_SetEntryCountAndClampSelection((int*)(request+0xb4),1);
    TextLayout_AppendConvertedLineAndUpdateWidths((char*)request+0x44,Text_LookupStandardString(31));
    *(short*)(request+0xf8)=8;
    *(short*)(request+0xfa)=64;
    TextLayout_ComputeSelectionPanelBounds((Object*)(request+0x44),0,-4);
    request[0x278]=1;
    TextLayout_ResetPanelControlCountersAndSetMode(request+0x48,1);
    request[0x277]=1;
    request[0x278]=1;
    TextLayout_ResetPanelControlCountersAndSetMode(request+0x48,1);
    *(short*)(request+0xf8)=(256-*(short*)(request+0xfc))/2;
    *(short*)(request+0xfa)=64;
    TextLayout_StartPanelOpening((char*)request+0x44);
}
