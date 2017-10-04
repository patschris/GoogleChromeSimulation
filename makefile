CC		= gcc
CFLAGS	= -g3 -Wall
EXEC 	= GoogleChomeSimulation
OBJS 	= main.o session.o siteList.o tabList.o options.o
SRCS 	= main.c session.c siteList.c tabList.c options.c


.PHONY : all
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

session.o: session.c
	$(CC) $(CFLAGS) -c session.c

siteList.o: siteList.c
	$(CC) $(CFLAGS) -c siteList.c

tabList.o: tabList.c
	$(CC) $(CFLAGS) -c tabList.c

options.o: options.c
	$(CC) $(CFLAGS) -c options.c



.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC)



.PHONY: run
run:
	./$(EXEC)



.PHONY: check
check:
	valgrind --leak-check=full ./$(EXEC)
