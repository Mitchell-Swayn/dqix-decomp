// Original: arm9/main @ 0x020BD7C4; symbol: func_020bd7c4; size: 0xc8.
#include <globaldefs.h>
#pragma optimize_for_size off
#include <Filesystem/NitroVM.h>
int NitroVM_ReadSync(NitroVM*,void*,int);
int NitroVM_Seek(NitroVM*,int,int);
typedef struct Entry
{
  unsigned offset;
  unsigned length;
  unsigned unknown8;
  unsigned unknownC;
} Entry;
typedef struct Table
{
  unsigned unknown0;
  unsigned unknown4;
  unsigned count;
  Entry entries[1];
} Table;
typedef struct Owner
{
  unsigned pad[13];
  NitroVM vm;
  unsigned unknown7C;
  unsigned unknown80;
  Table *table;
  unsigned unknown88;
  unsigned unknown8C;
  int chunkSize;
} Owner;
// Original data: arm9/main @ 0x2110370; symbol: data_02110370.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Owner *NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
// Original ARM9 main @ 0x020bd7c4, symbol func_020bd7c4.
extern "C" ARM int Filesystem_ReadIndexedResourceRangeInChunks(unsigned index, char *destination, int length, unsigned offset)
{
  int total;
  int chunkLimit;
  NitroVM *stream;
  Entry *entry;
  char *streamAddress;
  unsigned seekBaseOffset;
  int chunk;
  Owner *owner;
  Entry *selectedEntry;
  owner = NNSSndArcGetCurrent_UnknownRoleZeroInitializedStorage;
  Table *table = owner->table;
  if (index >= table->count)
  {
    return -1;
  }
  chunkLimit = owner->chunkSize;
  selectedEntry = &table->entries[index];
  if (!chunkLimit)
  {
    chunkLimit = length;
  }
  entry = selectedEntry;
  total = 0;
  if (length > 0)
  {
    do
    {
      chunk = length - total;
      if (chunk > chunkLimit)
      {
        chunk = chunkLimit;
      }
      streamAddress = (char*)&owner->vm;
      unsigned remaining = entry->length - offset;
      if (((unsigned) chunk) > remaining)
      {
        chunk = remaining;
      }
      if (!chunk)
      {
        break;
      }
      seekBaseOffset = entry->offset;
      stream = (NitroVM *) streamAddress;
      if (!NitroVM_Seek(stream, seekBaseOffset + offset, 0))
      {
        return -1;
      }
      int read = NitroVM_ReadSync(stream, destination, chunk);
      if (read < 0)
      {
        return read;
      }
      total += read;
      offset += read;
      destination += read;
    }
    while (total < length);
  }
  return total;
}
