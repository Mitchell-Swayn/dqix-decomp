"use strict";

(() => {
  const POLL_MS = 5000;
  const SNAPSHOT_STALE_MS = 30000;
  const HEARTBEAT_STALE_MS = 120000;
  const ACTIVITY_QUIET_MS = 300000;
  const numberFormat = new Intl.NumberFormat("en-US");
  let state = null;
  let inFlight = false;
  let requestError = null;
  let receivedAt = null;
  const byId = (id) => document.getElementById(id);
  const knownNumber = (value) => typeof value === "number" && Number.isFinite(value) && value >= 0;
  const count = (value) => knownNumber(value) ? numberFormat.format(value) : "Unknown";
  const valueText = (value, fallback = "Unknown") => value === null || value === undefined || value === "" ? fallback : String(value);
  const list = (value) => Array.isArray(value) ? value : [];
  const item = (value) => value && typeof value === "object" ? value : {};
  function element(tag, className, text) {
    const node = document.createElement(tag);
    if (className) node.className = className;
    if (text !== undefined) node.textContent = text;
    return node;
  }
  function timestamp(value) {
    if (typeof value !== "string" || !value) return null;
    const parsed = Date.parse(value);
    return Number.isFinite(parsed) ? parsed : null;
  }
  function absoluteTime(value) {
    const parsed = timestamp(value);
    return parsed === null ? "Unknown" : new Date(parsed).toLocaleString(undefined, { month: "short", day: "numeric", hour: "2-digit", minute: "2-digit", second: "2-digit", timeZoneName: "short" });
  }
  function ageText(value) {
    const parsed = timestamp(value);
    if (parsed === null) return "Unknown";
    const seconds = Math.floor((Date.now() - parsed) / 1000);
    if (seconds < -5) return "Clock ahead";
    if (seconds < 5) return "Just now";
    if (seconds < 60) return `${Math.max(0, seconds)}s ago`;
    if (seconds < 3600) return `${Math.floor(seconds / 60)}m ago`;
    if (seconds < 86400) return `${Math.floor(seconds / 3600)}h ago`;
    return `${Math.floor(seconds / 86400)}d ago`;
  }
  function duration(value) {
    if (!knownNumber(value)) return "Elapsed unknown";
    if (value < 60) return `${numberFormat.format(Math.round(value))}s elapsed`;
    const minutes = Math.floor(value / 60);
    if (minutes < 60) return `${minutes}m ${Math.floor(value % 60)}s elapsed`;
    return `${Math.floor(minutes / 60)}h ${minutes % 60}m elapsed`;
  }
  function statusBadge(value) {
    const label = valueText(value, "Status unknown");
    const status = label.toLowerCase();
    let tone = "neutral";
    if (/^(accepted|matched|complete|completed|passed|success|healthy)$/.test(status)) tone = "good";
    else if (/^(running|working|active|compiling|comparing|verifying|claimed|in_progress)$/.test(status)) tone = "busy";
    else if (/^(blocked|deferred|stale|paused|mismatch|unmatched)$/.test(status)) tone = "warn";
    else if (/^(failed|error|rejected)$/.test(status)) tone = "bad";
    return element("span", `badge ${tone}`, label);
  }
  function empty(container, text) {
    container.replaceChildren(element("p", "empty", text));
  }
  function renderMetric(kind, matched, total, noun) {
    const valid = knownNumber(matched) && knownNumber(total) && total > 0 && matched <= total;
    const percent = valid ? matched / total * 100 : null;
    byId(`arm9-${kind}-percent`).textContent = percent === null ? "Unknown" : `${percent.toFixed(2)}%`;
    const progress = byId(`arm9-${kind}-progress`);
    progress.classList.toggle("unknown", !valid);
    progress.firstElementChild.style.width = valid ? `${percent}%` : "0%";
    if (valid) {
      progress.setAttribute("aria-valuemin", "0");
      progress.setAttribute("aria-valuemax", "100");
      progress.setAttribute("aria-valuenow", percent.toFixed(2));
      progress.setAttribute("aria-valuetext", `${percent.toFixed(2)} percent matched`);
    } else {
      progress.removeAttribute("aria-valuenow");
      progress.setAttribute("aria-valuetext", "Coverage unknown");
    }
    const text = byId(`arm9-${kind}-count`);
    text.replaceChildren(element("strong", "", count(matched)), document.createTextNode(` / ${count(total)} ${noun}`));
  }
  function renderCoverage() {
    const coverage = item(state.coverage);
    const arm9 = item(coverage.arm9);
    renderMetric("code", arm9.matched_code, arm9.total_code, "code bytes");
    renderMetric("functions", arm9.matched_functions, arm9.total_functions, "functions");
    renderMetric("data", arm9.matched_data, arm9.total_data, "data bytes");
    byId("accepted-revision").textContent = `Accepted revision ${valueText(coverage.accepted_revision)}`;
    byId("accepted-at").textContent = `Accepted ${absoluteTime(coverage.accepted_at)}`;
    const arm7 = item(coverage.arm7);
    const fields = [
      ["source_functions", "Source functions", ""],
      ["source_code_bytes", "Source instruction bytes", ""],
      ["source_literal_pool_bytes", "Literal pool bytes", ""],
      ["source_data_bytes", "Initialized data bytes", ""],
      ["source_bss_bytes", "BSS bytes", ""],
      ["reviewed_assembly_bytes", "Reviewed assembly bytes", "assembly"],
      ["binary_fallback_bytes", "Original fallback bytes", "fallback"]
    ];
    byId("arm7-counts").replaceChildren(...fields.map(([key, label, className]) => {
      const block = element("div", className);
      block.append(element("dt", "", label), element("dd", "", count(arm7[key])));
      return block;
    }));
  }
  function timeLine(label, value, threshold, staleLabel) {
    const row = element("div", "time-line");
    const parsed = timestamp(value);
    const stale = parsed !== null && Date.now() - parsed > threshold;
    const detail = element("strong", parsed === null ? "missing" : stale ? "stale" : "", `${ageText(value)}${stale ? ` · ${staleLabel}` : ""}`);
    detail.title = absoluteTime(value);
    row.append(element("span", "", label), detail);
    return row;
  }
  function renderWorkers() {
    if (!Array.isArray(state.workers)) {
      byId("worker-count").textContent = "Unknown";
      return empty(byId("worker-grid"), "Worker state unknown.");
    }
    const workers = list(state.workers);
    byId("worker-count").textContent = count(workers.length);
    const container = byId("worker-grid");
    if (!workers.length) return empty(container, "No workers recorded. Worker activity appears here when reported.");
    container.replaceChildren(...workers.map((raw) => {
      const worker = item(raw);
      const card = element("article", "panel worker-card");
      const top = element("div", "worker-top");
      top.append(element("h3", "worker-name", valueText(worker.id, "Worker unknown")), statusBadge(worker.status));
      const times = element("div", "worker-times");
      times.append(timeLine("Heartbeat", worker.updated_at, HEARTBEAT_STALE_MS, "stale"), timeLine("Task activity", worker.activity_at, ACTIVITY_QUIET_MS, "quiet"));
      const path = element("div", "worker-path", valueText(worker.worktree, "Worktree unknown"));
      path.title = valueText(worker.worktree, "Worktree unknown");
      card.append(top, element("p", "worker-model", `Model · ${valueText(worker.model)}`), element("p", "worker-task", valueText(worker.task, "Task not reported")), path, times);
      return card;
    }));
  }
  function refreshFilters() {
    const select = byId("job-filter");
    const previous = select.value;
    const statuses = [...new Set(list(state.jobs).map((raw) => valueText(item(raw).status, "Status unknown")))].sort();
    const all = element("option", "", "All statuses");
    all.value = "";
    select.replaceChildren(all, ...statuses.map((status) => {
      const option = element("option", "", status);
      option.value = status;
      return option;
    }));
    // Keep a selected status when its last matching job has just left the queue.
    if (previous && !statuses.includes(previous)) {
      const option = element("option", "", previous);
      option.value = previous;
      select.append(option);
    }
    select.value = previous;
  }
  function renderJobs() {
    if (!state) return;
    if (!Array.isArray(state.jobs)) {
      byId("job-count").textContent = "Unknown";
      byId("job-result-count").textContent = "Queue state unknown";
      const row = element("tr");
      const cell = element("td", "empty", "Queue state unknown.");
      cell.colSpan = 3;
      row.append(cell);
      byId("job-rows").replaceChildren(row);
      return;
    }
    const jobs = list(state.jobs);
    const filter = byId("job-filter").value;
    const search = byId("job-search").value.trim().toLowerCase();
    const shown = jobs.filter((raw) => {
      const job = item(raw);
      return (!filter || valueText(job.status, "Status unknown") === filter) && (!search || [job.id, job.scope, job.owner].some((value) => valueText(value, "").toLowerCase().includes(search)));
    });
    byId("job-count").textContent = count(jobs.length);
    byId("job-result-count").textContent = `${count(shown.length)} of ${count(jobs.length)} jobs shown`;
    const rows = byId("job-rows");
    if (!shown.length) {
      const row = element("tr");
      const cell = element("td", "empty", jobs.length ? "No jobs match these filters." : "No jobs recorded in the queue.");
      cell.colSpan = 3;
      row.append(cell);
      rows.replaceChildren(row);
      return;
    }
    rows.replaceChildren(...shown.map((raw) => {
      const job = item(raw);
      const row = element("tr");
      const scope = element("td");
      scope.append(element("div", "job-scope", valueText(job.scope, "Scope unknown")), element("div", "job-id", valueText(job.id, "ID unknown")));
      const status = element("td");
      status.append(statusBadge(job.status));
      row.append(scope, status, element("td", "", valueText(job.owner, "Unassigned")));
      return row;
    }));
  }
  function meta(parts) {
    const node = element("div", "record-meta");
    node.append(...parts.map((text) => element("span", "", text)));
    return node;
  }
  function recent(records, key) {
    return records.slice().sort((a, b) => (timestamp(item(b)[key]) ?? -Infinity) - (timestamp(item(a)[key]) ?? -Infinity));
  }
  function renderAttempts() {
    if (!Array.isArray(state.attempts)) {
      byId("attempt-count").textContent = "Unknown";
      return empty(byId("attempt-list"), "Attempt state unknown.");
    }
    const attempts = list(state.attempts);
    byId("attempt-count").textContent = attempts.length > 12 ? `Latest 12 of ${count(attempts.length)}` : count(attempts.length);
    const container = byId("attempt-list");
    if (!attempts.length) return empty(container, "No candidate attempts recorded.");
    container.replaceChildren(...recent(attempts, "started_at").slice(0, 12).map((raw) => {
      const attempt = item(raw);
      const record = element("div", "record");
      const top = element("div", "record-top");
      top.append(element("h4", "record-title", valueText(attempt.unit, "Unit unknown")), statusBadge(attempt.status));
      const result = element("div", "attempt-result");
      const match = knownNumber(attempt.match_percent) && attempt.match_percent <= 100 ? `${attempt.match_percent.toFixed(2)}% match` : "Match unknown";
      result.append(element("strong", "", match), element("span", "", duration(attempt.elapsed_seconds)));
      const tags = element("div", "tags");
      tags.append(...list(attempt.categories).map((category) => element("span", "tag", valueText(category))));
      record.append(top, meta([valueText(attempt.worker, "Worker unknown"), absoluteTime(attempt.started_at), valueText(attempt.id, "ID unknown")]), result);
      if (tags.childElementCount) record.append(tags);
      return record;
    }));
  }
  function delta(value, label) {
    const span = element("span");
    const valid = typeof value === "number" && Number.isFinite(value);
    const text = valid ? `${value > 0 ? "+" : ""}${numberFormat.format(value)}` : "Unknown";
    span.append(element("strong", valid && value < 0 ? "negative" : "", text), document.createTextNode(label));
    return span;
  }
  function renderBatches() {
    if (!Array.isArray(state.batches)) {
      byId("batch-count").textContent = "Unknown";
      return empty(byId("batch-list"), "Accepted batch state unknown.");
    }
    const batches = list(state.batches);
    byId("batch-count").textContent = count(batches.length);
    const container = byId("batch-list");
    if (!batches.length) return empty(container, "No accepted batches recorded.");
    container.replaceChildren(...recent(batches, "utc").map((raw) => {
      const batch = item(raw);
      const record = element("div", "record");
      const top = element("div", "record-top");
      top.append(element("h4", "record-title", valueText(batch.name, "Batch unknown")), statusBadge("accepted"));
      const deltas = element("div", "deltas");
      deltas.append(delta(batch.arm9_code_delta, "ARM9 code bytes"), delta(batch.arm9_functions_delta, "ARM9 functions"), delta(batch.arm7_code_delta, "ARM7 code bytes"));
      record.append(top, meta([absoluteTime(batch.utc), duration(batch.elapsed_seconds)]), deltas);
      return record;
    }));
  }
  function renderHealth() {
    const messages = [];
    if (requestError) messages.push(state ? `Connection interrupted. Showing the last received state; ${requestError}` : `State unavailable; ${requestError}`);
    const generated = timestamp(state?.generated_at);
    const stale = state && (generated === null || Date.now() - generated > SNAPSHOT_STALE_MS);
    if (stale) messages.push(generated === null ? "Snapshot timestamp unknown. Freshness cannot be verified." : `Snapshot is stale (${ageText(state.generated_at)}). Accepted coverage and worker activity may be out of date.`);
    if (state) for (const warning of list(state.warnings)) messages.push(valueText(warning));
    const notice = byId("notice");
    notice.hidden = !messages.length;
    notice.classList.toggle("error", Boolean(requestError));
    notice.replaceChildren(...messages.map((text) => element("p", "", text)));
    byId("connection").className = `badge ${requestError ? "bad" : stale ? "warn" : state ? "good" : "neutral"}`;
    byId("connection-text").textContent = requestError ? "Disconnected" : stale ? "Stale snapshot" : state ? "Live state" : "Connecting";
    byId("last-refresh").textContent = receivedAt === null ? "Waiting for state" : `Received ${ageText(new Date(receivedAt).toISOString())}`;
    byId("last-refresh").title = receivedAt === null ? "" : absoluteTime(new Date(receivedAt).toISOString());
  }
  function renderState() {
    renderCoverage();
    renderWorkers();
    refreshFilters();
    renderJobs();
    renderAttempts();
    renderBatches();
    byId("state-revision").textContent = `State revision ${valueText(state.revision)}`;
    renderHealth();
  }
  async function poll() {
    if (inFlight) return;
    inFlight = true;
    const controller = new AbortController();
    const timeout = setTimeout(() => controller.abort(), 8000);
    try {
      const response = await fetch("/api/state", { cache: "no-store", signal: controller.signal, headers: { Accept: "application/json" } });
      if (!response.ok) throw new Error(`HTTP ${response.status}`);
      const payload = await response.json();
      if (!payload || typeof payload !== "object" || Array.isArray(payload)) throw new Error("Invalid state response");
      state = payload;
      receivedAt = Date.now();
      requestError = null;
      renderState();
    } catch (error) {
      requestError = error.name === "AbortError" ? "request timed out. Retrying every 5s." : `${error.message || "Request failed"}. Retrying every 5s.`;
      renderHealth();
    } finally {
      clearTimeout(timeout);
      inFlight = false;
    }
  }
  byId("job-search").addEventListener("input", renderJobs);
  byId("job-filter").addEventListener("change", renderJobs);
  poll();
  setInterval(poll, POLL_MS);
  setInterval(() => { renderHealth(); if (state) renderWorkers(); }, 1000);
})();
