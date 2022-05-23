gcc2_compiled.:
___gnu_compiled_c:
.text
	.align 4
	.global _mulsi
	.proc	0105
_mulsi:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	mov %i0,%l0
	ld [%i1+4],%o1
	sra %o1,24,%l2
	sethi %hi(65535),%o0
	or %o0,%lo(65535),%o0
	cmp %l0,0
	be L3
	and %o1,%o0,%l1
	cmp %l2,0
	bne L2
	cmp %l0,0
L3:
	sethi %hi(_gzero),%o0
	b L11
	ld [%o0+%lo(_gzero)],%i0
L2:
	bge L4
	nop
	subcc %g0,%l0,%l0
	bpos L4
	sub %g0,%l2,%l2
	call _stoi,0
	sethi %hi(-2147483648),%o0
	call _mulii,0
	mov %i1,%o1
	b L11
	mov %o0,%i0
L4:
	call _cgeti,0
	add %l1,1,%o0
	mov %o0,%i0
	mov 0,%o2
	sll %l1,2,%o0
	add %i1,%o0,%i1
	add %i0,%o0,%g2
	addcc %l1,-2,%o3
	be L7
	add %g2,4,%g2
L8:
	add %g2,-4,%g2
	mov %o2,%o1
	add %i1,-4,%i1
	mov %l0,%o0
	ld [%i1],%g3
	 
        or      %o0,%g3,%o4      
        mov     %o0,%y
        andncc  %o4,0xfff,%g0
        be      2f
        andcc   %g0,%g0,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g0,%o4
        tst     %g3
        bl,a    1f
        add     %o4,%o0,%o4
1:      mov     %o4,%o2
        b       3f 
        rd      %y,%o0
2:      clr     %o2
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g3,%o4
        mulscc  %o4,%g0,%o4
        rd      %y,%o5
        sll     %o4,12,%o4
        srl     %o5,20,%o5
        or      %o5,%o4,%o0
3:       

	addcc %o1,%o0,%g3
	addx %o2,%g0,%o2
	addcc %o3,-1,%o3
	bne L8
	st %g3,[%g2]
L7:
	cmp %o2,0
	be L9
	sethi %hi(-65536),%o1
	st %o2,[%g2-4]
	ld [%i0+4],%o0
	and %o0,%o1,%o0
	add %o0,%l1,%o0
	b L12
	add %o0,1,%o0
L9:
	sethi %hi(_avma),%o1
	ld [%o1+%lo(_avma)],%o0
	add %o0,4,%o0
	st %o0,[%o1+%lo(_avma)]
	ld [%i0],%o0
	add %o0,-1,%o0
	st %o0,[%i0+4]
	add %i0,4,%i0
	ld [%i0+4],%o0
	sethi %hi(-65536),%o1
	and %o0,%o1,%o0
	add %o0,%l1,%o0
L12:
	st %o0,[%i0+4]
	ld [%i0+4],%o0
	sethi %hi(-16777216),%o1
	andn %o0,%o1,%o1
	sll %l2,24,%o0
	add %o1,%o0,%o1
	st %o1,[%i0+4]
L11:
	ret
	restore
	.align 4
	.global _expi
	.proc	04
_expi:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	ld [%i0+4],%o1
	sethi %hi(65535),%o0
	or %o0,%lo(65535),%o0
	and %o1,%o0,%l0
	cmp %l0,2
	be,a L15
	sethi %hi(-8388608),%i0
	call _bfffo,0
	ld [%i0+8],%o0
	add %l0,-2,%i0
	sll %i0,5,%i0
	sub %i0,%o0,%i0
	add %i0,-1,%i0
L15:
	ret
	restore
	.align 4
	.global _addsi
	.proc	0105
_addsi:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	orcc %i0,%g0,%l1
	bne,a L17
	ldsb [%i1+4],%l3
	call _icopy,0
	mov %i1,%o0
	b L59
	mov %o0,%i0
L17:
	cmp %l3,0
	bne L18
	cmp %l1,0
	call _stoi,0
	mov %l1,%o0
	b L59
	mov %o0,%i0
L18:
	bge,a L21
	mov 1,%l4
	subcc %g0,%l1,%l1
	bpos L21
	mov -1,%l4
	sethi %hi(_MOST_NEGS),%o0
	or %o0,%lo(_MOST_NEGS),%o0
	call _addii,0
	mov %i1,%o1
	b L59
	mov %o0,%i0
L21:
	ld [%i1+4],%o1
	sethi %hi(65535),%o0
	or %o0,%lo(65535),%o0
	cmp %l4,%l3
	bne L22
	and %o1,%o0,%l0
	mov %l1,%o1
	sll %l0,2,%l2
	add %l2,%i1,%o0
	ld [%o0-4],%o0
	add %o1,%o0,%o0
	cmp %o0,%o1
	bgeu L23
	mov %o0,%l1
	call _cgeti,0
	add %l0,1,%o0
	mov %o0,%i0
	add %l0,-1,%o2
	cmp %o2,2
	ble L64
	st %l1,[%i0+%l2]
	sll %o2,2,%o0
	mov %o0,%o1
	b L60
	add %o0,%i1,%o0
L27:
	cmp %o2,2
	ble L64
	st %g0,[%i0+%o1]
	sll %o2,2,%o1
	add %o1,%i1,%o0
L60:
	ld [%o0-4],%o0
	cmp %o0,-1
	be,a L27
	add %o2,-1,%o2
	cmp %o2,2
L64:
	ble L28
	sll %o2,2,%o1
	add %o1,%i1,%o0
	ld [%o0-4],%o0
	add %o0,1,%o0
	b L61
	st %o0,[%i0+%o1]
L31:
	add %o0,%i1,%o1
	ld [%o1-4],%o1
	st %o1,[%i0+%o0]
L61:
	add %o2,-1,%o2
	cmp %o2,2
	bg L31
	sll %o2,2,%o0
	ld [%i0],%o0
	add %o0,-1,%o0
	st %o0,[%i0+4]
	st %o0,[%i0+8]
	add %i0,4,%i0
	sethi %hi(_avma),%o1
	ld [%o1+%lo(_avma)],%o0
	add %o0,4,%o0
	b L33
	st %o0,[%o1+%lo(_avma)]
L28:
	mov 1,%o0
	st %o0,[%i0+8]
	ld [%i0],%o0
	b L33
	st %o0,[%i0+4]
L23:
	call _cgeti,0
	mov %l0,%o0
	mov %o0,%i0
	sll %l0,2,%o0
	add %o0,%i0,%o0
	st %l1,[%o0-4]
	mov 1,%o2
	add %l0,-1,%o0
	cmp %o2,%o0
	bge L33
	mov %o0,%o3
L37:
	sll %o2,2,%o1
	ld [%i1+%o1],%o0
	add %o2,1,%o2
	cmp %o2,%o3
	bl L37
	st %o0,[%i0+%o1]
L33:
	ld [%i0+4],%o0
	sethi %hi(-16777216),%o1
	andn %o0,%o1,%o1
	sll %l4,24,%o0
	add %o1,%o0,%o1
	b L59
	st %o1,[%i0+4]
L22:
	cmp %l0,3
	bne L39
	sll %l0,2,%l2
	ld [%i1+8],%o0
	cmp %o0,%l1
	bleu L40
	nop
	call _cgeti,0
	mov 3,%o0
	mov %o0,%i0
	sll %l3,24,%o0
	add %o0,3,%o0
	st %o0,[%i0+4]
	ld [%i1+8],%o0
	sub %o0,%l1,%o0
	b L59
	st %o0,[%i0+8]
L40:
	bne L41
	sethi %hi(_gzero),%o0
	b L59
	ld [%o0+%lo(_gzero)],%i0
L41:
	call _cgeti,0
	mov 3,%o0
	mov %o0,%i0
	sub %g0,%l3,%o0
	sll %o0,24,%o0
	add %o0,3,%o0
	st %o0,[%i0+4]
	ld [%i1+8],%o0
	sub %l1,%o0,%o0
	b L59
	st %o0,[%i0+8]
L39:
	add %l2,%i1,%o0
	ld [%o0-4],%o1
	mov %l1,%o0
	cmp %o1,%o0
	bgeu L42
	sub %o1,%o0,%l1
	call _cgeti,0
	mov %l0,%o0
	mov %o0,%i0
	add %l2,%i0,%o0
	st %l1,[%o0-4]
	add %l0,-2,%o2
	sll %o2,2,%o0
	mov %o0,%o1
	ld [%i1+%o0],%o0
	cmp %o0,0
	bne,a L62
	sll %o2,2,%o1
	mov -1,%o3
	st %o3,[%i0+%o1]
L63:
	add %o2,-1,%o2
	sll %o2,2,%o1
	ld [%i1+%o1],%o0
	cmp %o0,0
	be,a L63
	st %o3,[%i0+%o1]
	sll %o2,2,%o1
L62:
	ld [%i1+%o1],%o0
	add %o0,-1,%o0
	cmp %o2,2
	bg L48
	st %o0,[%i0+%o1]
	cmp %o0,0
	be,a L47
	ld [%i0],%o0
L48:
	add %o2,-1,%o2
	cmp %o2,0
	ble L59
	nop
L52:
	sll %o2,2,%o1
	ld [%i1+%o1],%o0
	add %o2,-1,%o2
	cmp %o2,0
	bg L52
	st %o0,[%i0+%o1]
	b,a L59
L47:
	add %o0,-1,%o0
	st %o0,[%i0+4]
	st %o0,[%i0+8]
	add %i0,4,%i0
	sethi %hi(_avma),%o1
	ld [%o1+%lo(_avma)],%o0
	add %o0,4,%o0
	st %o0,[%o1+%lo(_avma)]
	ld [%i0+4],%o1
	sethi %hi(-16777216),%o0
	andn %o1,%o0,%o0
	sll %l3,24,%o1
	add %o0,%o1,%o0
	b L59
	st %o0,[%i0+4]
L42:
	call _cgeti,0
	mov %l0,%o0
	mov %o0,%i0
	sll %l0,2,%o0
	add %o0,%i0,%o0
	st %l1,[%o0-4]
	mov 1,%o2
	add %l0,-1,%o0
	cmp %o2,%o0
	bge L59
	mov %o0,%o3
L58:
	sll %o2,2,%o1
	ld [%i1+%o1],%o0
	add %o2,1,%o2
	cmp %o2,%o3
	bl L58
	st %o0,[%i0+%o1]
L59:
	ret
	restore
	.align 4
	.global _addii
	.proc	0105
_addii:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	mov %i0,%l0
	ld [%l0+4],%o0
	sethi %hi(65535),%o1
	or %o1,%lo(65535),%o1
	and %o0,%o1,%l1
	ld [%i1+4],%o0
	and %o0,%o1,%l2
	cmp %l1,%l2
	bge,a L188
	ldsb [%i1+4],%o5
	mov %i1,%l0
	mov %i0,%i1
	mov %l1,%l3
	mov %l2,%l1
	mov %l3,%l2
	ldsb [%i1+4],%o5
L188:
	cmp %o5,0
	bne,a L67
	ldsb [%l0+4],%l3
	call _icopy,0
	mov %l0,%o0
	b L185
	mov %o0,%i0
L67:
	cmp %l3,%o5
	bne L68
	cmp %l1,%l2
	call _cgeti,0
	add %l1,1,%o0
	mov %o0,%i0
	mov 0,%o2
	sll %l1,2,%o0
	add %i0,%o0,%o4
	add %o4,4,%o4
	add %l0,%o0,%o3
	sll %l2,2,%o0
	add %i1,%o0,%o1
	add %l2,-2,%o5
	sethi %hi(L106),%o0
	or %o0,%lo(L106),%g2
	add %o5,-1,%o0
L204:
	cmp %o0,15
	bgu L74
	sll %o0,2,%o0
	ld [%o0+%g2],%o0
	jmp %o0
	nop
L106:
	.word	L104
	.word	L102
	.word	L100
	.word	L98
	.word	L96
	.word	L94
	.word	L92
	.word	L90
	.word	L88
	.word	L86
	.word	L84
	.word	L82
	.word	L80
	.word	L78
	.word	L76
	.word	L74
L74:
	subcc %g0,%o2,%g0
	b L75
	add %o4,-4,%o4
L76:
	subcc %g0,%o2,%g0
	b L189
	add %o4,-4,%o4
L78:
	subcc %g0,%o2,%g0
	b L190
	add %o4,-4,%o4
L80:
	subcc %g0,%o2,%g0
	b L191
	add %o4,-4,%o4
L82:
	subcc %g0,%o2,%g0
	b L192
	add %o4,-4,%o4
L84:
	subcc %g0,%o2,%g0
	b L193
	add %o4,-4,%o4
L86:
	subcc %g0,%o2,%g0
	b L194
	add %o4,-4,%o4
L88:
	subcc %g0,%o2,%g0
	b L195
	add %o4,-4,%o4
L90:
	subcc %g0,%o2,%g0
	b L196
	add %o4,-4,%o4
L92:
	subcc %g0,%o2,%g0
	b L197
	add %o4,-4,%o4
L94:
	subcc %g0,%o2,%g0
	b L198
	add %o4,-4,%o4
L96:
	subcc %g0,%o2,%g0
	b L199
	add %o4,-4,%o4
L98:
	subcc %g0,%o2,%g0
	b L200
	add %o4,-4,%o4
L100:
	subcc %g0,%o2,%g0
	b L201
	add %o4,-4,%o4
L102:
	subcc %g0,%o2,%g0
	b L202
	add %o4,-4,%o4
L104:
	subcc %g0,%o2,%g0
	b L203
	add %o4,-4,%o4
L75:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L189:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L190:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L191:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L192:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L193:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L194:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L195:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L196:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L197:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L198:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L199:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L200:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L201:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L202:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L203:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	addxcc %l4,%g3,%l4
	st %l4,[%o4]
	addx %g0,%g0,%o2
	add %o5,-16,%o5
	cmp %o5,0
	bg L204
	add %o5,-1,%o0
	cmp %o2,0
	be L107
	add %l0,8,%o2
L108:
	add %o3,-4,%o3
	cmp %o3,%o2
	blu L109
	mov %o3,%o1
	ld [%o3],%o0
	cmp %o0,-1
	bne,a L110
	add %o4,-4,%o4
	add %o4,-4,%o4
	b L108
	st %g0,[%o4]
L110:
	ld [%o1],%o0
	b L187
	add %o0,1,%o0
L114:
	add %o4,-4,%o4
	ld [%o1],%o0
L187:
	st %o0,[%o4]
	add %o3,-4,%o3
	cmp %o3,%o2
	bgeu L114
	mov %o3,%o1
	b L205
	ld [%i0],%o0
L109:
	mov 1,%o0
	st %o0,[%i0+8]
	ld [%l0+4],%o0
	add %o0,1,%o0
	b L185
	st %o0,[%i0+4]
L107:
	subcc %l1,%l2,%o2
	be,a L205
	ld [%i0],%o0
L119:
	add %o4,-4,%o4
	add %o3,-4,%o3
	ld [%o3],%o0
	addcc %o2,-1,%o2
	bne L119
	st %o0,[%o4]
	ld [%i0],%o0
L205:
	add %o0,-1,%o0
	st %o0,[%i0+4]
	ld [%l0+4],%o0
	st %o0,[%i0+8]
	add %i0,4,%i0
	sethi %hi(_avma),%o1
	ld [%o1+%lo(_avma)],%o0
	add %o0,4,%o0
	b L185
	st %o0,[%o1+%lo(_avma)]
L68:
	bne L121
	add %l0,8,%o3
	addcc %l1,-2,%o2
	be L129
	add %i1,8,%o1
	ld [%o3],%o4
L206:
	add %o3,4,%o3
	ld [%o1],%o0
	cmp %o0,%o4
	bgu L186
	add %o1,4,%o1
	cmp %o4,%o0
	bgu L121
	addcc %o2,-1,%o2
	bne,a L206
	ld [%o3],%o4
L129:
	sethi %hi(_gzero),%o0
	b L185
	ld [%o0+%lo(_gzero)],%i0
L186:
	mov %l0,%i0
	mov %i1,%l0
	mov %i0,%i1
	mov %o5,%l3
L121:
	call _cgeti,0
	mov %l1,%o0
	mov %o0,%i0
	mov 0,%o2
	sll %l1,2,%o0
	add %l0,%o0,%o3
	sll %l2,2,%o1
	add %i1,%o1,%o1
	add %i0,%o0,%o4
	add %l2,-2,%o5
	sethi %hi(L167),%o0
	or %o0,%lo(L167),%g2
	add %o5,-1,%o0
L222:
	cmp %o0,15
	bgu L135
	sll %o0,2,%o0
	ld [%o0+%g2],%o0
	jmp %o0
	nop
L167:
	.word	L165
	.word	L163
	.word	L161
	.word	L159
	.word	L157
	.word	L155
	.word	L153
	.word	L151
	.word	L149
	.word	L147
	.word	L145
	.word	L143
	.word	L141
	.word	L139
	.word	L137
	.word	L135
L135:
	subcc %g0,%o2,%g0
	b L136
	add %o4,-4,%o4
L137:
	subcc %g0,%o2,%g0
	b L207
	add %o4,-4,%o4
L139:
	subcc %g0,%o2,%g0
	b L208
	add %o4,-4,%o4
L141:
	subcc %g0,%o2,%g0
	b L209
	add %o4,-4,%o4
L143:
	subcc %g0,%o2,%g0
	b L210
	add %o4,-4,%o4
L145:
	subcc %g0,%o2,%g0
	b L211
	add %o4,-4,%o4
L147:
	subcc %g0,%o2,%g0
	b L212
	add %o4,-4,%o4
L149:
	subcc %g0,%o2,%g0
	b L213
	add %o4,-4,%o4
L151:
	subcc %g0,%o2,%g0
	b L214
	add %o4,-4,%o4
L153:
	subcc %g0,%o2,%g0
	b L215
	add %o4,-4,%o4
L155:
	subcc %g0,%o2,%g0
	b L216
	add %o4,-4,%o4
L157:
	subcc %g0,%o2,%g0
	b L217
	add %o4,-4,%o4
L159:
	subcc %g0,%o2,%g0
	b L218
	add %o4,-4,%o4
L161:
	subcc %g0,%o2,%g0
	b L219
	add %o4,-4,%o4
L163:
	subcc %g0,%o2,%g0
	b L220
	add %o4,-4,%o4
L165:
	subcc %g0,%o2,%g0
	b L221
	add %o4,-4,%o4
L136:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L207:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L208:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L209:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L210:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L211:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L212:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L213:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L214:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L215:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L216:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L217:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L218:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L219:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L220:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	add %o4,-4,%o4
L221:
	add %o3,-4,%o3
	add %o1,-4,%o1
	ld [%o3],%l4
	ld [%o1],%g3
	subxcc %l4,%g3,%l4
	st %l4,[%o4]
	addx %g0,%g0,%o2
	add %o5,-16,%o5
	cmp %o5,0
	bg L222
	add %o5,-1,%o0
	cmp %o2,0
	be,a L168
	subcc %l1,%l2,%o5
	add %o3,-4,%o3
	ld [%o3],%o0
	cmp %o0,0
	bne L223
	add %l0,8,%o1
	mov -1,%o1
	add %o4,-4,%o4
L224:
	st %o1,[%o4]
	add %o3,-4,%o3
	ld [%o3],%o0
	cmp %o0,0
	be,a L224
	add %o4,-4,%o4
	add %l0,8,%o1
L223:
	cmp %o3,%o1
	blu L176
	add %o0,-1,%o0
	add %o4,-4,%o4
	st %o0,[%o4]
	add %o3,-4,%o3
	cmp %o3,%o1
	blu L176
	mov %o3,%o0
L175:
	add %o4,-4,%o4
	ld [%o0],%o0
	st %o0,[%o4]
	add %o3,-4,%o3
	cmp %o3,%o1
	bgeu L175
	mov %o3,%o0
	b L225
	ld [%i0+8],%o0
L168:
	be,a L225
	ld [%i0+8],%o0
L179:
	add %o4,-4,%o4
	add %o3,-4,%o3
	ld [%o3],%o0
	addcc %o5,-1,%o5
	bne L179
	st %o0,[%o4]
L176:
	ld [%i0+8],%o0
L225:
	cmp %o0,0
	be,a L180
	ld [%i0+12],%o0
	ld [%l0+4],%o0
	b L185
	st %o0,[%i0+4]
L180:
	cmp %o0,0
	bne L183
	add %i0,12,%o4
	add %o4,4,%o4
L226:
	ld [%o4],%o0
	cmp %o0,0
	be,a L226
	add %o4,4,%o4
L183:
	add %o4,-8,%o4
	sub %o4,%i0,%o5
	sra %o5,2,%o5
	ld [%i0],%o1
	sub %o1,%o5,%o1
	st %o1,[%o4]
	st %o1,[%o4+4]
	mov %o4,%i0
	sethi %hi(-16777216),%o0
	andn %o1,%o0,%o0
	sll %l3,24,%o1
	add %o0,%o1,%o0
	st %o0,[%i0+4]
	sethi %hi(_avma),%o2
	sll %o5,2,%o0
	ld [%o2+%lo(_avma)],%o1
	add %o0,%o1,%o0
	st %o0,[%o2+%lo(_avma)]
L185:
	ret
	restore
	.align 4
	.global _mulss
	.proc	0105
_mulss:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	orcc %i0,%g0,%o0
	be L229
	cmp %i1,0
	bne L228
	cmp %o0,0
L229:
	sethi %hi(_gzero),%o0
	b L237
	ld [%o0+%lo(_gzero)],%i0
L228:
	bge L230
	mov 1,%l0
	subcc %g0,%o0,%o0
	bpos L230
	mov -1,%l0
	call _stoi,0
	nop
	mov %o0,%o1
	call _mulsi,0
	mov %i1,%o0
	b L237
	mov %o0,%i0
L230:
	cmp %i1,0
	bge L238
	mov %o0,%l1
	subcc %g0,%i1,%i1
	bpos L238
	sub %g0,%l0,%l0
	cmp %l0,0
	bg L234
	mov %o0,%o1
	sub %g0,%o0,%o1
L234:
	mov %o1,%o0
	sethi %hi(_ABS_MOST_NEGS),%o1
	call _mulsi,0
	or %o1,%lo(_ABS_MOST_NEGS),%o1
	b L237
	mov %o0,%i0
L238:
	 
        or      %l1,%i1,%o4      
        mov     %l1,%y
        andncc  %o4,0xfff,%g0
        be      2f
        andcc   %g0,%g0,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%g0,%o4
        tst     %i1
        bl,a    1f
        add     %o4,%l1,%o4
1:      mov     %o4,%o2
        b       3f 
        rd      %y,%l1
2:      clr     %o2
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%g0,%o4
        rd      %y,%o5
        sll     %o4,12,%o4
        srl     %o5,20,%o5
        or      %o5,%o4,%l1
3:       

	orcc %o2,%g0,%i1
	be L235
	nop
	call _cgeti,0
	mov 4,%o0
	mov %o0,%i0
	st %i1,[%i0+8]
	b L236
	st %l1,[%i0+12]
L235:
	call _cgeti,0
	mov 3,%o0
	mov %o0,%i0
	st %l1,[%i0+8]
L236:
	ld [%i0],%o0
	sethi %hi(-16777216),%o1
	andn %o0,%o1,%o1
	sll %l0,24,%o0
	add %o1,%o0,%o1
	st %o1,[%i0+4]
L237:
	ret
	restore
	.align 4
	.global _mulii
	.proc	0105
_mulii:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	mov %i0,%l4
	ld [%l4+4],%o0
	sethi %hi(65535),%o1
	or %o1,%lo(65535),%o1
	and %o0,%o1,%l0
	ld [%i1+4],%o2
	sra %o0,24,%l3
	cmp %l3,0
	be L256
	and %o2,%o1,%l2
	ldsb [%i1+4],%o0
	cmp %o0,0
	bne L241
	nop
L256:
	sethi %hi(_gzero),%o0
	b L255
	ld [%o0+%lo(_gzero)],%i0
L241:
	bl,a L242
	sub %g0,%l3,%l3
L242:
	cmp %l0,%l2
	ble L243
	sethi %hi(65535),%o0
	mov %l4,%i0
	mov %i1,%l4
	mov %i0,%i1
	mov %l0,%l1
	mov %l2,%l0
	mov %l1,%l2
L243:
	add %l0,%l2,%l1
	add %l1,-2,%l1
	or %o0,%lo(65535),%o0
	cmp %l1,%o0
	ble L244
	nop
	call _err,0
	mov 17,%o0
L244:
	call _cgeti,0
	mov %l1,%o0
	mov %o0,%i0
	ld [%i0],%o1
	sethi %hi(-16777216),%o0
	andn %o1,%o0,%o0
	sll %l3,24,%o1
	add %o0,%o1,%o0
	st %o0,[%i0+4]
	sll %l0,2,%o0
	add %l4,%o0,%g4
	add %g4,-4,%g4
	ld [%g4],%g2
	mov 0,%o2
	sll %l2,2,%o0
	add %i1,%o0,%g3
	sll %l1,2,%o0
	addcc %l2,-2,%o3
	be L246
	add %i0,%o0,%g1
L247:
	add %g1,-4,%g1
	mov %o2,%o1
	add %g3,-4,%g3
	mov %g2,%o0
	ld [%g3],%l5
	 
        or      %o0,%l5,%o4      
        mov     %o0,%y
        andncc  %o4,0xfff,%g0
        be      2f
        andcc   %g0,%g0,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%g0,%o4
        tst     %l5
        bl,a    1f
        add     %o4,%o0,%o4
1:      mov     %o4,%o2
        b       3f 
        rd      %y,%o0
2:      clr     %o2
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%l5,%o4
        mulscc  %o4,%g0,%o4
        rd      %y,%o5
        sll     %o4,12,%o4
        srl     %o5,20,%o5
        or      %o5,%o4,%o0
3:       

	addcc %o1,%o0,%l5
	addx %o2,%g0,%o2
	addcc %o3,-1,%o3
	bne L247
	st %l5,[%g1]
L246:
	st %o2,[%g1-4]
	sll %l1,2,%o0
	add %i0,%o0,%g1
	sll %l2,2,%o0
	add %i1,%o0,%i1
	add %l0,-3,%l0
	cmp %l0,0
	ble L249
	add %l2,-1,%l2
L253:
	add %g4,-4,%g4
	ld [%g4],%o7
	mov %i1,%g3
	add %g1,-4,%o1
	mov %o1,%g1
	addcc %l2,-1,%o3
	be L251
	mov 0,%g2
L252:
	add %g3,-4,%g3
	ld [%g3],%o0
	 
        or      %o0,%o7,%o4      
        mov     %o0,%y
        andncc  %o4,0xfff,%g0
        be      2f
        andcc   %g0,%g0,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%g0,%o4
        tst     %o7
        bl,a    1f
        add     %o4,%o0,%o4
1:      mov     %o4,%o2
        b       3f 
        rd      %y,%o0
2:      clr     %o2
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%g0,%o4
        rd      %y,%o5
        sll     %o4,12,%o4
        srl     %o5,20,%o5
        or      %o5,%o4,%o0
3:       

	add %o1,-4,%o1
	ld [%o1],%l5
	addcc %o0,%l5,%o0
	addx %o2,%g0,%o2
	addcc %o0,%g2,%l5
	addx %o2,%g0,%o2
	st %l5,[%o1]
	addcc %o3,-1,%o3
	bne L252
	mov %o2,%g2
L251:
	add %l0,-1,%l0
	cmp %l0,0
	bg L253
	st %o2,[%o1-4]
L249:
	ld [%i0+8],%o0
	cmp %o0,0
	bne L255
	sethi %hi(_avma),%o1
	ld [%i0+4],%o0
	add %o0,-1,%o0
	st %o0,[%i0+8]
	ld [%i0],%o0
	add %o0,-1,%o0
	st %o0,[%i0+4]
	add %i0,4,%i0
	ld [%o1+%lo(_avma)],%o0
	add %o0,4,%o0
	st %o0,[%o1+%lo(_avma)]
L255:
	ret
	restore
.data
	.align 8
LC0:
	.word	0x3fd34413
	.word	0x55475a32
	.align 8
LC1:
	.word	0x3ff00000
	.word	0x0
.text
	.align 4
	.global _confrac
	.proc	0105
_confrac:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	ld [%i0],%o1
	sethi %hi(65535),%o0
	or %o0,%lo(65535),%o0
	and %o1,%o0,%l2
	ld [%i0+4],%o0
	sethi %hi(-16777216),%o1
	andn %o0,%o1,%o1
	sethi %hi(8388607),%o0
	or %o0,%lo(8388607),%o0
	sub %o0,%o1,%l0
	sethi %hi(_avma),%o0
	ld [%o0+%lo(_avma)],%l5
	add %l2,-2,%l4
	sll %l4,5,%l4
	add %l4,%l0,%l4
	add %l4,63,%l3
	sra %l3,5,%l3
	call _cgeti,0
	mov %l3,%o0
	sra %l0,5,%o1
	mov 0,%g2
	cmp %g2,%o1
	bge L259
	mov %o0,%l1
L261:
	sll %g2,2,%o0
	add %g2,1,%g2
	cmp %g2,%o1
	bl L261
	st %g0,[%l1+%o0]
L259:
	andcc %l0,31,%l0
	bne L262
	mov 2,%g3
	cmp %g3,%l2
	bge L280
	sll %l3,2,%o0
L266:
	sll %g2,2,%o0
	sll %g3,2,%o1
	ld [%i0+%o1],%o1
	st %o1,[%l1+%o0]
	add %g3,1,%g3
	cmp %g3,%l2
	bl L266
	add %g2,1,%g2
	b L280
	sll %l3,2,%o0
L262:
	cmp %g3,%l2
	bge L269
	mov 0,%o3
	mov 32,%o0
	sub %o0,%l0,%o4
L271:
	sll %g2,2,%o1
	sll %g3,2,%o0
	ld [%i0+%o0],%o2
	add %g2,1,%g2
	srl %o2,%l0,%o0
	add %o0,%o3,%o0
	st %o0,[%l1+%o1]
	add %g3,1,%g3
	cmp %g3,%l2
	bl L271
	sll %o2,%o4,%o3
L269:
	sll %l3,2,%o0
	add %o0,%l1,%o0
	st %o3,[%o0-8]
	sll %l3,2,%o0
L280:
	add %o0,%l1,%o0
	st %g0,[%o0-4]
	st %l4,[%fp-16]
	ld [%fp-16],%f6
	fitod %f6,%f2
	sethi %hi(LC0),%l6
	ldd [%l6+%lo(LC0)],%f4
	fmuld %f2,%f4,%f2
	sethi %hi(LC1),%l6
	ldd [%l6+%lo(LC1)],%f4
	faddd %f2,%f4,%f2
	fdtoi %f2,%f2
	st %f2,[%fp-16]
	ld [%fp-16],%l0
	add %l0,17,%l2
	mov %l2,%o0
	call .div,0
	mov 9,%o1
	call _cgeti,0
	mov %o0,%l2
	mov %o0,%i0
	mov 1,%g3
	cmp %g3,%l2
	bge L273
	st %l0,[%i0]
L279:
	addcc %l3,-1,%g2
	bneg L276
	mov 0,%o3
	sethi %hi(1000000000),%o0
	or %o0,%lo(1000000000),%o7
L278:
	sll %g2,2,%o1
	mov %o3,%o2
	ld [%l1+%o1],%o0
	 
        or      %o0,%o7,%o4      
        mov     %o0,%y
        andncc  %o4,0xfff,%g0
        be      2f
        andcc   %g0,%g0,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%g0,%o4
        tst     %o7
        bl,a    1f
        add     %o4,%o0,%o4
1:      mov     %o4,%o3
        b       3f 
        rd      %y,%o0
2:      clr     %o3
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%o7,%o4
        mulscc  %o4,%g0,%o4
        rd      %y,%o5
        sll     %o4,12,%o4
        srl     %o5,20,%o5
        or      %o5,%o4,%o0
3:       

	addcc %o2,%o0,%l6
	addx %o3,%g0,%o3
	addcc %g2,-1,%g2
	bpos L278
	st %l6,[%l1+%o1]
L276:
	sll %g3,2,%o0
	add %g3,1,%g3
	cmp %g3,%l2
	bl L279
	st %o3,[%i0+%o0]
L273:
	sethi %hi(_avma),%o0
	st %l5,[%o0+%lo(_avma)]
	ret
	restore
	.align 4
	.global _divss
	.proc	0105
_divss:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	cmp %i1,0
	bne L290
	sethi %hi(-2147483648),%o0
	call _err,0
	mov 23,%o0
	sethi %hi(-2147483648),%o0
L290:
	cmp %i0,%o0
	bne L283
	sethi %hi(_hiremainder),%o0
	call _stoi,0
	mov %i0,%o0
	call _divis,0
	mov %i1,%o1
	b,a L289
L283:
	st %g0,[%o0+%lo(_hiremainder)]
	cmp %i0,0
	bge L284
	mov %i0,%o0
	sub %g0,%i0,%o0
L284:
	cmp %i1,0
	bge L285
	mov %i1,%o1
	sub %g0,%i1,%o1
L285:
	sethi %hi(_hiremainder),%l0
	call _divul3,0
	or %l0,%lo(_hiremainder),%o2
	cmp %i1,0
	bge L286
	mov %o0,%o1
	ld [%l0+%lo(_hiremainder)],%o0
	sub %g0,%o0,%o0
	st %o0,[%l0+%lo(_hiremainder)]
	sub %g0,%o1,%o1
L286:
	cmp %i0,0
	bl,a L287
	sub %g0,%o1,%o1
L287:
	call _stoi,0
	mov %o1,%o0
L289:
	ret
	restore %g0,%o0,%o0
	.align 4
	.global _modss
	.proc	0105
_modss:
	!#PROLOGUE# 0
	save %sp,-120,%sp
	!#PROLOGUE# 1
	cmp %i1,0
	bne L300
	sethi %hi(-2147483648),%o0
	call _err,0
	mov 38,%o0
	sethi %hi(-2147483648),%o0
L300:
	cmp %i0,%o0
	bne L293
	mov %i0,%o0
	call _stoi,0
	nop
	call _modis,0
	mov %i1,%o1
	b L299
	mov %o0,%i0
L293:
	cmp %o0,0
	bge L294
	st %g0,[%fp-20]
	sub %g0,%o0,%o0
L294:
	cmp %i1,0
	bl,a L295
	sub %g0,%i1,%i1
L295:
	mov %i1,%o1
	call _divul3,0
	add %fp,-20,%o2
	ld [%fp-20],%o0
	cmp %o0,0
	bne L296
	nop
	sethi %hi(_gzero),%o0
	b L299
	ld [%o0+%lo(_gzero)],%i0
L296:
	bge L297
	nop
	call _stoi,0
	sub %i1,%o0,%o0
	b L299
	mov %o0,%i0
L297:
	call _stoi,0
	ld [%fp-20],%o0
	mov %o0,%i0
L299:
	ret
	restore
	.align 4
	.global _resss
	.proc	0105
_resss:
	!#PROLOGUE# 0
	save %sp,-120,%sp
	!#PROLOGUE# 1
	cmp %i1,0
	bne L307
	mov %i0,%o0
	call _err,0
	mov 40,%o0
	mov %i0,%o0
L307:
	cmp %o0,0
	bge L303
	st %g0,[%fp-20]
	sub %g0,%o0,%o0
L303:
	cmp %i1,0
	bge L304
	mov %i1,%o1
	sub %g0,%i1,%o1
L304:
	call _divul3,0
	add %fp,-20,%o2
	cmp %i1,0
	bge L305
	ld [%fp-20],%o0
	call _stoi,0
	sub %g0,%o0,%o0
	b,a L306
L305:
	call _stoi,0
	nop
L306:
	ret
	restore %g0,%o0,%o0
	.align 4
	.global _divsi
	.proc	0105
_divsi:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	ld [%i1+4],%o0
	sra %o0,24,%o2
	sethi %hi(65535),%o1
	or %o1,%lo(65535),%o1
	cmp %o2,0
	bne L309
	and %o0,%o1,%l0
	call _err,0
	mov 24,%o0
L309:
	cmp %i0,0
	be L311
	cmp %l0,3
	bg L318
	sethi %hi(_hiremainder),%o0
	ld [%i1+8],%o0
	cmp %o0,0
	bge L310
	sethi %hi(-2147483648),%o0
L311:
	sethi %hi(_hiremainder),%o0
L318:
	st %i0,[%o0+%lo(_hiremainder)]
	sethi %hi(_gzero),%o0
	b L316
	ld [%o0+%lo(_gzero)],%i0
L310:
	cmp %i0,%o0
	bne L312
	sethi %hi(_hiremainder),%o0
	call _stoi,0
	mov %i0,%o0
	mov %i1,%o1
	call _dvmdii,0
	mov 0,%o2
	b L316
	mov %o0,%i0
L312:
	st %g0,[%o0+%lo(_hiremainder)]
	cmp %i0,0
	bge L313
	mov %i0,%o0
	sub %g0,%i0,%o0
L313:
	ld [%i1+8],%o1
	sethi %hi(_hiremainder),%l0
	call _divul3,0
	or %l0,%lo(_hiremainder),%o2
	mov %o0,%o1
	ldsb [%i1+4],%o0
	cmp %o0,0
	bge L319
	cmp %i0,0
	ld [%l0+%lo(_hiremainder)],%o0
	sub %g0,%o0,%o0
	st %o0,[%l0+%lo(_hiremainder)]
	sub %g0,%o1,%o1
L319:
	bl,a L315
	sub %g0,%o1,%o1
L315:
	call _stoi,0
	mov %o1,%o0
	mov %o0,%i0
L316:
	ret
	restore
	.align 4
	.global _divis
	.proc	0105
_divis:
	!#PROLOGUE# 0
	save %sp,-120,%sp
	!#PROLOGUE# 1
	ld [%i0+4],%o1
	sra %o1,24,%l4
	sethi %hi(65535),%o0
	or %o0,%lo(65535),%o0
	cmp %i1,0
	bne L321
	and %o1,%o0,%l3
	call _err,0
	mov 26,%o0
L321:
	cmp %l4,0
	bne L322
	cmp %i1,0
	sethi %hi(_hiremainder),%o0
	b L336
	st %g0,[%o0+%lo(_hiremainder)]
L322:
	bge,a L337
	ld [%i0+8],%o0
	subcc %g0,%i1,%i1
	bpos L323
	sub %g0,%l4,%l4
	call _stoi,0
	mov %i1,%o0
	mov %o0,%o1
	mov %i0,%o0
	call _dvmdii,0
	mov 0,%o2
	b L335
	mov %o0,%i0
L323:
	ld [%i0+8],%o0
L337:
	cmp %i1,%o0
	bleu L325
	cmp %l3,3
	bne L326
	sethi %hi(_hiremainder),%l0
	call _itos,0
	mov %i0,%o0
	st %o0,[%l0+%lo(_hiremainder)]
L336:
	sethi %hi(_gzero),%o0
	b L335
	ld [%o0+%lo(_gzero)],%i0
L326:
	call _cgeti,0
	add %l3,-1,%o0
	mov %o0,%l2
	mov 1,%l1
	ld [%i0+8],%o0
	b L328
	st %o0,[%fp-20]
L325:
	call _cgeti,0
	mov %l3,%o0
	mov %o0,%l2
	mov 0,%l1
	st %g0,[%fp-20]
L328:
	add %l1,2,%l0
	cmp %l0,%l3
	bge,a L338
	ld [%l2],%o0
L332:
	sll %l0,2,%o0
	ld [%i0+%o0],%o0
	mov %i1,%o1
	call _divul3,0
	add %fp,-20,%o2
	sub %l0,%l1,%o1
	sll %o1,2,%o1
	add %l0,1,%l0
	cmp %l0,%l3
	bl L332
	st %o0,[%l2+%o1]
	ld [%l2],%o0
L338:
	sethi %hi(-16777216),%o1
	andn %o0,%o1,%o1
	sll %l4,24,%o0
	add %o1,%o0,%o1
	st %o1,[%l2+4]
	sethi %hi(_hiremainder),%o1
	cmp %l4,0
	bge L333
	or %o1,%lo(_hiremainder),%o2
	ld [%fp-20],%o0
	sub %g0,%o0,%o0
	b L334
	st %o0,[%o1+%lo(_hiremainder)]
L333:
	ld [%fp-20],%o0
	st %o0,[%o2]
L334:
	mov %l2,%i0
L335:
	ret
	restore
	.align 4
	.global _dvmdii
	.proc	0105
_dvmdii:
	!#PROLOGUE# 0
	save %sp,-152,%sp
	!#PROLOGUE# 1
	mov %i0,%l0
	mov %i2,%i4
	ldsb [%l0+4],%g4
	st %g4,[%fp-36]
	ldsb [%i1+4],%g1
	cmp %g1,0
	bne L340
	st %g1,[%fp-44]
	call _err,0
	mov 36,%o0
L340:
	ld [%fp-36],%g4
	cmp %g4,0
	bne,a L341
	ld [%l0+4],%o0
	cmp %i4,-1
	be L428
	cmp %i4,0
	be L428
	sethi %hi(_gzero),%o1
	ld [%o1+%lo(_gzero)],%o0
	st %o0,[%i4]
	b L427
	ld [%o1+%lo(_gzero)],%i0
L341:
	sethi %hi(65535),%o1
	or %o1,%lo(65535),%o1
	and %o0,%o1,%l6
	ld [%i1+4],%o0
	and %o0,%o1,%i3
	subcc %l6,%i3,%i5
	bpos,a L344
	sethi %hi(_avma),%o0
	cmp %i4,-1
	bne L345
	cmp %i4,0
	call _icopy,0
	mov %l0,%o0
	b L427
	mov %o0,%i0
L345:
	be L433
	sethi %hi(_gzero),%o0
	call _icopy,0
	mov %l0,%o0
	b L428
	st %o0,[%i4]
L344:
	ld [%o0+%lo(_avma)],%o0
	st %o0,[%fp-28]
	ld [%fp-36],%g1
	cmp %g1,0
	bge L434
	cmp %i3,3
	ld [%fp-44],%g4
	sub %g0,%g4,%g4
	st %g4,[%fp-44]
L434:
	bne L348
	nop
	ld [%i1+8],%i1
	ld [%l0+8],%o0
	cmp %i1,%o0
	bleu L349
	add %l0,8,%l1
	add %l6,-1,%l4
	st %o0,[%fp-20]
	b L350
	add %l0,12,%l1
L349:
	mov %l6,%l4
	st %g0,[%fp-20]
L350:
	call _cgeti,0
	mov %l4,%o0
	mov %o0,%l5
	addcc %l4,-2,%l3
	be L352
	add %l5,8,%l2
L353:
	ld [%l1],%o0
	add %l1,4,%l1
	mov %i1,%o1
	call _divul3,0
	add %fp,-20,%o2
	st %o0,[%l2]
	addcc %l3,-1,%l3
	bne L353
	add %l2,4,%l2
L352:
	cmp %i4,-1
	bne L354
	cmp %l4,2
	ld [%fp-28],%g1
	sethi %hi(_avma),%o0
	st %g1,[%o0+%lo(_avma)]
	ld [%fp-20],%o0
	cmp %o0,0
	bne L355
	nop
L428:
	sethi %hi(_gzero),%o0
L433:
	b L427
	ld [%o0+%lo(_gzero)],%i0
L355:
	call _cgeti,0
	mov 3,%o0
	mov %o0,%i0
	ld [%fp-36],%g4
	sll %g4,24,%o0
	add %o0,3,%o0
	st %o0,[%i0+4]
	ld [%fp-20],%o0
	b L427
	st %o0,[%i0+8]
L354:
	be L356
	sethi %hi(-16777216),%o1
	ld [%l5],%o0
	andn %o0,%o1,%o1
	ld [%fp-44],%g1
	sll %g1,24,%o0
	add %o1,%o0,%o1
	b L357
	st %o1,[%l5+4]
L356:
	ld [%fp-28],%g4
	sethi %hi(_avma),%o0
	st %g4,[%o0+%lo(_avma)]
	sethi %hi(_gzero),%o0
	ld [%o0+%lo(_gzero)],%l5
L357:
	cmp %i4,0
	bne L358
	ld [%fp-20],%o0
L430:
	b L427
	mov %l5,%i0
L358:
	cmp %o0,0
	bne L359
	sethi %hi(_gzero),%o0
	ld [%o0+%lo(_gzero)],%o0
	b L430
	st %o0,[%i4]
L359:
	call _cgeti,0
	mov 3,%o0
	mov %o0,%i0
	ld [%fp-36],%g1
	sll %g1,24,%o0
	add %o0,3,%o0
	st %o0,[%i0+4]
	ld [%fp-20],%o0
	st %o0,[%i0+8]
	b L430
	st %i0,[%i4]
L348:
	call _cgeti,0
	mov %l6,%o0
	mov %o0,%l5
	call _bfffo,0
	ld [%i1+8],%o0
	orcc %o0,%g0,%l7
	be L362
	add %l0,8,%l1
	call _cgeti,0
	mov %i3,%o0
	mov %o0,%i0
	ld [%i1+8],%o3
	add %i1,12,%o1
	mov 32,%o0
	sub %o0,%l7,%o0
	srl %o3,%o0,%o0
	st %o0,[%fp-20]
	sll %o3,%l7,%g2
	addcc %i3,-3,%l3
	be L364
	add %i0,8,%o2
	mov 32,%o0
	sub %o0,%l7,%o4
L365:
	ld [%o1],%o3
	add %o1,4,%o1
	srl %o3,%o4,%o0
	st %o0,[%fp-20]
	add %g2,%o0,%o0
	st %o0,[%o2]
	add %o2,4,%o2
	addcc %l3,-1,%l3
	bne L365
	sll %o3,%l7,%g2
L364:
	st %g2,[%o2]
	mov 0,%g2
	add %l0,8,%l1
	addcc %l6,-2,%l3
	be L367
	add %l5,4,%l2
	mov 32,%o0
	sub %o0,%l7,%o1
L368:
	ld [%l1],%o3
	add %l1,4,%l1
	srl %o3,%o1,%o0
	st %o0,[%fp-20]
	add %g2,%o0,%o0
	st %o0,[%l2]
	add %l2,4,%l2
	addcc %l3,-1,%l3
	bne L368
	sll %o3,%l7,%g2
L367:
	b L369
	st %g2,[%l2]
L362:
	st %g0,[%l5+4]
	addcc %l6,-2,%l0
	be L371
	add %l5,8,%l2
L372:
	ld [%l1],%o0
	st %o0,[%l2]
	add %l1,4,%l1
	addcc %l0,-1,%l0
	bne L372
	add %l2,4,%l2
L371:
	mov %i1,%i0
L369:
	ld [%i0+8],%i1
	ld [%i0+12],%i2
	addcc %i5,1,%l3
	be L374
	add %l5,4,%l2
	sll %i3,2,%l1
L396:
	ld [%l2],%o0
	cmp %o0,%i1
	bne L375
	add %l2,4,%l2
	mov -1,%o7
	mov %i1,%o3
	ld [%l2],%o0
	add %o3,%o0,%o1
	cmp %o1,%o3
	addx %g0,0,%o2
	b L376
	mov %o1,%g2
L375:
	ld [%l2-4],%o0
	st %o0,[%fp-20]
	ld [%l2],%o0
	mov %i1,%o1
	call _divul3,0
	add %fp,-20,%o2
	mov %o0,%o7
	mov 0,%o2
	ld [%fp-20],%g2
L376:
	cmp %o2,0
	bne,a L435
	st %g0,[%fp-20]
	mov %o7,%o3
	 
        or      %o3,%i2,%o4      
        mov     %o3,%y
        andncc  %o4,0xfff,%g0
        be      2f
        andcc   %g0,%g0,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%g0,%o4
        tst     %i2
        bl,a    1f
        add     %o4,%o3,%o4
1:      mov     %o4,%g4
        b       3f 
        rd      %y,%o3
2:      clr     %g4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%i2,%o4
        mulscc  %o4,%g0,%o4
        rd      %y,%o5
        sll     %o4,12,%o4
        srl     %o5,20,%o5
        or      %o5,%o4,%o3
3:       

	st %g4,[%fp-20]
	ld [%l2+4],%o0
	cmp %o3,%o0
	sub %o3,%o0,%o5
	ld [%fp-20],%o3
	addx %g0,0,%o2
	subx %o3,%g2,%o1
	cmp %g2,%o3
	bgu L432
	mov %g2,%o0
	b L436
	cmp %o0,%o3
L388:
	mov %i2,%o0
	cmp %o3,%o0
	sub %o3,%o0,%o5
	mov %o4,%o3
	mov %i1,%o0
	addx %g0,0,%o2
	subx %o3,%o0,%o1
	cmp %o0,%o3
	bleu L436
	add %o7,-1,%o7
L432:
	b L385
	mov 1,%o2
L436:
	blu,a L385
	mov 0,%o2
L385:
	cmp %o2,0
	bne L377
	mov %o1,%o4
	cmp %o1,0
	bne L388
	mov %o5,%o3
L377:
	st %g0,[%fp-20]
L435:
	add %l2,%l1,%o0
	add %o0,-8,%g2
	addcc %i3,-2,%l0
	be L390
	add %i0,%l1,%g3
L391:
	ld [%fp-20],%o3
	add %g3,-4,%g3
	mov %o7,%o1
	ld [%g3],%g4
	 
        or      %o1,%g4,%o4      
        mov     %o1,%y
        andncc  %o4,0xfff,%g0
        be      2f
        andcc   %g0,%g0,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g0,%o4
        tst     %g4
        bl,a    1f
        add     %o4,%o1,%o4
1:      mov     %o4,%g1
        b       3f 
        rd      %y,%o1
2:      clr     %g1
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g4,%o4
        mulscc  %o4,%g0,%o4
        rd      %y,%o5
        sll     %o4,12,%o4
        srl     %o5,20,%o5
        or      %o5,%o4,%o1
3:       

	st %g1,[%fp-20]
	ld [%fp-20],%g1
	addcc %o3,%o1,%o2
	addx %g1,%g0,%g1
	st %g1,[%fp-20]
	add %g2,-4,%g2
	ld [%g2],%o3
	sub %o3,%o2,%o1
	cmp %o3,%o2
	st %o1,[%g2]
	ld [%fp-20],%o0
	addx %g0,%o0,%o0
	addcc %l0,-1,%l0
	bne L391
	st %o0,[%fp-20]
L390:
	ld [%l2-4],%o1
	ld [%fp-20],%o0
	cmp %o1,%o0
	bgeu,a L437
	addcc %l3,-1,%l3
	mov 0,%o2
	add %o7,-1,%o7
	add %l2,%l1,%g2
	add %g2,-8,%g2
	addcc %i3,-2,%l0
	be L392
	add %i0,%l1,%g3
	add %g2,-4,%g2
L438:
	subcc %g0,%o2,%g0
	add %g3,-4,%g3
	ld [%g2],%g4
	ld [%g3],%g1
	addxcc %g4,%g1,%g4
	st %g4,[%g2]
	addx %g0,%g0,%o2
	addcc %l0,-1,%l0
	bne,a L438
	add %g2,-4,%g2
L392:
	addcc %l3,-1,%l3
L437:
	bne L396
	st %o7,[%l2-4]
L374:
	sethi %hi(_avma),%o0
	cmp %i4,-1
	be L397
	ld [%o0+%lo(_avma)],%i0
	add %i5,2,%l1
	sll %l1,2,%o0
	add %l5,%o0,%l2
	ld [%l5+4],%o0
	cmp %o0,0
	be L398
	cmp %i5,0
	b L399
	add %i5,3,%l1
L398:
	be,a L399
	st %g0,[%fp-44]
L399:
	call _cgeti,0
	mov %l1,%o0
	st %o0,[%fp-52]
	sll %l1,2,%o0
	ld [%fp-52],%g4
	addcc %l1,-2,%l0
	be L402
	add %g4,%o0,%o1
L403:
	add %o1,-4,%o1
	add %l2,-4,%l2
	ld [%l2],%o0
	addcc %l0,-1,%l0
	bne L403
	st %o0,[%o1]
L402:
	cmp %l1,2
	bgu L404
	mov 2,%o0
	ld [%fp-52],%g1
	b L397
	st %o0,[%g1+4]
L404:
	ld [%fp-52],%g4
	ld [%g4],%o0
	sethi %hi(-16777216),%o1
	andn %o0,%o1,%o1
	ld [%fp-44],%g1
	sll %g1,24,%o0
	add %o1,%o0,%o1
	st %o1,[%g4+4]
L397:
	cmp %i4,0
	be L439
	cmp %i4,-1
	add %i5,2,%l0
L409:
	cmp %l0,%l6
	bge L441
	sll %l0,2,%o0
	ld [%l5+%o0],%o0
	cmp %o0,0
	be,a L409
	add %l0,1,%l0
	cmp %l0,%l6
L441:
	bne L411
	sub %l6,%l0,%o0
	sethi %hi(_gzero),%o0
	call _icopy,0
	ld [%o0+%lo(_gzero)],%o0
	b L406
	mov %o0,%l4
L411:
	call _cgeti,0
	add %o0,2,%o0
	mov %o0,%l4
	ld [%l4],%o0
	cmp %l7,0
	bne L413
	st %o0,[%l4+4]
	cmp %l0,%l6
	bge L418
	mov 2,%l3
L417:
	sll %l3,2,%o0
	sll %l0,2,%o1
	ld [%l5+%o1],%o1
	st %o1,[%l4+%o0]
	add %l0,1,%l0
	cmp %l0,%l6
	bl L417
	add %l3,1,%l3
	b L440
	ld [%l4+4],%o0
L413:
	st %g0,[%fp-20]
	sll %l0,2,%o0
	ld [%l5+%o0],%o3
	add %l0,1,%l0
	mov 32,%o0
	sub %o0,%l7,%o0
	sll %o3,%o0,%o0
	st %o0,[%fp-20]
	srl %o3,%l7,%o2
	cmp %o2,0
	be L419
	mov %o0,%g2
	st %o2,[%l4+8]
	b L420
	mov 1,%o0
L419:
	ld [%l4],%o0
	add %o0,-1,%o0
	st %o0,[%l4+4]
	add %l4,4,%l4
	sethi %hi(_avma),%o1
	ld [%o1+%lo(_avma)],%o0
	add %o0,4,%o0
	st %o0,[%o1+%lo(_avma)]
	ld [%l4],%o0
	st %o0,[%l4+4]
	mov 0,%o0
L420:
	cmp %l0,%l6
	bge L418
	add %o0,2,%l3
	mov 32,%o0
	sub %o0,%l7,%o4
L424:
	sll %l3,2,%o2
	sll %l0,2,%o0
	ld [%l5+%o0],%o3
	sll %o3,%o4,%o1
	st %o1,[%fp-20]
	srl %o3,%l7,%o0
	add %o0,%g2,%o0
	st %o0,[%l4+%o2]
	mov %o1,%g2
	add %l0,1,%l0
	cmp %l0,%l6
	bl L424
	add %l3,1,%l3
L418:
	ld [%l4+4],%o0
L440:
	sethi %hi(-16777216),%o1
	andn %o0,%o1,%o1
	ld [%fp-36],%g4
	sll %g4,24,%o0
	add %o1,%o0,%o1
	st %o1,[%l4+4]
L406:
	cmp %i4,-1
L439:
	bne L425
	cmp %i4,0
	ld [%fp-28],%o0
	mov %i0,%o1
	call _gerepile,0
	mov %l4,%o2
	b L427
	mov %o0,%i0
L425:
	be L426
	ld [%fp-28],%o0
	mov %i0,%o1
	call _gerepile,0
	mov 0,%o2
	and %o0,-4,%o0
	add %l4,%o0,%o1
	st %o1,[%i4]
	ld [%fp-52],%g1
	b L427
	add %g1,%o0,%i0
L426:
	mov %i0,%o1
	call _gerepile,0
	ld [%fp-52],%o2
	mov %o0,%i0
L427:
	ret
	restore
	.align 4
	.global _mulul3
	.proc	016
_mulul3:
	!#PROLOGUE# 0
	save %sp,-112,%sp
	!#PROLOGUE# 1
	 
        or      %i0,%i1,%o4      
        mov     %i0,%y
        andncc  %o4,0xfff,%g0
        be      2f
        andcc   %g0,%g0,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%g0,%o4
        tst     %i1
        bl,a    1f
        add     %o4,%i0,%o4
1:      mov     %o4,%g2
        b       3f 
        rd      %y,%i0
2:      clr     %g2
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%i1,%o4
        mulscc  %o4,%g0,%o4
        rd      %y,%o5
        sll     %o4,12,%o4
        srl     %o5,20,%o5
        or      %o5,%o4,%i0
3:       

	st %g2,[%i2]
	ret
	restore
	.global _in_saved_avma
	.common _in_saved_avma,8,"bss"
