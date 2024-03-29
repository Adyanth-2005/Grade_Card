

#include "grade_card.h"
#include <stdio.h>

float calculateSGPA(float totalMarks) {
    if (totalMarks >= 90)
        return 10;
    else if (totalMarks >= 80)
        return 9;
    else if (totalMarks >= 70)
        return 8;
    else if (totalMarks >= 60)
        return 7;
    else if (totalMarks >= 50)
        return 6;
    else
        return 0;
}
