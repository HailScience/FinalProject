#makefile

CXX = g++


crime: main.o game.o space.o crimeScene.o questioning.o autopsy.o testing.o identify.o interrogation.o
	${CXX} -o crime main.o game.o space.o crimeScene.o questioning.o autopsy.o testing.o identify.o interrogation.o

main.o: game.cpp game.hpp main.cpp space.cpp space.hpp crimeScene.cpp crimeScene.hpp questioning.cpp questioning.hpp autopsy.cpp autopsy.hpp testing.cpp testing.hpp identify.cpp identify.hpp interrogation.cpp interrogation.hpp
	${CXX} -c main.cpp

game.o: game.hpp game.cpp
	${CXX} -c game.cpp

space.o: space.hpp space.cpp
	${CXX} -c space.cpp

crimeScene.o: crimeScene.hpp crimeScene.cpp space.hpp space.cpp
	${CXX} -c crimeScene.cpp

questioning.o: questioning.hpp questioning.cpp space.hpp space.cpp
	${CXX} -c questioning.cpp

autopsy.o: autopsy.hpp autopsy.cpp space.hpp space.cpp
	${CXX} -c autopsy.cpp

testing.o: testing.hpp testing.cpp space.hpp space.cpp
	${CXX} -c testing.cpp

identify.o: identify.hpp identify.cpp space.hpp space.cpp
	${CXX} -c identify.cpp

interrogation.o: interrogation.hpp interrogation.cpp space.hpp space.cpp
	${CXX} -c interrogation.cpp

clean:
	rm *.o crime
