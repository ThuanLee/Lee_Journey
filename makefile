all: compile link clean

compile:
	g++ -Iinclude -Iheader -c src/*.cpp

	
link:
	g++ *.o -o main -Llib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-network -lsfml-system

clean:
	del *.o