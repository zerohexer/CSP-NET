# CSP-NET Starter Template - Complete Beginner's Guide

## Table of Contents
1. [What is CSP-NET?](#what-is-csp-net)
2. [Technologies Used](#technologies-used)
3. [Project Structure](#project-structure)
4. [Prerequisites](#prerequisites)
5. [Building and Running](#building-and-running)
6. [Understanding the Code](#understanding-the-code)
7. [Design System](#design-system)
8. [Routing and Navigation](#routing-and-navigation)
9. [Adding New Features](#adding-new-features)
10. [Troubleshooting](#troubleshooting)

## What is CSP-NET?

CSP-NET is a **premium web application starter template** built with modern C++ technologies. It demonstrates how to create beautiful, Apple-inspired web applications using:

- **Drogon Framework**: High-performance C++ web framework (like Express.js but for C++)
- **Wt Framework**: C++ web GUI library (like React but for C++)
- **Apple Design System**: Premium UI design with glassmorphism effects

This template is perfect for developers who want to build fast, modern web applications using C++ instead of JavaScript.

## Technologies Used

### Core Frameworks

#### 1. Drogon Framework
- **What it is**: A modern C++ web framework for building high-performance web applications
- **Role in CSP-NET**: Backend server foundation (though we primarily use Wt's built-in server)
- **Similar to**: Express.js (Node.js), Flask (Python), or Spring Boot (Java)

#### 2. Wt Framework (Web Toolkit)
- **What it is**: A C++ library for developing web applications with widget-based GUI
- **Role in CSP-NET**: Frontend UI components and rendering
- **Similar to**: React, Angular, or Vue.js but compiled to C++

### Design Technologies
- **Apple Design System**: Premium typography, spacing, and visual effects
- **Glassmorphism**: Modern UI effect with backdrop blur and transparency
- **CSS Grid & Flexbox**: Modern layout systems
- **Apple SF Pro Font Stack**: Premium typography

## Project Structure

```
CSP-NET/
├── src/
│   └── main.cpp                 # Main application file
├── build/                       # Compiled files and build artifacts
│   ├── CSP_NET                 # Executable application
│   └── static/                 # Static web assets
├── CMakeLists.txt              # Build configuration
├── build.sh                    # Build script
├── README.md                   # Basic project info
└── DOCUMENTATION.md            # This comprehensive guide
```

### Key Files Explained

#### `src/main.cpp`
This is the **heart of your application**. It contains:
- **CSPNetApp class**: Main application class (like App.js in React)
- **Page components**: Home and Credits pages
- **Navigation system**: Routing between pages
- **CSS styling**: Complete Apple design system
- **Server setup**: Web server configuration

#### `CMakeLists.txt`
This file tells CMake **how to build your project**:
- Links Wt Framework libraries
- Links Drogon Framework libraries
- Sets compiler flags and C++ standard (C++17)
- Configures build output

#### `build/` Directory
Contains compiled application and assets:
- `CSP_NET`: Your executable web application
- `static/`: Web assets served by the application

## Prerequisites

### Required Software

1. **C++ Compiler** (GCC 7+ or Clang 5+)
   ```bash
   # Check if you have a compiler
   g++ --version
   # or
   clang++ --version
   ```

2. **CMake** (3.10+)
   ```bash
   # Check CMake version
   cmake --version
   ```

3. **Wt Framework**
   ```bash
   # Ubuntu/Debian
   sudo apt-get install libwt-dev libwthttp-dev
   
   # macOS with Homebrew
   brew install wt
   
   # Build from source (if needed)
   # See: https://webtoolkit.eu/wt/download
   ```

4. **Drogon Framework** (Optional - for extended backend features)
   ```bash
   # Ubuntu/Debian
   sudo apt-get install libdrogon-dev
   
   # Or build from source
   # See: https://github.com/drogonframework/drogon
   ```

### System Dependencies
```bash
# Ubuntu/Debian
sudo apt-get install build-essential cmake libboost-all-dev

# macOS
xcode-select --install
brew install boost
```

## Building and Running

### Method 1: Using the Build Script (Recommended)
```bash
# Make the script executable
chmod +x build.sh

# Build the project
./build.sh

# Run the application
./build/CSP_NET --docroot=./build/static --http-address=0.0.0.0 --http-port=8080
```

### Method 2: Manual CMake Build
```bash
# Create build directory
mkdir -p build
cd build

# Configure the project
cmake ..

# Build the application
make

# Return to project root
cd ..

# Run the application
./build/CSP_NET --docroot=./build/static --http-address=0.0.0.0 --http-port=8080
```

### Accessing Your Application
Once running, open your web browser and go to:
- **Local access**: http://localhost:8080
- **Network access**: http://YOUR_IP_ADDRESS:8080

## Understanding the Code

### Application Architecture

CSP-NET follows a **component-based architecture** similar to modern JavaScript frameworks:

```cpp
// Main Application Class
class CSPNetApp : public WApplication {
    // Navigation system
    PremiumNav* nav_;
    WStackedWidget* content_;
    
    // Page components
    WWidget* homePage_;
    WWidget* creditsPage_;
    
    // Navigation methods
    void showHomePage();
    void showCreditsPage();
};
```

### Key Components Breakdown

#### 1. Application Entry Point
```cpp
int main(int argc, char* argv[]) {
    // Create Wt server
    WServer server(argc, argv, WTHTTP_CONFIGURATION);
    
    // Set up application factory
    server.addEntryPoint(EntryPointType::Application, createApplication);
    
    // Start server
    if (server.start()) {
        WServer::waitForShutdown();
    }
}
```

**What this does**:
- Creates a web server using Wt's built-in HTTP server
- Registers our application factory function
- Starts the server and waits for connections

#### 2. Application Factory
```cpp
std::unique_ptr<WApplication> createApplication(const WEnvironment& env) {
    return std::make_unique<CSPNetApp>(env);
}
```

**What this does**:
- Creates a new instance of our app for each user session
- Similar to how React creates component instances

#### 3. Main Application Class
```cpp
class CSPNetApp : public WApplication {
public:
    CSPNetApp(const WEnvironment& env) : WApplication(env) {
        setTitle("CSP-NET • Premium Platform");
        
        // Set up design system
        setupAppleDesignSystem();
        
        // Create UI structure
        createNavigation();
        createPages();
    }
};
```

**What this does**:
- Inherits from Wt's WApplication (like extending React.Component)
- Sets up the complete application structure
- Applies our Apple design system

### CSS Styling System

CSP-NET uses Wt's `styleSheet().addRule()` method for styling:

```cpp
void setupAppleDesignSystem() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // Global styles
    styleSheet.addRule("body", 
        "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif; "
        "background: #000000; "
        "color: #f5f5f7;"
    );
    
    // Component styles
    styleSheet.addRule(".feature-card", 
        "background: rgba(255, 255, 255, 0.05); "
        "backdrop-filter: blur(20px); "
        "border-radius: 20px;"
    );
}
```

**Why this approach?**:
- **Type-safe**: CSS is validated at compile time
- **Component-scoped**: Styles are tied to C++ components
- **Performance**: CSS is served efficiently by Wt

### Widget System

Wt uses a **widget-based approach** similar to GUI frameworks:

```cpp
// Create a container (like a <div>)
auto container = addWidget(std::make_unique<WContainerWidget>());

// Add a text element (like <p>)
auto title = container->addWidget(std::make_unique<WText>("Hello World"));

// Apply CSS class
title->setStyleClass("hero-title");

// Set inline styles
container->setAttributeValue("style", "padding: 20px;");
```

**Widget Hierarchy**:
```
CSPNetApp (root)
├── Navigation Container
│   ├── Logo Text
│   └── Navigation Menu
│       ├── Home Link
│       └── Credits Link
├── Content Stack
│   ├── Home Page
│   │   ├── Hero Section
│   │   ├── Feature Cards
│   │   └── CTA Button
│   └── Credits Page
│       ├── Hero Section
│       └── Credit Cards
```

## Design System

### Apple-Inspired Design Principles

#### 1. Typography
```cpp
// Primary heading
"font-size: clamp(48px, 8vw, 96px); "
"font-weight: 700; "
"letter-spacing: -0.055em;"

// Body text
"font-size: 17px; "
"font-weight: 400; "
"letter-spacing: -0.022em;"
```

#### 2. Colors
- **Background**: Pure black (#000000) for premium feel
- **Text**: Apple Gray (#f5f5f7) for readability
- **Accents**: Apple Blue (#0071e3) for interactive elements
- **Glass effects**: Semi-transparent whites with blur

#### 3. Spacing System
- **Micro spacing**: 4px, 8px, 12px, 16px
- **Component spacing**: 20px, 24px, 32px, 40px
- **Section spacing**: 60px, 80px, 120px

#### 4. Glassmorphism Effects
```cpp
"background: rgba(255, 255, 255, 0.05); "
"backdrop-filter: blur(20px); "
"-webkit-backdrop-filter: blur(20px); "
"border: 1px solid rgba(255, 255, 255, 0.1);"
```

### Component Design Patterns

#### Feature Cards
```cpp
void createFeatureCard(WContainerWidget* parent, 
                      const std::string& title, 
                      const std::string& description) {
    auto card = parent->addWidget(std::make_unique<WContainerWidget>());
    card->setStyleClass("feature-card");
    
    // Add content
    auto titleWidget = card->addWidget(std::make_unique<WText>(title));
    titleWidget->setStyleClass("feature-title");
    
    auto descWidget = card->addWidget(std::make_unique<WText>(description));
    descWidget->setStyleClass("feature-desc");
}
```

**Design Features**:
- **Glass morphism**: Semi-transparent background with blur
- **Hover effects**: Smooth animations on mouse over
- **Consistent spacing**: Follows Apple's design grid

## Routing and Navigation

### Navigation System Architecture

CSP-NET uses **single-page application (SPA)** routing with Wt's `WStackedWidget`:

```cpp
class CSPNetApp : public WApplication {
private:
    WStackedWidget* contentStack_;  // Page container
    WText* homeNavItem_;           // Home navigation link
    WText* creditsNavItem_;        // Credits navigation link
    
public:
    void showHomePage() {
        contentStack_->setCurrentIndex(0);  // Show first page
        // Update navigation states
        homeNavItem_->setStyleClass("nav-item active");
        creditsNavItem_->setStyleClass("nav-item");
    }
    
    void showCreditsPage() {
        contentStack_->setCurrentIndex(1);  // Show second page
        // Update navigation states
        homeNavItem_->setStyleClass("nav-item");
        creditsNavItem_->setStyleClass("nav-item active");
    }
};
```

### How Navigation Works

1. **Page Stack**: All pages are loaded into a `WStackedWidget`
2. **Index Switching**: Navigation changes which page is visible
3. **State Management**: Active navigation item is highlighted
4. **Event Handling**: Click events trigger page transitions

### Adding New Pages

To add a new page (e.g., "About"):

1. **Declare page variable**:
```cpp
class CSPNetApp : public WApplication {
private:
    WWidget* aboutPage_;  // Add this
    WText* aboutNavItem_; // Add this
};
```

2. **Create page content**:
```cpp
void createAboutPage() {
    auto page = contentStack_->addWidget(std::make_unique<WContainerWidget>());
    page->setStyleClass("page");
    
    auto container = page->addWidget(std::make_unique<WContainerWidget>());
    container->setStyleClass("page-container");
    
    // Add your content here
    auto title = container->addWidget(std::make_unique<WText>("About Us"));
    title->setStyleClass("hero-title");
}
```

3. **Add navigation item**:
```cpp
void createNavigation(WVBoxLayout* layout) {
    // ... existing navigation code ...
    
    // Add About link
    aboutNavItem_ = menuLayout->addWidget(std::make_unique<WText>("About"));
    aboutNavItem_->setStyleClass("nav-item");
    aboutNavItem_->clicked().connect([=]() {
        showAboutPage();
    });
}
```

4. **Add navigation method**:
```cpp
void showAboutPage() {
    contentStack_->setCurrentIndex(2);  // Third page
    homeNavItem_->setStyleClass("nav-item");
    creditsNavItem_->setStyleClass("nav-item");
    aboutNavItem_->setStyleClass("nav-item active");
}
```

## Adding New Features

### Creating Custom Components

#### Example: Creating a Testimonial Card

1. **Design the component**:
```cpp
void createTestimonialCard(WContainerWidget* parent,
                          const std::string& quote,
                          const std::string& author,
                          const std::string& role) {
    auto card = parent->addWidget(std::make_unique<WContainerWidget>());
    card->setStyleClass("testimonial-card");
    
    // Quote text
    auto quoteText = card->addWidget(std::make_unique<WText>("\"" + quote + "\""));
    quoteText->setStyleClass("testimonial-quote");
    
    // Author info
    auto authorText = card->addWidget(std::make_unique<WText>(author));
    authorText->setStyleClass("testimonial-author");
    
    auto roleText = card->addWidget(std::make_unique<WText>(role));
    roleText->setStyleClass("testimonial-role");
}
```

2. **Add CSS styling**:
```cpp
void setupAppleDesignSystem() {
    // ... existing styles ...
    
    styleSheet.addRule(".testimonial-card",
        "background: rgba(255, 255, 255, 0.05); "
        "backdrop-filter: blur(20px); "
        "border-radius: 20px; "
        "padding: 32px; "
        "margin: 16px; "
        "transition: all 0.3s ease;"
    );
    
    styleSheet.addRule(".testimonial-quote",
        "font-size: 18px; "
        "font-style: italic; "
        "color: #f5f5f7; "
        "margin-bottom: 20px;"
    );
    
    styleSheet.addRule(".testimonial-author",
        "font-size: 16px; "
        "font-weight: 600; "
        "color: #ffffff; "
        "margin-bottom: 4px;"
    );
    
    styleSheet.addRule(".testimonial-role",
        "font-size: 14px; "
        "color: #8e8e93;"
    );
}
```

### Adding Interactive Elements

#### Example: Contact Form

```cpp
void createContactForm(WContainerWidget* parent) {
    auto form = parent->addWidget(std::make_unique<WContainerWidget>());
    form->setStyleClass("contact-form");
    
    // Name input
    auto nameField = form->addWidget(std::make_unique<WLineEdit>());
    nameField->setPlaceholderText("Your Name");
    nameField->setStyleClass("form-input");
    
    // Email input
    auto emailField = form->addWidget(std::make_unique<WLineEdit>());
    emailField->setPlaceholderText("Your Email");
    emailField->setStyleClass("form-input");
    
    // Message textarea
    auto messageField = form->addWidget(std::make_unique<WTextArea>());
    messageField->setPlaceholderText("Your Message");
    messageField->setStyleClass("form-textarea");
    
    // Submit button
    auto submitBtn = form->addWidget(std::make_unique<WPushButton>("Send Message"));
    submitBtn->setStyleClass("submit-button");
    
    // Handle form submission
    submitBtn->clicked().connect([=]() {
        std::string name = nameField->text().toUTF8();
        std::string email = emailField->text().toUTF8();
        std::string message = messageField->text().toUTF8();
        
        // Process form data here
        std::cout << "Form submitted: " << name << ", " << email << std::endl;
        
        // Show confirmation
        auto confirmation = form->addWidget(std::make_unique<WText>("Message sent!"));
        confirmation->setStyleClass("form-confirmation");
    });
}
```

### Backend Integration with Drogon

While CSP-NET primarily uses Wt's built-in server, you can integrate Drogon for advanced backend features:

```cpp
#include <drogon/drogon.h>

// API endpoint example
void setupDrogonAPI() {
    drogon::app().registerHandler("/api/contact",
        [](const drogon::HttpRequestPtr& req,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
            // Handle API request
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("{\"status\": \"success\"}");
            resp->setContentTypeCode(drogon::CT_APPLICATION_JSON);
            callback(resp);
        },
        {drogon::Post}
    );
}
```

## Troubleshooting

### Common Build Issues

#### 1. "Wt Framework not found"
```bash
# Solution: Install Wt development packages
sudo apt-get install libwt-dev libwthttp-dev

# Or build from source
git clone https://github.com/emweb/wt.git
cd wt
mkdir build && cd build
cmake ..
make -j4
sudo make install
```

#### 2. "CMake version too old"
```bash
# Check current version
cmake --version

# Upgrade on Ubuntu
sudo apt-get update
sudo apt-get install cmake

# Or install from snap
sudo snap install cmake --classic
```

#### 3. "Boost libraries not found"
```bash
# Install Boost development packages
sudo apt-get install libboost-all-dev
```

### Runtime Issues

#### 1. "Document root was not set"
```bash
# Always specify docroot when running
./build/CSP_NET --docroot=./build/static --http-address=0.0.0.0 --http-port=8080
```

#### 2. "Port already in use"
```bash
# Kill existing process
pkill CSP_NET

# Or use different port
./build/CSP_NET --docroot=./build/static --http-port=8081
```

#### 3. "CSS not loading"
- Ensure you're using `styleSheet().addRule()` method
- Check that CSS strings are properly formatted
- Avoid single quotes in CSS values (use double quotes)

### Development Tips

#### 1. Fast Development Cycle
```bash
# Create a development script
#!/bin/bash
make -C build && pkill CSP_NET; sleep 1 && ./build/CSP_NET --docroot=./build/static --http-port=8080
```

#### 2. Debugging
```cpp
// Add debug output
std::cout << "Debug: Page loaded" << std::endl;

// Use Wt's logging
Wt::log("info") << "Application started";
```

#### 3. CSS Hot Reloading
- Restart the application after CSS changes
- Use browser developer tools to test CSS quickly
- Copy working CSS from browser to C++ code

### Performance Optimization

#### 1. CSS Optimization
```cpp
// Combine related CSS rules
styleSheet.addRule(".card, .button",
    "transition: all 0.3s ease; "
    "border-radius: 12px;"
);
```

#### 2. Memory Management
```cpp
// Use smart pointers consistently
auto widget = std::make_unique<WContainerWidget>();

// Avoid raw pointers for widgets
// Wt handles widget lifetime automatically
```

#### 3. Server Configuration
```bash
# Production server settings
./CSP_NET --docroot=./static \
          --http-address=0.0.0.0 \
          --http-port=80 \
          --threads=4 \
          --max-request-size=1024
```

## Next Steps

### Learning Resources

1. **Wt Framework Documentation**: https://webtoolkit.eu/wt/doc/reference/html/
2. **Drogon Framework**: https://github.com/drogonframework/drogon
3. **Modern C++ Features**: https://en.cppreference.com/
4. **Apple Design Guidelines**: https://developer.apple.com/design/human-interface-guidelines/

### Project Ideas to Build

1. **Blog System**: Add post creation, editing, and display
2. **User Authentication**: Login/logout with session management
3. **File Upload**: Image upload with preview functionality
4. **Database Integration**: Connect to PostgreSQL or MySQL
5. **Real-time Features**: WebSocket chat or notifications
6. **REST API**: Build JSON API endpoints with Drogon

### Advanced Features to Explore

1. **Progressive Web App (PWA)**: Add offline functionality
2. **Server-Side Rendering**: Optimize for SEO
3. **Microservices**: Split into multiple Drogon services
4. **Docker Deployment**: Containerize the application
5. **CI/CD Pipeline**: Automated testing and deployment

---

**Congratulations!** You now have a comprehensive understanding of the CSP-NET starter template. This foundation will help you build modern, high-performance web applications using C++. The combination of Wt's widget system and Apple's design principles creates a powerful platform for premium web experiences.

Happy coding! 🚀