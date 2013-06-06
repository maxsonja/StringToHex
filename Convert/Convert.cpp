#include "Convert.h"
#include "Arduino.h"

//converts one char to real value
byte value(char input)
{
  if(input >47 && input<58) return input-48;
  else if(input > 64 && input<71) return input-65+10;
  else return 0;
}

byte toHex(String input)
{
  input.toUpperCase();
  byte result = 0x00;
  //input checking
  if(input.length()==4) input = input.substring(2);
  else if(input.length()==3||input.length()>4) return 0x00;
  //
  result=value(input.charAt(0)); //first hex
  result=result<<4; //bitshift 4 places to the left
  result+=value(input.charAt(1)); //second hex
  return result;
}
	

float toFloat(String var)
{
  long dot = var.indexOf(".");
  boolean negative = false;
  float fpoint = 1;
  float result;
  
  if (dot == -1)
  {
    dot = var.length();
  }
  
  //if number negative
  if (var.charAt(0) == 45)
  {
    negative = true;
    var = var.substring(1);
    dot--;
  }
  //convert  value
  result = toInt(var.substring(0,dot-1));
  for(int i = dot+1; i< var.length(); i++)
  {
    fpoint *= 0.1;
    result = result + (value(var.charAt(i))*fpoint);
  }
  
  //fix negative number
  if(negative)
  {
    result *=-1;
  }
  
  return result;
  
}

long toInt(String input)
{
  boolean negative = false;
  long result = 0;
  //if number negative
  if(input.charAt(0) == 45)
  {
    input = input.substring(1);
    negative = true;
  }
  
  for (int i=0; i<input.length(); i++)
  {
    result = (result*10) + value(input.charAt(i));
  }
  if(negative) result*=-1;
  return result;
}
