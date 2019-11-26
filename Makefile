CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = raiinet
OBJECTS = main.o player.o data.o virus.o point.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.phony: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
