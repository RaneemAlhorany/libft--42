/*
! notes:
    ? Libraries are a collection of code that can be used by other programs
    # type of library:
        1) static library
        2) dynamic library

! steps to create static library in c language :
     1) create all method (specific method)
            // all method i write is inside the description methods file
     2) create heder file 
            // the all information of header file you need is inside the  header file.c file 
     3) create make file
            // the all information of make file you need is inside the  make file.c file        

 
  
  ! after every thing you want to use this library:
    ~1) create a file called main.c
        inside it add main method          
            int     main()
            {
                    return (0);
            } 
    ~ 2) include the libft library inside the main file
    ~ 3) to use all function inside the library use command : make all 
        that will convert each c file to object file 
    ~ 4) then go to main file and add any method you want to use it 
    ~ 5) to implement the function/main
        ? make all : to create object file
        ? cc main.c libft.a                   












*/