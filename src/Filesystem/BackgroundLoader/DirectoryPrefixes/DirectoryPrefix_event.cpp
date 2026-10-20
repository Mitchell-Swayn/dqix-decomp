// Original data: arm9/main @ 0x020EF817; symbol: data_020ef817.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "event/" followed by NUL; extent 7 bytes.
extern "C" char ProgramData_TextEvent[7] = "event/";
