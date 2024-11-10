extern ll_clear

; void ll_free_c(ll_t *list)
; {
;     ll_clear(list);
; }

global ll_free
ll_free:
    ; there is only nodes in the list, if we remove all nodes,
    ; nothing else need to be removed.
    call ll_clear
    ret
