MEMORY {
    sram_memory           : ORIGIN = 0x00400000, LENGTH = 32M
    zda_memory            : ORIGIN = 0xffff8000, LENGTH = 28K
    sfr_memory		  : ORIGIN = 0xfffff000, LENGTH = 4K

    flash_rsvd1           : ORIGIN = 0x00000000, LENGTH = 0x1000
    flash_memory          : ORIGIN = .,          LENGTH = 4M - 0x1000
}
DEFAULTS {

    heap_reserve = 1M
    stack_reserve = 64K

}
//
// Program layout for starting in ROM, copying data to RAM,
// and continuing to execute out of ROM.
//

SECTIONS
{
//
// RAM SECTIONS
//
    .sdabase			                   ALIGN(4) : > sram_memory
    .sdata						    : > .
    .sbss						    : > .

    .data						    : > .
    .bss						    : > .

    .heap	                ALIGN(8) PAD(heap_reserve)  : > .

    .stack                  ALIGN(4) PAD(stack_reserve) ABS : > .
    .tdata					        ABS : > zda_memory
    .zdata			                        ABS : > .
    .zbss					        ABS : > .

//
// ROM SECTIONS
//

    .rozdata				                ABS : > flash_memory
    .robase				           ALIGN(4) : > .
    .rosdata						    : > .
    .rodata						    : > .
    .text						    : > .
    .syscall			                            : > .
    .secinfo						    : > .
    .fixaddr						    : > .
    .fixtype						    : > .
    .CROM.zdata				       CROM(.zdata) : > .
    .CROM.tdata				       CROM(.tdata) : > .
    .CROM.data				        CROM(.data) : > .
    .CROM.sdata				       CROM(.sdata) : > .

//
// These special symbols mark the bounds of RAM and ROM memory.
// They are used by the MULTI debugger.
//
    ___ghs_ramstart  = MEMADDR(sram_memory);
    ___ghs_ramend    = MEMENDADDR(sram_memory);
    ___ghs_romstart  = MEMADDR(flash_memory);
    ___ghs_romend    = MEMENDADDR(flash_memory);

//
// These special symbols mark the bounds of RAM and ROM images of boot code.
// They are used by the GHS startup code (_start and __ghs_ind_crt0).
//
    ___ghs_rambootcodestart  = 0;
    ___ghs_rambootcodeend    = 0;
    ___ghs_rombootcodestart  = ADDR(.text);
    ___ghs_rombootcodeend    = ENDADDR(.fixtype);
}
