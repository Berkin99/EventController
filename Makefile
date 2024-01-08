event: main.c event.c 
	gcc -o event main.c event.c

clean:
	del event.exe