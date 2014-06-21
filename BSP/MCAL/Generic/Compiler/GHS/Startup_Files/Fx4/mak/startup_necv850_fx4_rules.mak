#######################################################################
# REGISTRY
#

LIBRARIES_TO_BUILD +=

CC_FILES_TO_BUILD +=

CPP_FILES_TO_BUILD  +=
ASM_FILES_TO_BUILD  += \
                 $(STARTUP_FX4_CORE_PATH)\src\df4010_startup.$(ASM_FILE_SUFFIX)

LIBRARIES_LINK_ONLY +=
OBJECTS_LINK_ONLY +=
GENERATED_SOURCE_FILES +=
MAKE_CLEAN_RULES +=
MAKE_GENERATE_RULES +=
MAKE_DEBUG_RULES += debug_startup_necv850_fx4_makefile
MAKE_CONFIG_RULES +=

#######################################################################
# Command to print debug information                                  #
#######################################################################
debug_startup_necv850_fx4_makefile:
	@echo STARTUP_FX4_CORE_PATH = $(STARTUP_FX4_CORE_PATH)
	@echo OBJ_FILE_SUFFIX = $(OBJ_FILE_SUFFIX)

#######################################################################
