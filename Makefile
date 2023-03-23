

sample: sample.o imageio.o invert.o invert-half.o
	g++ -o sample sample.o imageio.o invert.o invert-half.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

invert.o: invert.cpp imageio.h

invert-half.o: invert-half.cpp imageio.h

clean:
	rm -f *.o sample invertpicture.png invert.pgm outImage.pgm inverthalf.pgm

invert:
	convert invert.pgm invertpicture.png

inverthalf:
	convert inverthalf.pgm inverthalfpicture.png