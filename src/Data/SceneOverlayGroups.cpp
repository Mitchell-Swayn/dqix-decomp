#include "System/SceneOverlays.h"
// USA scene IDs map to six mutually exclusive overlay residency slots.
extern "C" {
extern char ProgramData_TextBattle[];
extern char ProgramData_TextEvent_Copy2[];
extern char ProgramData_TextTopmenu[];
extern char ProgramData_TextShisetsu[];
extern char ProgramData_TextMenucallback[];
extern char ProgramData_TextEquipmenu[];
extern char ProgramData_TextRenkin_Copy2[];
extern char ProgramData_TextDebug[];
extern char ProgramData_TextJourecode[];
extern char ProgramData_TextCharamake2[];
extern char ProgramData_TextPitfall[];
extern char ProgramData_TextMenusys[];
extern char ProgramData_TextProf[];
extern char ProgramData_TextSkillup[];
extern char ProgramData_TextSubjugation[];
extern char ProgramData_TextCharaview[];
extern char ProgramData_TextMovieview[];
extern char ProgramData_TextGamemain[];
extern char ProgramData_TextMapjump[];
extern char ProgramData_TextReaderror[];
extern char ProgramData_TextTitle_Copy2[];
extern char ProgramData_TextCharamake[];
extern char ProgramData_TextSubDebug[];
extern char ProgramData_TextSubMenu[];
extern char ProgramData_TextSubBattle[];
extern char ProgramData_TextSubRound[];
extern char ProgramData_TextSubCommand[];
extern char ProgramData_TextSubStaffroll[];
extern char ProgramData_TextSubHoge[];
extern char ProgramData_TextSubMakescn[];
extern char ProgramData_TextSubLibmb[];
extern char ProgramData_TextWifi[];
extern char ProgramData_TextSound_Copy2[];
extern char ProgramData_TextBgload1[];
extern char ProgramData_TextBgload2[];
}
// Original data: arm9/main @ 0x20e8f20; symbol: data_020e8f20.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 0000000069190f020000000050190f02000000008e190f0200000000c8190f02000000006e1a0f0200000000021a0f020000000070190f02010000004a190f02 ...; full span in module reference.
// Observed span: 280 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const SceneEntry IsSceneLoaded_UnknownRoleDataReferences[35] = {
    {0, ProgramData_TextBattle},
    {0, ProgramData_TextEvent_Copy2},
    {0, ProgramData_TextTopmenu},
    {0, ProgramData_TextShisetsu},
    {0, ProgramData_TextMenucallback},
    {0, ProgramData_TextEquipmenu},
    {0, ProgramData_TextRenkin_Copy2},
    {1, ProgramData_TextDebug},
    {1, ProgramData_TextJourecode},
    {1, ProgramData_TextCharamake2},
    {1, ProgramData_TextPitfall},
    {1, ProgramData_TextMenusys},
    {1, ProgramData_TextProf},
    {1, ProgramData_TextSkillup},
    {1, ProgramData_TextSubjugation},
    {2, ProgramData_TextCharaview},
    {2, ProgramData_TextMovieview},
    {2, ProgramData_TextGamemain},
    {2, ProgramData_TextMapjump},
    {2, ProgramData_TextReaderror},
    {2, ProgramData_TextTitle_Copy2},
    {2, ProgramData_TextCharamake},
    {3, ProgramData_TextSubDebug},
    {3, ProgramData_TextSubMenu},
    {3, ProgramData_TextSubBattle},
    {3, ProgramData_TextSubRound},
    {3, ProgramData_TextSubCommand},
    {3, ProgramData_TextSubStaffroll},
    {3, ProgramData_TextSubHoge},
    {3, ProgramData_TextSubMakescn},
    {3, ProgramData_TextSubLibmb},
    {4, ProgramData_TextWifi},
    {4, ProgramData_TextSound_Copy2},
    {5, ProgramData_TextBgload1},
    {5, ProgramData_TextBgload2},
};
