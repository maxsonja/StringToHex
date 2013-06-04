//converts one hex to binary
byte charToInt(char input)
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
  else if(input.length()==3||input.length()>4) return Ox00;
  //
  result=charToInt(input.charAt(0));    //first hex
  result=result<<4;                     //bitshift 4 places to the left
  result+=charToInt(input.charAt(1));   //second hex
  return result;
}
