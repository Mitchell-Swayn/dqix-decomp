// Original data: arm9/main @ 0x020EF7FB; symbol: data_020ef7fb.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "movie/" followed by NUL; extent 7 bytes.
extern "C" char ProgramData_TextMovie[7] = "movie/";
