class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsl(n),nsr(n);
        stack<int>st;
        for (int i=n-1;i>=0;i--){
            while (!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.empty()){
                nsr[i]=n;
            }
            else {
                nsr[i]=st.top();
        }
        st.push(i);
        }
while (!st.empty()){
        st.pop();
}
    for (int i=0;i<n;i++){
            while (!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (st.empty()){
                nsl[i]=-1;
            }
            else {
                nsl[i]=st.top();
        }
        st.push(i);
        }   
int maxArea = 0;
for (int a = 0; a < n; a++) {
    int width = nsr[a] - nsl[a] - 1;
    int area = heights[a] * width;
    maxArea = max(maxArea, area);
}
return maxArea;
    }
};