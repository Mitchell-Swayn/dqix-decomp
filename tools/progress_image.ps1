param(
    [string]$Report = 'build/usa/report.json',
    [string]$Arm7Report = 'build/usa/arm7/report.json',
    [string]$Rom = 'dqix_usa.nds',
    [string]$Output = 'build/progress/latest.png'
)
$ErrorActionPreference = 'Stop'
Add-Type -AssemblyName System.Drawing
$arm9 = (Get-Content -LiteralPath $Report -Raw | ConvertFrom-Json).measures
$arm7 = Get-Content -LiteralPath $Arm7Report -Raw | ConvertFrom-Json
$sha = (Get-FileHash -LiteralPath $Rom -Algorithm SHA1).Hash.ToLowerInvariant()
$revision = git rev-parse --short HEAD
$matched = $sha -eq 'c7c3014c237900c8281289b8bc76a781969b6278'
$bitmap = New-Object Drawing.Bitmap 1200,780
$graphics = [Drawing.Graphics]::FromImage($bitmap)
$graphics.SmoothingMode = [Drawing.Drawing2D.SmoothingMode]::AntiAlias
$graphics.TextRenderingHint = [Drawing.Text.TextRenderingHint]::AntiAliasGridFit
$graphics.Clear([Drawing.ColorTranslator]::FromHtml('#111827'))
$fonts = @{}
$brushes = @{}
function Label([string]$text, [int]$size, [int]$x, [int]$y, [string]$color = '#e5e7eb') {
    if (-not $fonts.ContainsKey($size)) { $fonts[$size] = New-Object Drawing.Font 'Segoe UI', $size, ([Drawing.FontStyle]::Regular), ([Drawing.GraphicsUnit]::Pixel) }
    if (-not $brushes.ContainsKey($color)) { $brushes[$color] = New-Object Drawing.SolidBrush ([Drawing.ColorTranslator]::FromHtml($color)) }
    $graphics.DrawString($text, $fonts[$size], $brushes[$color], [single]$x, [single]$y)
}
function Block([int]$x, [int]$y, [int]$width, [int]$height, [string]$color) {
    if (-not $brushes.ContainsKey($color)) { $brushes[$color] = New-Object Drawing.SolidBrush ([Drawing.ColorTranslator]::FromHtml($color)) }
    $graphics.FillRectangle($brushes[$color], $x, $y, $width, $height)
}
function Coverage([string]$title, [double]$value, [double]$total, [int]$y) {
    Label $title 23 48 $y
    Label ('{0:N0} / {1:N0}   ({2:N2}%)' -f $value, $total, (100 * $value / $total)) 23 595 $y '#67e8f9'
    Block 48 ($y+38) 1104 17 '#374151'
    Block 48 ($y+38) ([int](1104*$value/$total)) 17 '#22d3ee'
}
try {
    Label 'DRAGON QUEST IX | Reconstruction progress' 34 48 34
    Label ('USA  /  revision {0}  /  {1}' -f $revision, (Get-Date -Format 'yyyy-MM-dd HH:mm zzz')) 20 48 85 '#9ca3af'
    Block 48 132 1104 80 '#1f2937'
    if ($matched) { Label 'ROM byte match: PASS' 27 68 145 '#86efac' }
    else { Label 'ROM byte match: NOT VERIFIED' 27 68 145 '#fca5a5' }
    Label 'Rebuild still combines reconstructed source with original binary fallbacks.' 20 68 180
    Label 'ARM9 matching report (includes existing assembly)' 24 48 238
    Coverage 'Functions' ([double]$arm9.matched_functions) ([double]$arm9.total_functions) 285
    Coverage 'Code bytes' ([double]$arm9.matched_code) ([double]$arm9.total_code) 363
    Coverage 'Data bytes' ([double]$arm9.matched_data) ([double]$arm9.total_data) 441
    Block 48 529 1104 139 '#1f2937'
    Label 'ARM7 | separate source accounting' 24 68 544
    Label ('{0:N0} C functions   /   {1:N0} instruction bytes   /   {2:N0} literal bytes' -f $arm7.source_functions, $arm7.source_code_bytes, $arm7.source_literal_pool_bytes) 22 68 582
    Label ('Reviewed assembly: {0:N0} bytes   |   Source BSS: {1:N0} bytes' -f $arm7.reviewed_assembly_bytes, $arm7.source_bss_bytes) 20 68 619 '#cbd5e1'
    Label 'Whole-cartridge source completion is not yet established.' 22 48 695 '#fcd34d'
    Label 'ARM7 total code/function counts remain unknown. Bar lengths measure bytes/functions, not effort.' 18 48 731 '#9ca3af'
    $target = [IO.Path]::GetFullPath($Output)
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
    $bitmap.Save($target, [Drawing.Imaging.ImageFormat]::Png)
    Write-Output $target
} finally {
    $graphics.Dispose()
    $bitmap.Dispose()
    foreach ($font in $fonts.Values) { $font.Dispose() }
    foreach ($brush in $brushes.Values) { $brush.Dispose() }
}
