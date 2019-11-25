TARGET = proj9
CXX = g++
CXX_FLAGS = -Wall

all: $(TARGET)

$(TARGET): $(TARGET).o DataType.o
	$(CXX) $(CXX_FLAGS) $(TARGET).cpp DataType.o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp ArrayQueue.h NodeQueue.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

DataType.o: DataType.cpp DataType.h
	$(CXX) $(CXX_FLAGS) -c DataType.cpp

clean:
	-rm -f *.o
	-rm -f $(TARGET)
