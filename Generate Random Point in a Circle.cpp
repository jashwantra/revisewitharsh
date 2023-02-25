class Solution {
public:
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }   
    vector<double> randPoint() {
        double ang=(double)rand()/RAND_MAX*2*M_PI,
            ra=sqrt((double)rand()/RAND_MAX)*r,
            xa=cos(ang)*ra,
            ya=sin(ang)*ra;
        return {x+xa,y+ya};
    }
};
