run: 2_4_2.exe
	./$<

2_4_2.exe: func.o 2_4_2.c
	gcc -o $@ $^

func.o: func.c func.h
	gcc -c $<

clean:
	rm 2_4_2.exe func.o