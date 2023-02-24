class Solution {
public:
    bool asteroidsDestroyed(int Mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int i=0;
        long long int mass=Mass;
        for(i=0;i<asteroids.size();i++)
            if(mass>=asteroids[i]){
                mass+=asteroids[i];
                //if(mass>=INT_MAX)
                    //return true;
            }
            else
                break;
        if(i==asteroids.size())
            return true;
        return false;
    }
};
