#ifndef FRAME_DATA_H
#define FRAME_DATA_H

#include "tga.h"

typedef struct {
    int width, height;
    TGAImage *framebuffer;
    float *zBuffer;
} Frame;

float *init_zbuffer(int width, int height) {
    int buffer_size = width * height;
    float *zbuffer = malloc(sizeof(float) * buffer_size);
    if (zbuffer == NULL) {
        return NULL;
    }

    // Init zbuffer to be "far away"
    for (int i = 0; i < buffer_size; ++i) {
        zbuffer[i] = -1.0f;
    }
    return zbuffer;
}

Frame *init_frame(int width, int height) {
    Frame *frame = malloc(sizeof(Frame));
    if (frame == NULL) {
        printf("ERROR: Failed to malloc frame\n");
        return NULL;
    }

    frame->framebuffer = createTGAImage(width, height);
    if (frame->framebuffer == NULL) {
        printf("ERROR: Failed to malloc TGAImage\n");
        return NULL;
    }

    frame->zBuffer = init_zbuffer(width, height);
    if (frame->zBuffer == NULL) {
        printf("ERROR: Failed to malloc zBuffer\n");
        return NULL;
    }

    frame->width = width;
    frame->height = height;
    return frame;
}

void reset_zbuffer(Frame *frame) {
    // Init zbuffer to be "far away"
    int buffer_size = frame->width * frame->height;
    for (int i = 0; i < buffer_size; ++i) {
        frame->zBuffer[i] = -1.0f;
    }
}

void free_frame(Frame *frame) {
    free(frame->zBuffer);
    free(frame->framebuffer);
    free(frame);
}

#endif // FRAME_DATA_H