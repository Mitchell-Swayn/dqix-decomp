// Original data: arm9/main @ 0x020EF81E; symbol: data_020ef81e.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "effect/" followed by NUL; extent 8 bytes.
extern "C" char ProgramData_TextEffect[8] = "effect/";
