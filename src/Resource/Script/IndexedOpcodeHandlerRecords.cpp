#include <Resource/Script.h>

// Procedure declarations retain the current reconstructed ABI of each target.
// Script_AddFilteredCountToQuestProgress is still unreconstructed. Its original
// ARM instructions preserve r0 as the parameter address passed to conversion,
// and return the integer success values 0 or 1 (main @ 0x0209D1A4).
extern "C" int Script_ClearFilteredRecords(void);
extern "C" int Script_FilterRecordsByKind(void *param1);
extern "C" int Script_FilterSixtyFourByteRecordsByInitialFlagMaskWithConvertedParameters(char* p);
extern "C" int Script_FilterDatabaseRecordsByFlagByte1WithConvertedParameters(void *p);
extern "C" int Script_FilterRecordsByPredicateModeZero(unsigned char* param);
extern "C" int Script_FilterSixtyFourByteRecordsByValuePredicateWithConvertedParameters(char* p);
extern "C" int Script_FilterDatabaseRecordsByFlagByte2WithConvertedParameters(char* p);
extern "C" int Script_FilterRecordsByFourthFlagByteMask(char* p);
extern "C" int Script_FilterSixtyFourByteRecordsByPredicateModeOneWithConvertedParameters(unsigned char*);
extern "C" int Script_FilterDatabaseRecordsByModeAndValueWithConvertedParameters(int parameter);
extern "C" int Script_FilterRecordsByPackedMask(int argument);
extern "C" int Script_InvokeStateForParameterPairs(Script::Parameter* p,int count);
extern "C" int Script_FilterRecordsByHalfwordThreshold(char* p);
extern "C" int Script_AddFilteredCountToQuestProgress(void*);
extern "C" int Script_ReadMatchingRequestHalfwordAtOffsetA(int);
extern "C" bool Script_MarkQuestRecordWithFlag4000(unsigned value);
extern "C" int Script_AddRequestEntryHalfword(char *params);
extern "C" int Script_ReadQuestProgressElement(unsigned char* self);
extern "C" int Script_WriteSourceOrFilteredEntryCount(char* p);
extern "C" int Script_WriteRandomValueWithinInclusiveLimit(char* p);
extern "C" int Script_FilterDatabaseRecordsByCategoryWithConvertedParameters(int param_1);
extern "C" int Script_ReadOptionalValueOrPercent(unsigned char*);
extern "C" int Script_InvokeGlobalStateWithResolvedPair(char* p);
extern "C" int Script_WriteRemappedProgressFlag(int p);
extern "C" int Script_FilterFlag80RecordsByKind(int param);
extern "C" int Script_InvokeStateWithMixedResolvedTriple(void* object, int, int, int arg3);
extern "C" int Script_FilterRecordsWithoutPositiveCounters(void* input);
extern "C" int Script_FilterRecordsByConvertedFloatThreshold(void* state);
extern "C" int Script_InvokeStateWithResolvedValue(unsigned value);
extern "C" int Script_WriteZoneOrGrottoBossFloor(unsigned value);
extern "C" int Script_FilterRecordsWithEitherByte25Or26(int a);
extern "C" int Script_InvokeStateWithResolvedTriple(char* p);
extern "C" int Script_FilterSixtyFourByteRecordsWithFlags36ClearWithConvertedParameters(void* p);
extern "C" int Script_SetGlobalRecordWord6C(void* param);
extern "C" int Script_SetFilterContextParameter(int param);
extern "C" bool Grotto_WriteDetailedMapKindThroughOutputParameter(void*);
extern "C" int Script_ReadDetailedGrottoByte62(void* p);
extern "C" int Script_WriteClampedResolvedHalfword0A(char* args);
extern "C" int Script_AddSpecialItemQuantityAndRememberArguments(char* parameters);
extern "C" int GameState_DispatchHalfwordAndByteConvertedParameters(int argument);
extern "C" int Script_ReadSpecialInventoryItemCount(char* p);
extern "C" int Script_WriteResolvedStateValueToParameter(char* p);
extern "C" int Grotto_WriteCurrentOrBossFloorIndexThroughOutput(unsigned value);
extern "C" int Script_SetGlobalRecordWords84And88And6C(char* input);
extern "C" bool Script_WriteCurrentStateValueToParameter(void*);
extern "C" int Script_SetQueryContextResultValue(int argument);
extern "C" bool Script_ReadDetailedGrottoByte63(void*);
extern "C" int Script_ReadActiveGrottoDetailedValue(void* parameter);
extern "C" int Grotto_WriteDetailedMapByte100WhenKindOne(void* p);

// The registration consumer copies only the procedure address and signed index;
// it does not invoke the targets. Keep that address field opaque rather than
// imposing one callback prototype on their differing current declarations.
struct IndexedOpcodeHandlerRecord {
    void* procedure;
    int index;
};

// Original data: arm9/main @ 0x020F1758; symbol: data_020f1758; size: 0x190.
// 49 indexed procedure records followed by the null-procedure/-1 sentinel.
// Script_RegisterFortyNineIndexedOpcodeHandlers walks these eight-byte records,
// validates indices against [0,49), rejects duplicate slots, and registers them.
// Original values and relocation targets: docs/data-symbols/main.md.
extern "C" {
IndexedOpcodeHandlerRecord ScriptRegisterFortyNineIndexedOpcodeHandlers_UnknownRoleProcedureReferenceRecords[50] = {
    { (void*)Script_ClearFilteredRecords, 0 },
    { (void*)Script_FilterRecordsByKind, 1 },
    { (void*)Script_FilterSixtyFourByteRecordsByInitialFlagMaskWithConvertedParameters, 2 },
    { (void*)Script_FilterDatabaseRecordsByFlagByte1WithConvertedParameters, 3 },
    { (void*)Script_FilterRecordsByPredicateModeZero, 4 },
    { (void*)Script_FilterSixtyFourByteRecordsByValuePredicateWithConvertedParameters, 5 },
    { (void*)Script_FilterDatabaseRecordsByFlagByte2WithConvertedParameters, 6 },
    { (void*)Script_FilterRecordsByFourthFlagByteMask, 7 },
    { (void*)Script_FilterSixtyFourByteRecordsByPredicateModeOneWithConvertedParameters, 8 },
    { (void*)Script_FilterDatabaseRecordsByModeAndValueWithConvertedParameters, 9 },
    { (void*)Script_FilterRecordsByPackedMask, 10 },
    { (void*)Script_InvokeStateForParameterPairs, 11 },
    { (void*)Script_FilterRecordsByHalfwordThreshold, 12 },
    { (void*)Script_AddFilteredCountToQuestProgress, 13 },
    { (void*)Script_ReadMatchingRequestHalfwordAtOffsetA, 14 },
    { (void*)Script_MarkQuestRecordWithFlag4000, 15 },
    { (void*)Script_AddRequestEntryHalfword, 16 },
    { (void*)Script_ReadQuestProgressElement, 17 },
    { (void*)Script_WriteSourceOrFilteredEntryCount, 18 },
    { (void*)Script_WriteRandomValueWithinInclusiveLimit, 19 },
    { (void*)Script_FilterDatabaseRecordsByCategoryWithConvertedParameters, 20 },
    { (void*)Script_ReadOptionalValueOrPercent, 21 },
    { (void*)Script_InvokeGlobalStateWithResolvedPair, 22 },
    { (void*)Script_WriteRemappedProgressFlag, 23 },
    { (void*)Script_FilterFlag80RecordsByKind, 24 },
    { (void*)Script_InvokeStateWithMixedResolvedTriple, 25 },
    { (void*)Script_FilterRecordsWithoutPositiveCounters, 26 },
    { (void*)Script_FilterRecordsByConvertedFloatThreshold, 27 },
    { (void*)Script_InvokeStateWithResolvedValue, 28 },
    { (void*)Script_WriteZoneOrGrottoBossFloor, 29 },
    { (void*)Script_FilterRecordsWithEitherByte25Or26, 30 },
    { (void*)Script_InvokeStateWithResolvedTriple, 31 },
    { (void*)Script_FilterSixtyFourByteRecordsWithFlags36ClearWithConvertedParameters, 32 },
    { (void*)Script_SetGlobalRecordWord6C, 33 },
    { (void*)Script_SetFilterContextParameter, 34 },
    { (void*)Grotto_WriteDetailedMapKindThroughOutputParameter, 35 },
    { (void*)Script_ReadDetailedGrottoByte62, 36 },
    { (void*)Script_WriteClampedResolvedHalfword0A, 37 },
    { (void*)Script_AddSpecialItemQuantityAndRememberArguments, 38 },
    { (void*)GameState_DispatchHalfwordAndByteConvertedParameters, 39 },
    { (void*)Script_ReadSpecialInventoryItemCount, 40 },
    { (void*)Script_WriteResolvedStateValueToParameter, 41 },
    { (void*)Grotto_WriteCurrentOrBossFloorIndexThroughOutput, 42 },
    { (void*)Script_SetGlobalRecordWords84And88And6C, 43 },
    { (void*)Script_WriteCurrentStateValueToParameter, 44 },
    { (void*)Script_SetQueryContextResultValue, 45 },
    { (void*)Script_ReadDetailedGrottoByte63, 46 },
    { (void*)Script_ReadActiveGrottoDetailedValue, 47 },
    { (void*)Grotto_WriteDetailedMapByte100WhenKindOne, 48 },
    { 0, -1 }
};
}
