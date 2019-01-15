CC=gcc
CFLAGS=-c
CMATH=-lm
PFLAG=-pthread

all: clean myOS 

myOS: myOS.o shell.o execute.o tokenize.o simulator.o simulate.o scheduler.o job.o d_linked_list.o helper.o
	$(CC) -o $@ $^ $(CMATH) $(PFLAG)

myOS.o: myOS.c myOS.h
	$(CC) $(CFLAGS) -o $@ $<

shell.o: shell.c shell.h
	$(CC) $(CFLAGS) -o $@ $<

execute.o: execute.c execute.h
	$(CC) $(CFLAGS) -o $@ $<

tokenize.o: tokenize.c tokenize.h
	$(CC) $(CFLAGS) -o $@ $<

simulator.o: simulator.c simulator.h
	$(CC) $(CFLAGS) -o $@ $<

simulate.o: simulate.c simulate.h
	$(CC) $(CFLAGS) -o $@ $<  $(PFLAG)

scheduler.o: scheduler.c scheduler.h 
	$(CC) $(CFLAGS) -o $@ $<

job.o: job.c job.h
	$(CC) $(CFLAGS) -o $@ $<

d_linked_list.o: d_linked_list.c d_linked_list.h
	$(CC) $(CFLAGS) -o $@ $<

helper.o: helper.c helper.h 
	$(CC) $(CFLAGS) -o $@ $<

test: clean myOS test1 test2

test1:
	bash ./tests/run.sh 1

test2:
	bash ./tests/run.sh 2

clean:
	rm -f *.o myOS report.txt system.out