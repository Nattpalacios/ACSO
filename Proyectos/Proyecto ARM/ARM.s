@ R12 area
@ R11 angulo del triangulo
@ R10
@ 0. No es un triangulo
@ 1. Escaleno y acutángulo
@ 2. Escaleno y rectangulo
@ 3. Escaleno y obtusángulo
@ 4. Isosceles y acutángulo
@ 5. Isosceles y rectangulo
@ 6. Isosceles y obtusángulo
@ 7. Equilatero y acutángulo

.text
.global _start
_start:
		LDR R1, X1
		LDR R2, Y1
		LDR R3, X2
		LDR R4, Y2
		LDR R5, X3
		LDR R6, Y3
		SUB R7, R1, R3
		MOV R1, R7
		SUB R7, R6, R4
		MOV R6, R7
		SUB R7, R2, R4
		MOV R2, R7
		SUB R7, R5, R3
		MOV R5, R7
		MUL R8, R1, R6
		MOV R3, R8		
		MUL R8, R2, R5
		MOV R4, R8
		SUB R7, R3, R4
		MOV R1, R7
		CMP R1, #0
		BLT ValorAbsoluto
		BEQ NoTriangulo
		B Clasificar
ValorAbsoluto:		MOV R3, #0
		SUB R4, R3, R1
		MOV R1, R4
		B Clasificar
NoTriangulo:		MOV R10, #0
		MOV R11, #0
		MOV R12, #0
		SVC 0
Clasificar:		MOV R12, R1, LSR #1
		@ A2
		LDR R1, X1
		LDR R2, X2
		LDR R3, Y1
		LDR R4, Y2
		SUB R5, R1, R2
		MUL R6, R5, R5
		SUB R5, R3, R4
		MUL R7, R5, R5
		ADD R8, R6, R7
		@ B2
		LDR R1, X1
		LDR R2, X3
		LDR R3, Y1
		LDR R4, Y3
		SUB R5, R1, R2
		MUL R6, R5, R5
		SUB R5, R3, R4
		MUL R7, R5, R5
		ADD R9, R6, R7
		@ C2
		LDR R1, X2
		LDR R2, X3
		LDR R3, Y2
		LDR R4, Y3
		SUB R5, R1, R2
		MUL R6, R5, R5
		SUB R5, R3, R4
		MUL R7, R5, R5
		ADD R2, R6, R7
		@ Comparacion lados
		CMP R8, R9 @ Comparacion A2 == B2
		BEQ EsEquilatero
		BNE	NoEquilatero
EsEquilatero:		CMP R9, R2 @ Comparacion B2 == C2
		BNE EsIsosceles
		BEQ EsEquilatero2
EsEquilatero2:		MOV R10, #7
		MOV R11, #7
		SVC 0
EsIsosceles:		MOV R10, #4
		B AnguloIf
NoEquilatero:		CMP R8, R2 @ Comparacion A2 == C2
		BEQ EsIsosceles
		BNE EsEscaleno
EsEscaleno:		CMP R9, R2 @Comparacion B2 == C2
		BNE EsEscaleno2
		BEQ EsIsosceles
EsEscaleno2:	MOV R10, #1
		B AnguloIf
AnguloIf:		CMP R8, R9 @ Comparacion A2 > B2
		BGT AnguloIf2
		BLE AnguloElif
AnguloIf2:		CMP R8, R2 @ Comparacion A2 > C2
		BLE AnguloElif
		BGT AnguloIf3
AnguloIf3:		MOV R7, R8
		MOV R6, R9
		MOV R5, R2
		B ClasificarAngulo
AnguloElif:		CMP R9, R2 @ Comparacion B2 > C2
		BGT AnguloElif2
		BLE AnguloElse
AnguloElif2:		CMP R9, R8 @ Comparacion B2 > A2
		BLE AnguloElse
		BGT AnguloElif3
AnguloElif3:		MOV R7, R9
		MOV R6, R8
		MOV R5, R2
		B ClasificarAngulo
AnguloElse:		MOV R7, R2
		MOV R6, R8
		MOV R5, R9
		B ClasificarAngulo		
ClasificarAngulo:		ADD R3, R6, R5
		CMP R7, R3 @ Comparacion piv == p1 + p2
		BEQ EsRectangulo
		BGT EsObtusangulo
		BLT EsAcutangulo
EsRectangulo:		CMP R10, #1
		BNE RectanguloIsosceles
		BEQ RectanguloEscaleno
RectanguloEscaleno:		MOV R11, #2
		MOV R10, #2
		SVC 0
RectanguloIsosceles:		MOV R11, #5
		MOV R10, #5
		SVC 0
EsObtusangulo:		CMP R10, #1
		BNE ObtusanguloIsosceles
		BEQ ObtusanguloEscaleno
ObtusanguloEscaleno:		MOV R11, #3
		MOV R10, #3
		SVC 0
ObtusanguloIsosceles:		MOV R11, #6
		MOV R10, #6
		SVC 0
EsAcutangulo:		CMP R10, #1
		BNE AcutanguloIsosceles
		BEQ AcutanguloEscaleno
AcutanguloEscaleno:		MOV R11, #1
		SVC 0
AcutanguloIsosceles:		MOV R11, #4
		SVC 0
		
.d:
		X1: .word 7
		Y1: .word 0
		X2:	.word 0
		Y2: .word 5
		X3: .word 7
		Y3: .word 5
.end