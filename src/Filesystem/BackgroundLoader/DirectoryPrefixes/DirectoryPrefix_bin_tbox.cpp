// Original data: arm9/main @ 0x020EF83A; symbol: data_020ef83a.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "bin/tbox/" followed by NUL; extent 10 bytes.
extern "C" char ProgramData_TextBinTbox[10] = "bin/tbox/";
