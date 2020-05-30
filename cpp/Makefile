# compiler setting
CC=g++
CFLAGS = ${IALGLIB} -I./
CFLAGS += -O2 -DNDEBUG
CFLAGS += -Wall
LFLAGS= 
OBJ = coordinate_transforms.o main.o

PROGS=demo 

all:		${PROGS}

demo:		$(OBJ)
		${CC} $^ -o $@
%.o: 		%.cpp
		${CC} ${CFLAGS} -c $< -o $@

clean:
		rm -f *.o ${PROGS} *.csv
