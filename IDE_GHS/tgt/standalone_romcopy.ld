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
// Program layout for starting in ROM, copying text and data to RAM,
// and then running out of RAM.
//

SECTIONS
{
//
// RAM SECTIONS
//
    .boottext ALIGN(4) : {
	  // All .text which is reachable between
	  // _start and __ghs_ind_crt1 needs to be
	  // pulled into .boottext and left
	  // uncompressed.
	  crt0.o(.text)
	  libstartup.a(*)(.text)
	  libsys.a(ind_crt1.o)(.text)
	  libarch.a(*)(.text)
    }							      > sram_memory
    .syscall					   ALIGN(4) : > .
    .text						    : > .

    .data						    : > .
    .bss						    : > .

    .sdabase			                   ALIGN(4) : > .
    .sdata					            : > .
    .sbss						    : > .

    .heap	                 ALIGN(8) PAD(heap_reserve) : > .

    .stack                  ALIGN(4) PAD(stack_reserve) ABS : > .
    .tdata					        ABS : > zda_memory
    .zdata			                        ABS : > .
    .zbss					        ABS : > .

//
// ROM SECTIONS
//

    .rozdata				                    : > flash_memory
    .robase				           ALIGN(4) : > .
    .rosdata						    : > .
    .rodata						    : > .

    .ROM.boottext		    ALIGN(4) ROM(.boottext) : > .
    .ROM.syscall		     ALIGN(4) ROM(.syscall) : > .
    .secinfo						    : > .
    .fixaddr						    : > .
    .fixtype						    : > .

    .CROM.zdata				       CROM(.zdata) : > .
    .CROM.tdata				       CROM(.tdata) : > .
    .CROM.data				        CROM(.data) : > .
    .CROM.sdata				       CROM(.sdata) : > .
    .CROM.text			                CROM(.text) : > .

//
// These special symbols mark the bounds of RAM and ROM images of boot code.
// They are used by the GHS startup code (_start and __ghs_ind_crt0).
//
    ___ghs_rambootcodestart  = ADDR(.boottext);
    ___ghs_rambootcodeend    = ENDADDR(.text);	
    ___ghs_rombootcodestart  = ADDR(.ROM.boottext);
    ___ghs_rombootcodeend    = ENDADDR(.fixtype);

//
// These special symbols mark the bounds of RAM and ROM memory.
// They are used by the MULTI debugger.
//
    ___ghs_ramstart  = MEMADDR(sram_memory);
    ___ghs_ramend    = MEMENDADDR(sram_memory);
    ___ghs_romstart  = MEMADDR(flash_memory);
    ___ghs_romend    = MEMENDADDR(flash_memory);

//
// This special symbol marks the the first address executed after the
// ROM to RAM copy is complete.  It is used by the MULTI debugger.
//
    ___ghs_after_romcopy = ___ghs_ind_crt1;
}






