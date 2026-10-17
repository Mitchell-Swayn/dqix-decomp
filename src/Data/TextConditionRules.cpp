// func_02068f40 walks 20-byte rules until the null evaluator sentinel.
// Each four-byte sequence indexes the condition-keyword table; -1 ends it.
// Evaluators receive the game state and two opaque context words, returning a branch ID.
extern "C" {
int TestIndexedByteDiffersFromStateValue(void*, unsigned, unsigned);
int GameState_ReadFirstPartyMemberLinkedBitFlag(void*, unsigned, unsigned);
int GameState_ReadProtagonistNestedFlagAtOffset49C(void*, unsigned, unsigned);
int GameState_ReadFirstPartyMemberStoredBit(void*, unsigned, unsigned);
int GameState_ReadUnknownObjectLinkedBitFlag(void*, unsigned, unsigned);
int GameState_TestAnyListedPartyMemberWithClearStatusFlag(void*, unsigned, unsigned);
int TestPrimaryOrFallbackFlagNotOne(void*, unsigned, unsigned);
int GameState_TestAdditionalNonfilteredPartyMembers(void*, unsigned, unsigned);
int GameState_TestListedQualifyingMemberCountNotOne(void*, unsigned, unsigned);
int TestField8B0NotOne(void*, unsigned, unsigned);
int TestFieldAtOffset8B4(void*, unsigned, unsigned);
int Object_TestElement558DiffersFrom1(void*, unsigned, unsigned);
int TestField8BCNotOne(void*, unsigned, unsigned);
int TestFieldAtOffset8C0(void*, unsigned, unsigned);
int Object_TestNestedOffset18Word8Bit26Clear(void*, unsigned, unsigned);
int TestIndirectEntryBit26Clear(void*, unsigned, unsigned);
int ReadTypeBitsFromOptionalPointerAtOffset18(void*, unsigned, unsigned);
int Object_ReadNestedOffset20PackedFlag(void*, unsigned, unsigned);
int ReadIndirectIndex2ValueOrZero(void*, unsigned, unsigned);
int ReadTypeBitsFromOptionalFirstPointer(void*, unsigned, unsigned);
int Object_ReadInitialNestedPackedFlag(void*, unsigned, unsigned);
int ReadIndirectIndex4ValueOrZero(void*, unsigned, unsigned);
int IsByteField19D5Zero(void*, unsigned, unsigned);
int Object_TestElement6614Equals0(void*, unsigned, unsigned);
int TestPresentUnequalPairValues(void*, unsigned, unsigned);
int IsLinkedWordBitTwentySevenClear(void*, unsigned, unsigned);
int Object_TestNestedOffset10Word8Bit27Clear(void*, unsigned, unsigned);
int ReadByteAtOffset19D7(void*, unsigned, unsigned);
int IsByteField19D8Zero(void*, unsigned, unsigned);
int GameState_TestFirstPartyMemberStatsPredicate(void*, unsigned, unsigned);
int TestProtagonistResourceLookupSuccess(void*, unsigned, unsigned);
int GameState_TestUnknownObjectResolvedValueStatusZero(void*, unsigned, unsigned);
int Object_TestNestedOffset18StatsPredicate(void*, unsigned, unsigned);
int TestIndirectField1CLookupSuccess(void*, unsigned, unsigned);
int TestResolvedPointerField20ValueStatusZero(void*, unsigned, unsigned);
int Object_TestNestedOffset28StatsPredicate(void*, unsigned, unsigned);
int TestIndirectField0LookupSuccess(void*, unsigned, unsigned);
int TestResolvedPointerField10ValueStatusZero(void*, unsigned, unsigned);
int Object_TestWord8B0OutsideZeroOrOne(void*, unsigned, unsigned);
int TestField8B4NeitherZeroNorOne(void*, unsigned, unsigned);
int ToggleMaskedFlagsAtOffset22E(void*, unsigned, unsigned);
int Object_TestWord8BCOutsideZeroOrOne(void*, unsigned, unsigned);
int TestField8C0NeitherZeroNorOne(void*, unsigned, unsigned);
int GameState_TestProtagonistResolvedValueStatusZero(void*, unsigned, unsigned);
int GameState_TestCurrentObjectValuePredicate(void*, unsigned, unsigned);
int TestIndirectField18LookupSuccess(void*, unsigned, unsigned);
int TestAlternateResolvedPointerField20StatusZero(void*, unsigned, unsigned);
int Object_TestNestedOffset28ValuePredicate(void*, unsigned, unsigned);
int TestIndirectField0ValidationSuccess(void*, unsigned, unsigned);
int TestAlternateResolvedPointerField10StatusZero(void*, unsigned, unsigned);
int Object_TestNestedOffset18ObjectPredicate(void*, unsigned, unsigned);
int TestIndirectField20ValidationSuccess(void*, unsigned, unsigned);
int TestResolvedFirstPointerStatusZero(void*, unsigned, unsigned);
int Object_TestNestedOffset10ObjectPredicate(void*, unsigned, unsigned);
}
typedef int (*TextConditionEvaluator)(void*, unsigned, unsigned);
struct TextConditionRule { signed char tags[4][4]; TextConditionEvaluator evaluate; };
extern "C" const TextConditionRule data_020e833c[57] = {
    {{{17, 44, -1, -1}, {3, 27, 44, -1}, {-1, -1, -1, -1}, {4, 44, -1, -1}}, TestIndexedByteDiffersFromStateValue},
    {{{17, 13, 21, -1}, {3, 13, 27, 21}, {-1, -1, -1, -1}, {4, 13, 21, -1}}, GameState_ReadFirstPartyMemberLinkedBitFlag},
    {{{17, 48, 21, -1}, {3, 48, 27, 21}, {-1, -1, -1, -1}, {4, 48, 21, -1}}, GameState_ReadProtagonistNestedFlagAtOffset49C},
    {{{17, 12, 21, -1}, {3, 12, 27, 21}, {-1, -1, -1, -1}, {4, 12, 21, -1}}, GameState_ReadFirstPartyMemberStoredBit},
    {{{17, 21, -1, -1}, {3, 27, 21, -1}, {-1, -1, -1, -1}, {4, 21, -1, -1}}, GameState_ReadUnknownObjectLinkedBitFlag},
    {{{17, 6, 28, -1}, {3, 27, 6, 28}, {-1, -1, -1, -1}, {4, 6, 28, -1}}, GameState_TestAnyListedPartyMemberWithClearStatusFlag},
    {{{17, 43, -1, -1}, {3, 27, 43, -1}, {-1, -1, -1, -1}, {4, 43, -1, -1}}, TestPrimaryOrFallbackFlagNotOne},
    {{{17, 50, -1, -1}, {3, 27, 50, -1}, {-1, -1, -1, -1}, {4, 50, -1, -1}}, GameState_TestAdditionalNonfilteredPartyMembers},
    {{{17, 49, -1, -1}, {3, 27, 49, -1}, {-1, -1, -1, -1}, {4, 49, -1, -1}}, GameState_TestListedQualifyingMemberCountNotOne},
    {{{17, 38, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, TestField8B0NotOne},
    {{{17, 39, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, TestFieldAtOffset8B4},
    {{{17, 40, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, Object_TestElement558DiffersFrom1},
    {{{17, 41, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, TestField8BCNotOne},
    {{{17, 42, -1, -1}, {3, 27, 37, -1}, {-1, -1, -1, -1}, {4, 37, -1, -1}}, TestFieldAtOffset8C0},
    {{{17, 14, 25, 30}, {3, 27, 30, -1}, {-1, -1, -1, -1}, {4, 30, -1, -1}}, Object_TestNestedOffset18Word8Bit26Clear},
    {{{17, 14, 26, 30}, {3, 27, 30, -1}, {-1, -1, -1, -1}, {4, 30, -1, -1}}, Object_TestNestedOffset18Word8Bit26Clear},
    {{{17, 20, 25, 30}, {3, 27, 30, -1}, {-1, -1, -1, -1}, {4, 30, -1, -1}}, TestIndirectEntryBit26Clear},
    {{{17, 14, 25, 20}, {17, 14, 25, 5}, {17, 14, 25, 24}, {4, 14, 25, 22}}, ReadTypeBitsFromOptionalPointerAtOffset18},
    {{{17, 20, 25, 20}, {17, 20, 25, 5}, {17, 20, 25, 24}, {4, 20, 25, 22}}, Object_ReadNestedOffset20PackedFlag},
    {{{17, 0, 20, -1}, {17, 0, 5, -1}, {17, 0, 24, -1}, {4, 0, -1, -1}}, ReadIndirectIndex2ValueOrZero},
    {{{17, 1, 21, -1}, {3, 1, 27, 21}, {-1, -1, -1, -1}, {4, 1, 21, -1}}, ReadTypeBitsFromOptionalFirstPointer},
    {{{17, 1, 20, -1}, {17, 1, 5, -1}, {17, 1, 24, -1}, {4, 1, 22, -1}}, Object_ReadInitialNestedPackedFlag},
    {{{17, 45, 20, -1}, {17, 45, 5, -1}, {17, 45, 24, -1}, {4, 45, 22, -1}}, ReadIndirectIndex4ValueOrZero},
    {{{17, 45, 28, -1}, {3, 45, 27, 28}, {-1, -1, -1, -1}, {4, 45, 28, -1}}, IsByteField19D5Zero},
    {{{17, 1, 28, -1}, {3, 1, 27, 28}, {-1, -1, -1, -1}, {4, 1, 28, -1}}, Object_TestElement6614Equals0},
    {{{17, 1, 45, -1}, {3, 1, 27, 45}, {-1, -1, -1, -1}, {4, 1, 45, -1}}, TestPresentUnequalPairValues},
    {{{17, 1, 31, -1}, {3, 1, 27, 31}, {-1, -1, -1, -1}, {4, 1, 31, -1}}, IsLinkedWordBitTwentySevenClear},
    {{{17, 45, 31, -1}, {3, 45, 27, 31}, {-1, -1, -1, -1}, {4, 45, 31, -1}}, Object_TestNestedOffset10Word8Bit27Clear},
    {{{17, 45, 37, -1}, {3, 45, 29, -1}, {-1, -1, -1, -1}, {4, 45, -1, -1}}, ReadByteAtOffset19D7},
    {{{17, 45, 23, -1}, {3, 45, 27, 23}, {-1, -1, -1, -1}, {4, 45, 23, -1}}, IsByteField19D8Zero},
    {{{17, 47, 7, 12}, {3, 2, 7, 12}, {-1, -1, -1, -1}, {4, 47, 7, 12}}, GameState_TestFirstPartyMemberStatsPredicate},
    {{{17, 47, 7, 48}, {3, 2, 7, 48}, {-1, -1, -1, -1}, {4, 47, 7, 48}}, TestProtagonistResourceLookupSuccess},
    {{{17, 47, 7, 19}, {3, 2, 7, 19}, {-1, -1, -1, -1}, {4, 47, 7, 19}}, GameState_TestUnknownObjectResolvedValueStatusZero},
    {{{17, 47, 7, 14}, {3, 2, 7, 14}, {-1, -1, -1, -1}, {4, 47, 7, 14}}, Object_TestNestedOffset18StatsPredicate},
    {{{17, 47, 7, 15}, {3, 2, 7, 14}, {-1, -1, -1, -1}, {4, 47, 7, 14}}, Object_TestNestedOffset18StatsPredicate},
    {{{17, 47, 7, 16}, {3, 2, 7, 14}, {-1, -1, -1, -1}, {4, 47, 7, 14}}, TestIndirectField1CLookupSuccess},
    {{{17, 47, 7, 20}, {3, 2, 7, 20}, {-1, -1, -1, -1}, {4, 47, 7, 20}}, TestResolvedPointerField20ValueStatusZero},
    {{{17, 47, 7, 46}, {3, 2, 7, 46}, {-1, -1, -1, -1}, {4, 47, 7, 46}}, Object_TestNestedOffset28StatsPredicate},
    {{{17, 47, 7, 1}, {3, 2, 7, 1}, {-1, -1, -1, -1}, {4, 47, 7, 1}}, TestIndirectField0LookupSuccess},
    {{{17, 47, 7, 45}, {3, 2, 7, 45}, {-1, -1, -1, -1}, {4, 47, 7, 45}}, TestResolvedPointerField10ValueStatusZero},
    {{{17, 37, 8, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, Object_TestWord8B0OutsideZeroOrOne},
    {{{17, 37, 9, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, TestField8B4NeitherZeroNorOne},
    {{{17, 37, 10, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, ToggleMaskedFlagsAtOffset22E},
    {{{17, 37, 11, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, Object_TestWord8BCOutsideZeroOrOne},
    {{{17, 37, 51, -1}, {3, 27, 37, 7}, {-1, -1, -1, -1}, {4, 37, 7, -1}}, TestField8C0NeitherZeroNorOne},
    {{{17, 47, 12, -1}, {3, 2, 12, -1}, {-1, -1, -1, -1}, {4, 47, 12, -1}}, GameState_TestProtagonistResolvedValueStatusZero},
    {{{17, 47, 19, -1}, {3, 2, 19, -1}, {-1, -1, -1, -1}, {4, 47, 19, -1}}, GameState_TestCurrentObjectValuePredicate},
    {{{17, 47, 14, -1}, {3, 2, 14, -1}, {-1, -1, -1, -1}, {4, 47, 14, -1}}, TestIndirectField18LookupSuccess},
    {{{17, 47, 20, -1}, {3, 2, 20, -1}, {-1, -1, -1, -1}, {4, 47, 20, -1}}, TestAlternateResolvedPointerField20StatusZero},
    {{{17, 47, 46, -1}, {3, 2, 46, -1}, {-1, -1, -1, -1}, {4, 47, 46, -1}}, Object_TestNestedOffset28ValuePredicate},
    {{{17, 47, 1, -1}, {3, 2, 1, -1}, {-1, -1, -1, -1}, {4, 47, 1, -1}}, TestIndirectField0ValidationSuccess},
    {{{17, 47, 45, -1}, {3, 2, 45, -1}, {-1, -1, -1, -1}, {4, 47, 45, -1}}, TestAlternateResolvedPointerField10StatusZero},
    {{{17, 18, 35, -1}, {3, 27, 18, 35}, {-1, -1, -1, -1}, {4, 18, 35, -1}}, Object_TestNestedOffset18ObjectPredicate},
    {{{17, 18, 36, -1}, {3, 27, 18, 36}, {-1, -1, -1, -1}, {4, 18, 36, -1}}, TestIndirectField20ValidationSuccess},
    {{{17, 18, 33, -1}, {3, 27, 18, 33}, {-1, -1, -1, -1}, {4, 18, 33, -1}}, TestResolvedFirstPointerStatusZero},
    {{{17, 18, 34, -1}, {3, 27, 18, 34}, {-1, -1, -1, -1}, {4, 18, 34, -1}}, Object_TestNestedOffset10ObjectPredicate},
    {{{-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}}, 0},
};
