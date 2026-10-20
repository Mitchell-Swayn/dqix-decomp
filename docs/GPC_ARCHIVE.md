# GPC archive subsystem

`Filesystem/GPC` owns archive metadata lookup and decompression adapters. Its three source units contain25 matched functions plus the initialized `gpcData` storage. All existing descriptive API names and startup ABI spelling are retained; source units are grouped without merging. The address-qualified inventory is `config/usa/gpc_archive_symbols.json`.

## Format and operations

GPCFile/Header/FileEntry describe signature, metadata offsets and word-based entry offsets. Name-based helpers calculate the established file-cache string CRC and call the CRC form. `GPCFile::GetFileByCRC` searches the archive entries. In-memory data access computes the inner-file address from archive and entry offsets and returns its stored size.

The streaming path opens the archive with ExtendedNitroVM, reads and checks its GPC2 signature, and decompresses metadata into caller-provided space. It can right-align the metadata within that space. Inner-file length/read adapters seek to the entry offset and either read uncompressed bytes or invoke streaming decompression. The archive/reader pair API resets the file pointer and reader together.

Runtime startup initializes the revision-string suffix and numeric GPC0/GPC1/GPC2 signatures from existing text. `GPCData.cpp` retains the on-cartridge zero initializers and explicit layout carrier; startup writes runtime fields rather than replacing the binary data initializer with precomputed constants.

## Ownership boundary

ExtendedNitroVM provides file reads/decompression, FileCache provides string CRC, and memory/cache helpers provide copying and cache synchronization. BackgroundLoader owns task scheduling and metadata scratch-arena lifetime. These remain separate owners even when GPC routines are called from the loader loop. Public headers retain their established include paths.

The matched compilation units and data carrier are preserved. The original declaration boundaries for the adjacent static data remain uncertain. No missing-entry behavior, argument contract or bounds are altered.

## Inventory

| Identity | Retained symbol |
|---|---|
| arm9/main:020d8fcc | `Filesystem_GetGPCInnerFileDataByEntry` |
| arm9/main:020d9010 | `_ZN7GPCFile16GetMainDataStartEv` |
| arm9/main:020d901c | `_ZN7GPCFile12GetFileByCRCEj` |
| arm9/main:020d90d0 | `Filesystem_GetGPCInnerFileDataByName` |
| arm9/main:020d9100 | `Filesystem_GetGPCInnerFileDataByCRC` |
| arm9/main:020d9164 | `_Z18ZeroInitGPCPointerPP7GPCFile` |
| arm9/main:020d9170 | `_Z21ZeroDestroyGPCPointerPP7GPCFile` |
| arm9/main:020d917c | `Filesystem_IsGPCPairReadable` |
| arm9/main:020d91a8 | `_Z12ResetGPCPairPP7GPCFileR15ExtendedNitroVM` |
| arm9/main:020d91dc | `_Z42LoadAndDecompressGPCHeaderAndInnerFileInfoPP7GPCFileR15ExtendedNitroVMPKcPvRjjbPb` |
| arm9/main:020d9354 | `_Z21GetGPCInnerFileLengthR15ExtendedNitroVMRKN7GPCFile6HeaderEPKNS1_9FileEntryE` |
| arm9/main:020d93d8 | `_Z27GetGPCInnerFileLengthByNameRKP7GPCFileR15ExtendedNitroVMPKc` |
| arm9/main:020d9400 | `_Z26GetGPCInnerFileLengthByCRCRKP7GPCFileR15ExtendedNitroVMj` |
| arm9/main:020d9458 | `_Z21DecompressFileFromGPCR15ExtendedNitroVMPvRjjRKN7GPCFile6HeaderEPKNS3_9FileEntryE` |
| arm9/main:020d9538 | `_Z27DecompressFileFromGPCByNameRKP7GPCFileR15ExtendedNitroVMPvRjjPKc` |
| arm9/main:020d9580 | `_Z26DecompressFileFromGPCByCRCRKP7GPCFileR15ExtendedNitroVMPvRjjj` |
| arm9/main:020d95f8 | `_ZN11GPCReadPair14ZeroInitializeEv` |
| arm9/main:020d960c | `_ZN11GPCReadPair21ZeroInitializeMachineEv` |
| arm9/main:020d961c | `_ZN11GPCReadPair5ResetEv` |
| arm9/main:020d962c | `_Z16CopyGPCSignaturePjS_` |
| arm9/main:020d9638 | `_Z19SetGPCSignatureGPC0Pj` |
| arm9/main:020d9654 | `_Z26CopyGPCSignatureFromStringPjPKc` |
| arm9/main:020d9678 | `_Z19SetGPCSignatureGPC1Pj` |
| arm9/main:020d9694 | `_Z19SetGPCSignatureGPC2Pj` |
| arm9/main:020e6710 | `__sinit_020e6710` |
