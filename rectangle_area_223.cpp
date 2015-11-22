class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        if (C<=E || B>=H || A>=G || D<=F)
        	return area1 + area2;
        
        int len_left = max(E, A);
        int len_right = min(C, G);
        int hei_bottom = max(B, F);
        int hei_top = min(D, H);
        int pub_area = (len_right - len_left) * (hei_top - hei_bottom);
        return area1 + area2 - pub_area;
    }
};