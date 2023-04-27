OPT = -Wall

a05: Time.o Date.o Animal.o Appt.o Schedule.o Control.o main.o View.o
	g++ $(OPT) -o a05 Time.o Date.o Animal.o Appt.o Schedule.o Control.o main.o View.o

main.o:	main.cc
	g++ $(OPT) -c main.cc

View.o:	View.cc View.h
	g++ $(OPT) -c View.cc

Control.o: Control.cc Control.h List.h
	g++ $(OPT) -c Control.cc

Time.o: Time.cc Time.h
	g++ $(OPT) -c Time.cc

Date.o: Date.cc Date.h
	g++ $(OPT) -c Date.cc

Appt.o: Appt.cc Appt.h
	g++ $(OPT) -c Appt.cc

Schedule.o: Schedule.cc Schedule.h List.h
	g++ $(OPT) -c Schedule.cc

Animal.o:  Animal.cc Animal.h
	g++ $(OPT) -c Animal.cc

clean:
	rm -f *.o a05
