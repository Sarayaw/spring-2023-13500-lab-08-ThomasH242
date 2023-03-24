main: main.o imageio.o funcs.o
	g++ -o main main.o imageio.o funcs.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

main.o: main.cpp imageio.h funcs.h

funcs.o: funcs.cpp funcs.h imageio.h

clean:
	rm -f sample.o imageio.o main.o funcs.o main sample taskA.pgm taskB.pgm taskC.pgm taskD.pgm taskE.pgm taskF.pgm