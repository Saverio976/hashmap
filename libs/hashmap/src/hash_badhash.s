global badhash

badhash:
    push rbp
    mov rbp, rsp
    push r8
    push r9

.instanciate:
    mov r8, 0
    mov r9, r8

.check_null:
    test rdi, rdi
    jz .end

.loop:
    cmp [rdi], byte 0
    jz .end
    movsx r9, byte [rdi]
    add r8, r9
    inc rdi
    jmp .loop

.end:
    mov rax, r8
    pop r9
    pop r8
    leave
    ret
