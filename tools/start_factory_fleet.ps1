param([string]$ConfigPath = '')
$ErrorActionPreference = 'Stop'
$projectRoot = Split-Path -Parent $PSScriptRoot
if (-not $ConfigPath) { $ConfigPath = Join-Path $projectRoot 'build/factory/fleet-config.json' }
$ConfigPath = (Resolve-Path -LiteralPath $ConfigPath).Path
$pythonExe = Join-Path $projectRoot '.venv/Scripts/python.exe'
$fleetScript = Join-Path $PSScriptRoot 'factory_fleet.py'
$logDirectory = Join-Path $projectRoot 'build/factory'
if (Test-Path -LiteralPath (Join-Path $logDirectory 'STOP')) {
    throw 'Fleet STOP marker exists. Remove it only when intentionally resuming new batches.'
}
$statePath = Join-Path $logDirectory 'fleet.json'
if (Test-Path -LiteralPath $statePath) {
    $old = Get-Content -LiteralPath $statePath -Raw | ConvertFrom-Json
    $existing = Get-CimInstance Win32_Process -Filter "ProcessId = $($old.supervisor_pid)"
    if ($existing -and $existing.CommandLine -like '*factory_fleet.py*') {
        Write-Output "Fleet supervisor already running (PID $($old.supervisor_pid))."
        exit 0
    }
}
$process = Start-Process -FilePath $pythonExe -ArgumentList @('"' + $fleetScript + '"', '--root', '"' + $projectRoot + '"', '--config', '"' + $ConfigPath + '"') -WorkingDirectory $projectRoot -WindowStyle Hidden -PassThru -RedirectStandardOutput (Join-Path $logDirectory 'fleet.stdout.log') -RedirectStandardError (Join-Path $logDirectory 'fleet.stderr.log')
for ($attempt=0; $attempt -lt 30; $attempt++) {
    Start-Sleep -Milliseconds 500
    if ($process.HasExited) { throw "Supervisor exited. See $logDirectory/fleet.stderr.log" }
    if (Test-Path -LiteralPath $statePath) {
        $state = Get-Content -LiteralPath $statePath -Raw | ConvertFrom-Json
        if ($state.supervisor_pid -and $state.started_utc -gt [DateTime]::UtcNow.AddMinutes(-1).ToString('o')) {
            Write-Output "Fleet launched: $($state.counts.running) running, $($state.counts.pending) pending, $($state.counts.blocked) blocked."
            exit 0
        }
    }
}
throw "Supervisor did not publish a fresh state. See $logDirectory/fleet.stderr.log"
