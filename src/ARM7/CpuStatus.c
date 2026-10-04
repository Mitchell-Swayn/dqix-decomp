/* Necessary CPU-status access: ordinary C cannot read or write CPSR.
 * The whole routines are classified as reviewed assembly exceptions, including
 * compiler-generated masks/returns. See ../assembly_exceptions.json.
 * Original assembly authorship has not been established. */

int ARM7_EnableIRQInterrupts(void) {
    int oldState;
    int newState;
    __asm("mrs oldState, cpsr");
    newState = oldState & ~0x80;
    __asm("msr cpsr_c, newState");
    return oldState & 0x80;
}

int ARM7_DisableIRQInterrupts(void) {
    int oldState;
    int newState;
    __asm("mrs oldState, cpsr");
    newState = oldState | 0x80;
    __asm("msr cpsr_c, newState");
    return oldState & 0x80;
}

int ARM7_SetIRQInterruptState(int state) {
    int oldState;
    int newState;
    __asm("mrs oldState, cpsr");
    newState = oldState & ~0x80;
    newState |= state;
    __asm("msr cpsr_c, newState");
    return oldState & 0x80;
}

int ARM7_DisableIRQAndFIQInterrupts(void) {
    int oldState;
    int newState;
    __asm("mrs oldState, cpsr");
    newState = oldState | 0xc0;
    __asm("msr cpsr_c, newState");
    return oldState & 0xc0;
}

int ARM7_SetIRQAndFIQInterruptState(int state) {
    int oldState;
    int newState;
    __asm("mrs oldState, cpsr");
    newState = oldState & ~0xc0;
    newState |= state;
    __asm("msr cpsr_c, newState");
    return oldState & 0xc0;
}

int ARM7_GetProcessorMode(void) {
    int state;
    __asm("mrs state, cpsr");
    return state & 0x1f;
}
