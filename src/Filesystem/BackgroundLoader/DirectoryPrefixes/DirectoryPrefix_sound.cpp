// Original data: arm9/main @ 0x020EF809; symbol: data_020ef809.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "sound/" followed by NUL; extent 7 bytes.
extern "C" char ProgramData_TextSound[7] = "sound/";
