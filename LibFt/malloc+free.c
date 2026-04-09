
////===============================================================================
//!                                malloc()
////===============================================================================

/*
! Prototype:
    void *malloc(size_t size);

//-------------------------------------------------------------------------------
! 📌 DESCRIPTION:
    malloc allocates 'size' bytes of memory on the heap and returns a pointer
    to the allocated memory.

    - The memory is NOT initialized (contains garbage values).
    - Allocation happens at runtime (dynamic memory allocation).

//-------------------------------------------------------------------------------
! 📥 RETURN VALUE:
    - On success: pointer to allocated memory.
    - On failure: NULL.

//-------------------------------------------------------------------------------
! ⚠️ IMPORTANT NOTES:
    - Always check if malloc returned NULL.
    - Memory must be freed using free().
    - Memory is allocated in the HEAP, not the STACK.
    - Contents are undefined until initialized.

//-------------------------------------------------------------------------------
! 🧩 BASIC USAGE:

    #include <stdlib.h>

    void *ptr = malloc(size);
    if (!ptr)
    {
        // handle allocation failure
    }

//-------------------------------------------------------------------------------
! 🔥 BEST PRACTICE:

    malloc(n * sizeof(type))

    Example:
        int *arr = malloc(10 * sizeof(int));

    OR (better):
        int *arr = malloc(10 * sizeof(*arr));

//-------------------------------------------------------------------------------
! 📦 USAGE WITH DIFFERENT TYPES:

% 1️⃣ int array:
    int *arr = malloc(10 * sizeof(int));

% 2️⃣ struct:
    typedef struct s_user
    {
        int id;
        char name[50];
    } t_user;

    t_user *user = malloc(sizeof(t_user));

% 3️⃣ array of structs:
    t_user *users = malloc(5 * sizeof(t_user));

% 4️⃣ strings (char array):
    char *str = malloc(21); // 20 chars + '\0'

% 5️⃣ 2D array:
    int **arr = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        arr[i] = malloc(cols * sizeof(int));

// -------------------------------------------------------------------------------
! 🧠 HOW IT WORKS (CONCEPT):
    - Uses heap memory manager.
    - Finds suitable free block.
    - May split large blocks.
    - May merge adjacent free blocks (coalescing).

//-------------------------------------------------------------------------------
! ❌ COMMON MISTAKES:

# 1. Not checking NULL:
    int *p = malloc(sizeof(int));
    *p = 5; // ❌ dangerous if malloc failed

# 2. Memory leak:
    malloc(100); // ❌ lost reference

# 3. Use after free:
    free(p);
    *p = 10; // ❌ undefined behavior

# 4. Wrong size:
    malloc(10); // ❌ not portable

//-------------------------------------------------------------------------------
! ✔️ CORRECT PATTERNS:

    int *p = malloc(sizeof(int));
    if (!p)
        return (ERROR);

    free(p);
    p = NULL;

//-------------------------------------------------------------------------------
! 🔄 RELATED FUNCTIONS:

    malloc   → allocate (no initialization)
    calloc   → allocate + initialize to 0
    realloc  → resize memory
    free     → release memory

//-------------------------------------------------------------------------------
! 🧪 FULL EXAMPLE:

    #include <stdlib.h>
    #include <stdio.h>

    int main(void)
    {
        int *arr = malloc(5 * sizeof(int));
        if (!arr)
            return (1);

        for (int i = 0; i < 5; i++)
            arr[i] = i * 2;

        for (int i = 0; i < 5; i++)
            printf("%d\n", arr[i]);

        free(arr);
        arr = NULL;

        return (0);
    }

//-------------------------------------------------------------------------------
! 🧠 PRO TIPS (42 / SYSTEM LEVEL):

    ✔ Use sizeof(*ptr) instead of type
        int *arr = malloc(10 * sizeof(*arr));

    ✔ Create wrapper:

        void *ft_malloc(size_t size)
        {
            void *ptr = malloc(size);
            if (!ptr)
            {
                perror("malloc failed");
                exit(EXIT_FAILURE);
            }
            return ptr;
        }

    ✔ Golden Rule:
        malloc → check → use → free

//-------------------------------------------------------------------------------
!🎯 SUMMARY:
    malloc is essential for dynamic memory allocation, but must be used
    carefully to avoid leaks, crashes, and undefined behavior.

//===============================================================================
*/



////===============================================================================
//!                                    free()
////===============================================================================
/*
! Prototype:
    void free(void *ptr);

//-------------------------------------------------------------------------------
! 📌 DESCRIPTION:
    free releases (deallocates) memory that was previously allocated by:
        - malloc()
        - calloc()
        - realloc()

    ? The memory is returned to the heap (system).
    ? The pointer itself is NOT deleted (still exists, but becomes dangling).

// -------------------------------------------------------------------------------
! 📥 RETURN VALUE:
    - free does NOT return anything (void).

//-------------------------------------------------------------------------------
!⚠️ IMPORTANT NOTES:
    - You MUST only free memory that was dynamically allocated.
    - Never free:
        ❌ stack variables
        ❌ static memory
        ❌ string literals
    - After free, the pointer becomes a DANGLING POINTER.
    - It is GOOD PRACTICE to set pointer to NULL after freeing.

//-------------------------------------------------------------------------------
!🧩 BASIC USAGE:

    void *ptr = malloc(100);

    if (!ptr)
        return ;

    free(ptr);
    ptr = NULL;

//-------------------------------------------------------------------------------
!🚨 WHAT HAPPENS AFTER free?

    - Memory is released back to the system.
    - Pointer still holds the old address (invalid now).
    - Accessing it leads to UNDEFINED BEHAVIOR.

//-------------------------------------------------------------------------------
!❌ COMMON MISTAKES:

1️⃣ Double free:
    free(ptr);
    free(ptr); // ❌ CRASH / undefined behavior

2️⃣ Freeing unallocated memory:
    int x;
    free(&x); // ❌ ERROR

3️⃣ Freeing string literal:
    char *str = "hello";
    free(str); // ❌ ERROR

4️⃣ Use after free:
    free(ptr);
    *ptr = 10; // ❌ undefined behavior

//-------------------------------------------------------------------------------
! ✔️ CORRECT PATTERNS:

    free(ptr);
    ptr = NULL;

    if (ptr)
        free(ptr);

//-------------------------------------------------------------------------------
!🧠 SAFE FREE PATTERN (Recommended):

    if (ptr)
    {
        free(ptr);
        ptr = NULL;
    }

//-------------------------------------------------------------------------------
! 📦 FREEING COMPLEX STRUCTURES:

# 1️⃣ Free array:

    int *arr = malloc(10 * sizeof(int));
    free(arr);

//-------------------------------------------------------------------------------
# 2️⃣ Free 2D array:

    for (int i = 0; i < rows; i++)
        free(arr[i]);

    free(arr);

//-------------------------------------------------------------------------------
# 3️⃣ Free linked list:

    t_node *tmp;

    while (head)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }

//-------------------------------------------------------------------------------
! 🧠 HOW IT WORKS (CONCEPT):
    - Marks the memory block as free in the heap.
    - May merge adjacent free blocks (coalescing).
    - Does NOT erase data (just releases ownership).

// -------------------------------------------------------------------------------
! 🔄 RELATED FUNCTIONS:

    malloc   → allocate memory
    calloc   → allocate + zero
    realloc  → resize memory
    free     → release memory

//-------------------------------------------------------------------------------
! 🧪 FULL EXAMPLE:

    #include <stdlib.h>

    int main(void)
    {
        int *p = malloc(sizeof(int));
        if (!p)
            return (1);

        *p = 42;

        free(p);
        p = NULL;

        return (0);
    }

//-------------------------------------------------------------------------------
! 🧠 PRO TIPS (42 / SYSTEM LEVEL):

    ✔ Always set pointer to NULL after free
    ✔ Never double free
    ✔ Track ownership of memory
    ✔ Use valgrind to detect leaks:
        valgrind --leak-check=full ./program

//-------------------------------------------------------------------------------
! 🎯 SUMMARY:
    free is used to release dynamically allocated memory.
    Improper use can cause crashes, leaks, and undefined behavior.

    Golden Rule:
        malloc → use → free → ptr = NULL

//===============================================================================
*/



