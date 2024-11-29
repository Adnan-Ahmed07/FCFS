include 'emu8086.inc'
.stack 100h
.data
.code

main proc
    
    print 'enter number : '
    mov ah,01h
    int 21h
    sub al,48
    mov bl,al
    
    
    mov dl,10
    mov ah,02h
    int 21h
    
    mov dl,13
    mov ah,02h
    int 21h
    
    
    print 'enter numer two: '
    mov ah,01h
    int 21h
    sub al,48
    add bl,al
    
    
    mov dl,10
    mov ah,02h
    int 21h
    
    mov dl,13
    mov ah,02h
    int 21h
    
    print 'enter nuber three: '
    mov ah,01h
    int 21h
    sub al,48
    add bl,al
    
    add bl,48
    
    
    mov dl,10
    mov ah,02h
    int 21h
    
    mov dl,13
    mov ah,02h
    int 21h
    
    
    print 'result: '
    mov ah,02h
    mov dl,bl
    int 21h
    
    
    main endp

end main
