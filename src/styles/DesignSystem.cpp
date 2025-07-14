#include "DesignSystem.h"

namespace CSPNet {
namespace Styles {

Wt::WCssStyleSheet& DesignSystem::getStyleSheet() {
    return Wt::WApplication::instance()->styleSheet();
}

void DesignSystem::setupGlobalStyles() {
    auto& styleSheet = getStyleSheet();
    
    // Base reset and typography
    styleSheet.addRule("*", 
        "margin: 0; "
        "padding: 0; "
        "box-sizing: border-box;"
    );
    
    styleSheet.addRule("html, body", 
        "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif; "
        "-webkit-font-smoothing: antialiased; "
        "-moz-osx-font-smoothing: grayscale; "
        "background: #000000; "
        "color: #f5f5f7; "
        "line-height: 1.47; "
        "overflow-x: hidden; "
        "min-height: 100vh;"
    );
    
    // App container
    styleSheet.addRule(".app-container", 
        "min-height: 100vh; "
        "background: linear-gradient(135deg, #000000 0%, #1d1d1f 50%, #000000 100%);"
    );
}

void DesignSystem::setupComponentStyles() {
    auto& styleSheet = getStyleSheet();
    
    // Content stack
    styleSheet.addRule(".content-stack", 
        "flex: 1;"
    );
    
    // Page styles
    styleSheet.addRule(".page", 
        "min-height: calc(100vh - 52px); "
        "padding: 80px 20px; "
        "overflow: visible;"
    );
    
    styleSheet.addRule(".page-container", 
        "max-width: 1200px; "
        "margin: 0 auto; "
        "text-align: center; "
        "overflow: visible; "
        "position: relative;"
    );
    
    // Hero section
    styleSheet.addRule(".hero", 
        "margin-bottom: 80px;"
    );
    
    styleSheet.addRule(".hero-title", 
        "font-size: clamp(48px, 8vw, 96px); "
        "font-weight: 700; "
        "letter-spacing: -0.055em; "
        "margin-bottom: 24px; "
        "background: linear-gradient(135deg, #ffffff 0%, #f5f5f7 25%, #d1d1d6 75%, #a1a1a6 100%); "
        "-webkit-background-clip: text; "
        "-webkit-text-fill-color: transparent; "
        "background-clip: text; "
        "line-height: 1.05;"
    );
    
    styleSheet.addRule(".hero-subtitle", 
        "font-size: clamp(21px, 3vw, 28px); "
        "font-weight: 400; "
        "color: rgba(245, 245, 247, 0.7); "
        "margin-bottom: 48px; "
        "letter-spacing: -0.022em; "
        "line-height: 1.14;"
    );
    
    // Feature cards
    styleSheet.addRule(".feature-card", 
        "background: rgba(255, 255, 255, 0.05); "
        "backdrop-filter: blur(20px); "
        "-webkit-backdrop-filter: blur(20px); "
        "border: 1px solid rgba(255, 255, 255, 0.1); "
        "border-radius: 20px; "
        "padding: 40px 32px; "
        "transition: all 0.4s ease; "
        "position: relative; "
        "overflow: hidden; "
        "z-index: 1;"
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
        "box-shadow: 0 20px 40px rgba(0, 0, 0, 0.3); "
        "z-index: 10;"
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
    
    // Credit cards
    styleSheet.addRule(".credit-card", 
        "background: rgba(255, 255, 255, 0.05); "
        "backdrop-filter: blur(20px); "
        "-webkit-backdrop-filter: blur(20px); "
        "border: 1px solid rgba(255, 255, 255, 0.1); "
        "border-radius: 24px; "
        "padding: 60px 40px; "
        "transition: all 0.4s ease; "
        "text-align: center; "
        "position: relative; "
        "z-index: 1;"
    );
    
    styleSheet.addRule(".credit-card:hover", 
        "transform: translateY(-12px); "
        "background: rgba(255, 255, 255, 0.08); "
        "border-color: rgba(255, 255, 255, 0.2); "
        "box-shadow: 0 25px 50px rgba(0, 0, 0, 0.4); "
        "z-index: 10;"
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

void DesignSystem::setupLayoutStyles() {
    auto& styleSheet = getStyleSheet();
    
    // Feature grid
    styleSheet.addRule(".features", 
        "display: grid; "
        "grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); "
        "gap: 24px; "
        "margin: 60px 0; "
        "padding: 20px 0 40px 0; "
        "overflow: visible; "
        "position: relative;"
    );
    
    // Credits grid
    styleSheet.addRule(".credits-grid", 
        "display: grid; "
        "grid-template-columns: repeat(auto-fit, minmax(350px, 1fr)); "
        "gap: 40px; "
        "margin-top: 60px; "
        "padding: 30px 0 50px 0; "
        "overflow: visible; "
        "position: relative;"
    );
    
    // Tech stack
    styleSheet.addRule(".tech-stack", 
        "margin-top: 80px; "
        "padding-top: 60px; "
        "border-top: 1px solid rgba(255, 255, 255, 0.1);"
    );
    
    styleSheet.addRule(".tech-label", 
        "font-size: 15px; "
        "color: #a1a1a6; "
        "margin-bottom: 20px; "
        "text-transform: uppercase; "
        "letter-spacing: 2px; "
        "font-weight: 500;"
    );
    
    styleSheet.addRule(".tech-items", 
        "font-size: 18px; "
        "color: #d1d1d6; "
        "font-weight: 400; "
        "letter-spacing: -0.022em;"
    );
}

void DesignSystem::setupResponsiveStyles() {
    auto& styleSheet = getStyleSheet();
    
    styleSheet.addRule("@media (max-width: 768px)", 
        ".nav-container { padding: 0 16px; } "
        ".nav-menu { gap: 20px; } "
        ".page { padding: 40px 16px; } "
        ".features { grid-template-columns: 1fr; } "
        ".credits-grid { grid-template-columns: 1fr; } "
        ".feature-card, .credit-card { padding: 32px 24px; }"
    );
}

} // namespace Styles
} // namespace CSPNet