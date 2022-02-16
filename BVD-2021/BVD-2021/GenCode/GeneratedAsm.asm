.586
.model flat, stdcall
includelib kernel32.lib
includelib ../Debug/MASMStaticLib.lib

STD_OUTPUT			EQU - 11 
ExitProcess			PROTO : DWORD 
GetStdHandle		PROTO : DWORD; 
WriteConsoleA		PROTO : DWORD, : DWORD, : DWORD, : DWORD, : DWORD 
SetConsoleTitleA	PROTO : DWORD  
byte_to_char			PROTO : SBYTE , : DWORD 
_pow					PROTO : SBYTE, : SBYTE  
_abs					PROTO : SBYTE  
_strcat					PROTO : DWORD, : DWORD 
__push					PROTO 
__pop					PROTO 
fill_str				PROTO : DWORD,: DWORD
find_len				PROTO
_ah PROTO : DWORD
_addone PROTO : SBYTE,: SBYTE

.const
newStr BYTE 10, 13
newStr_len BYTE 2
zeroEx BYTE "Division by zero", 0
literal5 BYTE " with the BVD-2021 programming language", 0 
literal9 SBYTE 0b
literal10 BYTE "a < 0 ", 0 
literal11 BYTE "a >= 0 ", 0 
literal12 SBYTE 1b
literal21 SBYTE -0000110b
literal22 SBYTE 10b
literal23 SBYTE 1010b
literal24 SBYTE 1b
literal25 SBYTE 1b
literal27 BYTE "You are working ", 0 
literal28 SBYTE 0b

.data
buffer BYTE 10 dup(0)
bufferstr BYTE 255 dup(0)
bufferstrSymbol dword 0
consoleOutHandle	dword ? 
_13y SBYTE 0b
_13x SBYTE 0b
_13a DWORD 0
str0 byte 255 dup(0)
str1 byte 255 dup(0)
str2 byte 255 dup(0)
str3 byte 255 dup(0)
str4 byte 255 dup(0)
str5 byte 255 dup(0)
str6 byte 255 dup(0)

.code
_ah PROC  a0: DWORD
invoke _strcat,  a0, offset literal5
invoke fill_str, offset str0, eax
mov a0,eax
mov eax, a0
invoke fill_str, offset str1, eax
call find_len

invoke WriteConsoleA, consoleOutHandle, eax, edx, 0, 0
invoke WriteConsoleA, consoleOutHandle, offset newStr , newStr_len, 0, 0
mov eax, a0
invoke fill_str, offset str2, eax

ret
_ah ENDP
_addone PROC  a6: SBYTE, b6: SBYTE
mov ah, a6
mov al, literal9
.if ah < al
mov eax, offset literal10
invoke fill_str, offset str3, eax
call find_len

invoke WriteConsoleA, consoleOutHandle, eax, edx, 0, 0
invoke WriteConsoleA, consoleOutHandle, offset newStr , newStr_len, 0, 0
.else
mov eax, offset literal11
invoke fill_str, offset str4, eax
call find_len

invoke WriteConsoleA, consoleOutHandle, eax, edx, 0, 0
invoke WriteConsoleA, consoleOutHandle, offset newStr , newStr_len, 0, 0
.endif
mov al, a6
call __push
mov al, b6
call __push

mov	eax, 0b
call	__pop
mov		bl, al
call	__pop
add		al, bl
jno		isOk0
mov		al, 0b
isOk0:
call	__push
mov al, literal12
call __push

mov	eax, 0b
call	__pop
mov		bl, al
call	__pop
add		al, bl
jno		isOk1
mov		al, 0b
isOk1:
call	__push
call __pop
 mov a6, al
mov al, a6
call __push
call __pop
ret
_addone ENDP
main PROC
invoke	GetStdHandle, STD_OUTPUT 
mov	consoleOutHandle, eax
mov al, literal21
call __push
call __pop
push eax
call _abs
call __push
call __pop
 mov _13y, al
mov al, _13y
call __push
mov al, literal22
call __push
call __pop
push eax
call __pop
push eax
call _pow
call __push
mov al, literal23
call __push

mov	eax, 0b
call	__pop
mov		bl, al
call	__pop
sub		al, bl
jno		isOk2
mov		al, 0b
isOk2:
call	__push
call __pop
 mov _13x, al
mov al, _13y
call __push
call __pop
invoke	byte_to_char, al, offset buffer
invoke WriteConsoleA, consoleOutHandle, offset buffer, sizeof buffer, 0, 0
invoke WriteConsoleA, consoleOutHandle, offset newStr , newStr_len, 0, 0

mov al, _13x
call __push
call __pop
invoke	byte_to_char, al, offset buffer
invoke WriteConsoleA, consoleOutHandle, offset buffer, sizeof buffer, 0, 0
invoke WriteConsoleA, consoleOutHandle, offset newStr , newStr_len, 0, 0

mov al, _13x
call __push
mov al, literal24
call __push
call __pop
push eax
call __pop
push eax
call _addone
call __push
call __pop
 mov _13x, al
mov ecx, 2
while0:
mov ah, _13y
mov al, _13x
.if ah < al
mov ecx, 2
.else
jmp while0end
.endif
mov al, _13y
call __push
mov al, literal25
call __push

mov	eax, 0b
call	__pop
mov		bl, al
call	__pop
add		al, bl
jno		isOk3
mov		al, 0b
isOk3:
call	__push
call __pop
 mov _13y, al
loop while0
while0end:
mov al, _13y
call __push
call __pop
invoke	byte_to_char, al, offset buffer
invoke WriteConsoleA, consoleOutHandle, offset buffer, sizeof buffer, 0, 0
invoke WriteConsoleA, consoleOutHandle, offset newStr , newStr_len, 0, 0

mov al, _13x
call __push
call __pop
invoke	byte_to_char, al, offset buffer
invoke WriteConsoleA, consoleOutHandle, offset buffer, sizeof buffer, 0, 0
invoke WriteConsoleA, consoleOutHandle, offset newStr , newStr_len, 0, 0

invoke _ah,  offset literal27
invoke fill_str, offset str5, eax
mov _13a,eax
mov eax, _13a
invoke fill_str, offset str6, eax
call find_len

invoke WriteConsoleA, consoleOutHandle, eax, edx, 0, 0
invoke WriteConsoleA, consoleOutHandle, offset newStr , newStr_len, 0, 0
mov al, literal28
call __push
call __pop
ret

invoke ExitProcess, 0
main ENDP
end main
