@ R12 tipo de triangulo: 0. No es un triangulo 
@ 1. Equilatero y acutangulo. 
@ 2. Escaleno y rectangulo.
@ 3. Escaleto y obtusangulo.
@ 4. Escaleto y acutangulo.
@ 5. Isosceles y rectangulo.
@ 6. Isosceles y obtusangulo.
@ 7. Isosceles y acutangulo.
@ R11 Area
.text
.global _start
_start:
	LDR R1, X1
	LDR R2, Y1
	LDR R3, X2
	LDR R4, Y2
	LDR R5, X3
	LDR R6, Y3
	SUB R8, R1, R3
	MOV R1, R8
	SUB R8, R6, R4
	MOV R6, R8
	MUL R7, R1, R6
	MOV R1, R7
	SUB R8, R2, R4
	MOV R2, R8
	SUB R8, R5, R3
	MOV R5, R8
	MUL R9, R2, R5
	MOV R2, R9
	SUB R0, R1, R2
	MOV R1, #5
	MUL R2, R0, R1
	CMP R2, #0
	BEQ NotATriangle
	BLT Negative
	B Continue
Continue:	MOV R11, R2
	LDR R1, X1 @Calculo distancia A^2
	LDR R2, Y1
	LDR R3, X2
	LDR R4, Y2
	SUB R0, R1, R3
	MUL R1, R0, R0
	SUB R0, R2, R4
	MUL R2, R0, R0
	ADD R10, R1, R2
	LDR R1, X1 @Calculo distancia B^2
	LDR R2, Y1
	LDR R3, X3
	LDR R4, Y3
	SUB R0, R1, R3
	MUL R1, R0, R0
	SUB R0, R2, R4
	MUL R2, R0, R0
	ADD R9, R1, R2
	LDR R1, X2 @Calculo distancia C^2
	LDR R2, Y2
	LDR R3, X3
	LDR R4, Y3
	SUB R0, R1, R3
	MUL R1, R0, R0
	SUB R0, R2, R4
	MUL R2, R0, R0
	ADD R8, R1, R2 @ Inicio clasificacion por lados 
	CMP R10, R9 @A^2 == B^2
	BNE pe
	BEQ Equilatero @Inicio clasificaciÃ³n por angulos
Continue2: CMP R10, R9 @A>B
	BGE agtb @Si A>=B --> Ir a agtb
	BLT bgta @Si no B>A --> Ir a bgta
Continue3: ADD R0, R10, R9 @Calculo para comparacion y clasificacion por angulos
	CMP R8, R0
	BGT Obtusangulo
	BLT Acutangulo
	BEQ Rectangulo
end:	MOV R7, #1
	SVC 0

Obtusangulo:	ADD R0, R12, #1
	MOV R12, R0
	B end
Acutangulo:	ADD R0, R12, #2
	MOV R12, R0
	B end
Rectangulo:	B end
cgtb:	B Continue3
cgta:	B Continue3
bgta:	CMP R9, R8 @B>C
	BGE bgtc @Si B=>C
	BLT cgtb @Si C>B y por tanto C>A
bgtc:	MOV R0, R8
	MOV R1, R9
	MOV R9, R0
	MOV R8, R1
	B Continue3
agtb:  CMP R10, R8 @A>C
	BGE agtc @Si A>=C --> agtc
	BLT cgta @Si no C>A --> cgta y por tanto C>B
agtc:	MOV R0, R8
	MOV R1, R10
	MOV R10, R0
	MOV R8, R1
	B Continue3
pe:	CMP R10, R8 @A^2 == C^2
	BNE Escaleno
	BEQ Isosceles
Equilatero: CMP R10, R8
	BNE Isosceles
	MOV R12, #1
	MOV R7, #1
	SVC 0
Isosceles: MOV R12, #5
	B Continue2
Escaleno:
	MOV R12, #2
	B Continue2
NotATriangle:
	MOV R12, #0
	MOV R7, #1
	SVC 0
Negative:
	MOV R0, #0
	SUB R1, R0, R2
	MOV R2, R1
	B Continue
.d:
	X1: .word 7
	Y1: .word 0
	X2: .word 0
	Y2: .word 5
	X3: .word 7
	Y3: .word 5
.end