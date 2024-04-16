#include <stdio.h>
#include <string.h>
char * ft_des(char *input)
{
  char cVar1;
  char *intput_dup;
  unsigned int uVar3;
  char *pcVar4;
  char bVar5;
  unsigned int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  bVar5 = 0;
  intput_dup = strdup(input);
  local_1c = 0;
  local_20 = 0;
  do {
    uVar3 = 0xffffffff;
    pcVar4 = intput_dup;
    do
    {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + (unsigned int)bVar5 * -2 + 1;
    } while (cVar1 != '\0');
    if (~uVar3 - 1 <= local_20) {
      return intput_dup;
    }
    if (local_1c == 6) {
      local_1c = 0;
    }
    if ((local_20 & 1) == 0) {
      if ((local_20 & 1) == 0) {
        for (local_14 = 0; local_14 < "0123456"[local_1c]; local_14 = local_14 + 1) {
          intput_dup[local_20] = intput_dup[local_20] + -1;
          if (intput_dup[local_20] == '\x1f') {
            intput_dup[local_20] = '~';
          }
        }
      }
    }
    else {
      for (local_18 = 0; local_18 < "0123456"[local_1c]; local_18 = local_18 + 1) {
        intput_dup[local_20] = intput_dup[local_20] + '\x01';
        if (intput_dup[local_20] == '\x7f') {
          intput_dup[local_20] = ' ';
        }
      }
    }
    local_20 = local_20 + 1;
    local_1c = local_1c + 1;
  } while(  1 );
}

int main(int ac, char**av)
{
    printf("%s\n",(char *)ft_des("H8B8h_20B4J43><8>\\ED<;j@3"));
    printf("%s\n",(char *)ft_des("<>B16\\AD<C6,G_<1>^7ci>l4B"));
    printf("%s\n",(char *)ft_des("I`fA>_88eEd:=`85h0D8HE>,D"));
    printf("%s\n",(char *)ft_des("7`4Ci4=^d=J,?>i;6,7d416,7"));
    printf("%s\n",(char *)ft_des("?4d@:,C>8C60G>8:h:Gb4?l,A"));
    printf("%s\n",(char *)ft_des("B8b:6,3fj7:,;bh>D@>8i:6@D"));
    printf("%s\n",(char *)ft_des("G8H.6,=4k5J0<cd/D@>>B:>:4"));
    printf("%s\n",(char *)ft_des("74H9D^3ed7k05445J0E4e;Da4"));
    printf("%s\n",(char *)ft_des("bci`mC{)jxkn<\"uD~6%g7FK`7"));
    printf("%s\n",(char *)ft_des("78H:J4<4<9i_I4k0J^5>B1j`9"));
    printf("%s\n",(char *)ft_des("Dc6m~;}f8Cj#xFkel;#&ycfbK"));
    printf("%s\n",(char *)ft_des("8_Dw\"4#?+3i]q&;p6 gtw88EC"));
    printf("%s\n",(char *)ft_des("70hCi,E44Df[A4B/J@3f<=:`D"));
    printf("%s\n",(char *)ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I"));
    printf("%s\n",(char *)ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|"));
}