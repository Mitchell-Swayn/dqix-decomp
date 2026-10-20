// Original data: arm9/main @ 0x020EF830; symbol: data_020ef830.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "bin/menu/" followed by NUL; extent 10 bytes.
extern "C" char ProgramData_TextBinMenu[10] = "bin/menu/";
