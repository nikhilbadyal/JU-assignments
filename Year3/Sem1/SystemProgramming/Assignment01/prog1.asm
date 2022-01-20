.model small
.stack 100h
.data
name1 db 0AH,0DH,'NAME: SOURAV DUTTA$'
title1 db 0AH,0DH,'PROGRAM TITLE: A1Q1.ASM$'
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
print name1
;invoking print macro to display name
print title1
;invoking print macro to display title
mov ah, 4ch
;terminate the program
int 21h
main endp
end main