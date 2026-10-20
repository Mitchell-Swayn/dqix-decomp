// Original data: arm9/main @ 0x020EF810; symbol: data_020ef810.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "enemy/" followed by NUL; extent 7 bytes.
extern "C" char ProgramData_TextEnemy[7] = "enemy/";
