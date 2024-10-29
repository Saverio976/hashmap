global badhash
badhash:

.check_null:
    test rdi, rdi           ; test if NULL pointer
    jz .end_null

.instanciate:
    mov rax, 0
    xor r8, r8
    jmp .loop_middle

.loop:
    add rax, r8             ; add char to the final hash
    inc rdi                 ; pointing to next char
.loop_middle:
    movsx r8, byte [rdi]
    cmp r8b, 0
    jne .loop
    ret

.end_null:
    mov rax, 0
    ret
