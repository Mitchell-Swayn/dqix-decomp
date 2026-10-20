# Runtime protection subsystem

The runtime protection subsystem contains callback gates, cartridge and hardware-configuration probes, instruction-signature checks, and encoded execution support. `Protection_` identifies the observed mechanism; no specific protection vendor or gameplay penalty is established.

## Ownership and source organization

Matched compilation units live in `src/System/Protection/<module>/`. Module identity remains part of the path and provenance because overlay addresses overlap. Units remain separate; their ABI, types, instructions, literals and callbacks are unchanged. The script opcode handler is protection-specific and remains in this subsystem rather than the generic script interpreter.

`config/usa/protection_symbols.json` is the address-qualified inventory of 66 routines and entry points: 18 protected entries, 18 encoded bodies, 12 execution helpers, five initialization routines and 13 startup/script adapters. It records source paths where matched source exists. `analysis-identity` entries have no independent build symbol; their names describe decoded code inside the original payload and do not count as decompiled functions. Initializer ABI symbols are preserved.

## Entry points and behavior

Startup (`arm9/main:02000C9C`) calls three gates from overlay29. Gate results select loader initialization paths; the exact gameplay consequence is not established. Main retains its existing name and ownership.

Script opcode `0x32F` (815) maps to `Script_CheckRuntimeProtection` at `arm9/ov001:02162338`; its handler/id pair is at `arm9/ov001:02165444`. When enabled, the handler loads overlay29 and invokes the three script gates. It checks the wrapper tokens and a callback counter of at least six, writes the script result, clears the counter and releases the overlay slot. Result zero is success; one is failure. The handler completion return is a separate value.

The three script wrappers invoke an optional callback and return fixed numeric tokens `0x001BF27F`, `0x001BEFCB` and `0x001BEB10`. Existing nominal return types, including `void *`, are retained; the caller compares tokens rather than dereferencing the value. Counter callbacks add one, two and three to the word at `arm9/ov001:021658A8`.

## Protected execution

Five overlay29 initializers decode ranges with an XOR/ARM-branch transformation. Protected entries then decode an inner body, execute it and re-encode it. The transformed code remains in its original `.rodata` payload. Entry wrappers and inner bodies have separate identities.

The probes compare instruction signatures, examine MAC/configuration patterns, and compare direct cartridge reads with SDK reads. Gates accumulate probe results and use predicates modulo 199 (startup) or 173 (script) before invoking the supplied wrapper. Startup/script name suffixes describe established call sites and do not prove exclusive use.

The cartridge checksum uses polynomial `0xEDB88320`, but its conditional XOR uses a zero low bit. It is named `ComputeInvertedBitTestChecksum`, not ordinary CRC32. Direct reads use hardware command `0xB7` and restore the saved card command/register state.

## Naming inventory

| Identity | Name | Representation |
|---|---|---|
| arm9/main:020D6BAC | `Protection_InvokeCallbackAndReturnCartridgeStartupToken` | matched-source |
| arm9/main:020D6BC8 | `Protection_InvokeCallbackAndReturnConfigurationStartupToken` | matched-source |
| arm9/main:020D6BE4 | `Protection_InvokeCallbackAndReturnConstantStartupToken` | matched-source |
| arm9/main:020D6C0C | `Protection_InitializeOverlay34Loader` | live-symbol |
| arm9/main:020D6C34 | `Protection_EnsureOverlay34LoaderForConfigurationGate` | live-symbol |
| arm9/main:020D6C68 | `Protection_EnsureOverlay34LoaderForConstantGate` | live-symbol |
| arm9/ov001:0215A6FC | `Protection_InvokeCallbackAndReturnCartridgeScriptToken` | matched-source |
| arm9/ov001:0215A718 | `Protection_InvokeCallbackAndReturnConfigurationScriptToken` | matched-source |
| arm9/ov001:0215A734 | `Protection_InvokeCallbackAndReturnConstantScriptToken` | matched-source |
| arm9/ov001:021622F0 | `Protection_AddOneToScriptCheckCounter` | matched-source |
| arm9/ov001:02162308 | `Protection_AddTwoToScriptCheckCounter` | matched-source |
| arm9/ov001:02162320 | `Protection_AddThreeToScriptCheckCounter` | matched-source |
| arm9/ov001:02162338 | `Script_CheckRuntimeProtection` | live-symbol |
| arm9/ov029:021D8A40 | `Protection_EvaluateCartridgeGateForStartup` | analysis-identity |
| arm9/ov029:021D8AE4 | `Protection_EvaluateCartridgeGateForScript` | analysis-identity |
| arm9/ov029:021D8B94 | `Protection_EvaluateHardwareConfigurationGateForStartup` | analysis-identity |
| arm9/ov029:021D8C38 | `Protection_EvaluateHardwareConfigurationGateForScript` | analysis-identity |
| arm9/ov029:021D8CE8 | `Protection_EvaluateConstantGateForStartup` | analysis-identity |
| arm9/ov029:021D8D7C | `Protection_EvaluateConstantGateForScript` | analysis-identity |
| arm9/ov029:021D8E1C | `Protection_InvokeCartridgeGateForStartup` | live-symbol |
| arm9/ov029:021D8E94 | `Protection_InvokeCartridgeGateForScript` | live-symbol |
| arm9/ov029:021D8F0C | `Protection_InvokeHardwareConfigurationGateForStartup` | live-symbol |
| arm9/ov029:021D8F84 | `Protection_InvokeHardwareConfigurationGateForScript` | live-symbol |
| arm9/ov029:021D8FFC | `Protection_InvokeConstantGateForStartup` | live-symbol |
| arm9/ov029:021D9074 | `Protection_InvokeConstantGateForScript` | live-symbol |
| arm9/ov029:021D90EC | `__sinit_ov029_021d90ec` | preserved-initializer |
| arm9/ov029:021D9138 | `Protection_CheckStartupConfigurationEntrySignatureBody` | analysis-identity |
| arm9/ov029:021D9254 | `Protection_CheckScriptConfigurationEntrySignatureBody` | analysis-identity |
| arm9/ov029:021D9370 | `Protection_CheckStartupCartridgeEntrySignatureBody` | analysis-identity |
| arm9/ov029:021D948C | `Protection_CheckScriptCartridgeEntrySignatureBody` | analysis-identity |
| arm9/ov029:021D95A8 | `Protection_CheckStartupConfigurationEntrySignature` | analysis-identity |
| arm9/ov029:021D9620 | `Protection_CheckScriptConfigurationEntrySignature` | analysis-identity |
| arm9/ov029:021D9698 | `Protection_CheckStartupCartridgeEntrySignature` | analysis-identity |
| arm9/ov029:021D9710 | `Protection_CheckScriptCartridgeEntrySignature` | analysis-identity |
| arm9/ov029:021D9788 | `__sinit_ov029_021d9788` | preserved-initializer |
| arm9/ov029:021D97C0 | `Protection_SynchronizeCodeCaches` | analysis-identity |
| arm9/ov029:021D97E8 | `Protection_ClassifyArmBranchInstruction` | analysis-identity |
| arm9/ov029:021D9824 | `Protection_DecodeInitialCodeRanges` | analysis-identity |
| arm9/ov029:021D990C | `Protection_DecodeProtectedBody` | analysis-identity |
| arm9/ov029:021D9994 | `Protection_ReencodeProtectedBody` | analysis-identity |
| arm9/ov029:021D9A24 | `__sinit_ov029_021d9a24` | preserved-initializer |
| arm9/ov029:021D9A4C | `Protection_ProbeHardwareConfigurationForStartupBody` | analysis-identity |
| arm9/ov029:021D9AF0 | `Protection_ProbeHardwareConfigurationForScriptBody` | analysis-identity |
| arm9/ov029:021D9B94 | `Protection_ProbeHardwareConfigurationForStartup` | analysis-identity |
| arm9/ov029:021D9C0C | `Protection_ProbeHardwareConfigurationForScript` | analysis-identity |
| arm9/ov029:021D9C84 | `Protection_ReadCartridgeBytesDirectBody` | analysis-identity |
| arm9/ov029:021D9DD8 | `Protection_ComputeInvertedBitTestChecksumBody` | analysis-identity |
| arm9/ov029:021D9E6C | `Protection_ReadCartridgeBytesDirect` | analysis-identity |
| arm9/ov029:021D9EE4 | `Protection_ComputeInvertedBitTestChecksum` | analysis-identity |
| arm9/ov029:021D9F5C | `Protection_ProbeCartridgeReadsForStartupBody` | analysis-identity |
| arm9/ov029:021DA06C | `Protection_ProbeCartridgeReadsForScriptBody` | analysis-identity |
| arm9/ov029:021DA17C | `Protection_ProbeCartridgeReadsForStartup` | analysis-identity |
| arm9/ov029:021DA1F4 | `Protection_ProbeCartridgeReadsForScript` | analysis-identity |
| arm9/ov029:021DA26C | `Protection_ReturnStartupProbeConstantBody` | analysis-identity |
| arm9/ov029:021DA278 | `Protection_ReturnScriptProbeConstantBody` | analysis-identity |
| arm9/ov029:021DA284 | `Protection_ReturnStartupProbeConstant` | analysis-identity |
| arm9/ov029:021DA2FC | `Protection_ReturnScriptProbeConstant` | analysis-identity |
| arm9/ov029:021DA374 | `__sinit_ov029_021da374` | preserved-initializer |
| arm9/ov029:021DA3CC | `Protection_InitializeStreamPermutation` | analysis-identity |
| arm9/ov029:021DA458 | `Protection_GenerateStreamByte` | analysis-identity |
| arm9/ov029:021DA4B0 | `Protection_InitializeByteComplementTable` | analysis-identity |
| arm9/ov029:021DA4E8 | `Protection_EncodeArmInstructionStream` | analysis-identity |
| arm9/ov029:021DA5FC | `Protection_DecodeArmInstructionStream` | analysis-identity |
| arm9/ov029:021DA784 | `Protection_EncodeProtectedRange` | analysis-identity |
| arm9/ov029:021DA7E4 | `Protection_DecodeProtectedRange` | analysis-identity |
| arm9/ov029:021DA844 | `__sinit_ov029_021da844` | preserved-initializer |

## Boundary and limitations

Generic overlay loading, SDK card locks/reads, MAC/configuration readers, script parameter/result helpers and the opcode-table builder remain shared dependencies. Neighboring zone script commands are outside this subsystem.

Analysis is static; emulator/hardware execution and all possible indirect consumers are not established. The registry records decoded addresses for navigation without introducing function symbols into encoded bytes or changing coverage denominators.
