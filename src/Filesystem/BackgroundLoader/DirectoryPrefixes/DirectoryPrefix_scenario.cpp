// Original data: arm9/main @ 0x020EF826; symbol: data_020ef826.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "scenario/" followed by NUL; extent 10 bytes.
extern "C" char ProgramData_TextScenario[10] = "scenario/";
