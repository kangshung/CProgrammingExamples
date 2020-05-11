run: 2_1.exe
	./$< 16.5 88.01

2_1.exe: func.o 2_1.c
	gcc -o $@ $^

func.o: func.c func.h
	gcc -c $<

clean:
	rm 2_1.exe func.o