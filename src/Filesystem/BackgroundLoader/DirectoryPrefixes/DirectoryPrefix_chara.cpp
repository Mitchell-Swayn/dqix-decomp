// Original data: arm9/main @ 0x020EF802; symbol: data_020ef802.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "chara/" followed by NUL; extent 7 bytes.
extern "C" char ProgramData_TextChara[7] = "chara/";
