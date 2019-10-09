#
#
# usage: make all


myExec: main.o gradeutil.o
	g++ -std=c++11 -o myExec main.o gradeutil.o

main.o: main.cpp gradeutil.cpp gradeutil.h
	g++ -c -std=c++11 main.cpp

gradeutil.o: gradeutil.cpp gradeutil.h
	g++ -c -std=c++11 gradeutil.cpp

clean:
	rm main.o gradeutil.o myExec

