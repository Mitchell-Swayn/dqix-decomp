// Original data: arm9/ov000 @ 0x218409c; symbol: data_ov000_0218409c.
// Combat target-selection procedure dispatch. Dispatcher021820bc bounds-checks selector0..57, forwards incoming context/action registers and output-array pointer (r3 becomes r2), then returns procedure result/count. Wrappers02181a5c and02181a74 pass the output array to0218177c; that routine stores signed combatant IDs as four-byte ints and returns their count. Context and action layouts remain unresolved; these are opaque pointer types.
// Initial values: hex 5c1a1802741a18028c1a1802a41a1802bc1a180200000000000000004c1d1802681d1802881d1802a41d1802c01d1802dc1d1802f81d1802141e1802301e1802 ...; full span in module reference.
// Observed span: 232 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
#include <globaldefs.h>
// Combat target-selection procedure dispatch. Dispatcher021820bc bounds-checks
// selector0..57, forwards incoming context/action registers and output-array
// pointer (r3 becomes r2), then returns procedure result/count.
// Wrappers02181a5c and02181a74 pass the output array to0218177c; that routine
// stores signed combatant IDs as four-byte ints and returns their count.
// Context and action layouts remain unresolved; these are opaque pointer types.
struct CombatSelectionContext;
struct CombatSelectionAction;
typedef int (*CombatSelectionProc)(CombatSelectionContext*, CombatSelectionAction*, int* output);
extern "C" {
int Combat_CollectPrimarySameSideCombatants(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CollectSecondarySameSideCombatants(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CollectPrimaryRecordOpposingCombatants(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CollectSecondaryRecordOpposingCombatants(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CollectBothSidesForPrimaryRecord(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CollectUniqueSecondaryRecordTargets(CombatSelectionContext*, CombatSelectionAction*, int*);
int Util_CopyLinkedNodeHalfwordsToArray(CombatSelectionContext*, CombatSelectionAction*, int*);
int Util_CopyLinkedListFieldToArray(CombatSelectionContext*, CombatSelectionAction*, int*);
int Ov000_ConvertFourHalfwordsToWords(CombatSelectionContext*, CombatSelectionAction*, int*);
int CopyEnabledIdsToWords(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeOneIndexZero(CombatSelectionContext*, CombatSelectionAction*, int*);
int GameState_ReadLinkedRecordModeOneIndexOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeOneIndexTwo(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeOneIndexThree(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeOneIndexFour(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeOneIndexFive(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeOneIndexSix(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeOneIndexSeven(CombatSelectionContext*, CombatSelectionAction*, int*);
int GameState_ReadLinkedRecordModeZeroIndexZero(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeZeroIndexOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadSecondaryLinkedTargetAtSlotTwo(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeZeroIndexThree(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeZeroIndexFour(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeZeroIndexFive(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeZeroIndexSix(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeZeroIndexSeven(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadLinkedRecordModeTwoIndexZero(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_ReadSecondaryLinkedSelectedValueAtSlotOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CopyIndexedEntryValueIfPresentIndexZero(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CopyIndexedEntryValueIfPresentIndexOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CopyIndexedEntryValueIfPresentIndexTwo(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CopyIndexedEntryValueIfPresentIndexThree(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CopyIndexedEntryValueIfPresentIndexFour(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CopyIndexedEntryValueIfPresentIndexFive(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CopyIndexedEntryValueIfPresentIndexSix(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_CopyIndexedEntryValueIfPresentIndexSeven(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_GetValidLinkedObjectIndexAtSlotZeroKindZero(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_FindLinkedObjectIndexForModeOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_GetValidLinkedObjectIndexAtSlotTwoKindZero(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_GetValidLinkedObjectIndexAtSlotThreeKindZero(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_GetValidLinkedObjectIndexAtSlotZeroKindOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_GetValidLinkedObjectIndexAtSlotOneKindOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_GetValidLinkedObjectIndexAtSlotTwoKindOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_GetValidLinkedObjectIndexAtSlotThreeKindOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int Combat_Write200ToOutputAndReturnSuccess(CombatSelectionContext*, CombatSelectionAction*, int*);
CombatSelectionProc CombatDispatchSelectionProcedure_CombatTargetSelectionProcedureDispatch[58] = {
    Combat_CollectPrimarySameSideCombatants, // selector0
    Combat_CollectSecondarySameSideCombatants, // selector1
    Combat_CollectPrimaryRecordOpposingCombatants, // selector2
    Combat_CollectSecondaryRecordOpposingCombatants, // selector3
    Combat_CollectBothSidesForPrimaryRecord, // selector4
    0, // selector5
    0, // selector6
    Combat_ReadLinkedRecordModeOneIndexZero, // selector7
    GameState_ReadLinkedRecordModeOneIndexOne, // selector8
    Combat_ReadLinkedRecordModeOneIndexTwo, // selector9
    Combat_ReadLinkedRecordModeOneIndexThree, // selector10
    Combat_ReadLinkedRecordModeOneIndexFour, // selector11
    Combat_ReadLinkedRecordModeOneIndexFive, // selector12
    Combat_ReadLinkedRecordModeOneIndexSix, // selector13
    Combat_ReadLinkedRecordModeOneIndexSeven, // selector14
    GameState_ReadLinkedRecordModeZeroIndexZero, // selector15
    Combat_ReadLinkedRecordModeZeroIndexOne, // selector16
    Combat_ReadSecondaryLinkedTargetAtSlotTwo, // selector17
    Combat_ReadLinkedRecordModeZeroIndexThree, // selector18
    Combat_ReadLinkedRecordModeZeroIndexFour, // selector19
    Combat_ReadLinkedRecordModeZeroIndexFive, // selector20
    Combat_ReadLinkedRecordModeZeroIndexSix, // selector21
    Combat_ReadLinkedRecordModeZeroIndexSeven, // selector22
    Util_CopyLinkedNodeHalfwordsToArray, // selector23
    Util_CopyLinkedListFieldToArray, // selector24
    0, // selector25
    Combat_CopyIndexedEntryValueIfPresentIndexZero, // selector26
    Combat_CopyIndexedEntryValueIfPresentIndexOne, // selector27
    Combat_CopyIndexedEntryValueIfPresentIndexTwo, // selector28
    Combat_CopyIndexedEntryValueIfPresentIndexThree, // selector29
    Combat_CopyIndexedEntryValueIfPresentIndexFour, // selector30
    Combat_CopyIndexedEntryValueIfPresentIndexFive, // selector31
    Combat_CopyIndexedEntryValueIfPresentIndexSix, // selector32
    Combat_CopyIndexedEntryValueIfPresentIndexSeven, // selector33
    Combat_GetValidLinkedObjectIndexAtSlotZeroKindZero, // selector34
    Combat_FindLinkedObjectIndexForModeOne, // selector35
    Combat_GetValidLinkedObjectIndexAtSlotTwoKindZero, // selector36
    Combat_GetValidLinkedObjectIndexAtSlotThreeKindZero, // selector37
    Ov000_ConvertFourHalfwordsToWords, // selector38
    CopyEnabledIdsToWords, // selector39
    Combat_Write200ToOutputAndReturnSuccess, // selector40
    0, // selector41
    0, // selector42
    0, // selector43
    0, // selector44
    0, // selector45
    0, // selector46
    0, // selector47
    0, // selector48
    0, // selector49
    Combat_ReadLinkedRecordModeTwoIndexZero, // selector50
    Combat_CollectUniqueSecondaryRecordTargets, // selector51
    Combat_ReadSecondaryLinkedSelectedValueAtSlotOne, // selector52
    Combat_GetValidLinkedObjectIndexAtSlotZeroKindOne, // selector53
    Combat_GetValidLinkedObjectIndexAtSlotOneKindOne, // selector54
    Combat_GetValidLinkedObjectIndexAtSlotTwoKindOne, // selector55
    Combat_GetValidLinkedObjectIndexAtSlotThreeKindOne, // selector56
    0, // selector57
};
}
