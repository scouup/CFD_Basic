CXX = g++
CXXFLAGS = -O2 -std=c++17
INCLUDES = -I./src

# ---------- Source ----------
SRCS = src/Main.cpp src/Parameters.cpp src/Time_integrator.cpp
OBJS = $(SRCS:.cpp=.o)

# ---------- Target ----------
TARGET = Advective_wave

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
