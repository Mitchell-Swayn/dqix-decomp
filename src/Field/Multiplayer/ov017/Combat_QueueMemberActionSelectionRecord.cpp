#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Object;
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(Object*,const void*,short);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
struct Input42 {unsigned char a,b,c,d;signed char value;unsigned char pad;unsigned short e,f;};
struct Packed42 {unsigned short first,second,e,f;signed char value;unsigned char a,b,c,d;unsigned char bit0:1,bit1:1,protagonist:6;signed char extra;};
struct Command42 {unsigned char opcode;unsigned char alignment[3];Packed42 payload;};
// Original: arm9/ov017 @ 0x021C6814; symbol: Combat_QueueMemberActionSelectionRecord; size: 0xD4.
// Queues command 0x42 with copied scalar fields, two one-bit options and the protagonist index packed into six bits.
extern "C" void Combat_QueueMemberActionSelectionRecord(unsigned short first,unsigned short second,const Input42* input,unsigned char option0,signed char extra,unsigned char option1) {
 Object* queue=(Object*)Network_GetCommandRecordPool();
 Command42 command;
 Packed42* out=&command.payload;
 GameState* game=GameState::GetInstance();
 command.opcode=0x42;
 out->first=first;out->second=second;
 out->a=input->a;out->b=input->b;out->c=input->c;out->d=input->d;
 out->e=input->e;out->value=input->value;out->f=input->f;
 out->bit0=option0;
 out->protagonist=(unsigned char)GameState_ReadProtagonistObjectIndex(game);
 out->extra=extra;
 out->bit1=option1;
 Network_QueueOutgoingRecord(queue,&command,0);
}
