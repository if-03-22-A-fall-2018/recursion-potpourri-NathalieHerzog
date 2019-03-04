CC					= g++
CCLINK			= g++
LIBS				=
CCOPTIONS		= -Wall -pedantic -g
LDOPTIONS		=
HDRS				= recfuncs.h test_recpot.h shortcut.h

TEST = test_recpot
#PROGRAM = depot_prg

TESTOBJECT = recpot_test_driver.o
#MAINOBJECT = depot_main_driver.o
OBJS = shortcut.o recfuncs.o test_recpot.o

#DOXY            = /Applications/Doxygen/Doxygen.app/Contents/Resources/doxygen
DOXY            = doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test setsample setassignment definesample defineassignment assignmentfolder

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)

cleanall:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS) index.html
	rm -R html

doxy:
	$(DOXY)
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

#sets project as sample solution
setsample:
	cp recfuncs.cpp.sample recfuncs.cpp
	cp recfuncs.h.sample recfuncs.h

#sets project as assignment
setassignment:
	cp recfuncs.cpp.assignment recfuncs.cpp
	cp recfuncs.h.assignment recfuncs.h

# defines current state of project as sample solution
definesample:
	cp recfuncs.cpp recfuncs.cpp.sample
	cp recfuncs.h recfuncs.h.sample

# defines current sate of project as assignment
defineassignment:
	cp recfuncs.cpp recfuncs.cpp.assignment
	cp recfuncs.h recfuncs.h.assignment

# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setsample
	make doxy
	make setassignment
	mkdir ../assignment
	cp -R * ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
	make cleanall

%.o: %.cpp $(HDRS)
	$(CC) $(CCOPTIONS) -c $<
