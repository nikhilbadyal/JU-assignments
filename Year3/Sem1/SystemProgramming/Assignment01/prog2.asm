.model small
.stack 100h
.data
msg1 db 0DH,0AH,'Enter a character: $'
msg2 db 0DH,0AH,'Lower case character: $'
.code
print macro msg
;macro to print a string
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
mov ah,01h ; read character
int 21h
cmp al,'A'
jl exit
cmp al,'Z'
jg exit
add al,32
; convert uppercase to lowercase by adding 32 to its ascii
exit:
print msg2
mov dl,al
; display character
mov ah,02h
int 21h
mov ah, 4ch
int 21h
main endp
end main