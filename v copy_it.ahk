;todo:
; add checkbox (default checked) [ ] disable for this window focus
;

 Coordmode, tooltip, screen
 Coordmode, mouse, screen
 AutoTrim, off

 tmpC :=""
 a1   :=""

 gui, add, text, vT1, ~numpad0::`r`n  clipboard.tabs_to_spaces()`r`nreturn
 gui, add, edit, vE1 r15 w500 +HScroll,
 gui, show, x1640 y20, copy_it v1.0
return
GuiClose:
 exitapp
return

~*c::
 sleep, 400
 if(tmpC = clipboard)
  return

 tmpC := clipboard
 a1   := clipboard
 stringReplace, a1, a1,%A_Tab%,%A_Space%, all
 stringReplace, a1, a1,%A_Space%%A_Space%%A_Space%%A_Space%,%A_Space%, all
 stringReplace, a1, a1,`r,, all
 stringReplace, a1, a1,`n,`r`n, all

 soundbeep, 600, 40
 soundbeep, 700, 40
 soundbeep, 740, 40
 GuiControl,, E1,%a1%
return

~Numpad1::send, {backspace}{space}{left}{down}

~Numpad0::
 clipboard:= a1
 soundbeep, 800, 60
return
;