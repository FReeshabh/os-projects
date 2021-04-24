#include <stdlib.h>
#include <stdio.h>

int main() {
        char *var = getenv("MY_ENV");
        printf("%p", var);
}
