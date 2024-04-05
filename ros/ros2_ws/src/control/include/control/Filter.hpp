#ifndef FILTER_HPP
#define FILTER_HPP

struct MovingAverageFilter {
  double *buffer;
  int size; // buffer size
  int index;
  double sum;
};

// Initialization move average filter
void initMovingAverage(MovingAverageFilter *filter, int size);

// update moving average filter
void updateMovingAverage(MovingAverageFilter *filter, double newValue);

// return moving average filter
double getMovingAverage(const MovingAverageFilter *filter);

// Release move average filter
void freeMovingAverage(MovingAverageFilter *filter);

#endif // FILTER_HPP
