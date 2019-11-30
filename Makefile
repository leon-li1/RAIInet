CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = raiinet
OBJECTS = main.o player.o data.o virus.o point.o edge.o serverport.o direction.o graphics.o textDisplay.o observer.o subject.o piece.o invalidMove.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.phony: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
