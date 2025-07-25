cmake_minimum_required(VERSION 3.16)
project(CSP_NET VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(/usr/local/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Link directories
link_directories(/usr/local/lib64)

# Collect all source files
set(SOURCES
    src/main_new.cpp
    
    # Models
    src/models/FeatureModel.cpp
    
    # Styles
    src/styles/DesignSystem.cpp
    src/styles/AppleTheme.cpp
    
    # Views - Components
    src/views/components/Navigation.cpp
    src/views/components/FeatureCard.cpp
    src/views/components/CreditCard.cpp
    
    # Views - Layouts
    src/views/layouts/MainLayout.cpp
    
    # Views - Pages
    src/views/pages/HomePage.cpp
    src/views/pages/CreditsPage.cpp
    
    # Controllers
    src/controllers/HomeController.cpp
    src/controllers/CreditsController.cpp
    
    # Clean Architecture - Builders
    src/builders/HomePageBuilder.cpp
    src/builders/CreditsPageBuilder.cpp
    
    # Clean Architecture - Components
    src/components/ComponentFactory.cpp
    
    # App
    src/app/Router.cpp
    src/app/Application.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    PRIVATE
    drogon
    trantor
    wt
    wthttp
    pthread
    dl
    stdc++fs
    ssl
    crypto
    z
    jsoncpp
    uuid
    pq
    sqlite3
    mysqlclient
)

# Compiler options
target_compile_options(${PROJECT_NAME} PRIVATE 
    -Wall
    -Wextra
    -O2
    -DCSP_NET_VERSION="1.0.0"
)

# Create necessary directories
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/static)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/views)

# Print configuration summary
message(STATUS "")
message(STATUS "CSP-NET MVC Configuration Summary:")
message(STATUS "  Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Architecture: MVC + SPA")
message(STATUS "  Version: ${PROJECT_VERSION}")
message(STATUS "  Source files: ${CMAKE_CURRENT_LIST_LENGTH} files")
message(STATUS "")