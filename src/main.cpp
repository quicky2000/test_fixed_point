/*
    This file is part of test_fixed_point
    Copyright (C) 2011  Julien Thevenon ( julien_thevenon at yahoo.fr )

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "fixed_point.h"

int main(void)
{
  const uint16_t l_fixed_min_x = 0xFE00; // -2
  const uint16_t l_fixed_min_y = 0xFF10; // -0.9355
  uint16_t x = 0x80;//l_fixed_min_x + 320;
  uint16_t y = 0x80;//l_fixed_min_y + 240;
  uint16_t l_nb_max_iter = 16;
  uint16_t l_module_limit = 0x400;
  display16("x",x,8);
  display16("y",y,8);

  uint16_t x_n = x;
  uint16_t y_n = y;




  uint16_t x_n_plus_1 = 0;
  uint16_t y_n_plus_1 = 0;
  uint16_t l_module = 0 ;
  for(uint16_t l_index = 0 ; l_index < l_nb_max_iter && l_module < l_module_limit ; ++l_index)
    {
      cout << "------------------------------" << endl ;
      cout << "Iter = " << l_index << endl ;
      display16("x_n",x_n,8);
      display16("y_n",y_n,8);
      uint16_t x_square = fixed_mult16(x_n,x_n,8);
      display16("x_square",x_square,8);
      uint16_t y_square = fixed_mult16(y_n,y_n,8);
      display16("y_square",y_square,8);
      l_module = x_square + y_square;
      display16("Module",l_module,8);
      uint16_t x_y = fixed_mult16(x_n,y_n,8);
      display16("x_y",x_y,8);
      
      x_n_plus_1 = x_square - y_square + x;
      y_n_plus_1 = fixed_mult16(0x200,x_y,8) + y;
      display16("x_n+1",x_n_plus_1,8);
      display16("y_n+1",y_n_plus_1,8);
      x_n = x_n_plus_1;
      y_n = y_n_plus_1;
    }    
}
