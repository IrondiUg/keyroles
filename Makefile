# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wno-deprecated-declarations
LDFLAGS = -lssl -lcrypto

# Output executable name
TARGET = project

# Source and object files
SRCS = main.cpp database.cpp dashboards.cpp sha256.cpp
OBJS = $(SRCS:.cpp=.o)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) -lssl -lcrypto

# Compile rule for .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
.PHONY: clean