#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/binding/GJGameLevel.hpp>
#include <Geode/binding/CCMenuItemToggler.hpp>
#include <Geode/binding/GameLevelOptionsLayer.hpp>

const int DISABLE_SHAKE_BUTTON_INDEX = 2;
const cocos2d::ccColor3B SHADED_COLOR = { 166, 166, 166 };
bool enabled = Mod::get()->getSettingValue<bool>("enabled");

#include <Geode/modify/GJBaseGameLayer.hpp>
class $modify(GJBaseGameLayer) {
	void shakeCamera(float p0, float p1, float p2) {
		if (!enabled) GJBaseGameLayer::shakeCamera(p0, p1, p2);
	}

	void applyShake(cocos2d::CCPoint& p0) {
		if (!enabled) GJBaseGameLayer::applyShake(p0);
	}
};

#include <Geode/modify/GameLevelOptionsLayer.hpp>
class $modify(NSGameLevelOptionsLayer, GameLevelOptionsLayer) {
	bool init(GJGameLevel* level) {
		if (!GameLevelOptionsLayer::init(level))
			return false;
		if (!enabled)
			return true;
		auto disableShakeButton = reinterpret_cast<CCMenuItemToggler*>(this->m_buttonMenu->getChildren()->objectAtIndex(1));
		disableShakeButton->m_notClickable = true;
		auto color1 = typeinfo_cast<CCRGBAProtocol*>(disableShakeButton->m_onButton);
		auto color2 = typeinfo_cast<CCRGBAProtocol*>(disableShakeButton->m_offButton);
		color1->setColor(SHADED_COLOR);
		color2->setColor(SHADED_COLOR);
		// auto onSprite = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
		// onSprite->setScale(0.8f);
		// auto offSprite = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
		// offSprite->setScale(0.8f);
		// auto disableShakeButton = CCMenuItemToggler::create(
		// 	offSprite,
		// 	onSprite,
		// 	this,
		// 	menu_selector(NSGameLevelOptionsLayer::onToggle)
		// );
		// this->m_buttonMenu->getChildren()->removeObjectAtIndex(1);
		// this->m_buttonMenu->addChild(disableShakeButton);
		// disableShakeButton->setAnchorPoint({0.5f, 0.5f});
		// disableShakeButton->setPosition({32, 80});
		// disableShakeButton->setZOrder(5);
		// disableShakeButton->m_toggled = true;
		// disableShakeButton->m_notClickable = true;
		return true;
	}

	// void onToggle(cocos2d::CCObject* _) {
	// 	enabled = !enabled;
	// }
};



/*
the method that doesnt work cuz of robs wonderfulness
m_disableShake doesn't do anything

#include <Geode/modify/LevelInfoLayer.hpp>
class $modify(LevelInfoLayer) {
	static LevelInfoLayer* create(GJGameLevel* level, bool p1) {
		GameLevelOptionsLayer* options = GameLevelOptionsLayer::create(level);

		LevelInfoLayer* layer = LevelInfoLayer::create(level, p1);
		return layer;
	}

	void downloadLevel() {
		LevelInfoLayer::downloadLevel();
		this->m_level->m_disableShake = true;
	}

	void onPlay(cocos2d::CCObject* sender) {
		this->m_level->m_disableShake = true;
		LevelInfoLayer::onPlay(sender);
	}

	bool init(GJGameLevel* level, bool p1) {
		if (!LevelInfoLayer::init(level, p1))
			return false;

		this->m_level->m_disableShake = true;
		return true;
	}
};
*/