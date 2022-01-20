.model small
.stack 100h
.data
.code
printchar macro char
; macro to display a character
push ax
push dx
mov dl,char
mov ah,02h
int 21h
pop dx
pop ax
endm
main proc
mov ax,@data
mov ds,ax
mov cl,64
;cl = 64 (ascii value of character just before ‘A’)
l1:
inc cl
printchar cl
;print alphabet
printchar 20h
;print space (ASCII - 20H)
cmp cl,'Z'
jne l1
;loop until Z occurs
mov ah, 4CH
int 21h
main endp
end main