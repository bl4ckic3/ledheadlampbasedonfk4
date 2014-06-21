DEFAULTS {

    heap_reserve = 1M
    stack_reserve = 64K

}
//
// Program layout for PIC and PID built programs.
//
//

SECTIONS
{
        .stack     0xfff00000   PAD(stack_reserve)  ABS :
        .tdata                  MAX_SIZE(256)       ABS :
        .zdata     0xffff8000                       ABS :
        .zbss                                       ABS :

        .rozdata   0x00001000                       ABS :
        .robase      ALIGN(4)                       ABS :
        .rosdata                                    ABS :
        .rodata                                     ABS :
        .text      0x00000000                           :
        .syscall     ALIGN(4)                           :
        .secinfo                                        :
        .fixaddr                                        :
        .fixtype                                        :

        .sdabase   0x00000000                           :
        .sdata                                          :

        .sbss                                           :
        .bss                                            :
        .data                                           :

        .heap        ALIGN(8)   PAD(heap_reserve)       :
}
