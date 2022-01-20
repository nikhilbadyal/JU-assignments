.model small
.stack 100h
.data
msg1 db 0AH,0DH,'ENTER A CHARACTER (PRESS ENTER KEY TO EXIT): $'
msg2 db 0AH,0DH,'PROGRAM TERMINATED.$'
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
mov ax, @data
mov ds, ax
l1:
print msg1
mov ah, 01h ; read a character
int 21h
cmp al,13
; compare with ASCII value of enter key
jne l1
; continue until enter key is not pressed
print msg2
; print terminating message
mov ah,4CH
int 21h
main endp
end main