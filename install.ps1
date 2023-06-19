$sourceFilePath = "$PWD\mp1.exe"
$folderPath = "$env:LOCALAPPDATA\MP1Taskbar"
$exePath = "$env:LOCALAPPDATA\MP1Taskbar\mp1.exe"
$shortcutPath = "$env:APPDATA\Microsoft\Windows\Start Menu\Programs\Startup\mp1.lnk"
# Creates directory
if (Test-Path -Path $folderPath -PathType Container){}
else {New-Item -ItemType Directory -Path $folderPath}
# Copies mp1.exe to MP1Taskbar folder
Copy-Item -Path $sourceFilePath -Destination $folderPath
# Creates shortcut and adds to startup folder
$WScriptShell = New-Object -ComObject WScript.Shell
$shortcut = $WScriptShell.CreateShortcut($shortcutPath)
$shortcut.TargetPath = $exePath
$shortcut.WorkingDirectory = $folderPath
$shortcut.Save()
#Starts mp1.exe from the shortcut created
Start-Process -FilePath $shortcutPath
