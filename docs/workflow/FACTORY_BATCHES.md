# Function commits and batch pull requests

Each reconstruction worker uses an independent worktree and returns a linear
commit sequence containing exactly its assigned function in the predetermined
unit file, with necessary declarations and delink-map changes. Candidate commits
are pinned under `refs/factory/candidates/`; object matching is not acceptance.
Different functions in one unit can run concurrently.

`tools/rom_inputs.py` provisions `build/factory/inputs.json` with explicit paths to
one verified, read-only ROM and pinned compiler pool. There are no workspace ROM
or compiler copies for revisions supporting this binding. Shared originals have
fixed hashes and are never generated outputs. Extracted assets, compiled objects
and output ROMs remain independent workspace-local files. Older immutable worker
revisions retain their existing input contract until they finish.

After an attempt exits and its result is recorded, Factory pins its Git revision,
archives source differences and text evidence in `.factory/workspace-archives/`,
and removes the registered idle worktree. Session logs and receipts remain in
their durable attempt directories. Active attempts and worktrees required for
pending verification/promotion remain protected until those consumers finish.

The integrator groups up to ten available, independently reviewed candidates in
one branch and one GitHub PR to `Mitchell-Swayn/dqix-decomp`, targeting `main`.
It combines append-only unit edits and disjoint delink blocks. Conflicts that
cannot be combined safely split the batch for individual resolution. Every held
member retains its commit, review and function identity.

Combined acceptance verifies the full ROM, every configured module and symbols,
the original SHA-1, unchanged denominators, exact function/code gains, and the
preservation of all previously accepted isolated C definitions. GitHub receives
a pending/success/failure status for this gate. Only a verified PR tip with an
unchanged base may merge. Factory verifies the GitHub merged tree equals the
locally verified tree before advancing `factory/integration` and refreshing
accepted coverage. A stale base requires revalidation; failed batches grant no
source credit. Token usage is reported only when measured.
