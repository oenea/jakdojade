ccflags = -Wall -Werror -Wextra -Wpedantic -Wconversion \
					-OFast 
name = jakdojade
objects = main.o city.o dijkstra.o input.o myString.o priorityQueue.o

$(name) : $(objects)
	g++ $(ccflags) -o $(name) $(objects)

.PHONY : clean
clean :
	rm $(name) $(objects)
