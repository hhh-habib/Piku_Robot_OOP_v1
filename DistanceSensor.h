#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

class DistanceSensor
{
  private:

    int trigPin;
    int echoPin;

  public:

    DistanceSensor(
      int trig,
      int echo);

    void begin();

    float getDistance();
};

#endif