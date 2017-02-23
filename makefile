CPP = g++

Register: main.o main.o fileGen.o reportGen.o registerSystem.o Course.o Student.o registrationTable.o courseSelection.o indexOfCourse.o indexOfStudent.o hashTable.h Deque.h
	$(CPP) -std=c++11 -o Register main.o fileGen.o reportGen.o registerSystem.o Course.o Student.o registrationTable.o courseSelection.o indexOfCourse.o indexOfStudent.o
main.o: main.cpp registerSystem.h
	$(CPP) -std=c++11 -c main.cpp
fileGen.o: fileGen.cpp registerSystem.h
	$(CPP) -std=c++11 -c fileGen.cpp
reportGen.o: reportGen.cpp registerSystem.h
	$(CPP) -std=c++11 -c reportGen.cpp
registerSystem.o: registerSystem.cpp registerSystem.h
	$(CPP) -std=c++11 -c registerSystem.cpp
Course.o: Course.cpp Course.h
	$(CPP) -std=c++11 -c Course.cpp
Student.o: Student.cpp Student.h
	$(CPP) -std=c++11 -c Student.cpp
registrationTable.o: registrationTable.cpp registrationTable.h Deque.h courseSelection.h indexOfCourse.h indexOfStudent.h hashTable.h
	$(CPP) -std=c++11 -c registrationTable.cpp
courseSelection.o: courseSelection.cpp courseSelection.h
	$(CPP) -std=c++11 -c courseSelection.cpp
indexOfStudent.o: indexOfStudent.cpp indexOfStudent.h
	$(CPP) -std=c++11 -c indexOfStudent.cpp
indexOfCourse.o: indexOfCourse.cpp indexOfCourse.h
	$(CPP) -std=c++11 -c indexOfCourse.cpp
clean: 
	rm -f *.o Register 
version:
	$(CPP) -v