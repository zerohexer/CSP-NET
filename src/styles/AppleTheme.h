#pragma once
#include <Wt/WApplication.h>

namespace CSPNet {
namespace Styles {

class AppleTheme {
public:
    static void setupAppleDesignSystem();
    static void setupTypography();
    static void setupColors();
    static void setupEffects();
    static void setupAnimations();
    
private:
    static Wt::WCssStyleSheet& getStyleSheet();
};

} // namespace Styles
} // namespace CSPNet