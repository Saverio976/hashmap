global djb2

djb2:
    push rbp
    mov rbp, rsp
    push r8
    push r9
    push r10

.instanciate:
    mov r8, 0
    mov r9, r8

.check_null:
    test rdi, rdi           ; test if NULL pointer
    jz .end

.instanciate_hash:
    mov r8, 5381

.loop:
    cmp [rdi], byte 0       ; test for '\0'
    jz .end
    movsx r9, byte [rdi]
    mov r10, r8             ; tmp hash
    shl r8, 5               ; c:{hash << 5}
    add r8, r10             ; c:{hash += old_hash}
    add r8, r9              ; c:{hash += char}
    inc rdi                 ; pointing to next char
    jmp .loop

.end:
    mov rax, r8
    pop r10
    pop r9
    pop r8
    leave
    ret
