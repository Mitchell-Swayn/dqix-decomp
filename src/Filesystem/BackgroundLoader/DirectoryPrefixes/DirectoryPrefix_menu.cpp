// Original data: arm9/main @ 0x020EF7E8; symbol: data_020ef7e8.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "menu/" followed by NUL; extent 6 bytes.
extern "C" char ProgramData_TextMenu[6] = "menu/";
