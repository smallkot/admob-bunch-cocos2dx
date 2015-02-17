Admob Bunch Cocos2dx
---

It's Cocos2d-x implementation of Admob for Native Gateway.

Native Gateway
---

Native Gateway allows you to create flexible native extension for cross-platform engines in easy way.

Getting Started
---

> Before start with Admob integration, please go through this document in order to integrate Native Gateway to your project: https://github.com/vedi/native-gateway-cocos2dx

> Draw your attention this repository includes all needed dependency including Admob libs as well.

### iOS

Drag&Drop repository folder to your project in XCode.


### Android

1. In `Android.mk` of your project include files from `cocos2dx` folder to your sources,
2. Add jar-files from `android` folder to `libs` of your project.
3. Add `google-play-services_lib` from `android` folder as dependency of your project.

### General Hints

1. Add repository as submodule of your project typing in your `Classes` folder:
```
git submodule add https://github.com/smallkot/admob-bunch-cocos2dx.git admob-bunch
```
2. Create static links for jars in `proj.android/libs` instead of copying:
```
ln -s ../../Classes/admob-bunch/android/admob-bunch.jar admob-bunch.jar
```
3. Create a static link for `google-play-services_lib` (I put it to `android_deps` folder at roo of my project):
```
ln -s ../Classes/admob-bunch/android/google-play-services_lib google-play-services_lib
```
4. Put new record to your `project.properties`. In my case it's:
```
android.library.reference.2=../android_deps/google-play-services_lib
```

### Configuration

Initialize AdmobBunch:

```cpp
#include "CCAdmobBunch.h"
...
CCAdmobBunch::initialize();
```

### Banner
Create banner
```cpp
#include "CCAdmobBunch.h"
...
CCAdmobBunch::createBanner("ca-app-pub-......", aGADAdSizeBanner);
```
The banner is created only once at the start of the game.

Show banner
```cpp
CCAdmobBunch::getInstance()->showBanner(0, 0, Director::getInstance()->getWinSize().width, Director::getInstance()->getWinSize().height, kBannerGravityBottomCenter);
```

Hide banner
```cpp
CCAdmobBunch::getInstance()->hideBanner();
```

### Interstitial
Create interstitial
```cpp
CCAdmobBunch::getInstance()->createInterstitial("ca-app-pub-65......");
```
Show interstitial
```cpp
CCAdmobBunch::getInstance()->showInterstitial();
```

### What's the next

Explore `CCAdmobBunch.h`. You'll find the simple things here, which reflect well to admob API.

Related projects
---

This repository includes prebuild native libraries, the sources are available at the following URLs:

* https://github.com/smallkot/admob-bunch-android
* https://github.com/smallkot/admob-bunch-ios
