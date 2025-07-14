#!/bin/bash
echo "Building CSP-NET Premium Platform..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

echo "Build complete! Run with: ./CSP_NET"
echo "Frontend: http://localhost:8080"
echo "Backend API: http://localhost:8081/api/health"