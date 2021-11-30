myapp: main.o 
	gcc -o myapp main.o -lm

main.o: main.c generate_nw.h network.h suffix.h
	gcc -c main.c generate_nw.h network.h suffix.h

generate_nw.h: string_util.h suffix.h
	gcc -c string_util.h suffix.h

network.h: string_util.h ip_util.h
	gcc -c string_util.h ip_util.h

suffix.h: string_util.h ip_util.h
	gcc -c string_util.h ip_util.h

ip_util.h: string_util.h
	gcc -c string_util.h

