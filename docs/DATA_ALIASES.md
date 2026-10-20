# Source data aliases

These fourteen field aliases and local literal labels have no separate owning USA symbol-map entry. They share storage with their owner or accepted runtime function; they add no reconstructed bytes.

## FileIO_LanguageNamePointers

Original: `arm9/main:0x20f0da0`; `data_020f0da0`.

Language pointer order: Japanese, English, French, German, Italian, Spanish. Aliases gFileIOConfiguration.languages.

Original bytes (hex):

```text
7f 0d 0f 02 7c 0d 0f 02 76 0d 0f 02 70 0d 0f 02 73 0d 0f 02 79 0d 0f 02
```

## FileIO_ArchiveSignature

Original: `arm9/main:0x20f0db8`; `data_020f0db8`.

Archive signature: "ARC" followed by NUL; aliases gFileIOConfiguration.archiveSignature.

Original bytes (hex):

```text
41 52 43 00
```

## FileIO_ArchiveRoot

Original: `arm9/main:0x20f0dbc`; `data_020f0dbc`.

Archive root: "arc:/" followed by NUL; aliases gFileIOConfiguration.archiveRoot.

Original bytes (hex):

```text
61 72 63 3a 2f 00
```

## FileIO_LanguageTag

Original: `arm9/main:0x20f0dc2`; `data_020f0dc2`.

Language placeholder: "<LG>" followed by two zero bytes; aliases gFileIOConfiguration.languageTag.

Original bytes (hex):

```text
3c 4c 47 3e 00 00
```

## FileCache_CompressionPrefixSizes

Original: `arm9/main:0x20f2384`; `data_020f2384`.

Two little-endian words {4, 4}; aliases gFileCacheConfiguration.compressionPrefixBytes.

Original bytes (hex):

```text
04 00 00 00 04 00 00 00
```

## FileCache_DataRoot

Original: `arm9/main:0x20f27b8`; `data_020f27b8`.

Root path "data/" followed by zero padding; aliases gFileCacheConfiguration.root.

Original bytes (hex):

```text
64 61 74 61 2f 00 00 00
```

## GPC_RuntimeConfiguration

Original: `arm9/main:0x20f27c0`; `data_020f27c0`.

Five runtime fields: {null revision-number pointer, revision-string pointer, 0, 0, 0}. Startup fills signature fields. Aliases gpcData.runtime.

Original bytes (hex):

```text
00 00 00 00 d4 27 0f 02 00 00 00 00 00 00 00 00 00 00 00 00
```

## GPC_Signature0

Original: `arm9/main:0x20f27e8`; `data_020f27e8`.

"GPC0" followed by zero padding; aliases gpcData.signature0.

Original bytes (hex):

```text
47 50 43 30 00 00 00 00
```

## GPC_Signature1

Original: `arm9/main:0x20f27f0`; `data_020f27f0`.

"GPC1" followed by zero padding; aliases gpcData.signature1.

Original bytes (hex):

```text
47 50 43 31 00 00 00 00
```

## GPC_Signature2

Original: `arm9/main:0x20f27f8`; `data_020f27f8`.

"GPC2" followed by zero padding; aliases gpcData.signature2.

Original bytes (hex):

```text
47 50 43 32 00 00 00 00
```

## OS_TimerOverflowCount

Original: `arm9/main:0x2111640`; `data_02111640`.

64-bit Timer64Bit.numTimerOverflows member at OS_TimerState + 8. Initially zero; updated at runtime.

Initial value: zero-filled; mutable at runtime.

## OS_TimerOverflowCountHighWord

Original: `arm9/main:0x2111644`; `data_02111644`.

Upper 32 bits of OS_TimerOverflowCount, at OS_TimerState + 12. Initially zero; runtime contents are mutable.

Initial value: zero-filled; mutable at runtime.

## Runtime_FloatDivideLiteralBytes

Original: `arm9/main:0x200c274`; `data_0200c274`.

256 literal bytes embedded in the accepted floating-point division routine. Source dcd words preserve all values; this is a local data label, not a separate allocation.

Original bytes (hex):

```text
ff ff fe fd fc fb fa f9 f8 f7 f6 f5 f4 f3 f2 f1 f0 f0 ef ee ed ec eb ea ea e9 e8 e7 e6 e6 e5 e4
e3 e2 e2 e1 e0 df df de dd dc dc db da d9 d9 d8 d7 d7 d6 d5 d4 d4 d3 d2 d2 d1 d0 d0 cf ce ce cd
cc cc cb cb ca c9 c9 c8 c8 c7 c6 c6 c5 c5 c4 c3 c3 c2 c2 c1 c0 c0 bf bf be be bd bd bc bc bb ba
ba b9 b9 b8 b8 b7 b7 b6 b6 b5 b5 b4 b4 b3 b3 b2 b2 b1 b1 b0 b0 af af af ae ae ad ad ac ac ab ab
aa aa aa a9 a9 a8 a8 a7 a7 a7 a6 a6 a5 a5 a4 a4 a4 a3 a3 a2 a2 a2 a1 a1 a0 a0 a0 9f 9f 9e 9e 9e
9d 9d 9d 9c 9c 9b 9b 9b 9a 9a 9a 99 99 99 98 98 98 97 97 96 96 96 95 95 95 94 94 94 93 93 93 92
92 92 91 91 91 91 90 90 90 8f 8f 8f 8e 8e 8e 8d 8d 8d 8c 8c 8c 8c 8b 8b 8b 8a 8a 8a 8a 89 89 89
88 88 88 88 87 87 87 86 86 86 86 85 85 85 85 84 84 84 83 83 83 83 82 82 82 82 81 81 81 81 80 80
```

## Runtime_DoubleDivideLiteralBytes

Original: `arm9/main:0x200d484`; `data_0200d484`.

256 literal bytes embedded in the accepted double-precision division routine. Source dcd words preserve all values; this is a local data label, not a separate allocation.

Original bytes (hex):

```text
ff ff fe fd fc fb fa f9 f8 f7 f6 f5 f4 f3 f2 f1 f0 f0 ef ee ed ec eb ea ea e9 e8 e7 e6 e6 e5 e4
e3 e2 e2 e1 e0 df df de dd dc dc db da d9 d9 d8 d7 d7 d6 d5 d4 d4 d3 d2 d2 d1 d0 d0 cf ce ce cd
cc cc cb cb ca c9 c9 c8 c8 c7 c6 c6 c5 c5 c4 c3 c3 c2 c2 c1 c0 c0 bf bf be be bd bd bc bc bb ba
ba b9 b9 b8 b8 b7 b7 b6 b6 b5 b5 b4 b4 b3 b3 b2 b2 b1 b1 b0 b0 af af af ae ae ad ad ac ac ab ab
aa aa aa a9 a9 a8 a8 a7 a7 a7 a6 a6 a5 a5 a4 a4 a4 a3 a3 a2 a2 a2 a1 a1 a0 a0 a0 9f 9f 9e 9e 9e
9d 9d 9d 9c 9c 9b 9b 9b 9a 9a 9a 99 99 99 98 98 98 97 97 96 96 96 95 95 95 94 94 94 93 93 93 92
92 92 91 91 91 91 90 90 90 8f 8f 8f 8e 8e 8e 8d 8d 8d 8c 8c 8c 8c 8b 8b 8b 8a 8a 8a 8a 89 89 89
88 88 88 88 87 87 87 86 86 86 86 85 85 85 85 84 84 84 83 83 83 83 82 82 82 82 81 81 81 81 80 80
```

## Regional and executable identities

Japanese compatibility macros retain their original regional target symbols. The shared runtime label `data_0200d158` is an executable ABI entry used by `_ull_mod`, and remains accepted runtime support rather than a data object.
