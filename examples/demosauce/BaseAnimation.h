#ifndef BASE_ANIMATION_H__
#define BASE_ANIMATION_H__

#include "ILI9342Wrapper.h"
#include <Arduino.h>
#include "MathUtil.h"
#include "FrameParams.h"

class BaseAnimation {
public:
	BaseAnimation(){};

	virtual void init(ILI9342Wrapper & tft );
	virtual uint_fast16_t bgColor( void );
	virtual void reset(ILI9342Wrapper& tft);
	virtual String title();

	virtual boolean willForceTransition( void );
	virtual boolean forceTransitionNow( void );

	virtual void perFrame(ILI9342Wrapper& tft, FrameParams frameParams );
};

void BaseAnimation::init(ILI9342Wrapper& tft) {
	// Extend me
}

uint_fast16_t BaseAnimation::bgColor( void ) {
	// Extend me
	return 0xf81f;	// Everyone loves magenta
}

void BaseAnimation::reset(ILI9342Wrapper& tft) {
	// Extend me
}

String BaseAnimation::title() {
	return "BaseAnimation";
}

boolean BaseAnimation::willForceTransition( void ) {
	return false;	// Default: SuperTFT will transition animations automatically
}

boolean BaseAnimation::forceTransitionNow( void ) {
	// Extend me
	return false;	// Default: SuperTFT will transition animations automatically
}

void BaseAnimation::perFrame(ILI9342Wrapper& tft, FrameParams frameParams ) {
	// Extend me
}

#endif
