/*
 * chart.h
 *
 * Draws charts for LCD screen
 * Charts have axes and a data area
 * Data can be printed as pixels or line or area
 * Labels and grid are optional
 *
 *  Created on:  14.02.2012
 *      Author:  Armin Joachimsmeyer
 *      Email:   armin.joachimsmeyer@gmx.de
 *      License: GPL v3 (http://www.gnu.org/licenses/gpl.html)
 *      Version: 1.0.0
 *
 */

#ifndef CHART_H_
#define CHART_H_

#define TOUCHGUI_SAVE_SPACE

#include <MI0283QT2.h>

#define CHART_DEFAULT_AXES_COLOR 		COLOR_BLACK
#define CHART_DEFAULT_GRID_COLOR 		RGB( 180, 180, 180)
#define CHART_DEFAULT_BACKGROUND_COLOR  COLOR_WHITE
#define CHART_DEFAULT_LABEL_COLOR  		COLOR_BLACK
#define CHART_MAX_AXES_SIZE 			10

// data drawing modes
#define CHART_MODE_PIXEL 				0
#define CHART_MODE_LINE 				1
#define CHART_MODE_AREA 				2

// Error codes
#define CHART_ERROR_POS_X 		-1
#define CHART_ERROR_POS_Y 		-2
#define CHART_ERROR_WIDTH 		-4
#define CHART_ERROR_HEIGHT		-8
#define CHART_ERROR_AXES_SIZE	-16
#define CHART_ERROR_GRID_X_RESOLUTION -32

#ifdef TOUCHGUI_SAVE_SPACE
/*
 * MI0283QT2 TFTDisplay - must provided by main program
 * external deklaration saves ROM (210 Bytes) and RAM ( 20 Bytes)
 * and avoids missing initialisation :-)
 */
extern MI0283QT2 TFTDisplay;
#endif

class Chart {
public:
    ~Chart();
    Chart();
#ifndef TOUCHGUI_SAVE_SPACE
    static void init(const MI0283QT2 aTheLCD);
#endif
    uint8_t initChart(const uint16_t aPositionX, const uint16_t aPositionY, const uint16_t aWidthX, const uint16_t aHeightY, const uint8_t aAxesSize, const bool aHasGrid, const uint8_t aGridXResolution, const uint8_t aGridYResolution);
    void initXLabelInt(const int  aXLabelStartValue, const int  aXLabelIncrementValue, const uint8_t aXMinStringWidth);
    int stepXLabelInt(const bool aDoIncrement);
    void initXLabelFloat(const float aXLabelStartValue, const float aXLabelIncrementValue, uint8_t aXMinStringWidthIncDecimalPoint, uint8_t aXNumVarsAfterDecimal);
    bool stepXLabelFloat(const bool aDoIncrement);
    void initYLabelInt(const int  aYLabelStartValue, const int  aYLabelIncrementValue, const uint8_t aMaxYLabelCharacters);
    int stepYLabelInt(const bool aDoIncrement);
    void initYLabelFloat(const float aYLabelStartValue, const float aYLabelIncrementValue, uint8_t aYMinStringWidthIncDecimalPoint, uint8_t aYNumVarsAfterDecimal);
    float stepYLabelFloat(const bool aDoIncrement);
    void initChartColors(const uint16_t aAxesColor, const uint16_t aGridColor, const uint16_t aLabelColor, const uint16_t aBackgroundColor);
    uint8_t drawChart(void);
    bool drawChartData(uint8_t *aDataPointer, const uint16_t aDataLength, const uint16_t aDataColor, const uint8_t aMode);
    void drawGrid(void);
    uint8_t drawXAxis(bool aClearLabelsBefore);
    uint8_t drawYAxis(bool aClearLabelsBefore);
    uint8_t drawAxes(bool aClearLabelsBefore);
    void clear(void);
    uint16_t getHeightY() const;
    uint16_t getPositionX() const;
    uint16_t getPositionY() const;
    uint16_t getWidthX() const;
    void setHeightY(const uint16_t heightY);
    void setPositionX(const uint16_t positionX);
    void setPositionY(const uint16_t positionY);
    void setWidthX(const uint16_t widthX);
    void setXLabelStartValue(int xLabelStartValue);
    void setXLabelStartValueFloat(float xLabelStartValueFloat);
    void setYLabelStartValue(int yLabelStartValue);
    void setYLabelStartValueFloat(float yLabelStartValueFloat);
    void setXLabelIncrementValue(int xLabelIncrementValue);
    void setXLabelIncrementValueFloat(float xLabelIncrementValueFloat);
    void setYLabelIncrementValue(int yLabelIncrementValue);
    void setYLabelIncrementValueFloat(float yLabelIncrementValueFloat);

private:
#ifndef TOUCHGUI_SAVE_SPACE
    static MI0283QT2 sTheLcd;
#endif
    uint16_t mPositionX;
    uint16_t mPositionY;
    uint16_t mWidthX;
    uint16_t mHeightY;
    uint16_t mChartBackgroundColor;
    uint8_t mAxesSize;
    uint16_t mAxesColor;
    bool mHasGrid;
    uint8_t mGridXResolution;
    uint8_t mGridYResolution;
    uint16_t mGridColor;
    int mXLabelStartValue;
    int mXLabelIncrementValue;
    int mYLabelStartValue;
    int mYLabelIncrementValue;
    float mXLabelStartValueFloat;
    float mXLabelIncrementValueFloat;
    uint8_t mXNumVarsAfterDecimal;
    float mYLabelStartValueFloat;
    float mYLabelIncrementValueFloat;
    uint8_t mYNumVarsAfterDecimal;
	uint8_t mXMinStringWidth;
	uint8_t mYMinStringWidth;
	uint16_t mLabelColor;

	uint8_t checkParameterValues();
};

#endif /* CHART_H_ */
