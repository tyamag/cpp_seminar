# -Dxxx(マクロ定義)
INCLUDE = -I./include
CFLAGS = -Wall -std=c++11 $(INCLUDE)
LDLIBS =
TARGET = neuralnet_test
SRC_DIR = ./src
OBJ_DIR = ./obj

# SRCS = ./src/hoge1.cpp ./src/hoge2.cpp ...
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# $(subst from,to,text) ... text中のfromをtoに置換する
# ./src/main.cpp -> ./obj/main.o ...
OBJS = $(subst $(SRC_DIR),$(OBJ_DIR)/,$(SRCS:.cpp=.o))

.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	#objディレクトリがなかったら生成
	@if [ ! -d $(OBJ_DIR) ]; \
	    then echo "mkdir -p $(OBJ_DIR)"; mkdir -p $(OBJ_DIR); \
	fi
	$(CXX) -c $(CFLAGS) $< -o $@

clean:
	$(RM) -r $(TARGET) $(OBJ_DIR)

