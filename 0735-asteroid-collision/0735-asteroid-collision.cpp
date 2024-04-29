class Solution {
public:
    void collide(vector<int>& left, int right){
        if(left.empty()){
            left.push_back(right);
            return;
        }

        // <-o o-> no collision
        int x=left.back();
        if(x<0 or right>0){
            left.push_back(right);
            return;
        }

        // o-> <-o (same size)
        if(x== -right){
            left.pop_back();
            return;
        }

        // o-> <-o (diff size)
        right = (x < -right)? right : x;
        left.pop_back();
        collide(left, right);
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto& i: asteroids) collide(ans, i);
        return ans;
    }
};