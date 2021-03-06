/*
 * TouchSlider.h
 *
 *  Created on: 31.01.2012
 *      Author: Armin Joachimsmeyer
 *      Email:   armin.joachimsmeyer@gmx.de
 *      License: GPL v3 (http://www.gnu.org/licenses/gpl.html)
 *      Version: 1.0.0
 *
 */

#ifndef TOUCHSLIDER_H_
#define TOUCHSLIDER_H_

#include "TouchGui.h"

#include <MI0283QT2.h>

#define TOUCHSLIDER_DEFAULT_SLIDER_COLOR 		RGB( 180, 180, 180)
#define TOUCHSLIDER_DEFAULT_BAR_COLOR 			COLOR_GREEN
#define TOUCHSLIDER_DEFAULT_BAR_THRESHOLD_COLOR COLOR_RED
#define TOUCHSLIDER_DEFAULT_BAR_BACK_COLOR 		COLOR_WHITE
#define TOUCHSLIDER_DEFAULT_CAPTION_COLOR 		COLOR_RED
#define TOUCHSLIDER_DEFAULT_VALUE_COLOR 		COLOR_BLUE
#define TOUCHSLIDER_DEFAULT_CAPTION_VALUE_BACK_COLOR 	COLOR_WHITE
#define TOUCHSLIDER_SIZE_FACTOR 				2 // Factor for right and left border size
#define TOUCHSLIDER_OVERALL_SIZE_FACTOR 		6 // DEFAULT_SIZE * OVERALL_SIZE_FACTOR = width in pixel
#define TOUCHSLIDER_DEFAULT_SIZE 				4
#define TOUCHSLIDER_DEFAULT_TOUCH_BORDER 		4 // extension of touch region
#define TOUCHSLIDER_DEFAULT_SHOW_CAPTION		true
#define TOUCHSLIDER_DEFAULT_SHOW_VALUE			true
#define TOUCHSLIDER_DEFAULT_MAX_VALUE           160
#define TOUCHSLIDER_DEFAULT_THRESHOLD_VALUE     100

// Error codes
#define TOUCHSLIDER_ERROR_POS_X			-1
#define TOUCHSLIDER_ERROR_POS_Y			-2
#define TOUCHSLIDER_ERROR_SIZE_ZERO 	-3
#define TOUCHSLIDER_ERROR_SIZE 			-4
#define TOUCHSLIDER_ERROR_MAX_VALUE		-5
#define TOUCHSLIDER_ERROR_ACTUAL_VALUE 	-6
#define TOUCHSLIDER_ERROR_CAPTION_LENGTH -7
#define TOUCHSLIDER_ERROR_CAPTION_HEIGTH -8
#define TOUCHSLIDER_ERROR_VALUE_TOO_HIGH -9
#define TOUCHSLIDER_ERROR_X_RIGHT 		-16
#define TOUCHSLIDER_ERROR_Y_BOTTOM		-32
#define TOUCHSLIDER_ERROR_NOT_INITIALIZED -64

#ifdef TOUCHGUI_SAVE_SPACE
extern MI0283QT2 TFTDisplay;
#endif

class TouchSlider {
public:
	// Start of list of touchslider
	static TouchSlider * sListStart;

	/*
	 * Static functions
	 */
	~TouchSlider();
	TouchSlider();
#ifndef TOUCHGUI_SAVE_SPACE
	static void init(const MI0283QT2 aTheLCD);
#endif
	static void setDefaults(const int8_t aDefaultTouchBorder, const uint16_t aDefaultSliderColor,
			const uint16_t aDefaultBarColor, const uint16_t aDefaultBarThresholdColor,
			const uint16_t aDefaultBarBackgroundColor, const uint16_t aDefaultCaptionColor,
			const uint16_t aDefaultValueColor, const uint16_t aDefaultValueCaptionBackgroundColor);
	static void setDefaultSliderColor(const uint16_t aDefaultSliderColor);
	static void setDefaultBarColor(const uint16_t aDefaultBarColor);
	static bool checkAllSliders(const uint16_t aTouchPositionX, const uint16_t aTouchPositionY);
	static void deactivateAllSliders();
	static void activateAllSliders();
	/*
	 * Member functions
	 */
	int8_t initSimpleSlider(const uint16_t aPositionX, const uint16_t aPositionY, const uint8_t aSizeX,
			const char * aCaption, const bool aShowValue,
			uint8_t (*aOnChangeHandler)(TouchSlider * const, const uint8_t), const char * (*aValueHandler)(uint8_t));
	int8_t initSlider(const uint16_t aPositionX, const uint16_t aPositionY, const uint8_t aSizeX,
			const uint8_t aMaxValue, const bool aShowBorder, const char * aCaption, const uint8_t aInitalValue,
			const uint8_t aThresholdValue, const bool aShowValue, const int8_t aTouchBorder,
			uint8_t (*aOnChangeHandler)(TouchSlider * const, const uint8_t), const char * (*aValueHandler)(uint8_t));
	void initSliderColors(const uint16_t aSliderColor, const uint16_t aBarColor, const uint16_t aBarThresholdColor,
			const uint16_t aBarBackgroundColor, const uint16_t aCaptionColor, const uint16_t aValueColor,
			const uint16_t aValueCaptionBackgroundColor);
	int8_t drawSlider();
	bool checkSlider(const uint16_t aPositionX, const uint16_t aPositionY);
	void drawBar();
	void drawBorder();
	int8_t getActualValue() const;
	void setActualValue(int8_t actualValue);
	uint16_t getPositionXRight() const;
	uint16_t getPositionYBottom() const;
	void activate();
	void deactivate();
	uint16_t getBarColor() const;
	void setSliderColor(uint16_t sliderColor);
	void setBarColor(uint16_t barColor);
	void setBarThresholdColor(uint16_t barThresholdColor);

private:
#ifndef TOUCHGUI_SAVE_SPACE
	static MI0283QT2 TFTDisplay;
#endif
	/*
	 * Defaults
	 */
	static uint16_t sDefaultSliderColor;
	static uint16_t sDefaultBarColor;
	static uint16_t sDefaultBarThresholdColor;
	static uint16_t sDefaultBarBackgroundColor;
	static uint16_t sDefaultCaptionColor;
	static uint16_t sDefaultValueColor;
	static uint16_t sDefaultValueCaptionBackgroundColor;
	static int8_t sDefaultTouchBorder;
	/*
	 * The Value
	 */
	uint8_t mActualTouchValue;
	// This value can be different from mActualTouchValue and is provided by callback handler
	uint8_t mActualValue;
	/*
	 * The Slider
	 */
	uint16_t mPositionX;
	uint16_t mPositionXRight;
	uint16_t mPositionY;
	uint8_t mMaxValue; //aMaxValue serves also as height
	bool mShowBorder;
	uint8_t mThresholdValue;// Value for color change
	uint16_t mPositionYBottom;
	uint8_t mSize;
	const char* mCaption;
	bool mShowValue;
	uint8_t mTouchBorder;// extension of touch region
	// Colors
	uint16_t mSliderColor;
	uint16_t mBarColor;
	uint16_t mBarThresholdColor;
	uint16_t mBarBackgroundColor;
	uint16_t mCaptionColor;
	uint16_t mValueColor;
	uint16_t mValueCaptionBackgroundColor;
	// misc
	bool mIsActive;
	TouchSlider* mNextObject;
	uint8_t (*mOnChangeHandler)(TouchSlider*const , uint8_t);
	const char* (*mValueHandler)(uint8_t);
	int8_t checkParameterValues();
	int8_t printCaption();
	int8_t printValue();
};

#endif /* TOUCHSLIDER_H_ */
