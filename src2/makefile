ccflags = -Wall -Werror -Wextra -Wpedantic -Wconversion \
					-OFast 
name = jakdojade
objects = main.o path.o priority_queue.o town.o

$(name) : $(objects)
	g++ $(ccflags) -o $(name) $(objects)

.PHONY : clean
clean :
	rm $(name) $(objects)
