/*************************************************************************************
 * 8 x 15 pixel font to be used in graphical LCDs
 * Author:
 * Date:
 * Ref:
 ************************************************************************************/

#include "AADFontsLibDefault8x15.h"

AADFontsLibDefault8x15::AADFontsLibDefault8x15(){

  this->_font_type = TWO_DIM_ROW_8BIT_LSB;
  this->_font_height = 15;
  this->_font_weight = 8;
  this->_font_name = new String("Nokia1616EmbeddedFont");
}

String* AADFontsLibDefault8x15::getFontName(void){
  return this->_font_name;
}

int AADFontsLibDefault8x15::getFontType(void){
  return this->_font_type;
}

byte AADFontsLibDefault8x15::getFontHeight(void){
  return this->_font_height;
}

byte AADFontsLibDefault8x15::getFontWidth(void){
  return this->_font_weight;
}

byte AADFontsLibDefault8x15::getRowByteForCharacter(unsigned char ch, byte rownum){
  if(this->_font_type >= TWO_DIM_ROW_8BIT_LSB && this->_font_type <= TWO_DIM_ROW_16BIT_MSB)
    return pgm_read_byte(&(FONT8x15[ch-32][rownum]));
  else if(this->_font_type >= ONE_DIM_ROW_8BIT_LSB && this->_font_type <= ONE_DIM_ROW_16BIT_MSB)
    return pgm_read_byte(&(FONT8x15[((ch-32)*this->_font_height)+rownum]));
  else
    return -1;
}

byte AADFontsLibDefault8x15::getColByteForCharacter(unsigned char ch, byte colnum){
  if(this->_font_type >= TWO_DIM_COL_8BIT_LSB && this->_font_type <= TWO_DIM_COL_16BIT_MSB)
    return pgm_read_byte(&(FONT8x15[ch-32][colnum]));
  else if(this->_font_type >= ONE_DIM_COL_8BIT_LSB && this->_font_type <= ONE_DIM_COL_16BIT_MSB)
    return pgm_read_byte(&(FONT8x15[((ch-32)*this->_font_height)+colnum]));
  else
    return -1;
}

const byte* AADFontsLibDefault8x15::getRawByteMap(){
    if(this->_font_type >= TWO_DIM_ROW_8BIT_LSB && this->_font_type <= TWO_DIM_COL_16BIT_MSB)
      return &(FONT8x15[0][0]);
    else if(this->_font_type >= ONE_DIM_ROW_8BIT_LSB && this->_font_type <= ONE_DIM_COL_16BIT_MSB)
      return (FONT8x15[0]);
    else
      return NULL;
}
