# Filesystem reader and streaming decompression

ExtendedNitroVM is the file-readable-state and streaming-decompression wrapper used by BackgroundLoader and GPC. Its13 reader/decompression functions retain their established API names and current Filesystem source unit. One cache initializer shares that compilation unit but belongs logically to FileCache; it is not moved or absorbed merely because of source adjacency.

## Reader contract

Open first closes/reset the old machine. With skip=false, it searches cached file-accessor CRCs when the cache is ready and otherwise prepares a read by path. Close finishes pending work and clears state. Abort cancels the NitroVM command under the resource mutex and marks the wrapper bad. Read issues an async command and yields until it leaves the handle queue, then returns bytes read or zero on a bad state.

Status2 is readable but has no file size and cannot seek; its original meaning is unresolved. Existing raw status names and behavior remain unchanged.

## Compression contract

The four-byte prefix has a3bit compression type and29bit declared output length. Type0 copies data; type1 calls the preserved SDK LZ stream implementation; types2/3 use tree-based Huffman output with4/8bit symbols; type4 uses RLE repeat/literal runs. Decompressor initialization checks pointers, prefix size, type and rounded output capacity.

The scratch path reads compressed bytes right-aligned in the output space when capacity permits and uses a256byte tail buffer when needed. It tracks input consumption separately from declared output length and retains cache-maintenance operations. The refactor does not alter buffer assumptions or repair bounds.

Two unreconstructed functions now have descriptive behavior names: `Decompressor_ProcessRleStream` (020CA95C) and `Decompressor_ProcessHuffmanStream` (020CAB94). They retain original binary instructions and nominal declarations. These names do not claim recovered SDK spellings. `MI_ReadUncompLZ8` retains its existing SDK name, assembly source and runtime provenance; no C decompilation credit is added.

## Inventory

`config/usa/filesystem_reader_symbols.json` distinguishes owned reader routines, the related cache initializer and the runtime dependency.

| Identity | Current symbol | Ownership |
|---|---|---|
| arm9/main:020d8714 | `_ZNK17CompressionPrefix21GetDecompressedLengthEv` | Filesystem/Reader |
| arm9/main:020d8720 | `_ZN12Decompressor17InitAndDecompressEPvjPKvj` | Filesystem/Reader |
| arm9/main:020d8824 | `_ZN12Decompressor12ProcessBytesEPKvj` | Filesystem/Reader |
| arm9/main:020d890c | `_Z22CacheMainFileAccessorsv` | Filesystem/FileCache |
| arm9/main:020d8a48 | `_ZN15ExtendedNitroVM14ZeroInitializeEv` | Filesystem/Reader |
| arm9/main:020d8a68 | `_ZN15ExtendedNitroVM17IsInReadableStateEv` | Filesystem/Reader |
| arm9/main:020d8ab0 | `_ZN15ExtendedNitroVM11GetFileSizeEv` | Filesystem/Reader |
| arm9/main:020d8ae8 | `_ZN15ExtendedNitroVM4SeekEj` | Filesystem/Reader |
| arm9/main:020d8b4c | `_ZN15ExtendedNitroVM5CloseEv` | Filesystem/Reader |
| arm9/main:020d8b94 | `_ZN15ExtendedNitroVM4OpenEPKcb` | Filesystem/Reader |
| arm9/main:020d8c78 | `_ZN15ExtendedNitroVM4ReadEPvj` | Filesystem/Reader |
| arm9/main:020d8d20 | `_ZN15ExtendedNitroVM5AbortEv` | Filesystem/Reader |
| arm9/main:020d8d5c | `_ZN15ExtendedNitroVM26DecompressWithScratchSpaceER12DecompressorRjS2_S2_Pvj` | Filesystem/Reader |
| arm9/main:020d8ee4 | `_ZN15ExtendedNitroVM15DecompressBytesEPvRjjj` | Filesystem/Reader |
| arm9/main:020ca95c | `Decompressor_ProcessRleStream` | Filesystem/Reader |
| arm9/main:020cab94 | `Decompressor_ProcessHuffmanStream` | Filesystem/Reader |
| arm9/main:020caa10 | `MI_ReadUncompLZ8` | RuntimeSupport |

Underlying NitroVM command execution, file-accessor cache tables, memory/cache maintenance and locks remain separate dependencies. The established public header paths and compilation units are preserved.
