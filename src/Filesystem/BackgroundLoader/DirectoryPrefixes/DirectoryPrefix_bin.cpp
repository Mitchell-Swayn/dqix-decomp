// Original data: arm9/main @ 0x020EF7D4; symbol: data_020ef7d4.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "bin/" followed by NUL; extent 5 bytes.
extern "C" char ProgramData_TextBin[5] = "bin/";
