# -----------------------------------------------------------------
# https://spin.atomicobject.com/2016/08/26/makefile-c-projects/
# -----------------------------------------------------------------

TARGET ?= a.out
SRC_DIRS ?= ./

SRCS := $(shell find $(SRC_DIRS) -name "*.cpp" -or -name "*.cc")
OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d -not -path '*/\.*')
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -g
LOADLIBES ?= -lpthread

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBES) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)
