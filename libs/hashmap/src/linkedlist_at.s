extern ll_next

global ll_at
ll_at:
    mov r8, rdi         ; initial value

.check_null:
    test rdi, rdi
    jz .end_null

.initialize:
    mov rax, rdi
    jmp .loop_middle

.loop:                  ; get the next element (until dec == 0)
    dec rsi
    call ll_next
    mov rdi, rax
    cmp r8, rdi         ; we looped back to the first element
    je .end_null        ; => return not found
.loop_middle:
    test rsi, rsi
    jnz .loop

.end:                   ; rax has already the pointer to the element
    ret

.end_null:
    xor rax, rax
    ret
