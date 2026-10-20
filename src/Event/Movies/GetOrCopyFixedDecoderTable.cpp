#include <globaldefs.h>
ARM
extern "C" void MIi_CpuCopyFast(const void*,void*,unsigned);
// Original data: arm9/ov016 @ 0x219d1c0; symbol: data_ov016_0219d1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov016 @ 0x2193e78; symbol: data_ov016_02193e78.
// Movie coefficient variable-length decoder lookup. A 12-bit lookahead indexes packed records: consumed bit count, magnitude, zero run and last-coefficient flag. Embedded decoder at 02199f14 extracts these four fields; escape paths at 02199e34/02199e88 add magnitude/run corrections from the trailing tables. Exact codec revision and original table names remain unknown.
// Initial values: hex 010001000100010001000100010001002c822c823c803c80bc00bc00ac00ac001bb81bb81bb81bb81bb61bb61bb61bb61bb41bb41bb41bb41bb21bb21bb21bb2 ...; full span in module reference.
// Observed span: 8448 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned char GetOrCopyFixedDecoderTable_MovieCoefficientVariableLengthDecoderLookup[];
// Original: arm9/ov016 @ 0x0218FD50; symbol: func_ov016_0218fd50; size: 0x70.
// Returns a cached decoder table, copying the fixed table into a reserved arena when space permits.
extern "C" void* GetOrCopyFixedDecoderTable() {
 if(!GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[1]) {
 if(GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[3]>=0x2100){
 GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[1]=GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[4];
 MIi_CpuCopyFast(GetOrCopyFixedDecoderTable_MovieCoefficientVariableLengthDecoderLookup,(void*)GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[1],0x2100);
 GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[4]+=0x2100;GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[3]-=0x2100;
 }else return GetOrCopyFixedDecoderTable_MovieCoefficientVariableLengthDecoderLookup;
 }
 return (void*)GetOrCopyDataBlock_UnknownRoleZeroInitializedStorage[1];
}
