#ifndef BASE_TRANSITION_H__
#define BASE_TRANSITION_H__

#include <Arduino.h>
#include "ILI9342Wrapper.h"
#include "MathUtil.h"

class BaseTransition {
public:
	BaseTransition(){};

	virtual void init(ILI9342Wrapper& tft);
	virtual void restart(ILI9342Wrapper& tft, uint_fast16_t color );
	virtual void perFrame(ILI9342Wrapper& tft, FrameParams frameParams );
	virtual boolean isComplete();
};

void BaseTransition::init(ILI9342Wrapper& tft) {
	// Extend me
}

void BaseTransition::restart(ILI9342Wrapper& tft, uint_fast16_t color ) {
	// Extend me
}

void BaseTransition::perFrame(ILI9342Wrapper& tft, FrameParams frameParams ) {
	// Extend me
}

boolean BaseTransition::isComplete() {
	// Extend me
	return false;
}

#endif
