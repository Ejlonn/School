
# cc : derleyici
CC = g++

# -I./src  src/ klasörünü include pathe ekler, -Wall tüm uyarıları gösterir, -Wextra extra uyarıları gösterir
CFLAGS = -g -Wall -Wextra -Ilib

#Kaynak dosyalarının bulunduğu klasör src/
SRC_DIR = src

#Derlenmiş dosyaların bulunduğu ve yürütülebilir programın tutulacağı klasör bin/
BIN_DIR = bin

#oluşturmak istediğimiz yürütülebilir son dosya bin/program
TARGET = program

#wildcard src/ klasöründeki tüm .c dosyalarını bulur
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)


#patsubt (pattern substition), dosya isimlerinin uzantılarını değiştirir
#$(SRC_DIR)/%.c ---> $(BIN_DIR)/%.o dönüşümü yapar
#örneğin src/main.c ---> bin/main.o
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SOURCES))


#varsayılan hedef, make komutuyla çağırılır
all: $(TARGET)

# $^ tüm bağımlılık dosyalarını temsil eder $(OBJECTS) $@ : Hedef dosyayı temsil eder $(TARGET)
$(TARGET): $(OBJECTS)
	@echo "Creating program. To launch type ./program in your terminal"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $^ -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clear:
		@echo "Removing unnecessary files"
		@rm -f $(BIN_DIR)/*.o 

debug: $(TARGET)
	gdb ./$(TARGET)

.PHONY: all clear debug
