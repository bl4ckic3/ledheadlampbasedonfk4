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
// Program layout for running out of RAM.
//
//

SECTIONS
{
//
// RAM SECTIONS
//
    .text						    : > sram_memory
    .syscall			                   ALIGN(4) : > .
    .secinfo						    : > .
    .fixaddr						    : > .
    .fixtype						    : > .

    .robase				           ALIGN(4) : > .
    .rosdata						    : > .
    .rodata						    : > .
 
    .sdabase			                   ALIGN(4) : > .
    .sdata						    : > .
    .sbss						    : > .

    .data						    : > .
    .bss						    : > .

    .heap	                ALIGN(8)  PAD(heap_reserve) : > .

    .stack                  ALIGN(4) PAD(stack_reserve) ABS : > .
    .tdata					        ABS : > zda_memory
    .rozdata					        ABS : > .
    .zdata			                        ABS : > . 
    .zbss					        ABS : > . 


//
// These special symbols mark the bounds of RAM and ROM memory.
// They are used by the MULTI debugger.
//
    ___ghs_ramstart  = MEMADDR(sram_memory);
    ___ghs_ramend    = MEMENDADDR(sram_memory);
    ___ghs_romstart  = MEMADDR(flash_memory);
    ___ghs_romend    = MEMENDADDR(flash_memory);
    
}


