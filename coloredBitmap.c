#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // YOUR CODE HERE - BEGIN
 // gray scale image size in bits
    int grayScale= w * h * 8;

    // Colored image  size in bits (24 bits per pixel for a colored image)
    float color = grayScale * 3;

    // Convert based on the unit
    if (strcmp(unit, "bt") == 0) {
        return color; // Bits
    } else if (strcmp(unit, "ko") == 0) {
        return color / 1024; // Kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return color / (1024 * 1024); // Megabits
    } else if (strcmp(unit, "go") == 0) {
        return color / (1024 * 1024 * 1024); // Gigabits
    }
   // YOUR CODE HERE - END
   return 0;
}
