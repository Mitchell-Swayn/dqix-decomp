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
int Util_CallTargetWithFlagsOne(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181a74(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181a8c(CombatSelectionContext*, CombatSelectionAction*, int*);
int Unclassified_InvokeHelperWithZeroFlags(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181abc(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181b4c(CombatSelectionContext*, CombatSelectionAction*, int*);
int Util_CopyLinkedNodeHalfwordsToArray(CombatSelectionContext*, CombatSelectionAction*, int*);
int Util_CopyLinkedListFieldToArray(CombatSelectionContext*, CombatSelectionAction*, int*);
int Ov000_ConvertFourHalfwordsToWords(CombatSelectionContext*, CombatSelectionAction*, int*);
int CopyEnabledIdsToWords(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181d4c(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181d68(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181d88(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181da4(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181dc0(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181ddc(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181df8(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181e14(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181e30(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181e50(CombatSelectionContext*, CombatSelectionAction*, int*);
int Ov000_ForwardSecondAndThirdWithMode0Index2(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181e88(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181ea4(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181ec0(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181edc(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181ef8(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181f14(CombatSelectionContext*, CombatSelectionAction*, int*);
int Ov000_ForwardSecondAndThirdWithMode2Index1(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181f4c(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181f60(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181f74(CombatSelectionContext*, CombatSelectionAction*, int*);
int Ov000_ForwardThirdArgWithMode3(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181f9c(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181fb0(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181fc4(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02181fd8(CombatSelectionContext*, CombatSelectionAction*, int*);
int Ov000_ForwardSecondThirdWithZeroes(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02182004(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_0218201c(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02182034(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_0218204c(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_02182064(CombatSelectionContext*, CombatSelectionAction*, int*);
int Ov000_ForwardSecondThirdWithMode2Flag1(CombatSelectionContext*, CombatSelectionAction*, int*);
int Ov000_ForwardSecondThirdWithMode3Flag1(CombatSelectionContext*, CombatSelectionAction*, int*);
int func_ov000_021820ac(CombatSelectionContext*, CombatSelectionAction*, int*);
CombatSelectionProc data_ov000_0218409c[58] = {
    Util_CallTargetWithFlagsOne, // selector0
    func_ov000_02181a74, // selector1
    func_ov000_02181a8c, // selector2
    Unclassified_InvokeHelperWithZeroFlags, // selector3
    func_ov000_02181abc, // selector4
    0, // selector5
    0, // selector6
    func_ov000_02181d4c, // selector7
    func_ov000_02181d68, // selector8
    func_ov000_02181d88, // selector9
    func_ov000_02181da4, // selector10
    func_ov000_02181dc0, // selector11
    func_ov000_02181ddc, // selector12
    func_ov000_02181df8, // selector13
    func_ov000_02181e14, // selector14
    func_ov000_02181e30, // selector15
    func_ov000_02181e50, // selector16
    Ov000_ForwardSecondAndThirdWithMode0Index2, // selector17
    func_ov000_02181e88, // selector18
    func_ov000_02181ea4, // selector19
    func_ov000_02181ec0, // selector20
    func_ov000_02181edc, // selector21
    func_ov000_02181ef8, // selector22
    Util_CopyLinkedNodeHalfwordsToArray, // selector23
    Util_CopyLinkedListFieldToArray, // selector24
    0, // selector25
    func_ov000_02181f4c, // selector26
    func_ov000_02181f60, // selector27
    func_ov000_02181f74, // selector28
    Ov000_ForwardThirdArgWithMode3, // selector29
    func_ov000_02181f9c, // selector30
    func_ov000_02181fb0, // selector31
    func_ov000_02181fc4, // selector32
    func_ov000_02181fd8, // selector33
    Ov000_ForwardSecondThirdWithZeroes, // selector34
    func_ov000_02182004, // selector35
    func_ov000_0218201c, // selector36
    func_ov000_02182034, // selector37
    Ov000_ConvertFourHalfwordsToWords, // selector38
    CopyEnabledIdsToWords, // selector39
    func_ov000_021820ac, // selector40
    0, // selector41
    0, // selector42
    0, // selector43
    0, // selector44
    0, // selector45
    0, // selector46
    0, // selector47
    0, // selector48
    0, // selector49
    func_ov000_02181f14, // selector50
    func_ov000_02181b4c, // selector51
    Ov000_ForwardSecondAndThirdWithMode2Index1, // selector52
    func_ov000_0218204c, // selector53
    func_ov000_02182064, // selector54
    Ov000_ForwardSecondThirdWithMode2Flag1, // selector55
    Ov000_ForwardSecondThirdWithMode3Flag1, // selector56
    0, // selector57
};
}
