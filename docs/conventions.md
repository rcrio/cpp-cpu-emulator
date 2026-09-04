# Conventions

## Include best practices

- Corresponding header first
- Standard-library headers second
- Third-party libraries third
- Other headers

Example below for Class1.cpp:
```C++
#include "Class1.h"

#include <cstdint>
#include <iostream>

#include <some_library.h>

#include "Class2.h"
```