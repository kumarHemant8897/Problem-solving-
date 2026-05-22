class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            // collision possible
            while (!st.empty() && st.back() > 0 && a < 0) {

                // current asteroid bigger
                if (abs(a) > st.back()) {
                    st.pop_back();
                    continue;
                }

                // both equal
                else if (abs(a) == st.back()) {
                    st.pop_back();
                }

                // current asteroid destroyed
                destroyed = true;
                break;
            }

            // push if survives
            if (!destroyed) {
                st.push_back(a);
            }
        }

        return st;
    }
};