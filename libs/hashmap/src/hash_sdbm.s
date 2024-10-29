global sdbm
sdbm:

.check_null:
    test rdi, rdi           ; test if NULL pointer
    jz .end_null

.instanciate_hash:
    xor rax, rax
    xor r9, r9
    jmp .loop_middle

.loop:
    mov r11, rax
    mov r9, rax
    shl r9, 6               ; c:{old_hash << 6}
    mov r10, rax
    shl r10, 16             ; c:{old_hash << 16}
    mov rax, r8             ; c:{hash = char}
    add rax, r9             ; c:{hash += (old_hash << 6)}
    add rax, r10            ; c:{hash += (old_hash << 16)}
    sub rax, r11            ; c:{hash -= old_hash}
    inc rdi
.loop_middle:
    movsx r8, byte [rdi]
    cmp r8b, 0
    jnz .loop
    ret

.end_null:
    mov rax, 0
    ret
