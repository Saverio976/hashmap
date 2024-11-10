global djb2
djb2:

.check_null:
    test rdi, rdi           ; test if NULL pointer
    jz .end_null

.instanciate_hash:
    mov rax, 5381
    xor r8, r8
    jmp .loop_middle

; 'for' loop transformed into 'do while' loop
.loop:
    mov r9, rax             ; tmp hash
    shl rax, 5              ; c:{hash << 5}
    add rax, r9             ; c:{hash += old_hash}
    add rax, r8             ; c:{hash += char}
    inc rdi                 ; pointing to next char
.loop_middle:
    movsx r8, byte [rdi]
    test r8b, r8b          ; test for '\0'
    jnz .loop
    ret

.end_null:
    xor rax, rax
    ret
