assume cs:code
datta1 segment
	db 1,2,3,4,5,6,7,8,9,10
data1 ends
sum segment
	db 1
sum ends
code segment
start:
	mov ax,data1[0]
	mov cx,9
	s:mov bx,data1[cx]
	add ax,bx
	loop s
	mov sum[0],ax
	int 21h
code ends
end