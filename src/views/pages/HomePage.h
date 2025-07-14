#pragma once
#include <Wt/WContainerWidget.h>
#include <memory>

namespace CSPNet {
namespace Views {
namespace Pages {

class HomePage : public Wt::WContainerWidget {
public:
    HomePage();
    
    void setupPage();
    
private:
    void createPageStructure();
    void createHeroSection(Wt::WContainerWidget* parent);
    void createFeaturesSection(Wt::WContainerWidget* parent);
    void createCTASection(Wt::WContainerWidget* parent);
    void createTechStackSection(Wt::WContainerWidget* parent);
    void createFeatureCard(Wt::WContainerWidget* parent, const std::string& title, const std::string& description);
    
    void setupPageStyles();
};

} // namespace Pages
} // namespace Views
} // namespace CSPNet