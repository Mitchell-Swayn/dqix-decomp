# Local reconstruction factory

Start the web monitor from the project root:

```powershell
powershell -ExecutionPolicy Bypass -File tools/start_factory.ps1
```

Open **http://127.0.0.1:8765**. It binds to loopback only, uses no CDN or remote
service, and has a read-only HTTP API. Logs and SQLite state live under ignored
`build/factory/`. The dashboard refreshes every five seconds. Restarting the
server preserves jobs and experiments. It must be running for live updates;
closing the browser does not stop the server.

For this workstation's LAN interface, start with
`powershell -ExecutionPolicy Bypass -File tools/start_factory.ps1 -BindAddress 192.168.1.49`
and open **http://192.168.1.49:8765** from another device on the same network.
The configured Windows rule `DQIX-Factory-LAN-8765` permits TCP 8765 on that
address through the private Ethernet 2 interface from LocalSubnet only. If DHCP
changes the workstation address, update both the bind address and firewall rule.
This is a read-only, unauthenticated LAN monitor; no internet forwarding is set up.

## What the display means

- Accepted coverage comes from main's archived `pilot-*-finish.json` evidence.
  Worker reports and live build reports never replace that accepted snapshot.
  The acceptance timestamp and revision identify exactly what was recorded;
  the server does not rerun ROM checks on each refresh.
- ARM9 report code includes its existing assembly. ARM7 instructions, literals,
  initialized data, BSS, assembly and fallback remain separate. ARM7's complete
  code/function denominator is unknown. Coverage is not effort completion.
- Existing queue owners appear with **unknown** status until they send a heartbeat.
  Attempt timestamps are evidence of past activity, not agent liveness.
  A running/idle heartbeat older than three minutes becomes **stale**.
- Successful dispatched commands enter **review**, never accepted/integrated.
  The root integrator still reviews source and runs full ROM/module/symbol/SHA1
  checks before archiving acceptance. No automatic merge is performed.
- Cost and token use are not inferred. Existing `measure_agent_tokens.py` remains
  the separate source for measured token windows.

## Experiments and function evidence

The monitor imports `build/matching/attempts.jsonl` from registered Git worktrees
into a persistent SQLite experiment index. Entries are deduplicated by worktree
and attempt ID. Existing ARM7 pipeline results do not use this ARM9 ledger;
ARM7 workers should send heartbeats and retain their distinct pipeline evidence.

New ARM9 experiments preserve candidate source snapshots and hypotheses:

```powershell
.venv/Scripts/python.exe tools/match_unit.py src/System/RuntimeRandom --hypothesis 'test unsigned accumulator' --worker sol61_library --job random-family
.venv/Scripts/python.exe tools/factory_evidence.py --root . --unit src/System/RuntimeRandom --output build/factory/random-evidence.json
.venv/Scripts/python.exe tools/factory_diff.py build/matching/ATTEMPT/diff.json --output build/factory/diagnosis.json
```

The diagnosis labels observed stack/register/control-flow/immediate/relocation
differences heuristically; it does not prove their cause or semantic equivalence.
Function packages disclose unavailable information. They do not invent Ghidra
pseudocode. Headless Ghidra is a future adapter, not a dependency of this release.
The ten-variant cap remains a coordinator obligation: old attempts without source
snapshots and repeated verification builds cannot reliably be counted as unique
source hypotheses automatically.

## Worker heartbeats

Workers may invoke the main checkout's tool without modifying its source:

```powershell
.venv/Scripts/python.exe tools/factory.py heartbeat sol61_arm7 --model gpt-6.1-sol --status running --task 'Touch filter family' --worktree C:/Users/swayn/Projects/DQIX-Decomp-arm7-power-events
```

Send at start, roughly every two minutes, and on finish (`review`, `failed` or
`interrupted`). Direct chat agents are not controlled by this HTTP server; their
heartbeats are explicit instrumentation. The dispatcher below maintains its own
heartbeats while commands run.

## Durable command dispatcher

The runner executes explicitly configured argument arrays without a shell. It
does not acquire model credentials, buy API usage, or guess an agent command.
First create and prepare an independent worker worktree using the existing ROM
isolation rules. Never queue main or a worktree already used by a chat worker.
Prepare a local JSON file containing the exact executable and arguments for the
installed worker backend. Use a verified non-interactive command that exits when
its bounded job finishes; pass the task through the backend's supported mechanism.

```powershell
.venv/Scripts/python.exe tools/factory.py enqueue batch-example --scope 'bounded function family' --worktree C:/path/to/prepared-worker --command-json build/factory/worker-command.json
.venv/Scripts/python.exe tools/factory.py worker runner-1 --model gpt-6.1-sol --once
```

Omit `--once` for a persistent consumer. Separate consumers can run concurrently;
SQLite atomically assigns jobs and prevents two running jobs sharing a worktree.
Default job timeout is 1800 seconds (`--timeout` overrides it). Command output is
stored under `build/factory/logs/`. Exit zero means ready for review, not matching.

Expired claims become stale and block reuse of their worktree. They are never
automatically retried because an orphan process might still be writing files.
After verifying the old process and descendants have stopped, retry explicitly:

```powershell
.venv/Scripts/python.exe tools/factory.py retry batch-example --confirmed-stopped
```

This release provides a tested local dispatcher and monitor. It does not increase
the chat session's agent limit, schedule new model sessions by itself, or claim
that a large unattended fleet has been launched. Current chat workers can keep
working alongside it in separately owned worktrees.
