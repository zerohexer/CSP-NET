# CSP-NET MVC Architecture Guide

## Overview

CSP-NET has been restructured from a single-file monolith into a clean, modular **MVC (Model-View-Controller) + SPA (Single Page Application)** architecture. This provides better code organization, maintainability, and scalability.

## 🏗️ Project Structure

```
CSP-NET/
├── src/
│   ├── main_new.cpp                    # Application entry point
│   │
│   ├── app/                           # 🚀 Application Core
│   │   ├── Application.h/.cpp         # Main application class
│   │   └── Router.h/.cpp             # SPA routing system
│   │
│   ├── controllers/                   # 🎮 MVC Controllers
│   │   ├── HomeController.h/.cpp      # Home page logic
│   │   └── CreditsController.h/.cpp   # Credits page logic
│   │
│   ├── views/                         # 🎨 UI Components & Pages
│   │   ├── layouts/
│   │   │   └── MainLayout.h/.cpp      # Main app layout
│   │   ├── pages/
│   │   │   ├── HomePage.h/.cpp        # Home page view
│   │   │   └── CreditsPage.h/.cpp     # Credits page view
│   │   └── components/
│   │       ├── Navigation.h/.cpp      # Navigation component
│   │       ├── FeatureCard.h/.cpp     # Feature card component
│   │       └── CreditCard.h/.cpp      # Credit card component
│   │
│   ├── styles/                        # 🎨 Design System
│   │   ├── DesignSystem.h/.cpp        # Core design system
│   │   └── AppleTheme.h/.cpp          # Apple-inspired styling
│   │
│   └── models/                        # 📊 Data Models
│       └── FeatureModel.h/.cpp        # Data structures
│
├── CMakeLists_new.txt                 # Build configuration for MVC
├── ARCHITECTURE_GUIDE.md              # This file
├── DOCUMENTATION.md                   # General documentation
└── README_STYLING_GUIDE.md            # Styling guide
```

## 🏛️ Architecture Patterns

### MVC Pattern
- **Models**: Data structures and business logic
- **Views**: UI components and pages
- **Controllers**: Handle user interactions and coordinate between models and views

### SPA Pattern
- **Single Page Application**: No page reloads, smooth transitions
- **Router**: Client-side routing between pages
- **Component-based**: Reusable UI components

### Component Architecture
- **Layouts**: Page structure and navigation
- **Pages**: Full page components
- **Components**: Reusable UI elements

## 📁 Detailed File Structure

### Entry Point (`main_new.cpp`)
```cpp
// Clean entry point - only server setup
int main(int argc, char* argv[]) {
    WServer server(argc, argv, WTHTTP_CONFIGURATION);
    server.addEntryPoint(EntryPointType::Application, CSPNet::App::createApplication);
    server.start();
    WServer::waitForShutdown();
}
```

### Application Core (`app/`)

#### `Application.h/.cpp`
- Main application class inheriting from `WApplication`
- Coordinates all components: layout, controllers, routing
- Sets up design system and initializes the app

#### `Router.h/.cpp`
- SPA routing system
- Maps routes to handler functions
- Manages navigation state

### Controllers (`controllers/`)

#### `HomeController.h/.cpp`
```cpp
class HomeController {
public:
    std::unique_ptr<Views::Pages::HomePage> createView();
    void handleGetStartedClick();
    void handleFeatureInteraction(const std::string& featureId);
};
```

#### `CreditsController.h/.cpp`
```cpp
class CreditsController {
public:
    std::unique_ptr<Views::Pages::CreditsPage> createView();
    void handleCreditInteraction(const std::string& creditId);
};
```

### Views (`views/`)

#### Layouts (`views/layouts/`)
**`MainLayout.h/.cpp`**: Main application layout
- Navigation bar
- Content area (WStackedWidget for SPA)
- Handles page transitions

#### Pages (`views/pages/`)
**`HomePage.h/.cpp`**: Home page implementation
- Hero section
- Feature cards
- CTA button
- Tech stack section

**`CreditsPage.h/.cpp`**: Credits page implementation
- Hero section
- Credit cards grid

#### Components (`views/components/`)
**`Navigation.h/.cpp`**: Navigation bar component
- Logo
- Navigation items
- Active state management

**`FeatureCard.h/.cpp`**: Reusable feature card
- Takes `FeatureModel` as input
- Consistent styling and behavior

**`CreditCard.h/.cpp`**: Reusable credit card
- Takes `CreditModel` as input
- Hover effects and styling

### Styles (`styles/`)

#### `DesignSystem.h/.cpp`
- Global styles (reset, typography, base)
- Component styles (pages, containers)
- Layout styles (grid, flexbox)
- Responsive styles (media queries)

#### `AppleTheme.h/.cpp`
- Apple-specific styling
- Navigation styling
- Card effects (glassmorphism)
- Animations and transitions

### Models (`models/`)

#### `FeatureModel.h/.cpp`
```cpp
struct FeatureModel {
    std::string title;
    std::string description;
    std::string icon;
};

struct CreditModel {
    std::string name;
    std::string role;
    std::string avatar;
};

class AppData {
    static std::vector<FeatureModel> getFeatures();
    static std::vector<CreditModel> getCredits();
};
```

## 🔄 Data Flow

### Application Startup
1. `main_new.cpp` → Creates `Application`
2. `Application` → Sets up design system
3. `Application` → Creates controllers
4. `Application` → Creates main layout
5. `Application` → Sets up routing
6. `Application` → Creates pages

### Navigation Flow
1. User clicks navigation → `Navigation` component
2. `Navigation` → Calls navigation callback
3. `MainLayout` → Handles page transition
4. `Router` → Updates route state
5. `WStackedWidget` → Shows selected page

### Component Data Flow
1. `Models::AppData` → Provides data
2. `Controllers` → Create views with data
3. `Pages` → Use components to render UI
4. `Components` → Display data consistently

## 🚀 Getting Started

### Building the MVC Version

1. **Replace CMakeLists.txt**:
   ```bash
   cp CMakeLists_new.txt CMakeLists.txt
   ```

2. **Clean and rebuild**:
   ```bash
   rm -rf build
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the application**:
   ```bash
   ./CSP_NET --docroot=./static --http-address=0.0.0.0 --http-port=8080
   ```

### Switching Between Versions

**Monolithic version** (original):
```bash
cp CMakeLists_original.txt CMakeLists.txt  # If you backed it up
# Edit CMakeLists.txt to use src/main.cpp
```

**MVC version** (new):
```bash
cp CMakeLists_new.txt CMakeLists.txt
# Uses src/main_new.cpp and all MVC files
```

## 🔧 Development Patterns

### Adding a New Page

1. **Create the model** (if needed):
   ```cpp
   // models/AboutModel.h
   struct AboutModel {
       std::string mission;
       std::string vision;
   };
   ```

2. **Create the controller**:
   ```cpp
   // controllers/AboutController.h/.cpp
   class AboutController {
   public:
       std::unique_ptr<Views::Pages::AboutPage> createView();
   };
   ```

3. **Create the page view**:
   ```cpp
   // views/pages/AboutPage.h/.cpp
   class AboutPage : public Wt::WContainerWidget {
   public:
       AboutPage();
   private:
       void createPageStructure();
   };
   ```

4. **Add route to application**:
   ```cpp
   // app/Application.cpp
   void Application::setupRouting() {
       router_->addRoute("about", [this]() { navigateToAbout(); });
   }
   ```

5. **Add navigation item**:
   ```cpp
   // views/components/Navigation.cpp
   auto aboutNavItem = menuLayout->addWidget(std::make_unique<Wt::WText>("About"));
   aboutNavItem->clicked().connect([=]() { onNavigate_("about"); });
   ```

### Adding a New Component

1. **Create component files**:
   ```cpp
   // views/components/MyComponent.h
   class MyComponent : public Wt::WContainerWidget {
   public:
       MyComponent(const MyData& data);
   private:
       void setupComponent();
   };
   ```

2. **Add styling** (if needed):
   ```cpp
   // styles/DesignSystem.cpp or AppleTheme.cpp
   styleSheet.addRule(".my-component", "/* styling */");
   ```

3. **Use in pages**:
   ```cpp
   // views/pages/SomePage.cpp
   auto myComponent = addWidget(std::make_unique<MyComponent>(data));
   ```

## 🎨 Styling Architecture

### Design System Hierarchy
1. **Global styles** (`DesignSystem.cpp`)
   - Reset, typography, base colors
   
2. **Component styles** (`DesignSystem.cpp`)
   - Generic component patterns
   
3. **Theme styles** (`AppleTheme.cpp`)
   - Brand-specific styling
   
4. **Component-specific styles**
   - Inline styles for dynamic behavior

### CSS Organization
```cpp
// In DesignSystem.cpp - Generic patterns
styleSheet.addRule(".card", "/* generic card styles */");

// In AppleTheme.cpp - Apple-specific
styleSheet.addRule(".feature-card", "/* Apple glassmorphism */");

// In components - Dynamic behavior
widget->setAttributeValue("style", "/* dynamic styles */");
```

## 🧪 Testing the Architecture

### Testing Individual Components
```cpp
// Test a component in isolation
auto feature = FeatureModel("Test", "Description");
auto card = std::make_unique<FeatureCard>(feature);
// Verify card creation and styling
```

### Testing Page Navigation
```cpp
// Test routing
router->navigate("home");
assert(router->getCurrentRoute() == "home");
```

### Testing Data Flow
```cpp
// Test model data
auto features = AppData::getFeatures();
assert(features.size() == 3);
```

## 🚀 Benefits of This Architecture

### 🔧 **Maintainability**
- **Separation of concerns**: Each file has a specific purpose
- **Easy to find code**: Logical file organization
- **Modular**: Changes to one component don't affect others

### 📈 **Scalability**
- **Easy to add pages**: Follow established patterns
- **Reusable components**: DRY principle
- **Team development**: Multiple developers can work on different parts

### 🐛 **Debugging**
- **Isolated issues**: Problems are contained to specific files
- **Clear data flow**: Easy to trace how data moves through the app
- **Compile-time safety**: Better type checking

### 🎨 **Design Consistency**
- **Centralized styling**: Design system ensures consistency
- **Component reuse**: UI elements look and behave consistently
- **Theme management**: Easy to change the entire app's appearance

### 🔄 **Performance**
- **Component reuse**: Less code duplication
- **Modular compilation**: Only changed files need recompiling
- **Clear dependencies**: Better optimization opportunities

## 🛠️ Customization Guide

### Changing the Design Theme
1. Modify `AppleTheme.cpp` for Apple-specific styling
2. Create new theme files (e.g., `MaterialTheme.cpp`)
3. Switch themes in `Application::setupDesignSystem()`

### Adding Business Logic
1. Extend models with new data structures
2. Add methods to controllers for business logic
3. Keep views focused on presentation only

### Extending the Router
1. Add new route patterns
2. Implement parameter parsing
3. Add middleware for authentication, etc.

---

## 🎯 Migration from Monolithic to MVC

If you're moving from the original single-file structure:

### What Changed
- **Single file** → **Multiple organized files**
- **Everything in main.cpp** → **Separated by responsibility**
- **Mixed concerns** → **Clear MVC separation**
- **Hard to extend** → **Easy to add features**

### What Stayed the Same
- **Same functionality**: All features work identically
- **Same styling**: Exact same Apple design system
- **Same performance**: No performance degradation
- **Same build process**: Still uses CMake and Wt Framework

### Migration Steps
1. Backup your current `main.cpp`
2. Use the new MVC structure
3. Build and test
4. Gradually customize and extend

This architecture provides a solid foundation for building scalable, maintainable web applications with Wt Framework! 🚀