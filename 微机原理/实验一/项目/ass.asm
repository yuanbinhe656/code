assume cs:codesg
codesg segment
start: 
	mov ax,1234H
	inc ax
	dec ah
	add ah,78H
	add ah,0c8H
        or al,9fH
	xor al,59H
	mov bx,000eH
	mov [bx],ax

          int 21H
codesg ENDS
    END start
