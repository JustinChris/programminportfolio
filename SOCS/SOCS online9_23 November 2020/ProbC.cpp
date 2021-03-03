#include<stdio.h>
#include <stdlib.h>

int dp[8][8];

int min(int x, int y) {
	if(x < y) {
	    return x;
	}
	return y;
}
int solution(int sr, int sc, int fr, int fc) {
	if (sr == fr && sc == fc) {
		return dp[0][0];
	}
	else {
  		if (dp[abs(sr - fr)][abs(sc - fc)] != 0){
  			return dp[abs(sr - fr)][abs(sc - fc)];
		  }
  		else {
			int x1, y1, x2, y2;

		if (sr <= fr) {
			if (sc <= fc) {
			x1 = sr + 2;
			y1 = sc + 1;
			x2 = sr + 1;
			y2 = sc + 2;
		}else {
			x1 = sr + 2;
			y1 = sc - 1;
			x2 = sr + 1;
			y2 = sc - 2;
			}
		}
		else {
			if (sc <= fc) {
			x1 = sr - 2;
			y1 = sc + 1;
			x2 = sr - 1;
			y2 = sc + 2;
		}else {
			x1 = sr - 2;
			y1 = sc - 1;
			x2 = sr - 1;
			y2 = sc - 2;
		}
}
		dp[abs(sr - fr)][abs(sc - fc)] = min(solution(x1, y1, fr, fc), solution(x2, y2, fr, fc)) + 1;
		dp[abs(sc - fc)][abs(sr - fr)] = dp[abs(sr - fr)][abs(sc- fc)];
		return dp[abs(sr - fr)][abs(sc - fc)];
		}
	}
}

int main() {
   int t, j, ans;
   scanf("%d", &t);
   for (int q = 0; q < t;q++) {

       	char awal[3], akhir[3];
       	scanf("%s %s", awal, akhir);

       	int sc = awal[1]-'0';
       	int sr = awal[0]-'A'+1;
       	int fc = akhir[1]-'0';
       	int fr = akhir[0]-'A'+1;

       	if ((sr == 1 && sc == 1 && fr == 2 && fc == 2) || (sr == 2 && sc == 2 && fr == 1 && fc == 1))
		ans = 4;
	   	else if ((sr == 1 && sc == 8 && fr == 2 && fc == 7) || (sr == 2 && sc == 7 && fr == 1 && fc == 8))
	   	ans = 4;
	   	else if ((sr == 8 && sc == 1 && fr == 7 && fc == 2) || (sr == 7 && sc == 2 && fr == 8 && fc == 1))
	   	ans = 4;
	   	else if ((sr == 8 && sc == 8 && fr == 7 && fc == 7) || (sr == 7 && sc == 7 && fr == 8 && fc == 8))
	   	ans = 4;
   else {
           for(int i = 0; i < 8; i++) {
               for(int j = 0; j < 8; j++) {
                   dp[i][j] = 0;
               }
           }
   dp[1][0] = 3;
   dp[0][1] = 3;
   dp[1][1] = 2;
   dp[2][0] = 2;
   dp[0][2] = 2;
   dp[2][1] = 1;
   dp[1][2] = 1;
   ans = solution(sr, sc, fr, fc);
   }
       printf("Case #%d: %d\n", q+1, ans);
       j++;
   }
}
