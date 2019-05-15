@Else es 3 right t CAMBIAR
//1: obtusangulo, 2: acutangulo, 3: rectangulo
//1: isosceles: 2: equilatero, 3: escaleno
.text
.syntax unified

@Distancia entre dos puntos, parametros en S0 X1, S1 Y1, S2 X2 S3 Y2
Distancia:		VPUSH {S4,S5,S6,S7} @Respuesta en S0
        VSUB.f32 S4,S0,S2 @ X1 - X2
        VMUL.f32 S6,S4,S4 @ (X1 - X2) * (X1 - X2)
        VSUB.f32 S5,S1,S3 @ (Y1 - Y2)
        VMUL.f32 S7,S5,S5 @ (Y1 - Y2)*(Y1 - Y2)
        VADD.f32 S0, S6,S7 @borra valor de S0 y coloca res
        VSQRT.f32 S0,S0 @ S := sqrt(S0)
        VPOP {S4,S5,S6,S7}
        BX LR

Area:		VPUSH {S4,S5,S6,S7} @Params S0 a, S1 b, S2 c todas son distancias
        VADD.f32 S4, S0,S1 @S4 = a+b
        VADD.f32 S4, S4,S2 @S4 = a+b+c
        LDR R0,=VDOS
        VLDR S5,[R0]
        VDIV.f32 S4, S4, S5 @S4/2
        VSUB.f32 S5, S4, S0 @s-a
        VSUB.f32 S6, S4, S1 @s-b
        VSUB.f32 S7, S4, S2 @s-c
        VMUL.f32 S0, S5, S6 @(s-a)*(s-b)
        VMUL.f32 S0, S7,S0 @(s-a)*(s-b)*(s-c)
        VMUL.f32 S0, S4,S0 @(s-a)*(s-b)*(s-c)*s
        VSQRT.f32 S0, S0 @ S0 := sqrt(S0)
        VPOP {S4,S5,S6,S7}
        BX LR

Angulo:		VPUSH {S4,S5,S6,S7} @Param S0 a, S1 b S2 c todas son distancias
        VMOV.f32 S7, S2 @ temp es S7 := c
        VCMP.f32 S0,S1 @ a > b? 
        VMRS APSR_nzcv, FPSCR @Bits de control para branch
        BGT Angulo2 @ a > b true branch
        VCMP.f32 S1,S2 @false, second cond b > c
        VMRS APSR_nzcv, FPSCR @Bits de control para branch
        VMOVGT.f32 S2,S1 @ c = b
        VMOVGT.f32 S1,S7 @ b = temp(val c anterior)
        B ClasificarAngulo

Angulo2:		VCMP.f32 S0,S2 @ a > c @if angle
        VMRS APSR_nzcv, FPSCR @Bits de control
        VMOVGT.f32 S2,S0 @ c = a
        VMOVGT.f32 S0,S7 @ a = temp(val c anterior)

ClasificarAngulo:		VMUL.f32 S4, S2,S2 @ S4 es c*c	@classify angle
        VMUL.f32 S5, S0,S0 @ S5 es a*a
        VMUL.f32 S6, S1,S1 @ S6 es b*b
        LDR R0, =VTRES
        LDR R1, =VDOS
        LDR R2, =VUNO
        VLDR S0, [R0]@Else es 3 right t 
        VLDR S1, [R1]@2
        VLDR S2, [R2]@1
        VADD.f32 S7, S5,S6 @ S7 = a*a + b*b
        VCMP.f32 S4,S7 @ c*c <=> ? a*a+b*b
        VMOVGT.f32 S0, S2 @ si a*a+b*b > c*c angulo obtuse
        VMOVLT.f32 S0, S1 @ si a*a+b*b < c*c angulo acute
        VPOP {S4,S5,S6,S7}
        BX LR

ClaseTriangulo:		VCMP.f32 S0,S1 @com a con b  @Params S0 a, S1 b ,S2 c
        VMRS APSR_nzcv, FPSCR @Bits de control
        BEQ Equilatero1 @si a = b toca a = c 

Comparar:		VPUSH {S4} @if condicion a = b | b = c | a = c
        VCMP.f32 S0,S1 @no iguales toca mirar a = c o c = b
        VMRS APSR_nzcv, FPSCR @Bits de control
        BEQ Isosceles
        VCMP.f32 S0,S2 @a =c
        VMRS APSR_nzcv, FPSCR @Bits de control
        BEQ Isosceles
        VCMP.f32 S1,S2 @ b = c
        VMRS APSR_nzcv, FPSCR @Bits de control
        BEQ Isosceles
        LDR R0, =VTRES
        VLDR S3, [R0] @nada, entonces escaleno (3)
        B Finish

Equilatero1:		VCMP.f32 S0,S2 @comp a con c @equilatero primer if    
        BEQ Equilatero2
        B Comparar
		
Equilatero2:		LDR R0, =VDOS @Equilatero 2 @equilatero segundo if
        VSTR S4, [R0] 
        VCMP.f32 S1,S2
        VMRS APSR_nzcv, FPSCR @Bits de control
        VMOV.f32 S3, S4

Isosceles:		LDR R0, =VUNO @cargar isosceles
        VLDR S3, [R0]

Finish:		VMOV.f32 S0,S3
        VPOP {S4}
        BX LR

.global _start
_start: 

		@LDR R0, =VNUM @Cargar test num
        @VLDR S0, [R0] @Cargar valor de r0
        @VSQRT.f32 S0, S0  
        @SQRT ok

        LDR R4, = X1 @Cargar distancia entre puntos x1y1 y x2y2
        LDR R5, = Y1
        LDR R6, = X2
        LDR R7, = Y2
        LDR R0, = X3
        LDR R1, = Y3
        VLDR S0, [R4] 
        VLDR S1, [R5]
        VLDR S2, [R6]
        VLDR S3, [R7]

        BL Distancia 
        VMOV.f32 S4, S0 @S4 es a  x1y1 a x2y2

        VLDR S0, [R4] 
        VLDR S1, [R5]
        VLDR S2, [R0]
        VLDR S3, [R1]
        BL Distancia @S5 es b x1y1 a x3y3
        VMOV.f32 S5,S0

        VLDR S0, [R6] 
        VLDR S1, [R7]
        VLDR S2, [R0]
        VLDR S3, [R1]
        BL Distancia @S6 es c x2y2 a x3y3
        VMOV.f32 S6, S0

        VMOV.f32 S0,S4 @sacar area
        VMOV.f32 S1,S5
        VMOV.f32 S2,S6
        BL Area @area

        VMOV.f32 S0,S4 @Distacia ok + area ok
        VMOV.f32 S1,S5
        VMOV.f32 S2,S6
        BL Angulo
        @angulo ok

        VMOV.f32 S0,S4
        VMOV.f32 S1,S5
        VMOV.f32 S2,S6
        BL ClaseTriangulo
  
        MOV R7, #1
        SVC 0

.data

		X1: .float 2.5
		Y1: .float 3.0
		X2: .float 7.5
		Y2: .float 2.5
		X3: .float 3.5
		Y3: .float 6.0
		VNUM: .float 12.578
		VUNO:  .float 1.0
		VDOS:  .float 2.0
		VTRES: .float 3.0

.end