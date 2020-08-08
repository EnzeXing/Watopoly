CXX=g++
CXXFLAGS=-std=c++14 -MMD
OBJECTS=Board.o Building.o Dice.o Game.o NonProperty.o Player.o Property.o test.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=watopoly

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
