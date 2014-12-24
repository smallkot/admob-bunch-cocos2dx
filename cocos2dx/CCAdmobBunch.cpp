//
// Created by Konstantin Poznyak on 20/12/14.
//

#include "CCAdmobBunch.h"
#include "CCPlatformDefine.h"
#include "CCBunchManager.h"
#include "CCNativeGateway.h"

#define BUNCH "AdmobBunch"

static CCAdmobBunch *INSTANCE = nullptr;

CCAdmobBunch *CCAdmobBunch::getInstance() {
    CC_ASSERT(INSTANCE);
    return INSTANCE;
}

CCAdmobBunch::CCAdmobBunch() {

}

bool CCAdmobBunch::initialize() {
    if (INSTANCE == nullptr) {
        INSTANCE = new CCAdmobBunch();
        CCBunchManager::registerBunch(BUNCH);
        return true;
    } else {
        return false;
    }
}

void CCAdmobBunch::createBanner(const char *adUnitID, long adSizeBanner, double mX , double mY){
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("adUnitID", adUnitID, dict.GetAllocator());
    dict.AddMember("adSizeBanner", (double)adSizeBanner, dict.GetAllocator());
    dict.AddMember("mX", mX, dict.GetAllocator());
    dict.AddMember("mY", mY, dict.GetAllocator());
    CCNativeGateway::dispatch(
            BUNCH,
            "createBanner",
            dict
    );
}

void CCAdmobBunch::showBanner(){
    rapidjson::Document dict = rapidjson::Document();
    CCNativeGateway::dispatch(
                              BUNCH,
                              "showBanner",
                              dict
                              );
}

void CCAdmobBunch::createInterstitial(const char *adUnitID){
    rapidjson::Document dict = rapidjson::Document();
    dict.SetObject();
    dict.AddMember("adUnitID", adUnitID, dict.GetAllocator());
    CCNativeGateway::dispatch(
                              BUNCH,
                              "createInterstitial",
                              dict
                              );
}

void CCAdmobBunch::showInterstitial(){
    rapidjson::Document dict = rapidjson::Document();
    CCNativeGateway::dispatch(
                              BUNCH,
                              "showInterstitial",
                              dict
                              );
}

rapidjson::Value *CCAdmobBunch::mapToJson(std::map <std::string, std::string> &dict) {
    rapidjson::Value *pRet = new rapidjson::Value();
    rapidjson::Value &ret = *pRet;

    for (std::map<std::string, std::string>::iterator it=dict.begin(); it!=dict.end(); ++it) {
        ret[it->first.c_str()] = it->second.c_str();
    }

    return pRet;
}
