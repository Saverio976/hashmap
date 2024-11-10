extern ll_free

global hm_internal_free
hm_internal_free:
; rdi = array
; rsi = capacity

.initialize:
    push r12
    jmp .loop_middle

.loop:
    mov r12, rdi
    call ll_free
    mov rdi, r12
    add rdi, 8
    dec rsi
.loop_middle:
    test rsi, rsi
    jnz .loop
    pop r12
    ret
