#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WPushButton.h>
#include <string>

namespace CSPNet {
namespace Components {

class ComponentFactory {
public:
    // Feature Cards
    static void createFeatureCard(Wt::WContainerWidget* parent, 
                                const std::string& title, 
                                const std::string& description);
    
    // Credit Cards  
    static void createCreditCard(Wt::WContainerWidget* parent,
                               const std::string& name,
                               const std::string& role);
    
    // Interactive Buttons
    static Wt::WPushButton* createGetStartedButton(Wt::WContainerWidget* parent);
    
private:
    // Helper methods for button interactions
    static void setupGetStartedButtonHover(Wt::WPushButton* button);
};

} // namespace Components
} // namespace CSPNet