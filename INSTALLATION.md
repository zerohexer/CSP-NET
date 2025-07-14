# CSP-NET Installation Guide
**Complete installation instructions for all supported platforms**

## Overview

CSP-NET requires two main frameworks:
- **Wt Framework** - For web UI components
- **Drogon Framework** - For high-performance backend

## Platform-Specific Instructions

### openSUSE (Tested and Recommended)

**System Requirements:**
- openSUSE Leap 15.6 or Tumbleweed
- GCC 7+ or Clang 5+
- CMake 3.16+

#### Step 1: Install System Dependencies
```bash
# Install build tools and Wt framework
sudo zypper install gcc-c++ cmake wt-devel

# Install additional development packages
sudo zypper install git pkgconfig boost-devel openssl-devel
```

#### Step 2: Install Drogon Framework (Manual Compilation)
```bash
# Clone Drogon repository
git clone https://github.com/drogonframework/drogon.git
cd drogon

# Install Drogon dependencies
sudo zypper install jsoncpp-devel libuuid-devel zlib-devel \
                    postgresql-devel sqlite3-devel libmysqlclient-devel

# Build and install Drogon
git submodule update --init
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install

# Update library cache
sudo ldconfig
```

#### Step 3: Verify Installation
```bash
# Check Wt installation
pkg-config --modversion wt

# Check Drogon installation
drogon_ctl version

# Test compilation
echo '#include <Wt/WApplication.h>
#include <drogon/drogon.h>
int main() { return 0; }' > test.cpp
g++ -std=c++17 test.cpp $(pkg-config --libs --cflags wt) -ldrogon
rm test.cpp a.out
```

---

### Ubuntu/Debian (Untested)

**Note: These instructions are provided for reference but have not been tested.**

#### Step 1: Install System Dependencies
```bash
# Update package list
sudo apt-get update

# Install build tools
sudo apt-get install build-essential cmake git pkg-config

# Install Wt framework
sudo apt-get install libwt-dev libwthttp-dev
```

#### Step 2: Install Drogon Dependencies
```bash
# Install Drogon build dependencies
sudo apt-get install libjsoncpp-dev uuid-dev zlib1g-dev \
                     libssl-dev libpq-dev libsqlite3-dev \
                     libmysqlclient-dev libboost-all-dev
```

#### Step 3: Install Drogon Framework
```bash
# Clone and build Drogon
git clone https://github.com/drogonframework/drogon.git
cd drogon
git submodule update --init
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
sudo ldconfig
```

---

### macOS (Untested)

**Note: These instructions are provided for reference but have not been tested.**

#### Step 1: Install Prerequisites
```bash
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install Xcode command line tools
xcode-select --install
```

#### Step 2: Install Dependencies
```bash
# Install build tools and dependencies
brew install cmake pkg-config boost openssl jsoncpp ossp-uuid

# Install database libraries
brew install postgresql mysql sqlite
```

#### Step 3: Install Wt Framework
```bash
# Install Wt via Homebrew
brew install wt
```

#### Step 4: Install Drogon Framework
```bash
# Clone and build Drogon
git clone https://github.com/drogonframework/drogon.git
cd drogon
git submodule update --init
mkdir build && cd build

# Configure with Homebrew paths
cmake -DCMAKE_PREFIX_PATH=/opt/homebrew ..
make -j$(sysctl -n hw.ncpu)
sudo make install
```

---

### Arch Linux (Untested)

**Note: These instructions are provided for reference but have not been tested.**

#### Step 1: Install Dependencies
```bash
# Install from official repositories
sudo pacman -S base-devel cmake git boost jsoncpp postgresql-libs \
               sqlite mysql++ openssl

# Install Wt framework
sudo pacman -S wt
```

#### Step 2: Install Drogon Framework
```bash
# Clone and build Drogon
git clone https://github.com/drogonframework/drogon.git
cd drogon
git submodule update --init
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
sudo ldconfig
```

---

### Fedora/RHEL/CentOS (Untested)

**Note: These instructions are provided for reference but have not been tested.**

#### Step 1: Install Dependencies
```bash
# For Fedora
sudo dnf install gcc-c++ cmake git pkgconfig boost-devel \
                 jsoncpp-devel libuuid-devel openssl-devel \
                 postgresql-devel sqlite-devel mysql-devel

# Install Wt framework
sudo dnf install wt-devel
```

#### Step 2: Install Drogon Framework
```bash
# Clone and build Drogon
git clone https://github.com/drogonframework/drogon.git
cd drogon
git submodule update --init
mkdir build && cd build
cmake ..
make -j$(nproc)
sudo make install
sudo ldconfig
```

---

## Building CSP-NET

After installing the dependencies on your platform:

### Step 1: Clone CSP-NET
```bash
git clone https://github.com/zerohexer/CSP-NET.git
cd CSP-NET
```

### Step 2: Build
```bash
mkdir build && cd build
cmake ..
make
```

### Step 3: Run
```bash
./CSP_NET --docroot=../static --http-port=8080
```

### Step 4: Access
Open your browser and navigate to: **http://localhost:8080**

---

## Troubleshooting

### Common Issues

#### 1. Wt Framework Not Found
```bash
# Check if Wt is installed
pkg-config --list-all | grep wt

# If not found, install development packages
# openSUSE: sudo zypper install wt-devel
# Ubuntu: sudo apt-get install libwt-dev
```

#### 2. Drogon Framework Not Found
```bash
# Check if Drogon is installed
which drogon_ctl

# If not found, ensure you ran 'sudo make install' and 'sudo ldconfig'
# Also check CMake can find it:
cmake --find-package -DNAME=Drogon -DCOMPILER_ID=GNU -DLANGUAGE=CXX
```

#### 3. CMake Version Too Old
```bash
# Check CMake version
cmake --version

# Install newer version if needed
# openSUSE: sudo zypper install cmake
# Ubuntu: sudo apt-get install cmake
```

#### 4. Missing Database Libraries
```bash
# Install database development packages
# openSUSE: sudo zypper install postgresql-devel sqlite3-devel libmysqlclient-devel
# Ubuntu: sudo apt-get install libpq-dev libsqlite3-dev libmysqlclient-dev
```

#### 5. Compilation Errors
```bash
# Clean rebuild
rm -rf build
mkdir build && cd build
cmake ..
make VERBOSE=1  # For detailed output
```

### Build Environment Verification

Create and run this test script to verify your environment:

```bash
#!/bin/bash
echo "=== CSP-NET Build Environment Check ==="

echo "1. Checking C++ compiler..."
g++ --version || echo "ERROR: g++ not found"

echo "2. Checking CMake..."
cmake --version || echo "ERROR: CMake not found"

echo "3. Checking Wt framework..."
pkg-config --modversion wt || echo "ERROR: Wt not found"

echo "4. Checking Drogon framework..."
drogon_ctl version || echo "ERROR: Drogon not found"

echo "5. Checking required libraries..."
pkg-config --exists jsoncpp && echo "jsoncpp: OK" || echo "jsoncpp: MISSING"
pkg-config --exists openssl && echo "openssl: OK" || echo "openssl: MISSING"

echo "=== Environment Check Complete ==="
```

### Getting Help

If you encounter issues:

1. **Check system logs** for detailed error messages
2. **Verify all dependencies** are installed correctly
3. **Try a clean rebuild** with verbose output
4. **Check our documentation** in the repository
5. **Open an issue** on GitHub with:
   - Your operating system and version
   - Complete error messages
   - Steps you've already tried

---

## Development Environment Setup

### IDE Configuration

#### CLion
1. Open CSP-NET project directory
2. CLion should auto-detect CMake configuration
3. Set build directory to `build/`
4. Configure run target: `CSP_NET --docroot=../static --http-port=8080`

#### Visual Studio Code
1. Install C++ extension pack
2. Install CMake Tools extension
3. Open project directory
4. Use Ctrl+Shift+P → "CMake: Configure"
5. Use Ctrl+Shift+P → "CMake: Build"

#### Command Line Development
```bash
# Create development script
cat > dev.sh << 'EOF'
#!/bin/bash
echo "Building CSP-NET..."
cd build
make && echo "Build successful!" || exit 1

echo "Starting server..."
pkill CSP_NET 2>/dev/null
sleep 1
./CSP_NET --docroot=../static --http-port=8080 &
echo "Server started at http://localhost:8080"
EOF

chmod +x dev.sh
./dev.sh
```

---

*This installation guide is maintained for CSP-NET. For the latest updates, visit the [GitHub repository](https://github.com/zerohexer/CSP-NET).*