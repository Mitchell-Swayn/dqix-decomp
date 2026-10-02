# World script array list

This batch reconstructs the fixed-capacity `WorldScriptArrayList` operations at
ARM9 addresses `0x0208d82c`, `0x0208d8ec`, `0x0208d928`, and `0x0208d994`.
The shared declarations assert the observed 24-byte entry and 16-byte list
sizes. Disassembly shows the list fields, `capacity * 0x18` allocation,
24-byte append copy, and signed 16-bit key scan.

All four candidate objects compare at 1/1 symbols and 100%. Their linked map
contains only the four expected function definitions from their respective
units; there are no additional `WorldScriptArrayList` helper globals. Coverage
changed from 212,992 to 213,284 matched ARM9 code bytes and from 1,577 to 1,581
matched functions. This is +292 code bytes and +4 functions.

The first full build made during a separate five-variant experiment on
`func_0208df20` showed `func_0208df94` and subsequent main symbols shifted by
`0x20`. After saving the array-list patch and restoring the pre-batch source
and delinks, full ROM checks passed. Restoring only the four array-list units
and their delinks also passed. The baseline map assigns `func_0208df20` to
fallback `main_83.o` with size `0x74`, ending at `0x0208df94`; the current
delinks assign the next function `WorldScriptRecordListAppend` at that address.
This is consistent with the discarded loader experiment having introduced the
shift, but does not by itself prove which edit caused it. The loader remains
unowned and receives no coverage credit.

Validation: each unit matched 1/1 symbols at 100%; `ninja rom check report
sha1` passed all checks; generated USA ROM SHA-1 is
`c7c3014c237900c8281289b8bc76a781969b6278`. The exact-object artifacts,
baseline log, candidate-only log, and failed experimental log are retained
under ignored `build/`.
\n