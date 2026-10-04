#pragma dont_inline on
#pragma optimize_for_size off

/* Stop/wait for DMA with IRQ protection. Channel zero is reinitialized to
 * the native fixed-address one-word transfer after completion/reset. */
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
typedef struct { unsigned int source,destination,control; } DmaRegisters;
#define DMA_REGS(n) (*(volatile DmaRegisters*)((n)*12+0x040000b0))
#define DMA_CONTROL(n) (*(volatile unsigned int*)(((n)*3+2)*4+0x040000b0))
#define DMA_HIGH(n) (*(volatile unsigned short*)(((n)*6+5)*2+0x040000b0))
void ARM7_AwaitDmaCompletion(int id)
{
 int state=ARM7_DisableIRQInterrupts();
 while(DMA_CONTROL(id)&0x80000000){}
 if(id==0){
  volatile DmaRegisters *regs=&DMA_REGS(id);
  regs->source=0;
  regs->destination=0;
  regs->control=0x81400001;
 }
 ARM7_SetIRQInterruptState(state);
}
void ARM7_ResetDmaChannel(int id)
{
 int state=ARM7_DisableIRQInterrupts();
 DMA_HIGH(id)&=~0x3200;
 DMA_HIGH(id)&=~0x8000;
 (void)DMA_HIGH(id);
 (void)DMA_HIGH(id);
 if(id==0){
  volatile DmaRegisters *regs=&DMA_REGS(id);
  regs->source=0;
  regs->destination=0;
  regs->control=0x81400001;
 }
 ARM7_SetIRQInterruptState(state);
}
