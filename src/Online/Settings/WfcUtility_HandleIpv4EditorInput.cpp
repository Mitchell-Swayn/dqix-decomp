#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
#pragma force_active on

struct Ipv4Editor {
    void *canvas; unsigned *spriteControl; unsigned char digits[12]; unsigned char selected,result;
};
extern "C" {
// Original data: arm9/ov031 @ 0x02290C98; allocated IPv4 editor state.
extern Ipv4Editor* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
unsigned WfcNumberPad_GetInputCode(); void Ov031_SetCurrentObjectByte66(unsigned char); void WfcNumberPad_SetDigitEntryEnabled(unsigned char); void WfcNumberPad_SetAdvanceFieldEnabled(int);
void WfcUtility_PlaySequenceArchiveEntry(unsigned); void VectorizedMemset(void*,int,unsigned);
void WfcUtility_SetMainLoopCallback(void(*)()); void System_QueueTimedCallbackAndSetContextHandler();
int WfcUtility_ValidateIpv4EditorValue(); int Util_TestSelectedThreeDigitValueAtLeast(int);
void WfcUtility_DrawIpv4EditorDigits(); void WfcUtility_PositionIpv4EditorCursor(); void WfcUtility_NormalizeIpv4EditorLeadingZeros();
}
#define EDITOR WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage

// Original: arm9/ov031 @ 0x0222DA60; symbol: func_ov031_0222da60; size: 0x310.
// Handles IPv4 digit insertion, group navigation, cancellation and validation, then refreshes the editor.
extern "C" void WfcUtility_HandleIpv4EditorInput()
{
    int key=WfcNumberPad_GetInputCode();
    switch (key) {
    case 0: return;
    case 16:
        if (!EDITOR->selected && !EDITOR->digits[2]) break;
        WfcUtility_PlaySequenceArchiveEntry(3);
        if (!EDITOR->digits[EDITOR->selected*3+2]) --EDITOR->selected;
        VectorizedMemset(EDITOR->digits+EDITOR->selected*3,0,3);
        if (!EDITOR->selected && !EDITOR->digits[2]) Ov031_SetCurrentObjectByte66(0);
        WfcNumberPad_SetDigitEntryEnabled(1); WfcNumberPad_SetAdvanceFieldEnabled(0); break;
    case 17:
        if (EDITOR->selected>=3 || !EDITOR->digits[EDITOR->selected*3+2]) break;
        WfcUtility_PlaySequenceArchiveEntry(1); ++EDITOR->selected; WfcNumberPad_SetAdvanceFieldEnabled(0); break;
    case 18:
        EDITOR->result=0; WfcUtility_PlaySequenceArchiveEntry(7); WfcUtility_SetMainLoopCallback(System_QueueTimedCallbackAndSetContextHandler); return;
    case 19:
        if (WfcUtility_ValidateIpv4EditorValue()) {WfcUtility_PlaySequenceArchiveEntry(6);EDITOR->result=1;}
        else {EDITOR->result=2;WfcUtility_PlaySequenceArchiveEntry(9);}
        EDITOR->selected=3;
        *EDITOR->spriteControl=(*EDITOR->spriteControl&0xc1fffcff)|0x200;
        WfcUtility_PositionIpv4EditorCursor(); WfcUtility_NormalizeIpv4EditorLeadingZeros(); WfcUtility_SetMainLoopCallback(System_QueueTimedCallbackAndSetContextHandler); return;
    default: {
        if (EDITOR->selected==3 && Util_TestSelectedThreeDigitValueAtLeast(26)) break;
        WfcUtility_PlaySequenceArchiveEntry(1);
        unsigned char *digits=EDITOR->digits;
        int offset=EDITOR->selected*3;
        if (!digits[offset+2]) digits[offset+2]=key;
        else if (!digits[offset+1]) {
            digits[offset+1]=digits[offset+2]; digits[offset+2]=key;
            if (Util_TestSelectedThreeDigitValueAtLeast(26) && EDITOR->selected<3) ++EDITOR->selected;
        } else {
            digits[offset]=digits[offset+1]; digits[offset+1]=digits[offset+2]; digits[offset+2]=key;
            if (EDITOR->selected<3) ++EDITOR->selected;
        }
        Ov031_SetCurrentObjectByte66(1);
        if (EDITOR->selected<3) WfcNumberPad_SetAdvanceFieldEnabled(1); else WfcNumberPad_SetAdvanceFieldEnabled(0);
        if (EDITOR->selected==3 && Util_TestSelectedThreeDigitValueAtLeast(26)) WfcNumberPad_SetDigitEntryEnabled(0);
        break;
    }
    }
    WfcUtility_DrawIpv4EditorDigits(); WfcUtility_PositionIpv4EditorCursor();
}
#pragma force_active reset
