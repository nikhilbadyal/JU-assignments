.MODEL SMALL
.STACK 300H
.DATA
ARRAY1 DB 11,22,33,44,55
MSG1 DB 0AH,0DH,'Enter size of the array: $'
MSG2 DB 0AH,0DH,'Minimum value in array: $'
MSG3 DB 0AH,0DH,'Maximum value in array: $ '
ENDL DB 0AH,0DH,'$'
min dw 99
max dw 0
SE DB 33H
COUNT DB 00H
.CODE
PRINT MACRO MSG
; macro to print a string
push ax
push dx
mov AH, 09H
lea DX, MSG
int 21H
pop dx
pop ax
ENDM
MAIN PROC
MOV AX,@DATA
MOV DS,AX
START:
PRINT MSG1
call readnum
; read the size of array
mov COUNT, al
mov cl, COUNT
mov bx, 00h
rdnxt:
PRINT ENDL
call readnum
; read each array element
mov ARRAY1[BX],AL ; storing it in array
inc BX
loop rdnxt
LEA SI, ARRAY1
call findminmax
; calling procedure to find min and max
print msg2
mov ax, min
; minimum value is stored in min
call writenum
; print the result
print msg3
mov ax, max
; maximum value is stored in max
call writenum
; print the result
mov ah, 4ch
int 21h
MAIN ENDP
findminmax PROC
; this procedure will print the elements of a given array
; input : SI=offset address of the array
; : BX=size of the array
; output : none
PUSH AX ; push AX onto the STACK
PUSH CX ; push CX onto the STACK
PUSH DX ; push DX onto the STACK
push SI
MOV CX, BX ; set CX=BX
@PRINT_ARRAY: ; loop label
XOR AH, AH ; clear AH
MOV AL, [SI] ; set AL=[SI]
cmp min, ax
jl notminupdate
; if min >= ax
mov min, ax
; copy ax to min
notminupdate:
cmp max, ax
jg notmaxupdate
; if max <= ax
mov max, ax
; copy ax to max
notmaxupdate:
MOV AH, 2 ; set output function
MOV DL, 20H ; set DL=20H
INT 21H ; print a character
INC SI ; set SI=SI+1
LOOP @PRINT_ARRAY ; jump to label @PRINT_ARRAY while CX!=0
pop SI
POP DX ; pop a value from STACK into DX
POP CX ; pop a value from STACK into CX
POP AX ; pop a value from STACK into AX
RET ; return control to the calling procedure
findminmax ENDP
readnum proc near
push bx
push cx
mov cx,0ah
mov bx,00h
loopnum:
mov ah,01h
int 21h
cmp al,'0'
jb skip
cmp al,'9'
ja skip
sub al,'0'
push ax
mov ax,bx
mul cx
mov bx,ax
pop ax
mov ah,00h
add bx,ax
jmp loopnum
skip:
mov ax,bx
pop cx
pop bx
ret
readnum endp
writenum PROC near
; this procedure will display a decimal number
; input : AX
; output : none
push bx ; push BX onto the STACK
push cx ; push CX onto the STACK
push dx ; push DX onto the STACK
XOR CX, CX ; clear CX
MOV BX, 10 ; set BX=10
@OUTPUT: ; loop label
XOR DX, DX ; clear DX
DIV BX ; divide AX by BX
PUSH DX ; push DX onto the STACK
INC CX ; increment CX
OR AX, AX ; take OR of Ax with AX
JNE @OUTPUT ; jump to label @OUTPUT if ZF=0
MOV AH, 2 ; set output function
@DISPLAY: ; loop label
POP DX ; pop a value from STACK to DX
OR DL, 30H ; convert decimal to ascii code
INT 21H ; print a character
LOOP @DISPLAY ; jump to label @DISPLAY if CX!=0
POP DX ; pop a value from STACK into DX
POP CX ; pop a value from STACK into CX
POP BX ; pop a value from STACK into BX
RET ; return control to the calling procedure
writenum ENDP
END MAIN