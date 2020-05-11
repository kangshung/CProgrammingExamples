save: run
	@printf "\n\nCheck inputfile.txt and output.txt\n"
	./2_3.exe < inputfile.txt > output.txt

run: 2_3.exe
	./$<

2_3.exe: func.o 2_3.c
	gcc -o $@ $^

func.o: func.c func.h
	gcc -c $<

clean:
	rm 2_3.exe func.o output.txt