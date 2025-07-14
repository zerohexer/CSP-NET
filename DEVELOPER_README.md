# CSP-NET Starter Template
**🚀 Modern C++ Web Development Made Easy**

---

## 🎯 Quick Start (5 Minutes)

### 1. Prerequisites
```bash
# Install required packages (Ubuntu/Debian)
sudo apt-get install build-essential cmake libwt-dev libwthttp-dev libdrogon-dev

# macOS
brew install cmake wt drogon
```

### 2. Build & Run
```bash
# Clone or download CSP-NET
cd CSP-NET

# Build
mkdir build && cd build
cmake .. && make

# Run
./CSP_NET --docroot=../static --http-port=8080
```

### 3. Open Browser
Visit: **http://localhost:8080**

You'll see a beautiful Apple-inspired web app with smooth navigation!

---

## 📁 Project Structure (What Goes Where)

```
src/
├── 🏗️ builders/           👈 ADD NEW PAGES HERE
│   ├── HomePageBuilder.cpp    # Home page construction
│   └── CreditsPageBuilder.cpp # Credits page construction
│
├── 🧩 components/         👈 ADD REUSABLE COMPONENTS HERE  
│   └── ComponentFactory.cpp  # UI components (cards, buttons, forms)
│
├── 🎨 styles/             👈 CUSTOMIZE DESIGN HERE
│   ├── DesignSystem.cpp       # Core CSS & layout
│   └── AppleTheme.cpp         # Colors, effects, animations
│
├── 🎮 controllers/        👈 ADD BUSINESS LOGIC HERE
│   ├── HomeController.cpp     # Home page interactions
│   └── CreditsController.cpp  # Credits page interactions
│
├── 📊 models/             👈 ADD DATA STRUCTURES HERE
│   └── FeatureModel.cpp       # Data models and structures
│
├── 📱 views/              👈 BASIC UI COMPONENTS
│   ├── components/            # Navigation, cards, etc.
│   ├── layouts/               # Page layouts
│   └── pages/                 # Individual pages
│
└── 🎭 app/                👈 CORE APPLICATION (rarely edited)
    ├── Application.cpp        # Main app coordinator
    └── Router.cpp             # URL routing
```

---

## 🎨 Customization Guide

### Change Colors & Theme

**Edit: `src/styles/AppleTheme.cpp`**

```cpp
// Change primary colors
styleSheet.addRule(".nav-bar", 
    "background: rgba(29, 29, 31, 0.8);"  // Dark nav → Change to your color
);

// Change accent color
styleSheet.addRule(".cta-button", 
    "background: #007aff;"  // Apple blue → Change to your brand color
);

// Change card background
styleSheet.addRule(".feature-card", 
    "background: rgba(255, 255, 255, 0.05);"  // Glass effect → Customize opacity
);
```

### Change Typography

**Edit: `src/styles/DesignSystem.cpp`**

```cpp
// Change font family
styleSheet.addRule("html, body", 
    "font-family: 'Your Custom Font', -apple-system, BlinkMacSystemFont, sans-serif;"
);

// Change font sizes
styleSheet.addRule(".hero-title", 
    "font-size: clamp(48px, 8vw, 96px);"  // Responsive title size
);
```

### Customize Content

**Edit: `src/builders/HomePageBuilder.cpp`**

```cpp
// Change hero text
auto title = heroLayout->addWidget(std::make_unique<Wt::WText>("Your App Name"));
auto subtitle = heroLayout->addWidget(std::make_unique<Wt::WText>("Your tagline here"));

// Change feature cards
ComponentFactory::createFeatureCard(features, 
    "Your Feature Title", 
    "Your feature description here");
```

---

## ➕ Adding New Features

### 1. Add a New Component

**Example: Creating a Pricing Card**

**Step 1: Add to `src/components/ComponentFactory.h`**
```cpp
class ComponentFactory {
public:
    // Add this line
    static void createPricingCard(Wt::WContainerWidget* parent,
                                const std::string& plan,
                                const std::string& price,
                                const std::vector<std::string>& features);
};
```

**Step 2: Implement in `src/components/ComponentFactory.cpp`**
```cpp
void ComponentFactory::createPricingCard(Wt::WContainerWidget* parent,
                                        const std::string& plan,
                                        const std::string& price,
                                        const std::vector<std::string>& features) {
    auto card = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    card->setStyleClass("pricing-card");
    
    auto layout = card->setLayout(std::make_unique<Wt::WVBoxLayout>());
    
    // Plan name
    auto planName = layout->addWidget(std::make_unique<Wt::WText>(plan));
    planName->setStyleClass("pricing-plan");
    
    // Price
    auto priceText = layout->addWidget(std::make_unique<Wt::WText>(price));
    priceText->setStyleClass("pricing-price");
    
    // Features list
    for (const auto& feature : features) {
        auto featureText = layout->addWidget(std::make_unique<Wt::WText>("✓ " + feature));
        featureText->setStyleClass("pricing-feature");
    }
    
    // Subscribe button
    auto button = layout->addWidget(std::make_unique<Wt::WPushButton>("Choose Plan"));
    button->setStyleClass("pricing-button");
}
```

**Step 3: Add CSS styles in `src/styles/DesignSystem.cpp`**
```cpp
styleSheet.addRule(".pricing-card",
    "background: rgba(255, 255, 255, 0.05); "
    "border: 1px solid rgba(255, 255, 255, 0.1); "
    "border-radius: 20px; "
    "padding: 40px; "
    "text-align: center; "
    "transition: all 0.3s ease;"
);

styleSheet.addRule(".pricing-plan",
    "font-size: 24px; "
    "font-weight: 600; "
    "color: #ffffff; "
    "margin-bottom: 16px;"
);

styleSheet.addRule(".pricing-price",
    "font-size: 48px; "
    "font-weight: 700; "
    "color: #007aff; "
    "margin-bottom: 32px;"
);
```

**Step 4: Use anywhere**
```cpp
ComponentFactory::createPricingCard(container, 
    "Pro Plan", 
    "$29/month", 
    {"Unlimited projects", "24/7 support", "Advanced features"});
```

### 2. Add a New Page

**Example: Creating a Pricing Page**

**Step 1: Create `src/builders/PricingPageBuilder.h`**
```cpp
#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WVBoxLayout.h>

namespace CSPNet {
namespace Builders {

class PricingPageBuilder {
public:
    static Wt::WContainerWidget* build(Wt::WStackedWidget* contentStack);
    
private:
    static void buildPricingHeader(Wt::WVBoxLayout* layout);
    static void buildPricingCards(Wt::WVBoxLayout* layout);
    
    // Helper methods
    static Wt::WContainerWidget* createPageContainer(Wt::WStackedWidget* contentStack);
    static Wt::WVBoxLayout* setupPageLayout(Wt::WContainerWidget* page);
};

}}
```

**Step 2: Create `src/builders/PricingPageBuilder.cpp`**
```cpp
#include "PricingPageBuilder.h"
#include "../components/ComponentFactory.h"
#include <Wt/WText.h>

namespace CSPNet {
namespace Builders {

Wt::WContainerWidget* PricingPageBuilder::build(Wt::WStackedWidget* contentStack) {
    auto pricingPage = createPageContainer(contentStack);
    auto layout = setupPageLayout(pricingPage);
    
    buildPricingHeader(layout);
    buildPricingCards(layout);
    
    return pricingPage;
}

void PricingPageBuilder::buildPricingHeader(Wt::WVBoxLayout* layout) {
    auto header = layout->addWidget(std::make_unique<Wt::WContainerWidget>());
    header->setAttributeValue("style", "margin-bottom: 80px; text-align: center;");
    
    auto headerLayout = header->setLayout(std::make_unique<Wt::WVBoxLayout>());
    
    auto title = headerLayout->addWidget(std::make_unique<Wt::WText>("Choose Your Plan"));
    title->setAttributeValue("style",
        "font-size: clamp(48px, 8vw, 72px); "
        "font-weight: 700; "
        "color: #ffffff; "
        "margin-bottom: 24px;"
    );
    
    auto subtitle = headerLayout->addWidget(std::make_unique<Wt::WText>(
        "Select the perfect plan for your needs"));
    subtitle->setAttributeValue("style",
        "font-size: 24px; "
        "color: rgba(245, 245, 247, 0.7);"
    );
}

void PricingPageBuilder::buildPricingCards(Wt::WVBoxLayout* layout) {
    auto container = layout->addWidget(std::make_unique<Wt::WContainerWidget>());
    container->setAttributeValue("style",
        "display: grid; "
        "grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); "
        "gap: 40px; "
        "margin-top: 60px;"
    );
    
    // Starter plan
    ComponentFactory::createPricingCard(container,
        "Starter",
        "Free",
        {"1 project", "Basic support", "Community access"}
    );
    
    // Pro plan
    ComponentFactory::createPricingCard(container,
        "Pro",
        "$29/month",
        {"Unlimited projects", "Priority support", "Advanced features", "API access"}
    );
    
    // Enterprise plan
    ComponentFactory::createPricingCard(container,
        "Enterprise",
        "Custom",
        {"Everything in Pro", "Dedicated support", "Custom integrations", "SLA guarantee"}
    );
}

// Implement helper methods (copy from HomePageBuilder and modify)
Wt::WContainerWidget* PricingPageBuilder::createPageContainer(Wt::WStackedWidget* contentStack) {
    auto page = contentStack->addWidget(std::make_unique<Wt::WContainerWidget>());
    page->setAttributeValue("style", 
        "min-height: calc(100vh - 52px); "
        "padding: 80px 20px; "
        "overflow: visible; "
        "background: linear-gradient(135deg, #000000 0%, #1d1d1f 50%, #000000 100%);"
    );
    return page;
}

Wt::WVBoxLayout* PricingPageBuilder::setupPageLayout(Wt::WContainerWidget* page) {
    auto container = page->addWidget(std::make_unique<Wt::WContainerWidget>());
    container->setAttributeValue("style", 
        "max-width: 1200px; "
        "margin: 0 auto; "
        "text-align: center; "
        "overflow: visible;"
    );
    
    auto layout = container->setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    return layout;
}

}}
```

**Step 3: Add to application - Edit `src/app/Application.h`**
```cpp
// Add include
#include "../builders/PricingPageBuilder.h"

class Application : public Wt::WApplication {
private:
    // Add member variable
    Wt::WContainerWidget* pricingPage_;
};
```

**Step 4: Update `src/app/Application.cpp`**
```cpp
// Add to setupPages()
void Application::setupPages() {
    auto contentStack = mainLayout_->getContentStack();
    
    homePage_ = Builders::HomePageBuilder::build(contentStack);
    creditsPage_ = Builders::CreditsPageBuilder::build(contentStack);
    pricingPage_ = Builders::PricingPageBuilder::build(contentStack);  // Add this
    
    contentStack->setCurrentIndex(0);
}

// Add navigation method
void Application::navigateToPricing() {
    auto contentStack = mainLayout_->getContentStack();
    contentStack->setCurrentIndex(2);  // Adjust index as needed
    router_->setCurrentRoute("pricing");
}

// Add to setupRouting()
void Application::setupRouting() {
    router_->addRoute("home", [this]() { navigateToHome(); });
    router_->addRoute("credits", [this]() { navigateToCredits(); });
    router_->addRoute("pricing", [this]() { navigateToPricing(); });  // Add this
}
```

**Step 5: Add navigation link - Edit `src/views/components/Navigation.cpp`**
```cpp
// Add pricing link to navigation menu
auto pricingNavItem = menuLayout->addWidget(std::make_unique<Wt::WText>("Pricing"));
pricingNavItem->setStyleClass("nav-item");
pricingNavItem->clicked().connect([=]() {
    onNavigate_("pricing");
});
```

**Step 6: Update `CMakeLists.txt`**
```cmake
set(SOURCES
    # ... existing sources ...
    src/builders/PricingPageBuilder.cpp    # Add this line
)
```

**Step 7: Build and test**
```bash
cd build
make
./CSP_NET --docroot=../static --http-port=8080
```

### 3. Add Interactive Forms

**Example: Contact Form with Validation**

**Add to `src/components/ComponentFactory.cpp`**
```cpp
void ComponentFactory::createContactForm(Wt::WContainerWidget* parent) {
    auto form = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    form->setStyleClass("contact-form");
    
    auto layout = form->setLayout(std::make_unique<Wt::WVBoxLayout>());
    
    // Form title
    auto title = layout->addWidget(std::make_unique<Wt::WText>("Get In Touch"));
    title->setStyleClass("form-title");
    
    // Name field
    auto nameField = layout->addWidget(std::make_unique<Wt::WLineEdit>());
    nameField->setPlaceholderText("Your Name");
    nameField->setStyleClass("form-input");
    
    // Email field
    auto emailField = layout->addWidget(std::make_unique<Wt::WLineEdit>());
    emailField->setPlaceholderText("Your Email");
    emailField->setStyleClass("form-input");
    
    // Message field
    auto messageField = layout->addWidget(std::make_unique<Wt::WTextArea>());
    messageField->setPlaceholderText("Your Message");
    messageField->setStyleClass("form-textarea");
    
    // Submit button
    auto submitBtn = layout->addWidget(std::make_unique<Wt::WPushButton>("Send Message"));
    submitBtn->setStyleClass("form-submit-btn");
    
    // Validation and submission
    submitBtn->clicked().connect([=]() {
        std::string name = nameField->text().toUTF8();
        std::string email = emailField->text().toUTF8();
        std::string message = messageField->text().toUTF8();
        
        // Clear previous messages
        auto children = form->children();
        for (auto child : children) {
            if (child->styleClass().toUTF8().find("form-message") != std::string::npos) {
                form->removeWidget(child);
            }
        }
        
        // Validation
        if (name.empty() || email.empty() || message.empty()) {
            auto error = form->addWidget(std::make_unique<Wt::WText>("Please fill all fields"));
            error->setStyleClass("form-message form-error");
            return;
        }
        
        if (email.find("@") == std::string::npos) {
            auto error = form->addWidget(std::make_unique<Wt::WText>("Please enter a valid email"));
            error->setStyleClass("form-message form-error");
            return;
        }
        
        // Success (here you could save to database, send email, etc.)
        auto success = form->addWidget(std::make_unique<Wt::WText>("Message sent successfully!"));
        success->setStyleClass("form-message form-success");
        
        // Clear form
        nameField->setText("");
        emailField->setText("");
        messageField->setText("");
        
        std::cout << "Contact form submitted: " << name << " <" << email << ">" << std::endl;
    });
}
```

**Add form styles to `src/styles/DesignSystem.cpp`**
```cpp
// Form container
styleSheet.addRule(".contact-form",
    "background: rgba(255, 255, 255, 0.05); "
    "border: 1px solid rgba(255, 255, 255, 0.1); "
    "border-radius: 20px; "
    "padding: 40px; "
    "max-width: 600px; "
    "margin: 0 auto;"
);

// Form inputs
styleSheet.addRule(".form-input, .form-textarea",
    "width: 100%; "
    "padding: 16px; "
    "margin-bottom: 20px; "
    "background: rgba(255, 255, 255, 0.1); "
    "border: 1px solid rgba(255, 255, 255, 0.2); "
    "border-radius: 12px; "
    "color: #ffffff; "
    "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif; "
    "font-size: 16px;"
);

// Submit button
styleSheet.addRule(".form-submit-btn",
    "width: 100%; "
    "padding: 18px; "
    "background: #007aff; "
    "color: #ffffff; "
    "border: none; "
    "border-radius: 12px; "
    "font-size: 18px; "
    "font-weight: 600; "
    "cursor: pointer; "
    "transition: all 0.3s ease;"
);

// Messages
styleSheet.addRule(".form-error",
    "color: #ff3b30; "
    "background: rgba(255, 59, 48, 0.1); "
    "padding: 12px; "
    "border-radius: 8px; "
    "margin-top: 16px;"
);

styleSheet.addRule(".form-success",
    "color: #30d158; "
    "background: rgba(48, 209, 88, 0.1); "
    "padding: 12px; "
    "border-radius: 8px; "
    "margin-top: 16px;"
);
```

---

## 🎛️ Development Workflow

### Fast Development Script

**Create `dev.sh` in project root:**
```bash
#!/bin/bash
echo "🔨 Building CSP-NET..."

# Build
cd build
make

if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
    
    # Kill existing server
    pkill CSP_NET 2>/dev/null
    sleep 1
    
    # Start server
    echo "🚀 Starting server..."
    ./CSP_NET --docroot=../static --http-port=8080 &
    
    echo "📱 App running at: http://localhost:8080"
    echo "Press Ctrl+C to stop"
else
    echo "❌ Build failed!"
fi
```

```bash
# Make executable and use
chmod +x dev.sh
./dev.sh
```

### Debugging Tips

**Add debug output:**
```cpp
// In builders
std::cout << "=== Building Home Page ===" << std::endl;

// In components
std::cout << "Creating feature card: " << title << std::endl;

// Check widget creation
if (widget) {
    std::cout << "✅ Widget created successfully" << std::endl;
} else {
    std::cout << "❌ Widget creation failed!" << std::endl;
}
```

**CSS debugging:**
```cpp
// Temporarily add visible borders
widget->setAttributeValue("style", "border: 2px solid red;");
```

---

## 🚨 Common Issues & Solutions

### Build Fails
```bash
# Clean rebuild
rm -rf build
mkdir build && cd build
cmake .. && make
```

### Page Shows Blank
```cpp
// Check if widget is added to parent
auto widget = layout->addWidget(std::make_unique<Wt::WText>("Test"));

// Ensure container has height
container->setAttributeValue("style", "min-height: 100px;");
```

### Styles Not Applied
```cpp
// Check CSS class spelling
widget->setStyleClass("feature-card");  // Not "fetaure-card"

// Verify CSS rule exists in DesignSystem.cpp
styleSheet.addRule(".feature-card", "background: red;");  // Temporary test
```

### Port Already in Use
```bash
# Kill existing process
pkill CSP_NET

# Or use different port
./CSP_NET --docroot=../static --http-port=8081
```

---

## 📚 File Templates

### New Component Template
```cpp
// components/ComponentFactory.h
static void createYourComponent(Wt::WContainerWidget* parent,
                               const std::string& param1,
                               const std::string& param2);

// components/ComponentFactory.cpp
void ComponentFactory::createYourComponent(Wt::WContainerWidget* parent,
                                         const std::string& param1,
                                         const std::string& param2) {
    auto component = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    component->setStyleClass("your-component");
    
    auto layout = component->setLayout(std::make_unique<Wt::WVBoxLayout>());
    
    // Add your content here
    auto title = layout->addWidget(std::make_unique<Wt::WText>(param1));
    title->setStyleClass("component-title");
}
```

### New Page Builder Template
```cpp
// builders/YourPageBuilder.h
#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WVBoxLayout.h>

namespace CSPNet {
namespace Builders {

class YourPageBuilder {
public:
    static Wt::WContainerWidget* build(Wt::WStackedWidget* contentStack);
    
private:
    static void buildYourSection(Wt::WVBoxLayout* layout);
    static Wt::WContainerWidget* createPageContainer(Wt::WStackedWidget* contentStack);
    static Wt::WVBoxLayout* setupPageLayout(Wt::WContainerWidget* page);
};

}}

// builders/YourPageBuilder.cpp
#include "YourPageBuilder.h"
#include "../components/ComponentFactory.h"

namespace CSPNet {
namespace Builders {

Wt::WContainerWidget* YourPageBuilder::build(Wt::WStackedWidget* contentStack) {
    auto page = createPageContainer(contentStack);
    auto layout = setupPageLayout(page);
    
    buildYourSection(layout);
    
    return page;
}

// Copy createPageContainer and setupPageLayout from HomePageBuilder
// Implement buildYourSection with your content

}}
```

---

## 🎯 What's Next?

1. **Customize the design** - Change colors, fonts, and spacing
2. **Add your content** - Replace placeholder text with your content  
3. **Create new pages** - Follow the examples above
4. **Add components** - Build reusable UI elements
5. **Implement features** - Forms, authentication, database integration
6. **Deploy** - Set up production environment

### Ready to Build Something Amazing?

This starter template gives you everything you need to create professional, high-performance web applications with C++. The modular architecture scales with your project, and the Apple-inspired design ensures your app looks modern and professional.

**Happy coding!** 🚀

---

*For detailed architecture explanations, see [COMPLETE_GUIDE.md](./COMPLETE_GUIDE.md)*  
*For comprehensive documentation, see [ARCHITECTURE_GUIDE.md](./ARCHITECTURE_GUIDE.md)*