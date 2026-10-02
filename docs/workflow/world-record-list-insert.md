# World script record-list reset and append

Branch `work/luna-world-record-next`, based on integrated main `96b1293ddc6b62e5b01ae6a8d745e02cb2bc79e1`.

Reconstructed `func_0208df10` (16 bytes) and `func_0208df94` (108 bytes) using the shared `WorldScriptRecordNode` and a `WorldScriptRecordList` header. The list has its head pointer at +0 and signed count at +4; compile-time typedef checks require the node and list to be 12 and 8 bytes respectively. Reset clears head and count. Append allocates one 12-byte node through `SafeAllocator`, copies it with `func_0208e000`, links it at the tail, and increments the count. The target has no allocation-failure branch, which the matching source preserves.

Callers establish the interface: `func_ov013_02186eec` resets the list at object +0x0c during setup, and another overlay-13 path resets that same member on state 4. `func_0208dc84` calls append using the list pointer and allocator stored in `data_02108fd4` at +8 and +0xc, and passes a stack-built record. Append traverses the shared node's +8 link and updates the list's signed halfword count.

Both objects matched 1/1 symbols at 100% on the first candidate. This removes 124 bytes of fallback code across two functions; no data/literal/BSS credit or denominator change. Full `ninja rom check report sha1` passed, including module and symbol checks, ARM7 baseline, and guarded ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`, equal to the verified input. Inputs and outputs are separate files. The batch started at 2026-10-02 12:33:22.937 UTC and `tools/work_batch.py` recorded 66.49 seconds to acceptance. Token usage was not measured. Verbose logs remain under ignored `build/workflow/world-record-list-insert/` and `build/matching/`.
