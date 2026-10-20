// func_020e4958 expands article tags using one of four grammatical cases.
// Cases choose a six-byte GermanArticles entry; zero tagLength ends the scan.
struct GermanArticleTagCase { signed char articleIndex[4]; const char* tag; signed char tagLength; signed char reserved[3]; };
extern "C" {
extern char ProgramData_TextDefm[];
extern char ProgramData_TextDeff[];
extern char ProgramData_TextDefn[];
extern char ProgramData_TextDefplr[];
extern char ProgramData_TextIndefm[];
extern char ProgramData_TextIndeff[];
extern char ProgramData_TextIndefn[];
}
// Original data: arm9/main @ 0x20eea50; symbol: data_020eea50.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 00010203042d0f020500000004000004f82c0f020500000005010205fe2c0f020500000004000304122d0f0207000000060708091a2d0f02070000000a0b0b0a ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const GermanArticleTagCase TextMarkupAppendInflectedNameAndArticles_UnknownRoleDataReferences[8] = {
    {{0, 1, 2, 3}, ProgramData_TextDefm, 5, {0, 0, 0}},
    {{4, 0, 0, 4}, ProgramData_TextDeff, 5, {0, 0, 0}},
    {{5, 1, 2, 5}, ProgramData_TextDefn, 5, {0, 0, 0}},
    {{4, 0, 3, 4}, ProgramData_TextDefplr, 7, {0, 0, 0}},
    {{6, 7, 8, 9}, ProgramData_TextIndefm, 7, {0, 0, 0}},
    {{10, 11, 11, 10}, ProgramData_TextIndeff, 7, {0, 0, 0}},
    {{6, 7, 8, 6}, ProgramData_TextIndefn, 7, {0, 0, 0}},
    {{-1, -1, -1, -1}, 0, 0, {0, 0, 0}},
};
