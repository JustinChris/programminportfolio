#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int dp[8][8];

int min(int x, int y) {
   if(x < y) {
       return x;
   }
   return y;
}

int solution(int sr, int sc, int fr, int fc)
{
// If knight has reached on target.
if (sr == fr && sc == fc)
return dp[0][0];
else {
  
// I for current state answer is already calculated than no need to process it, just return stored value
// Which we had already calculated.
if (dp[abs(sr - fr)][abs(sc - fc)] != 0)
return dp[abs(sr - fr)][abs(sc - fc)];
  
// Else calculate solution for current state and store it in dp.
else {

int x1, y1, x2, y2;

if (sr <= fr) {
if (sc <= fc) {
x1 = sr + 2;
y1 = sc + 1;
x2 = sr + 1;
y2 = sc + 2;
} else {
x1 = sr + 2;
y1 = sc - 1;
x2 = sr + 1;
y2 = sc - 2;
}
} else {
if (sc <= fc) {
x1 = sr - 2;
y1 = sc + 1;
x2 = sr - 1;
y2 = sc + 2;
} else {
x1 = sr - 2;
y1 = sc - 1;
x2 = sr - 1;
y2 = sc - 2;
}
}
  
// ans will be, 1 + minimum of steps
// required from (x1, y1) and (x2, y2).
dp[abs(sr - fr)][abs(sc - fc)] = min(solution(x1, y1, fr, fc), solution(x2, y2, fr, fc)) + 1;

// exchanging the coordinates x with y of both
// knight and target will result in same ans.
dp[abs(sc - fc)][abs(sr - fr)] = dp[abs(sr - fr)][abs(sc- fc)];
return dp[abs(sr - fr)][abs(sc - fc)];
}
}
}

int main(void) {
   // Declaring local variables.
   int t, j, ans;
   // Taking user input for number of test cases.
   scanf("%d", &t);
   j = 1;
   // Running while loop for test cases.
   while(t--) {
       // Creating two char arrays for user input of coordinates of start position and final position of knight.
       char start[3], final[3];
       scanf("%s %s", start, final);
       // Converting user input into integer coordinates, considering chess board as 8x8 matrix.
       int sc = start[1]-'0';
       int sr = start[0]-'A'+1;
       int fc = final[1]-'0';
       int fr = final[0]-'A'+1;
       // These are 4 corner cases.
       // When Knight is placed at a conrner and final position is one cell ahead diagonally.
       if ((sr == 1 && sc == 1 && fr == 2 && fc == 2) || (sr == 2 && sc == 2 && fr == 1 && fc == 1))
ans = 4;
   else if ((sr == 1 && sc == 8 && fr == 2 && fc == 7) || (sr == 2 && sc == 7 && fr == 1 && fc == 8))
   ans = 4;
   else if ((sr == 8 && sc == 1 && fr == 7 && fc == 2) || (sr == 7 && sc == 2 && fr == 8 && fc == 1))
   ans = 4;
   else if ((sr == 8 && sc == 8 && fr == 7 && fc == 7) || (sr == 7 && sc == 7 && fr == 8 && fc == 8))
   ans = 4;
   // Else using dynamic programming to solve the problem.
   else {
       // Intializing dp array with all zeros.
           for(int i = 0; i < 8; i++) {
               for(int j = 0; j < 8; j++) {
                   dp[i][j] = 0;
               }
           }
   // dp[a][b], here a, b is the difference of
   // sr & fr and sc & fc respectively.
   // Basically dp state is represeted as diffrence between current position and final position.
   // Initially current position is start position.
   dp[1][0] = 3;
   dp[0][1] = 3;
   dp[1][1] = 2;
   dp[2][0] = 2;
   dp[0][2] = 2;
   dp[2][1] = 1;
   dp[1][2] = 1;
   ans = solution(sr, sc, fr, fc);
   }
       printf("Case #%d: %d\n", j, ans);
       j++;
   }
}
