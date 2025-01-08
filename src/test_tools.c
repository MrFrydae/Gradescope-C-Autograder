//
// Created by welli on 1/7/2025.
//
int epsilon_equal(double x, double y, double epsilon) {
    double diff = x - y;
    if (diff < 0)
    {
        diff = diff * -1;
    }
    return diff<=epsilon;

}
