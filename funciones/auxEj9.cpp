#include <string>

int memoMaxLikes(int* tiros, int* likes, int k, bool bailo, int numRonda, int ventaja, int memo[][1001][2]){    
    
    if(numRonda == k) return 0;

    if (memo[numRonda][ventaja][bailo] != -1) return memo[numRonda][ventaja][bailo];

    int ventajaOriginal = ventaja;
    ventaja += tiros[numRonda];

    int noBailar = memoMaxLikes(tiros, likes, k, false, numRonda + 1, ventaja, memo);

    int bailar = 0;
    int cantLikes = 0;


    if (ventaja > 0) {
        if (bailo) {
            cantLikes = likes[numRonda] / 2;
        }
        else cantLikes = likes[numRonda];

        ventaja--;
        bailar = cantLikes + memoMaxLikes(tiros, likes, k, true, numRonda + 1, ventaja, memo);
    }

    int res = std::max(bailar, noBailar);

    memo[numRonda][ventajaOriginal][bailo] = res;

    return res;

}

int maxLikes(int* tiros, int* likes, int k, bool bailo, int numRonda, int ventaja){
    static int memo[1001][1001][2];
    for (int i=0; i<=k; i++){
        for(int j=0; j<=k; j++){
            for(int w=0; w<2; w++){
                memo[i][j][w]=-1;
            }
        }
    }

    return  memoMaxLikes(tiros, likes, k, bailo, numRonda, ventaja, memo);
}