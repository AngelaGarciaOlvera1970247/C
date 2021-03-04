#include<stdio.h>
#include<math.h>
#define K 15 

  void prime(int h); 
  void binary(int j); 

  int main() {
  printf("First prime binary numbers:\n");
  prime(K); 
}
  void binary(int j){
    int i = 0; 
    int base[10] = {0}; 
    while(j > 0){
        
	base[i] = j % 2; 
	j /= 2; 
	++i; 
    }
    
    for(int x = 9; x >= 0; --x){ 
        printf("%01d",base[x]);
    }
        printf("\n"); 
}
    void prime(int k){
        int count, i, flag, sr;
        int h = 1;
        count = 1;

    while(count <= k){
        sr = sqrt(h);
        flag = 0; 
    for(i = 2; i <= sr; i++){
        if(h % i ==0){
        flag = 1; 
        break;
    }
}
    if(flag == 0){ 
        binary(h); 
        count++; 
    }
        h++; 
    }
}

/* Task carried out with the help of ANGEL RAUL CHAVEZ CARRILLO. */