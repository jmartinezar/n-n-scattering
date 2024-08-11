report.pdf: report.tex 4-polar.pdf 4-car.pdf
	pdflatex $<

4-polar.pdf: 4-polar.py  4-1.txt 4-2.txt
	python3 $<

4-car.pdf: 4-car.py  4-1.txt 4-2.txt
	python3 $<

4-1.txt: 4-1
	./$<

4-2.txt: 4-2
	./$<

%.o: %.cpp include.hpp
	g++ -fsanitize=address,leak,undefined -O3 -Wall -g `gsl-config --cflags --libs` -c $<

4-1: 4-1.o include.o
	g++ -fsanitize=address,leak,undefined -O3 -Wall -g $^ -o $@ `gsl-config --cflags --libs`

4-2: 4-2.o include.o
	g++ -fsanitize=address,leak,undefined -O3 -Wall -g $^ -o $@ `gsl-config --cflags --libs`

clean:
	rm *.o 4-polar.pdf 4-car.pdf *~ *.txt 4-1 4-2 *.aux *.log
