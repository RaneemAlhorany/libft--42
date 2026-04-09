//! header file:
    /*
        ! header file 
        ? is a file with a .h extension 
        ? that contains declarations of functions, variables, macros, and other constructs 
        ? that can be used in a C program

        //They serve as an interface :
            # providing information about available features without exposing their 
            # implementation details, which are typically found in corresponding .c source files
    
    
        ! Preprocessing Directive:: 
            $ #include <filename.h> is used for standard library header files.
            $ #include "filename.h" is used for user-defined header files, typically found in / for Header files in same directory as source file


        ~ inside it 
            #ifndef UNIQUE_NAME (The name should be capital case )
            #define UNIQUE_NAME(The name should be capital case ) 
            block of code that will call (ex : prototype of the method) 
            #endif 

        ^ explain each part:
           ? 1. #ifndef PROJECT_UNIQUE_NAME (if not define)
                    Means "if the macro PPROJECT_UNIQUE_NAME is not defined yet".
                    Used as the start of an include guard.
                    Purpose: Ensure the header file's content is included only if it hasn't been included before, preventing duplication and redefinition errors.
                    % the ex why use it (inside another file that you will call the header file )
                        #include "PROJECT_UNIQUE_NAME.h"
                        #include "PROJECT_UNIQUE_NAME.h"
                        ! you call it more than 1 so the result will be duplication and redefinition errors
                            ! so when you use #ifndef will preventing errors 

            ? 2.  define UNIQUE_NAME
                    Defines the macro PROJECT_UNIQUE_NAME the first time the file is included.
                    Purpose: When the file is included again, the compiler sees the macro is already defined and skips the entire file content.
                    Works together with #ifndef as a mechanism to prevent multiple inclusion.


            ? 3. block of code that will call (ex : prototype of the method) 
                    This is where you place the actual content of your header file, such as function prototypes, type definitions, constants, and macros.
                    Purpose: This section contains the declarations and definitions that you want to share across multiple source files.  
                    # It is only included once per compilation unit due to the include guard.
                    # example:
                        % you can call built-in library
                        ~ #include <stdio.h>  // use for printf
                        ~ #include <stdlib.h> // dynamic memory management (malloc / free)
                        ~ #include <stddef.h> // defines data types (size_t)
                        ~ #include <unistd.h> // system-level file operations (read / close)
                        ~ #include <fntl.h> //  file manipulation  (open)

                        % you can write the prototype of the function (you should end it with ;)
                        ! dataType nameFunction (parameter list);
                        ~ int ft_printf(const char *str, ...);

                        % you can  define constants
                        ^    # ifndef CONSTANT_NAME
                        ^    # define CONSTANT_NAME value
                        ^    # endif

                        ? ex:    
                            # ifndef BUFFER
                            # define BUFFER 100
                            # endif
                        
                        % you can include another header file inside it (user defined header)
                        ^ its allow you to use all functions (any thing inside the header file)
                            ! #include "the path of the project/nameHeaderFile.h"
                            ~ ex:
                                ~ #include "./Libft/libft.h"

                        % you can define data types using typedef or struct

                            struct NameOfTheStructures   // Structure declaration
                            {   
                                dataType identifier1;           
                                dataType identifier2;           
                                dataType identifier3;

                            }; // End the structure with a semicolon

                        ? ex:
                            typedef struct S_Node
                            {
                                int data;
                                struct S_Node *next;
                                struct S_Node *prev;
                            } t_Node;
                  
            ? 4. endif // add comment and write the name of  PROJECT_UNIQUE_NAME that will close   
                    Closes the #ifndef condition started earlier.
                    Purpose: Marks the end of the include guard.
                    The comment // PROJECT_UNIQUE_NAME is optional to make it clear which condition is being closed.

   
        ! then call the header file in another files :
            #include "nameFile.h"
            then call any method you want inside the header file 

        ! then implement it by :    
                ^ cc -Wall -Wextar -Werror  ft_*.c NameFileHeader.h
                    
           
    ^ how to solved it :
        #ifndef LIBFT_H
        # define LIBFT_H
        # include <stddef.h>

        int		ft_isalnum(int c);
        int		ft_isascii(int c);

        #endif

    */
