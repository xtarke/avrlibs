StringRamInit:
; This table contains the initial value that should always be
; used for the coefficient table on start-up.  The RAM copy
; of the table will be initialized based on this table.
.equ STRING_SIZE = 14
.db "Hello, world", '\n', 0

Initialize_RAM:
   ; Copy the initial values for the coefficient table from Flash into RAM.
   ldi ZH, high(StringRamInit << 1)
   ldi ZL, low(StringRamInit << 1)
   ldi XH, high(myRAMstring)
   ldi XL, low(myRAMstring)
   ldi r16, STRING_SIZE
Initialize_RAM_Loop:
   lpm r17, Z+
   st X+, r17
   dec r16
   brne Initialize_RAM_Loop
   ret

;Região de dados em RAM
.dseg
.org        0x100
var1:       .BYTE ;   ; reserve 1 byte to var1 
myRAMstring: .BYTE 64 ; reserve 64 bytes 
