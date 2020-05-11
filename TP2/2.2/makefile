run: 2_2.exe
	./$<

2_2.exe: func.o 2_2.c
	gcc -o $@ $^

func.o: func.c func.h
	gcc -c $<

clean:
	rm 2_2.exe func.o