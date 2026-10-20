// func_02068f40 walks 20-byte rules until the null evaluator sentinel.
// Each four-byte sequence indexes the condition-keyword table; -1 ends it.
// Evaluators receive the game state and two opaque context words, returning a branch ID.
extern "C" {
int TestIndexedByteDiffersFromStateValue(void*, unsigned, unsigned);
int GameState_ReadFirstPartyMemberLinkedBitFlag(void*, unsigned, unsigned);
int TextCondition_ReadProtagonistGender(void*, unsigned, unsigned);
int GameState_ReadFirstPartyMemberStoredBit(void*, unsigned, unsigned);
int GameState_ReadUnknownObjectLinkedBitFlag(void*, unsigned, unsigned);
int GameState_TestAnyListedPartyMemberWithClearStatusFlag(void*, unsigned, unsigned);
int TextCondition_TestNonSoloParty(void*, unsigned, unsigned);
int GameState_TestAdditionalNonfilteredPartyMembers(void*, unsigned, unsigned);
int GameState_TestListedQualifyingMemberCountNotOne(void*, unsigned, unsigned);
int TextCondition_TestFirstNumericArgumentNotOne(void*, unsigned, unsigned);
int TextCondition_TestSecondNumericArgumentNotOne(void*, unsigned, unsigned);
int TextCondition_TestElement558DiffersFrom1(void*, unsigned, unsigned);
int TextCondition_TestFourthNumericArgumentNotOne(void*, unsigned, unsigned);
int TextCondition_TestFifthNumericArgumentNotOne(void*, unsigned, unsigned);
int TextCondition_TestItemNamePluralNounFlagClear(void*, unsigned, unsigned);
int TextCondition_TestMonsterNamePluralNounFlagClear(void*, unsigned, unsigned);
int TextCondition_ReadItemNameGrammaticalGender(void*, unsigned, unsigned);
int TextCondition_ReadMonsterNameGrammaticalGender(void*, unsigned, unsigned);
int TextCondition_ReadActionGrammaticalGender(void*, unsigned, unsigned);
int ReadTypeBitsFromOptionalFirstPointer(void*, unsigned, unsigned);
int TextCondition_ReadActorGrammaticalGender(void*, unsigned, unsigned);
int TextCondition_ReadTargetGrammaticalGender(void*, unsigned, unsigned);
int TextCondition_TestTargetPartyFlagClear(void*, unsigned, unsigned);
int TextCondition_TestActorPartyFlagClear(void*, unsigned, unsigned);
int TestPresentUnequalPairValues(void*, unsigned, unsigned);
int TextCondition_TestActorProperNounFlagClear(void*, unsigned, unsigned);
int TextCondition_TestTargetProperNounFlagClear(void*, unsigned, unsigned);
int TextCondition_ReadTargetMixedFlag(void*, unsigned, unsigned);
int TextCondition_TestTargetIsNotMixed(void*, unsigned, unsigned);
int GameState_TestFirstPartyMemberStatsPredicate(void*, unsigned, unsigned);
int TestProtagonistResourceLookupSuccess(void*, unsigned, unsigned);
int GameState_TestUnknownObjectResolvedValueStatusZero(void*, unsigned, unsigned);
int TextCondition_TestItemFrenchVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestSecondItemFrenchVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestMonsterFrenchVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestVocationFrenchVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestActorFrenchVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestTargetFrenchVowelFlagClear(void*, unsigned, unsigned);
int Object_TestWord8B0OutsideZeroOrOne(void*, unsigned, unsigned);
int TextCondition_TestFormatValueTwoIsFrenchPlural(void*, unsigned, unsigned);
int TextCondition_TestFormatValueThreeIsFrenchPlural(void*, unsigned, unsigned);
int Object_TestWord8BCOutsideZeroOrOne(void*, unsigned, unsigned);
int TextCondition_TestFormatValueFiveIsFrenchPlural(void*, unsigned, unsigned);
int GameState_TestProtagonistResolvedValueStatusZero(void*, unsigned, unsigned);
int GameState_TestCurrentObjectValuePredicate(void*, unsigned, unsigned);
int TextCondition_TestItemVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestMonsterVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestVocationVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestActorVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestTargetVowelFlagClear(void*, unsigned, unsigned);
int TextCondition_TestItemHasNoGermanSpecialEnding(void*, unsigned, unsigned);
int TextCondition_TestMonsterHasNoGermanSpecialEnding(void*, unsigned, unsigned);
int TextCondition_TestActorHasNoGermanSpecialEnding(void*, unsigned, unsigned);
int TextCondition_TestTargetHasNoGermanSpecialEnding(void*, unsigned, unsigned);
}
typedef int (*TextConditionEvaluator)(void*, unsigned, unsigned);
struct TextConditionRule { signed char tags[4][4]; TextConditionEvaluator evaluate; };
// Original data: arm9/main @ 0x20e833c; symbol: data_020e833c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 112cffff031b2cffffffffff042cffff2c850602110d15ff030d1b15ffffffff040d15ff58850602113015ff03301b15ffffffff043015ff80850602110c15ff ...; full span in module reference.
// Observed span: 1144 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const TextConditionRule TextMarkupExpandConditionalBranches_UnknownRoleProcedureReferenceRecords[57] = {
    {{{17, 44, -1, -1}, {3, 27, 44, -1}, {-1, -1, -1, -1}, {4, 44, -1, -1}}, TestIndexedByteDiffersFromStateValue},
    {{{17, 13, 21, -1}, {3, 13, 27, 21}, {-1, -1, -1, -1}, {4, 13, 21, -1}}, GameState_ReadFirstPartyMemberLinkedBitFlag},
    {{{17, 48, 21, -1}, {3, 48, 27, 21}, {-1, -1, -1, -1}, {4, 48, 21, -1}}, TextCondition_ReadProtagonistGender},
    {{{17, 12, 21, -1}, {3, 12, 27, 21}, {-1, -1, -1, -1}, {4, 12, 21, -1}}, GameState_ReadFirstPartyMemberStoredBit},
    {{{17, 21, -1, -1}, {3, 27, 21, -1}, {-1, -1, -1, -1}, {4, 21, -1, -1}}, GameState_ReadUnknownObjectLinkedBitFlag},
    {{{17, 6, 28, -1}, {3, 27, 6, 28}, {-1, -1, -1, -1}, {4, 6, 28, -1}}, GameState_TestAnyListedPartyMemberWithClearStatusFlag},
    {{{17, 43, -1, -1}, {3, 27, 43, -1}, {-1, -1, -1, -1}, {4, 43, -1, -1}}, TextCondition_TestNonSoloParty},
    {{{17, 50, -1, -1}, {3, 27, 50, -1}, {-1, -1, -1, -1}, {4, 50, -1, -1}}, GameState_TestAdditionalNonfilteredPartyMembers},
    {{{17, 49, -1, -1}, {3, 27, 49, -1}, {-1, -1, -1, -1}, {4, 49, -1, -1}}, GameState_TestListedQualifyingMemberCountNotOne},
    {{{17, 38, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, TextCondition_TestFirstNumericArgumentNotOne},
    {{{17, 39, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, TextCondition_TestSecondNumericArgumentNotOne},
    {{{17, 40, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, TextCondition_TestElement558DiffersFrom1},
    {{{17, 41, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, TextCondition_TestFourthNumericArgumentNotOne},
    {{{17, 42, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, TextCondition_TestFifthNumericArgumentNotOne},
    {{{17, 14, 25, 30}, {3, 27, 30, -1}, {-1, -1, -1, -1}, {4, 30, -1, -1}}, TextCondition_TestItemNamePluralNounFlagClear},
    {{{17, 14, 26, 30}, {3, 27, 30, -1}, {-1, -1, -1, -1}, {4, 30, -1, -1}}, TextCondition_TestItemNamePluralNounFlagClear},
    {{{17, 20, 25, 30}, {3, 27, 30, -1}, {-1, -1, -1, -1}, {4, 30, -1, -1}}, TextCondition_TestMonsterNamePluralNounFlagClear},
    {{{17, 14, 25, 20}, {17, 14, 25, 5}, {17, 14, 25, 24}, {4, 14, 25, 22}}, TextCondition_ReadItemNameGrammaticalGender},
    {{{17, 20, 25, 20}, {17, 20, 25, 5}, {17, 20, 25, 24}, {4, 20, 25, 22}}, TextCondition_ReadMonsterNameGrammaticalGender},
    {{{17, 0, 20, -1}, {17, 0, 5, -1}, {17, 0, 24, -1}, {4, 0, -1, -1}}, TextCondition_ReadActionGrammaticalGender},
    {{{17, 1, 21, -1}, {3, 1, 27, 21}, {-1, -1, -1, -1}, {4, 1, 21, -1}}, ReadTypeBitsFromOptionalFirstPointer},
    {{{17, 1, 20, -1}, {17, 1, 5, -1}, {17, 1, 24, -1}, {4, 1, 22, -1}}, TextCondition_ReadActorGrammaticalGender},
    {{{17, 45, 20, -1}, {17, 45, 5, -1}, {17, 45, 24, -1}, {4, 45, 22, -1}}, TextCondition_ReadTargetGrammaticalGender},
    {{{17, 45, 28, -1}, {3, 45, 27, 28}, {-1, -1, -1, -1}, {4, 45, 28, -1}}, TextCondition_TestTargetPartyFlagClear},
    {{{17, 1, 28, -1}, {3, 1, 27, 28}, {-1, -1, -1, -1}, {4, 1, 28, -1}}, TextCondition_TestActorPartyFlagClear},
    {{{17, 1, 45, -1}, {3, 1, 27, 45}, {-1, -1, -1, -1}, {4, 1, 45, -1}}, TestPresentUnequalPairValues},
    {{{17, 1, 31, -1}, {3, 1, 27, 31}, {-1, -1, -1, -1}, {4, 1, 31, -1}}, TextCondition_TestActorProperNounFlagClear},
    {{{17, 45, 31, -1}, {3, 45, 27, 31}, {-1, -1, -1, -1}, {4, 45, 31, -1}}, TextCondition_TestTargetProperNounFlagClear},
    {{{17, 45, 37, -1}, {3, 45, 29, -1}, {-1, -1, -1, -1}, {4, 45, -1, -1}}, TextCondition_ReadTargetMixedFlag},
    {{{17, 45, 23, -1}, {3, 45, 27, 23}, {-1, -1, -1, -1}, {4, 45, 23, -1}}, TextCondition_TestTargetIsNotMixed},
    {{{17, 47, 7, 12}, {3, 2, 7, 12}, {-1, -1, -1, -1}, {4, 47, 7, 12}}, GameState_TestFirstPartyMemberStatsPredicate},
    {{{17, 47, 7, 48}, {3, 2, 7, 48}, {-1, -1, -1, -1}, {4, 47, 7, 48}}, TestProtagonistResourceLookupSuccess},
    {{{17, 47, 7, 19}, {3, 2, 7, 19}, {-1, -1, -1, -1}, {4, 47, 7, 19}}, GameState_TestUnknownObjectResolvedValueStatusZero},
    {{{17, 47, 7, 14}, {3, 2, 7, 14}, {-1, -1, -1, -1}, {4, 47, 7, 14}}, TextCondition_TestItemFrenchVowelFlagClear},
    {{{17, 47, 7, 15}, {3, 2, 7, 14}, {-1, -1, -1, -1}, {4, 47, 7, 14}}, TextCondition_TestItemFrenchVowelFlagClear},
    {{{17, 47, 7, 16}, {3, 2, 7, 14}, {-1, -1, -1, -1}, {4, 47, 7, 14}}, TextCondition_TestSecondItemFrenchVowelFlagClear},
    {{{17, 47, 7, 20}, {3, 2, 7, 20}, {-1, -1, -1, -1}, {4, 47, 7, 20}}, TextCondition_TestMonsterFrenchVowelFlagClear},
    {{{17, 47, 7, 46}, {3, 2, 7, 46}, {-1, -1, -1, -1}, {4, 47, 7, 46}}, TextCondition_TestVocationFrenchVowelFlagClear},
    {{{17, 47, 7, 1}, {3, 2, 7, 1}, {-1, -1, -1, -1}, {4, 47, 7, 1}}, TextCondition_TestActorFrenchVowelFlagClear},
    {{{17, 47, 7, 45}, {3, 2, 7, 45}, {-1, -1, -1, -1}, {4, 47, 7, 45}}, TextCondition_TestTargetFrenchVowelFlagClear},
    {{{17, 37, 8, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, Object_TestWord8B0OutsideZeroOrOne},
    {{{17, 37, 9, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, TextCondition_TestFormatValueTwoIsFrenchPlural},
    {{{17, 37, 10, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, TextCondition_TestFormatValueThreeIsFrenchPlural},
    {{{17, 37, 11, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, Object_TestWord8BCOutsideZeroOrOne},
    {{{17, 37, 51, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, TextCondition_TestFormatValueFiveIsFrenchPlural},
    {{{17, 47, 12, -1}, {3, 2, 12, -1}, {-1, -1, -1, -1}, {4, 47, 12, -1}}, GameState_TestProtagonistResolvedValueStatusZero},
    {{{17, 47, 19, -1}, {3, 2, 19, -1}, {-1, -1, -1, -1}, {4, 47, 19, -1}}, GameState_TestCurrentObjectValuePredicate},
    {{{17, 47, 14, -1}, {3, 2, 14, -1}, {-1, -1, -1, -1}, {4, 47, 14, -1}}, TextCondition_TestItemVowelFlagClear},
    {{{17, 47, 20, -1}, {3, 2, 20, -1}, {-1, -1, -1, -1}, {4, 47, 20, -1}}, TextCondition_TestMonsterVowelFlagClear},
    {{{17, 47, 46, -1}, {3, 2, 46, -1}, {-1, -1, -1, -1}, {4, 47, 46, -1}}, TextCondition_TestVocationVowelFlagClear},
    {{{17, 47, 1, -1}, {3, 2, 1, -1}, {-1, -1, -1, -1}, {4, 47, 1, -1}}, TextCondition_TestActorVowelFlagClear},
    {{{17, 47, 45, -1}, {3, 2, 45, -1}, {-1, -1, -1, -1}, {4, 47, 45, -1}}, TextCondition_TestTargetVowelFlagClear},
    {{{17, 18, 35, -1}, {3, 27, 18, 35}, {-1, -1, -1, -1}, {4, 18, 35, -1}}, TextCondition_TestItemHasNoGermanSpecialEnding},
    {{{17, 18, 36, -1}, {3, 27, 18, 36}, {-1, -1, -1, -1}, {4, 18, 36, -1}}, TextCondition_TestMonsterHasNoGermanSpecialEnding},
    {{{17, 18, 33, -1}, {3, 27, 18, 33}, {-1, -1, -1, -1}, {4, 18, 33, -1}}, TextCondition_TestActorHasNoGermanSpecialEnding},
    {{{17, 18, 34, -1}, {3, 27, 18, 34}, {-1, -1, -1, -1}, {4, 18, 34, -1}}, TextCondition_TestTargetHasNoGermanSpecialEnding},
    {{{-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}}, 0},
};
