#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

unsigned int power( unsigned int a, unsigned int k, unsigned int n );

void main(){

srand((unsigned) time(NULL));

int flg = 0;
while(flg == 0){
  //Nを求める
  int N,p,q,p1,q1,flag = 0;

  //p素数判定
  while(flag == 0){
    p1 = rand() % 100000;
    int a,l;
    for(l=2; l<=sqrt(p1); l++){
      a = p1 % l;
      if(a == 0){
        //素数でない時
        flag = 0;
        break;
      }
      flag = 1;
    }
  }

  //q素数判定
  int flag1 = 0;
  while(flag1 == 0){
    q1 = rand() % 100;
    int b,m;
    for(m=2; m<=sqrt(q1); m++){
      b = q1 % m;
      if(b == 0){
        //素数でない時
        flag1 = 0;
        break;
      }
      flag1 = 1;
    }
  }

  p = p1;
  q = q1;

  N = p * q;

  //Lを求める
  int x,y,r,gcd,L;

  if( p > q ){
      x = p - 1;
      y = q - 1;
  }else{
      x = q - 1;
      y = p - 1;
  }

  //最大公約数を求める
  while((r = x % y) != 0){
    x = y;
    y = r;
  }

  gcd = y;

  //最小公倍数を求める
  L = (p - 1) * (q - 1) / gcd;

  //Eを求める
  int E,n,e1,gcdEL;

  while(gcdEL != 1){
    e1 = 0; //e1 reset
    while(e1 <= 1){
      e1 = rand() % L;
    }

    x = e1;
    y = L;

    while((r = x % y) != 0){
      x = y;
      y = r;
    }
    gcdEL = y;
  }

  E = e1;

  //Dを求める
  int x1 = 1;
  int y1 = 0;
  int z1 = L;
  int x2 = 0;
  int y2 = 1;
  int z2 = E;

  while(z2 != 0){
    int q = z1 / z2;
    int x3 = x1 - q * x2;
    int y3 = y1 - q * y2;
    int z3 = z1 - q * z2;
    x1 = x2;
    y1 = y2;
    z1 = z2;
    x2 = x3;
    y2 = y3;
    z2 = z3;
  }
  if(y1 < 0) continue;
  int D = y1;

  printf("\nN:%d\nL:%d\nE:%d\nD:%d\n",N,L,E,D);

  int hirabun;
  printf("暗号化したい数値を入力して下さい\n");
  scanf("%d",&hirabun);

  //暗号化
  int angou = power(hirabun,E,N);
  printf("平文:%d\n",hirabun);
  printf("暗号化:%d\n",angou);

  //復号化
  int motobun = power(angou,D,N);
  printf("復号化:%d\n", motobun);


  flg = 1;
}


}

/*
  繰り返し自乗法を使った法nのべき乗計算( aのk乗をnで割った余りを求める )

  unsigned int a : 底
  unsigned int k : 指数
  unsigned int n : 法
*/
unsigned int power( unsigned int a, unsigned int k, unsigned int n )
{
  if ( n >= 0x10000 ) return( 0 );

  if ( a == 0 || n == 0 ) return( 0 ); 
  if ( k == 0 ) return( 1 % n );       

  unsigned int currentMod = a % n;
  unsigned int currentValue = ( ( k & 1 ) > 0 ) ? currentMod : 1;

  for ( k >>= 1 ; k > 0 ; k >>= 1 ) {
    currentMod = ( currentMod * currentMod ) % n;
    if ( ( k & 1 ) > 0 )
      currentValue = ( currentValue * currentMod ) % n;
  }

  return( currentValue );
}
