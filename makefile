CC = g++
TARGET = Terminal
PREF_SRC = ./src/
PREF_OBJ = ./obj/
DEL_PREF_OBJ = .\obj\\
SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
	$(CC) -c $< -o $@

clean :
	del $(DEL_PREF_OBJ)*.o

