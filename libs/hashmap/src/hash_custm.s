global custm

do_calc:
    shl rdi, 3
    add rdi, rsi
    mov rax, rdi
    ret

custm:

.check_null:
    test rdi, rdi
    jz .end_null

.initialize:
    mov r8, rdi
    xor r9, r9
    xor rsi, rsi
    jmp .loop_middle

.loop:
    mov rdi, r9
    call do_calc
    mov rsi, rax
    inc r8
.loop_middle:
    movsx r9, byte [r8]
    test r9b, r9b
    jnz .loop
    ret

.end_null:
    xor rax, rax
    ret
