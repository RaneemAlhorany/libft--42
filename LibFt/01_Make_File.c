//! MakeFile , make 

/*   
    ~ MakeFile:
        % is a file that contains instructions for the make tool,
        % telling it how to compile and link your project files. 
        // you write the name of the file : makefile (case sensitive)

    ~ main idea from Makefile:
        # define a target, its dependencies, and the commands needed to build it.
    
    ~ make tool :
        % only rebuilds files that have changed, saving time and effort

      
   ! general Format
      target: prerequisites
      <TAB> command1
      <TAB> command2
  
    ? target: 
        The file or program you want to create (e.g., app or main.o).

    ?prerequisites: 
        Files that the target depends on (like .c or .h files).

    ?command: 
        Commands to execute (must be preceded by a Tab, not spaces).


    ! how to write make file (what is contains):

~ 1)     CC = gcc (or) CC= cc     
///////////////////////////////////////////////////////
~ 2)    CFLAGS = -Wall -Wextra -Werror  
///////////////////////////////////////////////////////
~ 3)     NAME = nameessintial_file.a  / nameTheLibrary.a 
///////////////////////////////////////////////////////
~  4)     SRC = nameFile.c    nameFile.c .... 
or  if you want to write it as a separate line use (\)
~  4)     SRC = nameFile.c  
                nameFile.c \
               nameFile.c .... 
        
///////////////////////////////////////////////////////
~  5)     OBJ = $(SRC:.c=.o)
///////////////////////////////////////////////////////
~ 6)     all: $(NAME)
///////////////////////////////////////////////////////
! this 7 for program/app)
~ 7)     $(NAME): $(OBJ)
~	        $(CC) $(OBJ) -o $@
///////////////////////////////////////////////////////
! this 7 for (Static Library)
~ 7)     $(NAME): $(OBJ)
~	         ar rcs $@ $(OBJ)  
///////////////////////////////////////////////////////
~ 8)    %.o: %.c
~	    $(CC) $(CFLAGS) -c $< -o $@
///////////////////////////////////////////////////////
! this 9 for (program/app)
~ 9   clean:
~          rm -f $(OBJ) $(OBJ:.o=.d)
~ fclean: clean
~   	rm -f $(NAME)
///////////////////////////////////////////////////////
! this 9 for (Static Library)
~ 9   clean:
~          rm -f $(OBJ)
~ fclean: clean
~   	rm -f $(NAME)
///////////////////////////////////////////////////////
~ 10    re: fclean all
///////////////////////////////////////////////////////
~ 11    .PHONY: all clean fclean re
///////////////////////////////////////////////////////



// explain each part of make file
? the name of the variables is write in capital case
? to acess to the variable use $(name variable)

! 1) CC = gcc (or) CC= cc  
        # compiler used to compile the .c files into .o files.
        CC it is a variable , 
        This variable holds the ((compiler command)) that converts C files
        into object files (.o) and then into the final program or library
        converts C files --> object files (.o) --> final program or library
        ? note :
            Storing it in a variable makes it easy to change later — instead 
            of modifying every rule, you can just update CC if you switch to 
            another compiler like clang.

! 2) CFLAGS = -Wall -Wextra -Werror 
        # compiler flags (warnings + treat warnings as errors).
        (CFLAGS like a variable) ,
        This variable stores the compilation options (Compile Flags).
        -Wall and -Wextra enable most warnings, helping detect errors early.
        -Werror turns warnings into errors, stopping compilation if any appear.

! 3) NAME = nameessintial_file.a  / nameTheLibrary.a 
        # final static library that will be produced.
        This is the name of the final target the Makefile will produce.
        If it’s an executable program
                it might be app or program.
        If it’s a static library, it might be  (nameLibrary.a)
                ex:libft.a.
        # The value you set here will be used in the compile and link commands.

! 4) SRC = nameFile.c    nameFile.c .... 
        # all source .c files for project
        ~ (contains all c files ) 
         This variable lists all the source files you want to compile.
        They are space-separated, 
        and you can include paths 
                * if they are in subfolders, e.g., src/main.c.

!   5) OBJ = $(SRC:.c=.o)
        # convert all .c file names in SRC → corresponding .o object files.
        // convert the c file into o bject file     
        This line transforms the list in SRC from .c to .o extensions 
        using pattern substitution.
        For example: main.c becomes main.o. 
        The .o files are the object files produced during compilation
        before the final linking step.

! 6)  all: $(NAME)
        ? Default target all to build the program or library (builds the main library)
        In a Makefile, we usually start with a default target called all which depends on $(NAME)
        that builds the final target $(NAME). 
        This makes it easy to just run make without specifying the target explicitly.
                # ensures $(NAME) is created when you simply run "make".  
        $ In short:  
            "all" → main entry point of Makefile,  
            makes sure the final library is built

        Running 'make' without arguments will trigger this rule,  
        causing the Makefile to build the final static library   


! 7) Linking rule (program/app)
        $(NAME): $(OBJ)
            $(CC) $(OBJ) -o $@
                After compiling .c files into .o files,
                you need to link them into the final 
                executable or library. 
                This usually uses $@ for the target name 
                and $^ for all prerequisites.
                # $(OBJ) = all object files
                # -o $@ = specify the output file name

                ? linke eack object with the file (Name) after compling the  .c file
            
! 7) Linking rule   (Static Library)
       # General syntax:
             ar rcs libname.a file1.o file2.o ...

        $(NAME): $(OBJ)
            ar rcs $@ $(OBJ)  

        ar -> archive command , Used to create or update static libraries (.a).   
        r → insert or replace files in the archive
        c → create the library if it doesn’t exist
        s → add a symbol table for faster linking when using the library


! 8) Pattern rule to convert .c to .o
        %.o: %.c
            $(CC) $(CFLAGS) -c $< -o $@
                // rule to compile each .c file into a .o file (object file)  
                We use a pattern rule to reduce repetition:
                any .c file is compiled into a .o file
                in the same way. 
                $< represents the first prerequisite (usually the .c file).
                # pattern rule (generic):  
                    %.o = the target (corresponding object file  )
                    %.c = the source file
                -c $< = compile only
			* $(CC)      = compiler (gcc /cc)  
            * $(CFLAGS)  = flags (-Wall -Wextra -Werror)  
            * -c         = compile only (don’t link)  
            * $<         = first prerequisite (the .c file)  
            * -o $@      = output with the target name (the .o file)  
    ? its optional part You can not write because (make file) already does its job by default             
        $ In short:  
            This rule takes each .c file,  
            compiles it into its .o object file,  
            using the given compiler and flags. 
			 
        # Pattern rule: compile each .c → .o file.
        # $< = current source file (.c), $@ = target object file (.o).


!   9) Cleaning targets (clean, fclean) (program/app)
            clean:
                rm -f $(OBJ) $(OBJ:.o=.d) 
            fclean: clean
                rm -f $(NAME)

                   # clean:
                         deletes .o object files and dependency .d files
                    # fclean: 
                        in addition to clean, deletes the final executable or library

                    ~ rm : stand to remove 
                    ~ f : stand to forace  
                    
                    
!   9) Cleaning targets (clean, fclean) (Static Library)
            clean:
                rm -f $(OBJ) 
            fclean: clean
                rm -f $(NAME)

                   # clean:
                         deletes .o object files 
                    # fclean: 
                        in addition to clean, deletes the final executable or library

                    ~ rm : stand to remove 
                    ~ f : stand to forace    


!   10) re: fclean all
        # Rebuild from scratch.
        re runs fclean and then all to rebuild everything from scratch.
        ~ re: stand to rebuild 

!   11) .PHONY: all clean fclean re
        # Declare phony targets to avoid conflicts with file names.
        We use .PHONY to declare targets that are not real files, 
        avoiding conflicts if a file with the same name exists.

*/

//! MakeFile command
/*
    ? NAME → 
        # The variable that holds the final program or library name
                (Think of it as a label for your final output)

    ? all → 
        # The main target: compiles the project and produces the final program/library
                (Runs when you just type make.)

    ? clean → 
        # Removes only temporary object files (.o)
                (Keeps the final executable safe.)

    ? fclean → 
        # Full clean: removes both object files and the final program/library 
                (Resets the project completely.)

    ? re → 
        # Rebuild: runs fclean then all
                (Forces a fresh rebuild with no old files left)

     ~ you write it inside the command :-
        make (here write command)           
        
*/

//! ex MakeFile for Static Library (like libft.a) without usung main function:
//~ excutable command : make (here write command)
/*
    CC = cc

    CFLAGS = -Wall -Wextra -Werror

    NAME = libft.a

    SRC = ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memcpy.c 


    OBJ = $(SRC:.c=.o)

    all: $(NAME)

    $(NAME) : $(OBJ)
        ar rcs $@ $(OBJ)

    clean: 
        rm -f $(OBJ)

    fclean: clean 
        rm -f $(NAME)

    re: fclean all

    .PHONY: all clean fclean re


*/



// 


