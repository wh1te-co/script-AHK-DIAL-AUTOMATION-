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


; ================== TAB AUTOMATIZARE ==================
; TINE APASAT ALT → APARE MENIU ALT-TAB
; ATINGE ALT → CELALALT TAB SE DESCHIDE 

~LAlt::
    if (A_PriorHotkey = "~LAlt" && A_TimeSincePriorHotkey < 400)  ; dublu tap repede 
    {
        Send !{Tab}   ; schimba fereastra 0.10~
    }
    else
    {
        Send {LAlt down}   ; apasa alt pt fereastra
    }
return

~LAlt up::
    Send {LAlt up}
return
