#pragma optimize_for_size off
// Original: arm9/main @ 0x020DD7AC; symbol: func_020dd7ac; size: 0x108.
// Initializes a party-indexed record and twelve pointers to its current values.
// Proposed descriptive name: Party_InitializeTwelveValuePairRecord.
struct PartyValuePairRecord {
 int partyIndex; unsigned state; void *currentValues[12]; unsigned char flag; unsigned char padding[3];
 unsigned short halfwordPairs0[4];
 unsigned wordPairs[8];
 unsigned short halfwordPairs1[12];
};
extern "C" void Party_InitializeTwelveValuePairRecord(PartyValuePairRecord *self)
{
 self->partyIndex=-1; self->state=0;
 self->currentValues[0]=0;
 self->currentValues[1]=0;
 self->currentValues[2]=0;
 self->currentValues[3]=0;
 self->currentValues[4]=0;
 self->currentValues[5]=0;
 self->currentValues[6]=0;
 self->currentValues[7]=0;
 self->currentValues[8]=0;
 self->currentValues[9]=0;
 self->currentValues[10]=0;
 self->currentValues[11]=0;
 self->flag=0;
 self->currentValues[0]=(char *)self+0x3e;
 self->currentValues[1]=(char *)self+0x42;
 self->currentValues[2]=(char *)self+0x48;
 self->currentValues[3]=(char *)self+0x50;
 self->currentValues[4]=(char *)self+0x58;
 self->currentValues[5]=(char *)self+0x60;
 self->currentValues[6]=(char *)self+0x66;
 self->currentValues[7]=(char *)self+0x6a;
 self->currentValues[8]=(char *)self+0x6e;
 self->currentValues[9]=(char *)self+0x72;
 self->currentValues[10]=(char *)self+0x76;
 self->currentValues[11]=(char *)self+0x7a;
 self->halfwordPairs0[0]=self->halfwordPairs0[1]=0;
 self->halfwordPairs0[2]=self->halfwordPairs0[3]=0;
 self->wordPairs[0]=self->wordPairs[1]=0;
 self->wordPairs[2]=self->wordPairs[3]=0;
 self->wordPairs[4]=self->wordPairs[5]=0;
 self->wordPairs[6]=self->wordPairs[7]=0;
 self->halfwordPairs1[0]=self->halfwordPairs1[1]=0;
 self->halfwordPairs1[2]=self->halfwordPairs1[3]=0;
 self->halfwordPairs1[4]=self->halfwordPairs1[5]=0;
 self->halfwordPairs1[6]=self->halfwordPairs1[7]=0;
 self->halfwordPairs1[8]=self->halfwordPairs1[9]=0;
 self->halfwordPairs1[11]=0;
 self->halfwordPairs1[10]=*(volatile unsigned short *)&self->halfwordPairs1[11];
}
