// Original data: arm9/main @ 0x020EF7EE; symbol: data_020ef7ee.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "pack/" followed by NUL; extent 6 bytes.
extern "C" char ProgramData_TextPack[6] = "pack/";
