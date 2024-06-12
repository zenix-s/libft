#include "../libft.h"

int print_uint_base(unsigned int number, unsigned int base, char *base_str) {
  int characters_printed;

  characters_printed = 0;
  if (number >= base) {
    characters_printed += print_uint_base(number / base, base, base_str);
    characters_printed += ft_putchar_fd(base_str[number % base], 1);
  } else
    characters_printed += ft_putchar_fd(base_str[number], 1);

  return (characters_printed);
}
