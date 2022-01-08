PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
CC = gcc
CXX = $(CC)
	
OBJS = calculation.o display.o input.o memory.o lifeV1.o
LIBS = ncursesw

#CFLAGS += -l $(LIBS)

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else ifeq ($(BUILD_MODE),linuxtools)
	CFLAGS += -g -pg -fprofile-arcs -ftest-coverage
	LDFLAGS += -pg -fprofile-arcs -ftest-coverage
	EXTRA_CLEAN += life.gcda life.gcno $(PROJECT_ROOT)gmon.out
	EXTRA_CMDS = rm -rf life.gcda
else
    $(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all:	lifeV1

lifeV1:	$(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ -l $(LIBS)
	$(EXTRA_CMDS)

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
#	rm -fr life $(OBJS) $(EXTRA_CLEAN)
	del  life.exe $(OBJS) $(EXTRA_CLEAN)
	