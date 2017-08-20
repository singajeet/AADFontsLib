// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _AADFontsLib_H_
#define _AADFontsLib_H_
#include "Arduino.h"
//add your includes for the project AADFontsLib here

#include "Arduino.h"

class AADFonts{

  public:
    enum FONT_TYPE {
      ONE_DIM_ROW_8BIT_LSB, // eg: FONT[] = {0x00, 0x01, ...};  Each byte represents an row and each bit in the byte is pixel(column) to be rendered from LSB (right) to MSB (left)
      ONE_DIM_ROW_8BIT_MSB,
      ONE_DIM_ROW_16BIT_LSB,
      ONE_DIM_ROW_16BIT_MSB,
      ONE_DIM_COL_8BIT_LSB, // eg: FONT[] = {0x00, 0x01, ...};  Each byte represents an column and each bit in the byte is pixel(row) to be rendered from LSB (top) to MSB (bottom)
      ONE_DIM_COL_8BIT_MSB,
      ONE_DIM_COL_16BIT_LSB,
      ONE_DIM_COL_16BIT_MSB,
      TWO_DIM_ROW_8BIT_LSB, // eg: FONT[][] = {{0x00, 0x01}, {0x0C, 0x00}, ...};  Each byte represents an row and each bit in the byte is pixel(column) to be rendered from LSB (right) to MSB (left)
      TWO_DIM_ROW_8BIT_MSB,
      TWO_DIM_ROW_16BIT_LSB,
      TWO_DIM_ROW_16BIT_MSB,
      TWO_DIM_COL_8BIT_LSB, // eg: FONT[][] = {{0x00, 0x01}, {0x0C, 0x00}, ...};  Each byte represents an column and each bit in the byte is pixel(row) to be rendered from LSB (top) to MSB (bottom)
      TWO_DIM_COL_8BIT_MSB,
      TWO_DIM_COL_16BIT_LSB,
      TWO_DIM_COL_16BIT_MSB
    };


    virtual String* getFontName(void);
    virtual int getFontType(void);
    virtual byte getFontHeight(void);
    virtual byte getFontWidth(void);
    virtual byte getRowByteForCharacter(unsigned char ch, byte rownum);
    virtual byte getColByteForCharacter(unsigned char ch, byte colnum);
    virtual const byte* getRawByteMap();

    virtual ~AADFonts(){};

    protected:
      FONT_TYPE _font_type;
      byte _font_height;
      byte _font_weight;
      String *_font_name;
};
//Do not add code below this line
#endif /* _AADFontsLib_H_ */
