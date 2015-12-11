OBJS = dagen.o inout.o intro.o end.o

CC = gcc
CFLAGS = -Wall -c
LFLAGS = -Wall

dagen : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o dagen

dagen.o : inout.h intro.h dagen.c
	$(CC) $(CFLAGS) inout.h intro.h dagen.c

intro.o : intro.h intro.c
	$(CC) $(CFLAGS) intro.h intro.c

inout.o : inout.c inout.h
	$(CC) $(CFLAGS) inout.h inout.c

end.o : end.c end.h
	$(CC) $(CFLAGS) end.h end.c

clean :
	\rm *.o *.gch *~ dagen
