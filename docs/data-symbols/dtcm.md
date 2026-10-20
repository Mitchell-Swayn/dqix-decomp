# ARM9 dtcm data symbols

Original values describe initialization, not current runtime state. Unresolved semantic roles remain explicit.

## Entry_UnknownRoleProcedureReferenceRecords

Original: `arm9/dtcm:027e0000`; `data_027e0000`.

Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.

Observed span: 96 bytes to the next configured symbol, bounded by the module. This is not a proven object size; aliases can split larger objects and spans can include padding.

Original initialized bytes (hex):

```text
c8 69 0c 02 c8 69 0c 02 c8 69 0c 02 94 6a 0c 02 a4 6a 0c 02 b4 6a 0c 02 c4 6a 0c 02 c8 69 0c 02
54 6a 0c 02 64 6a 0c 02 74 6a 0c 02 84 6a 0c 02 c8 69 0c 02 c8 69 0c 02 c8 69 0c 02 c8 69 0c 02
c8 69 0c 02 c8 69 0c 02 c8 69 0c 02 c8 69 0c 02 c8 69 0c 02 c8 69 0c 02 00 00 00 00 00 00 00 00
```

Observed consumers: `Entry`, `Graphics_InitializeDisplayOnceAndSetHardwareFlag`, `Graphics_ToggleDisplayModeAndSignal`, `OS_InitThread`, `OS_IrqHandler`, `OS_SetIrqStackChecker`, `OSi_DoBoot`, `ScanlineAlarm_HandleVCountInterrupt`, `Startup_ConfigureProtectionCachesAndTcm`, `System_HandleVBlankAndRefreshBrightness`, `WaitForInterruptMaskAndOptionallyClear`, `WfcUtility_RunMainTasksAndSignalControl`, `_Z16WaitForInterruptbj`, `_Z19GetInitialArenaHighi`, `_Z19GetInterruptHandlerj`, `_Z19SetInterruptHandlerjPKv`, `_Z20HandleTimer1Overflowv`, `_Z22OnDMAOrTimerCompletioni`. These references do not establish exclusive ownership.

Relocated values:

- Offset 0: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 4: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 8: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 12: `main:0x20c6a94` (`_Z30Timer0OverflowInterruptHandlerv`).
- Offset 16: `main:0x20c6aa4` (`_Z30Timer1OverflowInterruptHandlerv`).
- Offset 20: `main:0x20c6ab4` (`_Z30Timer2OverflowInterruptHandlerv`).
- Offset 24: `main:0x20c6ac4` (`_Z30Timer3OverflowInterruptHandlerv`).
- Offset 28: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 32: `main:0x20c6a54` (`_Z20DMA0InterruptHandlerv`).
- Offset 36: `main:0x20c6a64` (`_Z20DMA1InterruptHandlerv`).
- Offset 40: `main:0x20c6a74` (`_Z20DMA2InterruptHandlerv`).
- Offset 44: `main:0x20c6a84` (`_Z20DMA3InterruptHandlerv`).
- Offset 48: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 52: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 56: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 60: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 64: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 68: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 72: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 76: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 80: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).
- Offset 84: `main:0x20c69c8` (`_Z21EmptyInterruptHandlerv`).

## OSIrqHandlerThreadSwitch_UnknownRoleZeroInitializedStorage

Original: `arm9/dtcm:027e0060`; `data_027e0060`.

Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.

Observed span: 32 bytes to the next configured symbol, bounded by the module. This is not a proven object size; aliases can split larger objects and spans can include padding.

Initial value: zero-filled BSS. Runtime contents are mutable; no initialized bytes are present in the ROM for this span.

Observed consumers: `OS_IrqHandler_ThreadSwitch`. These references do not establish exclusive ownership.
