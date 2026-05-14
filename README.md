# libvector-dev (vector.h)

A high-performance, header-only, and typesafe dynamic array (vector) library for the C programming language programmed by **hypernova-developer**.

## 🚀 The Vision

In the world of C, developers are often chained to static arrays like `int arr[100]`. This limitation hinders the development of scalable systems and modern software architecture. **libvector-dev** is designed to liberate C developers by providing a C++ `std::vector`-like experience without leaving the pure C ecosystem.

> "True power lies in the ability to manage memory without being enslaved by it." — **hypernova-developer**

## 🛡️ Key Features

- **Dynamic Memory Management:** Automatically doubles its capacity when the limit is reached.
- **Type Safety via Macros:** Uses macro-based code generation to provide type-specific functions for any data type (int, float, custom structs, etc.).
- **Zero Dependencies:** Requires only standard headers (`stdlib.h` and `stdio.h`).
- **Allman Style Implementation:** Adheres to the classic Allman brace style for maximum readability in system programming.
- **Optimized Performance:** Uses `static inline` functions to ensure zero function-call overhead.

## 🛠️ Quick Start

### 1. Installation
Simply copy `Vector.h` into your project directory.

### 2. Implementation
Define the vector type for the data structure you need at the top of your source file:

```c
#include "include/vector.h"

/* Generate vector functions for 'int' */
VECTOR_TYPE(int),
```

### 3. Basic Example
```c
#include "include/vector.h"

VECTOR_TYPE(int)

int main()
{
    Vector_int myVec;
    vector_init_int(&myVec);

    /* No more [100] limits. Push as much as you need. */
    for (int i = 0; i < 1000; i++)
    {
        vector_push_int(&myVec, i * 2);
    }

    printf("Vector Size: %zu\n", myVec.size);
    printf("Value at index 500: %d\n", myVec.data[500]);

    /* Always free your memory to maintain system integrity */
    vector_free_int(&myVec);

    return 0;
}
```
## 🏛️ Technical Architecture

The library utilizes **Macro Metaprogramming** to simulate C++ templates. When `VECTOR_TYPE(T)` is invoked, the preprocessor generates a dedicated struct and a suite of functions (init, push, free) specifically for type `T`. This approach ensures both type safety and compile-time optimization.

## 📜 License
Developed and maintained by **hypernova-developer**. Feel free to use it in your open-source projects. The project is protected under the GNU GPL v3.0 License.
