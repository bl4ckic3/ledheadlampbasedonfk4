################################################################################
# INTERNAL REQUIRED CONFIGURATION
#
# COMPILER_INSTALL_DIR
#
COMPILER_INSTALL_DIR=C:\GHS\multi516C

################################################################################
# REQUIRED (in base_make)
#
# CC
# LINKER
# DBLINKER
# CONVERTER
# GHS Compiler Driver for compiling source files
CC="$(COMPILER_INSTALL_DIR)\ccv850e.exe"

# GHS Compiler Driver for assembling the startup files
ASM="$(COMPILER_INSTALL_DIR)\ccv850e.exe"

# GHS Compiler Driver for linking the object files and startup code
LINKER="$(COMPILER_INSTALL_DIR)\ccv850e.exe"

# GHS Linker for linking the object files without startup code
DBLINKER="$(COMPILER_INSTALL_DIR)\elxr.exe"

# GHS Code converter to generate motorola S-Record file
CONVERTER="$(COMPILER_INSTALL_DIR)\gsrec.exe"
################################################################################

ASM_FILE_SUFFIX = 850
OBJ_FILE_SUFFIX = o
ASM_OBJ_FILE_SUFFIX = ao
LST_FILE_SUFFIX = lst
PRE_FILE_SUFFIX = pre
MAP_FILE_SUFFIX = map
S_RECORD_SUFFIX = s37
EXE_FILE_SUFFIX = out
C_FILE_SUFFIX = c

################################################################################
# REGISTRY
#
CC_INCLUDE_PATH += $(GHS_CORE_PATH)\Compiler_Config\inc
CPP_INCLUDE_PATH +=
ASM_INCLUDE_PATH +=
PREPROCESSOR_DEFINES +=

################################################################################
# Directory to store the Assembly List file and the Preprocessor file          #
################################################################################
export TEXTPATH=$(OBJECT_OUTPUT_PATH)
export OBJPATH=$(OBJECT_OUTPUT_PATH)

################################################################################
