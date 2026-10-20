// Original data: arm9/main @ 0x020EF8A4; symbol: data_020ef8a4; size: 0x64.
// QueueFileTask scans these prefixes in order until the NULL terminator and
// stores the matching index in the task. Task::GetFullFilename uses that index
// to concatenate "data/", the prefix and the outer filename.
// The external linker identity remains unchanged; its UnknownRole wording is
// a legacy name. The pointer-array type matches the existing caller contract.
extern "C" {
// Original data: arm9/main @ 0x020EF7DE; symbol: data_020ef7de.
extern char ProgramData_TextAni[];
// Original data: arm9/main @ 0x020EF7D4; symbol: data_020ef7d4.
extern char ProgramData_TextBin[];
// Original data: arm9/main @ 0x020EF87C; symbol: data_020ef87c.
extern char ProgramData_TextBinEncount[];
// Original data: arm9/main @ 0x020EF889; symbol: data_020ef889.
extern char ProgramData_TextBinFlditem[];
// Original data: arm9/main @ 0x020EF896; symbol: data_020ef896.
extern char ProgramData_TextBinHondana[];
// Original data: arm9/main @ 0x020EF830; symbol: data_020ef830.
extern char ProgramData_TextBinMenu[];
// Original data: arm9/main @ 0x020EF83A; symbol: data_020ef83a.
extern char ProgramData_TextBinTbox[];
// Original data: arm9/main @ 0x020EF802; symbol: data_020ef802.
extern char ProgramData_TextChara[];
// Original data: arm9/main @ 0x020EF864; symbol: data_020ef864.
extern char ProgramData_TextCharaSub[];
// Original data: arm9/main @ 0x020EF81E; symbol: data_020ef81e.
extern char ProgramData_TextEffect[];
// Original data: arm9/main @ 0x020EF810; symbol: data_020ef810.
extern char ProgramData_TextEnemy[];
// Original data: arm9/main @ 0x020EF817; symbol: data_020ef817.
extern char ProgramData_TextEvent[];
// Original data: arm9/main @ 0x020EF86F; symbol: data_020ef86f.
extern char ProgramData_TextEventChara[];
// Original data: arm9/main @ 0x020EF84E; symbol: data_020ef84e.
extern char ProgramData_TextEventLv5[];
// Original data: arm9/main @ 0x020EF859; symbol: data_020ef859.
extern char ProgramData_TextEvsptLv5[];
// Original data: arm9/main @ 0x020EF7D9; symbol: data_020ef7d9.
extern char ProgramData_TextMap[];
// Original data: arm9/main @ 0x020EF7E8; symbol: data_020ef7e8.
extern char ProgramData_TextMenu[];
// Original data: arm9/main @ 0x020EF7FB; symbol: data_020ef7fb.
extern char ProgramData_TextMovie[];
// Original data: arm9/main @ 0x020EF7EE; symbol: data_020ef7ee.
extern char ProgramData_TextPack[];
// Original data: arm9/main @ 0x020EF844; symbol: data_020ef844.
extern char ProgramData_TextPackLv5[];
// Original data: arm9/main @ 0x020EF7E3; symbol: data_020ef7e3.
extern char ProgramData_TextPrm[];
// Original data: arm9/main @ 0x020EF826; symbol: data_020ef826.
extern char ProgramData_TextScenario[];
// Original data: arm9/main @ 0x020EF7F4; symbol: data_020ef7f4.
extern char ProgramData_TextSkill[];
// Original data: arm9/main @ 0x020EF809; symbol: data_020ef809.
extern char ProgramData_TextSound[];
char* BackgroundLoaderTaskGetFullFilename_UnknownRoleDataReferences[25] = {
    ProgramData_TextAni, // "ani/"
    ProgramData_TextBin, // "bin/"
    ProgramData_TextBinEncount, // "bin/encount/"
    ProgramData_TextBinFlditem, // "bin/flditem/"
    ProgramData_TextBinHondana, // "bin/hondana/"
    ProgramData_TextBinMenu, // "bin/menu/"
    ProgramData_TextBinTbox, // "bin/tbox/"
    ProgramData_TextChara, // "chara/"
    ProgramData_TextCharaSub, // "chara_sub/"
    ProgramData_TextEffect, // "effect/"
    ProgramData_TextEnemy, // "enemy/"
    ProgramData_TextEvent, // "event/"
    ProgramData_TextEventChara, // "event_chara/"
    ProgramData_TextEventLv5, // "event_lv5/"
    ProgramData_TextEvsptLv5, // "evspt_lv5/"
    ProgramData_TextMap, // "map/"
    ProgramData_TextMenu, // "menu/"
    ProgramData_TextMovie, // "movie/"
    ProgramData_TextPack, // "pack/"
    ProgramData_TextPackLv5, // "pack_lv5/"
    ProgramData_TextPrm, // "prm/"
    ProgramData_TextScenario, // "scenario/"
    ProgramData_TextSkill, // "skill/"
    ProgramData_TextSound, // "sound/"
    0
};
}
typedef char BackgroundLoaderDirectoryTableHasTwentyFivePointers[(sizeof(BackgroundLoaderTaskGetFullFilename_UnknownRoleDataReferences) == 100) ? 1 : -1];
