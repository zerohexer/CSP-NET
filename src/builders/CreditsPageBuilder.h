#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>

namespace CSPNet {
namespace Builders {

class CreditsPageBuilder {
public:
    // Main builder method
    static Wt::WContainerWidget* build(Wt::WStackedWidget* contentStack);
    
private:
    // Section builders
    static void buildHeroSection(Wt::WVBoxLayout* layout);
    static void buildCreditsGridSection(Wt::WVBoxLayout* layout);
    
    // Helper methods
    static Wt::WContainerWidget* createPageContainer(Wt::WStackedWidget* contentStack);
    static Wt::WVBoxLayout* setupPageLayout(Wt::WContainerWidget* page);
};

} // namespace Builders
} // namespace CSPNet