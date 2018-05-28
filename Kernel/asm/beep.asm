GLOBAL beep

SECTION .text

global _start

beep:
pushState
MOV     BX, 1            ; Frequency Value.
                         ; Formula = 1,193,180 \ frequency value
                         ; Will put it in BX for now.
                         ; The lower the value the higher
                         ; the sound / the higher the value
                         ; the lower the sound.

MOV     AL, 10110110B    ; The Magic Number (use this binary number only!)
OUT     43H, AL          ; Send it to the initializing port 43H Timer 2.

MOV     AX, BX           ; Move our Frequency Value into AX.

OUT     42H, AL          ; Send LSB to port 42H.
MOV     AL, AH           ; Move MSB into AL
OUT     42H, AL          ; Send MSB to port 42H.


IN      AL, 61H          ; Get current value of port 61H.
OR      AL, 00000011B    ; OR AL to this value, forcing first two bits high.
OUT     61H, AL          ; Copy it to port 61H of the PPI Chip
                         ; to turn ON the speaker.

MOV     CX, 100          ; Repeat the loop 100 times.
DELAY_LOOP:              ; We loop back to here.
LOOP    DELAY_LOOP       ; Jump repeatedly to DELAY_LOOP until CX = 0

IN      AL, 61H          ; Get current value of port 61H.
AND     AL, 11111100B    ; AND AL to this value, forcing first two bits low.
OUT     61H, AL          ; Copy it to port 61H of the PPI Chip
                         ; to turn OFF the speaker.
popState
