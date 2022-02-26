PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = calculation.o display.o input.o memory.o FieldModel.o View.o Controller.o App.o LifeCPP.o
LIBS = ncursesw

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else ifeq ($(BUILD_MODE),linuxtools)
	CFLAGS += -g -pg -fprofile-arcs -ftest-coverage
	LDFLAGS += -pg -fprofile-arcs -ftest-coverage
	EXTRA_CLEAN += LifeCPP.gcda LifeCPP.gcno $(PROJECT_ROOT)gmon.out
	EXTRA_CMDS = rm -rf LifeCPP.gcda
else
    $(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all:	LifeCPP

LifeCPP:	$(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ -l $(LIBS)
	$(EXTRA_CMDS)

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
	
%.o:	$(PROJECT_ROOT)src/%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<


clean:
	rm -fr LifeCPP $(OBJS) $(EXTRA_CLEAN)
