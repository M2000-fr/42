#include <unistd.h>
#include <stdarg.h>

void print_line(char *str, int *len)
{
    if(!str)
        str = "(null)";
    while(*str)
        *len += write(1, str++, 1);
}

void print_numb(long long int nbr, int base, int *len)
{
    char *hexa = "0123456789abcdef";

    if(nbr < 0)
    {
        nbr *= -1;
        *len += write(1, "-", 1);
    }
    if(nbr >= base)
        print_numb((nbr / base), base, len);
    *len += write(1, &hexa[nbr % base], 1);
}

int ft_printf(const char *format, ... )
{
    int len = 0;
    va_list pointer;
    va_start(pointer, format);

    while(*format)
    {
        if((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
        {
            format++;
            if(*format == 's')
                print_line(va_arg(pointer, char *), &len);
            else if(*format == 'd')
                print_numb((long long int)va_arg(pointer, int), 10, &len);
            else if(*format == 'x')
                print_numb((long long int)va_arg(pointer, unsigned int), 16, &len);
        }
        else 
            len += write(1, format, 1);
        format++;
    }
    return(va_end(pointer), len);
}