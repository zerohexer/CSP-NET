#pragma once
#include <Wt/WContainerWidget.h>
#include <memory>

namespace CSPNet {
namespace Views {
namespace Pages {

class CreditsPage : public Wt::WContainerWidget {
public:
    CreditsPage();
    
    void setupPage();
    
private:
    void createPageStructure();
    void createHeroSection(Wt::WContainerWidget* parent);
    void createCreditsSection(Wt::WContainerWidget* parent);
    void createCreditCard(Wt::WContainerWidget* parent, const std::string& name, const std::string& role);
    
    void setupPageStyles();
};

} // namespace Pages
} // namespace Views
} // namespace CSPNet