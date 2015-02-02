//
// Created by Shubin Fedor on 16/10/14.
//


#ifndef __CCAdmobBunch_H_
#define __CCAdmobBunch_H_

#include <string>
#include <map>
#include "json/document.h"

enum{
    aGADAdSizeBanner,
    
    /// Taller version of kGADAdSizeBanner. Typically 320x100.
    aGADAdSizeLargeBanner,
    
    /// Medium Rectangle size for the iPad (especially in a UISplitView's left pane). Typically 300x250.
    aGADAdSizeMediumRectangle,
    
    /// Full Banner size for the iPad (especially in a UIPopoverController or in
    /// UIModalPresentationFormSheet). Typically 468x60.
    aGADAdSizeFullBanner,
    
    /// Leaderboard size for the iPad. Typically 728x90.
    aGADAdSizeLeaderboard,
    
    /// Skyscraper size for the iPad. Mediation only. AdMob/Google does not offer this size. Typically
    /// 120x600.
    aGADAdSizeSkyscraper,
    
    /// An ad size that spans the full width of the application in portrait orientation. The height is
    /// typically 50 pixels on an iPhone/iPod UI, and 90 pixels tall on an iPad UI.
    aGADAdSizeSmartBannerPortrait,
    
    /// An ad size that spans the full width of the application in landscape orientation. The height is
    /// typically 32 pixels on an iPhone/iPod UI, and 90 pixels tall on an iPad UI.
    aGADAdSizeSmartBannerLandscape
};

enum
{
    kBannerGravityNone = -1,
    kBannerGravityTopLeft = 0,
    kBannerGravityCenterLeft,
    kBannerGravityBottomLeft,
    kBannerGravityTopCenter,
    kBannerGravityCenter,
    kBannerGravityBottomCenter,
    kBannerGravityTopRight,
    kBannerGravityCenterRight,
    kBannerGravityBottomRight
};

class CCAdmobBunch {
public:
    static CCAdmobBunch *getInstance();
    static bool initialize();
    
private:
    //std::string apiKey;

    CCAdmobBunch();

public:
    void createBanner(const char *adUnitID, long adSizeBanner);
    void createInterstitial(const char *adUnitID);
    
    void showBanner(double mX, double mY, double mWidth, double mHeight, int mGravity);
    void hideBanner();
    void showInterstitial();
private:

    static rapidjson::Value *mapToJson(std::map <std::string, std::string> &dict);
};


#endif //__CCAdmobBunch_H_
