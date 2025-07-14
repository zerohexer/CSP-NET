#include "ComponentFactory.h"
#include <memory>

namespace CSPNet {
namespace Components {

void ComponentFactory::createFeatureCard(Wt::WContainerWidget* parent, 
                                        const std::string& title, 
                                        const std::string& description) {
    auto card = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    card->setStyleClass("feature-card");
    
    auto layout = card->setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    
    auto titleWidget = layout->addWidget(std::make_unique<Wt::WText>(title));
    titleWidget->setStyleClass("feature-title");
    
    auto descWidget = layout->addWidget(std::make_unique<Wt::WText>(description));
    descWidget->setStyleClass("feature-desc");
}

void ComponentFactory::createCreditCard(Wt::WContainerWidget* parent,
                                       const std::string& name,
                                       const std::string& role) {
    auto card = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    card->setStyleClass("credit-card");
    
    auto layout = card->setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    
    auto nameWidget = layout->addWidget(std::make_unique<Wt::WText>(name));
    nameWidget->setStyleClass("credit-name");
    
    auto roleWidget = layout->addWidget(std::make_unique<Wt::WText>(role));
    roleWidget->setStyleClass("credit-role");
}

Wt::WPushButton* ComponentFactory::createGetStartedButton(Wt::WContainerWidget* parent) {
    auto buttonContainer = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    buttonContainer->setAttributeValue("style", 
        "margin-top: 60px; "
        "margin-bottom: 40px; "
        "text-align: center; "
        "padding: 40px; "
        "overflow: visible;"
    );
    
    auto button = buttonContainer->addWidget(std::make_unique<Wt::WPushButton>("Get Started"));
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
    
    setupGetStartedButtonHover(button);
    return button;
}

void ComponentFactory::setupGetStartedButtonHover(Wt::WPushButton* button) {
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
    
    button->mouseWentOut().connect([button]() {
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
            "text-shadow: 0 1px 2px rgba(0, 0, 0, 0.1); "
            "transform: translateY(0) scale(1);"
        );
    });
}

} // namespace Components
} // namespace CSPNet