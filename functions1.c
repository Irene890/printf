#include "main.h"

/********************* PRINT UNSIGNED NUMBER *********************/
/**
 * print_unsigned - Display unsigned no
 * @types: shows arguments
 * @buffer: array to print
 * @flags:  Evaluates active flag
 * @width: width
 *
 * @precision: precision specific
 * @size: size specifier
 * Return: No of chars displayed
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/********** PRINT UNSIGNED NO IN OCTAL  *************/
/**
 * print_octal - Display an unsigned no in octal format
 * @types: shows arg
 *
 * @buffer: array to handle print
 * @flags:  Evaluates active flag
 * @width: find width
 * @precision: precision specific
 * @size: size
 * Return: No of chars displayed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/*********** PRINT UNSIGNED NUM IN HEX ***********/
/**
 * print_hexadecimal - display an unsigned number in hexadecimal format
 * @types: Shows arguments
 * @buffer: array to handle print
 * @flags:  Evaluates active flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: No of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED No IN UPPER HEX **************/
/**
 * print_hexa_upper - display an unsigned in upper hexadecimal format
 * @types: shows arguments
 * @buffer: array to handle print
 * @flags:  Evaluates active flags
 * @width: width
 * @precision: Precision
 * @size: size specifiers
 * Return: No of chars displayed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Display a hexadecimal no lower/upper
 * @types: Shows arguments
 * @map_to: array of values
 * @buffer: array print
 * @flags:  Find active flags
 * @flag_ch: Evaluates active flags
 * @width: find width
 * @precision: Precision
 * @size: size specifiers
 * Return: No of chars displayed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
