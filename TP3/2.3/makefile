compress: 2_3.exe
	./$< -c binary t.a t.b
	# now, you can use "make decompress"

2_3.exe: 2_3.c func.o
	gcc -o $@ $^

func.o: func.c func.h
	gcc -c $<

clean:
	rm -rf func.o 2_3.exe binary decompressed

decompress:
	./2_3.exe -d binary
	ls decompressed