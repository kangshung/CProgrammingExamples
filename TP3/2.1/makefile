run: 2_1.exe
	./$< 3 0.6 20

2_1.exe: 2_1.o
	gcc -o $@ $<

2_1.o: 2_1.c
	gcc -c $<

clean:
	rm 2_1.o 2_1.exe