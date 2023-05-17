TARGET = main.exe
SRC_FILES = main.cpp Portfolio.cpp User.cpp Stock.cpp

# DO NOT EDIT BELOW HERE
CXX = g++
CFLAGS = -Wall -g -std=c++11
OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
main.o: main.cpp Portfolio.cpp User.cpp Stock.cpp Database.cpp
Player.o: Player.cpp 
User.o: User.cpp
Stock.o: Stock.cpp
Database.o: Database.cpp
Portfolio.o: Portfolio.cpp

