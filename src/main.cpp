#include <Geode/Geode.hpp>

using namespace geode::prelude;


#include <Geode/binding/GJGameLevel.hpp>

#include <Geode/modify/GJBaseGameLayer.hpp>
class $modify(GJBaseGameLayer) {
	TodoReturn shakeCamera(float p0, float p1, float p2) {
		return;
	}

	TodoReturn applyShake(cocos2d::CCPoint& p0) {
		return;
	}
};

// #include <Geode/modify/LevelInfoLayer.hpp>
// class $modify(LevelInfoLayer) {
// 	static LevelInfoLayer* create(GJGameLevel* level, bool p1) {
// 		LevelInfoLayer* layer = LevelInfoLayer::create(level, p1)	;
// 		level->m_disableShake = false;
// 		return layer;
// 	}

// 	// bool init(GJGameLevel* level, bool p1) {
// 	// 	if (!LevelInfoLayer::init(level, p1))
// 	// 		return false;
// 	//
// 	// 	this->m_level->m_disableShake = true;
// 	// 	return true;
// 	// }
// };