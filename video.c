#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   // YOUR CODE HERE - BEGIN
 // Calculate total frames for the movie and credits
    int framesMovie = fps * durationMovie;     // Total frames for the movie
    int framesCredits = fps * durationCredits; // Total frames for the credits

    // Calculate total size in bits for both sections
    // Color section: 24 bits per pixel
    float sizeMovieBits = framesMovie * w * h * 24;

    // Black-and-white section: 8 bits per pixel
    float sizeCreditsBits = framesCredits * w * h * 8;

    // Total size in bits
    float totalSizeBits = sizeMovieBits + sizeCreditsBits;

    // Convert total size to the specified unit
    if (strcmp(unit, "bt") == 0) {
        return totalSizeBits; // Return size in bits
    } else if (strcmp(unit, "ko") == 0) {
        return totalSizeBits / 1024; // Convert to kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return totalSizeBits / (1024 * 1024); // Convert to megabits
    } else if (strcmp(unit, "go") == 0) {
        return totalSizeBits / (1024 * 1024 * 1024); // Convert to gigabits
    }
   // YOUR CODE HERE - END
   return 0;
}
