# Makefile for Conway's Game of Life

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = conway

SOURCES = main.cpp patterns.cpp restart.cpp interactive.cpp

HEADERS = patterns.h restart.h interactive.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)

.PHONY: clean install uninstall
