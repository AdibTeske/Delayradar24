all:
	g++ src/*.cpp -I include -o delayradar.exe

clean:
	del delayradar.exe