run: 2_1.exe
	./$< 2
	# run with ./2_1.exe [123] with optional > file

2_1.exe: func.o 2_1.c
	gcc -o $@ $^

func.o: func.c func.h
	gcc -c $<

clean:
	rm 2_1.exe func.o