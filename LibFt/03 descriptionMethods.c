//! read  the method from the manual then summary it to build it 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////  part one + part 2 ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//! header file
    //? the summary of it is inside the header file section

//! Makefile 
    //? the summary of it is inside the make file section 


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
///////////////////////////////////////////// is part ///////////////////////////////////////////////////////////////   
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
//! 1) isdigit 
/*
    ^ information:
        % this method is part of ctype.h library 
    ^prototype of the method:
        # int isdigit (int c)
    ^ description:
        // it is used to check if the value that send is between 0 and 9
    ^ return: 
        ? return int value (true (1) or false (0))
            ~ return true : if the value is between 0 and 9 mean return (1)
            ~ otherwise: return false mean return (0)
    ^ note:
        the ascii code of 0 is 48
        the ascii code of 9 is 57
    ^ how it write :
        if (c > 47 && c < 58)
		    return (1);
	    return (0);
*/


//! 2) isalpha
/* 
    ^ information:
        % this method is part of ctype.h library 
    ^prototype of the method:
        $ int isalpha(int c);    
    ^ description:
        ~ this method is used to check if the sender value is a letter or not 
        ! letter / alpha --> means upper case or lower case character
    ^ return: 
        ? return int value and use it as boolean value (true or false)
            ~ return true : if the character is alphabit character (upper or lower) mean return (1)
            ~ return false : anything except letters (upper + lower) mean return (0)
    ^ notes:
        1) the ASCII of (A) is :  65 
        2) the ASCII of (Z) is :  90
        3) the ASCII of (a) is :  97
        4) the ASCII of (z) is :  122 
    ^ how it write :
        	if ((c > 64 && c < 91) || (c > 96 && c < 123))
                return (1);
            return (0);
*/



//! 3) isalunum
/*
    ^ information:
        % this method is part of ctype.h library 
    ^prototype of the method:
        $ int isalunum (int c);    
    ^ description:
        ~ this method is used to check for an alphanumeric character (alphabet character or digit)     
        ! letter / alpha --> upper case + lower case character
    ^ return: 
        return int value
        return true : if the send value is an alphanumeric character (alphabet character or digit)
        return false : for otherwise  0
    ^ notes:
        % you can use the previous methods that you write by using the header file 
        previous methods ( isalpha ,  isdigit)
        # the structure of isalunum = isalpha + isdigit
    ^ how it write :
        if (ft_isalpha(c) || ft_isdigit(c))
            return (1);
        return (0);
*/



//! 4) isascii
/*
    ^ information:
        % this method is part of ctype.h library 
    ^prototype of the method:
        $ int isascii (int c);    
    ^ description:
        ~ used to determine whether a given integer value represents a 7-bit US-ASCII character code   
    ^ return: 
        ? return int value use as a boolean value (true or false)
            ~ if the value is between 0 and 127 (inclusive both) then return true (1)
            ~ otherwise return false (0)
    ^ notes:
        % the ascii code between (0 - 127) its include printable and non-printanle value
    ^ how it write :
        if (c > -1 && c < 128)
            return (1);
        return (0);
*/



//! 5) isprint
/*
    ^ information:
        % this method is part of ctype.h library 
    ^prototype of the method:
        $ int isprint (int c);    
    ^ description:
        ~ this method is used to checks for any printable character space
        ~ meaning it checks if the character is a visible character or a space
    ^ return: 
        ? return int value as a boolean value
        return true : if the character  is  a printable / return (1)
        return false : for otherwise return 0 
    ^ notes:
        % the printable character between (32 - 126) (include both)
    ^ how it write :
        if (c > 31 && c < 127)
            return (1);
        return (0);
*/



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
///////////////////////////////////////////// fd method  ///////////////////////////////////////////////////////////      
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

//! 1)  ft_putchar_fd
/*
    ^ information:
        % this method is part of unistd.h library 
    ^prototype of the method:
        $ void ft_putchar_fd(char c, int fd);    
    ^ description:
        ~ this method is used to output a single character to a specified file descriptor
    ^ parameters:
        1) char c : the character to be written
        2) int fd : the file descriptor where the character will be written
            ! common file descriptors:
                0 : standard input (stdin)
                1 : standard output (stdout)
                2 : standard error (stderr)
                ? the standard mean the terminal
                ~ other values : refer to files or other I/O resources 
                * you can create 16 file descriptor
    ^ return: 
        it dosent return any value
    ^ notes:
        % you can use write function inside it to write the character to the file descriptor
        # write(fd, &c, 1);
       ! make sure to include the unistd.h library to use the write function
       $ explain the write function:
            ? ssize_t write(int fd, const void *buf, size_t count);
            % fd : the file descriptor where the data will be written
            % buf : pointer to the data to be written (use &Nameariable to get the address of the character)
            % count : number of bytes to write from the buffer
            ? return value : number of bytes written or -1 if an error occurs
    ^ how to solve it :
        ~ to write the character to the file descriptor you can directly use the write function
        write(fd, &c, 1);
*/



//! 2) ft_putstr_fd
/*
    ^ information:
        % this method is part of unistd.h library
    ^prototype of the method:
        $ void ft_putstr_fd(char *s, int fd);
    ^ description:
        ~ this method is used to output a string to a specified file descriptor
    ^ parameters:
        1) char *s : pointer to the null-terminated string to be written
        2) int fd : the file descriptor where the string will be written
            ! common file descriptors:
                0 : standard input (stdin)
                1 : standard output (stdout)
                2 : standard error (stderr)   
                ? the satandard is the terminal
                ~ other values : refer to files or other I/O resources 
    ^ return: 
        it dosent return any value  
    ^ how to solve it :
        ! if the input string is NULL you should return and do nothing
            if (s == NULL)
                return ((void)NULL);
            ? this for protiction    
        ~ if it is not NULL you can proceed with writing the string to the file descriptor
        ~ to write the string to the file descriptor you can follow these steps:
           while (*s)
            {
                ft_putchar_fd(*s, fd);
                s++;                  
            }
         ? use loop to move over all character inside the string  by using pointer
         // inside the loop :
            call the   ft_putchar_fd method and send it each character in the string and the fd (file descriptore)
            after call the method add 1 to the pointer to move to next character
        ~ another solution:
            # 1) calculate the length of the string using strlen method
            # 2) use write function to write the string to the file descriptor
                ? write(fd, s, len);
                % fd : the file descriptor where the data will be written
                % s : pointer to the data to be written (the string in this case)
                % len : number of bytes to write from the buffer (use strlen(s) to get the length of the string)
            ! make sure to include the unistd.h library to use the write function
*/



//! 3) ft_putendl_fd
/*
    ^ information:
        % this method is part of unistd.h library 
    ^prototype of the method:
        $ void ft_putendl_fd(char *s, int fd);    
    ^ description:
        ~ this method is used to output a string followed by a newline character to a specified file descriptor
    ^ parameters:
        1) char *s : pointer to the null-terminated string to be written
        2) int fd : the file descriptor where the string will be written
            ! common file descriptors:
                0 : standard input (stdin)
                1 : standard output (stdout)
                2 : standard error (stderr)
                ? the satandard is the terminal
                ~ other values : refer to files or other I/O resources 
    ^ return: 
        it dosent return any value
    ^ how to solve it :
      ~ to write the string file you can use the previous method that you write (ft_putstr_fd)
        ft_putstr_fd(s, fd);
      ~ to write the new line character you can use the previous method that you write (ft_putchar_fd)    
        ft_putchar_fd('\n', fd);
    ^ notes and other ways to do it
        % you can use write function inside it to write the string to the file descriptor
        # write(fd, s, strlen(s));
        # write(fd, "\n", 1); to write the newline character after writing the string
       ! make sure to include the unistd.h library to use the write function
       $ explain the write function:
            ? ssize_t write(int fd, const void *buf, size_t count);
            % fd : the file descriptor where the data will be written
            % buf : pointer to the data to be written (the string in this case)
            % count : number of bytes to write from the buffer (use strlen(s) to get the length of the string)
            ? return value : number of bytes written or -1 if an error occurs
*/



//! 4) putnbr_fd
/*
    ^ information:
        % this method is part of libft output utilities
    ^ prototype:
        $ void ft_putnbr_fd(int n, int fd);
    ^ description:
        ~ writes an integer to the given file descriptor
        ~ handles positive and negative numbers
        ~ prints the number digit by digit
        ~ uses recursion to ensure correct order of digits
    ^ parameters:
        1) int n  : the integer to be printed
        2) int fd : the file descriptor on which to write
    ^ return:
        ? no return value
    ^ how to solve it:
        ~ handle the edge case of the minimum integer value
            % INT_MIN cannot be negated safely
                $ if (n == INT_MIN)
                {
                      ft_putstr_fd("-2147483648", fd);
                      return;
                }
        ~ if the number is negative
            % print the minus sign
                if (n < 0)
                {
                    $ ft_putchar_fd('-', fd);
                    % convert the number to positive
                    $ n = -n;
                }

        ~ if the number has more than one digit
            % recursively print all digits except the last
                $ if (n > 9)
                      ft_putnbr_fd(n / 10, fd);
        ~ print the last digit
            $ ft_putchar_fd((n % 10) + '0', fd);
*/




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
///////////////////////////////////////////// convert method  ///////////////////////////////////////////////////////////      
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

//! 1) tolower
/*
    ^ information:
        % this method is part of ctype.h library 
    ^prototype of the method:
        $ int tolower (int c);    
    ^ description:
        ~ this method is used to check for an capital alphabetical character then convert it to lower case
    ^ return 
        * if the value that send is capital letter convert it to lower case otherwise return as send 
    ^ notes:
       to convert the value to lower case you can use the ASCII code
       add 32 to the ASCII code of the capital letter to convert it to lower case
       # the ASCII code of the capital letter is between 65 and 90
            # A = 65
            # Z = 90
            # a = 97    
            # z = 122
        ? the difference between capetal and small letter : 32
    ^ how to solve it :
        if (c > 64 && c < 91)
            return (c + 32);
        return (c);
*/

//! 2) toupper
/*
    ^ information:
        % this method is part of ctype.h library 
    ^prototype of the method:
        $ int toupper (int c);    
    ^ description:
        ~ this method is used to check for a small alphabetical character then convert it to upper case  
    ^ return: 
        * if the value that send is small letter convert it to upper case otherwise return as send
    ^ notes:
        to convert the value to upper case you can use the ASCII code
        substract 32 from the ASCII code of the small letter to convert it to upper case
        # the ASCII code of the small letter is between 97 and 122
            # a = 97    
            # z = 122
            # A = 65
            # Z = 90
        ? the difference between capetal and small letter : 32
    ^ how to solve it :
        if (c > 96 && c < 123)
            return (c - 32);
        return (c);

*/

//! 3)  atoi
/*
    ^ information:
        % this method is part of stdlib.h library 
    ^prototype of the method:
        $ int atoi (const char * nptr);    
    ^ description:
        ~ this method is used to convert a string to an integer
        ~ it parses the string, ignoring leading whitespace characters, 
        ~ and converts the subsequent characters into an integer
        ~ value until it encounters a non-numeric character
    ^ parameters:
        1) const char *nptr : pointer to the null-terminated string to be converted
    ^ return: 
        ? returns the converted integer value
        ? if the string does not contain a valid integer representation, it returns 0
    ^ how to solve it :
        ! you must to check if the input string is not NULL before proceeding with conversion
        ~ if the input string is NULL, you must return 0 
        ! if it is not NULL you can proceed with the conversion
        ~ to convert the string to an integer you can follow these steps:
            # 1) initialize variables:
                ? int sign = 1; // to track the sign of the number (positive or negative) 
                        , default is positive (1) , if negative it will be -1
                ? int result = 0; // to store the final integer result
                ? int index = 0; // index for iterating through the string
            # 2) skip leading whitespace characters:
              	while((nptr[index] > 8 && nptr [index] < 14) || nptr[index] == ' ')
		                index ++;       
                % This loop increments i until it points to the first non-whitespace character in the string
                ~ whitespace characters include spaces, tabs, and newline characters
                ~ the ASCII values for whitespace characters are:
                     space (32)
                     tab (9)
                     newline (10)
                     vertical tab (11)
                     form feed (12)
                     carriage return (13)
            # 3) check for optional sign (+ or -):
                ? if (nptr[index] == '-' || nptr[index] == '+')
                    {
                        if (nptr[index] == '-')
                            sign = -1; // set sign to -1 for negative numbers
                        index++; // move to the next character after the sign
                    }
                % This checks if the current character is a sign. If it's '-', we set sign to -1
                % We then increment i to move past the sign.
            # 4) convert numeric characters to integer:
                // check if the current character is a digit between '0' and '9' by using isdigit method
                ? while (ft_isdigit(nptr[index])) 
                    {
                        result = result * 10 + (nptr[index] - '0'); // convert char to int and build the number
                        index++; // move to the next character      
                    }
                % This loop continues as long as the current character is a digit (between '0' and '9').        ]
                % Inside the loop, we update result by multiplying it by 10 (to shift left) and adding the integer value of the current digit (str[i] - '0').
                % We then increment i to move to the next character.
            # 5) apply the sign to the result:
                ? return (result * sign);
                % Finally, we return the result multiplied by the sign to account for negative numbers.         
*/

//! 4) striteri
/*
    ^ information:
        % this method is part of string.h library
    ^prototype of the method:
        $ void ft_striteri(char *s, void (*f)(unsigned int, char *));
    ^ description:
        ~ applies the function f to each character of the string s, passing its index and a pointer to the character
        ~ modifies the string in place (does not allocate new memory)
    ^ parameters:
        1) char *s : pointer to the input null-terminated string
        2) void (*f)(unsigned int, char *) : function pointer that takes the index and a pointer to the character, modifies the character
    ^ return:
        it does not return any value
    ^ how to solve it:
        ~ first, check if s or f is NULL; if so, do nothing
            if (!s || !f)
                return;
        ~ create counter to move over each index
                unsigned int index = 0;
        ~ use a loop to apply f to each character of s
            while (s[index] != '\0')
            {
                f(index, &s[index]);
                index++;
            }
    ^ notes:
        ? this function is useful for applying transformations or operations to each character of a string in place
        # example of f function
        void    print_and_upper(unsigned int i, char *c)
        {
            if (*c >= 'a' && *c <= 'z')
                *c = *c - 32;
            printf("Index %u: %c\n", i, *c);
        }
*/


//! 5) ft_itoa
/*
    ^ information:
        % converts an integer to a string
    ^ prototype:
        $ char *ft_itoa(int n);
    ^ description:
        ~ allocates and returns a string representing the integer n
        ~ handles negative numbers and zero
        ~ handles INT_MIN separately to avoid overflow
    ^ parameters:
        1) int n : integer to convert
    ^ return:
        ? returns allocated string representation of n
        ? returns NULL if allocation fails
    ^ how to solve it:
        ~ handle INT_MIN case
                $ if (n == -2147483648)
                    $ return (ft_strdup("-2147483648"));
        ~ calculate length of integer
            $ int len = len_of_int_variable(n);
        ~ allocate memory
            $ char *	value_itoa = malloc(len + 1);
            $ if (!value_itoa)
                $ return (NULL);
        ~ handle zero case
            $ if (n == 0)
                $ value_itoa[0] = '0';
        ~ handle negative numbers
            ~ add '-' at beginning
            ~ convert n to positive
        ~ null terminate string
            $ if (n < 0) 
            $ {
            %     value_itoa[0] = '-';
            $     n *= -1;
            $ }
            $ value_itoa[len] = '\0';
        ~ fill digits from end
            $ fill_number(value_itoa, n, len);
        ~ return result
            $ return (value_itoa);
    ^ helper functions:
        ~ len_of_int_variable:
            % calculates number of characters needed
            % accounts for sign and zero
            static int	len_of_int_variable(int n)
            {
                int	len;

                len = 0;
                if (n <= 0)
                {
                    len++;
                    n *= -1;
                }
                while (n > 0)
                {
                    len++;
                    n /= 10;
                }
                return (len);
            }
        ~ fill_number:
            % fills string from end using modulo and division
            static void	fill_number(char *str, int n, int len)
            {
                while (n)
                {
                    str[--len] = (n % 10) + '0';
                    n /= 10;
                }
            }
    ^ optimization:
        ~ separated digit filling logic into helper function
        ~ improved readability and maintainability
        ~ kept original algorithm without modification
    ^ dependencies:
        ~ ft_strdup
    ^ edge cases:
        ~ n == 0
        ~ n < 0
        ~ n == INT_MIN
*/


//! 6) strmapi
/*
    ^ information:
        % this method is part of string.h library
    ^prototype of the method:
        $ char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
    ^ description:
        ~ applies the function f to each character of the string s, passing its index and character, and creates a new string with the results
        ~ allocates memory for the new string, which is the same length as s plus one for the null terminator
    ^ parameters:
        1) char const *s : pointer to the input null-terminated string
        2) char (*f)(unsigned int, char) : function pointer that takes the index and character, returns the mapped character
    ^ return:
        ? returns a pointer to the newly allocated string with mapped characters
        ? returns NULL if memory allocation fails or if s or f is NULL
    ^ how to solve it:
        ~ fisrst step check if the pointer or function is null or not if it return null
            if (!s || !f)
		        return (NULL);
        ~ decleration new pointer and call the ft_strdup method (that will duplicate the value in new string and allocate new memory) 
           char *new_str = ft_strdup(s);
        ~ check if allocation succeeded, return NULL if not (check if the strdup method return null or not) 
             if (!new_str)
                return (NULL);
        ~ initialization counter to move over each index
                 unsigned int index = 0 ;
        ~ use a loop to apply f to each character of s, storing the result in the new string
            while (new_str[index] != '\0')
            {
                new_str[index] = f(index, new_str[index]);
                index++;
            }
        ~ return the pointer to the new string
            return (new_str);
    ^ notes:
        ? here i dont use malloc because the strdup method  use it and allocate memory
*/



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
//! //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
///////////////////////////////////////////// mem method  ////////////////////////////////////////////////////////      
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

//! 1) bzero
/*
    ^ information:
        % this method is part of string.h library 
    ^prototype of the method:
        $  void  bzero(void *ptr,size_t num); 
    ^ description:
        ~ it used to fill a block of memory with a 0 value,
        ~ Its purpose: initialize (clear) a block of memory by setting all bytes to zero (0).
    ^ return: 
        it dosent return anyting
    ^ notes:
        its like memset but it only fill the memory with 0 value
        so call memset with 0 value inside it just like this
        memset(ptr, 0, num);   
    ^ how to solve it :
        ~ you can directly use memset function inside it to fill the memory with 0 value
            ft_memset(ptr, 0, num);
    ? how to use it inside the main ex:  
        ! note: the 0 mean null character  
        # Do not use it on string literals (e.g., char *s = "Hello";) because they are stored in read-only memory.
        # Best used with arrays or dynamically allocated memory.
        int main()
        {
            char test[] = "Alhorany";  
            ft_bzero(test, 5);
            // it will print nothing because the print statment stop on the first null character
            printf("%s\n", test);
            ft_bzero(test + 4, 5);
            printf("%s\n", test); //Alho
            return 0;
        } 
        
*|

//! 2) memcpy
/*
    ^ information:
        % this method is part of string.h library 
    ^prototype of the method:
        $ void *memcpy(void *dest, const void *src, size_t n);    
    ^ description:
        ~ this method is used to copy n bytes from memory area src to memory area dest
        ~ the memory areas should not overlap
    ^ parameters:
        1) void *dest : pointer to the destination memory area where the content is to be copied
        2) const void *src : pointer to the source memory area from which the content is to be copied
        3) size_t n : number of bytes to copy from src to dest
    ^ return: 
        ? returns a pointer to the destination memory area (dest)
    ^ how to solve it :
        ! if they are not NULL you can proceed with the copying
        ~ to copy n bytes from src to dest you can follow these steps:
            # 1) cast the input pointers to char pointers for byte-wise copying (to use it as array of char)
            ~  to used it as the array of the character not with type void
                ? unsigned char *d = dest (in the parameter);
                ? const  unsigned char *s = src;
                    * note the source is constant so you should use const  keyword
                % We cast dest and src to char pointers because we want to copy byte by byte.
            # 2) need counter with data type ==> size_t
                % to be compattable with  the type of Number of bytes to fill
                size_t count =-1;
            # 3) use a loop to copy each byte from src to dest
                 while (++count < n)
                    d[count] = s[count];
                % This loop iterates n times, copying each byte from the source (s) to the destination (d)
                to change value and the condition is the counter should be less that  Number of bytes to fill 
                    because it start with zero
            # 4) return the pointer to the destination memory area
                ? return d;
                % Finally, we return the pointer to the destination memory area.
    ^ notes:
        ! make sure to include the  "libft.h" library to use ft_bzero function
        ! make sure to include stdlib.h library to use malloc function
*/



//! 2) calloc (count, size)
/* 
    ^description:
         $ allocates count * size bytes and sets them all to zero
    ^ usage:
        ? when you need to allocate memory for an array or a structure and want all elements initialized to zero
    ^  prototype:
        void *calloc(size_t count, size_t size);
        # notes:
            ? count: number of elements to allocate.
            ? size: size of each element in bytes.
            ? total memory allocated / total_size = count * size.
            ? set all allocated memory to zero.
            ? size_t is an unsigned long integer type for object sizes; its maximum value is SIZE_MAX.
        # returns:
            ? a generic pointer to the allocated memory block, or NULL if allocation fails.
    ^ process how to work:
        ~ it allocates memory for a given size and zero-initializes it before use    
        ~ first step check for overflow:
                % the max size of memory that can be allocated is defined by SIZE_MAX.
            ? if count * size exceeds SIZE_MAX, it returns NULL.   
            # so check if the count != 0 and size > SIZE_MAX / count --> if true return NULL
                %the benifit of this check is to prevent overflow and ensure that the requested 
                    % memory size is within the limits of what can be allocated.
                % If size > SIZE_MAX / count, then count * size would overflow → return NULL.
            if (count != 0 && size > SIZE_MAX / count)
		            return (NULL);
        ~ calcolate the total size to allocate:
            ? size_t total_size = count * size
            % After ensuring no overflow, we compute the total number of bytes to allocate.
        ~ check if the total size is zero you will alocate malloc (1)  
                  ?if(total_size == 0)
                       ? ptr=malloc(1);
        ~ otherwise allocate memory using malloc of the total size:
            ?else
                ? void *ptr = malloc(total_size)
            % Use malloc to allocate the total size calculated.
            % If malloc fails  it returns NULL
                if (!p) 
                    return null;
            ! note:
                 * Note: if total == 0, malloc(0) may return NULL or a unique pointer; this code returns NULL if malloc does—both behaviors are allowed by the C standard.
        ~ use ft_bzero to initialize the allocated memory to zero:
            ? ft_bzero(ptr, total_size);
            % We use ft_bzero to set all bytes in the allocated memory block to zero.
            % This ensures that the memory is initialized and does not contain garbage values.
        ~ return the pointer to the allocated memory:
            ? return ptr
            % Finally, we return the pointer to the allocated memory block.
      ^ note: 
        ? when you call it you dont send a statc number you send for the second parameter (sizeof(dataType))  
      ! example:
      
        int main(void)
        {
            int *arr;
            int i;

            arr = ft_calloc(5, sizeof(int));
            if (!arr)
                return (1);

            for (i = 0; i < 5; i++)
                printf("arr[%d] = %d\n", i, arr[i]);

            free(arr);
            return (0);
        }
        ? output:    
            arr[0] = 0
            arr[1] = 0
            arr[2] = 0
            arr[3] = 0
            arr[4] = 0
*/      


//! 3) memset
/*
    ^ information:
        % this method is part of string.h library 
     ^prototype of the method:
        $  void *memset(void *ptr, int Replaced_value, size_t num);
            ^ *ptr -->
                Pointer to the beginning of the memory block to fill 
                if you send *ptr + 5 to the method  it will shift 5 from the beginneng
            ^ Replaced_value --> 
                 The value (as a single byte) to be set in each location
            ^ num -->
                Number of bytes to fill   
    ^ description:
        ~ it used to fill a block of memory with a specific value, repeated as a single byte
        ~ Commonly used to initialize arrays or memory regions to a fixed value, such as zeroing an array.
    ^ return: 
        // it return array of character with void type
    ^ how to solve it :
        % need counter with data type ==> size_t
            to be compattable with  the type of Number of bytes to fill (compattable with memeory)
               size_t	count = -1;
        % need to create array of character variable and make it equal the ptr array 
            to used it as the array of the character not with type void
            ex -> unsigned char *str = (unsigned char *) ptr in the parameter;
        % create loop and make the condition (++count < n) that inside theparameter from size of type
        	~ while (++ count < num)
                ~ str[count] = (unsigned char)  Replaced_value; // fill data to the memory with specific value
            to change value and the condition is the counter should be less that  Number of bytes to fill 
            because it start with zero
            finally change the the value of array of character with unsigned char type
        % return the pointer 
            ? return str;
        % note the value should be unsigned char to be able to store values between 0 and 255
        # unsigned char 
            ? is a data type that represents a single byte
            ? Its range is 0 to 255, covering all possible byte values
            ? It is used in memory functions (memset, memcpy, etc.) because:
                    ~ Memory is manipulated as raw bytes.      
            % char can be signed or unsigned depending on the compiler, which may cause negative values or unexpected results
            $  unsigned char guarantees consistent behavior across all systems.
            ! In short:
                ? unsigned char = safe, portable, and standard way to handle raw memory (byte by byte).
*/


//! 4) memcpy
/*
    ^ information:
        % this method is part of the <string.h> library in C (originally called memcpy).
    ^ prototype of the method:
        $ void *memcpy(void *dest, const void *src, size_t n);
    ^ description:
        ~ this function copies n bytes from memory area 'src' to memory area 'dest'.
        ~ It performs a raw memory copy, byte by byte.
        ~ Important: memory areas must NOT overlap (use ft_memmove instead if overlapping is possible).
    ^ parameters:
        1) void *dest : pointer to the destination memory area where the data will be copied.
        2) const void *src : pointer to the source memory area from which the data will be copied.
        3) size_t n : number of bytes to copy.
    ^ return:
        ? returns a pointer to the destination memory area (dest).
    ^ how to implement it:
        # 1) cast pointers to (unsigned char *) to allow byte-by-byte copying:
              unsigned char *d = dest;
              const unsigned char *s = src;
        # 2) prepare a counter of type size_t (to match the type of n).
                size_t count = -1;
        # 3) use a loop to copy each byte from s to d:
              while (++count < n)
                  d[count] = s[count];
        # 4) return the pointer to the destination memory area.
                return dest;
    ^ notes:
        ! use ft_memmove if there's a chance that 'src' and 'dest' overlap.
        ! make sure that both pointers are valid and not NULL before using this function.
        ! ft_memcpy is faster than ft_memmove in non-overlapping cases.

    ? how to use it inside main (example):

        # include <stdio.h>
        # include "libft.h"

        int main()
        {
            char src[] = "Hello World";
            char dest[20];

            // copy "Hello World" into dest
            ft_memcpy(dest, src, 12);
            printf("Copied text: %s\n", dest); // Output: Hello World

            int arr1[] = {1, 2, 3, 4, 5};
            int arr2[5];
            
            // copy integer array
            ft_memcpy(arr2, arr1, 5 * sizeof(int));
            for (int i = 0; i < 5; i++)
                printf("arr2[%d] = %d\n", i, arr2[i]);

            return 0;
        }
*/


//! 5) memmove
/*
    ^ information:
        % this method is part of string.h library
    ^ prototype:
        $ void *memmove(void *dest, const void *src, size_t n);
    ^ description:
        ~ copies n bytes from memory area src to memory area dest
        ~ handles overlapping memory areas safely
        ~ ensures correct copy direction when overlap occurs
    ^ parameters:
        1) void *dest        : pointer to the destination memory area
        2) const void *src   : pointer to the source memory area
        3) size_t n          : number of bytes to copy
    ^ return:
        ? returns a pointer to the destination memory area (dest)
    ^ how to solve it:
        ~ cast dest and src to unsigned char pointers
            $ unsigned char *d = (unsigned char *) dest;
            $ const unsigned char *s =  (unsigned char *) src;
        ~ check memory overlap direction
            % if dest address is greater than src
                # copy bytes backward to avoid overwrite
                if (d > s)
                     while (n--)
                          d[n] = s[n];
            % otherwise
                # safely copy forward using memcpy
                else
                    $ ft_memcpy(d, s, n);
        ~ return destination pointer
             return (dest);
*/


//! 6) memcmp
/*
    ^ information:
        % this method is part of string.h library
    ^ prototype:
        $ int memcmp(const void *s1, const void *s2, size_t n);
    ^ description:
        ~ compares the first n bytes of memory areas s1 and s2
        ~ comparison is done byte by byte (raw memory)
        ~ stops at the first different byte
    ^ parameters:
        1) const void *s1 : pointer to the first memory area
        2) const void *s2 : pointer to the second memory area
        3) size_t n       : number of bytes to compare
    ^ return:
        ? returns 0   if all compared bytes are equal
        ? returns <0  if the first differing byte in s1 is less than in s2
        ? returns >0  if the first differing byte in s1 is greater than in s2
    ^ how to solve it:
        ~ cast both void pointers to unsigned char pointers
            $ const unsigned char *str1 = s1;
            $ const unsigned char *str2 = s2;
        ~ loop through memory while n > 0
            $ while (n--)
            {
                % compare current bytes
                # if bytes are different, return the difference
                    $ if (*str1 != *str2)
                          return (*str1 - *str2);
                % move to the next byte
                    $ str1++;
                    $ str2++;
            }
        ~ if all bytes are equal after n comparisons
            $ return (0);
*/


//! 7) memchr
/*
    ^ information:
        % this method is part of string.h library
    ^ prototype:
        $ void *memchr(const void *s, int c, size_t n);
    ^ description:
        ~ searches for the first occurrence of a byte in a memory area
        ~ scans the first n bytes of memory pointed to by s
        ~ comparison is done byte by byte (raw memory)
    ^ parameters:
        1) const void *s : pointer to the memory area to be searched
        2) int c         : byte value to search for (converted to unsigned char)
        3) size_t n      : number of bytes to examine
    ^ return:
        ? returns a pointer to the first occurrence of c in s
        ? returns NULL if c is not found within the first n bytes
    ^ how to solve it:
        ~ cast the memory pointer to unsigned char pointer
            $ const unsigned char *src = (const unsigned char *)s;
        ~ loop through memory while n > 0
            $ while (n--)
            {
                % compare current byte with c
                    $ if (*src == (unsigned char)c)
                          return ((void *)src);
                % move to the next byte
                    $ src++;
            }
        ~ if the byte is not found after n checks
            $ return (NULL);
*/





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//! //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
///////////////////////////////////////////// string method  ////////////////////////////////////////////////////////      
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

//! 1) strlen
/*
    ^ information:
        % this method is part of string.h library 
    ^prototype of the method:
        $ size_t strlen (const char * s);    
    ^ description:
        ~ this method is used to return the length of the string
        ~ it counts the number of characters in a string until it reaches the null terminator '\0'
        # if the string is empty it will return 0
    ^ return: 
        return the number of the lenght (the type of the return value is size_t (long unsigned int))

    ^ how to solve it :
        ~ create counter to count the number of character in the string
            size_t count = 0;
        ~ use a loop to move over each character in the string until reach the null terminator
            while (s[count])
                count++;    
        ~ return the counter
        return (count);
*/



//! 2) strlcat (string length concatination)
/*
    ^ information:
        % this method is part of string.h library
    ^ prototype:
        $ size_t strlcat(char *dst, const char *src, size_t size);
    ^ description:
        ~ appends src to the end of dst, but only up to size - strlen(dst) - 1 bytes, and null-terminates the result
        ~ returns the total length of the string it tried to create (initial length of dst + length of src)
    ^ parameters:
        1) char *dst : destination buffer (must be null-terminated)
        2) const char *src : source string to append
        3) size_t size : total size of the destination buffer
    ^ return:
        ? returns the length of dst plus the length of src
        ? if return det_len >= size, truncation occurred (return (src_len + size))
    ^ how to solve it:
        ~ calculate the length of dst and src using strlen method
            size_t dst_len = strlen(dst);
            size_t src_len = strlen(src);
        ~ if dst_len >= size, return size + src_len (no space to append)
            if (dst_len >= size)
                return (size + src_len);
        ? If the current length of dst is greater than or equal to the given size,
        ? it means there is no space to append anything from src
        $ In this case, the function returns:
        src_len + size
        % which represents the intended total length (as if concatenation succeeded),
        % even though no characters were actually appended
        ~ if not copy as many bytes as possible from src to dst, leaving space for null terminator by using ft_strlcpy method
	        ft_strlcpy(dst + dst_len, src, size - dst_len);
            $ explain it 
                % dst + dst_len: This is the starting point in the destination buffer where the source string will be appended.
                    ! (dst + dst_len, which means: start from the last character in dst)
                % src: This is the source string that will be appended to the destination.
                    ! (This is the text you want to add to dst)
                % size - dst_len: This is the maximum number of bytes that can be copied from src to dst
                    ! (size is the full capacity available in dst
                    ! dst_len is the number of characters already present
                    ! So size - dst_len = space remaining after the old part
                    ! This ensures that we don't copy too much (so we don't exceed memory limits))
        ~ return dst_len + src_len
            return (dst_len + src_len);
    ^ notes:
        ! useful for safe string concatenation, avoids buffer overflows
        ! allows detection of truncation by comparing return value to size
*/



//! 3) strtrim
/*
    ^ Information:
        % This function is part of the libft library (handles strings).
    ^ Prototype:
        $ char *ft_strtrim(char const *s1, char const *set);
        ? s1 → the original string to be trimmed.
        ? set → a set of characters to remove from the beginning and the end.
    ^ Description:
        ~ Allocates memory and returns a new string which is a copy of s1 after removing any characters found in set from the start and end.
        ~ Uses malloc to allocate memory for the new string.
        ~ Uses ft_strchr to check from the beginning and ft_strrchr to check from the end.
    ^ Return value:
        // Returns the trimmed string.
        // Returns NULL if memory allocation fails.
    ^ How it works:
    % First, checks if s1 or set is NULL.
           if (!s1 || !set)
                return (NULL);
    % Sets 2 integer : to track the start and end of the trimmed string.
            int start = 0 ;
            int end = strlen(s1) - 1;(to point to the last character of s1)
    % Moves start forward while the current character exists in set
        while (s1[start] && ft_strchr(set, s1[start]))
            start++;
        ? explain the condition:
            # s1[start] checks if the current character is not the null terminator (ensures we don't go past the end of the string)
            # ft_strchr(set, s1[start]) checks if the current character is in the set of characters to trim
                ? note : here we check if the specific character is in the set or not
                ? if it is in the set we need to trim it so we move start forward
                ? if it is not in the set we stop moving start forward because we found the first
            # If both conditions are true, it increments start to move to the next character 
    % Moves end backward while the current character exists in set
        while (end >= start && ft_strrchr(set, s1[end]))
                end--;
        ? explain the condition:
            # end >= start ensures we do not move end before start (prevents invalid range)
            # ft_strrchr(set, s1[end]) checks if the current character is in the set of characters to trim
                ? note : here we check if the specific character is in the set or not
                ? if it is in the set we need to trim it so we move end backward
                ? if it is not in the set we stop moving end backward because we found the last        
            # If both conditions are true, it decrements end to move to the previous character
    % Allocates memory for the new string with (end - start + 2) to include  the last character and the null terminator \0 
        char *	trimmed_str = malloc(end - start + 2);
    % Checks if memory allocation was successful or not to avoid memory leak     
        if (!trimmed_str)
            return (NULL);
        ? If malloc fails, it returns NULL, indicating that memory allocation was unsuccessful.    
    % Uses ft_memcpy to copy characters from start to end into the new string
        ft_memcpy(trimmed_str, s1 + start, end - start + 1);
        ? s1 + start , &s1[start] points to the first character to copy
        ? end - start + 1 is the number of characters to copy (including the last character)
    % Adds the null terminator \0.
        trimmed_str[end - start + 1] = '\0';
    % Finally, returns the pointer to the new trimmed string.
        return (trimmed_str);

    ^ Note:
    ? The condition end >= start protects against cases where the entire string consists of set characters.
    ? start and end define the bounds of the actual string content to keep.
    ? +2 in malloc accounts for the length difference and the null terminator.
*/



//! 4) strdup
/*
    ^ information:
        % this method is part of string.h library 
    ^prototype of the method:
        $ char *strdup (const char *s);    
    ^ description:
        ~ this method is used to create a duplicate of the string s by allocating memory for the new string
        ~ it copies the content of the original string into the newly allocated memory
        $ creates a new copy of the string s in newly allocated memory and returns a pointer to it.
    ^ parameters:
        1) const char *s : pointer to the null-terminated string to be duplicated
    ^ return: 
        ? returns a pointer to the newly allocated duplicate string
        ? returns NULL if memory allocation fails
    ^ usage:
        ? when you need to duplicate a string and ensure that the new string is stored in a separate memory location.
    ^ process how to work:
        ! it allocates memory for a new string and copies the contents of the original string into it:
            ~ calculate the length of the input string using strlen method
                size_t len = strlen(s);
            % We use strlen to find the length of the string s, which is necessary to allocate enough memory for the new string
            $ We use strlen(s) to get the length of the original string (excluding \0).
            ~ allocate memory for the new string using calloc, adding 1 for the null terminator
                char *	dupstr = malloc(len + 1);
            % We use calloc to allocate memory for the new string, which is len bytes long.
            % We add +1 to allocate space for the null terminator \0
            ~ check if memory allocation was successful; if not, return NULL
                if (!dupstr)
                    return (NULL);
            % If malloc fails, it returns NULL, indicating that memory allocation was unsuccessful.
            ~ copy the content of the original string into the newly allocated memory using ft_memmove method
                ft_memmove(dupstr, s, len );
            % We use ft_memmove to copy the content from the original string s to the newly allocated memory dupstr.
            ~ add the null terminator at the end of the new string
                dupstr[len] = '\0';    
            ~ return the pointer to the newly allocated duplicate string
                return (dupstr);
    ^ notes:
        ! make sure to include stdlib.h library to use malloc function
        ! make sure to include "libft.h" library to use ft_memcpy function
        ! Note: strdup is not part of the C standard library, but it is widely supported in many C libraries.  
*/


//! 5) ft_strjoin
/*
    ^ information:
        % this method is part of string.h library 
    ^prototype of the method:
        $ char *ft_strjoin(char const *s1, char const *s2);    
    ^ description:
        ~ this method is used to concatenate two strings into a new string
        ~ it allocates memory for the new string, which is the combined length of both input strings plus one for the null terminator
    ^ parameters:
        1) char const *s1 : pointer to the first null-terminated string
        2) char const *s2 : pointer to the second null-terminated string
    ^ return: 
        ? returns a pointer to the newly allocated string containing the concatenated result of s1 and s2
        ? returns NULL if memory allocation fails
    ^ how to solve it :
        ! you must to check if the input strings are not NULL before proceeding with concatenation
        ! if it is not NULL you can proceed with the concatenation
        ~ to concatenate the two strings you can follow these steps:
            # check if either input string is NULL; if so, return NULL
                 if (!s1 || !s2)
                    return (NULL);
            #  calculate the lengths of both input strings using strlen method
                 size_t len_s1 = strlen(s1);
                 size_t len_s2 = strlen(s2);
            #  allocate memory for the new string using malloc
                ? char *new_str = malloc(len of the first string + len of the second string + 1 (this for \0));
                % We add +1 to allocate space for the null terminator \0
                char *	strjoin = malloc(len_s1 + len_s2 + 1);
            #  check if memory allocation was successful
                 if (!strjoin)     
                        return NULL;
                % If malloc fails, it returns NULL, indicating that memory allocation was unsuccessful.
            !  copy the contents of both input strings into the newly allocated memory
            #  first copy the contents of s1 into strjoin using ft_memcpy method
                 ft_memcpy(strjoin, s1, len_s1);
                % We use memcpy to copy the content from the original string s1 to the newly allocated memory strjoin.
            #  second copy the contents of s2 into strjoin using ft_memcpy method
                 ft_memcpy(strjoin + len_s1, s2, len_s2);
                % We use memcpy to copy the content from the original string s2 to the newly allocated memory strjoin.
            #  add the null terminator at the end of new_str
                ? strjoin[len_s1 + len_s2] = '\0';        
            #  return the pointer to the newly allocated concatenated string
                ? return strjoin;
    ^ notes:
        ! make sure to include the  "libft.h" library to use strlen function
        ! make sure to include stdlib.h library to use malloc function
*/


//! 6) split
/*
! ft_split
    ^ information:
        % this is the main method that replicates the behavior of splitting a string
          into an array of substrings based on a delimiter character
        % it relies on the three helper methods:
            - num_of_substrings
            - extract_word
            - fill_split_array
    ^ prototype:
        $ char **ft_split(char const *s, char c);
    ^ description:
        ~ takes a string s and splits it into multiple words separated by the
          delimiter character c
        ~ allocates an array of char* pointers where each element stores one word
        ~ the final element of the returned array is always NULL
        ~ does NOT modify the original string; all returned substrings are newly allocated
    ^ return:
        ? returns a dynamically allocated array of strings (char **)
        ? each string inside the array is also dynamically allocated
        ? returns NULL if:
              - s is NULL
              - memory allocation fails in any step
    ^ how to solve it:
        ~ first check if the input string is NULL:
            if (!s)
                return (NULL);
        ~ determine how many substrings exist using num_of_substrings:
            size_t num_words = num_of_substrings(s, c);
        ~ allocate memory for the array of pointers using calloc:
            char **split_array = ft_calloc(num_words + 1, sizeof(char *));
            % using calloc ensures:
                - all pointers start as NULL
                - the last pointer (num_words) is automatically NULL
        ~ handle allocation failure:
            if (!split_array)
                return (NULL);
        ~ fill the array using fill_split_array:
            if (fill_split_array(split_array, s, c) == -1)
            {
                free(split_array);
                return (NULL);
            }
            % fill_split_array:
                - extracts each word using extract_word
                - if a word allocation fails, it frees all previously allocated words
                  and signals failure with -1

        ~ ensure the last pointer in the array is NULL 
            split_array[num_words] = NULL;
        ~ if everything succeeds, return the fully built array:
            return (split_array);
    ^ notes:
        # this method does not free any words on error;
          fill_split_array is responsible for freeing the individual substrings
        # ft_split only frees the array of pointers when something goes wrong
        # time complexity: O(n) — each character in s is processed at most once
        # memory usage is proportional to:
              number_of_words + total_length_of_all_words
        # the method guarantees:
              - no memory leaks
              - no undefined behavior
              - a clean and well-structured split implementation

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
! num_of_substrings
    ^ information:
        % this is a static helper method used internally by ft_split
        % it counts how many words (substrings) exist inside the string s
          separated by the delimiter character c
    ^ prototype:
        $ static size_t num_of_substrings(const char *s, char c);
    ^ description:
        ~ scans the entire string s and counts how many valid words it contains
        ~ a word is any sequence of characters not equal to the delimiter c
        ~ skips all leading delimiters and only increments count when a word starts
    ^ return:
        ? returns the number of substrings found inside s
        ? returns 0 if the string contains no words
        ? never returns a negative value because the return type is size_t
    ^ how to solve it:
        ~ create a counter for the number of substrings + pointer to iterate through s:
            size_t count = 0;
             char *next ;
        ~ iterate through the string using a pointer s:
            while (*s)
            {
                % skip all consecutive delimiter characters:
                    while (*s && *s == c)
                        s++;
                % if we reach '\0' after skipping delimiters, stop:
                    if (*s == '\0')
                        break;
                % increment count since a new word has started:
                    count++;
                % find the next delimiter using ft_strchr:
                    next = ft_strchr(s, c);
                    $ if next exists, move pointer s to it:
                    if (next)
                        s = next;
                    $ otherwise no more delimiters exist, break because we are at the last word:
                    else
                        break;
            }
        ~ finally return the total count of substrings found:
            return (count);

    ^ notes:
        # works in O(n) time complexity
        # ft_strchr is used to jump directly to the next delimiter efficiently
        # this helper does not allocate memory; it only counts
        # used only inside ft_split to determine how much memory to allocate
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
! fill_split_array
    ^ information:
        % this is an internal static helper used by ft_split
        % its job is to fill the already-allocated array of strings (arr)
        % it extracts each word from the input string s and stores it in arr
        % it stops when s reaches the end of the string
    ^ prototype:
        $ static int fill_split_array(char **arr, const char *s, char c);
    ^ description:
        ~ skips delimiter characters c at the beginning of each loop
        ~ for every valid word, calls extract_word(s, c, &len)
            • extract_word returns a newly allocated substring
            • len contains the length of the extracted word
        ~ stores each extracted word into arr[i]
        ~ advances s by len to continue processing the remaining string
        ~ if memory allocation fails, frees all previously allocated words
    ^ return:
        ? returns 0 on success (all words stored correctly)
        ? returns -1 if a memory allocation failure occurs
            • in this case, all partially allocated words are freed
    ^ how to solve it:
        ~ create index i to track position in arr + length len for each word + pointer word:
            size_t i ;
            size_t len;
            char *word;
        ~ initialize index i to 0
            i = 0;
        ~ loop while (*s):
        while (*s)
        {
            # skip delimiters:
                while (*s && *s == c) 
                    s++;
            # check end of string:
                if (*s == '\0') 
                    break;
            # extract next word + its length:
                word = extract_word(s, c, &len);
            # check allocation failure:
                if (!word) free previous words and return -1;
                    if (!word)
                    {
                        while (i > 0)
                            free(arr[--i]);
                        return (-1);
                    }
            # save the word:
                arr[i++] = word;
            # move s forward:
                s += len;
        }
        ~ return 0 for success
            return (0);
    ^ notes:
        ! relies on extract_word to compute word length efficiently
        ! never calls ft_strlen manually (optimized)
        ! ensures clean memory handling in case of failure
        ! used only inside ft_split to build the result array

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
! extract_word
    ^ information:
        % this is a static helper function used internally by ft_split
        % its job is to extract a single word (substring) starting from pointer s
        % a “word” ends either at the next delimiter c or at the end of the string
        % unlike the simple version, this version ALSO returns the word length through *len
    ^ prototype:
        $ static char *extract_word(const char *s, char c, size_t *len);
    ^ description:
        ~ searches for the next occurrence of delimiter c using ft_strchr
        ~ if a delimiter is found, the word length is (next - s)
        ~ if no delimiter exists, the word length is the full remaining length of s
        ~ stores the computed length inside *len
        ~ finally, allocates and returns the substring using ft_substr
    ^ return:
        ? returns a newly allocated string containing the extracted word
        ? returns a substring of length *len
        ? memory must later be freed by the caller (ft_split)
    ^ how to solve it:
        ~ find the next delimiter:
             char *next = ft_strchr(s, c);
        ~ determine the length:
            • if next exists → *len = (size_t)(next - s)
            • otherwise → *len = ft_strlen(s)
            	if (next != NULL)
                    *len = (size_t)(next - s);
                else
                    *len = ft_strlen(s);
        ~ create and return the word:
             return ft_substr(s, 0, *len);
    ^ notes:
        ! runs in O(n), scanning until the next delimiter
        ! does not modify s; only reads it
        ! safe when the last word has no delimiter after it
        ! provides the word length so ft_split can avoid using ft_strlen again
*/



//! 7) strncmp
/*
    ^ information:
        % this method is part of string.h library
    ^ prototype:
        $ int strncmp(const char *s1, const char *s2, size_t n);
    ^ description:
        ~ compares two strings lexicographically
        ~ comparison is done character by character
        ~ compares at most n characters
        ~ stops when a difference is found or when a null terminator is reached
    ^ parameters:
        1) const char *s1 : pointer to the first string
        2) const char *s2 : pointer to the second string
        3) size_t n       : maximum number of characters to compare
    ^ return:
        ? returns 0   if both strings are equal within n characters
        ? returns <0  if the first differing character in s1 is less than in s2
        ? returns >0  if the first differing character in s1 is greater than in s2
    ^ how to solve it:
        ~ loop through both strings while n > 0
            $ while (n--)
            {
                % compare current characters as unsigned char
                    $ if (*(unsigned char *)s1 != *(unsigned char *)s2)
                          return (*(unsigned char *)s1 - *(unsigned char *)s2);
                % if end of string is reached
                    $ if (*s1 == '\0')
                          break;
                % move to the next characters
                    $ s1++;
                    $ s2++;
            }
        ~ if no difference is found within n characters
            $ return (0);
*/


//! 8) strlcpy
/*
    ^ information:
        % this method is part of string.h library
    ^ prototype:
        $ size_t strlcpy(char *dst, const char *src, size_t size);
    ^ description:
        ~ copies a string from src to dst
        ~ copies at most size - 1 characters
        ~ always null-terminates the destination string (if size > 0)
        ~ returns the total length of src
    ^ parameters:
        1) char *dst        : pointer to the destination buffer
        2) const char *src  : pointer to the source string
        3) size_t size      : size of the destination buffer
    ^ return:
        ? returns the length of the source string
        ? allows detection of truncation if return value >= size
    ^ how to solve it:
        ~ calculate the length of the source string
            $ size_t len = ft_strlen(src);
        ~ if destination size is zero
            % nothing is copied
                $ return (len);
        ~ copy characters while space remains and source is not finished
            $ while (--size && *src)
                  *dst++ = *src++;
        ~ ensure null termination of destination
            $ *dst = '\0';
        ~ return the source length
            $ return (len);
*/


//! 9) strnstr
/*
    ^ information:
        % this method is part of string.h library
    ^ prototype:
        $ char *strnstr(const char *big, const char *little, size_t len);
    ^ description:
        ~ searches for the first occurrence of the substring little in the string big
        ~ search is limited to the first len characters of big
        ~ stops when the substring is found or when len is exceeded
    ^ parameters:
        1) const char *big    : pointer to the string to be searched
        2) const char *little : pointer to the substring to find
        3) size_t len         : maximum number of characters to examine in big
    ^ return:
        ? returns a pointer to the beginning of the found substring in big
        ? returns NULL if little is not found within the first len characters
        ? returns big if little is an empty string
    ^ how to solve it:
        ~ handle the empty substring case
            % if little is an empty string
                if (!*little)
                     return ((char *)big);
        ~ get the length of the substring
             size_t little_len = ft_strlen(little);
        ~ loop through the main string while characters remain and len is sufficient
             while (*big && len >= little_len)
             {
                % compare the substring with the current position in big
                    $ if (ft_strncmp(big, little, little_len) == 0)
                          return ((char *)big);
                % move to the next character in big
                    $ big++;
                % decrease the remaining length
                    $ len--;
            }
        ~ if the substring is not found within the limit
             return (NULL);
*/



//! 10) substr
/*
    ^ information:
        % this method is part of string.h library
    ^ prototype:
        $ char *substr(char const *s, unsigned int start, size_t len);
    ^ description:
        ~ creates a new string which is a substring of the string s
        ~ the substring starts at index start and has a maximum length of len
        ~ memory for the new string is dynamically allocated
    ^ parameters:
        1) char const *s     : pointer to the original string
        2) unsigned int start: starting index of the substring
        3) size_t len        : maximum length of the substring
    ^ return:
        ? returns a newly allocated substring
        ? returns an empty string if start is beyond the length of s
        ? returns NULL if memory allocation fails or s is NULL
    ^ how to solve it:
        ~ handle invalid input
            % if s is NULL
                $ return (NULL);
        ~ get the length of the original string
            $ size_t len_str = ft_strlen(s);
        ~ handle the case where start is outside the string
            % if start >= len_str
                $ return (ft_strdup(""));
        ~ adjust len to avoid reading past the end of the string
            % if len > len_str - start
                $ len = len_str - start;
        ~ allocate memory for the substring using malloc
            $ char 	sub = malloc(len + 1);
        ~ copy the substring into the new buffer
            $ ft_memcpy(sub, s + start, len);
        ~ null-terminate and return the substring
            $ sub[len] = '\0';
            $ return (sub);
*/







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
//! //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
///////////////////////////////////////////// search method  ///////////////////////////////////////////////////////////      
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

//! 1) strchr
/*
    ^ information:
        % this method is part of string.h library 
    ^prototype of the method:
        $ char *strchr (const char *s , int c);
    ^ description:
        ~ returns a pointer to the first occurrence of the character c int in the string s
        ~ if the character is not found it return null
    ^ return: 
        * return a pointer to matched character (from the character to the end of characters) or null if the character is not found
    ^ notes:
        % need counter with data type ==> int 
              $ int	count = 0;
        % loop to check if there is a value inside the string or not 
              $ while (s[count])
              {
                    % inside the loop check which characters inside string is equaly to c (you should use cast to convert it to char)
                        $ if (s[count] == (char) c)
                            # if any character inside the string match the value of the specific character then you should return 
                            # the pointer of the specific charater in the array and use & to specify the location of the character
                                $ return ((char *) &s[counter]) or return ((char *) s + counter);
                    # the end of the loop you should increment the counter to check the next character if match or not because the previous one not match
                        $ count++;    
              }
        ~ after loop add check for null character , because the loop stop when it reach the null character
              $ if (c == '\0') or  if (s[count] == (char) c)
                return ((char *) &s[count]); or return ((char *) s + count);
        ~ if there is no match you should return null
             $ return (NULL);
*/



//! 2) strrchr 
/*
    ^ information:
        % this method is part of string.h library 
    ^prototype of the method:
        $ char *strrchr (const char *s , int c);
    ^ description:
        ~ returns a pointer to the last occurrence of the character c in the string s
        ~ if the character is not found it return null
    ^ return: 
        * return a pointer to matched character (from the character to the end of characters) or null if the character is not found
    ^ notes:
        % need counter with data type ==> int 
              $ int	count = strlen (s); 
                // to point to the last character of the string
        % loop to check if there is a value inside the string or not 
            $ while (count > -1)
            {
                % inside the loop check which characters inside string is equaly to c (you should use cast to convert it to char)
                # if any character inside the string match the value of the specific character then you should return 
                # the pointer of the specific charater in the array and use & to specify the location of the character
                    $ if (s[count] == (char) c)
                            $  return ((char *) &s[counter]) or return =( (char * )(s + counter));
                # the end of the loop you should decrement the counter to check the previous character if match or not because the next  one not match  
                        $ count --;
            }    
        ~ if there is no match you should return null
             $ return (NULL);
*/











