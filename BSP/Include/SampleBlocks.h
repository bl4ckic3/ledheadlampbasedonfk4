/* You also may define separate sections for arbitrary blocks

   You should replace the uint8 type by an appropriate type,
   and remove the brackets

   Different RAM/ROM blocks and/or callback declarations
   may also be split across several header files, according to your project.
   Then you either include these files here, or you configure the
   includes via the EAD
*/
#ifndef _SAMPLE_BLOCKS_NVM_
#define _SAMPLE_BLOCKS_NVM_


    VAR(uint8, NVM_APPL_DATA) SampleRamBlock_1[1];
    CONST(uint8, NVM_APPL_CONST) SampleDefaultBlock_1[1];

#endif

/************   Organi, Version 3.9.1 Vector-Informatik GmbH  ************/
