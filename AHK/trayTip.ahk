FileInstall, 1.ico, %A_WorkingDir%\1.ico, 1
FileInstall, 2.ico, %A_WorkingDir%\2.ico, 1
FileInstall, 3.ico, %A_WorkingDir%\3.ico, 1
FileInstall, 4.ico, %A_WorkingDir%\4.ico, 1
FileInstall, mecx.ico, %A_WorkingDir%\mecx.ico, 1
Menu, Tray, Icon, %A_WorkingDir%\mecx.ico,

F16::
Menu, Tray, Icon, %A_WorkingDir%\1.ico,
return

F13::
Menu, Tray, Icon, %A_WorkingDir%\2.ico,
return

F14::
Menu, Tray, Icon, %A_WorkingDir%\3.ico,
return

F15::
Menu, Tray, Icon, %A_WorkingDir%\4.ico,
return
