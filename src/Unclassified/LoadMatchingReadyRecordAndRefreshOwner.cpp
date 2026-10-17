#include <globaldefs.h>
#pragma optimize_for_size off
struct Record { char pad[0xc4]; unsigned char id; char rest[0x1b]; }; struct Owner { char pad[0x98]; unsigned ready; Record* records; char rest[0x13]; unsigned char count; };
extern "C" int AreBothWordFieldsD4And9CNonzero(Record*); extern "C" void func_0204cb20(Record*,void*,unsigned,unsigned char); extern "C" void ReadSelectedRecordGeometryAndScaleCoordinates(Owner*);
// Original: arm9/main @ 0x0205D5D0; symbol: func_0205d5d0; size: 0xAC.
extern "C" int LoadMatchingReadyRecordAndRefreshOwner(Owner* self,unsigned id,void* data,unsigned arg,unsigned char flag) { if(!data)return 1;if(!self->ready)return 1;if(!self->records)return 1; Record* record;for(unsigned char i=0;i<self->count;++i) { record=self->records+i; if(AreBothWordFieldsD4And9CNonzero(record)&&id==record->id) { func_0204cb20(record,data,arg,flag);ReadSelectedRecordGeometryAndScaleCoordinates(self);return 0; } } return 1; }
