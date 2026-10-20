// func_02069234 matches prefixes and dispatches grammatical form selectors.
// Categories0..3 set article/form/case attributes;4..9 choose named actors.
struct TextGrammarSelector { const char* prefix; signed char category; signed char argument; unsigned short reserved; };
extern "C" {
extern char ProgramData_TextDEF[];
extern char ProgramData_TextINDEF[];
extern char ProgramData_TextART[];
extern char ProgramData_TextSGL[];
extern char ProgramData_TextPLR[];
extern char ProgramData_TextNOM[];
extern char ProgramData_TextGEN[];
extern char ProgramData_TextDAT[];
extern char ProgramData_TextACC[];
extern char ProgramData_TextINAME[];
extern char ProgramData_TextMNAME[];
extern char ProgramData_TextACTOR[];
extern char ProgramData_TextTARGET[];
extern char ProgramData_TextACTION[];
extern char ProgramData_TextREFLEX[];
}
// Original data: arm9/main @ 0x20e7f04; symbol: data_020e7f04.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 09070f0200000000bc070f0200010000f0060f02010100000e070f02020000001d070f020201000027070f020300000013070f020301000018070f0203020000 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const TextGrammarSelector TextMarkupExpandHandlersTokensAndBracketNames_UnknownRoleDataReferences[16] = {
    {ProgramData_TextDEF, 0, 0, 0},
    {ProgramData_TextINDEF, 0, 1, 0},
    {ProgramData_TextART, 1, 1, 0},
    {ProgramData_TextSGL, 2, 0, 0},
    {ProgramData_TextPLR, 2, 1, 0},
    {ProgramData_TextNOM, 3, 0, 0},
    {ProgramData_TextGEN, 3, 1, 0},
    {ProgramData_TextDAT, 3, 2, 0},
    {ProgramData_TextACC, 3, 3, 0},
    {ProgramData_TextINAME, 4, -1, 0},
    {ProgramData_TextMNAME, 5, -1, 0},
    {ProgramData_TextACTOR, 6, -1, 0},
    {ProgramData_TextTARGET, 7, -1, 0},
    {ProgramData_TextACTION, 8, -1, 0},
    {ProgramData_TextREFLEX, 9, -1, 0},
    {0, -1, -1, 0},
};
