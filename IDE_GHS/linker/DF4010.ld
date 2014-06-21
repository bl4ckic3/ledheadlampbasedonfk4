/*===========================================================================*/
/* Environment:                                                              */
/*              Device:         UPD70F4010                                   */
/*              IDE:            GHS Multi 2000 for V800                      */
/*===========================================================================*/

CONSTANTS
{
  zero_start = 0xffff8000
}

MEMORY
 {
  iROM    : ORIGIN = 0x00000000,  LENGTH = 1536k
  iRAM    : ORIGIN = 0xFEDE4000,  LENGTH = 112k
  iRsvd0  : ORIGIN = .         ,  LENGTH = 0
  bRAM    : ORIGIN = 0xFF760000,  LENGTH = 16k
 }

SECTIONS
 {

/* Start of internal ROM area (iROM) */

  .intvect      0x0000             :>iROM   /* start of interrupt vector */
  .intvect_end  0x107F             :>.      /* end   of interrupt vector */
  
/*Code Section - user defined*/
    BOOT_CONST  0x1100             :>.
    APP_VECT    0x2000             :>.
    ISR_SECT    0x2500             :>.
    
    FAST_SECT   0x4000             :>.
    .rosdata  align(4)               :>.
/*Const Section - MCAL defined*/    
  .CONST_ROM_1BIT                  :>.
  .CONST_ROM_8BIT                  :>.
  .CONST_ROM_16BIT                 :>.
  .CONST_ROM_32BIT                 :>.
  .CONST_ROM_UNSPECIFIED           :>.
  .CONST_FAR_ROM_1BIT              :>.
  .CONST_FAR_ROM_8BIT              :>.
  .CONST_FAR_ROM_16BIT             :>.
  .CONST_FAR_ROM_32BIT             :>.
  .CONST_FAR_ROM_UNSPECIFIED       :>.
  .MCU_CFG_DATA_UNSPECIFIED        :>.
  .MCU_CFG_DBTOC_UNSPECIFIED       :>.
  .LIN_CFG_DATA_UNSPECIFIED        :>.
  .LIN_CFG_DBTOC_UNSPECIFIED        :>.
  .GPT_CFG_DATA_UNSPECIFIED        :>.
  .GPT_CFG_DBTOC_UNSPECIFIED        :>.
  .WDG23_A_CFG_DATA_UNSPECIFIED        :>.
  .WDG23_A_CFG_DBTOC_UNSPECIFIED        :>.
  .PORT_CFG_DATA_UNSPECIFIED        :>.
  .PORT_CFG_DBTOC_UNSPECIFIED        :>.
  .DIO_CFG_DATA_UNSPECIFIED        :>.
  .DIO_CFG_DBTOC_UNSPECIFIED        :>.
  .PWM_CFG_DATA_UNSPECIFIED        :>.
  .PWM_CFG_DBTOC_UNSPECIFIED        :>.
  .SPI_CFG_DATA_UNSPECIFIED        :>.
  .SPI_CFG_DBTOC_UNSPECIFIED        :>.
  .ADC_CFG_DATA_UNSPECIFIED        :>.
  .ADC_CFG_DBTOC_UNSPECIFIED        :>.
  .ICU_CFG_DATA_UNSPECIFIED        :>.
  .ICU_CFG_DBTOC_UNSPECIFIED        :>.
  .FEE_CFG_DATA_UNSPECIFIED        :>.
  .FEE_CFG_DBTOC_UNSPECIFIED        :>.
  
    TEXT_SECT   0xE000             :>.
    .rodata   align(4)             :>.
   .osrodata   align(4)               :>.      /* constant datas in normal area */

  
    .text     align(4)             :>.
  .ostext     align(4)               :>.      /* program code area */

/*Code Section - MCAL defined*/
  .LIN_PUBLIC_CODE_ROM             :>.
  .LIN_PRIVATE_CODE_ROM            :>.
  .PWM_PUBLIC_CODE_ROM             :>.
  .PWM_PRIVATE_CODE_ROM            :>.
  .PWM_APPL_CODE_ROM               :>.
  .PORT_PUBLIC_CODE_ROM             :>.
  .PORT_PRIVATE_CODE_ROM            :>.
  .PORT_APPL_CODE_ROM               :>.
  .GPT_PUBLIC_CODE_ROM             :>.
  .GPT_PRIVATE_CODE_ROM            :>.
  .GPT_APPL_CODE_ROM               :>.
  .SPI_PUBLIC_CODE_ROM             :>.
  .SPI_PRIVATE_CODE_ROM            :>.
  .SPI_APPL_CODE_ROM               :>.
  .ADC_PUBLIC_CODE_ROM             :>.
  .ADC_PRIVATE_CODE_ROM            :>.
  .ADC_APPL_CODE_ROM               :>.
  .WDG23_A_PUBLIC_CODE_ROM         :>.
  .MCU_PUBLIC_CODE_ROM             :>.
  .MCU_PRIVATE_CODE_ROM		   :>.
  .DIO_PUBLIC_CODE_ROM 		   :>.
  .ICU_PUBLIC_CODE_ROM 		   :>.
  .ICU_PRIVATE_CODE_ROM 		   :>.


 
  
  .rozdata                         :>.      /* constant datas in ZDA area */
  .robase   align(4)               :>.      /* initialize textpointer TP for SDA addressing */



  .fixaddr  align(4)               :>.      /* ghs internal (compiler) */
  .fixtype  align(4)               :>.      /* ghs internal (compiler) */
  .secinfo  align(4)               :>.      /* ghs internal (runtime library) */
  .syscall  align(4)               :>.      /* ghs internal (linker) */

  .romdata  ROM(.data)             :>.      /* constant data to initialize variables (copied to RAM at startup)*/
  .romzdata ROM(.zdata)            :>.      /* constant data to initialize variables in ZDA area (copied to RAM at startup)*/
  .romsdata ROM(.sdata)            :>.      /* constant data to initialize variables in SDA area (copied to RAM at startup)*/
  .romtdata ROM(.tdata)            :>.      /* constant data to initialize variables in TDA area (copied to RAM at startup)*/

/* EEL & FDL Program code */
  .FAL_TextRam align(4)             :>.      /* FDL code in RAM (FCL), otherwise in ROM (FDL) */
  .FAL_Text    align(4)             :>.      /* FDL code in ROM */
  .EEL_Text    align(4)             :>.      /* EEL code in ROM */
  .FAL_Const			    :>.
  .EEL_Const			    :>.
  .FEE_PUBLIC_CODE_ROM             :>.
  .FEE_PRIVATE_CODE_ROM            :>.
  .FEE_APPL_CODE_ROM               :>.

  
  .endofrom       align(128)       :>.  
/* Start of internal RAM area (iRAM) */

  .data                                 :>iRAM   /* initialized data */
  .osstackbss align(4) NOCLEAR		:>.  
  .osstacksbss align(4) NOCLEAR		:>.                  
  .bss      align(4)            :>.      /* zero initialized data*/
  .osbss      align(4)               :>.      /* zero initialized data*/

  .sdabase  align(4)                    :>.      /* initialize globalpointer GP for SDA addressing */
  .sdata    align(4)                    :>.      /* initialized data in SDA area*/
  .RAM_1BIT CLEAR                  :>.
  .RAM_8BIT CLEAR                  :>.
  .RAM_16BIT CLEAR                 :>.
  .RAM_32BIT CLEAR                 :>.
  
  .sbss     align(4)    NOCLEAR         :>.      /* zero initialized data in SDA area*/
  .RAM_UNSPECIFIED CLEAR           :>.
  .NOINIT_RAM_1BIT NOCLEAR         :>.
  .NOINIT_RAM_8BIT NOCLEAR         :>.
  .NOINIT_RAM_16BIT NOCLEAR        :>.
  .NOINIT_RAM_32BIT NOCLEAR        :>.
  .NOINIT_RAM_UNSPECIFIED NOCLEAR  :>.
  /*  Data Section for EEL */
  .EEL_Data                        :>.      /* EEL data */
  .FAL_Data                        :>.      /* FAL data */
  
  .FAST_RAM_1BIT                   :>.
  .FAST_RAM_8BIT                   :>.
  .FAST_RAM_16BIT                  :>.
  .FAST_RAM_32BIT                  :>.
  .FAST_RAM_UNSPECIFIED            :>.
  .ADC_CFG_RAM_UNSPECIFIED         :>.
  .PWM_CFG_RAM_UNSPECIFIED         :>.
  .GPT_CFG_RAM_UNSPECIFIED         :>.
  .SPI_CFG_RAM_UNSPECIFIED	   :>.
  .ICU_CFG_RAM_UNSPECIFIED         :>.
  .FEE_CFG_RAM_UNSPECIFIED         :>.	/////////////////
  .LIN_CFG_RAM_UNSPECIFIED         :>.

  
  
  .zdata    align(4)                    :>.      /* initialized data in ZDA area*/
  .zbss     align(4)                    :>.      /* zero initialized data in ZDA area*/

  
  .ramtext  align(128) MAX_SIZE(0x2000) :>.      /* initialized and zero-initialized data in TDA area */
  .tdata    align(4)   MAX_SIZE(0x0100) :>.      /* initialized and zero-initialized data in TDA area */
  .exec     align(128)                  :>.  
  .stack    align(4) pad(0x0800)        :>.      /* definition of stack size */

  .heapbase align(4)                  :>.
  .heap     align(4)
  	        pad(addr(iRsvd0)-addr(.heapbase))
  	        NOCLEAR	                    :>.      /* definition of heap size */ 

  .top_of_RAM align(4)                  :>iRsvd0
 }

/*===========================================================================*/
/*      End of File                                                          */
/*===========================================================================*/
