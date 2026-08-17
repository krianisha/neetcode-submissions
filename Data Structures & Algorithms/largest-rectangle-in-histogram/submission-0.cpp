class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nextsmaller(n);
        vector<int> prevsmaller(n);

        stack<int> st;

        // Next Smaller
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            nextsmaller[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Previous Smaller
        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            prevsmaller[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int width = nextsmaller[i] - prevsmaller[i] - 1;

            int area = heights[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }
};