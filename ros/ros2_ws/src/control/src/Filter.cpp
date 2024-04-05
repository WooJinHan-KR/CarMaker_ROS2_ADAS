#include "include/Filter.hpp"
#include <vector>

void initMovingAverage(MovingAverageFilter *filter, int size) {
    filter->buffer.resize(size);
    filter->size = size;
    filter->index = 0;
    filter->sum = 0.0;

    // Buffer Initialization
    for (int i = 0; i < size; ++i) {
        filter->buffer[i] = 0.0;
    }
}

void updateMovingAverage(MovingAverageFilter *filter, double newValue) {

    filter->sum = filter->sum - filter->buffer[filter->index] + newValue;

    filter->buffer[filter->index] = newValue;
    filter->index = (filter->index + 1) % filter->size;
}

double getMovingAverage(const MovingAverageFilter *filter) {
    return filter->sum / filter->size;
}

void freeMovingAverage(MovingAverageFilter *filter) {
    // vector의 메모리를 해제할 필요가 없으므로 따로 처리할 것은 없습니다.
    // 필요한 경우에는 명시적으로 vector를 비우는 것으로 충분합니다.
    filter->buffer.clear();
}
