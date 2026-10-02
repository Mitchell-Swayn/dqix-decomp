param([int]$Port = 8765)
$ErrorActionPreference = 'Stop'
$projectRoot = Split-Path -Parent $PSScriptRoot
$pythonExe = Join-Path $projectRoot '.venv/Scripts/python.exe'
$factoryScript = Join-Path $PSScriptRoot 'factory.py'
$logDirectory = Join-Path $projectRoot 'build/factory'
New-Item -ItemType Directory -Force -Path $logDirectory | Out-Null
try {
    $existing = Invoke-RestMethod "http://127.0.0.1:$Port/api/state" -TimeoutSec 2
    if ($existing.service -eq 'dqix-factory' -and $existing.project_root -eq $projectRoot) {
        Write-Output "Already running: http://127.0.0.1:$Port"
        exit 0
    }
    throw 'The selected port is already serving a different application.'
} catch [System.Net.WebException] {
    # No existing dashboard; start below.
}
$process = Start-Process -FilePath $pythonExe -ArgumentList @('"' + $factoryScript + '"', 'serve', '--port', "$Port") -WorkingDirectory $projectRoot -WindowStyle Hidden -PassThru -RedirectStandardOutput (Join-Path $logDirectory 'server.stdout.log') -RedirectStandardError (Join-Path $logDirectory 'server.stderr.log')
@{pid=$process.Id; port=$Port; started_utc=[DateTime]::UtcNow.ToString('o')} | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $logDirectory 'server.json')
for ($attempt=0; $attempt -lt 20; $attempt++) {
    Start-Sleep -Milliseconds 500
    if ($process.HasExited) { throw "Factory exited. See $logDirectory/server.stderr.log" }
    try {
        $state = Invoke-RestMethod "http://127.0.0.1:$Port/api/state" -TimeoutSec 2
        if ($state.service -eq 'dqix-factory') { Write-Output "Dashboard: http://127.0.0.1:$Port"; exit 0 }
    } catch [System.Net.WebException] {}
}
throw "Server did not become ready. See $logDirectory"
