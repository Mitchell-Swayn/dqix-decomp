// Original data: arm9/main @ 0x020EF7DE; symbol: data_020ef7de.
// BackgroundLoader::Task::GetFullFilename concatenates data/, a directory prefix,
// and the task filename. QueueFileTask selects the prefix by table order.
// Original initialized value: "ani/" followed by NUL; extent 5 bytes.
extern "C" char ProgramData_TextAni[5] = "ani/";
