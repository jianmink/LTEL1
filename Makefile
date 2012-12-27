
#Set this to @ to keep the makefile quiet
ifndef SILENCE
	SILENCE = @
endif

COMPONENT_NAME = CRC
CPPUTEST_HOME = ../3PP/CppUTest-v3.1

CPPUTEST_USE_EXTENSIONS = Y
CPP_PLATFORM = Gcc


# This line is overriCPPUTEST_HOMEding the default new macros.  This is helpful
# when using std library includes like <list> and other containers
# so that memory leak detection does not conflict with stl.
CPPUTEST_MEMLEAK_DETECTOR_NEW_MACRO_FILE = -include src/ExamplesNewOverrides.h
SRC_DIRS = \
	src

TEST_SRC_DIRS = \
	test

INCLUDE_DIRS =\
  .\
  src\
  $(CPPUTEST_HOME)/include\


include $(CPPUTEST_HOME)/build/MakefileWorker.mk


TestLib:
	cd $(CPPUTEST_HOME) && make cleanEverythingInstall everythingInstall

.PHONY: TestLib
