CXX = g++
CXXFLAGS = -O2 -std=c++17
INCLUDES = -I./src

# ---------- Source ----------
SRCS = src/Main.cpp src/Parameters.cpp src/Space_Scheme.cpp src/Time_integrator.cpp
OBJS = $(SRCS:.cpp=.o)

# ---------- Target ----------
TARGET = cfd_sim

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
