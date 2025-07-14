#include "AppleTheme.h"

namespace CSPNet {
namespace Styles {

Wt::WCssStyleSheet& AppleTheme::getStyleSheet() {
    return Wt::WApplication::instance()->styleSheet();
}

void AppleTheme::setupAppleDesignSystem() {
    setupTypography();
    setupColors();
    setupEffects();
    setupAnimations();
}

void AppleTheme::setupTypography() {
    auto& styleSheet = getStyleSheet();
    
    // Apple Navigation Bar
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
    
    styleSheet.addRule(".nav-container", 
        "max-width: 1200px; "
        "margin: 0 auto; "
        "height: 52px; "
        "display: flex; "
        "align-items: center; "
        "justify-content: space-between; "
        "padding: 0 20px;"
    );
    
    styleSheet.addRule(".nav-logo", 
        "font-size: 21px; "
        "font-weight: 600; "
        "color: #f5f5f7; "
        "letter-spacing: -0.022em;"
    );
    
    styleSheet.addRule(".nav-menu", 
        "display: flex; "
        "gap: 32px; "
        "align-items: center;"
    );
}

void AppleTheme::setupColors() {
    auto& styleSheet = getStyleSheet();
    
    styleSheet.addRule(".nav-item", 
        "color: #f5f5f7; "
        "font-size: 17px; "
        "font-weight: 400; "
        "text-decoration: none; "
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
    
    styleSheet.addRule(".nav-item.active", 
        "opacity: 1; "
        "background: rgba(255, 255, 255, 0.15); "
        "color: #ffffff;"
    );
}

void AppleTheme::setupEffects() {
    auto& styleSheet = getStyleSheet();
    
    // Feature card glassmorphism
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
    
    styleSheet.addRule(".feature-title", 
        "font-size: 22px; "
        "font-weight: 600; "
        "color: #f5f5f7; "
        "margin-bottom: 16px; "
        "letter-spacing: -0.022em;"
    );
    
    styleSheet.addRule(".feature-desc", 
        "font-size: 17px; "
        "color: rgba(245, 245, 247, 0.7); "
        "line-height: 1.47; "
        "letter-spacing: -0.022em;"
    );
    
    // Credit card effects
    styleSheet.addRule(".credit-card", 
        "background: rgba(255, 255, 255, 0.05); "
        "backdrop-filter: blur(20px); "
        "-webkit-backdrop-filter: blur(20px); "
        "border: 1px solid rgba(255, 255, 255, 0.1); "
        "border-radius: 24px; "
        "padding: 60px 40px; "
        "transition: all 0.4s ease; "
        "text-align: center;"
    );
    
    styleSheet.addRule(".credit-name", 
        "font-size: 32px; "
        "font-weight: 600; "
        "color: #f5f5f7; "
        "margin-bottom: 16px; "
        "letter-spacing: -0.022em;"
    );
    
    styleSheet.addRule(".credit-role", 
        "font-size: 18px; "
        "color: rgba(245, 245, 247, 0.7); "
        "font-weight: 400; "
        "letter-spacing: -0.022em;"
    );
}

void AppleTheme::setupAnimations() {
    auto& styleSheet = getStyleSheet();
    
    styleSheet.addRule(".feature-card:hover", 
        "transform: translateY(-8px); "
        "background: rgba(255, 255, 255, 0.08); "
        "border-color: rgba(255, 255, 255, 0.2); "
        "box-shadow: 0 20px 40px rgba(0, 0, 0, 0.3);"
    );
    
    styleSheet.addRule(".credit-card:hover", 
        "transform: translateY(-12px); "
        "background: rgba(255, 255, 255, 0.08); "
        "border-color: rgba(255, 255, 255, 0.2); "
        "box-shadow: 0 25px 50px rgba(0, 0, 0, 0.4);"
    );
}

} // namespace Styles
} // namespace CSPNet