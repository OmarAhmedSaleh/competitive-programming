public int blackjack(int a, int b) {
  if(a>21 && b>21){
    return 0;
  }
  if(a>21){
    return b;
  }
  if(b>21){
    return a;
  }
  int df_a = 21 - a;
  if(df_a < 0){df_a*=-1;}
  int df_b = 21 - b;
  if(df_b < 0){df_b*=-1;}
  return (df_a>df_b ? b:a);
}
