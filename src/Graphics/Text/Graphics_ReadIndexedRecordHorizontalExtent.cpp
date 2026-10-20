// Original data: arm9/main @ 0x2105244; symbol: data_02105244.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char* TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage[];
struct DrawRequest { unsigned char pad[20]; short index; };
struct Entry { unsigned char pad[33]; unsigned char extent; unsigned char tail[6]; };
// Original: arm9/main @ 0x0203C284; symbol: func_0203c284; size: 0x3C.
// Reads byte 0x21 of a 40-byte record selected by the signed request index.
// The caller uses this extent to adjust its horizontal coordinate for alignment.
extern "C" int Graphics_ReadIndexedRecordHorizontalExtent(const DrawRequest* request)
{
 unsigned char* table=TextSpriteDecodeCachedText_UnknownRoleZeroInitializedStorage[0];
 if(!table) return 0;
 Entry* records=(Entry*)(table+4);
 short index=request->index;
 if(index<0) return 0;
 return records[index].extent;
}
