# MAKEFILE for scs
include scs.mk


SCS_OBJECTS =	src/scs.o \
		src/util.o \
		src/cones.o \
		src/cs.o \
		src/linAlg.o \
		src/ctrlc.o \
		src/scs_version.o \
		src/directions.o \
		src/unit_test_util.o

TEST_RUNNER_DIR = UNIT_TEST_RUNNER_DIR
TEST_RUNNER_INDIR = UNIT_TEST_RUNNER_INDIR
TEST_SRC_PATH = tests/c
SRC_FILES = $(wildcard src/*.c)
INC_FILES = $(wildcard include/*.h)

CFLAGS += $(OPT_FLAGS)
CUDAFLAGS += $(OPT_FLAGS)

AMD_SOURCE = $(wildcard $(DIRSRCEXT)/amd_*.c)
DIRECT_SCS_OBJECTS = $(DIRSRCEXT)/ldl.o $(AMD_SOURCE:.c=.o)
TARGETS = $(OUT)/demo_direct $(OUT)/demo_indirect $(OUT)/demo_SOCP_indirect $(OUT)/demo_SOCP_direct

.PHONY: default 

default: $(TARGETS) $(OUT)/libscsdir.a $(OUT)/libscsindir.a $(OUT)/libscsdir.$(SHARED) $(OUT)/libscsindir.$(SHARED)
	@echo "\n*************************************************************"
	@echo "Successfully compiled SuperSCS (based on SCS)                "
	@echo "Find more at: https://github.com/kul-forbes/scs              "
	@echo "To test, type '$(OUT)/demo_direct' or '$(OUT)/demo_indirect',"
	@echo "or '$(OUT)/demo_SOCP_indirect' to solve a random SOCP.       "
	@echo "To run the unit tests, type 'make run-test'.                 "
	@echo "*************************************************************"
ifneq ($(USE_LAPACK), 0)
	@echo "Compiled with blas and lapack, can solve LPs, SOCPs, SDPs,   "
	@echo "ECPs, PCPs and use Anderson's acceleration.                  "
else
	@echo "NOT compiled with blas/lapack, cannot solve SDPs (can solve  "
	@echo "LPs, SOCPs, ECPs, and PCPs); cannot use Anderson's acceler.  "
	@echo "To solve SDPs, install blas and lapack, then edit scs.mk to  "
	@echo "set USE_LAPACK=1 and point to the library install locations, "
	@echo "and recompile with 'make purge', 'make'.                     "
endif
	@echo "*************************************************************\n"

%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

src/scs.o	: $(SRC_FILES) $(INC_FILES)
src/util.o	: src/util.c include/util.h include/constants.h
src/cones.o	: src/cones.c include/cones.h include/scs_blas.h
src/cs.o	: src/cs.c include/cs.h
src/linAlg.o: src/linAlg.c include/linAlg.h
src/ctrl.o  : src/ctrl.c include/ctrl.h
src/scs_version.o: src/scs_version.c include/constants.h
src/directions.o: src/directions.c include/directions.h


$(DIRSRC)/private.o: $(DIRSRC)/private.c  $(DIRSRC)/private.h
$(INDIRSRC)/indirect/private.o: $(INDIRSRC)/private.c $(INDIRSRC)/private.h
$(LINSYS)/common.o: $(LINSYS)/common.c $(LINSYS)/common.h

$(OUT)/libscsdir.a: $(SCS_OBJECTS) $(DIRSRC)/private.o $(DIRECT_SCS_OBJECTS) $(LINSYS)/common.o
	mkdir -p $(OUT)
	$(ARCHIVE) $@ $^
	- $(RANLIB) $@

$(OUT)/libscsindir.a: $(SCS_OBJECTS) $(INDIRSRC)/private.o $(LINSYS)/common.o
	mkdir -p $(OUT)
	$(ARCHIVE) $@ $^
	- $(RANLIB) $@

$(OUT)/libscsdir.$(SHARED): $(SCS_OBJECTS) $(DIRSRC)/private.o $(DIRECT_SCS_OBJECTS) $(LINSYS)/common.o
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) -shared -Wl,$(SONAME),$(@:$(OUT)/%=%) -o $@ $^ $(LDFLAGS)

$(OUT)/libscsindir.$(SHARED): $(SCS_OBJECTS) $(INDIRSRC)/private.o $(LINSYS)/common.o
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) -shared -Wl,$(SONAME),$(@:$(OUT)/%=%) -o $@ $^ $(LDFLAGS)

$(OUT)/demo_direct: examples/c/demo.c $(OUT)/libscsdir.a
	$(CC) $(CFLAGS) -DDEMO_PATH="\"$(CURDIR)/examples/raw/demo_data\"" $^ -o $@ $(LDFLAGS)

$(OUT)/demo_indirect: examples/c/demo.c $(OUT)/libscsindir.a
	$(CC) $(CFLAGS) -DDEMO_PATH="\"$(CURDIR)/examples/raw/demo_data\"" $^  -o $@ $(LDFLAGS)

$(OUT)/demo_SOCP_direct: examples/c/randomSOCPProb.c $(OUT)/libscsdir.a
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OUT)/demo_SOCP_indirect: examples/c/randomSOCPProb.c $(OUT)/libscsindir.a
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# REQUIRES GPU AND CUDA INSTALLED
gpu: $(OUT)/demo_gpu $(OUT)/demo_SOCP_gpu $(OUT)/libscsgpu.$(SHARED) $(OUT)/libscsgpu.a

$(GPU)/private.o: $(GPU)/private.c
	$(CUCC) -c -o $(GPU)/private.o $^ $(CUDAFLAGS)

$(OUT)/libscsgpu.$(SHARED): $(SCS_OBJECTS) $(GPU)/private.o $(LINSYS)/common.o
	mkdir -p $(OUT)
	$(CC) $(CFLAGS) -shared -Wl,$(SONAME),$(@:$(OUT)/%=%) -o $@ $^ $(LDFLAGS) $(CULDFLAGS)

$(OUT)/libscsgpu.a: $(SCS_OBJECTS) $(GPU)/private.o $(LINSYS)/common.o
	mkdir -p $(OUT)
	$(ARCHIVE) $@ $^
	- $(RANLIB) $@

$(OUT)/demo_SOCP_gpu: examples/c/randomSOCPProb.c $(OUT)/libscsgpu.a
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(CULDFLAGS)

$(OUT)/demo_gpu: examples/c/demo.c $(OUT)/libscsgpu.$(SHARED)
	$(CC) $(CFLAGS) -DDEMO_PATH="\"$(CURDIR)/examples/raw/demo_data\"" $^  -o $@ $(LDFLAGS) $(CULDFLAGS)

.PHONY: clean clean-cov purge test docs
	
profile-build: default
	$(CC) $(CFLAGS) tests/c/profiling/profile_superscs_1.c -o $(OUT)/profile_superscs -L./out -l:libscsindir.a $(LDFLAGS)

profile: profile-build
	$(OUT)/profile_superscs
	gprof $(OUT)/profile_superscs gmon.out > analysis_$(PN).txt
	gprof2dot analysis_$(PN).txt | dot -Tpng -o graph_$(PN).png
		
clean-cov:
	@rm -rf *.gcno 
	@rm -rf *.gcda
	@rm -rf *.info
	@rm -rf */*.gcno 
	@rm -rf */*.gcda
	@rm -rf */*/*.gcno 
	@rm -rf */*/*.gcda
	@rm -rf */*/*/*.gcno 
	@rm -rf */*/*/*.gcda	
	
clean: clean-cov
	@rm -rf $(TARGETS) $(SCS_OBJECTS) $(DIRECT_SCS_OBJECTS) $(LINSYS)/*.o $(DIRSRC)/*.o $(INDIRSRC)/*.o $(GPU)/*.o
	@rm -rf $(OUT)/*.dSYM
	@rm -rf matlab/*.mex*
	@rm -rf .idea
	@rm -rf python/*.pyc
	@rm -rf python/build
	@rm -rf */*.o
	@rm -rf */*/*.o
	@rm -rf */*/*/*.o

purge: clean 
	@rm -rf $(OUT)
	@rm -rf docs
	@rm -rf *.info
	
test:	default 
	@echo "Compiling individual tests..."
	$(CC) -c $(CFLAGS) $(TEST_SRC_PATH)/test_dummy.c -o $(TEST_SRC_PATH)/test_dummy.o
	$(CC) -c $(CFLAGS) $(TEST_SRC_PATH)/test_utilities.c -o $(TEST_SRC_PATH)/test_utilities.o
	$(CC) -c $(CFLAGS) $(TEST_SRC_PATH)/test_broyden.c -o $(TEST_SRC_PATH)/test_broyden.o
	$(CC) -c $(CFLAGS) $(TEST_SRC_PATH)/test_superscs.c -o $(TEST_SRC_PATH)/test_superscs.o
	@echo "Building test runner..."
	$(CC) $(CFLAGS) $(TEST_SRC_PATH)/test_runner_dir.c \
	    -o out/$(TEST_RUNNER_DIR) $(TEST_SRC_PATH)/test_dummy.o \
	    $(TEST_SRC_PATH)/test_broyden.o \
	    $(TEST_SRC_PATH)/test_superscs.o \
	    $(TEST_SRC_PATH)/test_utilities.o \
	    $(OUT)/libscsdir.a $(LDFLAGS) 

run-test: test
	out/UNIT_TEST_RUNNER_DIR 2> test_stderr_output.log
	
run-test-mem: test
	valgrind --track-origins=yes --leak-check=full out/UNIT_TEST_RUNNER_DIR
	
cov: run-test	
	lcov --directory ./src --capture --output-file scs-coverage.info
	lcov --remove scs-coverage.info  '/usr/*' 'include/*' --output-file scs-coverage.info
	lcov --list scs-coverage.info
	mkdir -p coverage
	genhtml -s --legend --title 'SuperSCS Unit Tests' scs-coverage.info --output-directory coverage

help:
	@echo "\nMakefile targets...\n"
	@echo "make help ....................... this help message"
	@echo "make ............................ builds the project (creates library files)"
	@echo "make clear ...................... clears build"
	@echo "make clear-cov .................. clears coverage files (gcno, gcda)"
	@echo "make purge ...................... spring-clean of build files/folders"
	@echo "make default .................... builds everything"
	@echo "make test ....................... builds tests"
	@echo "make run-test ................... runs all unit tests"
	@echo "make run-test-mem ............... memchecks unit tests"
	@echo "make cov COV=1 .................. runs lcov"
	@echo "make PF=1 PN={name} SCS_MEM={mem} \ "
	@echo "   SCS_DIR={direction} profile .. performs profiling"
	@echo "make docs ....................... runs doxygen and creates documentation"
	@echo "make show-docs .................. makes documentation and shows the result\n"
	@echo " "
	@echo "Make options:"
	@echo "PF .............................. whether profiling is activated (0/1)"
	@echo "PN .............................. profiler name (string)"
	@echo "SCS_MEM ......................... memory to be used in profiler (int, >2)"
	@echo "SCS_DIR ......................... direction type (ScsDirectionType)"
	@echo "COV ............................. whether coverage is activated (0/1)"
	@echo "OPT ............................. set optimization level (0/1/2/3/s/fast)"
	@echo " "
	
docs:
	doxygen Doxyfile

show-docs: docs
	xdg-open docs/index.html
