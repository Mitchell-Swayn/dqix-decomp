# Function database

The SQLite snapshot is generated at `build/call-graph/functions.sqlite`. It has
one function row per inventoried graph node, retaining processor/module identity
when overlays reuse addresses. It does not replace coverage reports or the queue.

Generate after the original-ROM extraction and full build acceptance:

```powershell
.venv/Scripts/python.exe tools/call_graph.py
.venv/Scripts/python.exe tools/function_database.py
.venv/Scripts/python.exe -m unittest discover -s tools -p test_function_database.py
```

The exporter validates graph input hashes and the original USA ROM SHA-1, builds
a new database transactionally, checks integrity and foreign keys, and replaces
the prior snapshot only on success. It never modifies ROM inputs or source files.
Do not put notes or manual edits in this generated snapshot; regeneration replaces
it. SQLite itself needs no extra Python package; extraction uses capstone and
pyelftools already used by the graph tools.

## Tables

| Table | Contents |
|---|---|
| `functions` | Function name, module, runtime address, mode, size, original assembly/bytes/hash, lineage depth, recursive group, uncertainty flags, source status and isolated completed C/C++ definition |
| `relationships` | Caller/callee function IDs, call or tail-branch kind, possible-overlay ambiguity |
| `call_sites` | Original instruction addresses for each relationship |
| `unresolved_calls` | Indirect and uninventoried direct targets; nullable caller where its inventory is missing |
| `dependency_groups` | Recursive groups and their dependency layers |
| `sources` | Actual source file contents, language and hashes, retained once for context |
| `modules` | Original executable-module addresses, sizes and hashes, including modules with no functions |
| `metadata` | Input hashes, source revision, dirty-tree flag, report hashes, extraction diagnostics, completion policy and graph limitations |

Views: `decompilation_order`, `remaining_functions`, and `named_relationships`.
Each layer is one greater than its deepest callee group; recursive members share
a layer. These are known static dependencies, not exhaustive runtime lineage.
The incomplete ARM7 inventory and unresolved targets remain explicit.

## Assembly and completed source

Assembly comes from original extracted modules, never candidate instructions.
PC-relative literal pools have data directives. Bytes not reached by bounded
control-flow traversal are explicitly marked unclassified; computed dispatch
can reach instructions that this static walk cannot discover. Full original
bytes are retained independently. Zero-sized symbols have empty assembly and
bytes because their extents are not known.

`decompiled_c` contains actual isolated source definitions, not pseudocode.
Compiler debug relocations associate exact mangled symbols with source locations,
including overloaded functions. This reads MWCC's ARM RELA debug records without
rewriting original or candidate objects. Declaration lines are used to extract
balanced function bodies while ignoring braces inside comments/strings.

For ARM9, source must own a declared-complete range and its report function must
match 100%. ARM7 requires its source hash and module/symbol verification.
`completion_status` distinguishes `completed`, `undecompiled`, `source_incomplete`,
`reviewed_assembly`, `mixed_source`, and `completed_source_unextracted`.
Reviewed assembly and matching mixed C/assembly are not presented as pure C.
For compiler-generated operators, destructors or initialization functions with
no isolatable definition, C remains NULL and the actual owning file is available
through `sources`; this does not mean the verified source unit is absent.
The source snippets are not self-contained compilable units: types, macros and
interfaces may require headers in the project.

## Queries

```sql
-- Examine the depth-3 example discussed in chat.
SELECT name, assembly, lineage_depth, completion_status, decompiled_c
FROM functions WHERE module_id='arm9/main' AND address=0x0206E31C;

-- Reconstructed random-number generator.
SELECT assembly, decompiled_c FROM functions
WHERE name='_Z10NextRandomP6Random';

-- Its callees and their reconstruction state.
SELECT f.name, f.lineage_depth, f.completion_status, r.kind, s.instruction_address
FROM relationships r JOIN functions f ON f.id=r.callee_id
JOIN call_sites s ON s.relationship_id=r.id
WHERE r.caller_id='arm9/main:0206e31c';

-- Candidate functions ordered by known dependency context.
SELECT * FROM remaining_functions
ORDER BY lineage_depth, dependency_group_id, id;
```

The graph viewer has a SQLite download link. On the configured Tailscale server,
it is `http://100.83.138.42:8899/functions.sqlite`. The database can be downloaded
on the Mac and opened with its `sqlite3` command or a SQLite viewer.

The server can be started with an explicit local bind address:

```powershell
node tools/call_graph_server.cjs C:/Users/swayn/Projects/DQIX-Decomp/build/call-graph 100.83.138.42 8899
```

Only the four generated public artifacts are served; logs and other files in the
output directory are not exposed. Availability ends when that server or Windows
machine stops. No cloud hosting is required.
