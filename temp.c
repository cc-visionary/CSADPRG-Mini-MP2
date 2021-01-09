#include <stdio.h>
#include "set.c"

int main() {
    Set *s1, *s2, *s3;

    s1 = create();
    s2 = create();
    s3 = create();

    add(&s1, 4);
    add(&s1, 2);
    add(&s1, 8);
    add(&s1, 6);
    print(s1); // this statement will display (2, 4, 6, 8)
    add(&s2, 2);
    add(&s2, 5);
    print(s2); // this statement will display (2, 5)
    add(&s3, 7);
    add(&s3, 6);
    print(s3); // this statement will display (6, 7)
    print(sunion(s1, s2)); // this statement will return (2, 4, 5, 6, 8)
    print (intersection(s1, s2)); // this statement will return (2)
    print (difference(s1, s3)); // this statement will return (2, 4, 8)
    print (intersection(s2, s3)); // this statement will return ()
    print(sunion(s2, s3)); // this statement will return (2, 5, 6, 7)
    
    return 0;
}