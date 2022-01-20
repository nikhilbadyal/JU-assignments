.model small
.stack 300h
.data
msg1 db 0AH,0DH,'Enter first decimal number: $'
msg2 db 0AH,0DH,'Enter second decimal number: $'
msg3 db 0AH,0DH,'Second number is less than first number$'
msg4 db 0AH,0DH,'Second number is not less than first number$'
.code
print macro msg
; macro to print a string
push ax
push dx
mov ah, 09h
lea dx, msg
int 21h
pop dx
pop ax
endm
main proc
mov ax,@data
mov ds,ax
print msg1
call readdecimal
; read first number, value is stored in ax
mov cx, ax
; copy first number to cx register
print msg2
call readdecimal
cmp ax,cx
; compare second with first number
jl less
print msg4
; print message if second number is < first
jmp exit
less:
; print message if second number is >= first
print msg3
exit:
mov ah, 4ch
int 21h
main endp
readdecimal proc near
; this procedure will take a number as input from user and store in AX
; input : none
; output : AX
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
readdecimal endp
end main