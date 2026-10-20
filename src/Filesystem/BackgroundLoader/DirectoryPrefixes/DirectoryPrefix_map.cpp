// Original data: arm9/main @ 0x020EF7D9; symbol: data_020ef7d9.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "map/" followed by NUL; extent 5 bytes.
extern "C" char ProgramData_TextMap[5] = "map/";
