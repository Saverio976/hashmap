global sdbm

sdbm:
    push rbp
    mov rbp, rsp
    push r8
    push r9
    push r10
    push r11
    push r12

.instanciate:
    xor r8, r8
    xor r9, r9

.check_null:
    test rdi, rdi           ; test if NULL pointer
    jz .end

.loop:
    cmp [rdi], byte 0       ; test for '\0'
    jz .end
    movsx r9, byte [rdi]
    mov r12, r8
    mov r10, r8             ; tmp hash
    shl r10, 6              ; c:{hash << 6}
    mov r11, r8             ; tmp hash
    shl r11, 16             ; c:{hash << 16}
    mov r8, r9              ; c:{hash += char}
    add r8, r10             ; c:{hash += (hash << 6)}
    add r8, r11             ; c:{hash += (hash << 16)}
    sub r8, r12             ; c:{hash -= old_hash}
    inc rdi                 ; pointing to next char
    jmp .loop

.end:
    mov rax, r8
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    leave
    ret
