// Original data: arm9/main @ 0x020EF7F4; symbol: data_020ef7f4.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "skill/" followed by NUL; extent 7 bytes.
extern "C" char ProgramData_TextSkill[7] = "skill/";
