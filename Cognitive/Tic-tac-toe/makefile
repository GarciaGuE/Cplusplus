GNUPLOT := -std=c++11

#Si se tiene instalado las librerías boost para desarrollo (sudo apt-get install libboost-all-dev), descomentar la siguiente línea
#GNUPLOT=-D__GNUPLOT__ -std=c++17 -lutil -lboost_iostreams -lboost_system -lboost_filesystem 

three-in-a-row: three-in-a-row.cpp gnuplot-iostream.h
	g++ -o three-in-a-row three-in-a-row.cpp -O3 -Wall -fmessage-length=0 $(GNUPLOT)
