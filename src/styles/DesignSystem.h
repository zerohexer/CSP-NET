#pragma once
#include <Wt/WApplication.h>

namespace CSPNet {
namespace Styles {

class DesignSystem {
public:
    static void setupGlobalStyles();
    static void setupComponentStyles();
    static void setupLayoutStyles();
    static void setupResponsiveStyles();
    
private:
    static Wt::WCssStyleSheet& getStyleSheet();
};

} // namespace Styles
} // namespace CSPNet