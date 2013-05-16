default: all

PROGS:= getmaxy getmaxx

.PHONY: all
all: $(PROGS)

$(PROGS) : LDFLAGS+= -g -lcurses
$(PROGS) : CXXFLAGS+=

getmaxy: CXXFLAGS+= -DMAX_Y
getmaxx: CXXFLAGS+= -DMAX_X

$(PROGS) : getmaxyx.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf $(PROGS)

#