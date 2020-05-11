run: logical.exe
	./$<

logical.exe: logical_use.c logical.o
	gcc -o $@ $^

logical.o: logical.c logical.h
	gcc -c $<

clean:
	rm logical.o logical.exe