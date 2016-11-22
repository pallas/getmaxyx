default: all

PROJECT := getmaxyx
PREFIX ?= /usr/local

PROGRAMS:= getmaxy getmaxx

.PHONY: all
all: $(PROGRAMS)

$(PROGRAMS) : LDFLAGS+= -g -lcurses
$(PROGRAMS) : CXXFLAGS+=

getmaxy: CXXFLAGS+= -DMAX_Y
getmaxx: CXXFLAGS+= -DMAX_X

$(PROGRAMS) : getmaxyx.cc
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf $(PROGRAMS)

.PHONY: install
install: all
	install -D -m 0755 -t $(PREFIX)/bin $(PROGRAMS)

#