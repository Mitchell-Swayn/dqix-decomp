#include <globaldefs.h>
struct Record {unsigned unused; const char* file; unsigned flags;}; extern "C" const char* RecordLookup_FindGlobalEntryById(int); extern "C" char* AppendDirectoryAndFilePathWithSeparator(char*,const char*,const char*,...);
// The fourth argument is passed in r3 for the formatting call's record context.
// Original: arm9/main @ 0x020E4810; symbol: func_020e4810; size: 0x54.
extern "C" ARM char* BuildResourcePathFromPackedKindAndFilename(char* out,Record* record){if(record->file){const char* directory=RecordLookup_FindGlobalEntryById((short)(((record->flags<<8)>>26)+200)); out=AppendDirectoryAndFilePathWithSeparator(out,directory,record->file,record);} return out;}
