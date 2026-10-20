// Original data: arm9/main @ 0x020EF7E3; symbol: data_020ef7e3.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "prm/" followed by NUL; extent 5 bytes.
extern "C" char ProgramData_TextPrm[5] = "prm/";
