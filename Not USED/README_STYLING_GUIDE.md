# Wt Framework Styling & Design Guide for Beginners

## Table of Contents
1. [Introduction to Wt Framework Styling](#introduction-to-wt-framework-styling)
2. [CSS Methods in Wt Framework](#css-methods-in-wt-framework)
3. [Basic Styling Concepts](#basic-styling-concepts)
4. [Advanced Styling Techniques](#advanced-styling-techniques)
5. [Layout Systems](#layout-systems)
6. [Component Design Patterns](#component-design-patterns)
7. [Common Styling Issues & Solutions](#common-styling-issues--solutions)
8. [Best Practices](#best-practices)
9. [Real Examples from CSP-NET](#real-examples-from-csp-net)

## Introduction to Wt Framework Styling

**Wt (Web Toolkit)** is a C++ web framework that allows you to build web applications using C++ instead of HTML/CSS/JavaScript. However, you still need to understand CSS concepts because Wt generates HTML and CSS under the hood.

### Key Concepts:
- **Widgets**: C++ objects that represent HTML elements (like `<div>`, `<p>`, `<button>`)
- **CSS Styling**: Applied through C++ methods, not separate CSS files
- **Component-Based**: Build reusable UI components in C++
- **Type Safety**: CSS errors caught at compile time

### Why Learn Wt Styling?
- **Performance**: C++ backend with optimized frontend rendering
- **Type Safety**: No runtime CSS errors
- **Component Reusability**: Build once, use everywhere
- **Modern UI**: Create beautiful, responsive interfaces

## CSS Methods in Wt Framework

### Method 1: `styleSheet().addRule()` (Recommended)

This is the **best practice** for Wt Framework styling:

```cpp
void setupStyling() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // Global styles
    styleSheet.addRule("body", 
        "font-family: -apple-system, sans-serif; "
        "margin: 0; "
        "padding: 0; "
        "background: #f5f5f5;"
    );
    
    // Component styles
    styleSheet.addRule(".card", 
        "background: white; "
        "border-radius: 12px; "
        "padding: 24px; "
        "box-shadow: 0 2px 10px rgba(0,0,0,0.1);"
    );
    
    // Hover effects
    styleSheet.addRule(".card:hover", 
        "transform: translateY(-2px); "
        "box-shadow: 0 4px 20px rgba(0,0,0,0.15);"
    );
}
```

**Advantages:**
- ✅ Compile-time CSS validation
- ✅ Global styles available to all components
- ✅ Supports all CSS features (hover, media queries, etc.)
- ✅ Best performance

### Method 2: `setAttributeValue("style", ...)` (For Dynamic Styles)

Use this for **component-specific** or **dynamic** styling:

```cpp
void createStyledWidget() {
    auto widget = addWidget(std::make_unique<WContainerWidget>());
    
    // Static inline styles
    widget->setAttributeValue("style", 
        "background: linear-gradient(45deg, #ff6b6b, #4ecdc4); "
        "color: white; "
        "padding: 20px; "
        "border-radius: 8px; "
        "text-align: center;"
    );
    
    // Dynamic styles based on conditions
    if (isHighlighted) {
        widget->setAttributeValue("style", 
            widget->attributeValue("style") + 
            "border: 3px solid gold; "
            "animation: pulse 2s infinite;"
        );
    }
}
```

**Advantages:**
- ✅ Component-specific styling
- ✅ Dynamic style changes
- ✅ Immediate application
- ❌ More verbose for complex styles

### Method 3: `setStyleClass()` (Combine with Method 1)

Set CSS classes defined in `styleSheet().addRule()`:

```cpp
// 1. Define the class in setupStyling()
styleSheet.addRule(".primary-button", 
    "background: #007aff; "
    "color: white; "
    "border: none; "
    "padding: 12px 24px; "
    "border-radius: 6px; "
    "cursor: pointer;"
);

// 2. Apply the class to widgets
auto button = addWidget(std::make_unique<WPushButton>("Click Me"));
button->setStyleClass("primary-button");

// 3. Add multiple classes
button->addStyleClass("large");
button->addStyleClass("shadow");
```

**Advantages:**
- ✅ Reusable styles
- ✅ Clean component code
- ✅ Easy to maintain

### ❌ Method to Avoid: `useStyleSheet("data:text/css,...")`

```cpp
// DON'T DO THIS - Unreliable!
useStyleSheet("data:text/css," + std::string(
    ".card { background: white; }"
));
```

**Why avoid:**
- ❌ Unreliable loading
- ❌ Browser compatibility issues
- ❌ Hard to debug
- ❌ Not recommended by Wt documentation

## Basic Styling Concepts

### 1. Container Widgets (Like `<div>`)

```cpp
void createBasicContainer() {
    auto container = addWidget(std::make_unique<WContainerWidget>());
    
    // Basic styling
    container->setAttributeValue("style", 
        "width: 300px; "
        "height: 200px; "
        "background: #ffffff; "
        "border: 1px solid #ddd; "
        "border-radius: 8px; "
        "padding: 16px; "
        "margin: 16px;"
    );
    
    // Add content
    auto title = container->addWidget(std::make_unique<WText>("Card Title"));
    title->setAttributeValue("style", 
        "font-size: 18px; "
        "font-weight: bold; "
        "color: #333; "
        "margin-bottom: 12px;"
    );
}
```

### 2. Text Styling

```cpp
void createStyledText() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // Define text styles
    styleSheet.addRule(".heading-1", 
        "font-size: 32px; "
        "font-weight: 700; "
        "color: #1a1a1a; "
        "margin-bottom: 16px; "
        "line-height: 1.2;"
    );
    
    styleSheet.addRule(".body-text", 
        "font-size: 16px; "
        "font-weight: 400; "
        "color: #666; "
        "line-height: 1.5; "
        "margin-bottom: 12px;"
    );
    
    // Apply to widgets
    auto heading = addWidget(std::make_unique<WText>("Welcome to Our App"));
    heading->setStyleClass("heading-1");
    
    auto paragraph = addWidget(std::make_unique<WText>("This is some descriptive text."));
    paragraph->setStyleClass("body-text");
}
```

### 3. Button Styling

```cpp
void createStyledButtons() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // Primary button
    styleSheet.addRule(".btn-primary", 
        "background: #007aff; "
        "color: white; "
        "border: none; "
        "padding: 12px 24px; "
        "border-radius: 8px; "
        "font-size: 16px; "
        "font-weight: 500; "
        "cursor: pointer; "
        "transition: all 0.2s ease;"
    );
    
    styleSheet.addRule(".btn-primary:hover", 
        "background: #0056cc; "
        "transform: translateY(-1px); "
        "box-shadow: 0 4px 12px rgba(0, 122, 255, 0.3);"
    );
    
    // Secondary button
    styleSheet.addRule(".btn-secondary", 
        "background: transparent; "
        "color: #007aff; "
        "border: 2px solid #007aff; "
        "padding: 10px 22px; "
        "border-radius: 8px; "
        "font-size: 16px; "
        "cursor: pointer; "
        "transition: all 0.2s ease;"
    );
    
    styleSheet.addRule(".btn-secondary:hover", 
        "background: #007aff; "
        "color: white;"
    );
    
    // Apply styles
    auto primaryBtn = addWidget(std::make_unique<WPushButton>("Get Started"));
    primaryBtn->setStyleClass("btn-primary");
    
    auto secondaryBtn = addWidget(std::make_unique<WPushButton>("Learn More"));
    secondaryBtn->setStyleClass("btn-secondary");
}
```

## Advanced Styling Techniques

### 1. Glassmorphism Effect

```cpp
void createGlassCard() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    styleSheet.addRule(".glass-card", 
        "background: rgba(255, 255, 255, 0.1); "
        "backdrop-filter: blur(20px); "
        "-webkit-backdrop-filter: blur(20px); "
        "border: 1px solid rgba(255, 255, 255, 0.2); "
        "border-radius: 16px; "
        "padding: 32px; "
        "box-shadow: 0 8px 32px rgba(0, 0, 0, 0.1);"
    );
    
    auto card = addWidget(std::make_unique<WContainerWidget>());
    card->setStyleClass("glass-card");
}
```

### 2. Gradient Backgrounds

```cpp
void createGradientElements() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // Linear gradient
    styleSheet.addRule(".gradient-bg", 
        "background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); "
        "color: white; "
        "padding: 40px; "
        "border-radius: 12px;"
    );
    
    // Radial gradient
    styleSheet.addRule(".radial-gradient", 
        "background: radial-gradient(circle, #ff9a56 0%, #ff6b6b 100%); "
        "min-height: 200px; "
        "border-radius: 50%;"
    );
    
    // Text gradient
    styleSheet.addRule(".gradient-text", 
        "background: linear-gradient(45deg, #ff6b6b, #4ecdc4); "
        "background-clip: text; "
        "-webkit-background-clip: text; "
        "-webkit-text-fill-color: transparent; "
        "font-size: 48px; "
        "font-weight: bold;"
    );
}
```

### 3. Animations and Transitions

```cpp
void createAnimatedElements() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // CSS Keyframes
    styleSheet.addRule("@keyframes fadeIn", 
        "from { opacity: 0; transform: translateY(20px); } "
        "to { opacity: 1; transform: translateY(0); }"
    );
    
    styleSheet.addRule("@keyframes pulse", 
        "0% { transform: scale(1); } "
        "50% { transform: scale(1.05); } "
        "100% { transform: scale(1); }"
    );
    
    // Animated card
    styleSheet.addRule(".animated-card", 
        "animation: fadeIn 0.6s ease-out; "
        "transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1); "
        "cursor: pointer;"
    );
    
    styleSheet.addRule(".animated-card:hover", 
        "animation: pulse 2s infinite; "
        "transform: translateY(-4px);"
    );
}
```

### 4. Responsive Design

```cpp
void createResponsiveLayout() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // Base styles
    styleSheet.addRule(".responsive-grid", 
        "display: grid; "
        "grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); "
        "gap: 24px; "
        "padding: 20px;"
    );
    
    // Mobile styles
    styleSheet.addRule("@media (max-width: 768px)", 
        ".responsive-grid { "
        "  grid-template-columns: 1fr; "
        "  gap: 16px; "
        "  padding: 16px; "
        "} "
        ".nav-menu { "
        "  flex-direction: column; "
        "  gap: 12px; "
        "}"
    );
    
    // Tablet styles
    styleSheet.addRule("@media (min-width: 769px) and (max-width: 1024px)", 
        ".responsive-grid { "
        "  grid-template-columns: repeat(2, 1fr); "
        "}"
    );
}
```

## Layout Systems

### 1. CSS Grid Layout

```cpp
void createGridLayout() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // Grid container
    styleSheet.addRule(".grid-container", 
        "display: grid; "
        "grid-template-columns: 1fr 2fr 1fr; "
        "grid-template-rows: auto 1fr auto; "
        "grid-gap: 20px; "
        "min-height: 100vh; "
        "grid-template-areas: "
        "  'header header header' "
        "  'sidebar main aside' "
        "  'footer footer footer';"
    );
    
    // Grid items
    styleSheet.addRule(".header", "grid-area: header; background: #f8f9fa;");
    styleSheet.addRule(".sidebar", "grid-area: sidebar; background: #e9ecef;");
    styleSheet.addRule(".main", "grid-area: main; background: white;");
    styleSheet.addRule(".aside", "grid-area: aside; background: #e9ecef;");
    styleSheet.addRule(".footer", "grid-area: footer; background: #f8f9fa;");
    
    // Create layout
    auto container = addWidget(std::make_unique<WContainerWidget>());
    container->setStyleClass("grid-container");
    
    auto header = container->addWidget(std::make_unique<WContainerWidget>());
    header->setStyleClass("header");
    // ... add other sections
}
```

### 2. Flexbox Layout

```cpp
void createFlexLayout() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // Flex container
    styleSheet.addRule(".flex-container", 
        "display: flex; "
        "flex-direction: row; "
        "justify-content: space-between; "
        "align-items: center; "
        "padding: 20px; "
        "gap: 16px;"
    );
    
    // Flex items
    styleSheet.addRule(".flex-item", 
        "flex: 1; "
        "padding: 16px; "
        "background: #f8f9fa; "
        "border-radius: 8px;"
    );
    
    styleSheet.addRule(".flex-item.grow", "flex-grow: 2;");
    styleSheet.addRule(".flex-item.shrink", "flex-shrink: 0;");
    
    // Create flex layout
    auto container = addWidget(std::make_unique<WContainerWidget>());
    container->setStyleClass("flex-container");
    
    auto item1 = container->addWidget(std::make_unique<WContainerWidget>());
    item1->setStyleClass("flex-item");
    
    auto item2 = container->addWidget(std::make_unique<WContainerWidget>());
    item2->setStyleClass("flex-item grow");
}
```

### 3. Wt Layout Managers vs CSS

**Wt Layout Managers** (WVBoxLayout, WHBoxLayout):
```cpp
// Good for: Simple, programmatic layouts
auto layout = setLayout(std::make_unique<WVBoxLayout>());
layout->addWidget(std::make_unique<WText>("Item 1"));
layout->addWidget(std::make_unique<WText>("Item 2"));
layout->setSpacing(10);
```

**CSS Layouts** (Grid, Flexbox):
```cpp
// Good for: Complex, responsive layouts
styleSheet.addRule(".container", 
    "display: grid; "
    "grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));"
);
```

**When to use each:**
- **Wt Layouts**: Simple forms, dialog boxes, basic arrangements
- **CSS Layouts**: Complex responsive designs, card grids, modern layouts

## Component Design Patterns

### 1. Card Component Pattern

```cpp
class CardComponent {
public:
    static void createCard(WContainerWidget* parent, 
                          const std::string& title,
                          const std::string& content,
                          const std::string& imageUrl = "") {
        auto card = parent->addWidget(std::make_unique<WContainerWidget>());
        card->setStyleClass("card");
        
        // Image (optional)
        if (!imageUrl.empty()) {
            auto image = card->addWidget(std::make_unique<WImage>(imageUrl));
            image->setStyleClass("card-image");
        }
        
        // Content area
        auto cardBody = card->addWidget(std::make_unique<WContainerWidget>());
        cardBody->setStyleClass("card-body");
        
        auto cardTitle = cardBody->addWidget(std::make_unique<WText>(title));
        cardTitle->setStyleClass("card-title");
        
        auto cardContent = cardBody->addWidget(std::make_unique<WText>(content));
        cardContent->setStyleClass("card-content");
        
        // Actions
        auto actions = cardBody->addWidget(std::make_unique<WContainerWidget>());
        actions->setStyleClass("card-actions");
        
        auto button = actions->addWidget(std::make_unique<WPushButton>("Learn More"));
        button->setStyleClass("btn-primary");
    }
    
    static void setupCardStyles() {
        auto& styleSheet = WApplication::instance()->styleSheet();
        
        styleSheet.addRule(".card", 
            "background: white; "
            "border-radius: 12px; "
            "overflow: hidden; "
            "box-shadow: 0 2px 8px rgba(0,0,0,0.1); "
            "transition: all 0.3s ease;"
        );
        
        styleSheet.addRule(".card:hover", 
            "box-shadow: 0 8px 25px rgba(0,0,0,0.15); "
            "transform: translateY(-2px);"
        );
        
        styleSheet.addRule(".card-image", 
            "width: 100%; "
            "height: 200px; "
            "object-fit: cover;"
        );
        
        styleSheet.addRule(".card-body", 
            "padding: 20px;"
        );
        
        styleSheet.addRule(".card-title", 
            "font-size: 20px; "
            "font-weight: 600; "
            "margin-bottom: 12px; "
            "color: #333;"
        );
        
        styleSheet.addRule(".card-content", 
            "font-size: 14px; "
            "color: #666; "
            "line-height: 1.5; "
            "margin-bottom: 16px;"
        );
        
        styleSheet.addRule(".card-actions", 
            "display: flex; "
            "justify-content: flex-end;"
        );
    }
};
```

### 2. Navigation Component Pattern

```cpp
class NavigationComponent {
public:
    static WContainerWidget* createNavigation(
        WContainerWidget* parent,
        const std::vector<std::pair<std::string, std::function<void()>>>& navItems) {
        
        auto nav = parent->addWidget(std::make_unique<WContainerWidget>());
        nav->setStyleClass("navigation");
        
        auto navContainer = nav->addWidget(std::make_unique<WContainerWidget>());
        navContainer->setStyleClass("nav-container");
        
        // Logo
        auto logo = navContainer->addWidget(std::make_unique<WText>("MyApp"));
        logo->setStyleClass("nav-logo");
        
        // Navigation items
        auto navMenu = navContainer->addWidget(std::make_unique<WContainerWidget>());
        navMenu->setStyleClass("nav-menu");
        
        for (const auto& item : navItems) {
            auto navItem = navMenu->addWidget(std::make_unique<WText>(item.first));
            navItem->setStyleClass("nav-item");
            navItem->clicked().connect(item.second);
        }
        
        return nav;
    }
    
    static void setupNavigationStyles() {
        auto& styleSheet = WApplication::instance()->styleSheet();
        
        styleSheet.addRule(".navigation", 
            "background: rgba(255, 255, 255, 0.95); "
            "backdrop-filter: blur(20px); "
            "border-bottom: 1px solid rgba(0,0,0,0.1); "
            "position: sticky; "
            "top: 0; "
            "z-index: 1000;"
        );
        
        styleSheet.addRule(".nav-container", 
            "max-width: 1200px; "
            "margin: 0 auto; "
            "display: flex; "
            "justify-content: space-between; "
            "align-items: center; "
            "padding: 16px 24px;"
        );
        
        styleSheet.addRule(".nav-logo", 
            "font-size: 24px; "
            "font-weight: 700; "
            "color: #333;"
        );
        
        styleSheet.addRule(".nav-menu", 
            "display: flex; "
            "gap: 32px;"
        );
        
        styleSheet.addRule(".nav-item", 
            "color: #666; "
            "cursor: pointer; "
            "padding: 8px 16px; "
            "border-radius: 6px; "
            "transition: all 0.2s ease;"
        );
        
        styleSheet.addRule(".nav-item:hover", 
            "color: #007aff; "
            "background: rgba(0, 122, 255, 0.1);"
        );
    }
};
```

## Common Styling Issues & Solutions

### 1. **Issue: CSS Not Loading**

**Problem:**
```cpp
// This doesn't work reliably
useStyleSheet("data:text/css,.card { background: white; }");
```

**Solution:**
```cpp
// Use styleSheet().addRule() instead
auto& styleSheet = WApplication::instance()->styleSheet();
styleSheet.addRule(".card", "background: white;");
```

### 2. **Issue: Hover Effects Not Working**

**Problem:**
```cpp
// Missing hover styles
widget->setAttributeValue("style", "background: blue;");
```

**Solution:**
```cpp
// Add hover effects via CSS
styleSheet.addRule(".my-widget", "background: blue; transition: all 0.2s;");
styleSheet.addRule(".my-widget:hover", "background: darkblue;");
widget->setStyleClass("my-widget");
```

### 3. **Issue: Elements Getting Clipped During Animation**

**Problem:**
```cpp
// Transform without proper container
styleSheet.addRule(".card:hover", "transform: translateY(-10px);");
```

**Solution:**
```cpp
// Add padding and overflow to container
styleSheet.addRule(".card-container", 
    "padding: 20px; "
    "overflow: visible;"
);
styleSheet.addRule(".card:hover", "transform: translateY(-10px);");
```

### 4. **Issue: Responsive Design Not Working**

**Problem:**
```cpp
// Fixed width containers
styleSheet.addRule(".container", "width: 1200px;");
```

**Solution:**
```cpp
// Responsive containers
styleSheet.addRule(".container", 
    "max-width: 1200px; "
    "width: 100%; "
    "margin: 0 auto; "
    "padding: 0 20px;"
);

styleSheet.addRule("@media (max-width: 768px)", 
    ".container { padding: 0 16px; }"
);
```

### 5. **Issue: Font Loading Problems**

**Problem:**
```cpp
// Fonts not loading
styleSheet.addRule("body", "font-family: 'Custom Font';");
```

**Solution:**
```cpp
// Use system font stack
styleSheet.addRule("body", 
    "font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', "
    "Roboto, 'Helvetica Neue', Arial, sans-serif;"
);
```

## Best Practices

### 1. **Organization and Structure**

```cpp
class MyApp : public WApplication {
public:
    MyApp(const WEnvironment& env) : WApplication(env) {
        // 1. Set up global styles first
        setupGlobalStyles();
        
        // 2. Set up component styles
        setupComponentStyles();
        
        // 3. Create UI structure
        createUI();
    }
    
private:
    void setupGlobalStyles() {
        auto& styleSheet = WApplication::instance()->styleSheet();
        
        // Reset and base styles
        styleSheet.addRule("*", 
            "margin: 0; "
            "padding: 0; "
            "box-sizing: border-box;"
        );
        
        styleSheet.addRule("body", 
            "font-family: -apple-system, sans-serif; "
            "line-height: 1.6; "
            "color: #333;"
        );
    }
    
    void setupComponentStyles() {
        // Component-specific styles
        CardComponent::setupCardStyles();
        NavigationComponent::setupNavigationStyles();
        // ... other components
    }
    
    void createUI() {
        // Build your UI here
    }
};
```

### 2. **CSS Class Naming Convention**

```cpp
// Use BEM-like naming
styleSheet.addRule(".card", "/* Block */");
styleSheet.addRule(".card__header", "/* Element */");
styleSheet.addRule(".card__header--large", "/* Modifier */");

// Or use simple descriptive names
styleSheet.addRule(".primary-button", "");
styleSheet.addRule(".secondary-button", "");
styleSheet.addRule(".danger-button", "");
```

### 3. **Performance Optimization**

```cpp
// Group similar styles
styleSheet.addRule(".btn, .link, .card", 
    "transition: all 0.2s ease; "
    "cursor: pointer;"
);

// Use CSS custom properties for themes
styleSheet.addRule(":root", 
    "--primary-color: #007aff; "
    "--secondary-color: #34c759; "
    "--text-color: #333; "
    "--bg-color: #f8f9fa;"
);

styleSheet.addRule(".primary-button", 
    "background: var(--primary-color);"
);
```

### 4. **Responsive Design Patterns**

```cpp
// Mobile-first approach
styleSheet.addRule(".grid", 
    "display: grid; "
    "grid-template-columns: 1fr; "
    "gap: 16px;"
);

styleSheet.addRule("@media (min-width: 768px)", 
    ".grid { grid-template-columns: repeat(2, 1fr); }"
);

styleSheet.addRule("@media (min-width: 1024px)", 
    ".grid { grid-template-columns: repeat(3, 1fr); }"
);
```

### 5. **Color and Typography Systems**

```cpp
void setupDesignSystem() {
    auto& styleSheet = WApplication::instance()->styleSheet();
    
    // Color palette
    styleSheet.addRule(":root", 
        "--color-primary: #007aff; "
        "--color-secondary: #34c759; "
        "--color-danger: #ff3b30; "
        "--color-warning: #ff9500; "
        "--color-gray-50: #f9fafb; "
        "--color-gray-100: #f3f4f6; "
        "--color-gray-900: #111827; "
        "--spacing-xs: 4px; "
        "--spacing-sm: 8px; "
        "--spacing-md: 16px; "
        "--spacing-lg: 24px; "
        "--spacing-xl: 32px; "
        "--radius-sm: 4px; "
        "--radius-md: 8px; "
        "--radius-lg: 12px;"
    );
    
    // Typography scale
    styleSheet.addRule(".text-xs", "font-size: 12px; line-height: 1.4;");
    styleSheet.addRule(".text-sm", "font-size: 14px; line-height: 1.4;");
    styleSheet.addRule(".text-base", "font-size: 16px; line-height: 1.5;");
    styleSheet.addRule(".text-lg", "font-size: 18px; line-height: 1.5;");
    styleSheet.addRule(".text-xl", "font-size: 20px; line-height: 1.4;");
    styleSheet.addRule(".text-2xl", "font-size: 24px; line-height: 1.3;");
    styleSheet.addRule(".text-3xl", "font-size: 30px; line-height: 1.2;");
}
```

## Real Examples from CSP-NET

### Example 1: Apple-Style Navigation

```cpp
// From CSP-NET: Premium navigation with glassmorphism
styleSheet.addRule(".nav-bar", 
    "background: rgba(29, 29, 31, 0.8); "
    "backdrop-filter: saturate(180%) blur(20px); "
    "-webkit-backdrop-filter: saturate(180%) blur(20px); "
    "border-bottom: 0.5px solid rgba(255, 255, 255, 0.1); "
    "height: 52px; "
    "position: sticky; "
    "top: 0; "
    "z-index: 9999;"
);

styleSheet.addRule(".nav-item", 
    "color: #f5f5f7; "
    "font-size: 17px; "
    "font-weight: 400; "
    "padding: 8px 16px; "
    "border-radius: 20px; "
    "transition: all 0.3s ease; "
    "cursor: pointer; "
    "opacity: 0.8;"
);

styleSheet.addRule(".nav-item:hover", 
    "opacity: 1; "
    "background: rgba(255, 255, 255, 0.1); "
    "transform: translateY(-1px);"
);
```

### Example 2: Feature Cards with Hover Effects

```cpp
// From CSP-NET: Premium feature cards
styleSheet.addRule(".feature-card", 
    "background: rgba(255, 255, 255, 0.05); "
    "backdrop-filter: blur(20px); "
    "-webkit-backdrop-filter: blur(20px); "
    "border: 1px solid rgba(255, 255, 255, 0.1); "
    "border-radius: 20px; "
    "padding: 40px 32px; "
    "transition: all 0.4s ease; "
    "position: relative; "
    "overflow: hidden;"
);

styleSheet.addRule(".feature-card::before", 
    "content: ''; "
    "position: absolute; "
    "top: 0; "
    "left: 0; "
    "right: 0; "
    "height: 1px; "
    "background: linear-gradient(90deg, transparent, rgba(255, 255, 255, 0.4), transparent);"
);

styleSheet.addRule(".feature-card:hover", 
    "transform: translateY(-8px); "
    "background: rgba(255, 255, 255, 0.08); "
    "border-color: rgba(255, 255, 255, 0.2); "
    "box-shadow: 0 20px 40px rgba(0, 0, 0, 0.3);"
);
```

### Example 3: Premium Button with Dynamic Styling

```cpp
// From CSP-NET: Dynamic button styling with hover effects
void createPremiumButton() {
    auto button = addWidget(std::make_unique<WPushButton>("Get Started"));
    
    // Base styling
    button->setAttributeValue("style", 
        "background: linear-gradient(135deg, #007aff 0%, #0056cc 100%); "
        "color: #ffffff; "
        "border: none; "
        "border-radius: 50px; "
        "padding: 20px 40px; "
        "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif; "
        "font-size: 18px; "
        "font-weight: 600; "
        "letter-spacing: -0.01em; "
        "cursor: pointer; "
        "transition: all 0.4s cubic-bezier(0.175, 0.885, 0.32, 1.275); "
        "box-shadow: 0 8px 30px rgba(0, 122, 255, 0.4), 0 4px 15px rgba(0, 122, 255, 0.2); "
        "backdrop-filter: blur(10px); "
        "position: relative; "
        "overflow: hidden; "
        "text-shadow: 0 1px 2px rgba(0, 0, 0, 0.1);"
    );
    
    // Dynamic hover effects
    button->mouseWentOver().connect([button]() {
        button->setAttributeValue("style", 
            "background: linear-gradient(135deg, #0084ff 0%, #0066ff 100%); "
            "color: #ffffff; "
            "border: none; "
            "border-radius: 50px; "
            "padding: 20px 40px; "
            "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif; "
            "font-size: 18px; "
            "font-weight: 600; "
            "letter-spacing: -0.01em; "
            "cursor: pointer; "
            "transition: all 0.4s cubic-bezier(0.175, 0.885, 0.32, 1.275); "
            "box-shadow: 0 12px 40px rgba(0, 122, 255, 0.6), 0 8px 25px rgba(0, 122, 255, 0.3); "
            "backdrop-filter: blur(10px); "
            "position: relative; "
            "overflow: hidden; "
            "text-shadow: 0 1px 2px rgba(0, 0, 0, 0.1); "
            "transform: translateY(-3px) scale(1.02);"
        );
    });
}
```

---

## Conclusion

This guide covers the essential concepts for styling Wt Framework applications. Key takeaways:

1. **Use `styleSheet().addRule()`** for global and component styles
2. **Use `setAttributeValue("style", ...)`** for dynamic and component-specific styling
3. **Avoid `useStyleSheet("data:text/css")`** method - it's unreliable
4. **Plan your design system** with consistent colors, typography, and spacing
5. **Use proper overflow settings** for animations and hover effects
6. **Follow responsive design principles** with mobile-first approach
7. **Organize styles** logically in your application structure

With these techniques, you can create beautiful, modern web applications using Wt Framework that rival any JavaScript-based solution!

**Happy Styling! 🎨**