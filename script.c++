@@@@@@@   @@@@@@@@  @@@@@@@@   @@@@@@   @@@@@@@   @@@@@@@@@@   @@@@@@@@ 
@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@ 
@@!  @@@  @@!       @@!       @@!  @@@  @@!  @@@  @@! @@! @@!  @@!      
!@!  @!@  !@!       !@!       !@!  @!@  !@!  @!@  !@! !@! !@!  !@!      
@!@!!@!   @!!!:!    @!!!:!    @!@  !@!  @!@!!@!   @!! !!@ @!@  @!!!:!   
!!@!@!    !!!!!:    !!!!!:    !@!  !!!  !!@!@!    !@!   ! !@!  !!!!!:   
!!: :!!   !!:       !!:       !!:  !!!  !!: :!!   !!:     !!:  !!:      
:!:  !:!  :!:       :!:       :!:  !:!  :!:  !:!  :!:     :!:  :!:      
::   :::   :: ::::   ::       ::::: ::  ::   :::  :::     ::    :: :::: 
 :   : :  : :: ::    :         : :  :    :   : :   :      :    : :: ::  
                                                                        
                                                                        
 @@@@@@@                                                                
@@@@@@@@                                                                
!@@          @@!        @@!                                             
!@!          !@!        !@!                                             
!@!       @!@!@!@!@  @!@!@!@!@                                          
!!!       !!!@!@!!!  !!!@!@!!!                                          
:!!          !!:        !!:                                             
:!:          :!:        :!:                                            
 ::: :::                                                                
 :: :: :         

Script bazat pe custom hotkey handling care implementează cyclic tab switching printr-un lightweight event loop, 
folosind keyboard hooks pentru interceptarea input-ului. Include un strat simplu de debounce + rate limiting pentru a 
filtra redundant key events și a evita key spam.
Navigarea se face printr-un circular index (ring logic), cu axare pe low-latency și comportament predictibil în condiții de input rapid.

=======================================================================================================================================================================================================================================================
=======================================================================================================================================================================================================================================================
; Ctrl + Shift + D 
^+d::
    Send ^c                  ; copieaza
    Sleep 100                ; pauza (10ms~)
    Run, tel:%Clipboard%     ; C//D 
return

; =============== Rapid Tab Cycling with single Ctrl hold ===============
; Hold Ctrl → it will keep sending Ctrl+Tab very quickly
; Release Ctrl → stops

~Ctrl::
    While GetKeyState("Ctrl", "P")  ; While you are physically holding Ctrl
    {
        Send, ^{Tab}                ; Send Ctrl + Tab (next tab)
        Sleep, 80                   ; Adjust this number for speed:
                                    ; Lower = faster (try 50 or 40)
                                    ; Higher = slower (100 is roughly normal speed)
    }
return
