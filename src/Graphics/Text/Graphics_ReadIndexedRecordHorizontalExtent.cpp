extern "C" unsigned char* data_02105244[];
struct DrawRequest { unsigned char pad[20]; short index; };
struct Entry { unsigned char pad[33]; unsigned char extent; unsigned char tail[6]; };
// Original: arm9/main @ 0x0203C284; symbol: func_0203c284; size: 0x3C.
// Reads byte 0x21 of a 40-byte record selected by the signed request index.
// The caller uses this extent to adjust its horizontal coordinate for alignment.
extern "C" int Graphics_ReadIndexedRecordHorizontalExtent(const DrawRequest* request)
{
 unsigned char* table=data_02105244[0];
 if(!table) return 0;
 Entry* records=(Entry*)(table+4);
 short index=request->index;
 if(index<0) return 0;
 return records[index].extent;
}
