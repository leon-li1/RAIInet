CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g 
EXEC = raiinet
OBJECTS = main.o player.o data.o virus.o point.o edge.o serverport.o direction.o graphics.o textDisplay.o graphicsDisplay.o observer.o subject.o piece.o invalidMove.o ability.o linkboost.o download.o firewallAbility.o scan.o polarize.o teleport.o steal.o strengthen.o firewall.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -L/usr/X11R6/lib -lX11

-include ${DEPENDS}

.phony: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
