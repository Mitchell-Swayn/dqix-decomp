// Original data: arm9/main @ 0x020EF908; symbol: data_020ef908.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "%s%s%s" followed by NUL; extent 7 bytes.
extern "C" char ProgramData_FormatSSS[7] = "%s%s%s";
