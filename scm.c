#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "scm.h"
#include "pgm.h"
#include "utils.h"

int quantizationValue(int originalValue, int quantizationLevel) {
    int quantizationLevelRange = 256/quantizationLevel;

    return originalValue/quantizationLevel;
}